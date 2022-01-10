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
#include "pshadow.h"

namespace OWPML {

    CPShadow* CPShadow::Create()
    {
        return new CPShadow();
    }

    CPShadow* CPShadow::Clone()
    {
        CPShadow* clone = new CPShadow();

        clone->SetStyle((SHADOWSTYLETYPE)this->m_uStyle);
        clone->SetAlpha(this->m_fAlpha);
        clone->SetRadius(this->m_fRadius);
        clone->SetDirection(this->m_fDirection);
        clone->SetDistance(this->m_fDistance);
        clone->SetAlignStyle((ALIGNSTYLETYPE)this->m_uAlignStyle);
        clone->SetRotationStyle(this->m_bRotationStyle);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPShadow::CPShadow() : CExtObject(ID_PARA_Shadow), m_fAlpha(0.0), m_fRadius(0.0), m_fDirection(0.0), m_fDistance(0.0), m_bRotationStyle(false)
    {
    }

    CPShadow::~CPShadow()
    {
    }

    void CPShadow::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CPShadow, skew)
            OWPML_PARALIST_REDIRECT_FUNC(CPShadow, scale)
            OWPML_PARALIST_REDIRECT_FUNC(CPShadow, effectsColor)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPShadow)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(skew, CSkewType, ID_PARA_SkewType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(scale, CScaleType, ID_PARA_ScaleType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(effectsColor, CEffectsColorType, ID_PARA_EffectsColorType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPShadow::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"style", g_ShadowStyleList, m_uStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);
        Util::CXMLAttConverter::SetAttribute(att, L"radius", m_fRadius);
        Util::CXMLAttConverter::SetAttribute(att, L"direction", m_fDirection);
        Util::CXMLAttConverter::SetAttribute(att, L"distance", m_fDistance);
        Util::CXMLAttConverter::SetAttribute(att, L"alignStyle", g_AlignStyleList, m_uAlignStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"rotationStyle", m_bRotationStyle);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPShadow::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"style", g_ShadowStyleList, m_uStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"radius", m_fRadius);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"direction", m_fDirection);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"distance", m_fDistance);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alignStyle", g_AlignStyleList, m_uAlignStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rotationStyle", m_bRotationStyle);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CSkewType* CPShadow::Setskew(CSkewType* pskew)
    {
        CSkewType* skew = pskew;
        if (skew == NULL) {
            skew = CSkewType::Create();
        }
        SetObject((CObject*)skew);

        return skew;
    }

    CSkewType* CPShadow::Getskew(int index)
    {
        return static_cast<CSkewType*>(GetObjectByID(ID_PARA_SkewType, index));
    }

    CScaleType* CPShadow::Setscale(CScaleType* pscale)
    {
        CScaleType* scale = pscale;
        if (scale == NULL) {
            scale = CScaleType::Create();
        }
        SetObject((CObject*)scale);

        return scale;
    }

    CScaleType* CPShadow::Getscale(int index)
    {
        return static_cast<CScaleType*>(GetObjectByID(ID_PARA_ScaleType, index));
    }

    CEffectsColorType* CPShadow::SeteffectsColor(CEffectsColorType* peffectsColor)
    {
        CEffectsColorType* effectsColor = peffectsColor;
        if (effectsColor == NULL) {
            effectsColor = CEffectsColorType::Create();
        }
        SetObject((CObject*)effectsColor);

        return effectsColor;
    }

    CEffectsColorType* CPShadow::GeteffectsColor(int index)
    {
        return static_cast<CEffectsColorType*>(GetObjectByID(ID_PARA_EffectsColorType, index));
    }

}
