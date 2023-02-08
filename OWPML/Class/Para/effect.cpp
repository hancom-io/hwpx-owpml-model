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
#include "effect.h"

namespace OWPML {


    CEffect* CEffect::Create()
    {
        return new CEffect();
    }

    CEffect* CEffect::Clone()
    {
        CEffect* clone = new CEffect();

        clone->SetType((EFFECTTYPE)this->m_uType);
        clone->SetValue(this->m_fValue);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEffect::CEffect() : CExtObject(ID_PARA_Effect)
    {
    }

    CEffect::~CEffect()
    {
    }

    void CEffect::InitMap(bool /*bRead*/)
    {
    }

    bool CEffect::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_EffectList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"value", m_fValue);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEffect::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_EffectList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", m_fValue);

        return bres;
    }

}
