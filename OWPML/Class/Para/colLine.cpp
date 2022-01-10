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
#include "colLine.h"

namespace OWPML {


    CColLine* CColLine::Create()
    {
        return new CColLine();
    }

    CColLine* CColLine::Clone()
    {
        CColLine* clone = new CColLine();

        clone->SetType((LINETYPE2)this->m_uType);
        clone->SetWidth((LINEWITHTYPE)this->m_uWidth);
        clone->SetColor((COLORREF)this->m_cColor);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CColLine::CColLine() : CExtObject(ID_PARA_ColLine), m_uType(LT2_SOLID), m_uWidth(LWT_0_12), m_cColor(0x000000)
    {
    }

    CColLine::~CColLine()
    {
    }

    void CColLine::InitMap(bool /*bRead*/)
    {
    }

    bool CColLine::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_LineTypeList2, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"width", g_LineWithList, m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CColLine::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_LineTypeList2, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", g_LineWithList, m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);

        return bres;
    }

}
