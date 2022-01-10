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
#include "color.h"

namespace OWPML {


    CColor* CColor::Create()
    {
        return new CColor();
    }

    CColor* CColor::Clone()
    {
        CColor* clone = new CColor();

        clone->SetValue((COLORREF)this->m_cValue);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CColor::CColor() : CExtObject(ID_CORE_Color)
    {
    }

    CColor::~CColor()
    {
    }

    void CColor::InitMap(bool /*bRead*/)
    {
    }

    bool CColor::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"value", m_cValue);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CColor::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", m_cValue);

        return bres;
    }

}
