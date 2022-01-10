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
#include "formCharPr.h"

namespace OWPML {


    CFormCharPr* CFormCharPr::Create()
    {
        return new CFormCharPr();
    }

    CFormCharPr* CFormCharPr::Clone()
    {
        CFormCharPr* clone = new CFormCharPr();

        clone->SetCharPrIDRef(this->m_uCharPrIDRef);
        clone->SetFollowContext(this->m_bFollowContext);
        clone->SetAutoSz(this->m_bAutoSz);
        clone->SetWordWrap(this->m_bWordWrap);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFormCharPr::CFormCharPr() : CExtObject(ID_PARA_FormCharPr), m_bFollowContext(false), m_bAutoSz(false), m_bWordWrap(false)
    {
    }

    CFormCharPr::~CFormCharPr()
    {
    }

    void CFormCharPr::InitMap(bool /*bRead*/)
    {
    }

    bool CFormCharPr::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"followContext", m_bFollowContext);
        Util::CXMLAttConverter::SetAttribute(att, L"autoSz", m_bAutoSz);
        Util::CXMLAttConverter::SetAttribute(att, L"wordWrap", m_bWordWrap);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFormCharPr::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"followContext", m_bFollowContext);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"autoSz", m_bAutoSz);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"wordWrap", m_bWordWrap);

        return bres;
    }

}
