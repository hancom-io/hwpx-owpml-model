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
#include "strikeout.h"

namespace OWPML {


    CStrikeout* CStrikeout::Create()
    {
        return new CStrikeout();
    }

    CStrikeout::CStrikeout() : CExtObject(ID_HEAD_Strikeout), m_uShape(0)
    {
    }

    CStrikeout::~CStrikeout()
    {
    }

    void CStrikeout::InitMap(bool /*bRead*/)
    {
    }

    bool CStrikeout::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"shape", g_LineTypeList2, m_uShape);
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CStrikeout::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"shape", g_LineTypeList2, m_uShape);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);

        return bres;
    }

}
