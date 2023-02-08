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
#include "SpineType.h"

namespace OWPML {

    CSpineType* CSpineType::Create()
    {
        return new CSpineType();
    }

    CSpineType::CSpineType() : CExtObject(ID_OPF_SpineType)
    {
    }

    CSpineType::~CSpineType()
    {
    }

    void CSpineType::InitMap(bool bRead)
    {
        OWPML_OPF_REDIRECT_FUNC(CSpineType, itemref)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CSpineType)
            OWPML_OPF_ADD_REDIRECT_FUNC(itemref, CItemref, ID_OPF_Itemref)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CSpineType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (!m_strId.empty()) Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSpineType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CItemref* CSpineType::Setitemref(CItemref* pitemref)
    {
        CItemref* itemref = pitemref;
        if (itemref == NULL) {
            itemref = CItemref::Create();
        }
        SetObject((CObject*)itemref);

        return itemref;
    }

    CItemref* CSpineType::Getitemref(int index)
    {
        return static_cast<CItemref*>(GetObjectByID(ID_OPF_Itemref, index));
    }

}
