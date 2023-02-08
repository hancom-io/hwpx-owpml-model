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
#include "GuideType.h"

namespace OWPML {

    CGuideType* CGuideType::Create()
    {
        return new CGuideType();
    }

    CGuideType::CGuideType() : CExtObject(ID_OPF_GuideType)
    {
    }

    CGuideType::~CGuideType()
    {
    }

    void CGuideType::InitMap(bool bRead)
    {
        OWPML_OPF_REDIRECT_FUNC(CGuideType, reference)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CGuideType)
            OWPML_OPF_ADD_REDIRECT_FUNC(reference, CReference, ID_OPF_Reference)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CGuideType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CGuideType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CReference* CGuideType::Setreference(CReference* preference)
    {
        CReference* reference = preference;
        if (reference == NULL) {
            reference = CReference::Create();
        }
        SetObject((CObject*)reference);

        return reference;
    }

    CReference* CGuideType::Getreference(int index)
    {
        return static_cast<CReference*>(GetObjectByID(ID_OPF_Reference, index));
    }

}
