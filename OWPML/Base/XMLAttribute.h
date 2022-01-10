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

#ifndef XML_ATTRIBUTE_H
#define XML_ATTRIBUTE_H

namespace OWPML {

    class CXMLAttribute : public CAttribute
    {
    public:
        CXMLAttribute() {}
        virtual ~CXMLAttribute() {}

    public:
        LPCWSTR getValue(LPCWSTR const uri, LPCWSTR const localPart) const;
        LPCWSTR getValue(LPCWSTR const qName) const;
        unsigned int getLength() const;
        LPCWSTR  getURI(const unsigned int index) const;
        LPCWSTR  getLocalName(const unsigned int index) const;
        LPCWSTR  getQName(const unsigned int index) const;
        LPCWSTR  getValue(const unsigned int index) const;


        void setValue(LPCWSTR const uri, LPCWSTR const localPart, LPCWSTR const value);
        void setValue(LPCWSTR const qname, LPCWSTR const value);

        const hncstd::wstring* toString();
        void toString(hncstd::wstring& value);

    private:
        hncstd::wstring m_mAttributeList;
    };

}

#endif // XML_ATTRIBUTE_H