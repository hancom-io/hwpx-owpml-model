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
#include "ManifestType.h"

namespace OWPML {

    CManifestType* CManifestType::Create()
    {
        return new CManifestType();
    }

    CManifestType::CManifestType() : CExtObject(ID_OPF_ManifestType)
    {
    }

    CManifestType::~CManifestType()
    {
    }

    void CManifestType::InitMap(bool bRead)
    {
        OWPML_OPF_REDIRECT_FUNC(CManifestType, item)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CManifestType)
            OWPML_OPF_ADD_REDIRECT_FUNC(item, CItem, ID_OPF_Item)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CManifestType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (!m_strId.empty()) Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CManifestType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CItem* CManifestType::Setitem(CItem* pitem)
    {
        CItem* item = pitem;
        if (item == NULL) {
            item = CItem::Create();
        }
        SetObject((CObject*)item);

        return item;
    }

    CItem* CManifestType::Getitem(int index)
    {
        return static_cast<CItem*>(GetObjectByID(ID_OPF_Item, index));
    }

}
