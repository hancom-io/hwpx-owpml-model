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

#include "OWPMLDocument.h"
#include "OWPMLSerialize.h"

namespace OWPML {

    COwpmlDocumnet::COwpmlDocumnet() : m_serialize(NULL)
    {
        m_serialize = new OWPML::COwpmlSerialize();
    }

    COwpmlDocumnet::~COwpmlDocumnet()
    {
        delete m_serialize;
    }

    COwpmlDocumnet* COwpmlDocumnet::CreateDocument()
    {
        COwpmlDocumnet* owpmlDoc = new COwpmlDocumnet();
        // Todo Default document path
        if (owpmlDoc->Open(L"Default Document Path")) {
            return owpmlDoc;
        }

        delete owpmlDoc;
        return NULL;
    }

    COwpmlDocumnet* COwpmlDocumnet::OpenDocument(LPCWSTR filePath)
    {
        COwpmlDocumnet* owpmlDoc = new COwpmlDocumnet();
        if (owpmlDoc->Open(filePath)) {
            return owpmlDoc;
        }

        delete owpmlDoc;
        return NULL;
    }

    BOOL COwpmlDocumnet::SaveDocument(LPCWSTR filePath)
    {
        if (m_serialize) {
            return m_serialize->Save(filePath);
        }
        return FALSE;
    }

    OWPML::CVersion* COwpmlDocumnet::GetVersion()
    {
        if (m_serialize) {
            return m_serialize->GetVersion();
        }
        return NULL;
    }

    OWPML::CHWPApplicationSetting* COwpmlDocumnet::GetApplicationSetting()
    {
        if (m_serialize) {
            return m_serialize->GetApplicationSetting();
        }
        return NULL;
    }

    OWPML::CPackage* COwpmlDocumnet::GetPackage()
    {
        if (m_serialize) {
            return m_serialize->GetPackage();
        }
        return NULL;
    }

    OWPML::CHWPMLHeadType* COwpmlDocumnet::GetHead()
    {
        if (m_serialize) {
            return m_serialize->GetHead();
        }
        return NULL;
    }

    std::vector<OWPML::CHWPMLHistoryType*>* COwpmlDocumnet::GetHistories()
    {
        if (m_serialize) {
            return m_serialize->GetHistories();
        }
        return NULL;
    }

    std::vector<OWPML::CSectionType*>* COwpmlDocumnet::GetSections()
    {
        if (m_serialize) {
            return m_serialize->GetSections();
        }
        return NULL;
    }

    BOOL COwpmlDocumnet::Open(LPCWSTR srcpath)
    {
        return m_serialize->Open(srcpath);
    }

}