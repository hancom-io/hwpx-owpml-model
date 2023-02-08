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
#include "tabProperties.h"

namespace OWPML {

    CTabProperties* CTabProperties::Create()
    {
        return new CTabProperties();
    }

    CTabProperties::CTabProperties() : CExtObject(ID_HEAD_TabProperties), m_uItemCnt(0)
    {
    }

    CTabProperties::~CTabProperties()
    {
    }

    void CTabProperties::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CTabProperties, tabPr)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTabProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(tabPr, CTabDefType, ID_HEAD_TabDefType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTabProperties::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTabProperties::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTabDefType* CTabProperties::SettabPr(CTabDefType* ptabPr)
    {
        CTabDefType* tabPr = ptabPr;
        if (tabPr == NULL) {
            tabPr = CTabDefType::Create();
        }
        SetObject((CObject*)tabPr);

        return tabPr;
    }

    CTabDefType* CTabProperties::GettabPr(int index)
    {
        return static_cast<CTabDefType*>(GetObjectByID(ID_HEAD_TabDefType, index));
    }

}
