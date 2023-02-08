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
#include "numberings.h"

namespace OWPML {

    CNumberings* CNumberings::Create()
    {
        return new CNumberings();
    }

    CNumberings::CNumberings() : CExtObject(ID_HEAD_Numberings), m_uItemCnt(0)
    {
    }

    CNumberings::~CNumberings()
    {
    }

    void CNumberings::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CNumberings, numbering)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CNumberings)
            OWPML_HEAD_ADD_REDIRECT_FUNC(numbering, CNumberingType, ID_HEAD_NumberingType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CNumberings::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNumberings::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CNumberingType* CNumberings::Setnumbering(CNumberingType* pnumbering)
    {
        CNumberingType* numbering = pnumbering;
        if (numbering == NULL) {
            numbering = CNumberingType::Create();
        }
        SetObject((CObject*)numbering);

        return numbering;
    }

    CNumberingType* CNumberings::Getnumbering(int index)
    {
        return static_cast<CNumberingType*>(GetObjectByID(ID_HEAD_NumberingType, index));
    }

}
