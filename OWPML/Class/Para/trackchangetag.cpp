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
#include "trackchangetag.h"

namespace OWPML {
    CTrackChangeTag* CTrackChangeTag::Create()
    {
        return new CTrackChangeTag(ID_PARA_TC_InsertBegin);
    }

    CTrackChangeTag* CTrackChangeTag::CreateArg(BOOL insert, BOOL begin)
    {
        if (insert) {
            return new CTrackChangeTag(begin ? ID_PARA_TC_InsertBegin : ID_PARA_TC_InsertEnd);
        } else {
            return new CTrackChangeTag(begin ? ID_PARA_TC_DeleteBegin : ID_PARA_TC_DeleteEnd);
        }
    }


    CTrackChangeTag::CTrackChangeTag(UINT id) : CExtObject(id), m_bParaEnd(false), m_uId(0), m_uTcId(0)
    {
    }

    CTrackChangeTag::~CTrackChangeTag()
    {
    }

    void CTrackChangeTag::InitMap(bool /*bRead*/)
    {
    }

    bool CTrackChangeTag::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"Id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"TcId", m_uTcId);
        if ((GetID() == ID_PARA_TC_InsertEnd) || (GetID() == ID_PARA_TC_DeleteEnd))
            Util::CXMLAttConverter::SetAttribute(att, L"paraend", m_bParaEnd);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTrackChangeTag::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"Id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"TcId", m_uTcId);
        if ((GetID() == ID_PARA_TC_InsertEnd) || (GetID() == ID_PARA_TC_DeleteEnd))
            bres &= Util::CXMLAttConverter::GetAttribute(att, L"paraend", m_bParaEnd);
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

}
