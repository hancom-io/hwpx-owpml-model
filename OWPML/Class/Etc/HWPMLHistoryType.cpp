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
#include "HWPMLHistoryType.h"

namespace OWPML {

    CHWPMLHistoryType* CHWPMLHistoryType::Create()
    {
        return new CHWPMLHistoryType();
    }

    CHWPMLHistoryType::CHWPMLHistoryType() : CNamedObject(ID_HISTORY_HWPMLHistoryType)
    {
        SetElemName(L"hhs:history");
    }

    CHWPMLHistoryType::~CHWPMLHistoryType()
    {
    }

    void CHWPMLHistoryType::InitMap(bool bRead)
    {
        OWPML_HISTORY_REDIRECT_FUNC(CHWPMLHistoryType, historyEntry)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CHWPMLHistoryType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(historyEntry, CHistoryEntryType, ID_HISTORY_HistoryEntryType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CHWPMLHistoryType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"version", m_strVersion);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHWPMLHistoryType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"version", m_strVersion);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CHistoryEntryType* CHWPMLHistoryType::SethistoryEntry(CHistoryEntryType* phistoryEntry)
    {
        CHistoryEntryType* historyEntry = phistoryEntry;
        if (historyEntry == NULL) {
            historyEntry = CHistoryEntryType::Create();
        }
        SetObject((CObject*)historyEntry);

        return historyEntry;
    }

    CHistoryEntryType* CHWPMLHistoryType::GethistoryEntry(int index)
    {
        return static_cast<CHistoryEntryType*>(GetObjectByID(ID_HISTORY_HistoryEntryType, index));
    }

}
