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
#include "textartPr.h"

namespace OWPML {

    CTextartPr* CTextartPr::Create()
    {
        return new CTextartPr();
    }

    CTextartPr* CTextartPr::Clone()
    {
        CTextartPr* clone = new CTextartPr();

        clone->SetFontName(this->m_strFontName.c_str());
        clone->SetFontStyle(this->m_strFontStyle.c_str());
        clone->SetFontType((TEXTARTFONTTYPE)this->m_uFontType);
        clone->SetTextShape((TEXTARTSHAPETYPE)this->m_uTextShape);
        clone->SetLineSpacing(this->m_uLineSpacing);
        clone->SetCharSpacing(this->m_uCharSpacing);
        clone->SetAlign((TEXTARTALIGNTYPE)this->m_uAlign);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CTextartPr::CTextartPr() : CExtObject(ID_PARA_TextartPr), m_strFontStyle(L"REGULAR"), m_uFontType(TAFT_TTF), m_uLineSpacing(120), m_uCharSpacing(100), m_uAlign(TAAT_LEFT), m_uTextShape(0)
    {
    }

    CTextartPr::~CTextartPr()
    {
    }

    void CTextartPr::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CTextartPr, shadow)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTextartPr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shadow, CShadowType, ID_PARA_ShadowType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTextartPr::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"fontName", m_strFontName);
        Util::CXMLAttConverter::SetAttribute(att, L"fontStyle", m_strFontStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"fontType", g_TextartFontList, m_uFontType);
        Util::CXMLAttConverter::SetAttribute(att, L"textShape", g_TextartShapeList, m_uTextShape);
        Util::CXMLAttConverter::SetAttribute(att, L"lineSpacing", m_uLineSpacing);
        Util::CXMLAttConverter::SetAttribute(att, L"charSpacing", m_uCharSpacing);
        Util::CXMLAttConverter::SetAttribute(att, L"align", g_TextartAlignList, m_uAlign);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTextartPr::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fontName", m_strFontName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fontStyle", m_strFontStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fontType", g_TextartFontList, m_uFontType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textShape", g_TextartShapeList, m_uTextShape);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineSpacing", m_uLineSpacing);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charSpacing", m_uCharSpacing);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"align", g_TextartAlignList, m_uAlign);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CShadowType* CTextartPr::Setshadow(CShadowType* pshadow)
    {
        CShadowType* shadow = pshadow;
        if (shadow == NULL) {
            shadow = CShadowType::Create();
        }
        SetObject((CObject*)shadow);

        return shadow;
    }

    CShadowType* CTextartPr::Getshadow(int index)
    {
        return static_cast<CShadowType*>(GetObjectByID(ID_PARA_ShadowType, index));
    }

}
