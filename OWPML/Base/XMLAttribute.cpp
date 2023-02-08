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
#include "PartNameSpaceInfo.h"
#include "XMLAttribute.h"

namespace OWPML {

    LPCWSTR CXMLAttribute::getValue(LPCWSTR const /*uri*/, LPCWSTR const /*localPart*/) const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return NULL;
    }

    LPCWSTR CXMLAttribute::getValue(LPCWSTR const /*qName*/) const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return NULL;
    }

    unsigned int CXMLAttribute::getLength() const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return 0;
    }

    LPCWSTR CXMLAttribute::getURI(const unsigned int /*index*/) const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return NULL;
    }

    LPCWSTR CXMLAttribute::getLocalName(const unsigned int /*index*/) const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return NULL;
    }

    LPCWSTR CXMLAttribute::getQName(const unsigned int /*index*/) const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return NULL;
    }

    LPCWSTR CXMLAttribute::getValue(const unsigned int /*index*/) const
    {
        _ASSERT(FALSE);        // Export시에는 전혀 사용되지 않는다.
        return NULL;
    }

    void CXMLAttribute::setValue(LPCWSTR const uri, LPCWSTR const localPart, LPCWSTR const value)
    {
        LPCWSTR prefix = NULL;
        CPartNameSpaceInfo* pnamespace = CPartNameSpaceInfo::GetMgr();
        if (pnamespace != NULL) {
            prefix = pnamespace->FindStandardPrefixFromNamespace(uri);
        }

        m_mAttributeList.append(L" ");
        if (prefix) {
            m_mAttributeList.append(prefix);
            m_mAttributeList.append(L":");
        }
        m_mAttributeList.append(localPart);
        m_mAttributeList.append(L"=\"");
        m_mAttributeList.append(value);
        m_mAttributeList.append(L"\"");
    }

    void CXMLAttribute::setValue(LPCWSTR const qname, LPCWSTR const value)
    {
        m_mAttributeList.append(L" ");
        m_mAttributeList.append(qname);
        m_mAttributeList.append(L"=\"");
        m_mAttributeList.append(value);
        m_mAttributeList.append(L"\"");
    }

    const hncstd::wstring* CXMLAttribute::toString()
    {
        return &m_mAttributeList;
    }

    void CXMLAttribute::toString(hncstd::wstring& value)
    {
        value = m_mAttributeList;
    }

}