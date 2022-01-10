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
#include "SectionDefinitionType.h"

namespace OWPML {

    CSectionDefinitionType* CSectionDefinitionType::Create()
    {
        return new CSectionDefinitionType();
    }

    CSectionDefinitionType* CSectionDefinitionType::Clone()
    {
        CSectionDefinitionType* clone = new CSectionDefinitionType();

        clone->SetId(this->m_strId.c_str());
        clone->SetTextDirection((SECTEXTDIRECTTYPE)this->m_uTextDirection);
        clone->SetSpaceColumns(this->m_nSpaceColumns);
        clone->SetTabStop(this->m_nTabStop);
        clone->SetTabStopVal(this->m_nTabStopVal);
        clone->SetTabStopUnit((UINTVALUETYPE)this->m_nTabStopUnit);
        clone->SetOutlineShapeIDRef(this->m_uOutlineShapeIDRef);
        clone->SetMemoShapeIDRef(this->m_uMemoShapeIDRef);
        clone->SetTextVerticalWidthHead(this->m_bTextVerticalWidthHead);
        clone->SetMasterPageCnt(this->m_uMasterPageCnt);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CSectionDefinitionType::CSectionDefinitionType() : CExtObject(ID_PARA_SectionDefinitionType), m_uTextDirection(STDT_HORIZONTAL), m_nSpaceColumns(0), m_nTabStop(8000), \
        m_bTextVerticalWidthHead(false), m_uMasterPageCnt(0), m_uMemoShapeIDRef(0), m_uOutlineShapeIDRef(0)
    {
    }

    CSectionDefinitionType::~CSectionDefinitionType()
    {
    }

    void CSectionDefinitionType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, startNum)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, grid)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, visibility)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, lineNumberShape)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, pagePr)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, footNotePr)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, endNotePr)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, pageBorderFill)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, masterPage)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, parameterset)
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, presentation)
            // metatag & json
            OWPML_PARALIST_REDIRECT_FUNC(CSectionDefinitionType, metaTag)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CSectionDefinitionType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(startNum, CStartNum, ID_PARA_StartNum)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(grid, CGrid, ID_PARA_Grid)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(visibility, CVisibility, ID_PARA_Visibility)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(lineNumberShape, CLineNumberShape, ID_PARA_LineNumShape)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pagePr, CPagePr, ID_PARA_PagePr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(footNotePr, CFootNoteShapeType, ID_PARA_FootNoteShapeType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(endNotePr, CEndNoteShapeType, ID_PARA_EndNoteShapeType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pageBorderFill, CPageBorderFill, ID_PARA_PageBorderFill)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(masterPage, CMasterPage, ID_PARA_MasterPage)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(presentation, CPresentation, ID_PARA_PresentationType)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CSectionDefinitionType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"textDirection", g_SecTextDirectList, m_uTextDirection);
        Util::CXMLAttConverter::SetAttribute(att, L"spaceColumns", m_nSpaceColumns);
        Util::CXMLAttConverter::SetAttribute(att, L"tabStop", m_nTabStop);
        Util::CXMLAttConverter::SetAttribute(att, L"tabStopVal", m_nTabStopVal);
        Util::CXMLAttConverter::SetAttribute(att, L"tabStopUnit", g_UnitValueList, m_nTabStopUnit);
        Util::CXMLAttConverter::SetAttribute(att, L"outlineShapeIDRef", m_uOutlineShapeIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"memoShapeIDRef", m_uMemoShapeIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"textVerticalWidthHead", m_bTextVerticalWidthHead);
        Util::CXMLAttConverter::SetAttribute(att, L"masterPageCnt", m_uMasterPageCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSectionDefinitionType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textDirection", g_SecTextDirectList, m_uTextDirection);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"spaceColumns", m_nSpaceColumns);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabStop", m_nTabStop);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabStopVal", m_nTabStopVal);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabStopUnit", g_UnitValueList, m_nTabStopUnit);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"outlineShapeIDRef", m_uOutlineShapeIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"memoShapeIDRef", m_uMemoShapeIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textVerticalWidthHead", m_bTextVerticalWidthHead);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"masterPageCnt", m_uMasterPageCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CStartNum* CSectionDefinitionType::SetstartNum(CStartNum* pstartNum)
    {
        CStartNum* startNum = pstartNum;
        if (startNum == NULL) {
            startNum = CStartNum::Create();
        }
        SetObject((CObject*)startNum);

        return startNum;
    }

    CStartNum* CSectionDefinitionType::GetstartNum(int index)
    {
        return static_cast<CStartNum*>(GetObjectByID(ID_PARA_StartNum, index));
    }

    CGrid* CSectionDefinitionType::Setgrid(CGrid* pgrid)
    {
        CGrid* grid = pgrid;
        if (grid == NULL) {
            grid = CGrid::Create();
        }
        SetObject((CObject*)grid);

        return grid;
    }

    CGrid* CSectionDefinitionType::Getgrid(int index)
    {
        return static_cast<CGrid*>(GetObjectByID(ID_PARA_Grid, index));
    }

    CVisibility* CSectionDefinitionType::Setvisibility(CVisibility* pvisibility)
    {
        CVisibility* visibility = pvisibility;
        if (visibility == NULL) {
            visibility = CVisibility::Create();
        }
        SetObject((CObject*)visibility);

        return visibility;
    }

    CVisibility* CSectionDefinitionType::Getvisibility(int index)
    {
        return static_cast<CVisibility*>(GetObjectByID(ID_PARA_Visibility, index));
    }


    CLineNumberShape* CSectionDefinitionType::SetlineNumberShape(CLineNumberShape* plinenumbershape)
    {
        CLineNumberShape* lineshape = plinenumbershape;
        if (lineshape == NULL) {
            lineshape = CLineNumberShape::Create();
        }
        SetObject((CObject*)lineshape);

        return lineshape;
    }

    CLineNumberShape* CSectionDefinitionType::GetlineNumberShape(int index)
    {
        return static_cast<CLineNumberShape*>(GetObjectByID(ID_PARA_LineNumShape, index));
    }

    CPagePr* CSectionDefinitionType::SetpagePr(CPagePr* ppagePr)
    {
        CPagePr* pagePr = ppagePr;
        if (pagePr == NULL) {
            pagePr = CPagePr::Create();
        }
        SetObject((CObject*)pagePr);

        return pagePr;
    }

    CPagePr* CSectionDefinitionType::GetpagePr(int index)
    {
        return static_cast<CPagePr*>(GetObjectByID(ID_PARA_PagePr, index));
    }

    CFootNoteShapeType* CSectionDefinitionType::SetfootNotePr(CFootNoteShapeType* pfootNotePr)
    {
        CFootNoteShapeType* footNotePr = pfootNotePr;
        if (footNotePr == NULL) {
            footNotePr = CFootNoteShapeType::Create();
        }
        SetObject((CObject*)footNotePr);

        return footNotePr;
    }

    CFootNoteShapeType* CSectionDefinitionType::GetfootNotePr(int index)
    {
        return static_cast<CFootNoteShapeType*>(GetObjectByID(ID_PARA_FootNoteShapeType, index));
    }

    CEndNoteShapeType* CSectionDefinitionType::SetendNotePr(CEndNoteShapeType* pendNotePr)
    {
        CEndNoteShapeType* endNotePr = pendNotePr;
        if (endNotePr == NULL) {
            endNotePr = CEndNoteShapeType::Create();
        }
        SetObject((CObject*)endNotePr);

        return endNotePr;
    }

    CEndNoteShapeType* CSectionDefinitionType::GetendNotePr(int index)
    {
        return static_cast<CEndNoteShapeType*>(GetObjectByID(ID_PARA_EndNoteShapeType, index));
    }

    CPageBorderFill* CSectionDefinitionType::SetpageBorderFill(CPageBorderFill* ppageBorderFill)
    {
        CPageBorderFill* pageBorderFill = ppageBorderFill;
        if (pageBorderFill == NULL) {
            pageBorderFill = CPageBorderFill::Create();
        }
        SetObject((CObject*)pageBorderFill);

        return pageBorderFill;
    }

    CPageBorderFill* CSectionDefinitionType::GetpageBorderFill(int index)
    {
        return static_cast<CPageBorderFill*>(GetObjectByID(ID_PARA_PageBorderFill, index));
    }

    CMasterPage* CSectionDefinitionType::SetmasterPage(CMasterPage* pmasterPage)
    {
        CMasterPage* masterPage = pmasterPage;
        if (masterPage == NULL) {
            masterPage = CMasterPage::Create();
        }
        SetObject((CObject*)masterPage);

        return masterPage;
    }

    CMasterPage* CSectionDefinitionType::GetmasterPage(int index)
    {
        return static_cast<CMasterPage*>(GetObjectByID(ID_PARA_MasterPage, index));
    }

    CPresentation* CSectionDefinitionType::Setpresentation(CPresentation* ppresentation)
    {
        CPresentation* presentation = ppresentation;
        if (presentation == NULL) {
            presentation = CPresentation::Create();
        }
        SetObject((CObject*)presentation);

        return presentation;
    }

    CPresentation* CSectionDefinitionType::Getpresentation(int index)
    {
        return static_cast<CPresentation*>(GetObjectByID(ID_PARA_PresentationType, index));
    }

}
