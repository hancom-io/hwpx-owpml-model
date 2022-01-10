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
#include "align.h"

namespace OWPML {


    CAlign* CAlign::Create()
    {
        return new CAlign();
    }

    CAlign::CAlign() : CExtObject(ID_HEAD_Align), m_uVertical(0), m_uHorizontal(0)
    {
    }

    CAlign::~CAlign()
    {
    }

    void CAlign::InitMap(bool /*bRead*/)
    {
    }

    bool CAlign::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"horizontal", g_AlignHorizontalList, m_uHorizontal);
        Util::CXMLAttConverter::SetAttribute(att, L"vertical", g_AlignVerticalList, m_uVertical);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAlign::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horizontal", g_AlignHorizontalList, m_uHorizontal);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertical", g_AlignVerticalList, m_uVertical);

        return bres;
    }

}
