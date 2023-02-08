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
#include "HistoryEntryType.h"

namespace OWPML {

    CHistoryEntryType* CHistoryEntryType::Create()
    {
        return new CHistoryEntryType();
    }

    CHistoryEntryType::CHistoryEntryType() : CExtObject(ID_HISTORY_HistoryEntryType), m_uRevisionNumber(0), m_AutoSave(false)
    {
    }

    CHistoryEntryType::~CHistoryEntryType()
    {
    }

    void CHistoryEntryType::InitMap(bool bRead)
    {
        OWPML_HISTORY_REDIRECT_FUNC(CHistoryEntryType, packageDiff)
            OWPML_HISTORY_REDIRECT_FUNC(CHistoryEntryType, headDiff)
            OWPML_HISTORY_REDIRECT_FUNC(CHistoryEntryType, bodyDiff)
            OWPML_HISTORY_REDIRECT_FUNC(CHistoryEntryType, tailDiff)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CHistoryEntryType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(packageDiff, CDiffEntryType, ID_HISTORY_PackageDiffEntryType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(headDiff, CDiffEntryType, ID_HISTORY_HeadDiffEntryType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(bodyDiff, CDiffEntryType, ID_HISTORY_BodyDiffEntryType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(tailDiff, CDiffEntryType, ID_HISTORY_TailDiffEntryType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CHistoryEntryType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"revisionNumber", m_uRevisionNumber);
        Util::CXMLAttConverter::SetAttribute(att, L"revisionDate", m_strRevisionDate);
        Util::CXMLAttConverter::SetAttribute(att, L"revisionAuthor", m_strRevisionAuthor);
        Util::CXMLAttConverter::SetAttribute(att, L"revisionDesc", m_strRevisionDescription);
        Util::CXMLAttConverter::SetAttribute(att, L"autoSave", m_AutoSave);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHistoryEntryType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"revisionNumber", m_uRevisionNumber);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"revisionDate", m_strRevisionDate);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"revisionAuthor", m_strRevisionAuthor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"revisionDesc", m_strRevisionDescription);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"autoSave", m_AutoSave);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CDiffEntryType* CHistoryEntryType::SetpackageDiff(CDiffEntryType* ppackageDiff)
    {
        CDiffEntryType* packageDiff = ppackageDiff;
        if (packageDiff == NULL) {
            packageDiff = CDiffEntryType::CreateArg(ID_HISTORY_PackageDiffEntryType);
        }
        SetObject((CObject*)packageDiff);

        return packageDiff;
    }

    CDiffEntryType* CHistoryEntryType::GetpackageDiff(int index)
    {
        return static_cast<CDiffEntryType*>(GetObjectByID(ID_HISTORY_PackageDiffEntryType, index));
    }

    CDiffEntryType* CHistoryEntryType::SetheadDiff(CDiffEntryType* pheadDiff)
    {
        CDiffEntryType* headDiff = pheadDiff;
        if (headDiff == NULL) {
            headDiff = CDiffEntryType::CreateArg(ID_HISTORY_HeadDiffEntryType);
        }
        SetObject((CObject*)headDiff);

        return headDiff;
    }

    CDiffEntryType* CHistoryEntryType::GetheadDiff(int index)
    {
        return static_cast<CDiffEntryType*>(GetObjectByID(ID_HISTORY_HeadDiffEntryType, index));
    }

    CDiffEntryType* CHistoryEntryType::SetbodyDiff(CDiffEntryType* pbodyDiff)
    {
        CDiffEntryType* bodyDiff = pbodyDiff;
        if (bodyDiff == NULL) {
            bodyDiff = CDiffEntryType::CreateArg(ID_HISTORY_BodyDiffEntryType);
        }
        SetObject((CObject*)bodyDiff);

        return bodyDiff;
    }

    CDiffEntryType* CHistoryEntryType::GetbodyDiff(int index)
    {
        return static_cast<CDiffEntryType*>(GetObjectByID(ID_HISTORY_BodyDiffEntryType, index));
    }

    CDiffEntryType* CHistoryEntryType::SettailDiff(CDiffEntryType* ptailDiff)
    {
        CDiffEntryType* tailDiff = ptailDiff;
        if (tailDiff == NULL) {
            tailDiff = CDiffEntryType::CreateArg(ID_HISTORY_TailDiffEntryType);
        }
        SetObject((CObject*)tailDiff);

        return tailDiff;
    }

    CDiffEntryType* CHistoryEntryType::GettailDiff(int index)
    {
        return static_cast<CDiffEntryType*>(GetObjectByID(ID_HISTORY_TailDiffEntryType, index));
    }

}
