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
#include "lineSpacing.h"

namespace OWPML {


    CLineSpacing* CLineSpacing::Create()
    {
        return new CLineSpacing();
    }

    CLineSpacing::CLineSpacing() : CExtObject(ID_HEAD_LineSpacing), m_nValue(-1), m_uUnit(UVT_HWPUNIT), m_uType(0)
    {
    }

    CLineSpacing::~CLineSpacing()
    {
    }

    void CLineSpacing::InitMap(bool /*bRead*/)
    {
    }

    bool CLineSpacing::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_LinespacingTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"value", m_nValue);
        Util::CXMLAttConverter::SetAttribute(att, L"unit", g_LinespacingUnitList, m_uUnit);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLineSpacing::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_LinespacingTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", m_nValue);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"unit", g_LinespacingUnitList, m_uUnit);

        return bres;
    }

}
