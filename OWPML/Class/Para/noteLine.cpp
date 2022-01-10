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
#include "noteLine.h"

namespace OWPML {


    CNoteLine* CNoteLine::Create()
    {
        return new CNoteLine();
    }

    CNoteLine::CNoteLine() : CExtObject(ID_PARA_NoteLine), m_nLength(0), m_uType(LT2_SOLID), m_uWidth(LWT_0_12), m_cColor(0x000000)
    {
    }

    CNoteLine::~CNoteLine()
    {
    }

    void CNoteLine::InitMap(bool /*bRead*/)
    {
    }

    bool CNoteLine::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"length", m_nLength);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_LineTypeList2, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"width", g_LineWithList, m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNoteLine::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"length", m_nLength);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_LineTypeList2, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", g_LineWithList, m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);

        return bres;
    }

}
