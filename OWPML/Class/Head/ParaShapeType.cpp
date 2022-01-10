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
#include "ParaShapeType.h"

namespace OWPML {

    CParaShapeType* CParaShapeType::Create()
    {
        return new CParaShapeType();
    }

    CParaShapeType::CParaShapeType() : CExtObject(ID_HEAD_ParaShapeType), m_uCondense(0), m_bFontLineHeight(false), m_bSnapToGrid(true), m_bSuppressLineNumbers(false), m_bChecked(false), m_uTabPrIDRef(0)
    {
    }

    CParaShapeType::~CParaShapeType()
    {
    }

    void CParaShapeType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, align)
            OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, heading)
            OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, breakSetting)
            OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, margin)
            OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, lineSpacing)
            OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, border)
            OWPML_HEAD_REDIRECT_FUNC(CParaShapeType, autoSpacing)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CParaShapeType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(align, CAlign, ID_HEAD_Align)
            OWPML_HEAD_ADD_REDIRECT_FUNC(heading, CHeading, ID_HEAD_Heading)
            OWPML_HEAD_ADD_REDIRECT_FUNC(breakSetting, CBreakSetting, ID_HEAD_BreakSetting)
            OWPML_HEAD_ADD_REDIRECT_FUNC(margin, CMargin, ID_HEAD_Margin)
            OWPML_HEAD_ADD_REDIRECT_FUNC(lineSpacing, CLineSpacing, ID_HEAD_LineSpacing)
            OWPML_HEAD_ADD_REDIRECT_FUNC(border, CBorder, ID_HEAD_Border)
            OWPML_HEAD_ADD_REDIRECT_FUNC(autoSpacing, CAutoSpacing, ID_HEAD_AutoSpacing)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CParaShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"tabPrIDRef", m_uTabPrIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"condense", m_uCondense);
        Util::CXMLAttConverter::SetAttribute(att, L"fontLineHeight", m_bFontLineHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"snapToGrid", m_bSnapToGrid);
        Util::CXMLAttConverter::SetAttribute(att, L"suppressLineNumbers", m_bSuppressLineNumbers);
        Util::CXMLAttConverter::SetAttribute(att, L"checked", m_bChecked);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParaShapeType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabPrIDRef", m_uTabPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"condense", m_uCondense);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fontLineHeight", m_bFontLineHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"snapToGrid", m_bSnapToGrid);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"suppressLineNumbers", m_bSuppressLineNumbers);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"checked", m_bChecked);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CAlign* CParaShapeType::Setalign(CAlign* palign)
    {
        CAlign* align = palign;
        if (align == NULL) {
            align = CAlign::Create();
        }
        SetObject((CObject*)align);

        return align;
    }

    CAlign* CParaShapeType::Getalign(int index)
    {
        return static_cast<CAlign*>(GetObjectByID(ID_HEAD_Align, index));
    }

    CHeading* CParaShapeType::Setheading(CHeading* pheading)
    {
        CHeading* heading = pheading;
        if (heading == NULL) {
            heading = CHeading::Create();
        }
        SetObject((CObject*)heading);

        return heading;
    }

    CHeading* CParaShapeType::Getheading(int index)
    {
        return static_cast<CHeading*>(GetObjectByID(ID_HEAD_Heading, index));
    }

    CBreakSetting* CParaShapeType::SetbreakSetting(CBreakSetting* pbreakSetting)
    {
        CBreakSetting* breakSetting = pbreakSetting;
        if (breakSetting == NULL) {
            breakSetting = CBreakSetting::Create();
        }
        SetObject((CObject*)breakSetting);

        return breakSetting;
    }

    CBreakSetting* CParaShapeType::GetbreakSetting(int index)
    {
        return static_cast<CBreakSetting*>(GetObjectByID(ID_HEAD_BreakSetting, index));
    }

    CMargin* CParaShapeType::Setmargin(CMargin* pmargin)
    {
        CMargin* margin = pmargin;
        if (margin == NULL) {
            margin = CMargin::Create();
        }
        SetObject((CObject*)margin);

        return margin;
    }

    CMargin* CParaShapeType::Getmargin(int index)
    {
        return static_cast<CMargin*>(GetObjectByID(ID_HEAD_Margin, index));
    }

    CLineSpacing* CParaShapeType::SetlineSpacing(CLineSpacing* plineSpacing)
    {
        CLineSpacing* lineSpacing = plineSpacing;
        if (lineSpacing == NULL) {
            lineSpacing = CLineSpacing::Create();
        }
        SetObject((CObject*)lineSpacing);

        return lineSpacing;
    }

    CLineSpacing* CParaShapeType::GetlineSpacing(int index)
    {
        return static_cast<CLineSpacing*>(GetObjectByID(ID_HEAD_LineSpacing, index));
    }

    CBorder* CParaShapeType::Setborder(CBorder* pborder)
    {
        CBorder* border = pborder;
        if (border == NULL) {
            border = CBorder::Create();
        }
        SetObject((CObject*)border);

        return border;
    }

    CBorder* CParaShapeType::Getborder(int index)
    {
        return static_cast<CBorder*>(GetObjectByID(ID_HEAD_Border, index));
    }

    CAutoSpacing* CParaShapeType::SetautoSpacing(CAutoSpacing* pautoSpacing)
    {
        CAutoSpacing* autoSpacing = pautoSpacing;
        if (autoSpacing == NULL) {
            autoSpacing = CAutoSpacing::Create();
        }
        SetObject((CObject*)autoSpacing);

        return autoSpacing;
    }

    CAutoSpacing* CParaShapeType::GetautoSpacing(int index)
    {
        return static_cast<CAutoSpacing*>(GetObjectByID(ID_HEAD_AutoSpacing, index));
    }

}
