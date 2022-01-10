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
#include "RDF.h"

namespace OWPML {



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfType Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    CRdfType* CRdfType::Create()
    {
        return new CRdfType();
    }

    CRdfType::CRdfType() : CExtObject(ID_RDF_TYPE)
    {
    }

    CRdfType::~CRdfType()
    {
    }

    void CRdfType::InitMap(bool /*bRead*/)
    {
    }

    bool CRdfType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"rdf:resource", m_strResource);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRdfType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rdf:resource", m_strResource);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfDescription Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    CRdfDescription* CRdfDescription::Create()
    {
        return new CRdfDescription();
    }

    CRdfDescription::CRdfDescription() : CExtObject(ID_RDF_DESCRIPTION)
    {
    }

    CRdfDescription::~CRdfDescription()
    {
    }

    void CRdfDescription::InitMap(bool bRead)
    {
        OWPML_RDF_REDIRECT_FUNC(CType, type)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CRdfDescription)
            OWPML_RDF_ADD_REDIRECT_FUNC(type, CRdfType, ID_RDF_TYPE)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CRdfDescription::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"rdf:about", m_strAbout, true);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRdfDescription::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rdf:about", m_strAbout);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CObject* CRdfDescription::ChildElementCreate(LPCWSTR const qname, const CAttribute* /*attrs*/)
    {
        OWPML::CRdfAnyElement* panyelement = OWPML::CRdfAnyElement::Create();
        if (panyelement) {
            panyelement->SetElemName(qname);
        }

        return panyelement;
    }

    CRdfType* CRdfDescription::Settype(CRdfType* type)
    {
        CRdfType* ptype = type;
        if (ptype == NULL) {
            ptype = CRdfType::Create();
        }
        SetObject((CObject*)ptype);

        return ptype;
    }

    CRdfType* CRdfDescription::Gettype(int index)
    {
        return static_cast<CRdfType*>(GetObjectByID(ID_RDF_TYPE, index));
    }

    CRdfAnyElement* CRdfDescription::SetAnyelement(CRdfAnyElement* anyele)
    {
        CRdfAnyElement* panyele = anyele;
        if (panyele == NULL) {
            panyele = CRdfAnyElement::Create();
        }
        SetObject((CObject*)panyele);

        return panyele;
    }

    CRdfAnyElement* CRdfDescription::GetAnyelement(int index)
    {
        return static_cast<CRdfAnyElement*>(GetObjectByID(ID_RDF_ANYELEMENT, index));
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdf Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    CRdf* CRdf::Create()
    {
        return new CRdf();
    }

    CRdf::CRdf() : CNamedObject(ID_RDF_RDF)
    {
        SetElemName(L"rdf:RDF");
    }

    CRdf::~CRdf()
    {
    }

    void CRdf::InitMap(bool bRead)
    {
        OWPML_RDF_REDIRECT_FUNC(CDescription, Description)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CRdfType)
            OWPML_RDF_ADD_REDIRECT_FUNC(Description, CRdfDescription, ID_RDF_DESCRIPTION)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CRdf::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRdf::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CRdfDescription* CRdf::SetDescription(CRdfDescription* description)
    {
        CRdfDescription* pdescription = description;
        if (pdescription == NULL) {
            pdescription = CRdfDescription::Create();
        }
        SetObject((CObject*)pdescription);

        return pdescription;
    }

    CRdfDescription* CRdf::GetDescription(int index)
    {
        return static_cast<CRdfDescription*>(GetObjectByID(ID_RDF_DESCRIPTION, index));
    }

}
