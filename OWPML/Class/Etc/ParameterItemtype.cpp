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
#include "ParameterItemtype.h"

namespace OWPML {


    CParameterItemtype* CParameterItemtype::Create()
    {
        return new CParameterItemtype();
    }

    CParameterItemtype::CParameterItemtype() : CStringValueObject(ID_APPLICATION_ParameterItemtype), m_uType(0)
    {
    }

    CParameterItemtype::~CParameterItemtype()
    {
    }

    void CParameterItemtype::InitMap(bool /*bRead*/)
    {
    }

    bool CParameterItemtype::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ParameterItemList, m_uType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParameterItemtype::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ParameterItemList, m_uType);

        return bres;
    }

}
