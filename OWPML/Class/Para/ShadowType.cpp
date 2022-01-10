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
#include "ShadowType.h"

namespace OWPML {


    CShadowType* CShadowType::Create()
    {
        return new CShadowType();
    }

    CShadowType* CShadowType::Clone()
    {
        CShadowType* clone = new CShadowType();

        clone->SetType((SHADOWTYPE)this->m_uType);
        clone->SetColor(this->m_cColor);
        clone->SetOffsetX(this->m_nOffsetX);
        clone->SetOffsetY(this->m_nOffsetY);
        clone->SetAlpha(this->m_fAlpha);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CShadowType::CShadowType() : CExtObject(ID_PARA_ShadowType), m_uType(SHT_NONE), m_cColor(0x000000), m_nOffsetX(0), m_nOffsetY(0), m_fAlpha(0.0)
    {
    }

    CShadowType::~CShadowType()
    {
    }

    void CShadowType::InitMap(bool /*bRead*/)
    {
    }

    bool CShadowType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ShadowTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetX", m_nOffsetX);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetY", m_nOffsetY);
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CShadowType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ShadowTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetX", m_nOffsetX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetY", m_nOffsetY);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);

        return bres;
    }

}
