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
#include "nbSpace.h"

namespace OWPML {


    CNbSpace* CNbSpace::Create()
    {
        return new CNbSpace();
    }

    CNbSpace* CNbSpace::Clone()
    {
        CNbSpace* clone = new CNbSpace();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CNbSpace::CNbSpace() : CExtObject(ID_PARA_NbSpace)
    {
    }

    CNbSpace::~CNbSpace()
    {
    }

    void CNbSpace::InitMap(bool /*bRead*/)
    {
    }

    bool CNbSpace::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNbSpace::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

}
