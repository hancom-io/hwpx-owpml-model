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
#include "MetadataType.h"

namespace OWPML {

    CMetadataType* CMetadataType::Create()
    {
        return new CMetadataType();
    }

    CMetadataType::CMetadataType() : CExtObject(ID_OPF_MetadataType)
    {
    }

    CMetadataType::~CMetadataType()
    {
    }

    void CMetadataType::InitMap(bool bRead)
    {
        OWPML_OPF_REDIRECT_FUNC(CMetadataType, title)
            OWPML_OPF_REDIRECT_FUNC(CMetadataType, language)
            OWPML_OPF_REDIRECT_FUNC(CMetadataType, identifier)
            OWPML_OPF_REDIRECT_FUNC(CMetadataType, meta)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CMetadataType)
            OWPML_OPF_ADD_REDIRECT_FUNC(title, CTitle, ID_OPF_Title)
            OWPML_OPF_ADD_REDIRECT_FUNC(language, CLanguage, ID_OPF_Language)
            OWPML_OPF_ADD_REDIRECT_FUNC(identifier, CIdentifier, ID_OPF_Identifier)
            OWPML_OPF_ADD_REDIRECT_FUNC(meta, CMeta, ID_OPF_Meta)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CMetadataType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (!m_strId.empty()) Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMetadataType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTitle* CMetadataType::Settitle(CTitle* ptitle)
    {
        CTitle* title = ptitle;
        if (title == NULL) {
            title = CTitle::Create();
        }
        SetObject((CObject*)title);

        return title;
    }

    CTitle* CMetadataType::Gettitle(int index)
    {
        return static_cast<CTitle*>(GetObjectByID(ID_OPF_Title, index));
    }

    CLanguage* CMetadataType::Setlanguage(CLanguage* planguage)
    {
        CLanguage* language = planguage;
        if (language == NULL) {
            language = CLanguage::Create();
        }
        SetObject((CObject*)language);

        return language;
    }

    CLanguage* CMetadataType::Getlanguage(int index)
    {
        return static_cast<CLanguage*>(GetObjectByID(ID_OPF_Language, index));
    }

    CIdentifier* CMetadataType::Setidentifier(CIdentifier* pidentifier)
    {
        CIdentifier* identifier = pidentifier;
        if (identifier == NULL) {
            identifier = CIdentifier::Create();
        }
        SetObject((CObject*)identifier);

        return identifier;
    }

    CIdentifier* CMetadataType::Getidentifier(int index)
    {
        return static_cast<CIdentifier*>(GetObjectByID(ID_OPF_Identifier, index));
    }

    CMeta* CMetadataType::Setmeta(CMeta* pmeta)
    {
        CMeta* meta = pmeta;
        if (meta == NULL) {
            meta = CMeta::Create();
        }
        SetObject((CObject*)meta);

        return meta;
    }

    CMeta* CMetadataType::Getmeta(int index)
    {
        return static_cast<CMeta*>(GetObjectByID(ID_OPF_Meta, index));
    }

}
