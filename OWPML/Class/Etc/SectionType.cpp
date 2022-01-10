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
#include "SectionType.h"

namespace OWPML {

    CSectionType* CSectionType::Create()
    {
        return new CSectionType();
    }

    CSectionType* CSectionType::Clone()
    {
        CSectionType* clone = new CSectionType();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CSectionType::CSectionType() : CNamedObject(ID_BODY_SectionType)
    {
        SetElemName(L"hs:sec");
    }

    CSectionType::~CSectionType()
    {
    }

    void CSectionType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CSectionType, p)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CSectionType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(p, CPType, ID_PARA_PType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CSectionType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSectionType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPType* CSectionType::Setp(CPType* pp)
    {
        CPType* p = pp;
        if (p == NULL) {
            p = CPType::Create();
        }
        SetObject((CObject*)p);

        return p;
    }

    CPType* CSectionType::Getp(int index)
    {
        return static_cast<CPType*>(GetObjectByID(ID_PARA_PType, index));
    }

}
