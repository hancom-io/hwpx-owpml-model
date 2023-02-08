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
#include "TableType.h"
#include "AbstractShapeObjectType.h"

namespace OWPML {

    CTableType* CTableType::Create()
    {
        return new CTableType();
    }

    CTableType::CTableType() : CAbstractShapeObjectType(ID_PARA_TableType), m_uRowCnt(0), m_uColCnt(0), m_bRepeatHeader(false), m_bNoAdjust(false)
    {
    }

    CTableType* CTableType::Clone()
    {
        CTableType* clone = new CTableType();

        clone->SetPageBreak((TABLEPAGEBREAKTYPE)(this->m_uPageBreak));
        clone->SetRepeatHeader(this->m_bRepeatHeader);
        clone->SetNoAdjust(this->m_bNoAdjust);
        clone->SetRowCnt(this->m_uRowCnt);
        clone->SetColCnt(this->m_uColCnt);
        clone->SetCellSpacing(this->m_uCellSpacing);
        clone->SetBorderFillIDRef(this->m_uBorderFillIDRef);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CTableType::~CTableType()
    {
    }

    void CTableType::InitMap(bool bRead)
    {
        // "AbstractShapeObjectType.h"
        OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, sz)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, pos)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, outMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, caption)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, shapeComment)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, parameterset)
            // metatag & json
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, metaTag)

            OWPML_PARALIST_REDIRECT_FUNC(CTableType, inMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CTableType, cellzoneList)
            OWPML_PARALIST_REDIRECT_FUNC(CTableType, tr)
            OWPML_PARALIST_REDIRECT_FUNC(CTableType, label)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTableType)
            // "AbstractShapeObjectType.h"
            OWPML_PARALIST_ADD_REDIRECT_FUNC(sz, CSz, ID_PARA_Sz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CASOPos, ID_PARA_ASOPos)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outMargin, COutMargin, ID_PARA_OutMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(caption, CCaption, ID_PARA_Caption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shapeComment, CShapeComment, ID_PARA_ShapeComment)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)

            OWPML_PARALIST_ADD_REDIRECT_FUNC(inMargin, CInsideMarginType, ID_PARA_InsideMarginType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cellzoneList, CCellzoneList, ID_PARA_CellzoneList)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(tr, CTr, ID_PARA_Tr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(label, CLabel, ID_PARA_LabelType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTableType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeObjectType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"pageBreak", g_TablePageBreakList, m_uPageBreak);
        Util::CXMLAttConverter::SetAttribute(att, L"repeatHeader", m_bRepeatHeader);
        Util::CXMLAttConverter::SetAttribute(att, L"rowCnt", m_uRowCnt);
        Util::CXMLAttConverter::SetAttribute(att, L"colCnt", m_uColCnt);
        Util::CXMLAttConverter::SetAttribute(att, L"cellSpacing", m_uCellSpacing);
        Util::CXMLAttConverter::SetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"noAdjust", m_bNoAdjust);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTableType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CAbstractShapeObjectType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageBreak", g_TablePageBreakList, m_uPageBreak);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"repeatHeader", m_bRepeatHeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rowCnt", m_uRowCnt);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"colCnt", m_uColCnt);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"cellSpacing", m_uCellSpacing);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"noAdjust", m_bNoAdjust);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CInsideMarginType* CTableType::SetinMargin(CInsideMarginType* pinMargin)
    {
        CInsideMarginType* inMargin = pinMargin;
        if (inMargin == NULL) {
            inMargin = CInsideMarginType::Create();
        }
        SetObject((CObject*)inMargin);

        return inMargin;
    }

    CInsideMarginType* CTableType::GetinMargin(int index)
    {
        return static_cast<CInsideMarginType*>(GetObjectByID(ID_PARA_InsideMarginType, index));
    }

    CCellzoneList* CTableType::SetcellzoneList(CCellzoneList* pcellzoneList)
    {
        CCellzoneList* cellzoneList = pcellzoneList;
        if (cellzoneList == NULL) {
            cellzoneList = CCellzoneList::Create();
        }
        SetObject((CObject*)cellzoneList);

        return cellzoneList;
    }

    CCellzoneList* CTableType::GetcellzoneList(int index)
    {
        return static_cast<CCellzoneList*>(GetObjectByID(ID_PARA_CellzoneList, index));
    }

    CTr* CTableType::Settr(CTr* ptr)
    {
        CTr* tr = ptr;
        if (tr == NULL) {
            tr = CTr::Create();
        }
        SetObject((CObject*)tr);

        return tr;
    }

    CTr* CTableType::Gettr(int index)
    {
        return static_cast<CTr*>(GetObjectByID(ID_PARA_Tr, index));
    }

    CLabel* CTableType::Setlabel(CLabel* plabel)
    {
        CLabel* label = plabel;
        if (label == NULL) {
            label = CLabel::Create();
        }
        SetObject((CObject*)label);

        return label;
    }

    CLabel* CTableType::Getlabel(int index)
    {
        return static_cast<CLabel*>(GetObjectByID(ID_PARA_LabelType, index));
    }

}
