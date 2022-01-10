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
#include "label.h"

namespace OWPML {

    CLabel* CLabel::Create()
    {
        return new CLabel();
    }

    CLabel* CLabel::Clone()
    {
        CLabel* clone = new CLabel();

        clone->SetTopMargin(this->m_topMargin);
        clone->SetLeftMargin(this->m_leftMargin);
        clone->SetBoxWidth(this->m_boxWidth);
        clone->SetBoxLength(this->m_boxLength);
        clone->SetBoxMarginHor(this->m_boxMarginHor);
        clone->SetBoxMarginVer(this->m_boxMarginVer);
        clone->SetLabelCols(this->m_labelCols);
        clone->SetLabelRows(this->m_labelRows);
        clone->SetLandscape((PAGELANDSCAPETYPE)this->m_landScape);
        clone->SetPageWidth(this->m_pageWidth);
        clone->SetPageHeight(this->m_pageHeight);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CLabel::CLabel() : CExtObject(ID_PARA_LabelType), m_topMargin(0), m_leftMargin(0), m_boxWidth(0), m_boxLength(0), m_boxMarginHor(0), m_boxMarginVer(0), m_labelCols(0),
        m_labelRows(0), m_landScape(0), m_pageWidth(0), m_pageHeight(0)
    {
    }

    CLabel::~CLabel()
    {
    }

    void CLabel::InitMap(bool /*bRead*/)
    {
    }

    bool CLabel::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"topmargin", m_topMargin);
        Util::CXMLAttConverter::SetAttribute(att, L"leftmargin", m_leftMargin);
        Util::CXMLAttConverter::SetAttribute(att, L"boxwidth", m_boxWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"boxlength", m_boxLength);
        Util::CXMLAttConverter::SetAttribute(att, L"boxmarginhor", m_boxMarginHor);
        Util::CXMLAttConverter::SetAttribute(att, L"boxmarginver", m_boxMarginVer);
        Util::CXMLAttConverter::SetAttribute(att, L"labelcols", m_labelCols);
        Util::CXMLAttConverter::SetAttribute(att, L"labelrows", m_labelRows);
        Util::CXMLAttConverter::SetAttribute(att, L"landscape", g_PageLandscapeList, m_landScape);
        Util::CXMLAttConverter::SetAttribute(att, L"pagewidth", m_pageWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"pageheight", m_pageHeight);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLabel::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"topmargin", m_topMargin);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"leftmargin", m_leftMargin);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"boxwidth", m_boxWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"boxlength", m_boxLength);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"boxmarginhor", m_boxMarginHor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"boxmarginver", m_boxMarginVer);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"labelcols", m_labelCols);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"labelrows", m_labelRows);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"landscape", g_PageLandscapeList, m_landScape);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pagewidth", m_pageWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageheight", m_pageHeight);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

}
