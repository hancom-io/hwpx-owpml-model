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
#include "CompatibleDocumentType.h"

namespace OWPML {

    CCompatibleDocumentType* CCompatibleDocumentType::Create()
    {
        return new CCompatibleDocumentType();
    }

    CCompatibleDocumentType::CCompatibleDocumentType() : CExtObject(ID_HEAD_CompatibleDocumentType), m_uTargetProgram(0)
    {
    }

    CCompatibleDocumentType::~CCompatibleDocumentType()
    {
    }

    void CCompatibleDocumentType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CCompatibleDocumentType, layoutCompatibility)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCompatibleDocumentType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(layoutCompatibility, CLayoutCompatibility, ID_HEAD_LayoutCompatibility)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCompatibleDocumentType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"targetProgram", g_CompatiblieDocList, m_uTargetProgram);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCompatibleDocumentType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"targetProgram", g_CompatiblieDocList, m_uTargetProgram);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CLayoutCompatibility* CCompatibleDocumentType::SetlayoutCompatibility(CLayoutCompatibility* playoutCompatibility)
    {
        CLayoutCompatibility* layoutCompatibility = playoutCompatibility;
        if (layoutCompatibility == NULL) {
            layoutCompatibility = CLayoutCompatibility::Create();
        }
        SetObject((CObject*)layoutCompatibility);

        return layoutCompatibility;
    }

    CLayoutCompatibility* CCompatibleDocumentType::GetlayoutCompatibility(int index)
    {
        return static_cast<CLayoutCompatibility*>(GetObjectByID(ID_HEAD_LayoutCompatibility, index));
    }

}
