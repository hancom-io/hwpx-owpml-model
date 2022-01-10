﻿/*
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
#include "hypen.h"

namespace OWPML {


    CHypen* CHypen::Create()
    {
        return new CHypen();
    }

    CHypen* CHypen::Clone()
    {
        CHypen* clone = new CHypen();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CHypen::CHypen() : CExtObject(ID_PARA_Hypen)
    {
    }

    CHypen::~CHypen()
    {
    }

    void CHypen::InitMap(bool /*bRead*/)
    {
    }

    bool CHypen::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHypen::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

}
