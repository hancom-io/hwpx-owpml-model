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
#include "fontfaces.h"

namespace OWPML {

    CFontfaces* CFontfaces::Create()
    {
        return new CFontfaces();
    }

    CFontfaces::CFontfaces() : CExtObject(ID_HEAD_Fontfaces), m_uItemCnt(0)
    {
    }

    CFontfaces::~CFontfaces()
    {
    }

    void CFontfaces::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CFontfaces, fontface)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFontfaces)
            OWPML_HEAD_ADD_REDIRECT_FUNC(fontface, CFontfaceType, ID_HEAD_FontfaceType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFontfaces::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFontfaces::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFontfaceType* CFontfaces::Setfontface(CFontfaceType* pfontface)
    {
        CFontfaceType* fontface = pfontface;
        if (fontface == NULL) {
            fontface = CFontfaceType::Create();
        }
        SetObject((CObject*)fontface);

        return fontface;
    }

    CFontfaceType* CFontfaces::Getfontface(int index)
    {
        return static_cast<CFontfaceType*>(GetObjectByID(ID_HEAD_FontfaceType, index));
    }

}
