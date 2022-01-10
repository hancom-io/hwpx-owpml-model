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
#include "ListBoxType.h"

namespace OWPML {

    CListBoxType* CListBoxType::Create()
    {
        return new CListBoxType();
    }

    CListBoxType* CListBoxType::Clone()
    {
        CListBoxType* clone = new CListBoxType();

        clone->SetItemHeight(this->m_nItemHeight);
        clone->SetTopIdx(this->m_uTopIdx);
        clone->SetSelectedValue(this->m_strSelectedValue.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CListBoxType::CListBoxType() : CAbstractFormObjectType(ID_PARA_ListBoxType), m_nItemHeight(-1), m_uTopIdx(0)
    {
    }

    CListBoxType::~CListBoxType()
    {
    }

    void CListBoxType::InitMap(bool bRead)
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

            OWPML_PARALIST_REDIRECT_FUNC(CListBoxType, listItem)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CListBoxType)
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

            OWPML_PARALIST_ADD_REDIRECT_FUNC(listItem, CListItemType, ID_PARA_ListItemType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CListBoxType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemHeight", m_nItemHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"topIdx", m_uTopIdx);
        Util::CXMLAttConverter::SetAttribute(att, L"selectedValue", m_strSelectedValue);

        CAbstractFormObjectType::WriteElement(pCurObjName, serialize, att);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CListBoxType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractFormObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemHeight", m_nItemHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"topIdx", m_uTopIdx);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"selectedValue", m_strSelectedValue);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CListItemType* CListBoxType::SetlistItem(CListItemType* plistItem)
    {
        CListItemType* listItem = plistItem;
        if (listItem == NULL) {
            listItem = CListItemType::Create();
        }
        SetObject((CObject*)listItem);

        return listItem;
    }

    CListItemType* CListBoxType::GetlistItem(int index)
    {
        return static_cast<CListItemType*>(GetObjectByID(ID_PARA_ListItemType, index));
    }

}
