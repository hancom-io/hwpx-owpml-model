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

#ifndef _Thread_H_
#define _Thread_H_

namespace OWPML {

#define SERIALIZE_BUFSIZE    (1 << 16)            // 2^16 = 64K

    void QuitSerialzeThreadMgr();

    /////////////////////////////////////////////////////////////////
    // _ReleaseThreadMgr Declaration
    class _ReleaseThreadMgr
    {
    public:
        static _ReleaseThreadMgr* GetMgr();
        static void DeleteObject(CObject* pObject);
        ~_ReleaseThreadMgr();

    public:
        void Release(CObject* pObject);
        void End();

    protected:
        void Quit();

    private:
        _ReleaseThreadMgr();

    private:
        /////////////////////////////////////////////////////////////////
        //    CSObject Tree에 대한 메모리 해제 담당 스레드:
        //        CHncString의 소멸자 호출이 Thread 안정성이 있는지..? 확인必!
        static UINT WINAPI DeleteThread(LPVOID lpParam);

    private:
        UINT            m_idThread;
        HANDLE          m_hThread;
        volatile LONG   m_cntLiveThread;
    };


    /////////////////////////////////////////////////////////////////
    // _SerializeThreadMgr Declaration
    class _SerializeThreadMgr
    {
    public:
        static _SerializeThreadMgr* GetMgr();
        static void WriteStream(std::ofstream* pStream, LPCWSTR pData, LONG size);
        ~_SerializeThreadMgr();

    public:
        // _SerializeStruct
        class _SerializeStruct
        {
        public:
            _SerializeStruct()
            {
                m_pStream = NULL;
                m_pData = NULL;
                m_size = 0;
                m_phWait = NULL;
            }
            void Set(std::ofstream* pStream, LPCWSTR pData, LONG size, HANDLE* phWait)
            {
                m_pStream = pStream;
                m_pData = pData;
                m_size = size;
                m_phWait = phWait;
            }

            std::ofstream* m_pStream;
            LPCWSTR m_pData;
            LONG m_size;
            HANDLE* m_phWait;
        };

    public:
        UINT GetThreadID();
        BOOL Serialize(UINT idThread, _SerializeStruct* pData);
        void End();

    protected:
        void Quit();

    private:
        _SerializeThreadMgr();

    private:
        /////////////////////////////////////////////////////////////////
        //    Buffer에 대한 File I/O(Serialize) 담당 스레드:
        static UINT WINAPI WriteThread(LPVOID lpParam);

    private:
        UINT            m_idThread;
        HANDLE          m_hThread;
        volatile LONG   m_cntLiveThread;
    };

}

#endif    // _Thread_H_
