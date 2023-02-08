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
#include "borderFills.h"

namespace OWPML {

    CBorderFills* CBorderFills::Create()
    {
        return new CBorderFills();
    }

    CBorderFills::CBorderFills() : CExtObject(ID_HEAD_BorderFills), m_uItemCnt(0)
    {
    }

    CBorderFills::~CBorderFills()
    {
    }

    void CBorderFills::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CBorderFills, borderFill)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CBorderFills)
            OWPML_HEAD_ADD_REDIRECT_FUNC(borderFill, CBorderFillType, ID_HEAD_BorderFillType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CBorderFills::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBorderFills::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);


        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CBorderFillType* CBorderFills::SetborderFill(CBorderFillType* pborderFill)
    {
        CBorderFillType* borderFill = pborderFill;
        if (borderFill == NULL) {
            borderFill = CBorderFillType::Create();
        }
        SetObject((CObject*)borderFill);

        return borderFill;
    }

    CBorderFillType* CBorderFills::GetborderFill(int index)
    {
        return static_cast<CBorderFillType*>(GetObjectByID(ID_HEAD_BorderFillType, index));
    }

}
