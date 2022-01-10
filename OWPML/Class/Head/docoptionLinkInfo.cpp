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
#include "docoptionLinkInfo.h"

namespace OWPML {


    CDocOptionLinkInfo* CDocOptionLinkInfo::Create()
    {
        return new CDocOptionLinkInfo();
    }

    CDocOptionLinkInfo::CDocOptionLinkInfo() : CExtObject(ID_HEAD_DocOption_LinkInfo), m_bPageInherit(false), m_bFootnoteInherit(false)
    {
    }

    CDocOptionLinkInfo::~CDocOptionLinkInfo()
    {
    }

    void CDocOptionLinkInfo::InitMap(bool /*bRead*/)
    {
    }

    bool CDocOptionLinkInfo::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"path", m_Path);
        Util::CXMLAttConverter::SetAttribute(att, L"pageInherit", m_bPageInherit);
        Util::CXMLAttConverter::SetAttribute(att, L"footnoteInherit", m_bFootnoteInherit);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDocOptionLinkInfo::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"path", m_Path);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageInherit", m_bPageInherit);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"footnoteInherit", m_bFootnoteInherit);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }


    CDocOptionLicenseMark* CDocOptionLicenseMark::Create()
    {
        return new CDocOptionLicenseMark();
    }

    CDocOptionLicenseMark::CDocOptionLicenseMark() : CExtObject(ID_HEAD_DocOption_LicenseMark), m_uType(0), m_bFlag(0), m_bLang(0)
    {
    }

    CDocOptionLicenseMark::~CDocOptionLicenseMark()
    {
    }

    void CDocOptionLicenseMark::InitMap(bool /*bRead*/)
    {
    }

    bool CDocOptionLicenseMark::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_LicensTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"flag", m_bFlag);
        if (m_bLang)
            Util::CXMLAttConverter::SetAttribute(att, L"lang", m_bLang);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDocOptionLicenseMark::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_LicensTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"flag", m_bFlag);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lang", m_bLang);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

}
