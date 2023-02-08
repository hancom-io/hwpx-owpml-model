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
#include "border.h"

namespace OWPML {


    CBorder* CBorder::Create()
    {
        return new CBorder();
    }

    CBorder::CBorder() : CExtObject(ID_HEAD_Border), m_nOffsetLeft(0), m_nOffsetRight(0), m_nOffsetTop(0), m_nOffsetBottom(0), m_bConnect(false), m_bIgnoreMargin(false), m_uBorderFillIDRef(0)
    {
    }

    CBorder::~CBorder()
    {
    }

    void CBorder::InitMap(bool /*bRead*/)
    {
    }

    bool CBorder::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetLeft", m_nOffsetLeft);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetRight", m_nOffsetRight);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetTop", m_nOffsetTop);
        Util::CXMLAttConverter::SetAttribute(att, L"offsetBottom", m_nOffsetBottom);
        Util::CXMLAttConverter::SetAttribute(att, L"connect", m_bConnect);
        Util::CXMLAttConverter::SetAttribute(att, L"ignoreMargin", m_bIgnoreMargin);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBorder::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetLeft", m_nOffsetLeft);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetRight", m_nOffsetRight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetTop", m_nOffsetTop);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"offsetBottom", m_nOffsetBottom);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"connect", m_bConnect);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"ignoreMargin", m_bIgnoreMargin);

        return bres;
    }

}
