/*
 * Copyright 2022 Hancom Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "stdafx.h"
#include "Object.h"
#include "Thread.h"

namespace OWPML {


    const static UINT HWPXWM_RELEASE = ::RegisterWindowMessage(_T("HWPXWM_RELEASE"));
    const static UINT HWPXWM_SERIALIZE = ::RegisterWindowMessage(_T("HWPXWM_SERIALIZE"));
    const static UINT HWPXWM_END = ::RegisterWindowMessage(_T("HWPXWM_END"));


    // _CheckUseThreads : core가 2개 이상인 시스템에서만 스레드 사용하기 위해 check
    static BOOL _CheckUseThreads()
    {
        static BOOL bUseThreads(FALSE);            // don't use '='.
        static BOOL bCheckNumOfCores(FALSE);    // don't use '='.

#if defined(OS_WIN)
        if (!bCheckNumOfCores) {
            SYSTEM_INFO sysInfo;
            ::GetSystemInfo(&sysInfo);

            bUseThreads = (sysInfo.dwNumberOfProcessors > 1) ? TRUE : FALSE;

            bCheckNumOfCores = TRUE;
        }
#endif //OS_WIN

        return bUseThreads;
    }


    /////////////////////////////////////////////////////////////////
    // _ReleaseThreadMgr Implementation
    _ReleaseThreadMgr* _ReleaseThreadMgr::GetMgr()
    {
        static _ReleaseThreadMgr mgr;
        return &mgr;
    }

    void _ReleaseThreadMgr::DeleteObject(CObject* pObject)
    {
        // 실제 Object가 지워지는 부분
        delete pObject;
    }

    _ReleaseThreadMgr::~_ReleaseThreadMgr()
    {
        End();
        Quit();
    }

    void _ReleaseThreadMgr::Release(CObject* pObject)
    {
        if (!m_idThread && !m_hThread) {
            m_hThread = _CheckUseThreads() ? (reinterpret_cast<HANDLE>(::_beginthreadex(NULL, 0, &DeleteThread, reinterpret_cast<LPVOID>(const_cast<LONG*>(&m_cntLiveThread)), CREATE_SUSPENDED, &m_idThread))) : NULL;
            if (m_hThread) {
                ::InterlockedIncrement(&m_cntLiveThread);
                ::ResumeThread(m_hThread);
                ::SwitchToThread();
            }
        }

        if (m_hThread) {
            // 스레드 생성 후 메시지 큐가 동작하기 이전에 메시지를 보내면 동작을 안할 수 있으므로 처음에는 반복해서 메시지를 보낸다.
            while (!::PostThreadMessage(m_idThread, HWPXWM_RELEASE, NULL, reinterpret_cast<LPARAM>(pObject)))
                ::Sleep(10);
        } else {    // 무슨 이유에선지 스레드가 생성이 안되면,, 그냥 메인스레드에서 release
            m_hThread = NULL;
            m_idThread = 0;

            DeleteObject(pObject);
        }
    }

    void _ReleaseThreadMgr::End()
    {
        if (m_idThread && m_hThread) {
            while (!::PostThreadMessage(m_idThread, HWPXWM_END, 0, NULL)) {
                // thread가 이미 종료
                if (GetLastError() == ERROR_INVALID_THREAD_ID) {
                    m_cntLiveThread = 0;
                    break;
                }

                ::Sleep(10);
            }
            ::CloseHandle(m_hThread);
            m_hThread = NULL;
            m_idThread = 0;
        }
    }

    void _ReleaseThreadMgr::Quit()
    {
        // thread가 종료할 때까지 대기
        while (m_cntLiveThread > 0)
            ::Sleep(100);
    }

    _ReleaseThreadMgr::_ReleaseThreadMgr()
        : m_idThread(0), m_hThread(NULL), m_cntLiveThread(0)
    {
    }

    UINT WINAPI _ReleaseThreadMgr::DeleteThread(LPVOID lpParam)
    {
#ifdef _DEBUG
        WCHAR tmpBuf[_MAX_PATH] = { 0, };
        _usprintf_s(tmpBuf, L"[Thread] HWPX_Release:   Begin **********\n");
        OutputDebugString(tmpBuf);
        unsigned int cntMsgs = 0;
#endif    // _DEBUG

        MSG msg;
        while (::GetMessage(&msg, NULL, 0, 0)) {
#ifdef _DEBUG
            ++cntMsgs;
#endif    // _DEBUG

            if (msg.message == HWPXWM_RELEASE)
                DeleteObject(reinterpret_cast<CObject*>(msg.lParam));
            else if (msg.message == HWPXWM_END)
                break;

            ::DispatchMessage(&msg);
        }

        ::InterlockedDecrement(reinterpret_cast<volatile LONG*>(lpParam));

#ifdef _DEBUG
        _usprintf_s(tmpBuf, L"[Thread] HWPX_Release:   End (%d Msgs) **********\n", cntMsgs);
        OutputDebugString(tmpBuf);
#endif    // _DEBUG

        _endthreadex(0);
        return 0;
    }


    /////////////////////////////////////////////////////////////////
    // _SerializeThreadMgr Implementation
    _SerializeThreadMgr* _SerializeThreadMgr::GetMgr()
    {
        static _SerializeThreadMgr mgr;
        return &mgr;
    }

    void _SerializeThreadMgr::WriteStream(std::ofstream* pStream, LPCWSTR pData, LONG size)
    {
        static char tmpConvBuf[SERIALIZE_BUFSIZE * 2];
        int newSize = ::WideCharToMultiByte(CP_UTF8, 0, pData, size, tmpConvBuf, SERIALIZE_BUFSIZE * 2/*sizeof(tmpConvBuf)*/, NULL, NULL);

        if (newSize > 0) {
            // 실제 data가 파일스트림으로 써지는 부분
            pStream->write(tmpConvBuf, newSize);
        } else {
            // 버퍼가 모자라는 듯.. source를 두 부분으로 나누어 처리(재귀호출).
            WriteStream(pStream, pData, size / 2);
            WriteStream(pStream, pData + (size / 2), size - (size / 2));
        }
    }

    _SerializeThreadMgr::~_SerializeThreadMgr()
    {
        End();
        Quit();
    }

    UINT _SerializeThreadMgr::GetThreadID()
    {
        if (!m_idThread && !m_hThread) {
            m_hThread = _CheckUseThreads() ? (reinterpret_cast<HANDLE>(::_beginthreadex(NULL, 0, &WriteThread, reinterpret_cast<LPVOID>(const_cast<LONG*>(&m_cntLiveThread)), CREATE_SUSPENDED, &m_idThread))) : NULL;
            if (m_hThread) {
                ::InterlockedIncrement(&m_cntLiveThread);
                ::ResumeThread(m_hThread);
                ::SwitchToThread();
            }
        }

        return m_idThread;
    }

    BOOL _SerializeThreadMgr::Serialize(UINT idThread, _SerializeStruct* pData)
    {
        return ::PostThreadMessage(idThread, HWPXWM_SERIALIZE, NULL, reinterpret_cast<LPARAM>(pData));
    }

    void _SerializeThreadMgr::End()
    {
        if (m_hThread && m_idThread) {
            // 스레드 생성 후 메시지 큐가 동작하기 이전에 메시지를 보내면 동작을 안할 수 있으므로 처음에는 반복해서 메시지를 보낸다.
            while (!::PostThreadMessage(m_idThread, HWPXWM_END, NULL, NULL)) {
                // thread가 이미 종료
                if (GetLastError() == ERROR_INVALID_THREAD_ID) {
                    m_cntLiveThread = 0;
                    break;
                }
                ::Sleep(10);
            }
            ::CloseHandle(m_hThread);
            m_hThread = NULL;
            m_idThread = 0;
        }
    }

    void _SerializeThreadMgr::Quit()
    {
        // thread가 종료할 때까지 대기
        while (m_cntLiveThread > 0)
            ::Sleep(100);
    }

    _SerializeThreadMgr::_SerializeThreadMgr()
        : m_idThread(0), m_hThread(NULL), m_cntLiveThread(0)
    {
    }

    UINT WINAPI _SerializeThreadMgr::WriteThread(LPVOID lpParam)
    {
#if defined(OS_WIN)
#ifdef _DEBUG
        WCHAR tmpBuf[_MAX_PATH] = { 0, };
        _usprintf_s(tmpBuf, L"[Thread] HWPX_Serialize: Begin **********\n");
        OutputDebugString(tmpBuf);
        unsigned int cntMsgs = 0;
#endif    // _DEBUG

        _SerializeStruct* pCurObj = NULL;

        MSG msg;
        while (::GetMessage(&msg, NULL, 0, 0)) {
#ifdef _DEBUG
            ++cntMsgs;
#endif    // _DEBUG

            if (msg.message == HWPXWM_SERIALIZE) {
                pCurObj = reinterpret_cast<_SerializeStruct*>(msg.lParam);
                WriteStream(pCurObj->m_pStream, pCurObj->m_pData, pCurObj->m_size);
                ::SetEvent(*(pCurObj->m_phWait));
            } else if (msg.message == HWPXWM_END) {
                break;
            }

            ::DispatchMessage(&msg);
        }

        ::InterlockedDecrement(reinterpret_cast<volatile LONG*>(lpParam));

#ifdef _DEBUG
        _usprintf_s(tmpBuf, L"[Thread] HWPX_Serialize: End (%d Msgs) **********\n", cntMsgs);
        OutputDebugString(tmpBuf);
#endif    // _DEBUG

        ::_endthreadex(0);
#endif //OS_WIN
        return 0;
    }


    void ToReleaseThreadMgr(CObject* pObj)
    {
        _ReleaseThreadMgr::GetMgr()->Release(pObj);
    }

    void QuitReleaseThreadMgr()
    {
        _ReleaseThreadMgr::GetMgr()->End();
    }

    void QuitSerialzeThreadMgr()
    {
        _SerializeThreadMgr::GetMgr()->End();
    }

}