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
#include "ParameterArrayType.h"

namespace OWPML {

    CParameterArrayType* CParameterArrayType::Create()
    {
        return new CParameterArrayType();
    }

    CParameterArrayType::CParameterArrayType() : CExtObject(ID_APPLICATION_ParameterArrayType), m_uCount(0)
    {
    }

    CParameterArrayType::~CParameterArrayType()
    {
    }

    void CParameterArrayType::InitMap(bool bRead)
    {
        OWPML_APPLICATION_REDIRECT_FUNC(CParameterArrayType, ParameterItem)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CParameterArrayType)
            OWPML_APPLICATION_ADD_REDIRECT_FUNC(ParameterItem, CParameterItemtype, ID_APPLICATION_ParameterItemtype)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CParameterArrayType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"count", m_uCount);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParameterArrayType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"count", m_uCount);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParameterItemtype* CParameterArrayType::SetParameterItem(CParameterItemtype* pParameterItem)
    {
        CParameterItemtype* ParameterItem = pParameterItem;
        if (ParameterItem == NULL) {
            ParameterItem = CParameterItemtype::Create();
        }
        SetObject((CObject*)ParameterItem);

        return ParameterItem;
    }

    CParameterItemtype* CParameterArrayType::GetParameterItem(int index)
    {
        return static_cast<CParameterItemtype*>(GetObjectByID(ID_APPLICATION_ParameterItemtype, index));
    }

}
