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
#include "cmyk.h"

namespace OWPML {


    CCmyk* CCmyk::Create()
    {
        return new CCmyk();
    }

    CCmyk* CCmyk::Clone()
    {
        CCmyk* clone = new CCmyk();

        clone->SetC(this->m_uC);
        clone->SetM(this->m_uM);
        clone->SetY(this->m_uY);
        clone->SetK(this->m_uK);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCmyk::CCmyk() : CExtObject(ID_PARA_Cmyk), m_uC(0), m_uM(0), m_uY(0), m_uK(0)
    {
    }

    CCmyk::~CCmyk()
    {
    }

    void CCmyk::InitMap(bool /*bRead*/)
    {
    }

    bool CCmyk::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"c", m_uC);
        Util::CXMLAttConverter::SetAttribute(att, L"m", m_uM);
        Util::CXMLAttConverter::SetAttribute(att, L"y", m_uY);
        Util::CXMLAttConverter::SetAttribute(att, L"k", m_uK);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCmyk::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"c", m_uC);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"m", m_uM);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y", m_uY);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"k", m_uK);

        return bres;
    }

}
