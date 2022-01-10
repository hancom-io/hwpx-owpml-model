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
#include "markpenBegin.h"

namespace OWPML {


    CMarkpenBegin* CMarkpenBegin::Create()
    {
        return new CMarkpenBegin();
    }

    CMarkpenBegin* CMarkpenBegin::Clone()
    {
        CMarkpenBegin* clone = new CMarkpenBegin();

        clone->Setcolor(this->m_cColor);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CMarkpenBegin::CMarkpenBegin() : CExtObject(ID_PARA_MarkpenBegin)
    {
    }

    CMarkpenBegin::~CMarkpenBegin()
    {
    }

    void CMarkpenBegin::InitMap(bool /*bRead*/)
    {
    }

    bool CMarkpenBegin::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMarkpenBegin::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);
        return bres;
    }

}
