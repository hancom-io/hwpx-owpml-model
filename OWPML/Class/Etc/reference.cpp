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
#include "reference.h"

namespace OWPML {


    CReference* CReference::Create()
    {
        return new CReference();
    }

    CReference::CReference() : CExtObject(ID_OPF_Reference)
    {
    }

    CReference::~CReference()
    {
    }

    void CReference::InitMap(bool /*bRead*/)
    {
    }

    bool CReference::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"type", m_strType);
        Util::CXMLAttConverter::SetAttribute(att, L"title", m_strTitle);
        Util::CXMLAttConverter::SetAttribute(att, L"href", m_strHref);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CReference::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", m_strType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"title", m_strTitle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"href", m_strHref);

        return bres;
    }

}
