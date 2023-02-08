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
#include "cellSpan.h"

namespace OWPML {


    CCellSpan* CCellSpan::Create()
    {
        return new CCellSpan();
    }

    CCellSpan* CCellSpan::Clone()
    {
        CCellSpan* clone = new CCellSpan();

        clone->SetColSpan(this->m_uColSpan);
        clone->SetRowSpan(this->m_uRowSpan);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCellSpan::CCellSpan() : CExtObject(ID_PARA_CellSpan), m_uColSpan(1), m_uRowSpan(1)
    {
    }

    CCellSpan::~CCellSpan()
    {
    }

    void CCellSpan::InitMap(bool /*bRead*/)
    {
    }

    bool CCellSpan::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"colSpan", m_uColSpan);
        Util::CXMLAttConverter::SetAttribute(att, L"rowSpan", m_uRowSpan);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCellSpan::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"colSpan", m_uColSpan);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rowSpan", m_uRowSpan);

        return bres;
    }

}
