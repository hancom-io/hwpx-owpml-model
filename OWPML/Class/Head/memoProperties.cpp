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
#include "memoProperties.h"

namespace OWPML {

    CMemoProperties* CMemoProperties::Create()
    {
        return new CMemoProperties();
    }

    CMemoProperties::CMemoProperties() : CExtObject(ID_HEAD_MemoProperties), m_uItemCnt(0)
    {
    }

    CMemoProperties::~CMemoProperties()
    {
    }

    void CMemoProperties::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CMemoProperties, memoPr)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CMemoProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(memoPr, CMemoShapeType, ID_HEAD_MemoShapeType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CMemoProperties::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMemoProperties::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CMemoShapeType* CMemoProperties::SetmemoPr(CMemoShapeType* pmemoPr)
    {
        CMemoShapeType* memoPr = pmemoPr;
        if (memoPr == NULL) {
            memoPr = CMemoShapeType::Create();
        }
        SetObject((CObject*)memoPr);

        return memoPr;
    }

    CMemoShapeType* CMemoProperties::GetmemoPr(int index)
    {
        return static_cast<CMemoShapeType*>(GetObjectByID(ID_HEAD_MemoShapeType, index));
    }

}
