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
#include "Attribute.h"
#include "Util.h"
#include "marginAtt.h"

namespace OWPML {

    CMarginAttrubute::CMarginAttrubute() : m_uLeft(0), m_uRight(0), m_uTop(0), m_uBottom(0)
    {
    }

    CMarginAttrubute::~CMarginAttrubute()
    {
    }

    bool CMarginAttrubute::SetAttribute(CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"left", m_uLeft);
        Util::CXMLAttConverter::SetAttribute(att, L"right", m_uRight);
        Util::CXMLAttConverter::SetAttribute(att, L"top", m_uTop);
        Util::CXMLAttConverter::SetAttribute(att, L"bottom", m_uBottom);

        return true;
    }

    bool CMarginAttrubute::ReadAttribute(CAttribute* att)
    {
        bool bres = true;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"left", m_uLeft);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"right", m_uRight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"top", m_uTop);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"bottom", m_uBottom);

        return bres;
    }

}
