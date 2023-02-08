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
#include "EffectsColorType.h"

namespace OWPML {

    CEffectsColorType* CEffectsColorType::Create()
    {
        return new CEffectsColorType();
    }

    CEffectsColorType* CEffectsColorType::Clone()
    {
        CEffectsColorType* clone = new CEffectsColorType();

        clone->SetType((EFFECTCOLORTYPE)this->m_uType);
        clone->SetSchemeIdx(this->m_nSchemeIdx);
        clone->SetSystemIdx(this->m_nSystemIdx);
        clone->SetPresetIdx(this->m_nPresetIdx);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEffectsColorType::CEffectsColorType() : CExtObject(ID_PARA_EffectsColorType), m_nSchemeIdx(-1), m_nSystemIdx(-1), m_nPresetIdx(-1)
    {
    }

    CEffectsColorType::~CEffectsColorType()
    {
    }

    void CEffectsColorType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CEffectsColorType, rgb)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsColorType, cmyk)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsColorType, scheme)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsColorType, system)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsColorType, effect)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEffectsColorType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(rgb, CRgb, ID_PARA_Rgb)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cmyk, CCmyk, ID_PARA_Cmyk)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(scheme, CScheme, ID_PARA_Scheme)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(system, CSystem, ID_PARA_System)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(effect, CEffect, ID_PARA_Effect)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEffectsColorType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_EffectColorList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"schemeIdx", m_nSchemeIdx);
        Util::CXMLAttConverter::SetAttribute(att, L"systemIdx", m_nSystemIdx);
        Util::CXMLAttConverter::SetAttribute(att, L"presetIdx", m_nPresetIdx);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEffectsColorType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_EffectColorList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"schemeIdx", m_nSchemeIdx);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"systemIdx", m_nSystemIdx);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"presetIdx", m_nPresetIdx);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CRgb* CEffectsColorType::Setrgb(CRgb* prgb)
    {
        CRgb* rgb = prgb;
        if (rgb == NULL) {
            rgb = CRgb::Create();
        }
        SetObject((CObject*)rgb);

        return rgb;
    }

    CRgb* CEffectsColorType::Getrgb(int index)
    {
        return static_cast<CRgb*>(GetObjectByID(ID_PARA_Rgb, index));
    }

    CCmyk* CEffectsColorType::Setcmyk(CCmyk* pcmyk)
    {
        CCmyk* cmyk = pcmyk;
        if (cmyk == NULL) {
            cmyk = CCmyk::Create();
        }
        SetObject((CObject*)cmyk);

        return cmyk;
    }

    CCmyk* CEffectsColorType::Getcmyk(int index)
    {
        return static_cast<CCmyk*>(GetObjectByID(ID_PARA_Cmyk, index));
    }

    CScheme* CEffectsColorType::Setscheme(CScheme* pscheme)
    {
        CScheme* scheme = pscheme;
        if (scheme == NULL) {
            scheme = CScheme::Create();
        }
        SetObject((CObject*)scheme);

        return scheme;
    }

    CScheme* CEffectsColorType::Getscheme(int index)
    {
        return static_cast<CScheme*>(GetObjectByID(ID_PARA_Scheme, index));
    }

    CSystem* CEffectsColorType::Setsystem(CSystem* psystem)
    {
        CSystem* system = psystem;
        if (system == NULL) {
            system = CSystem::Create();
        }
        SetObject((CObject*)system);

        return system;
    }

    CSystem* CEffectsColorType::Getsystem(int index)
    {
        return static_cast<CSystem*>(GetObjectByID(ID_PARA_System, index));
    }

    CEffect* CEffectsColorType::Seteffect(CEffect* peffect)
    {
        CEffect* effect = peffect;
        if (effect == NULL) {
            effect = CEffect::Create();
        }
        SetObject((CObject*)effect);

        return effect;
    }

    CEffect* CEffectsColorType::Geteffect(int index)
    {
        return static_cast<CEffect*>(GetObjectByID(ID_PARA_Effect, index));
    }


}
