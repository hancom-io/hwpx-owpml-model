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
#include "visibility.h"

namespace OWPML {


    CVisibility* CVisibility::Create()
    {
        return new CVisibility();
    }

    CVisibility* CVisibility::Clone()
    {
        CVisibility* clone = new CVisibility();

        clone->SetHideFirstHeader(this->m_bHideFirstHeader);
        clone->SetHideFirstFooter(this->m_bHideFirstFooter);
        clone->SetHideFirstMasterPage(this->m_bHideFirstMasterPage);
        clone->SetBorder((VISIBILITYVALUETYPE)this->m_uBorder);
        clone->SetFill((VISIBILITYVALUETYPE)this->m_uFill);
        clone->SetHideFirstPageNum(this->m_bHideFirstPageNum);
        clone->SetHideFirstEmptyLine(this->m_bHideFirstEmptyLine);
        clone->SetShowLineNumber(this->m_bShowLineNumber);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CVisibility::CVisibility() : CExtObject(ID_PARA_Visibility), m_bHideFirstHeader(false), m_bHideFirstFooter(false), m_bHideFirstMasterPage(false), \
        m_bHideFirstPageNum(false), m_bHideFirstEmptyLine(false), m_bShowLineNumber(false)
    {
    }

    CVisibility::~CVisibility()
    {
    }

    void CVisibility::InitMap(bool /*bRead*/)
    {
    }

    bool CVisibility::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"hideFirstHeader", m_bHideFirstHeader);
        Util::CXMLAttConverter::SetAttribute(att, L"hideFirstFooter", m_bHideFirstFooter);
        Util::CXMLAttConverter::SetAttribute(att, L"hideFirstMasterPage", m_bHideFirstMasterPage);
        Util::CXMLAttConverter::SetAttribute(att, L"border", g_VisibilityValueList, m_uBorder);
        Util::CXMLAttConverter::SetAttribute(att, L"fill", g_VisibilityValueList, m_uFill);
        Util::CXMLAttConverter::SetAttribute(att, L"hideFirstPageNum", m_bHideFirstPageNum);
        Util::CXMLAttConverter::SetAttribute(att, L"hideFirstEmptyLine", m_bHideFirstEmptyLine);
        Util::CXMLAttConverter::SetAttribute(att, L"showLineNumber", m_bShowLineNumber);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CVisibility::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFirstHeader", m_bHideFirstHeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFirstFooter", m_bHideFirstFooter);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFirstMasterPage", m_bHideFirstMasterPage);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"border", g_VisibilityValueList, m_uBorder);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fill", g_VisibilityValueList, m_uFill);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFirstPageNum", m_bHideFirstPageNum);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFirstEmptyLine", m_bHideFirstEmptyLine);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"showLineNumber", m_bShowLineNumber);

        return bres;
    }


    CLineNumberShape* CLineNumberShape::Create()
    {
        return new CLineNumberShape();
    }

    CLineNumberShape* CLineNumberShape::Clone()
    {
        CLineNumberShape* clone = new CLineNumberShape();

        clone->SetRestartType(this->m_RestartType);
        clone->SetCountBy(this->m_CountBy);
        clone->SetDistance(this->m_Distance);
        clone->SetStartNumber(this->m_StartNumber);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CLineNumberShape::CLineNumberShape() : CExtObject(ID_PARA_LineNumShape), m_RestartType(0), m_CountBy(0), m_Distance(0), m_StartNumber(0)
    {
    }

    CLineNumberShape::~CLineNumberShape()
    {
    }

    void CLineNumberShape::InitMap(bool /*bRead*/)
    {
    }

    bool CLineNumberShape::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"restartType", m_RestartType);
        Util::CXMLAttConverter::SetAttribute(att, L"countBy", m_CountBy);
        Util::CXMLAttConverter::SetAttribute(att, L"distance", m_Distance);
        Util::CXMLAttConverter::SetAttribute(att, L"startNumber", m_StartNumber);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLineNumberShape::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"restartType", m_RestartType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"countBy", m_CountBy);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"distance", m_Distance);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"startNumber", m_StartNumber);

        return bres;
    }


}
