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
#include "tab.h"

namespace OWPML {


    CTab* CTab::Create()
    {
        return new CTab();
    }

    CTab* CTab::Clone()
    {
        CTab* clone = new CTab();

        clone->Setwidth(this->m_uWidth);
        clone->Setleader(this->m_uLeader);
        clone->Settype(this->m_uType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CTab::CTab() : CExtObject(ID_PARA_Tab), m_uWidth(0), m_uLeader(0), m_uType(0)
    {
    }

    CTab::~CTab()
    {
    }

    void CTab::InitMap(bool /*bRead*/)
    {
    }

    bool CTab::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"leader", m_uLeader);
        Util::CXMLAttConverter::SetAttribute(att, L"type", m_uType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTab::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"leader", m_uLeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", m_uType);

        return bres;
    }

}
