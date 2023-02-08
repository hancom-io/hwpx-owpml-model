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
#include "NoteType.h"

namespace OWPML {

    CNoteType* CNoteType::Create()
    {
        return new CNoteType(ID_PARA_FootNoteType);
    }

    CNoteType* CNoteType::Clone()
    {
        CNoteType* clone = new CNoteType(ID_PARA_FootNoteType);

        clone->SetFlags(this->m_Flags);
        clone->SetNumber(this->m_Number);
        clone->SetUserChar(this->m_UserChar);
        clone->SetPrefixChar(this->m_PrefixChar);
        clone->SetSuffixChar(this->m_SuffixChar);
        clone->SetInstID(this->m_InstID);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CNoteType* CNoteType::CreateArg(UINT id)
    {
        return new CNoteType(id);
    }

    CNoteType::CNoteType(UINT id) : CExtObject(id), m_Flags(0), m_Number(0), m_UserChar(0), m_PrefixChar(0), m_SuffixChar(0), m_InstID(0)
    {
    }

    CNoteType::~CNoteType()
    {
    }

    void CNoteType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CNoteType, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CNoteType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CNoteType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (m_Flags > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"flag", m_Flags);

        if (m_Number > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"number", m_Number);

        if (m_UserChar > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"userChar", m_UserChar);

        if (m_PrefixChar > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"prefixChar", m_PrefixChar);

        if (m_SuffixChar > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"suffixChar", m_SuffixChar);

        if (m_InstID > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"instId", m_InstID);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNoteType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"flag", m_Flags);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"number", m_Number);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"userChar", (unsigned short&)m_UserChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"prefixChar", (unsigned short&)m_PrefixChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"suffixChar", (unsigned short&)m_SuffixChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"instId", m_InstID);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaListType* CNoteType::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CNoteType::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
