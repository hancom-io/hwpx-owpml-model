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
#include "glow.h"

namespace OWPML {

    CGlow* CGlow::Create()
    {
        return new CGlow();
    }

    CGlow* CGlow::Clone()
    {
        CGlow* clone = new CGlow();

        clone->SetAlpha(this->m_fAlpha);
        clone->SetRadius(this->m_fRadius);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CGlow::CGlow() : CExtObject(ID_PARA_Glow), m_fAlpha(0.0), m_fRadius(0.0)
    {
    }

    CGlow::~CGlow()
    {
    }

    void CGlow::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CGlow, effectsColor)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CGlow)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(effectsColor, CEffectsColorType, ID_PARA_EffectsColorType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CGlow::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);
        Util::CXMLAttConverter::SetAttribute(att, L"radius", m_fRadius);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CGlow::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"radius", m_fRadius);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CEffectsColorType* CGlow::SeteffectsColor(CEffectsColorType* peffectsColor)
    {
        CEffectsColorType* effectsColor = peffectsColor;
        if (effectsColor == NULL) {
            effectsColor = CEffectsColorType::Create();
        }
        SetObject((CObject*)effectsColor);

        return effectsColor;
    }

    CEffectsColorType* CGlow::GeteffectsColor(int index)
    {
        return static_cast<CEffectsColorType*>(GetObjectByID(ID_PARA_EffectsColorType, index));
    }

}
