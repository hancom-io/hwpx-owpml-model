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
#include "firstKey.h"

namespace OWPML {


    CFirstKey* CFirstKey::Create()
    {
        return new CFirstKey();
    }

    CFirstKey* CFirstKey::Clone()
    {
        CFirstKey* clone = new CFirstKey();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFirstKey::CFirstKey() : CStringValueObject(ID_PARA_FirstKey)
    {
    }

    CFirstKey::~CFirstKey()
    {
    }

    void CFirstKey::InitMap(bool /*bRead*/)
    {
    }

    bool CFirstKey::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CFirstKey::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

}
