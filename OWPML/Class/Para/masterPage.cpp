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
#include "masterPage.h"

namespace OWPML {


    CMasterPage* CMasterPage::Create()
    {
        return new CMasterPage();
    }

    CMasterPage* CMasterPage::Clone()
    {
        CMasterPage* clone = new CMasterPage();

        clone->SetIdRef(this->m_strIdRef.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CMasterPage::CMasterPage() : CExtObject(ID_PARA_MasterPage)
    {
    }

    CMasterPage::~CMasterPage()
    {
    }

    void CMasterPage::InitMap(bool /*bRead*/)
    {
    }

    bool CMasterPage::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"idRef", m_strIdRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMasterPage::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"idRef", m_strIdRef);

        return bres;
    }

}
