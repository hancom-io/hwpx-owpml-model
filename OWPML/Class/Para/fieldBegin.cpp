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
#include "fieldBegin.h"

namespace OWPML {

    CFieldBegin* CFieldBegin::Create()
    {
        return new CFieldBegin();
    }

    CFieldBegin* CFieldBegin::Clone()
    {
        CFieldBegin* clone = new CFieldBegin();

        clone->SetId(this->m_uId);
        clone->SetType((FIELDTYPE)(this->m_uType));
        clone->SetName(this->m_strName.c_str());
        clone->SetEditable(this->m_bEditable);
        clone->SetDirty(this->m_bDirty);
        clone->SetZorder(this->m_nZorder);
        clone->SetFieldId(this->m_uFieldid);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFieldBegin::CFieldBegin() : CExtObject(ID_PARA_FieldBegin), m_bEditable(true), m_bDirty(false), m_nZorder(-1), m_uType((UINT)FT_NONE)
    {
    }

    CFieldBegin::~CFieldBegin()
    {
    }

    void CFieldBegin::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CFieldBegin, parameters)
            OWPML_PARALIST_REDIRECT_FUNC(CFieldBegin, subList)
            // metatag & json
            OWPML_PARALIST_REDIRECT_FUNC(CFieldBegin, metaTag)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFieldBegin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameters, CParameterList, ID_PARA_ParameterList)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFieldBegin::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_FieldList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"editable", m_bEditable);
        Util::CXMLAttConverter::SetAttribute(att, L"dirty", m_bDirty);
        Util::CXMLAttConverter::SetAttribute(att, L"zorder", m_nZorder);
        Util::CXMLAttConverter::SetAttribute(att, L"fieldid", m_uFieldid);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFieldBegin::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_FieldList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"editable", m_bEditable);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"dirty", m_bDirty);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"zorder", m_nZorder);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fieldid", m_uFieldid);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParameterList* CFieldBegin::Setparameters(CParameterList* pparameters)
    {
        CParameterList* parameters = pparameters;
        if (parameters == NULL) {
            parameters = CParameterList::Create();
        }
        SetObject((CObject*)parameters);

        return parameters;
    }

    CParameterList* CFieldBegin::Getparameters(int index)
    {
        return static_cast<CParameterList*>(GetObjectByID(ID_PARA_ParameterList, index));
    }

    CParaListType* CFieldBegin::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CFieldBegin::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
