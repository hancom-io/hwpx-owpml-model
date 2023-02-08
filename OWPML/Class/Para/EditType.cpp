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
#include "AbstractShapeObjectType.h"
#include "AbstractFormObjectType.h"
#include "EditType.h"

namespace OWPML {

    CEditType* CEditType::Create()
    {
        return new CEditType();
    }

    CEditType* CEditType::Clone()
    {
        CEditType* clone = new CEditType();

        clone->SetMultiLine(this->m_bMultiLine);
        clone->SetPasswordChar(this->m_strPasswordChar.c_str());
        clone->SetMaxLength(this->m_uMaxLength);
        clone->SetScrollBars((EDSCROLLBARSTYPE)this->m_uScrollBars);
        clone->SetTabKeyBehavior((EDTABKEYBHTYPE)this->m_uTabKeyBehavior);
        clone->SetNumOnly(this->m_bNumOnly);
        clone->SetReadOnly(this->m_bReadOnly);
        clone->SetAlignText((EDITALIGNTYPE)this->m_uAlignText);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEditType::CEditType() : CAbstractFormObjectType(ID_PARA_EditType), m_bMultiLine(false), m_strPasswordChar(L"*"), m_uMaxLength(0), m_uScrollBars(ESBT_NONE), m_bNumOnly(false), m_bReadOnly(false), m_uAlignText(EAT_LEFT)
    {
    }

    CEditType::~CEditType()
    {
    }

    void CEditType::InitMap(bool bRead)
    {
        // "AbstractShapeObjectType.h"
        OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, sz)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, pos)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, outMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, caption)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, shapeComment)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, parameterset)
            // metatag & json
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, metaTag)

            //AbstractFormObjectType.h
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractFormObjectType, formCharPr)

            OWPML_PARALIST_REDIRECT_FUNC(CEditType, text)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEditType)
            // "AbstractShapeObjectType.h"
            OWPML_PARALIST_ADD_REDIRECT_FUNC(sz, CSz, ID_PARA_Sz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CASOPos, ID_PARA_ASOPos)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outMargin, COutMargin, ID_PARA_OutMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(caption, CCaption, ID_PARA_Caption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shapeComment, CShapeComment, ID_PARA_ShapeComment)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)

            //AbstractFormObjectType.h
            OWPML_PARALIST_ADD_REDIRECT_FUNC(formCharPr, CFormCharPr, ID_PARA_FormCharPr)

            OWPML_PARALIST_ADD_REDIRECT_FUNC(text, CText, ID_PARA_Text)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEditType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"multiLine", m_bMultiLine);
        Util::CXMLAttConverter::SetAttribute(att, L"passwordChar", m_strPasswordChar);
        Util::CXMLAttConverter::SetAttribute(att, L"maxLength", m_uMaxLength);
        Util::CXMLAttConverter::SetAttribute(att, L"scrollBars", g_EdScrollBarsList, m_uScrollBars);
        Util::CXMLAttConverter::SetAttribute(att, L"tabKeyBehavior", g_EdTabKeyBhList, m_uTabKeyBehavior);
        Util::CXMLAttConverter::SetAttribute(att, L"numOnly", m_bNumOnly);
        Util::CXMLAttConverter::SetAttribute(att, L"readOnly", m_bReadOnly);
        Util::CXMLAttConverter::SetAttribute(att, L"alignText", g_EditAlignList, m_uAlignText);

        CAbstractFormObjectType::WriteElement(pCurObjName, serialize, att);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEditType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractFormObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"multiLine", m_bMultiLine);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"passwordChar", m_strPasswordChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"maxLength", m_uMaxLength);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"scrollBars", g_EdScrollBarsList, m_uScrollBars);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabKeyBehavior", g_EdTabKeyBhList, m_uTabKeyBehavior);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"numOnly", m_bNumOnly);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"readOnly", m_bReadOnly);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alignText", g_EditAlignList, m_uAlignText);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CText* CEditType::Settext(CText* ptext)
    {
        CText* text = ptext;
        if (text == NULL) {
            text = CText::Create();
        }
        SetObject((CObject*)text);

        return text;
    }

    CText* CEditType::Gettext(int index)
    {
        return static_cast<CText*>(GetObjectByID(ID_PARA_Text, index));
    }

}
