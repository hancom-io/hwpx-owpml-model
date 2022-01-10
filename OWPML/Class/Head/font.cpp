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
#include "font.h"

namespace OWPML {

    CFont* CFont::Create()
    {
        return new CFont();
    }

    CFont::CFont() : CExtObject(ID_HEAD_Font), m_bIsEmbedded(false), m_uType(0), m_uId(0)
    {
    }

    CFont::~CFont()
    {
    }

    void CFont::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CFont, substFont)
            OWPML_HEAD_REDIRECT_FUNC(CFont, typeInfo)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFont)
            OWPML_HEAD_ADD_REDIRECT_FUNC(substFont, CSubstFont, ID_HEAD_SubstFont)
            OWPML_HEAD_ADD_REDIRECT_FUNC(typeInfo, CTypeInfo, ID_HEAD_TypeInfo)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFont::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"face", m_strFace);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_FontTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"isEmbedded", m_bIsEmbedded);
        if (!m_strBinaryItemIDRef.empty())
            Util::CXMLAttConverter::SetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFont::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"face", m_strFace);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_FontTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"isEmbedded", m_bIsEmbedded);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CSubstFont* CFont::SetsubstFont(CSubstFont* psubstFont)
    {
        CSubstFont* substFont = psubstFont;
        if (substFont == NULL) {
            substFont = CSubstFont::Create();
        }
        SetObject((CObject*)substFont);

        return substFont;
    }

    CSubstFont* CFont::GetsubstFont(int index)
    {
        return static_cast<CSubstFont*>(GetObjectByID(ID_HEAD_SubstFont, index));
    }

    CTypeInfo* CFont::SettypeInfo(CTypeInfo* ptypeInfo)
    {
        CTypeInfo* typeInfo = ptypeInfo;
        if (typeInfo == NULL) {
            typeInfo = CTypeInfo::Create();
        }
        SetObject((CObject*)typeInfo);

        return typeInfo;
    }

    CTypeInfo* CFont::GettypeInfo(int index)
    {
        return static_cast<CTypeInfo*>(GetObjectByID(ID_HEAD_TypeInfo, index));
    }

}
