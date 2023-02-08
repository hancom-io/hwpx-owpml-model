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
#include "presentation.h"

namespace OWPML {

    CPresentation* CPresentation::Create()
    {
        return new CPresentation();
    }

    CPresentation* CPresentation::Clone()
    {
        CPresentation* clone = new CPresentation();

        clone->SetEffect(this->m_effect);
        clone->SetSoundIDRef(this->m_soundIDRef.c_str());
        clone->SetInvertText(this->m_invertText);
        clone->SetAutoshow(this->m_autoshow);
        clone->SetShowtime(this->m_showtime);
        clone->SetApplyto(this->m_applyto);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPresentation::CPresentation() : CExtObject(ID_PARA_PresentationType), m_effect(0), m_invertText(false), m_autoshow(false), m_showtime(1), m_applyto(0)
    {
    }

    CPresentation::~CPresentation()
    {
    }

    void CPresentation::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CPresentation, fillBrush)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPresentation)
            OWPML_CORE_ADD_REDIRECT_FUNC(fillBrush, CFillBrushType, ID_CORE_FillBrushType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPresentation::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"effect", g_PresentationEffectsList, m_effect);
        Util::CXMLAttConverter::SetAttribute(att, L"soundIDRef", m_soundIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"invertText", m_invertText ? true : false);
        Util::CXMLAttConverter::SetAttribute(att, L"autoshow", m_autoshow ? true : false);
        Util::CXMLAttConverter::SetAttribute(att, L"showtime", m_showtime);
        Util::CXMLAttConverter::SetAttribute(att, L"applyto", g_PresentationApplyToList, m_applyto);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPresentation::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE, btemp;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"effect", g_PresentationEffectsList, m_effect);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"soundIDRef", m_soundIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"invertText", btemp);
        m_invertText = btemp ? TRUE : FALSE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"autoshow", btemp);
        m_autoshow = btemp ? TRUE : FALSE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"showtime", m_showtime);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"applyto", g_PresentationApplyToList, m_applyto);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFillBrushType* CPresentation::SetfillBrush(CFillBrushType* pfillBrush)
    {
        CFillBrushType* fillBrush = pfillBrush;
        if (fillBrush == NULL) {
            fillBrush = CFillBrushType::Create();
        }
        SetObject((CObject*)fillBrush);

        return fillBrush;
    }

    CFillBrushType* CPresentation::GetfillBrush(int index)
    {
        return static_cast<CFillBrushType*>(GetObjectByID(ID_CORE_FillBrushType, index));
    }

}
