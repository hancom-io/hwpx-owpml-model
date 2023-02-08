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
#include "rgb.h"

namespace OWPML {


    CRgb* CRgb::Create()
    {
        return new CRgb();
    }

    CRgb* CRgb::Clone()
    {
        CRgb* clone = new CRgb();

        clone->SetR(this->m_uR);
        clone->SetG(this->m_uG);
        clone->SetB(this->m_uB);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CRgb::CRgb() : CExtObject(ID_PARA_Rgb), m_uR(0), m_uG(0), m_uB(0)
    {
    }

    CRgb::~CRgb()
    {
    }

    void CRgb::InitMap(bool /*bRead*/)
    {
    }

    bool CRgb::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"r", m_uR);
        Util::CXMLAttConverter::SetAttribute(att, L"g", m_uG);
        Util::CXMLAttConverter::SetAttribute(att, L"b", m_uB);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRgb::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"r", m_uR);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"g", m_uG);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"b", m_uB);

        return bres;
    }

}
