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
#include "signatureelement.h"

namespace OWPML {

    /////////////////////////////////////////////////////////////////////////////////////////
    // CPublicKey
    /////////////////////////////////////////////////////////////////////////////////////////
    CPublicKey* CPublicKey::Create()
    {
        return new CPublicKey();
    }

    CPublicKey::CPublicKey() : CStringValueObject(ID_SIG_PublicKey)
    {
    }

    CPublicKey::~CPublicKey()
    {
    }

    void CPublicKey::InitMap(bool /*bRead*/)
    {
    }

    bool CPublicKey::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CPublicKey::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;
        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CSignatures
    /////////////////////////////////////////////////////////////////////////////////////////
    CSignatures* CSignatures::Create()
    {
        return new CSignatures();
    }

    CSignatures::CSignatures() : CNamedObject(ID_SIG_signatures)
    {
        SetElemName(L"ocf:signatures");
    }

    CSignatures::~CSignatures()
    {
    }

    void CSignatures::InitMap(bool bRead)
    {
        OWPML_HPF_REDIRECT_FUNC(CPublicKey, PublicKey)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CSignatures)
            OWPML_HPF_ADD_REDIRECT_FUNC(PublicKey, CPublicKey, ID_SIG_PublicKey)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CSignatures::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSignatures::ReadAttribute(CAttribute* att)
    {
        return CNamedObject::ReadAttribute(att);
    }

    CPublicKey* CSignatures::SetPublicKey(CPublicKey* ppublickey)
    {
        CPublicKey* publickey = ppublickey;
        if (publickey == NULL) {
            publickey = CPublicKey::Create();
        }
        SetObject((CObject*)publickey);

        return publickey;
    }

    CPublicKey* CSignatures::GetPublicKey(int index)
    {
        return static_cast<CPublicKey*>(GetObjectByID(ID_SIG_PublicKey, index));
    }

    CStringAnyElement* CSignatures::SetStringAnyElement(CStringAnyElement* panyelement)
    {
        CStringAnyElement* anyelement = panyelement;
        if (anyelement == NULL) {
            anyelement = CStringAnyElement::Create();
        }
        SetObject((CObject*)anyelement);

        return anyelement;
    }

    CStringAnyElement* CSignatures::GetStringAnyElement(int index)
    {
        return static_cast<CStringAnyElement*>(GetObjectByID(ID_STRING_ANYELEMENT_ID, index));
    }



}
