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
#include "MasterPageType.h"

namespace OWPML {

    CMasterPageType* CMasterPageType::Create()
    {
        return new CMasterPageType();
    }

    CMasterPageType::CMasterPageType() : CNamedObject(ID_MASTERPAGE_MasterPageType), m_uType(MPT_BOTH), m_uPageNumber(0), m_bPageDuplicate(false), m_bPageFront(false)
    {
        SetElemName(L"masterPage");
    }

    CMasterPageType::~CMasterPageType()
    {
    }

    void CMasterPageType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CMasterPageType, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CMasterPageType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CMasterPageType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_MasterPageTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"pageNumber", m_uPageNumber);
        Util::CXMLAttConverter::SetAttribute(att, L"pageDuplicate", m_bPageDuplicate);
        Util::CXMLAttConverter::SetAttribute(att, L"pageFront", m_bPageFront);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMasterPageType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_MasterPageTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageNumber", m_uPageNumber);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageDuplicate", m_bPageDuplicate);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageFront", m_bPageFront);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaListType* CMasterPageType::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CMasterPageType::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
