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
#include "ToursType.h"

namespace OWPML {

    CToursType* CToursType::Create()
    {
        return new CToursType();
    }

    CToursType::CToursType() : CExtObject(ID_OPF_ToursType)
    {
    }

    CToursType::~CToursType()
    {
    }

    void CToursType::InitMap(bool bRead)
    {
        OWPML_OPF_REDIRECT_FUNC(CToursType, tour)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CToursType)
            OWPML_OPF_ADD_REDIRECT_FUNC(tour, CTour, ID_OPF_Tour)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CToursType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CToursType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTour* CToursType::Settour(CTour* ptour)
    {
        CTour* tour = ptour;
        if (tour == NULL) {
            tour = CTour::Create();
        }
        SetObject((CObject*)tour);

        return tour;
    }

    CTour* CToursType::Gettour(int index)
    {
        return static_cast<CTour*>(GetObjectByID(ID_OPF_Tour, index));
    }

}
