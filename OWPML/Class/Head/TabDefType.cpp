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
#include "TabDefType.h"

namespace OWPML {

    CTabDefType* CTabDefType::Create()
    {
        return new CTabDefType();
    }

    CTabDefType::CTabDefType() : CExtObject(ID_HEAD_TabDefType), m_bAutoTabLeft(false), m_bAutoTabRight(false), m_uId(0)
    {
    }

    CTabDefType::~CTabDefType()
    {
    }

    void CTabDefType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CTabDefType, tabItem)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTabDefType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(tabItem, CTabItem, ID_HEAD_TabItem)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTabDefType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"autoTabLeft", m_bAutoTabLeft);
        Util::CXMLAttConverter::SetAttribute(att, L"autoTabRight", m_bAutoTabRight);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTabDefType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"autoTabLeft", m_bAutoTabLeft);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"autoTabRight", m_bAutoTabRight);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTabItem* CTabDefType::SettabItem(CTabItem* ptabItem)
    {
        CTabItem* tabItem = ptabItem;
        if (tabItem == NULL) {
            tabItem = CTabItem::Create();
        }
        SetObject((CObject*)tabItem);

        return tabItem;
    }

    CTabItem* CTabDefType::GettabItem(int index)
    {
        return static_cast<CTabItem*>(GetObjectByID(ID_HEAD_TabItem, index));
    }

}
