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
#include "ratio.h"

namespace OWPML {


    CRatio* CRatio::Create()
    {
        return new CRatio();
    }

    CRatio::CRatio() : CExtObject(ID_HEAD_Ratio), m_uHangul(100), m_uLatin(100), m_uHanja(100), m_uJapanese(100), m_uOther(100), m_uSymbol(100), m_uUser(100)
    {
    }

    CRatio::~CRatio()
    {
    }

    void CRatio::InitMap(bool /*bRead*/)
    {
    }

    bool CRatio::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"hangul", m_uHangul);
        Util::CXMLAttConverter::SetAttribute(att, L"latin", m_uLatin);
        Util::CXMLAttConverter::SetAttribute(att, L"hanja", m_uHanja);
        Util::CXMLAttConverter::SetAttribute(att, L"japanese", m_uJapanese);
        Util::CXMLAttConverter::SetAttribute(att, L"other", m_uOther);
        Util::CXMLAttConverter::SetAttribute(att, L"symbol", m_uSymbol);
        Util::CXMLAttConverter::SetAttribute(att, L"user", m_uUser);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRatio::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hangul", m_uHangul);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"latin", m_uLatin);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hanja", m_uHanja);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"japanese", m_uJapanese);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"other", m_uOther);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"symbol", m_uSymbol);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"user", m_uUser);

        return bres;
    }

}
