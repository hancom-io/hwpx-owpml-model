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
#include "HeaderFooterType.h"

namespace OWPML {

    CHeaderFooterType* CHeaderFooterType::Create()
    {
        return new CHeaderFooterType(ID_PARA_HeaderType);
    }

    CHeaderFooterType* CHeaderFooterType::CreateArg(UINT id)
    {
        return new CHeaderFooterType(id);
    }

    CHeaderFooterType* CHeaderFooterType::Clone()
    {
        CHeaderFooterType* clone = new CHeaderFooterType();

        clone->SetId(this->m_uId);
        clone->SetApplyPageType((APPLYPAGETYPE)this->m_uApplyPageType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CHeaderFooterType::CHeaderFooterType(UINT id) : CExtObject(id), m_uApplyPageType(APT_BOTH)
    {
    }

    CHeaderFooterType::~CHeaderFooterType()
    {
    }

    void CHeaderFooterType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CHeaderFooterType, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CHeaderFooterType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CHeaderFooterType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"applyPageType", g_ApplyPageTypeList, m_uApplyPageType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHeaderFooterType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"applyPageType", g_ApplyPageTypeList, m_uApplyPageType);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaListType* CHeaderFooterType::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CHeaderFooterType::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
