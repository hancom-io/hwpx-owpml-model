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
#include "pageBorderFill.h"

namespace OWPML {

    CPageBorderFill* CPageBorderFill::Create()
    {
        return new CPageBorderFill();
    }

    CPageBorderFill* CPageBorderFill::Clone()
    {
        CPageBorderFill* clone = new CPageBorderFill();

        clone->SetType((PBFTYPE)this->m_uType);
        clone->SetBorderFillIDRef(this->m_uBorderFillIDRef);
        clone->SetTextBorder((PBFTEXTBORDERTYPE)this->m_uTextBorder);
        clone->SetHeaderInside(this->m_bHeaderInside);
        clone->SetFooterInside(this->m_bFooterInside);
        clone->SetFillArea((PBFFILLAREATYPE)this->m_uFillArea);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPageBorderFill::CPageBorderFill() : CExtObject(ID_PARA_PageBorderFill), m_bHeaderInside(false), m_bFooterInside(false), m_uBorderFillIDRef(0)
    {
    }

    CPageBorderFill::~CPageBorderFill()
    {
    }

    void CPageBorderFill::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CPageBorderFill, offset)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPageBorderFill)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(offset, CPBFOffset, ID_PARA_PBFOffset)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPageBorderFill::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_PBFTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"textBorder", g_PBFTextBorderList, m_uTextBorder);
        Util::CXMLAttConverter::SetAttribute(att, L"headerInside", m_bHeaderInside);
        Util::CXMLAttConverter::SetAttribute(att, L"footerInside", m_bFooterInside);
        Util::CXMLAttConverter::SetAttribute(att, L"fillArea", g_PBFFillAreaList, m_uFillArea);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPageBorderFill::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_PBFTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textBorder", g_PBFTextBorderList, m_uTextBorder);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"headerInside", m_bHeaderInside);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"footerInside", m_bFooterInside);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fillArea", g_PBFFillAreaList, m_uFillArea);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPBFOffset* CPageBorderFill::Setoffset(CPBFOffset* poffset)
    {
        CPBFOffset* offset = poffset;
        if (offset == NULL) {
            offset = CPBFOffset::Create();
        }
        SetObject((CObject*)offset);

        return offset;
    }

    CPBFOffset* CPageBorderFill::Getoffset(int index)
    {
        return static_cast<CPBFOffset*>(GetObjectByID(ID_PARA_PBFOffset, index));
    }

}
