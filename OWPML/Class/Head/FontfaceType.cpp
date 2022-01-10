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
#include "FontfaceType.h"

namespace OWPML {

    CFontfaceType* CFontfaceType::Create()
    {
        return new CFontfaceType();
    }

    CFontfaceType::CFontfaceType() : CExtObject(ID_HEAD_FontfaceType), m_uFontCnt(0), m_uLang(0)
    {
    }

    CFontfaceType::~CFontfaceType()
    {
    }

    void CFontfaceType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CFontfaceType, font)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFontfaceType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(font, CFont, ID_HEAD_Font)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFontfaceType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"lang", g_FontFaceLangList, m_uLang);
        Util::CXMLAttConverter::SetAttribute(att, L"fontCnt", m_uFontCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFontfaceType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lang", g_FontFaceLangList, m_uLang);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fontCnt", m_uFontCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFont* CFontfaceType::Setfont(CFont* pfont)
    {
        CFont* font = pfont;
        if (font == NULL) {
            font = CFont::Create();
        }
        SetObject((CObject*)font);

        return font;
    }

    CFont* CFontfaceType::Getfont(int index)
    {
        return static_cast<CFont*>(GetObjectByID(ID_HEAD_Font, index));
    }

}
