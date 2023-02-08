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
#include "drawText.h"

namespace OWPML {

    CDrawText* CDrawText::Create()
    {
        return new CDrawText();
    }

    CDrawText* CDrawText::Clone()
    {
        CDrawText* clone = new CDrawText();

        clone->SetLastWidth(this->m_uLastWidth);
        clone->SetName(this->m_strName.c_str());
        clone->SetEditable(this->m_bEditable);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CDrawText::CDrawText() : CExtObject(ID_PARA_DrawText), m_uLastWidth(0), m_bEditable(false)
    {
    }

    CDrawText::~CDrawText()
    {
    }

    void CDrawText::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CDrawText, textMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CDrawText, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CDrawText)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(textMargin, CTextMargin, ID_PARA_TextMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CDrawText::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"lastWidth", m_uLastWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"editable", m_bEditable);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDrawText::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lastWidth", m_uLastWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"editable", m_bEditable);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTextMargin* CDrawText::SettextMargin(CTextMargin* ptextMargin)
    {
        CTextMargin* textMargin = ptextMargin;
        if (textMargin == NULL) {
            textMargin = CTextMargin::Create();
        }
        SetObject((CObject*)textMargin);

        return textMargin;
    }

    CTextMargin* CDrawText::GettextMargin(int index)
    {
        return static_cast<CTextMargin*>(GetObjectByID(ID_PARA_TextMargin, index));
    }

    CParaListType* CDrawText::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CDrawText::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
