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
#include "UpdateType.h"
#include "DeleteType.h"
#include "DiffEntryType.h"

namespace OWPML {

    CDiffEntryType* CDiffEntryType::Create()
    {
        return new CDiffEntryType(ID_HISTORY_PackageDiffEntryType);
    }

    CDiffEntryType* CDiffEntryType::CreateArg(UINT id)
    {
        return new CDiffEntryType(id);
    }

    CDiffEntryType::CDiffEntryType(UINT id) : CExtObject(id)
    {
    }

    CDiffEntryType::~CDiffEntryType()
    {
    }

    void CDiffEntryType::InitMap(bool bRead)
    {
        OWPML_HISTORY_REDIRECT_FUNC(CDiffEntryType, insert)
            OWPML_HISTORY_REDIRECT_FUNC(CDiffEntryType, update)
            OWPML_HISTORY_REDIRECT_FUNC(CDiffEntryType, delete)
            OWPML_HISTORY_REDIRECT_FUNC(CDiffEntryType, position)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CDiffEntryType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(insert, CInsertType, ID_HISTORY_InsertType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(update, CUpdateType, ID_HISTORY_UpdateType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(delete, CDeleteType, ID_HISTORY_DeleteType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(position, CPositionType, ID_HISTORY_PositionType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CDiffEntryType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"href", m_strHref);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDiffEntryType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"href", m_strHref);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CInsertType* CDiffEntryType::Setinsert(CInsertType* pinsert)
    {
        CInsertType* insert = pinsert;
        if (insert == NULL) {
            insert = CInsertType::Create();
        }
        SetObject((CObject*)insert);

        return insert;
    }

    CInsertType* CDiffEntryType::Getinsert(int index)
    {
        return static_cast<CInsertType*>(GetObjectByID(ID_HISTORY_InsertType, index));
    }

    CUpdateType* CDiffEntryType::Setupdate(CUpdateType* pupdate)
    {
        CUpdateType* update = pupdate;
        if (update == NULL) {
            update = CUpdateType::Create();
        }
        SetObject((CObject*)update);

        return update;
    }

    CUpdateType* CDiffEntryType::Getupdate(int index)
    {
        return static_cast<CUpdateType*>(GetObjectByID(ID_HISTORY_UpdateType, index));
    }

    CDeleteType* CDiffEntryType::Setdelete(CDeleteType* pdelete)
    {
        CDeleteType* _delete = pdelete;
        if (_delete == NULL) {
            _delete = CDeleteType::Create();
        }
        SetObject((CObject*)_delete);

        return _delete;
    }

    CDeleteType* CDiffEntryType::Getdelete(int index)
    {
        return static_cast<CDeleteType*>(GetObjectByID(ID_HISTORY_DeleteType, index));
    }

    CPositionType* CDiffEntryType::Setposition(CPositionType* pposition)
    {
        CPositionType* position = pposition;
        if (position == NULL) {
            position = CPositionType::Create();
        }
        SetObject((CObject*)position);

        return position;
    }

    CPositionType* CDiffEntryType::Getposition(int index)
    {
        return static_cast<CPositionType*>(GetObjectByID(ID_HISTORY_PositionType, index));
    }

}
