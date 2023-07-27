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

#include "OWPML/OWPML.h"

#include "OWPMLSerialize.h"
#include "OWPMLDocumentDef.h"
#include "OWPMLSectionHandler.h"

#include "OWPMLSerializeModel.h"
#include "OWPMLUtil/HncSha1.h"

namespace OWPML {

    ////////////////////////////////////////////////////////////////////////////////////////
    // COwpmlSerialize
    const LPCSTR COwpmlSerialize::s_distibutepassword = "\x22\x59\x61\x6e\x67\x20\x57\x61\x6e\x67\x53\x75\x6e\x76\x21\x21\x22";
    const LPCSTR COwpmlSerialize::s_olddistibutepassword = "\x22\0x59\0x61\0x6e\0x67\0x20\0x57\0x61\0x6e\0x67\0x53\0x75\0x6e\0x76\x21\x21\x22";

    COwpmlSerialize::COwpmlSerialize() : m_owpmlDoc(NULL), m_pVersion(NULL), m_pAppSetting(NULL),
        m_pPackage(NULL), m_pHead(NULL), m_pHistory(NULL), m_pSection(NULL), m_pRdf(NULL)
    {
        m_owpmlDoc = new OWPML::CDocument();
        m_pHistory = new std::vector<OWPML::CHWPMLHistoryType*>();
        m_pSection = new std::vector<OWPML::CSectionType*>();

        WCHAR pathTemp[_MAX_PATH];
        WCHAR env[_MAX_PATH] = { 0, };

        size_t returnsize = 0;
        _wgetenv_s(&returnsize, env, L"TMP");
        if (returnsize == 0)
            _wgetenv_s(&returnsize, env, L"TEMP");
        if (returnsize > 0) {
            _ustrcpy_s(pathTemp, env);
        } else {// HNCDIR_ROOT에 쓸수 없으면
            WCHAR buf[_MAX_PATH];
            GetTempPathW(_MAX_PATH, buf);
            _ustrcpy_s(pathTemp, buf);
        }

        // 문자열 끝에 backslash가 없어야 한다.
        HncRemoveBackSlash(pathTemp);

        HncRegisterPath(L"Temp", pathTemp);
    }

    COwpmlSerialize::~COwpmlSerialize()
    {
        if (m_pVersion) {
            delete m_pVersion;
        }

        if (m_pAppSetting) {
            delete m_pAppSetting;
        }

        if (m_pPackage) {
            delete m_pPackage;
        }

        if (m_pHead) {
            delete m_pHead;
        }

        if (m_pHistory) {
            for (size_t index = 0; index < m_pHistory->size(); index++) {
                OWPML::CHWPMLHistoryType* historyType = m_pHistory->at(index);
                if (historyType) {
                    delete historyType;
                }
            }
            delete m_pHistory;
        }

        if (m_pSection) {
            for (size_t index = 0; index < m_pSection->size(); index++) {
                OWPML::CSectionType* sectionType = m_pSection->at(index);
                if (sectionType) {
                    delete sectionType;
                }
            }
            delete m_pSection;
        }

        if (m_owpmlDoc) {
            delete m_owpmlDoc;
        }

        if (m_pRdf) {
            delete m_pRdf;
        }

        if (m_hHwpxFile) {
            ::CloseHandle(m_hHwpxFile);
            m_hHwpxFile = NULL;
        }
        HncUnregisterPath(L"Temp");
    }

    BOOL COwpmlSerialize::Open(LPCWSTR path)
    {
        // hwpx import
        if (m_owpmlDoc->Detect(path) == FALSE) {
            return FALSE;
        }

        if (_Init(path) == FALSE) {
            return FALSE;
        }

        if (_DoSerialize(path, L"") == FALSE) {
            return FALSE;
        }

        return TRUE;
    }

    BOOL COwpmlSerialize::Save(LPCWSTR path)
    {
        // prepareStorage
        HncPathMakeTemp(L"OXML", 0, m_szTempFile, _MAX_PATH);
        HncPathMakeTemp(L"OXML", 0, m_TempstoragePath, _MAX_PATH);

        if (m_hHwpxFile) {
            ::CloseHandle(m_hHwpxFile);
            m_hHwpxFile = NULL;
        }
        m_owpmlDoc->WriteFileCreate(m_TempstoragePath);

        // onBody
        //_WriteBinData();
        _WriteChartData();
        _WriteMimetype();
        _WriteVersion();

        _WriteHead();
        _WriteSections();
        _WritePreviewText();
        _WriteApplication();
        _WriteHistoryInfo();
        _WritePreviewImage();
        _WriteScripts();
        _WriteXMLTemplateInfo();
        _WriteBibliography();
        _WriteRDF();

        _WriteContenthpf();

        _WriteContainer();
        _WriteManifest();

        m_owpmlDoc->WriteFileClose();


        if (CopyFileW(m_TempstoragePath, path, FALSE)) {
            HncDeleteFile_s(m_TempstoragePath);
        } else {

            ULONG error = GetLastError();
            error;
            DeleteFileW(path);
            _urename(m_TempstoragePath, path);
        }

        DeleteFileW(m_szTempFile);
        return TRUE;
    }

    BOOL COwpmlSerialize::_Init(LPCWSTR path)
    {
        if (!m_owpmlDoc->Read(path)) {
            return FALSE;
        }

        if (m_owpmlDoc->IsEncryption()) {
            // default password확인
            if (__DetectPassword(COwpmlSerialize::s_distibutepassword) == TRUE) {
                return FALSE;
            }
            if (__DetectPassword(COwpmlSerialize::s_olddistibutepassword) == TRUE) {
                return FALSE;
            }

            return FALSE;
        }

        if (m_owpmlDoc->FindFile(SIGNATURES_FILENAME, FALSE)) {
            return FALSE;
        }

        return TRUE;
    }

    BOOL COwpmlSerialize::_DoSerialize(LPCWSTR path, LPWSTR /*arg*/)
    {
        BOOL bRes = TRUE;

        m_pPath = path;

        try {
            _OnBody();
        }
        catch (DWORD e) {
            e;
            bRes = FALSE;
        }

        if (m_hHwpxFile)
            ::CloseHandle(m_hHwpxFile);

        m_owpmlDoc->GetUnZip()->CloseFile();

        m_hHwpxFile = CreateFileW(m_pPath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (m_hHwpxFile == INVALID_HANDLE_VALUE) {
            m_hHwpxFile = NULL;
        }


        return bRes;
    }

    void COwpmlSerialize::_OnBody()
    {
        _CheckVersion();
        if (!_ReadApplication())
            return;

        _ReadHead();

        _ReadSections();

        _ReadPreviewText();
        _ReadHistoryInfo(TRUE, NULL);
        _ReadPreviewImage();
        _ReadScripts();
        _ReadXMLTemplateInfo();

        _ReadBibliography();
        _ReadRDF();

        _ReadContenthpf();
    }

    /// 본문 구역 Parsing
    BOOL COwpmlSerialize::_ReadSections()
    {
        if (m_pHead == NULL) {
            return FALSE;
        }

        int sectionCount = m_pHead->GetSecCnt();
        if (sectionCount <= 0)
            return FALSE;

        WCHAR szTempFile[_MAX_PATH];
        WCHAR szBuffer[_MAX_PATH];

        HncPathMakeTemp(L"OXML", 0, szTempFile, _MAX_PATH);

        for (int index = 0; index < sectionCount; index++) {
            // section id 만들기
            _usprintf_s(szBuffer, _MAX_PATH, SECTION_ID_FORMAT, index);

            LPCWSTR szZipPath = m_owpmlDoc->GetZipFilePath(szBuffer);
            if (szZipPath == NULL)
                return FALSE;

            // Section parse
            OWPML::CSectionType* section = OWPML::CSectionType::Create();
            OWPML::CHandler handle;

            if (!m_owpmlDoc->SectionParse(szZipPath, szTempFile, section, &handle))
                return FALSE;

            m_pSection->push_back(section);
        } // for

        DeleteFileW(szTempFile);

        return TRUE;
    }

    BOOL COwpmlSerialize::_CheckVersion()
    {
        m_pVersion = OWPML::CVersion::Create();

        if (!m_owpmlDoc->Parse(VERSION_FILENAME, m_pVersion)) {
            return FALSE;
        }
        return TRUE;
    }

    /// 문서의 설정 값 Read
    BOOL COwpmlSerialize::_ReadApplication()
    {
        LPCWSTR szZipPath = m_owpmlDoc->GetZipFilePath(SETTINGS_ID);
        if (szZipPath == NULL)
            return FALSE;

        m_pAppSetting = OWPML::CHWPApplicationSetting::Create();
        if (!m_owpmlDoc->Parse(szZipPath, m_pAppSetting)) {
            return FALSE;
        }
        return TRUE;
    }

    BOOL COwpmlSerialize::_ReadContenthpf()
    {
        m_pPackage = OWPML::CPackage::Create();
        if (!m_owpmlDoc->Parse(CONTENT_FILENAME, m_pPackage)) {
            return FALSE;
        }
        return TRUE;
    }

    /// 파일 인식 정보
    BOOL COwpmlSerialize::_ReadHead()
    {
        LPCWSTR szZipPath = m_owpmlDoc->GetZipFilePath(HEADER_ID);
        if (szZipPath == NULL)
            return FALSE;

        m_pHead = OWPML::CHWPMLHeadType::Create();
        if (!m_owpmlDoc->Parse(szZipPath, m_pHead)) {
            return FALSE;
        }
        return TRUE;

    }

    /// 미리보기 텍스트
    BOOL COwpmlSerialize::_ReadPreviewText(void)
    {
        CHAR buffer[1024] = { 0, };
        BOOL bend;
        int readsize;
        hncstd::string strtemp;

        while (m_owpmlDoc->Decompress(PREVEWTEXT_FILENAME, buffer, 1024, bend, readsize)) {
            if (readsize > 0) {
                strtemp.append(buffer, readsize);
            }
            if (bend) {
                if (!strtemp.empty()) {
                    int length = MultiByteToWideChar(CP_UTF8, 0, strtemp.c_str(), -1, NULL, 0);
                    MultiByteToWideChar(CP_UTF8, 0, strtemp.c_str(), -1, m_szPreviewText, length > 1024 ? 1024 - 1 : length);
                }
                return TRUE;
            }
        }

        return FALSE;
    }

    /// 미리보기 이미지
    BOOL COwpmlSerialize::_ReadPreviewImage(void)
    {
        WCHAR szTempFile[_MAX_PATH];
        HncPathMakeTemp(L"Prv", 0, szTempFile, _MAX_PATH);

        if (m_owpmlDoc->Decompress(PREVEWIMAGE_FILENAME, szTempFile)) {
            _ustrcpy_s(m_szPreviewImagePath, szTempFile);
            return TRUE;
        }

        return FALSE;
    }

    /// 문서 이력 관리
    BOOL COwpmlSerialize::_ReadHistoryInfo(BOOL bManifest, LPCWSTR pszTempFile)
    {
        LPCWSTR szZipPath = NULL;

        if (bManifest)
            szZipPath = m_owpmlDoc->GetZipFilePath(HISTORY_LASTDOC_ID);
        else {
            szZipPath = HISTORYLASTDOC_FILENAME;
            if (!m_owpmlDoc->FindFile(szZipPath, FALSE))
                szZipPath = NULL;
        }

        if (!szZipPath)
            return FALSE;

        // read historylastdoc.hml
        {
            if (pszTempFile != NULL)
                _ustrcpy_s(m_szLastDocMLPath, _MAX_PATH, pszTempFile);
            else
                HncPathMakeTemp(L"OXML", 0, m_szLastDocMLPath, _MAX_PATH);

            CHAR buffer[10240] = { 0, };
            BOOL bend;
            int readsize;
            int length = 0;
            hncstd::string strtemp;
            wchar_t* wbuffer = NULL;

            while (m_owpmlDoc->Decompress(szZipPath, buffer, 10240, bend, readsize)) {
                if (readsize > 0) {
                    strtemp.append(buffer, readsize);
                }

                if (bend) {
                    if (strtemp.empty())
                        return FALSE;

                    length = MultiByteToWideChar(CP_UTF8, 0, strtemp.c_str(), -1, NULL, 0);
                    wbuffer = new wchar_t[length];
                    MultiByteToWideChar(CP_UTF8, 0, strtemp.c_str(), -1, wbuffer, length);
                }
            }

            FILE* pfile = NULL;

            if (_wfopen_s(&pfile, m_szLastDocMLPath, L"rb+") != 0)
                return FALSE;
            
            if(wbuffer)
                fwrite(wbuffer, length * sizeof(WCHAR), 1, pfile);

            fclose(pfile);
            delete[] wbuffer;
        }

        // read versionlogN.xml
        WCHAR szBuffer[_MAX_PATH] = L"";
        UINT itemNum = 0;

        if (bManifest) {
            _usprintf_s(szBuffer, _MAX_PATH, VERSION_LOG_ID_FORMAT, itemNum);
            szZipPath = m_owpmlDoc->GetZipFilePath(szBuffer);
        } else {
            WCHAR strid[_MAX_PATH] = L"";
            _usprintf_s(strid, _MAX_PATH, VERSION_LOG_ID_FORMAT, itemNum);
            swprintf(szBuffer, _MAX_PATH, L"DocHistory/%s.xml", strid);
            szZipPath = szBuffer;
            if (!m_owpmlDoc->FindFile(szZipPath, FALSE))
                szZipPath = NULL;
        }

        while (szZipPath != NULL) {
            OWPML::CHWPMLHistoryType* history = OWPML::CHWPMLHistoryType::Create();
            if (!m_owpmlDoc->HistoryParse(szZipPath, history)) {
                _ASSERTE(FALSE && L"<history>를 읽을 수 없음!!!");
                return FALSE;
            }
            m_pHistory->push_back(history);
        }

        return TRUE;
    }

    BOOL COwpmlSerialize::_ReadScripts()
    {
        return TRUE;
    }

    BOOL COwpmlSerialize::_ReadXMLTemplateInfo()
    {
        return TRUE;
    }

    BOOL COwpmlSerialize::_ReadBibliography()
    {
        return TRUE;
    }

    BOOL COwpmlSerialize::_ReadRDF()
    {
        m_pRdf = OWPML::CRdf::Create();
        if (!m_owpmlDoc->Parse(RDF_FILENAME, m_pRdf)) {
            return FALSE;
        }

        return TRUE;
    }

    BOOL COwpmlSerialize::ReadBindata(LPCWSTR idstring, BOOL /*bOle*/)
    {
        BOOL bEmbed = TRUE;
        WCHAR szType[_MAX_PATH] = { 0, };
        WCHAR path[_MAX_PATH] = { 0, };

        std::map<hncstd::wstring, hncstd::wstring>::iterator binidfind;
        if (m_binData.find(idstring) != m_binData.end()) {
            return TRUE;
        }

        LPCWSTR szZipPath = m_owpmlDoc->GetZipImageFilePath(idstring, &bEmbed, szType);
        if (szZipPath == NULL) {
            _ASSERTE(FALSE);
            return 0;
        }

        HncPathMakeTempEx(L"Hnc\\BinData\\", L"EMB", 0, szType, path, _MAX_PATH);

        if (m_owpmlDoc->Decompress(szZipPath, path)) {
            m_binData.insert(std::map<hncstd::wstring, hncstd::wstring>::value_type(idstring, path));
            return TRUE;
        }

        return FALSE;
    }

    void COwpmlSerialize::_WriteDocSummary()
    {
        // Summary 정보 업데이트
        // 현재 단계에서는 구현 불필요
    }

    void COwpmlSerialize::_WriteBinData()
    {
        OWPML::CManifestType* manifest = m_pPackage->Getmanifest();
        for (size_t i = 0; i < manifest->GetChildCount(); i++) {
            OWPML::CItem* item = manifest->Getitem(i);
            hncstd::wstring type = item->GetMediatype();

            WCHAR szTempFile[_MAX_PATH];
            HncPathMakeTemp(L"OXML", 0, szTempFile, _MAX_PATH);
            
            if (type.compare(APP_XML_TYPE) != 0) {
                if (m_owpmlDoc->Decompress(item->GetHref(), szTempFile)) {
                    item->SetEmbeded(item->GetEmbeded());
                    m_owpmlDoc->WriteFileAdd(item->GetHref(), szTempFile, item->GetMediatype(), item->GetId(), TRUE);
                }
            }
            DeleteFileW(szTempFile);
        }
    }

    void COwpmlSerialize::_WriteChartData()
    {
        int index = 1;

        while (true)
        {
            WCHAR szBuffer[_MAX_PATH];
            _usprintf_s(szBuffer, _MAX_PATH, CHART_FILENAME_FORMAT, index);
            if (m_owpmlDoc->FindFile(szBuffer, FALSE) == FALSE) {
                break;
            }

            WCHAR szTempFile[_MAX_PATH];
            HncPathMakeTemp(L"OXML", 0, szTempFile, _MAX_PATH);

            if (m_owpmlDoc->Decompress(szBuffer, szTempFile)) {
                m_owpmlDoc->WriteFileAdd(szBuffer, szTempFile, NULL, NULL, TRUE, FALSE);
            }

            index++;
        }
    }

    /// MIME 미디어 유형
    void COwpmlSerialize::_WriteMimetype()
    {
        hncstd::wstring buffer = L"application/hwp+zip";
        OWPML::CXMLSerializer serializer;

        serializer.Open(m_szTempFile);
        serializer.WriteBuffer(buffer.c_str(), buffer.length());
        serializer.CloseStream();

        m_owpmlDoc->WriteFileAdd(MIMETYPE_FILENAME, m_szTempFile, NULL, NULL, FALSE, FALSE);
    }

    void COwpmlSerialize::_WriteVersion()
    {
        OWPML::CXMLSerializer serializer;

        serializer.Save(m_szTempFile, m_pVersion);
        serializer.CloseStream();

        m_owpmlDoc->WriteFileAdd(VERSION_FILENAME, m_szTempFile, NULL, NULL, FALSE, FALSE);
    }

    /// 파일 인식 정보
    BOOL COwpmlSerialize::_WriteHead()
    {
        OWPML::CXMLSerializer serializer;

        serializer.Save(m_szTempFile, m_pHead);
        serializer.CloseStream();

        return m_owpmlDoc->WriteFileAdd(HEADER_FILENAME, m_szTempFile, APP_XML_TYPE, HEADER_ID);
    }

    /// 본문 구역
    BOOL COwpmlSerialize::_WriteSections()
    {
        OWPML::CSectionType* sectionType = NULL;

        for (size_t index = 0; index < m_pSection->size(); index++) {
            sectionType = m_pSection->at(index);
            if (!sectionType)
                return FALSE;

            if (sectionType) {
                WCHAR strid[_MAX_PATH] = { 0, };
                WCHAR buffer[_MAX_PATH] = { 0, };
                OWPML::CXMLSerializer serializer;

                serializer.Save(m_szTempFile, sectionType);
                serializer.CloseStream();

                _usprintf_s(strid, _MAX_PATH, SECTION_ID_FORMAT, index);
                _usprintf_s(buffer, _MAX_PATH, L"Contents/%s.xml", strid);

                m_owpmlDoc->WriteFileAdd(buffer, m_szTempFile, APP_XML_TYPE, strid);
            }
        }

        return TRUE;
    }

    /// 미리보기 텍스트
    BOOL COwpmlSerialize::_WritePreviewText()
    {
        OWPML::CXMLSerializer serializer;

        serializer.Open(m_szTempFile);
        serializer.WriteBuffer(m_szPreviewText, _ustrlen(m_szPreviewText));
        serializer.CloseStream();

        if (m_owpmlDoc->WriteFileAdd(PREVEWTEXT_FILENAME, m_szTempFile, APP_TEXT_TYPE, NULL)) {
            return TRUE;
        }
        return FALSE;
    }

    /// 미리보기 이미지
    BOOL COwpmlSerialize::_WritePreviewImage()
    {
        if (m_owpmlDoc->WriteFileAdd(PREVEWIMAGE_FILENAME, m_szPreviewImagePath, L"image/png", NULL, FALSE, FALSE)) {
            return TRUE;
        }
        return FALSE;
    }

    BOOL COwpmlSerialize::_WriteScripts()
    {

        WCHAR szTempFile[_MAX_PATH];
        HncPathMakeTemp(L"OXML", 0, szTempFile, _MAX_PATH);

        LPCWSTR szZipPath = m_owpmlDoc->GetZipFilePath(HEADER_SCRIPT_ID);
        if (szZipPath != NULL) {
            if (m_owpmlDoc->Decompress(szZipPath, szTempFile)) {
                m_owpmlDoc->WriteFileAdd(szZipPath, szTempFile, NULL, NULL, TRUE, FALSE);
            }
        }

        szZipPath = m_owpmlDoc->GetZipFilePath(SOURCE_SCRIPT_ID);
        if (szZipPath != NULL) {
            if (m_owpmlDoc->Decompress(szZipPath, szTempFile)) {
                m_owpmlDoc->WriteFileAdd(szZipPath, szTempFile, NULL, NULL, TRUE, FALSE);
            }
        }

        szZipPath = m_owpmlDoc->GetZipFilePath(PRE_SCRIPT_ID);
        if (szZipPath != NULL) {
            if (m_owpmlDoc->Decompress(szZipPath, szTempFile)) {
                m_owpmlDoc->WriteFileAdd(szZipPath, szTempFile, NULL, NULL, TRUE, FALSE);
            }
        }

        szZipPath = m_owpmlDoc->GetZipFilePath(POST_SCRIPT_ID);
        if (szZipPath != NULL) {
            if (m_owpmlDoc->Decompress(szZipPath, szTempFile)) {
                m_owpmlDoc->WriteFileAdd(szZipPath, szTempFile, NULL, NULL, TRUE, FALSE);
            }
        }

        return TRUE;
    }

    BOOL COwpmlSerialize::_WriteXMLTemplateInfo()
    {
        return FALSE;
    }

    /// 문서의 설정 값 Write
    BOOL COwpmlSerialize::_WriteApplication()
    {
        OWPML::CHWPApplicationSetting* pApplicationSet = OWPML::CHWPApplicationSetting::Create();

        if (!pApplicationSet)
            return FALSE;

        OWPML::CCaretPosition* pCaretPos = pApplicationSet->SetCaretPosition();
        if (!pCaretPos)
            return FALSE;

        OWPML::CXMLSerializer serializer;
        serializer.Save(m_szTempFile, pApplicationSet);
        serializer.CloseStream();
        m_owpmlDoc->WriteFileAdd(SETTINGS_FILENAME, m_szTempFile, APP_TEXT_TYPE, NULL);

        return TRUE;
    }

    /// 문서 이력 관리
    BOOL COwpmlSerialize::_WriteHistoryInfo()
    {
        {
            FILE* pfile = NULL;
            char pbuffer[10240];
            size_t readlen = 0;

            if (_wfopen_s(&pfile, m_szLastDocMLPath, L"rb+") != 0)
                return FALSE;

            OWPML::CXMLSerializer serializer;

            serializer.Open(m_szTempFile);

            while ((readlen = fread(pbuffer, 1, 10240, pfile)) > 0) {
                serializer.WriteBuffer((LPCWSTR)pbuffer, readlen / sizeof(WCHAR));
            }

            serializer.CloseStream();
            fclose(pfile);

            m_owpmlDoc->WriteFileAdd(HISTORYLASTDOC_FILENAME, m_szTempFile, APP_HML_TYPE, HISTORY_LASTDOC_ID);
        }

        for (size_t index = 0; index < m_pHistory->size(); ++index) {
            WCHAR strid[_MAX_PATH] = L"";
            WCHAR buffer[_MAX_PATH] = L"";
            OWPML::CXMLSerializer serializer;

            OWPML::CHWPMLHistoryType* history = m_pHistory->at(index);
            if (!history) {
                return FALSE;
            }

            serializer.Save(m_szTempFile, history);
            serializer.CloseStream();
        }

        return TRUE;
    }

    /// 참고문헌
    BOOL COwpmlSerialize::_WriteBibliography()
    {
        WCHAR szTempFile[_MAX_PATH] = { 0, };
        HncPathMakeTemp(L"OXML", 0, szTempFile, _MAX_PATH);

        if (m_owpmlDoc->GetDecompressBibPath(BIBLIOGRAPHY_FILENAME, szTempFile)) {
            m_owpmlDoc->WriteFileAdd(BIBLIOGRAPHY_FILENAME, szTempFile, APP_XML_TYPE, BIBLIOGRAPHY_ID);
            return TRUE;
        }

        return FALSE;
    }

    BOOL COwpmlSerialize::_WriteRDF()
    {
        if (m_pRdf == NULL) {
            return FALSE;
        }

        OWPML::CXMLSerializer serializer;

        serializer.Save(m_szTempFile, m_pRdf);
        serializer.CloseStream();

        m_owpmlDoc->WriteFileAdd(RDF_FILENAME, m_szTempFile, NULL, NULL, TRUE, FALSE);

        return TRUE;
    }

    BOOL COwpmlSerialize::_WriteContenthpf()
    {
        OWPML::CXMLSerializer serializer;

        serializer.Save(m_szTempFile, m_pPackage);
        serializer.CloseStream();

        return m_owpmlDoc->WriteFileAdd(CONTENT_FILENAME, m_szTempFile, APP_TEXT_TYPE, NULL, TRUE, FALSE);
    }

    BOOL COwpmlSerialize::_WriteContainer()
    {
        OWPML::CContainer* pcontainer = OWPML::CContainer::Create();
        if (pcontainer) {
            OWPML::CRootFiles* prootfiles = pcontainer->Setrootfiles();
            if (prootfiles) {
                OWPML::CRootFile* prootfile = prootfiles->Setrootfile();
                if (prootfile) {
                    prootfile->SetFullpath(CONTENT_FILENAME);
                    prootfile->SetMediatype(L"application/hwpml-package+xml");
                }
                prootfile = prootfiles->Setrootfile();
                if (prootfile) {
                    prootfile->SetFullpath(PREVEWTEXT_FILENAME);
                    prootfile->SetMediatype(APP_TEXT_TYPE);
                }
                prootfile = prootfiles->Setrootfile();
                if (prootfile) {
                    prootfile->SetFullpath(RDF_FILENAME);
                    prootfile->SetMediatype(L"application/rdf+xml");
                }
            }

            // 실제 Writing
            OWPML::CXMLSerializer serializer;
            serializer.Save(m_szTempFile, pcontainer);
            serializer.CloseStream();
            m_owpmlDoc->WriteFileAdd(CONTAINER_FILENAME, m_szTempFile, APP_TEXT_TYPE, NULL, TRUE, FALSE);

            delete pcontainer;
        }

        return TRUE;
    }

    BOOL COwpmlSerialize::_WriteManifest()
    {
        OWPML::CODFManifest* podfmanifest = OWPML::CODFManifest::Create();
        if (podfmanifest == NULL)
            return FALSE;

        std::map<hncstd::wstring, OWPML::CEncryptInfo*>* encryptdatacon = m_owpmlDoc->GetEncryptDataCon();
        if (encryptdatacon) {
            std::map<hncstd::wstring, OWPML::CEncryptInfo*>::iterator iter;
            for (iter = encryptdatacon->begin(); iter != encryptdatacon->end(); ++iter) {
                if (iter->second == NULL)
                    continue;

                if (_ustricmp(MANIFEST_FILENAME, iter->second->m_filename.c_str()) == 0)
                    continue;

                // file entry
                OWPML::CFileEntry* fileentry = podfmanifest->Setfileentry();
                if (fileentry == NULL)
                    continue;

                fileentry->SetFullPath(iter->second->m_filename.c_str());
                fileentry->SetMediaType(iter->second->m_filetype.c_str());

                // 암호가 존재
                if (iter->second->m_password && iter->second->m_password[0]) {
                    fileentry->SetSize(iter->second->m_filesize);

                    m_owpmlDoc->SetEncryptInfo(fileentry, iter->second);
                }
            }
        }

        OWPML::CXMLSerializer serializer;
        serializer.Save(m_szTempFile, podfmanifest);
        serializer.CloseStream();
        m_owpmlDoc->WriteFileAdd(MANIFEST_FILENAME, m_szTempFile, NULL, NULL, TRUE, FALSE);

        delete podfmanifest;
        return TRUE;
    }

    BOOL COwpmlSerialize::__DetectPassword(LPCSTR password)
    {
        if ((password == NULL) || (password[0] == NULL)) {
            return FALSE;
        }

        m_owpmlDoc->SetPassword(password);

        // check sum
        WCHAR buffer[1024] = { 0, };
        BOOL bend = FALSE;
        int readsize = 0;

        OWPML::CEncryptInfo* pencryptinfo = m_owpmlDoc->GetEncryptData(HEADER_FILENAME);
        if (pencryptinfo) {
            if (pencryptinfo->m_checksumtype == OWPML::CEncryptInfo::CSHash_SHA256_1K) {
                if (m_owpmlDoc->Decompress(HEADER_FILENAME, buffer, 1024, bend, readsize)) {
                    BYTE plantextOut[64] = { 0, };

                    HNC_SHA256_ALG_INFO sha11;
                    HNC_SHA256_Init(&sha11);
                    HNC_SHA256_Update(&sha11, (BYTE*)buffer, readsize);
                    HNC_SHA256_Final(&sha11, plantextOut);

                    if (memcmp(plantextOut, pencryptinfo->m_checksum.data(), 32) == 0)
                        return TRUE;
                }
            }
        }

        m_owpmlDoc->SetPassword("");

        return FALSE;
    }

    void COwpmlSerialize::SetSerializeModel(COwpmlSerializeModel* serializeModel)
    {
        m_serializeModel = serializeModel;
    }

    OWPML::CVersion* COwpmlSerialize::GetVersion()
    {
        if (m_pVersion) {
            return m_pVersion;
        }
        return NULL;
    }

    OWPML::CHWPApplicationSetting* COwpmlSerialize::GetApplicationSetting()
    {
        if (m_pAppSetting) {
            return m_pAppSetting;
        }
        return NULL;
    }

    OWPML::CPackage* COwpmlSerialize::GetPackage()
    {
        if (m_pPackage) {
            return m_pPackage;
        }
        return NULL;
    }

    OWPML::CHWPMLHeadType* COwpmlSerialize::GetHead()
    {
        if (m_pHead) {
            return m_pHead;
        }
        return NULL;
    }

    std::vector<OWPML::CHWPMLHistoryType*>* COwpmlSerialize::GetHistories()
    {
        if (m_pHistory) {
            return m_pHistory;
        }
        return NULL;
    }

    std::vector<OWPML::CSectionType*>* COwpmlSerialize::GetSections()
    {
        if (m_pSection) {
            return m_pSection;
        }
        return NULL;
    }

}