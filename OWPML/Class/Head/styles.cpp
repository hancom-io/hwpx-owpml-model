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
#include "styles.h"

namespace OWPML {

    CStyles* CStyles::Create()
    {
        return new CStyles();
    }

    CStyles::CStyles() : CExtObject(ID_HEAD_Styles), m_uItemCnt(0)
    {
    }

    CStyles::~CStyles()
    {
    }

    void CStyles::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CStyles, style)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CStyles)
            OWPML_HEAD_ADD_REDIRECT_FUNC(style, CStyleType, ID_HEAD_StyleType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CStyles::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CStyles::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CStyleType* CStyles::Setstyle(CStyleType* pstyle)
    {
        CStyleType* style = pstyle;
        if (style == NULL) {
            style = CStyleType::Create();
        }
        SetObject((CObject*)style);

        return style;
    }

    CStyleType* CStyles::Getstyle(int index)
    {
        return static_cast<CStyleType*>(GetObjectByID(ID_HEAD_StyleType, index));
    }

}
