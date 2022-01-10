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
#include "tr.h"

namespace OWPML {

    CTr* CTr::Create()
    {
        return new CTr();
    }

    CTr* CTr::Clone()
    {
        CTr* clone = new CTr();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CTr::CTr() : CExtObject(ID_PARA_Tr)
    {
    }

    CTr::~CTr()
    {
    }

    void CTr::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CTr, tc)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(tc, CTc, ID_PARA_Tc)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTr::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTr::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTc* CTr::Settc(CTc* ptc)
    {
        CTc* tc = ptc;
        if (tc == NULL) {
            tc = CTc::Create();
        }
        SetObject((CObject*)tc);

        return tc;
    }

    CTc* CTr::Gettc(int index)
    {
        return static_cast<CTc*>(GetObjectByID(ID_PARA_Tc, index));
    }

}
