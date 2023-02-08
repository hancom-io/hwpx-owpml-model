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

#ifndef _OWPMLAPI_OWPML_SERIALIZE_H_
#define _OWPMLAPI_OWPML_SERIALIZE_H_

namespace OWPML
{
    class COwpmlSerializeModel;

    class COwpmlSerialize
    {

    public:
        COwpmlSerialize();
        ~COwpmlSerialize();

    public:
        BOOL Open(LPCWSTR path);
        BOOL Save(LPCWSTR path);

        BOOL ReadBindata(LPCWSTR idstring, BOOL bOle);
        void SetSerializeModel(COwpmlSerializeModel* serializeModel);

    public:
        OWPML::CVersion* GetVersion();
        OWPML::CHWPApplicationSetting* GetApplicationSetting();
        OWPML::CPackage* GetPackage();
        OWPML::CHWPMLHeadType* GetHead();
        std::vector<OWPML::CHWPMLHistoryType*>* GetHistories();
        std::vector<OWPML::CSectionType*>* GetSections();

    private:
        BOOL _Init(LPCWSTR path);
        BOOL _DoSerialize(LPCWSTR path, LPWSTR arg);
        void _OnBody();

        BOOL _CheckVersion();
        BOOL _ReadApplication();
        BOOL _ReadSections();
        BOOL _ReadContenthpf();
        BOOL _ReadHead();
        BOOL _ReadPreviewText();
        BOOL _ReadHistoryInfo(BOOL bManifest, LPCWSTR pszTempFile);
        BOOL _ReadPreviewImage();
        BOOL _ReadScripts();
        BOOL _ReadXMLTemplateInfo();
        BOOL _ReadBibliography();
        BOOL _ReadRDF();

        void _WriteDocSummary();
        void _WriteMimetype();
        void _WriteBinData();
        void _WriteChartData();
        void _WriteVersion();
        BOOL _WriteHead();
        BOOL _WriteSections();
        BOOL _WritePreviewText();
        BOOL _WritePreviewImage();
        BOOL _WriteScripts();
        BOOL _WriteXMLTemplateInfo();
        BOOL _WriteApplication();
        BOOL _WriteHistoryInfo();
        BOOL _WriteBibliography();
        BOOL _WriteRDF();
        BOOL _WriteContainer();
        BOOL _WriteContenthpf();
        BOOL _WriteManifest();

        BOOL __DetectPassword(LPCSTR password);

    private:
        LPCWSTR m_pPath;

        OWPML::CVersion* m_pVersion;
        OWPML::CHWPApplicationSetting* m_pAppSetting;
        OWPML::CPackage* m_pPackage;
        OWPML::CHWPMLHeadType* m_pHead;
        std::vector<OWPML::CHWPMLHistoryType*>* m_pHistory;
        std::vector<OWPML::CSectionType*>* m_pSection;
        OWPML::CRdf* m_pRdf;

        WCHAR m_szPreviewText[1024] = { 0, };
        WCHAR m_szPreviewImagePath[_MAX_PATH] = { 0, };
        WCHAR m_szLastDocMLPath[_MAX_PATH] = { 0, };
        WCHAR m_szTempFile[_MAX_PATH] = { 0, };
        WCHAR m_TempstoragePath[_MAX_PATH] = { 0, };
        int m_SectionCount = 0;

    protected:
        OWPML::CDocument* m_owpmlDoc;

        const static LPCSTR s_olddistibutepassword;
        const static LPCSTR s_distibutepassword;

        COwpmlSerializeModel* m_serializeModel;
        std::map<hncstd::wstring, hncstd::wstring> m_binData;
        HANDLE                    m_hHwpxFile = NULL;            // hwpx file lock을 걸기위해 추가함

    };
}

#endif // _OWPMLAPI_OWPML_SERIALIZE_H_