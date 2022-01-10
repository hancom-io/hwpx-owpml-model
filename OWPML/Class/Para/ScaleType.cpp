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
#include "ScaleType.h"

namespace OWPML {


    CScaleType* CScaleType::Create()
    {
        return new CScaleType();
    }

    CScaleType* CScaleType::Clone()
    {
        CScaleType* clone = new CScaleType();

        clone->SetX(this->m_fX);
        clone->SetY(this->m_fY);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CScaleType::CScaleType() : CExtObject(ID_PARA_ScaleType), m_fX(0.0), m_fY(0.0)
    {
    }

    CScaleType::~CScaleType()
    {
    }

    void CScaleType::InitMap(bool /*bRead*/)
    {
    }

    bool CScaleType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"x", m_fX);
        Util::CXMLAttConverter::SetAttribute(att, L"y", m_fY);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CScaleType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x", m_fX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y", m_fY);

        return bres;
    }

}
