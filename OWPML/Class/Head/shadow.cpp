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
#include "shadow.h"

namespace OWPML {


    CCharShadow* CCharShadow::Create()
    {
        return new CCharShadow();
    }

    CCharShadow::CCharShadow() : CExtObject(ID_HEAD_CharShadow), m_nOffsetX(0), m_nOffsetY(0), m_uType(CSHT_NONE)
    {
    }

    CCharShadow::~CCharShadow()
    {
    }

    void CCharShadow::InitMap(bool /*bRead*/)
    {
    }

    bool CCharShadow::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_CharShadowTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetX", m_nOffsetX);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetY", m_nOffsetY);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCharShadow::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_CharShadowTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetX", m_nOffsetX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetY", m_nOffsetY);

        return bres;
    }

}
