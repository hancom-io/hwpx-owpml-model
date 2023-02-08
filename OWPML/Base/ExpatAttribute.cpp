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

#include "Attribute.h"
#include "ExpatSax.h"
#include "ExpatAttribute.h"

namespace OWPML {

    CExpatAttribute::CExpatAttribute(const XML_Char ** atts) : m_attributes((EXPAT_ATTR*)atts)
    {
        unsigned int index = 0;
        m_nb_attributes = 0;

        while (atts[index] != NULL) {
            index++;
        }

        if (index > 0)
            m_nb_attributes = index / 4;

    }


    LPCWSTR CExpatAttribute::getValue(LPCWSTR const uri, LPCWSTR const localPart) const
    {
        unsigned int index = 0;
        for (index = 0; index < m_nb_attributes; ++index) {
            // localname이 같은지를 찾는다.
            if (_ustrcmp(localPart, (LPCWSTR)m_attributes[index].localname) == 0) {
                // uri가 같은지를 찾는다.
                if (_ustrcmp(uri, (LPCWSTR)m_attributes[index].uri) == 0) {
                    return (LPCWSTR)m_attributes[index].value;
                }
            }
        }

        return NULL;
    }

    LPCWSTR CExpatAttribute::getValue(LPCWSTR const qName) const
    {
        unsigned int index = 0;
        for (index = 0; index < m_nb_attributes; ++index) {
            // qname
            if (_ustrcmp(qName, (LPCWSTR)m_attributes[index].qname) == 0) {
                return (LPCWSTR)m_attributes[index].value;
            }
        }

        return NULL;
    }

    unsigned int CExpatAttribute::getLength() const
    {
        return m_nb_attributes;
    }

    LPCWSTR CExpatAttribute::getURI(const unsigned int index) const
    {
        if (m_nb_attributes > index) {
            return (LPCWSTR)m_attributes[index].uri;
        }
        return NULL;
    }

    LPCWSTR CExpatAttribute::getLocalName(const unsigned int index) const
    {
        if (m_nb_attributes > index) {
            return (LPCWSTR)m_attributes[index].localname;
        }
        return NULL;
    }

    LPCWSTR CExpatAttribute::getQName(const unsigned int index) const
    {
        if (m_nb_attributes > index) {
            return (LPCWSTR)m_attributes[index].qname;
        }
        return NULL;
    }

    LPCWSTR CExpatAttribute::getValue(const unsigned int index) const
    {
        if (m_nb_attributes > index) {
            return (LPCWSTR)m_attributes[index].value;
        }
        return NULL;
    }

    void CExpatAttribute::toString(hncstd::wstring& value)
    {
        if (m_nb_attributes > 0) {
            hncstd::wstring temp;
            WCHAR tempbuffer[_MAX_PATH];
            for (unsigned int i = 0; i < m_nb_attributes; ++i) {
                _usprintf_s(tempbuffer, _MAX_PATH, L"%s=\"%s\"", m_attributes[i].localname, m_attributes[0].value);
                value += tempbuffer;

                if (i + 1 < m_nb_attributes) {
                    value += L" ";
                }
            }
        }
    }

}
