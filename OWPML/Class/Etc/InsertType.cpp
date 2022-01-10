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
#include "AbstractDiffDataType.h"
#include "InsertType.h"

namespace OWPML {


    CInsertType* CInsertType::Create()
    {
        return new CInsertType();
    }

    CInsertType::CInsertType() : CAbstractDiffDataType(ID_HISTORY_InsertType)
    {
    }

    CInsertType::~CInsertType()
    {
    }

    void CInsertType::InitMap(bool bRead)
    {
        OWPML_HISTORY_REDIRECT_FUNC(CUpdateType, insert)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CInsertType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(insert, CInsertType, ID_HISTORY_InsertType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CInsertType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (m_strOPID.length() > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"OPID", m_strOPID);

        CAbstractDiffDataType::WriteElement(pCurObjName, serialize, att);
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CInsertType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        Util::CXMLAttConverter::GetAttribute(att, L"OPID", m_strOPID);

        bres &= CAbstractDiffDataType::ReadAttribute(att);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    CInsertType* CInsertType::Setinsert(CInsertType* pinsert)
    {
        CInsertType* insert = pinsert;
        if (insert == NULL) {
            insert = CInsertType::Create();
        }
        SetObject((CObject*)insert);

        return insert;
    }

    CInsertType* CInsertType::Getinsert(int index)
    {
        return static_cast<CInsertType*>(GetObjectByID(ID_HISTORY_InsertType, index));
    }


}
