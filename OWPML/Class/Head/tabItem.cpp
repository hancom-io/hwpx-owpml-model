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
#include "tabItem.h"

namespace OWPML {


    CTabItem* CTabItem::Create()
    {
        return new CTabItem();
    }

    CTabItem::CTabItem() : CExtObject(ID_HEAD_TabItem), m_nPos(-1), m_uLeader(0), m_nUnit(-1)
    {
    }

    CTabItem::~CTabItem()
    {
    }

    void CTabItem::InitMap(bool /*bRead*/)
    {
    }

    bool CTabItem::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"pos", m_nPos);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_TabItemTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"leader", g_LineTypeList2, m_uLeader);
        if (m_nUnit != -1)
            Util::CXMLAttConverter::SetAttribute(att, L"unit", g_UnitValueList, m_nUnit);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTabItem::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pos", m_nPos);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_TabItemTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"leader", g_LineTypeList2, m_uLeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"unit", g_UnitValueList, (UINT&)m_nUnit);

        return bres;
    }

}
