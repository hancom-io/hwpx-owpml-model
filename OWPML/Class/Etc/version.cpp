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
#include "Util.h"
#include "Serialize.h"
#include "version.h"

namespace OWPML {


    CVersion* CVersion::Create()
    {
        return new CVersion();
    }

    CVersion::CVersion() : CNamedObject(ID_VERSION_Version), m_uMajor(0), m_uMinor(0), m_uPatch(0), m_uRevision(0), m_uOS(0), m_uTagetApplication(0)
    {
        SetElemName(L"hv:HCFVersion");
    }

    CVersion::~CVersion()
    {
    }

    void CVersion::InitMap(bool /*bRead*/)
    {
    }

    bool CVersion::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"tagetApplication", g_tagetApplicationList, m_uTagetApplication);
        Util::CXMLAttConverter::SetAttribute(att, L"major", m_uMajor);
        Util::CXMLAttConverter::SetAttribute(att, L"minor", m_uMinor);
        Util::CXMLAttConverter::SetAttribute(att, L"micro", m_uPatch);
        Util::CXMLAttConverter::SetAttribute(att, L"buildNumber", m_uRevision);
        Util::CXMLAttConverter::SetAttribute(att, L"os", m_uOS);
        Util::CXMLAttConverter::SetAttribute(att, L"xmlVersion", m_strXmlVersion);
        Util::CXMLAttConverter::SetAttribute(att, L"application", m_strApplication);
        Util::CXMLAttConverter::SetAttribute(att, L"appVersion", m_strAppVersion);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CVersion::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tagetApplication", g_tagetApplicationList, m_uTagetApplication);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"major", m_uMajor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"minor", m_uMinor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"micro", m_uPatch);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"buildNumber", m_uRevision);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"os", m_uOS);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"xmlVersion", m_strXmlVersion);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"application", m_strApplication);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"appVersion", m_strAppVersion);

        return bres;
    }

}
