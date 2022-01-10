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
#include "ParaListType.h"

namespace OWPML {

    CParaListType* CParaListType::Create()
    {
        return new CParaListType();
    }

    CParaListType* CParaListType::Clone()
    {
        CParaListType* clone = new CParaListType();

        clone->SetId(this->m_strId.c_str());
        clone->SetTextDirection((PARATEXTDIRECTTYPE)this->m_uTextDirection);
        clone->SetLineWrap((PARALINEWRAPTYPE)this->m_uLineWrap);
        clone->SetVertAlign((PARAVERTALIGNTYPE)this->m_uVertAlign);
        clone->SetLinkListIDRef(this->m_uLinkListIDRef);
        clone->SetLinkListNextIDRef(this->m_uLinkListNextIDRef);
        clone->SetTextWidth(this->m_uTextWidth);
        clone->SetTextHeight(this->m_uTextHeight);
        clone->SetHasTextRef(this->m_bHasTextRef);
        clone->SetHasNumRef(this->m_bHasNumRef);
        clone->SetMetaTag(this->m_stMetaTag.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CParaListType::CParaListType() : CExtObject(ID_PARA_ParaListType), m_uTextDirection(PTDT_HORIZONTAL), m_uLineWrap(PLWT_BREAK), m_uVertAlign(PVAT_TOP), m_uTextWidth(0), m_uTextHeight(0), m_bHasTextRef(false), m_bHasNumRef(false)
    {
    }

    CParaListType::~CParaListType()
    {
    }

    void CParaListType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CParaListType, p)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CParaListType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(p, CPType, ID_PARA_PType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CParaListType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"textDirection", g_ParaTextDirectList, m_uTextDirection);
        Util::CXMLAttConverter::SetAttribute(att, L"lineWrap", g_ParaLineWrapList, m_uLineWrap);
        Util::CXMLAttConverter::SetAttribute(att, L"vertAlign", g_ParaVertAlignList, m_uVertAlign);
        Util::CXMLAttConverter::SetAttribute(att, L"linkListIDRef", m_uLinkListIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"linkListNextIDRef", m_uLinkListNextIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"textWidth", m_uTextWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"textHeight", m_uTextHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"hasTextRef", m_bHasTextRef);
        Util::CXMLAttConverter::SetAttribute(att, L"hasNumRef", m_bHasNumRef);
        if (!m_stMetaTag.empty())
            Util::CXMLAttConverter::SetAttribute(att, L"metatag", m_stMetaTag);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParaListType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textDirection", g_ParaTextDirectList, m_uTextDirection);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineWrap", g_ParaLineWrapList, m_uLineWrap);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertAlign", g_ParaVertAlignList, m_uVertAlign);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"linkListIDRef", m_uLinkListIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"linkListNextIDRef", m_uLinkListNextIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textWidth", m_uTextWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textHeight", m_uTextHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hasTextRef", m_bHasTextRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hasNumRef", m_bHasNumRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"metatag", m_stMetaTag);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPType* CParaListType::Setp(CPType* pp)
    {
        CPType* p = pp;
        if (p == NULL) {
            p = CPType::Create();
        }
        SetObject((CObject*)p);

        return p;
    }

    CPType* CParaListType::Getp(int index)
    {
        return static_cast<CPType*>(GetObjectByID(ID_PARA_PType, index));
    }

}
