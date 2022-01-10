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
#include "fontRef.h"

namespace OWPML {


    CFontRef* CFontRef::Create()
    {
        return new CFontRef();
    }

    CFontRef::CFontRef() : CExtObject(ID_HEAD_FontRef), m_uHanja(0), m_uSymbol(0)
    {
    }

    CFontRef::~CFontRef()
    {
    }

    void CFontRef::InitMap(bool /*bRead*/)
    {
    }

    bool CFontRef::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
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

    bool CFontRef::ReadAttribute(CAttribute* att)
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
