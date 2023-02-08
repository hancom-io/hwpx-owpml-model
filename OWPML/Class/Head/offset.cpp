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
#include "offset.h"

namespace OWPML {


    COffset* COffset::Create()
    {
        return new COffset();
    }

    COffset::COffset() : CExtObject(ID_HEAD_Offset), m_nHangul(0), m_nLatin(0), m_nHanja(0), m_nJapanese(0), m_nOther(0), m_nSymbol(0), m_nUser(0)
    {
    }

    COffset::~COffset()
    {
    }

    void COffset::InitMap(bool /*bRead*/)
    {
    }

    bool COffset::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"hangul", m_nHangul);
        Util::CXMLAttConverter::SetAttribute(att, L"latin", m_nLatin);
        Util::CXMLAttConverter::SetAttribute(att, L"hanja", m_nHanja);
        Util::CXMLAttConverter::SetAttribute(att, L"japanese", m_nJapanese);
        Util::CXMLAttConverter::SetAttribute(att, L"other", m_nOther);
        Util::CXMLAttConverter::SetAttribute(att, L"symbol", m_nSymbol);
        Util::CXMLAttConverter::SetAttribute(att, L"user", m_nUser);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool COffset::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hangul", m_nHangul);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"latin", m_nLatin);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hanja", m_nHanja);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"japanese", m_nJapanese);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"other", m_nOther);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"symbol", m_nSymbol);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"user", m_nUser);

        return bres;
    }

}
