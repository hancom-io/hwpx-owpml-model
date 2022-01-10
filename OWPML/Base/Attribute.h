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

#ifndef _ATTRIBUTE_H_
#define _ATTRIBUTE_H_

namespace OWPML {

    class  CAttribute
    {
    public:
        CAttribute() {}
        virtual ~CAttribute() {}

    public:
        // Get ...
        virtual LPCWSTR getValue(LPCWSTR const uri, LPCWSTR const localPart) const = 0;
        virtual LPCWSTR getValue(LPCWSTR const qName) const = 0;
        virtual unsigned int getLength() const = 0;
        virtual LPCWSTR  getURI(const unsigned int index) const = 0;
        virtual LPCWSTR  getLocalName(const unsigned int index) const = 0;
        virtual LPCWSTR  getQName(const unsigned int index) const = 0;
        virtual LPCWSTR  getValue(const unsigned int index) const = 0;

        // Set ...
        virtual void setValue(LPCWSTR const uri, LPCWSTR const localPart, LPCWSTR const value) = 0;
        virtual void setValue(LPCWSTR const qname, LPCWSTR const value) = 0;

        virtual const hncstd::wstring* toString() = 0;
        virtual void toString(hncstd::wstring& value) = 0;
    };

}

#endif // _ATTRIBUTE_H_