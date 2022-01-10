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
#include "anyelement.h"

namespace OWPML {

    //////////////////////////////////////////////////////////////////////////////
    // CStringAnyElement 
    //////////////////////////////////////////////////////////////////////////////
    CStringAnyElement* CStringAnyElement::Create()
    {
        return new CStringAnyElement();
    }

    CStringAnyElement::CStringAnyElement() : CExtObject(ID_STRING_ANYELEMENT_ID)
    {
    }

    CStringAnyElement::~CStringAnyElement()
    {
    }

    void CStringAnyElement::InitMap(bool /*bRead*/)
    {
    }

    bool CStringAnyElement::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* serialize, CAttribute* /*att*/)
    {
        return serialize->WriteBuffer(m_anyelementvalue.c_str(), m_anyelementvalue.length());
    }

    bool CStringAnyElement::ReadAttribute(CAttribute* /*att*/)
    {
        return TRUE;
    }

    void CStringAnyElement::ToStringStartElement(LPCWSTR pCurObjName, CAttribute* att, hncstd::wstring& xmlnamespace)
    {
        m_anyelementvalue.append(L"<");
        m_anyelementvalue.append(pCurObjName);

        if (!xmlnamespace.empty()) {
            m_anyelementvalue.append(L" ");
            m_anyelementvalue.append(xmlnamespace);
        }

        hncstd::wstring attvalue;
        att->toString(attvalue);
        if (!attvalue.empty()) {
            m_anyelementvalue.append(L" ");
            m_anyelementvalue.append(attvalue);
        }
        m_anyelementvalue.append(L">");
    }

    bool CStringAnyElement::ReadNodeValue(LPCWSTR const value, const unsigned int length)
    {
        m_anyelementvalue.append(value, length);
        return true;
    }

    void CStringAnyElement::ToStringEndElement(LPCWSTR pCurObjName)
    {
        m_anyelementvalue.append(L"</");
        m_anyelementvalue.append(pCurObjName);
        m_anyelementvalue.append(L">");
    }

    //////////////////////////////////////////////////////////////////////////////
    // CAnyElement 
    //////////////////////////////////////////////////////////////////////////////
    CAnyElement* CAnyElement::Create()
    {
        return new CAnyElement();
    }

    CAnyElement::CAnyElement() : CExtObject(ID_ANYELEMENT_ID)
    {
    }

    CAnyElement::~CAnyElement()
    {
    }

    void CAnyElement::InitMap(bool /*bRead*/)
    {
    }

    bool CAnyElement::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        std::map<hncstd::wstring, hncstd::wstring>::iterator attiter;

        for (attiter = m_attribute.begin(); attiter != m_attribute.end(); ++attiter) {
            if ((attiter->first.length() > 0) && (attiter->second.length() > 0))
                Util::CXMLAttConverter::SetAttribute(att, attiter->first.c_str(), attiter->second.c_str());
        }

        return serialize->WriteElement(pCurObjName, this, att, m_value.c_str(), false);
    }

    bool CAnyElement::ReadAttribute(CAttribute* att)
    {
        if (att == 0)
            return false;

        int count = att->getLength();

        for (int i = 0; i < count; i++) {
            m_attribute[att->getQName(i)] = att->getValue(i);
        }
        return true;
    }

    void CAnyElement::ToStringStartElement(LPCWSTR /*pCurObjName*/, CAttribute* /*att*/, hncstd::wstring& /*xmlnamespace*/)
    {
        //m_anyelementvalue.append(L"<");
        //m_anyelementvalue.append(pCurObjName);

        //if (!xmlnamespace.empty()) {
        //    m_anyelementvalue.append(L" ");
        //    m_anyelementvalue.append(xmlnamespace);
        //}

        //hncstd::wstring attvalue;
        //att->toString(attvalue);
        //if (!attvalue.empty()) {
        //    m_anyelementvalue.append(L" ");
        //    m_anyelementvalue.append(attvalue);
        //}
        //m_anyelementvalue.append(L">");
    }

    bool CAnyElement::ReadNodeValue(LPCWSTR const value, const unsigned int length)
    {
        m_value.append(value, length);
        return true;
    }

    void CAnyElement::ToStringEndElement(LPCWSTR /*pCurObjName*/)
    {
        //m_anyelementvalue.append(L"</");
        //m_anyelementvalue.append(pCurObjName);
        //m_anyelementvalue.append(L">");
    }

    CAnyElement* CAnyElement::GetChildElement(LPCWSTR pChildObjName, LPCWSTR pAttributeName, LPCWSTR pAttributeValue)
    {
        CAnyElement* pchild = NULL;

        if (pChildObjName && pAttributeName && pAttributeValue) {
            UINT count = GetChildCount();
            LPCWSTR attvalue = NULL;
            CAnyElement* piterch = NULL;

            for (UINT index = 0; index < count; ++index) {
                piterch = (CAnyElement*)GetObjectByIndex(index);
                if (piterch) {
                    attvalue = piterch->Getattribute(pAttributeName);
                    if (attvalue && (_ustrcmp(attvalue, pAttributeValue) == 0)) {
                        pchild = piterch;
                        break;
                    }
                }
            }
        }

        return pchild;
    }

    LPCWSTR CAnyElement::Getattribute(LPCWSTR attname)
    {
        std::map<hncstd::wstring, hncstd::wstring>::iterator fiter;
        fiter = m_attribute.find(attname);
        if (fiter != m_attribute.end())
            return fiter->second.c_str();

        return NULL;
    }

    void CAnyElement::Setattribute(LPCWSTR attname, LPCWSTR attvalue)
    {
        m_attribute[attname] = attvalue;
    }

    void CAnyElement::ReSetvalue(void)
    {
        if (m_IgnoreSpace) {
            const hncstd::wstring spacestring = L" \t\n\v\f\r";
            m_value = m_value.erase(m_value.find_last_not_of(spacestring) + 1);
            m_value = m_value.erase(0, m_value.find_first_not_of(spacestring));
        }
    }






    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfAnyElement Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    CRdfAnyElement* CRdfAnyElement::Create()
    {
        return new CRdfAnyElement();
    }

    CRdfAnyElement::CRdfAnyElement()
        : CExtObject(ID_RDF_ANYELEMENT)
        , m_bvalue(FALSE)
    {
    }

    CRdfAnyElement::~CRdfAnyElement()
    {
    }

    void CRdfAnyElement::InitMap(bool /*bRead*/)
    {
    }

    bool CRdfAnyElement::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        hncstd::wstring namespaceprifex = L"xmlns";
        if (!m_prefix.empty()) {
            namespaceprifex += L":";
            namespaceprifex += m_prefix;
        }

        hncstd::wstring newname = pCurObjName;
        if (newname.find(L':', 0) == -1) {
            if (!m_prefix.empty()) {
                newname = m_prefix.c_str();
                newname += L':';
                newname += pCurObjName;
            }
        }

        Util::CXMLAttConverter::SetAttribute(att, namespaceprifex.c_str(), m_namespace.c_str());
        Util::CXMLAttConverter::SetAttribute(att, L"rdf:resource", m_strResource);

        return serialize->WriteElement(newname.c_str(), this, att, NULL);
    }

    bool CRdfAnyElement::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rdf:resource", m_strResource);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CObject* CRdfAnyElement::ChildElementCreate(LPCWSTR const qname, const CAttribute* /*attrs*/)
    {
        OWPML::CRdfAnyElement* panyelement = OWPML::CRdfAnyElement::Create();
        if (panyelement) {
            panyelement->SetElemName(qname);
        }

        return panyelement;
    }



}
