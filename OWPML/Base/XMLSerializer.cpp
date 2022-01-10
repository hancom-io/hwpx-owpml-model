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
#include "Attribute.h"
#include "PartNameSpaceInfo.h"
#include "Serialize.h"
#include "XMLAttribute.h"
#include "Thread.h"
#include "NamespacePrefix.h"
#include "Util.h"
#include "XMLSerializer.h"

namespace OWPML {

#pragma warning (disable: 4512)

    ///////////////////////////////////////////////////////
    // CBaseStream
    class CBaseStream
    {
    public:
        virtual ~CBaseStream() {}

    public:
        virtual void open(LPCWSTR /*path*/, std::ios_base::open_mode /*mod*/) = 0;
        virtual bool is_open() = 0;
        virtual void close(void) = 0;

        virtual void write(LPCWSTR str, std::streamsize count) = 0;
    };


    ///////////////////////////////////////////////////////
    // CBufferedFileStream : Export 속도 향상을 위한 파일 버퍼링 클래스
    class CBufferedFileStream : public CBaseStream
    {
    public:
        CBufferedFileStream() : m_buffer(NULL), m_pBuf(NULL), m_pBufStart(NULL), m_pBufEnd(NULL), m_hWait(NULL)
        {
        }

        virtual ~CBufferedFileStream()
        {
            close();
            _releaseBuffer();
        }

    public:
        virtual void open(LPCWSTR path, std::ios_base::open_mode mod)
        {
            m_Stream.open(path, mod);
        }

        virtual void close(void)
        {
            if (m_pBuf != m_buffer)
                _flush();

            if (m_hWait) {
                ::WaitForSingleObject(m_hWait, INFINITE);
                ::CloseHandle(m_hWait);
                m_hWait = NULL;
            }

            m_Stream.close();
        }

        virtual bool is_open()
        {
            return m_Stream.is_open();
        }

        virtual void write(LPCWSTR str, std::streamsize count)
        {
            if (!m_buffer)
                _createBuffer();

            LONG flushSize = 0;
            while ((m_pBuf + count) > m_pBufEnd) {
                flushSize = m_pBufEnd - m_pBuf;
                _umemcpy_s(m_pBuf, flushSize, str, flushSize);
                m_pBuf += flushSize;
                str += flushSize;
                count -= flushSize;
                _flush();
            }

            if (m_pBufEnd - m_pBuf) {
                _umemcpy_s(m_pBuf, (m_pBufEnd - m_pBuf), str, (size_t)count);
                m_pBuf += count;
            }
        }

    private:
        void _createBuffer()
        {
            if (!m_buffer) {
                // 버퍼 크기를 2배로 잡고 반씩 나눠 교대로 사용
                m_buffer = new WCHAR[SERIALIZE_BUFSIZE * 2];

                m_pBuf = m_buffer;
                m_pBufStart = m_pBuf;
                m_pBufEnd = m_buffer + SERIALIZE_BUFSIZE;
            }
        }

        void _releaseBuffer()
        {
            if (m_buffer)
                delete[] m_buffer;

            m_pBuf = NULL;
            m_pBufStart = NULL;
            m_pBufEnd = NULL;
        }

        void _flush()
        {
            if (m_hWait) {
                ::WaitForSingleObject(m_hWait, INFINITE);
                ::CloseHandle(m_hWait);
                m_hWait = NULL;
            }

            LONG size = m_pBuf - m_pBufStart;
            if (size > 0) {
                m_data.Set(&m_Stream, (WCHAR*)m_pBufStart, size, &m_hWait);

                if (m_pBufStart == m_buffer)
                    m_pBuf = m_buffer + SERIALIZE_BUFSIZE;
                else
                    m_pBuf = m_buffer;
                m_pBufStart = m_pBuf;
                m_pBufEnd = m_pBuf + SERIALIZE_BUFSIZE;

#if defined(OS_WIN)
                UINT threadID = _SerializeThreadMgr::GetMgr()->GetThreadID();
                if (threadID) {
                    m_hWait = ::CreateEvent(NULL, TRUE, FALSE, NULL);

                    // 스레드 생성 후 메시지 큐가 동작하기 이전에 메시지를 보내면 동작을 안할 수 있으므로 처음에는 반복해서 메시지를 보낸다.
                    while (!_SerializeThreadMgr::GetMgr()->Serialize(threadID, &m_data))
                        ::Sleep(10);
                } else {    // 무슨 이유에선지 스레드가 생성이 안되면,, 그냥 메인스레드에서 serialize
                    _SerializeThreadMgr::WriteStream(m_data.m_pStream, m_data.m_pData, m_data.m_size);
                }
#endif //OS_WIN

#if defined(OS_UNIX)
                _SerializeThreadMgr::WriteStream(m_data.m_pStream, m_data.m_pData, m_data.m_size);
#endif //OS_UNIX
            }
        }

    private:
        std::ofstream m_Stream;
        HANDLE m_hWait;
        _SerializeThreadMgr::_SerializeStruct m_data;

        LPWSTR m_buffer;
        LPWSTR m_pBuf;
        LPWSTR m_pBufStart;
        LPWSTR m_pBufEnd;
    };


    ///////////////////////////////////////////////////////
    // CStringStream
    class CStringStream : public CBaseStream
    {
    public:
        CStringStream(hncstd::wstringstream& streambuffer) : m_Stream(streambuffer), m_bOpen(true)
        {
            ;
        }

        virtual ~CStringStream()
        {
            close();
        }

    public:
        void open(LPCWSTR /*path*/, std::ios_base::open_mode /*mod*/)
        {
        }

        bool is_open()
        {
            return m_bOpen;
        }

        void close(void)
        {
            m_Stream.seekp(0, std::ios::beg);
            m_bOpen = false;
        }

        void write(LPCWSTR str, std::streamsize count)
        {
            m_Stream.write(str, count);
        }

    private:
        hncstd::wstringstream& m_Stream;
        bool m_bOpen;
    };

    ///////////////////////////////////////////////////////
    // CXMLSerializer Implementation
    CXMLSerializer::CXMLSerializer() : m_bufStream(NULL)
    {
    }

    CXMLSerializer::~CXMLSerializer()
    {
        if (m_bufStream) {
            m_bufStream->close();

            delete m_bufStream;
            m_bufStream = NULL;
        }
    }

    void CXMLSerializer::CloseStream()
    {
        if (m_bufStream) {
            m_bufStream->close();

            delete m_bufStream;
            m_bufStream = NULL;
        }
    }

    bool CXMLSerializer::WriteElement(LPCWSTR pCurObjName, CObject* object, CAttribute* attribute, LPCWSTR value, bool bAvailPreserveSpace/*= true*/)
    {
        object->InitMap(false);

        // element header
        LPCWSTR strelename = pCurObjName;
        if (strelename) {
            bool haschild = object->HasChildList();
            bool emptyvalue = ((value == NULL) || (value && !value[0]));

            WriteBuffer(L"<", 1);
            WriteBuffer(strelename, _ustrlen(strelename));

            // 문자열의 가장 '왼쪽 또는 오른쪽'에 white-space가 존재하는 경우 xml:space="preserve" 속성을 추가
            if (value && bAvailPreserveSpace) {
                if (_NeedPreserveWhiteSpace(value))
                    attribute->setValue(L"xml:space", L"preserve");
            }

            // attribute
            WriteAttribute(attribute);


            if (emptyvalue && (!haschild)) {
                WriteBuffer(L"/>", 2);
            } else {
                WriteBuffer(L">", 1);

                // element value
                if (value != NULL) {
                    // value에 들어가는 금지문자를 Symbol of Signs로 변경
                    hncstd::wstring modifiedValue;
                    Util::CXMLAttConverter::_Val2SymbolOfSignsStr(value, modifiedValue);

                    WriteBuffer(modifiedValue.c_str(), modifiedValue.length());
                }

                if (haschild) {
                    // child
                    Objectlist* pobjlist = object->GetObjectList();
                    Objectlist::iterator iter;

                    for (iter = pobjlist->begin(); iter != pobjlist->end(); ++iter) {
                        CXMLAttribute xmlAattribute;
                        (*iter)->WriteElement(object->FindObjectName(*iter), this, &xmlAattribute);
                    }
                }

                // element tatil
                WriteBuffer(L"</", 2);
                WriteBuffer(strelename, _ustrlen(strelename));
                WriteBuffer(L">", 1);
            }
        }

        return true;
    }

    bool CXMLSerializer::WriteElementWithBuffer(LPCWSTR pCurObjName, CObject* object, CAttribute* attribute, LPCWSTR value, LPCWSTR buffer, int bufferlen, bool bAvailPreserveSpace /*= true*/)
    {
        object->InitMap(false);

        // element header
        LPCWSTR strelename = pCurObjName;
        if (strelename) {
            bool haschild = object->HasChildList();

            WriteBuffer(L"<", 1);
            WriteBuffer(strelename, _ustrlen(strelename));

            // 문자열의 가장 '왼쪽 또는 오른쪽'에 white-space가 존재하는 경우 xml:space="preserve" 속성을 추가
            if (value && bAvailPreserveSpace) {
                if (_NeedPreserveWhiteSpace(value))
                    attribute->setValue(L"xml:space", L"preserve");
            }

            // attribute
            WriteAttribute(attribute);

            if ((value == NULL) && (!haschild) && (!buffer)) {
                WriteBuffer(L"/>", 2);
            } else {
                WriteBuffer(L">", 1);

                // element value
                if (value != NULL) {
                    // value에 들어가는 금지문자를 Symbol of Signs로 변경
                    hncstd::wstring modifiedValue;
                    Util::CXMLAttConverter::_Val2SymbolOfSignsStr(value, modifiedValue);

                    WriteBuffer(modifiedValue.c_str(), modifiedValue.length());
                }

                if (haschild) {
                    // child
                    Objectlist* pobjlist = object->GetObjectList();
                    Objectlist::iterator iter;

                    for (iter = pobjlist->begin(); iter != pobjlist->end(); ++iter) {
                        CXMLAttribute xmlAattribute;
                        (*iter)->WriteElement(object->FindObjectName(*iter), this, &xmlAattribute);
                    }
                }

                // Buffer 내용 저장
                if (buffer)
                    WriteBuffer(buffer, bufferlen);

                // element tatil
                WriteBuffer(L"</", 2);
                WriteBuffer(strelename, _ustrlen(strelename));
                WriteBuffer(L">", 1);
            }
        }

        return true;
    }

    bool CXMLSerializer::WriteAttribute(CAttribute* attribute)
    {
        _ASSERT(m_bufStream->is_open());

        const hncstd::wstring* pAttr = attribute->toString();
        if (pAttr && !pAttr->empty())
            m_bufStream->write(pAttr->c_str(), pAttr->length());

        return true;
    }

    bool CXMLSerializer::WriteBuffer(LPCWSTR buffer, int bufferlen)
    {
        _ASSERT(m_bufStream->is_open());

        m_bufStream->write(buffer, bufferlen);
        return true;
    }

    bool CXMLSerializer::WriteRequiresAttribute(LPCWSTR requires, CAttribute* attribute)
    {
        if ((requires == NULL) || (attribute == NULL))
            return false;

        WCHAR szDelim[] = L" \t\r\n";
        WCHAR* pToken = NULL;
        WCHAR* pNextToken = NULL;
        hncstd::wstring strRequires = requires; // strtok사용할고 Temp로 사용한다.
        hncstd::wstring strAttName;
        LPCWSTR strNameSapce = NULL;

        pToken = _ustrtok_s((LPWSTR)strRequires.c_str(), szDelim, &pNextToken);

        while (pToken != NULL) {
            // namespace 를 얻는다.

            strNameSapce = CPartNameSpaceInfo::GetMgr()->FindNameSpaceFromStandardPrefix(pToken);
            if (strNameSapce) {
                strAttName = L"xmlns:";
                strAttName.append(pToken);

                attribute->setValue(strAttName.c_str(), strNameSapce);
            }
            pToken = _ustrtok_s(NULL, szDelim, &pNextToken);
        }

        return true;
    }


    bool CXMLSerializer::Save(LPCWSTR path, CNamedObject* object)
    {
        bool bres = false;

        if (object) {
            // Directory를 만든다
            WCHAR drive[_MAX_DRIVE] = { 0, };
            WCHAR dir[_MAX_PATH] = { 0, };
            WCHAR newpath[_MAX_PATH] = { 0, };

            _usplitpath_s(path, drive, _MAX_DRIVE, dir, _MAX_PATH, NULL, 0, NULL, 0);
            _umakepath_s(newpath, _MAX_PATH, drive, dir, NULL, NULL);

            if (!Util::CFileUtil::CreateFullDirectory(newpath))
                return false;

            m_bufStream = new CBufferedFileStream();

            m_bufStream->open(path, std::ios::out | std::ios::trunc | std::ofstream::binary);

            if (!m_bufStream->is_open()) {
                return false;
            }

            CXMLAttribute xmlAttribute;
            const WCHAR szXMLHeaderString[] = L"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>";

            WriteBuffer(szXMLHeaderString, _ustrlen(szXMLHeaderString));

            _SetNamespaces(object->GetRootpart(), object->GetID(), &xmlAttribute);

            bres = object->WriteElement(object->GetElemName(), this, &xmlAttribute);
        }

        return bres;
    }

    bool CXMLSerializer::Save(hncstd::wstringstream& streambuffer, CNamedObject* object)
    {
        m_bufStream = new CStringStream(streambuffer);

        CXMLAttribute xmlAttribute;
        bool bres = false;
        const WCHAR szXMLHeaderString[] = L"<?xml version=\"1.0\" encoding=\"UTF-16\" standalone=\"yes\" ?>";

        WriteBuffer(szXMLHeaderString, _ustrlen(szXMLHeaderString));
        _SetNamespaces(object->GetRootpart(), object->GetID(), &xmlAttribute);

        bres = object->WriteElement(object->GetElemName(), this, &xmlAttribute);

        return bres;
    }

    bool CXMLSerializer::SaveAnyElement(hncstd::wstringstream& streambuffer, CAnyElement* object, bool bheadcontain)
    {
        m_bufStream = new CStringStream(streambuffer);

        CXMLAttribute xmlAttribute;
        bool bres = false;

        if (bheadcontain) {
            const WCHAR szXMLHeaderString[] = L"<?xml version=\"1.0\" encoding=\"UTF-16\" standalone=\"yes\" ?>";

            WriteBuffer(szXMLHeaderString, _ustrlen(szXMLHeaderString));
        }
        //_SetNamespaces(object->GetRootpart(), object->GetID(), &xmlAttribute);

        bres = object->WriteElement(object->GetElemName(), this, &xmlAttribute);

        return bres;
    }

    bool CXMLSerializer::Open(LPCWSTR path)
    {
        // Directory를 만든다
        WCHAR drive[_MAX_DRIVE] = { 0, };
        WCHAR dir[_MAX_PATH] = { 0, };
        WCHAR newpath[_MAX_PATH] = { 0, };

        _usplitpath_s(path, drive, _MAX_DRIVE, dir, _MAX_PATH, NULL, 0, NULL, 0);
        _umakepath_s(newpath, _MAX_PATH, drive, dir, NULL, NULL);

        if (!Util::CFileUtil::CreateFullDirectory(newpath))
            return false;

        m_bufStream = new CBufferedFileStream();
        m_bufStream->open(path, std::ios::binary);

        if (!m_bufStream->is_open()) {
            return false;
        }

        return true;
    }

    void CXMLSerializer::_SetNamespace(CAttribute* attribute, LPCWSTR strNamespace)
    {
        LPCWSTR nsPrefix = CPartNameSpaceInfo::GetMgr()->FindStandardPrefixFromNamespace(strNamespace);
        hncstd::wstring xmlns = L"xmlns";

        if (nsPrefix) {
            xmlns.append(L":");
            xmlns.append(nsPrefix);
        }

        attribute->setValue(xmlns.c_str(), strNamespace);
    }

    void CXMLSerializer::_SetNamespaces(IPart* /*prootpart*/, unsigned int id, CAttribute* attribute)
    {
        if (id == ID_VERSION_Version) {
            _SetNamespace(attribute, str_HWPML_VERSION_NAMESPACE);
        } else if (id == ID_ODF_Manifest) {
            _SetNamespace(attribute, str_ODF_MANIFEST_NAMESPACE);
        } else if (id == ID_CON_Container) {
            _SetNamespace(attribute, str_OCF_CONTAIVER_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_PACKAGEFILE_NAMESPACE);
        } else if (id == ID_SIG_signatures) {
            _SetNamespace(attribute, str_OCF_CONTAIVER_NAMESPACE);
        } else if (id == ID_APPLICATION_HWPApplicationSetting) {
            _SetNamespace(attribute, str_HWPML_APP_NAMESPACE);
            _SetNamespace(attribute, str_ODF_CONFIG_NAMESPACE);
        } else if (id == ID_RDF_RDF) {
            _SetNamespace(attribute, str_RDF_NAMESPACE);
        } else {
            //_SetNamespace(attribute, str_HWPML_VERSION_NAMESPACE);        
            _SetNamespace(attribute, str_HWPML_APP_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_PARAGRAPH_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_PARAGRAPH10_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_SECTION_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_CORE_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_HEAD_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_HISTORY_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_MASTERPAGE_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_PACKAGEFILE_NAMESPACE);
            _SetNamespace(attribute, str_DC_NAMESPACE);
            _SetNamespace(attribute, str_OPF_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_OOXMLCHART_NAMESPACE);
            _SetNamespace(attribute, str_HWPML_HWPUNITCHAR_NAMESPACE);
            _SetNamespace(attribute, str_EPUB_NAMESPACE);
            _SetNamespace(attribute, str_ODF_CONFIG_NAMESPACE);
        }
    }

    BOOL CXMLSerializer::_NeedPreserveWhiteSpace(LPCWSTR valueStr)
    {
        if (valueStr) {
            size_t valueLen = _ustrlen(valueStr);
            if (valueLen) {
                WCHAR startChar = *valueStr;
                WCHAR endChar = *(valueStr + valueLen - 1);

                if (_uisspace(startChar) || _uisspace(endChar))
                    return TRUE;
            }
        }

        return FALSE;
    }

    //////////////////////////////////////////////////////
    // CStringValueObject Implementation
    CObject* CStringValueObject::Create(unsigned int id)
    {
        return new CStringValueObject(id);
    }

    bool CStringValueObject::ReadNodeValue(LPCWSTR const value, const unsigned int length)
    {
        if (value && length > 0) {
            if (!m_val.empty()) {
                // 현재 사용하는 SAX 엔진의 경우,
                // value에서 '&' 문자가 들어있으면 잘라서 보내주는 동작을 하고 있다..

                // 우선은 기존 Value에 현재 Value를 추가한다.
                m_val.append(value, length);
            } else {
                m_val.assign(value, length);
            }

            return true;
        }

        return false;
    }

    bool CStringValueObject::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        LPCWSTR pStrValue = NULL;

        if (!m_val.empty())
            pStrValue = m_val.c_str();

        return serialize->WriteElement(pCurObjName, this, att, pStrValue);
    }

    // Instantiation
    template class CValueObject<hncstd::wstring, const hncstd::wstring&>;

}
