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
#include "LineShapeType.h"

namespace OWPML {


    CLineShapeType* CLineShapeType::Create()
    {
        return new CLineShapeType();
    }

    CLineShapeType* CLineShapeType::Clone()
    {
        CLineShapeType* clone = new CLineShapeType();

        clone->SetColor(this->m_cColor);
        clone->SetWidth(this->m_uWidth);
        clone->SetStyle((LINETYPE2)this->m_uStyle);
        clone->SetEndCap((LINEENDCAPTYPE)this->m_uEndCap);
        clone->SetHeadStyle((ARROWTYPE)this->m_uHeadStyle);
        clone->SetTailStyle((ARROWTYPE)this->m_uTailStyle);
        clone->SetHeadSz((ARROWSIZE)this->m_uHeadSz);
        clone->SetHeadFill(this->m_bHeadFill);
        clone->SetTailFill(this->m_bTailFill);
        clone->SetTailSz((ARROWSIZE)this->m_uTailSz);
        clone->SetOutlineStyle((OUTLINESTYLE)this->m_uOutlineStyle);
        clone->SetAlpha(this->m_fAlpha);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CLineShapeType::CLineShapeType() : CExtObject(ID_PARA_LineShapeType), m_uWidth(0), m_uStyle(LT2_SOLID), m_uEndCap(LECT_FLAT), m_cColor(0x000000), \
        m_uHeadStyle(AT_NORMAL), m_uTailStyle(AT_NORMAL), m_uHeadSz(AST_SMALL_SMALL), m_uTailSz(AST_SMALL_SMALL), m_uOutlineStyle(OLST_NORMAL), m_fAlpha(0.0), m_bHeadFill(false), m_bTailFill(false)
    {
    }

    CLineShapeType::~CLineShapeType()
    {
    }

    void CLineShapeType::InitMap(bool /*bRead*/)
    {
    }

    bool CLineShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"style", g_LineTypeList2, m_uStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"endCap", g_LineEndCapList, m_uEndCap);
        Util::CXMLAttConverter::SetAttribute(att, L"headStyle", g_ArrowTypeList, m_uHeadStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"tailStyle", g_ArrowTypeList, m_uTailStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"headfill", m_bHeadFill);
        Util::CXMLAttConverter::SetAttribute(att, L"tailfill", m_bTailFill);
        Util::CXMLAttConverter::SetAttribute(att, L"headSz", g_ArrowSizeList, m_uHeadSz);
        Util::CXMLAttConverter::SetAttribute(att, L"tailSz", g_ArrowSizeList, m_uTailSz);
        Util::CXMLAttConverter::SetAttribute(att, L"outlineStyle", g_OutLineStyleList, m_uOutlineStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLineShapeType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"style", g_LineTypeList2, m_uStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"endCap", g_LineEndCapList, m_uEndCap);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"headStyle", g_ArrowTypeList, m_uHeadStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tailStyle", g_ArrowTypeList, m_uTailStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"headfill", m_bHeadFill);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tailfill", m_bTailFill);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"headSz", g_ArrowSizeList, m_uHeadSz);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tailSz", g_ArrowSizeList, m_uTailSz);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"outlineStyle", g_OutLineStyleList, m_uOutlineStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);

        return bres;
    }

}
