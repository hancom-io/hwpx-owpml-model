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
#include "poffset.h"

namespace OWPML {


    CPBFOffset* CPBFOffset::Create()
    {
        return new CPBFOffset();
    }

    CPBFOffset* CPBFOffset::Clone()
    {
        CPBFOffset* clone = new CPBFOffset();

        clone->SetLeft(this->m_uLeft);
        clone->SetRight(this->m_uRight);
        clone->SetTop(this->m_uTop);
        clone->SetBottom(this->m_uBottom);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPBFOffset::CPBFOffset() : CExtObject(ID_PARA_PBFOffset), m_uLeft(1417), m_uRight(1417), m_uTop(1417), m_uBottom(1417)
    {
    }

    CPBFOffset::~CPBFOffset()
    {
    }

    void CPBFOffset::InitMap(bool /*bRead*/)
    {
    }

    bool CPBFOffset::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"left", m_uLeft);
        Util::CXMLAttConverter::SetAttribute(att, L"right", m_uRight);
        Util::CXMLAttConverter::SetAttribute(att, L"top", m_uTop);
        Util::CXMLAttConverter::SetAttribute(att, L"bottom", m_uBottom);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPBFOffset::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"left", m_uLeft);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"right", m_uRight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"top", m_uTop);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"bottom", m_uBottom);

        return bres;
    }


    CASCOffset* CASCOffset::Create()
    {
        return new CASCOffset();
    }

    CASCOffset::CASCOffset() : CExtObject(ID_PARA_ASCOffset), m_uX(0), m_uY(0)
    {
    }

    CASCOffset::~CASCOffset()
    {
    }

    void CASCOffset::InitMap(bool /*bRead*/)
    {
    }

    bool CASCOffset::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"x", m_uX);
        Util::CXMLAttConverter::SetAttribute(att, L"y", m_uY);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CASCOffset::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x", m_uX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y", m_uY);

        return bres;
    }

}
