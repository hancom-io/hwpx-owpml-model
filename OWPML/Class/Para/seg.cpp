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
#include "seg.h"

namespace OWPML {


    CSeg* CSeg::Create()
    {
        return new CSeg();
    }

    CSeg* CSeg::Clone()
    {
        CSeg* clone = new CSeg();

        clone->SetType((SEGTYPE)this->m_uType);
        clone->SetX1(this->m_nX1);
        clone->SetY1(this->m_nY1);
        clone->SetX2(this->m_nX2);
        clone->SetY2(this->m_nY2);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CSeg::CSeg() : CExtObject(ID_PARA_Seg), m_uType(SEGT_CURVE), m_nX1(-1), m_nY1(-1), m_nX2(-1), m_nY2(-1)
    {
    }

    CSeg::~CSeg()
    {
    }

    void CSeg::InitMap(bool /*bRead*/)
    {
    }

    bool CSeg::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_SegTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"x1", m_nX1);
        Util::CXMLAttConverter::SetAttribute(att, L"y1", m_nY1);
        Util::CXMLAttConverter::SetAttribute(att, L"x2", m_nX2);
        Util::CXMLAttConverter::SetAttribute(att, L"y2", m_nY2);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSeg::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_SegTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x1", m_nX1);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y1", m_nY1);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x2", m_nX2);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y2", m_nY2);

        return bres;
    }

}
