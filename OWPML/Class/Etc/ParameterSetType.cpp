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
#include "ParameterSetType.h"

namespace OWPML {

    CParameterSetType* CParameterSetType::Create()
    {
        return new CParameterSetType();
    }

    CParameterSetType::CParameterSetType() : CExtObject(ID_APPLICATION_ParameterSetType), m_uCount(0)
    {
    }

    CParameterSetType::~CParameterSetType()
    {
    }

    void CParameterSetType::InitMap(bool bRead)
    {
        OWPML_APPLICATION_REDIRECT_FUNC(CParameterSetType, ParameterItem)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CParameterSetType)
            OWPML_APPLICATION_ADD_REDIRECT_FUNC(ParameterItem, CParameterItemtype, ID_APPLICATION_ParameterItemtype)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CParameterSetType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"count", m_uCount);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParameterSetType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"count", m_uCount);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParameterItemtype* CParameterSetType::SetParameterItem(CParameterItemtype* pParameterItem)
    {
        CParameterItemtype* ParameterItem = pParameterItem;
        if (ParameterItem == NULL) {
            ParameterItem = CParameterItemtype::Create();
        }
        SetObject((CObject*)ParameterItem);

        return ParameterItem;
    }

    CParameterItemtype* CParameterSetType::GetParameterItem(int index)
    {
        return static_cast<CParameterItemtype*>(GetObjectByID(ID_APPLICATION_ParameterItemtype, index));
    }

}
