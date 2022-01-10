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
#include "charPr.h"

namespace OWPML {


    CCharPr* CCharPr::Create()
    {
        return new CCharPr();
    }

    CCharPr* CCharPr::Clone()
    {
        CCharPr* clone = new CCharPr();

        clone->SetPrIDRef(this->m_uPrIDRef);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCharPr::CCharPr() : CExtObject(ID_PARA_CharPr), m_uPrIDRef(0)
    {
    }

    CCharPr::~CCharPr()
    {
    }

    void CCharPr::InitMap(bool /*bRead*/)
    {
    }

    bool CCharPr::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"prIDRef", m_uPrIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCharPr::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"prIDRef", m_uPrIDRef);

        return bres;
    }

}
