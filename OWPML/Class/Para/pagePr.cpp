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
#include "pagePr.h"

namespace OWPML {

    CPagePr* CPagePr::Create()
    {
        return new CPagePr();
    }

    CPagePr* CPagePr::Clone()
    {
        CPagePr* clone = new CPagePr();

        clone->SetLandscape((PAGELANDSCAPETYPE)this->m_uLandscape);
        clone->SetWidth(this->m_uWidth);
        clone->SetHeight(this->m_uHeight);
        clone->SetGutterType((PAGEGUTTERTYPE)this->m_uGutterType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPagePr::CPagePr() : CExtObject(ID_PARA_PagePr), m_uLandscape(PLT_NARROWLY), m_uWidth(59528), m_uHeight(84188), m_uGutterType(PGT_LEFT_ONLY)
    {
    }

    CPagePr::~CPagePr()
    {
    }

    void CPagePr::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CPagePr, margin)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPagePr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(margin, CPMargin, ID_PARA_Margin)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPagePr::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"landscape", g_PageLandscapeList, m_uLandscape);
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"height", m_uHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"gutterType", g_PageGutterList, m_uGutterType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPagePr::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"landscape", g_PageLandscapeList, m_uLandscape);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"height", m_uHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"gutterType", g_PageGutterList, m_uGutterType);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPMargin* CPagePr::Setmargin(CPMargin* pmargin)
    {
        CPMargin* margin = pmargin;
        if (margin == NULL) {
            margin = CPMargin::Create();
        }
        SetObject((CObject*)margin);

        return margin;
    }

    CPMargin* CPagePr::Getmargin(int index)
    {
        return static_cast<CPMargin*>(GetObjectByID(ID_PARA_Margin, index));
    }

}
