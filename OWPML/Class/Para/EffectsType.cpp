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
#include "EffectsType.h"

namespace OWPML {

    CEffectsType* CEffectsType::Create()
    {
        return new CEffectsType();
    }

    CEffectsType* CEffectsType::Clone()
    {
        CEffectsType* clone = new CEffectsType();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEffectsType::CEffectsType() : CExtObject(ID_PARA_EffectsType)
    {
    }

    CEffectsType::~CEffectsType()
    {
    }

    void CEffectsType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CEffectsType, shadow)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsType, glow)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsType, softEdge)
            OWPML_PARALIST_REDIRECT_FUNC(CEffectsType, reflection)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEffectsType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shadow, CPShadow, ID_PARA_Shadow)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(glow, CGlow, ID_PARA_Glow)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(softEdge, CSoftEdge, ID_PARA_SoftEdge)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(reflection, CReflection, ID_PARA_Reflection)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEffectsType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEffectsType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPShadow* CEffectsType::Setshadow(CPShadow* pshadow)
    {
        CPShadow* shadow = pshadow;
        if (shadow == NULL) {
            shadow = CPShadow::Create();
        }
        SetObject((CObject*)shadow);

        return shadow;
    }

    CPShadow* CEffectsType::Getshadow(int index)
    {
        return static_cast<CPShadow*>(GetObjectByID(ID_PARA_Shadow, index));
    }

    CGlow* CEffectsType::Setglow(CGlow* pglow)
    {
        CGlow* glow = pglow;
        if (glow == NULL) {
            glow = CGlow::Create();
        }
        SetObject((CObject*)glow);

        return glow;
    }

    CGlow* CEffectsType::Getglow(int index)
    {
        return static_cast<CGlow*>(GetObjectByID(ID_PARA_Glow, index));
    }

    CSoftEdge* CEffectsType::SetsoftEdge(CSoftEdge* psoftEdge)
    {
        CSoftEdge* softEdge = psoftEdge;
        if (softEdge == NULL) {
            softEdge = CSoftEdge::Create();
        }
        SetObject((CObject*)softEdge);

        return softEdge;
    }

    CSoftEdge* CEffectsType::GetsoftEdge(int index)
    {
        return static_cast<CSoftEdge*>(GetObjectByID(ID_PARA_SoftEdge, index));
    }

    CReflection* CEffectsType::Setreflection(CReflection* preflection)
    {
        CReflection* reflection = preflection;
        if (reflection == NULL) {
            reflection = CReflection::Create();
        }
        SetObject((CObject*)reflection);

        return reflection;
    }

    CReflection* CEffectsType::Getreflection(int index)
    {
        return static_cast<CReflection*>(GetObjectByID(ID_PARA_Reflection, index));
    }

}
