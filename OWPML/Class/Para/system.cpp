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
#include "system.h"

namespace OWPML {


    CSystem* CSystem::Create()
    {
        return new CSystem();
    }

    CSystem* CSystem::Clone()
    {
        CSystem* clone = new CSystem();

        clone->SetH(this->m_uH);
        clone->SetS(this->m_uS);
        clone->SetL(this->m_uL);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CSystem::CSystem() : CExtObject(ID_PARA_System), m_uH(0), m_uS(0), m_uL(0)
    {
    }

    CSystem::~CSystem()
    {
    }

    void CSystem::InitMap(bool /*bRead*/)
    {
    }

    bool CSystem::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"h", m_uH);
        Util::CXMLAttConverter::SetAttribute(att, L"s", m_uS);
        Util::CXMLAttConverter::SetAttribute(att, L"l", m_uL);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSystem::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"h", m_uH);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"s", m_uS);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"l", m_uL);

        return bres;
    }

}
