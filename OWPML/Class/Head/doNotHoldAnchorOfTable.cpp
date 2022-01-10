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
#include "doNotHoldAnchorOfTable.h"

namespace OWPML {


    CDoNotHoldAnchorOfTable* CDoNotHoldAnchorOfTable::Create()
    {
        return new CDoNotHoldAnchorOfTable();
    }

    CDoNotHoldAnchorOfTable::CDoNotHoldAnchorOfTable() : CExtObject(ID_HEAD_DoNotHoldAnchorOfTable)
    {
    }

    CDoNotHoldAnchorOfTable::~CDoNotHoldAnchorOfTable()
    {
    }

    void CDoNotHoldAnchorOfTable::InitMap(bool /*bRead*/)
    {
    }

    bool CDoNotHoldAnchorOfTable::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDoNotHoldAnchorOfTable::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

}
