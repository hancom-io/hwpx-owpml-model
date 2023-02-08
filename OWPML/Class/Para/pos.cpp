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
#include "pos.h"

namespace OWPML {


    CRFPos* CRFPos::Create()
    {
        return new CRFPos();
    }

    CRFPos* CRFPos::Clone()
    {
        CRFPos* clone = new CRFPos();

        clone->SetStart(this->m_fStart);
        clone->SetEnd(this->m_fEnd);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CRFPos::CRFPos() : CExtObject(ID_PARA_RFPos), m_fStart(0.0), m_fEnd(0.0)
    {
    }

    CRFPos::~CRFPos()
    {
    }

    void CRFPos::InitMap(bool /*bRead*/)
    {
    }

    bool CRFPos::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"start", m_fStart);
        Util::CXMLAttConverter::SetAttribute(att, L"end", m_fEnd);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRFPos::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"start", m_fStart);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"end", m_fEnd);

        return bres;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    // CASOPos Declaration 

    CASOPos* CASOPos::Create()
    {
        return new CASOPos();
    }

    CASOPos* CASOPos::Clone()
    {
        CASOPos* clone = new CASOPos();

        clone->SetTreatAsChar(this->m_bTreatAsChar);
        clone->SetAffectLSpacing(clone->m_bAffectLSpacing);
        clone->SetFlowWithText(clone->m_bFlowWithText);
        clone->SetAllowOverlap(clone->m_bAllowOverlap);
        clone->SetHoldAnchorAndSO(clone->m_bHoldAnchorAndSO);
        clone->SetVertRelTo((VERTRELTOTYPE)this->m_uVertRelTo);
        clone->SetHorzRelTo((HORZRELTOTYPE)this->m_uHorzRelTo);
        clone->SetVertAlign((VERTALIGNTYPE)this->m_uVertAlign);
        clone->SetHorzAlign((HORZALIGNTYPE)this->m_uHorzAlign);
        clone->SetVertOffset(clone->m_uVertOffset);
        clone->SetHorzOffset(clone->m_uHorzOffset);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CASOPos::CASOPos() : CExtObject(ID_PARA_ASOPos), m_bTreatAsChar(false), m_bAffectLSpacing(false), m_bFlowWithText(false), m_bAllowOverlap(false), m_bHoldAnchorAndSO(false), m_uVertOffset(0), m_uHorzOffset(0), m_uVertRelTo(0), m_uHorzRelTo(0), m_uVertAlign(0), m_uHorzAlign(0)
    {
    }

    CASOPos::~CASOPos()
    {
    }

    void CASOPos::InitMap(bool /*bRead*/)
    {
    }

    bool CASOPos::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"treatAsChar", m_bTreatAsChar);
        Util::CXMLAttConverter::SetAttribute(att, L"affectLSpacing", m_bAffectLSpacing);
        Util::CXMLAttConverter::SetAttribute(att, L"flowWithText", m_bFlowWithText);
        Util::CXMLAttConverter::SetAttribute(att, L"allowOverlap", m_bAllowOverlap);
        Util::CXMLAttConverter::SetAttribute(att, L"holdAnchorAndSO", m_bHoldAnchorAndSO);
        Util::CXMLAttConverter::SetAttribute(att, L"vertRelTo", g_VertRelToList, m_uVertRelTo);
        Util::CXMLAttConverter::SetAttribute(att, L"horzRelTo", g_HorzRelToList, m_uHorzRelTo);
        Util::CXMLAttConverter::SetAttribute(att, L"vertAlign", g_VertAlignList, m_uVertAlign);
        Util::CXMLAttConverter::SetAttribute(att, L"horzAlign", g_HorzAlignList, m_uHorzAlign);
        Util::CXMLAttConverter::SetAttribute(att, L"vertOffset", m_uVertOffset);
        Util::CXMLAttConverter::SetAttribute(att, L"horzOffset", m_uHorzOffset);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CASOPos::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"treatAsChar", m_bTreatAsChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"affectLSpacing", m_bAffectLSpacing);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"flowWithText", m_bFlowWithText);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"allowOverlap", m_bAllowOverlap);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"holdAnchorAndSO", m_bHoldAnchorAndSO);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertRelTo", g_VertRelToList, m_uVertRelTo);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horzRelTo", g_HorzRelToList, m_uHorzRelTo);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertAlign", g_VertAlignList, m_uVertAlign);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horzAlign", g_HorzAlignList, m_uHorzAlign);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertOffset", m_uVertOffset);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horzOffset", m_uHorzOffset);

        return bres;
    }

}
