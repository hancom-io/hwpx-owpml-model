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
#include "charProperties.h"

namespace OWPML {

    CCharProperties* CCharProperties::Create()
    {
        return new CCharProperties();
    }

    CCharProperties::CCharProperties() : CExtObject(ID_HEAD_CharProperties), m_uItemCnt(0)
    {
    }

    CCharProperties::~CCharProperties()
    {
    }

    void CCharProperties::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CCharProperties, charPr)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCharProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(charPr, CCharShapeType, ID_HEAD_CharShapeType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCharProperties::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCharProperties::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CCharShapeType* CCharProperties::SetcharPr(CCharShapeType* pcharPr)
    {
        CCharShapeType* charPr = pcharPr;
        if (charPr == NULL) {
            charPr = CCharShapeType::Create();
        }
        SetObject((CObject*)charPr);

        return charPr;
    }

    CCharShapeType* CCharProperties::GetcharPr(int index)
    {
        return static_cast<CCharShapeType*>(GetObjectByID(ID_HEAD_CharShapeType, index));
    }

}
