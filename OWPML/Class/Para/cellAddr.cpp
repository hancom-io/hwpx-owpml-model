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
#include "cellAddr.h"

namespace OWPML {


    CCellAddr* CCellAddr::Create()
    {
        return new CCellAddr();
    }

    CCellAddr* CCellAddr::Clone()
    {
        CCellAddr* clone = new CCellAddr();

        clone->SetColAddr(this->m_uColAddr);
        clone->SetRowAddr(this->m_uRowAddr);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCellAddr::CCellAddr() : CExtObject(ID_PARA_CellAddr), m_uColAddr(0), m_uRowAddr(0)
    {
    }

    CCellAddr::~CCellAddr()
    {
    }

    void CCellAddr::InitMap(bool /*bRead*/)
    {
    }

    bool CCellAddr::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"colAddr", m_uColAddr);
        Util::CXMLAttConverter::SetAttribute(att, L"rowAddr", m_uRowAddr);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCellAddr::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"colAddr", m_uColAddr);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rowAddr", m_uRowAddr);

        return bres;
    }

}
