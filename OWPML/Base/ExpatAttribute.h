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

#pragma once

#ifndef EXPAT_ATTRIBUTE_H
#define EXPAT_ATTRIBUTE_H

namespace OWPML {

    typedef struct expatattr
    {
        XML_Char* uri;
        XML_Char* qname;
        XML_Char* localname;
        XML_Char* value;
    } EXPAT_ATTR;

    class CExpatAttribute : public CAttribute
    {
    public:
        CExpatAttribute(const XML_Char ** atts);
        virtual ~CExpatAttribute() {}

    public:
        LPCWSTR getValue(LPCWSTR const uri, LPCWSTR const localPart) const;
        LPCWSTR getValue(LPCWSTR const qName) const;
        unsigned int getLength() const;
        LPCWSTR  getURI(const unsigned int index) const;
        LPCWSTR  getLocalName(const unsigned int index) const;
        LPCWSTR  getQName(const unsigned int index) const;
        LPCWSTR  getValue(const unsigned int index) const;


        void setValue(LPCWSTR const /*uri*/, LPCWSTR const /*localPart*/, LPCWSTR const /*value*/) {}
        void setValue(LPCWSTR const /*qname*/, LPCWSTR const /*value*/) {}
        const hncstd::wstring* toString() { return NULL; }
        void toString(hncstd::wstring& value);

    private:
        unsigned int m_nb_attributes;

        EXPAT_ATTR* m_attributes;
    };

}

#endif // EXPAT_ATTRIBUTE_H