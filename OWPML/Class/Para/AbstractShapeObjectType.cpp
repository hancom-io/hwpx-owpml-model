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

namespace OWPML {

    CAbstractShapeObjectType::CAbstractShapeObjectType(UINT id) : CExtObject(id), m_nZOrder(0), m_uNumberingType(ASONT_NONE), \
        m_uTextFlow(ASOTFT_BOTH_SIDES), m_bLock(false), m_uTextWrap(ASOTWT_TOP_AND_BOTTOM), m_uDropCapStyle(DCS_NONE), m_uId(0)
    {
    }

    CAbstractShapeObjectType::~CAbstractShapeObjectType()
    {
    }

    void CAbstractShapeObjectType::InitMap(bool /*bRead*/)
    {
    }

    bool CAbstractShapeObjectType::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"zOrder", m_nZOrder);
        Util::CXMLAttConverter::SetAttribute(att, L"numberingType", g_ASONumberingTypeList, m_uNumberingType);
        Util::CXMLAttConverter::SetAttribute(att, L"textWrap", g_ASOTextWrapList, m_uTextWrap, OWPML::ASOTWT_TOP_AND_BOTTOM);
        Util::CXMLAttConverter::SetAttribute(att, L"textFlow", g_ASOTextFlowList, m_uTextFlow);
        Util::CXMLAttConverter::SetAttribute(att, L"lock", m_bLock);

        Util::CXMLAttConverter::SetAttribute(att, L"dropcapstyle", g_DropcapStyleList, m_uDropCapStyle);

        return true;
    }

    bool CAbstractShapeObjectType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"zOrder", m_nZOrder);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"numberingType", g_ASONumberingTypeList, m_uNumberingType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textWrap", g_ASOTextWrapList, m_uTextWrap, OWPML::ASOTWT_SQUARE);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textFlow", g_ASOTextFlowList, m_uTextFlow);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lock", m_bLock);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"dropcapstyle", g_DropcapStyleList, m_uDropCapStyle);

        return bres;
    }

    CSz* CAbstractShapeObjectType::Setsz(CSz* psz)
    {
        CSz* sz = psz;
        if (sz == NULL) {
            sz = CSz::Create();
        }
        SetObject((CObject*)sz);

        return sz;
    }

    CSz* CAbstractShapeObjectType::Getsz(int index)
    {
        return static_cast<CSz*>(GetObjectByID(ID_PARA_Sz, index));
    }

    CASOPos* CAbstractShapeObjectType::Setpos(CASOPos* ppos)
    {
        CASOPos* pos = ppos;
        if (pos == NULL) {
            pos = CASOPos::Create();
        }
        SetObject((CObject*)pos);

        return pos;
    }

    CASOPos* CAbstractShapeObjectType::Getpos(int index)
    {
        return static_cast<CASOPos*>(GetObjectByID(ID_PARA_ASOPos, index));
    }

    COutMargin* CAbstractShapeObjectType::SetoutMargin(COutMargin* poutMargin)
    {
        COutMargin* outMargin = poutMargin;
        if (outMargin == NULL) {
            outMargin = COutMargin::Create();
        }
        SetObject((CObject*)outMargin);

        return outMargin;
    }

    COutMargin* CAbstractShapeObjectType::GetoutMargin(int index)
    {
        return static_cast<COutMargin*>(GetObjectByID(ID_PARA_OutMargin, index));
    }

    CCaption* CAbstractShapeObjectType::Setcaption(CCaption* pcaption)
    {
        CCaption* caption = pcaption;
        if (caption == NULL) {
            caption = CCaption::Create();
        }
        SetObject((CObject*)caption);

        return caption;
    }

    CCaption* CAbstractShapeObjectType::Getcaption(int index)
    {
        return static_cast<CCaption*>(GetObjectByID(ID_PARA_Caption, index));
    }

    CShapeComment* CAbstractShapeObjectType::SetshapeComment(CShapeComment* pshapeComment)
    {
        CShapeComment* shapeComment = pshapeComment;
        if (shapeComment == NULL) {
            shapeComment = CShapeComment::Create();
        }
        SetObject((CObject*)shapeComment);

        return shapeComment;
    }

    CShapeComment* CAbstractShapeObjectType::GetshapeComment(int index)
    {
        return static_cast<CShapeComment*>(GetObjectByID(ID_PARA_ShapeComment, index));
    }

}
