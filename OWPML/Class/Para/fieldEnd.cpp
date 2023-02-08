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
#include "fieldEnd.h"

namespace OWPML {


    CFieldEnd* CFieldEnd::Create()
    {
        return new CFieldEnd();
    }

    CFieldEnd::CFieldEnd() : CExtObject(ID_PARA_FieldEnd)
    {
    }

    CFieldEnd* CFieldEnd::Clone()
    {
        CFieldEnd* clone = new CFieldEnd();

        clone->SetBeginIDRef(this->m_uBeginIDRef);
        clone->SetFieldId(this->m_uFieldid);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFieldEnd::~CFieldEnd()
    {
    }

    void CFieldEnd::InitMap(bool /*bRead*/)
    {
    }

    bool CFieldEnd::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"beginIDRef", m_uBeginIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"fieldid", m_uFieldid);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFieldEnd::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"beginIDRef", m_uBeginIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fieldid", m_uFieldid);

        return bres;
    }

}
