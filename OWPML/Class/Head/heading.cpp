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
#include "heading.h"

namespace OWPML {


    CHeading* CHeading::Create()
    {
        return new CHeading();
    }

    CHeading::CHeading() : CExtObject(ID_HEAD_Heading), m_uLevel(0), m_uIdRef(0), m_uType(0)
    {
    }

    CHeading::~CHeading()
    {
    }

    void CHeading::InitMap(bool /*bRead*/)
    {
    }

    bool CHeading::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_HeadingTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"idRef", m_uIdRef);
        Util::CXMLAttConverter::SetAttribute(att, L"level", m_uLevel);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHeading::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_HeadingTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"idRef", m_uIdRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"level", m_uLevel);

        return bres;
    }

}
