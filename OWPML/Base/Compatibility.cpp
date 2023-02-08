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
#include "Compatibility.h"

namespace OWPML {

    //////////////////////////////////////////////////////////////////////////////
    // CDefault 
    //////////////////////////////////////////////////////////////////////////////
    CDefault* CDefault::Create()
    {
        return new CDefault();
    }

    CDefault::CDefault() : CExtObject(ID_PARA_DEFAULT)
    {
    }

    CDefault::~CDefault()
    {
    }

    bool CDefault::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDefault::ReadAttribute(CAttribute* att)
    {
        return CExtObject::ReadAttribute(att);
    }

    LPCWSTR CDefault::FindObjectName(CObject* pChildObj)
    {
        CObject* pAcParent = GetParentObj();

        if (pAcParent == NULL)
            return NULL;

        if (pAcParent->GetID() != ID_PARA_SWITCH)
            return NULL;

        CObject* pParent = pAcParent->GetParentObj();

        if (pParent == NULL)
            return NULL;

        return pParent->FindObjectName(pChildObj);
    }

    //////////////////////////////////////////////////////////////////////////////
    // CCase 
    //////////////////////////////////////////////////////////////////////////////
    CCase* CCase::Create()
    {
        return new CCase();
    }

    CCase::CCase() : CExtObject(ID_PARA_CASE)
    {
    }

    CCase::~CCase()
    {
    }

    bool CCase::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"hp:required-namespace", m_strRequires);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCase::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hp:required-namespace", m_strRequires);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    LPCWSTR CCase::FindObjectName(CObject* pChildObj)
    {
        CObject* pAcParent = GetParentObj();

        if (pAcParent == NULL)
            return NULL;

        if (pAcParent->GetID() != ID_PARA_SWITCH)
            return NULL;

        CObject* pParent = pAcParent->GetParentObj();

        if (pParent == NULL)
            return NULL;

        return pParent->FindObjectName(pChildObj);
    }

    //////////////////////////////////////////////////////////////////////////////
    // CSwitch 
    //////////////////////////////////////////////////////////////////////////////
    OWPML_BASE_REDIRECT_FUNC(HWPML_PARAGRAPH_PREFIX, CSwitch, case)
        OWPML_BASE_REDIRECT_FUNC(HWPML_PARAGRAPH_PREFIX, CSwitch, default)

        CSwitch* CSwitch::Create()
    {
        return new CSwitch();
    }

    CSwitch::CSwitch() : CNamedObject(ID_PARA_SWITCH)
    {
        SetElemName(L"hp:switch");
    }

    CSwitch::~CSwitch()
    {
    }

    void CSwitch::InitMap(bool bRead)
    {
        OWPML_BEGIN_IMPLEMENT_FUNCMAP(CSwitch)
            OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_PARAGRAPH_PREFIX, case, CCase, ID_PARA_CASE)
            OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_PARAGRAPH_PREFIX, default, CDefault, ID_PARA_DEFAULT)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CSwitch::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSwitch::ReadAttribute(CAttribute* att)
    {
        return CNamedObject::ReadAttribute(att);
    }

    CCase* CSwitch::SetCase()
    {
        CCase* pCase = CCase::Create();
        SetObject(pCase);

        return pCase;
    }

    CDefault* CSwitch::SetDefault()
    {
        CDefault* pDefault = CDefault::Create();
        SetObject(pDefault);

        return pDefault;
    }




    //////////////////////////////////////////////////////////////////////////////
    // CEpubDefault 
    //////////////////////////////////////////////////////////////////////////////
    CEpubDefault* CEpubDefault::Create()
    {
        return new CEpubDefault();
    }

    CEpubDefault::CEpubDefault() : CExtObject(ID_EPUB_DEFAULT)
    {
    }

    CEpubDefault::~CEpubDefault()
    {
    }

    bool CEpubDefault::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEpubDefault::ReadAttribute(CAttribute* att)
    {
        return CExtObject::ReadAttribute(att);
    }

    LPCWSTR CEpubDefault::FindObjectName(CObject* pChildObj)
    {
        CObject* pAcParent = GetParentObj();

        if (pAcParent == NULL)
            return NULL;

        if (pAcParent->GetID() != ID_EPUB_SWITCH)
            return NULL;

        CObject* pParent = pAcParent->GetParentObj();

        if (pParent == NULL)
            return NULL;

        return pParent->FindObjectName(pChildObj);
    }

    //////////////////////////////////////////////////////////////////////////////
    // CEpubCase 
    //////////////////////////////////////////////////////////////////////////////
    CEpubCase* CEpubCase::Create()
    {
        return new CEpubCase();
    }

    CEpubCase::CEpubCase() : CExtObject(ID_EPUB_CASE)
    {
    }

    CEpubCase::~CEpubCase()
    {
    }

    bool CEpubCase::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"epub:required-namespace", m_strRequires);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEpubCase::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"epub:required-namespace", m_strRequires);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    LPCWSTR CEpubCase::FindObjectName(CObject* pChildObj)
    {
        CObject* pAcParent = GetParentObj();

        if (pAcParent == NULL)
            return NULL;

        if (pAcParent->GetID() != ID_EPUB_SWITCH)
            return NULL;

        CObject* pParent = pAcParent->GetParentObj();

        if (pParent == NULL)
            return NULL;

        return pParent->FindObjectName(pChildObj);
    }

    //////////////////////////////////////////////////////////////////////////////
    // CEpubSwitch 
    //////////////////////////////////////////////////////////////////////////////
    OWPML_BASE_REDIRECT_FUNC(EPUB_NAMESPACE_PREFIX, CEpubSwitch, case)
        OWPML_BASE_REDIRECT_FUNC(EPUB_NAMESPACE_PREFIX, CEpubSwitch, default)

        CEpubSwitch* CEpubSwitch::Create()
    {
        return new CEpubSwitch();
    }

    CEpubSwitch::CEpubSwitch() : CNamedObject(ID_EPUB_SWITCH)
    {
        SetElemName(L"epub:switch");
    }

    CEpubSwitch::~CEpubSwitch()
    {
    }

    void CEpubSwitch::InitMap(bool bRead)
    {
        OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEpubSwitch)
            OWPML_BASE_ADD_REDIRECT_FUNC(EPUB_NAMESPACE_PREFIX, case, CEpubCase, ID_EPUB_CASE)
            OWPML_BASE_ADD_REDIRECT_FUNC(EPUB_NAMESPACE_PREFIX, default, CEpubDefault, ID_EPUB_DEFAULT)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEpubSwitch::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEpubSwitch::ReadAttribute(CAttribute* att)
    {
        return CNamedObject::ReadAttribute(att);
    }

    CEpubCase* CEpubSwitch::SetCase()
    {
        CEpubCase* pCase = CEpubCase::Create();
        SetObject(pCase);

        return pCase;
    }

    CEpubDefault* CEpubSwitch::SetDefault()
    {
        CEpubDefault* pDefault = CEpubDefault::Create();
        SetObject(pDefault);

        return pDefault;
    }

}
