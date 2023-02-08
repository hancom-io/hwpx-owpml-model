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
#include "StyleType.h"

namespace OWPML {


    CStyleType* CStyleType::Create()
    {
        return new CStyleType();
    }

    CStyleType::CStyleType() : CExtObject(ID_HEAD_StyleType), m_bLockForm(false), m_uCharPrIDRef(0)
    {
    }

    CStyleType::~CStyleType()
    {
    }

    void CStyleType::InitMap(bool /*bRead*/)
    {
    }

    bool CStyleType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_StyleList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"engName", m_strEngName);
        Util::CXMLAttConverter::SetAttribute(att, L"paraPrIDRef", m_uParaPrIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"nextStyleIDRef", m_uNextStyleIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"langID", m_nLangID);
        Util::CXMLAttConverter::SetAttribute(att, L"lockForm", m_bLockForm);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CStyleType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_StyleList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"engName", m_strEngName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"paraPrIDRef", m_uParaPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"nextStyleIDRef", m_uNextStyleIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"langID", m_nLangID);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lockForm", m_bLockForm);

        return bres;
    }

}
