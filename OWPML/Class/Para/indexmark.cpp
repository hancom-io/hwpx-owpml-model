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
#include "indexmark.h"

namespace OWPML {

    CIndexmark* CIndexmark::Create()
    {
        return new CIndexmark();
    }

    CIndexmark* CIndexmark::Clone()
    {
        CIndexmark* clone = new CIndexmark();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CIndexmark::CIndexmark() : CExtObject(ID_PARA_Indexmark)
    {
    }

    CIndexmark::~CIndexmark()
    {
    }

    void CIndexmark::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CIndexmark, firstKey)
            OWPML_PARALIST_REDIRECT_FUNC(CIndexmark, secondKey)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CIndexmark)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(firstKey, CFirstKey, ID_PARA_FirstKey)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(secondKey, CSecondKey, ID_PARA_SecondKey)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CIndexmark::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CIndexmark::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFirstKey* CIndexmark::SetfirstKey(CFirstKey* pfirstKey)
    {
        CFirstKey* firstKey = pfirstKey;
        if (firstKey == NULL) {
            firstKey = CFirstKey::Create();
        }
        SetObject((CObject*)firstKey);

        return firstKey;
    }

    CFirstKey* CIndexmark::GetfirstKey(int index)
    {
        return static_cast<CFirstKey*>(GetObjectByID(ID_PARA_FirstKey, index));
    }

    CSecondKey* CIndexmark::SetsecondKey(CSecondKey* psecondKey)
    {
        CSecondKey* secondKey = psecondKey;
        if (secondKey == NULL) {
            secondKey = CSecondKey::Create();
        }
        SetObject((CObject*)secondKey);

        return secondKey;
    }

    CSecondKey* CIndexmark::GetsecondKey(int index)
    {
        return static_cast<CSecondKey*>(GetObjectByID(ID_PARA_SecondKey, index));
    }

}
