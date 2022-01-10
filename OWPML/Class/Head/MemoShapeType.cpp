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
#include "MemoShapeType.h"

namespace OWPML {


    CMemoShapeType* CMemoShapeType::Create()
    {
        return new CMemoShapeType();
    }

    CMemoShapeType::CMemoShapeType() : CExtObject(ID_HEAD_MemoShapeType)
        , m_uId(0)
        , m_uWidth(55)
        , m_uLineWidth(LWT_0_12)
        , m_uLineType(LT2_SOLID)
        , m_cLineColor(RGB(0, 0, 0))
        , m_cFillColor(RGB(0xCC, 0xFF, 0x99))
        , m_cActiveColor(RGB(0xFF, 0xFF, 0x99))
        , m_uMemoType(MST_NOMAL)
    {
    }

    CMemoShapeType::~CMemoShapeType()
    {
    }

    void CMemoShapeType::InitMap(bool /*bRead*/)
    {
    }

    bool CMemoShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"lineWidth", m_uLineWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"lineType", g_LineTypeList2, m_uLineType);
        Util::CXMLAttConverter::SetAttribute(att, L"lineColor", m_cLineColor);
        Util::CXMLAttConverter::SetAttribute(att, L"fillColor", m_cFillColor);
        Util::CXMLAttConverter::SetAttribute(att, L"activeColor", m_cActiveColor);
        Util::CXMLAttConverter::SetAttribute(att, L"memoType", g_MemoShapeTypeList, m_uMemoType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMemoShapeType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineWidth", m_uLineWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineType", g_LineTypeList2, m_uLineType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineColor", m_cLineColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fillColor", m_cFillColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"activeColor", m_cActiveColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"memoType", g_MemoShapeTypeList, m_uMemoType);

        return bres;
    }

}
