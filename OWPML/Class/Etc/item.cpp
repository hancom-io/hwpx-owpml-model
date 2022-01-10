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
#include "item.h"

namespace OWPML {


    CItem* CItem::Create()
    {
        return new CItem();
    }

    CItem::CItem() : CExtObject(ID_OPF_Item), m_useEmbeded(FALSE), m_bEmbeded(true)
    {
    }

    CItem::~CItem()
    {
    }

    void CItem::InitMap(bool /*bRead*/)
    {
    }

    bool CItem::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"href", m_strHref);
        Util::CXMLAttConverter::SetAttribute(att, L"media-type", m_strMediatype);

        if (m_useEmbeded)
            Util::CXMLAttConverter::SetAttribute(att, L"isEmbeded", m_bEmbeded);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CItem::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"href", m_strHref);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"media-type", m_strMediatype);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"isEmbeded", m_bEmbeded);

        return bres;
    }

}
