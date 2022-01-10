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
#include "ListItemType.h"

namespace OWPML {


    CListItemType* CListItemType::Create()
    {
        return new CListItemType();
    }

    CListItemType* CListItemType::Clone()
    {
        CListItemType* clone = new CListItemType();

        clone->SetDisplayText(this->m_strDisplayText.c_str());
        clone->SetValue(this->m_strValue.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CListItemType::CListItemType() : CExtObject(ID_PARA_ListItemType)
    {
    }

    CListItemType::~CListItemType()
    {
    }

    void CListItemType::InitMap(bool /*bRead*/)
    {
    }

    bool CListItemType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"displayText", m_strDisplayText);
        Util::CXMLAttConverter::SetAttribute(att, L"value", m_strValue);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CListItemType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"displayText", m_strDisplayText);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", m_strValue);

        return bres;
    }

}
