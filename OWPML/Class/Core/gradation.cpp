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
#include "gradation.h"

namespace OWPML {

    CGradation* CGradation::Create()
    {
        return new CGradation();
    }

    CGradation* CGradation::Clone()
    {
        CGradation* clone = new CGradation();

        clone->SetType((GRADATIONTYPE)this->m_uType);
        clone->SetAngle(this->m_nAngle);
        clone->SetCenterX(this->m_nCenterX);
        clone->SetCenterY(this->m_nCenterY);
        clone->SetStep(this->m_nStep);
        clone->SetColorNum(this->m_uColorNum);
        clone->SetStepCenter(this->m_nStepCenter);
        clone->SetAlpha(this->m_fAlpha);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CGradation::CGradation() : CExtObject(ID_CORE_Gradation), m_nAngle(90), m_nCenterX(0), m_nCenterY(0), m_nStep(50), m_uColorNum(2), m_nStepCenter(50), m_fAlpha(0.0), m_uType(0)
    {
    }

    CGradation::~CGradation()
    {
    }

    void CGradation::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CGradation, color)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CGradation)
            OWPML_CORE_ADD_REDIRECT_FUNC(color, CColor, ID_CORE_Color)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CGradation::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_GradationTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"angle", m_nAngle);
        Util::CXMLAttConverter::SetAttribute(att, L"centerX", m_nCenterX);
        Util::CXMLAttConverter::SetAttribute(att, L"centerY", m_nCenterY);
        Util::CXMLAttConverter::SetAttribute(att, L"step", m_nStep);
        Util::CXMLAttConverter::SetAttribute(att, L"colorNum", m_uColorNum);
        Util::CXMLAttConverter::SetAttribute(att, L"stepCenter", m_nStepCenter);
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CGradation::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_GradationTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"angle", m_nAngle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"centerX", m_nCenterX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"centerY", m_nCenterY);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"step", m_nStep);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"colorNum", m_uColorNum);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"stepCenter", m_nStepCenter);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CColor* CGradation::Setcolor(CColor* pcolor)
    {
        CColor* color = pcolor;
        if (color == NULL) {
            color = CColor::Create();
        }
        SetObject((CObject*)color);

        return color;
    }

    CColor* CGradation::Getcolor(int index)
    {
        return static_cast<CColor*>(GetObjectByID(ID_CORE_Color, index));
    }

}
