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
#include "placement.h"

namespace OWPML {


    CFNPlacement* CFNPlacement::Create()
    {
        return new CFNPlacement();
    }

    CFNPlacement* CFNPlacement::Clone()
    {
        CFNPlacement* clone = new CFNPlacement();

        clone->SetPlace((FNPLACEMENTTYPE)this->m_uPlace);
        clone->SetBeneathText(this->m_bBeneathText);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFNPlacement::CFNPlacement() : CExtObject(ID_PARA_FNPlacement), m_uPlace(FNPT_EACH_COLUMN), m_bBeneathText(false)
    {
    }

    CFNPlacement::~CFNPlacement()
    {
    }

    void CFNPlacement::InitMap(bool /*bRead*/)
    {
    }

    bool CFNPlacement::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"place", g_FNPlacementList, m_uPlace);
        Util::CXMLAttConverter::SetAttribute(att, L"beneathText", m_bBeneathText);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFNPlacement::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"place", g_FNPlacementList, m_uPlace);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"beneathText", m_bBeneathText);

        return bres;
    }

    CENPlacement* CENPlacement::Create()
    {
        return new CENPlacement();
    }

    CENPlacement* CENPlacement::Clone()
    {
        CENPlacement* clone = new CENPlacement();

        clone->SetPlace((ENPLACEMENTTYPE)this->m_uPlace);
        clone->SetBeneathText(this->m_bBeneathText);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CENPlacement::CENPlacement() : CExtObject(ID_PARA_ENPlacement), m_uPlace(ENPT_END_OF_DOCUMENT), m_bBeneathText(FALSE)
    {
    }

    CENPlacement::~CENPlacement()
    {
    }

    void CENPlacement::InitMap(bool /*bRead*/)
    {
    }

    bool CENPlacement::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"place", g_ENPlacementList, m_uPlace);
        Util::CXMLAttConverter::SetAttribute(att, L"beneathText", m_bBeneathText);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CENPlacement::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"place", g_ENPlacementList, m_uPlace);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"beneathText", m_bBeneathText);

        return bres;
    }

}
