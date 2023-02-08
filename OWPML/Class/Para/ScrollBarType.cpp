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
#include "ScrollBarType.h"

namespace OWPML {

    CScrollBarType* CScrollBarType::Create()
    {
        return new CScrollBarType();
    }

    CScrollBarType* CScrollBarType::Clone()
    {
        CScrollBarType* clone = new CScrollBarType();

        clone->SetDelay(this->m_uDelay);
        clone->SetLargeChange(this->m_uLargeChange);
        clone->SetSmallChange(this->m_uSmallChange);
        clone->SetMin(this->m_nMin);
        clone->SetMax(this->m_nMax);
        clone->SetPage(this->m_nPage);
        clone->SetValue(this->m_nValue);
        clone->SetType((SCROLLBARTYPE)this->m_uType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CScrollBarType::CScrollBarType() : CAbstractFormObjectType(ID_PARA_ScrollBarType)
    {
    }

    CScrollBarType::~CScrollBarType()
    {
    }

    void CScrollBarType::InitMap(bool bRead)
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
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CScrollBarType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"delay", m_uDelay);
        Util::CXMLAttConverter::SetAttribute(att, L"largeChange", m_uLargeChange);
        Util::CXMLAttConverter::SetAttribute(att, L"smallChange", m_uSmallChange);
        Util::CXMLAttConverter::SetAttribute(att, L"min", m_nMin);
        Util::CXMLAttConverter::SetAttribute(att, L"max", m_nMax);
        Util::CXMLAttConverter::SetAttribute(att, L"page", m_nPage);
        Util::CXMLAttConverter::SetAttribute(att, L"value", m_nValue);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ScrollBarList, m_uType);

        CAbstractFormObjectType::WriteElement(pCurObjName, serialize, att);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CScrollBarType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractFormObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"delay", m_uDelay);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"largeChange", m_uLargeChange);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"smallChange", m_uSmallChange);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"min", m_nMin);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"max", m_nMax);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"page", m_nPage);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", m_nValue);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ScrollBarList, m_uType);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

}
