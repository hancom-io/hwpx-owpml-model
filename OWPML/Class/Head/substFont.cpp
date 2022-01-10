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
#include "substFont.h"

namespace OWPML {


    CSubstFont* CSubstFont::Create()
    {
        return new CSubstFont();
    }

    CSubstFont::CSubstFont() : CExtObject(ID_HEAD_SubstFont), m_bIsEmbedded(false), m_uType(0)
    {
    }

    CSubstFont::~CSubstFont()
    {
    }

    void CSubstFont::InitMap(bool /*bRead*/)
    {
    }

    bool CSubstFont::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"face", m_strFace);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_SubsFontTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"isEmbedded", m_bIsEmbedded);
        Util::CXMLAttConverter::SetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSubstFont::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"face", m_strFace);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_SubsFontTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"isEmbedded", m_bIsEmbedded);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);

        return bres;
    }

}
