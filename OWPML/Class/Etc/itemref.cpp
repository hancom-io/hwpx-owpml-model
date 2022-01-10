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
#include "itemref.h"

namespace OWPML {


    CItemref* CItemref::Create()
    {
        return new CItemref();
    }

    CItemref::CItemref() : CExtObject(ID_OPF_Itemref), m_uLinear(0)
    {
    }

    CItemref::~CItemref()
    {
    }

    void CItemref::InitMap(bool /*bRead*/)
    {
    }

    bool CItemref::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (!m_strId.empty()) Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"idref", m_strIdref);
        Util::CXMLAttConverter::SetAttribute(att, L"linear", g_ItemRefList, m_uLinear);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CItemref::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"idref", m_strIdref);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"linear", g_ItemRefList, m_uLinear);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

}
