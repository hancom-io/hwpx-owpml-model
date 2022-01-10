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
#include "reflection.h"

namespace OWPML {

    CReflection* CReflection::Create()
    {
        return new CReflection();
    }

    CReflection* CReflection::Clone()
    {
        CReflection* clone = new CReflection();

        clone->SetAlignStyle((ALIGNSTYLETYPE)this->m_uAlignStyle);
        clone->SetRadius(this->m_fRadius);
        clone->SetDirection(this->m_fDirection);
        clone->SetDistance(this->m_fDistance);
        clone->SetRotationStyle(this->m_bRotationStyle);
        clone->SetFadeDirection(this->m_fFadeDirection);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CReflection::CReflection() : CExtObject(ID_PARA_Reflection), m_fRadius(0.0), m_fDirection(0.0), m_fDistance(0.0), m_bRotationStyle(false), m_fFadeDirection(0.0)
    {
    }

    CReflection::~CReflection()
    {
    }

    void CReflection::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CReflection, skew)
            OWPML_PARALIST_REDIRECT_FUNC(CReflection, scale)
            OWPML_PARALIST_REDIRECT_FUNC(CReflection, alpha)
            OWPML_PARALIST_REDIRECT_FUNC(CReflection, pos)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CReflection)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(skew, CSkewType, ID_PARA_SkewType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(scale, CScaleType, ID_PARA_ScaleType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(alpha, CAlpha, ID_PARA_Alpha)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CRFPos, ID_PARA_RFPos)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CReflection::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"alignStyle", g_AlignStyleList, m_uAlignStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"radius", m_fRadius);
        Util::CXMLAttConverter::SetAttribute(att, L"direction", m_fDirection);
        Util::CXMLAttConverter::SetAttribute(att, L"distance", m_fDistance);
        Util::CXMLAttConverter::SetAttribute(att, L"rotationStyle", m_bRotationStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"fadeDirection", m_fFadeDirection);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CReflection::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alignStyle", g_AlignStyleList, m_uAlignStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"radius", m_fRadius);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"direction", m_fDirection);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"distance", m_fDistance);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rotationStyle", m_bRotationStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fadeDirection", m_fFadeDirection);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CSkewType* CReflection::Setskew(CSkewType* pskew)
    {
        CSkewType* skew = pskew;
        if (skew == NULL) {
            skew = CSkewType::Create();
        }
        SetObject((CObject*)skew);

        return skew;
    }

    CSkewType* CReflection::Getskew(int index)
    {
        return static_cast<CSkewType*>(GetObjectByID(ID_PARA_SkewType, index));
    }

    CScaleType* CReflection::Setscale(CScaleType* pscale)
    {
        CScaleType* scale = pscale;
        if (scale == NULL) {
            scale = CScaleType::Create();
        }
        SetObject((CObject*)scale);

        return scale;
    }

    CScaleType* CReflection::Getscale(int index)
    {
        return static_cast<CScaleType*>(GetObjectByID(ID_PARA_ScaleType, index));
    }

    CAlpha* CReflection::Setalpha(CAlpha* palpha)
    {
        CAlpha* alpha = palpha;
        if (alpha == NULL) {
            alpha = CAlpha::Create();
        }
        SetObject((CObject*)alpha);

        return alpha;
    }

    CAlpha* CReflection::Getalpha(int index)
    {
        return static_cast<CAlpha*>(GetObjectByID(ID_PARA_Alpha, index));
    }

    CRFPos* CReflection::Setpos(CRFPos* ppos)
    {
        CRFPos* pos = ppos;
        if (pos == NULL) {
            pos = CRFPos::Create();
        }
        SetObject((CObject*)pos);

        return pos;
    }

    CRFPos* CReflection::Getpos(int index)
    {
        return static_cast<CRFPos*>(GetObjectByID(ID_PARA_RFPos, index));
    }

}
