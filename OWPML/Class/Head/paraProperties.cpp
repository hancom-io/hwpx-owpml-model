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
#include "paraProperties.h"

namespace OWPML {

    CParaProperties* CParaProperties::Create()
    {
        return new CParaProperties();
    }

    CParaProperties::CParaProperties() : CExtObject(ID_HEAD_ParaProperties), m_uItemCnt(0)
    {
    }

    CParaProperties::~CParaProperties()
    {
    }

    void CParaProperties::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CParaProperties, paraPr)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CParaProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(paraPr, CParaShapeType, ID_HEAD_ParaShapeType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CParaProperties::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParaProperties::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaShapeType* CParaProperties::SetparaPr(CParaShapeType* pparaPr)
    {
        CParaShapeType* paraPr = pparaPr;
        if (paraPr == NULL) {
            paraPr = CParaShapeType::Create();
        }
        SetObject((CObject*)paraPr);

        return paraPr;
    }

    CParaShapeType* CParaProperties::GetparaPr(int index)
    {
        return static_cast<CParaShapeType*>(GetObjectByID(ID_HEAD_ParaShapeType, index));
    }

}
