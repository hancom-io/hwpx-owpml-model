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
#include "meta.h"

namespace OWPML {


    CMeta* CMeta::Create()
    {
        return new CMeta();
    }

    CMeta::CMeta() : CStringValueObject(ID_OPF_Meta), m_uLang(0)
    {
    }

    CMeta::~CMeta()
    {
    }

    void CMeta::InitMap(bool /*bRead*/)
    {
    }

    bool CMeta::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (!m_strId.empty()) Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"content", m_strContent);
        if (!m_strSchme.empty()) Util::CXMLAttConverter::SetAttribute(att, L"schme", m_strSchme);

        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CMeta::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"content", m_strContent);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"schme", m_strSchme);

        return bres;
    }

}
