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
#include "pmargin.h"

namespace OWPML {


    CPMargin* CPMargin::Create()
    {
        return new CPMargin();
    }

    CPMargin* CPMargin::Clone()
    {
        CPMargin* clone = new CPMargin();

        clone->SetLeft(this->m_uLeft);
        clone->SetRight(this->m_uRight);
        clone->SetTop(this->m_uTop);
        clone->SetBottom(this->m_uBottom);

        clone->SetHeader(this->m_uHeader);
        clone->SetFooter(this->m_uFooter);
        clone->SetGutter(this->m_uGutter);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPMargin::CPMargin() : CExtObject(ID_PARA_Margin), m_uHeader(4252), m_uFooter(4252), m_uGutter(0)
    {
        SetLeft(8504);
        SetRight(8504);
        SetTop(5668);
        SetBottom(4252);
    }

    CPMargin::~CPMargin()
    {
    }

    void CPMargin::InitMap(bool /*bRead*/)
    {
    }

    bool CPMargin::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"header", m_uHeader);
        Util::CXMLAttConverter::SetAttribute(att, L"footer", m_uFooter);
        Util::CXMLAttConverter::SetAttribute(att, L"gutter", m_uGutter);
        CMarginAttrubute::SetAttribute(att);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPMargin::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"header", m_uHeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"footer", m_uFooter);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"gutter", m_uGutter);

        bres &= CMarginAttrubute::ReadAttribute(att);
        return bres;
    }

}
