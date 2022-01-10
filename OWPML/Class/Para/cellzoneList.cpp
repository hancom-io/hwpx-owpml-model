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
#include "cellzoneList.h"

namespace OWPML {

    CCellzoneList* CCellzoneList::Create()
    {
        return new CCellzoneList();
    }

    CCellzoneList::CCellzoneList() : CExtObject(ID_PARA_CellzoneList)
    {
    }

    CCellzoneList::~CCellzoneList()
    {
    }

    CCellzoneList* CCellzoneList::Clone()
    {
        CCellzoneList* clone = new CCellzoneList();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    void CCellzoneList::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CCellzoneList, cellzone)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCellzoneList)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cellzone, CCellzone, ID_PARA_Cellzone)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCellzoneList::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCellzoneList::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CCellzone* CCellzoneList::Setcellzone(CCellzone* pcellzone)
    {
        CCellzone* cellzone = pcellzone;
        if (cellzone == NULL) {
            cellzone = CCellzone::Create();
        }
        SetObject((CObject*)cellzone);

        return cellzone;
    }

    CCellzone* CCellzoneList::Getcellzone(int index)
    {
        return static_cast<CCellzone*>(GetObjectByID(ID_PARA_Cellzone, index));
    }

}
