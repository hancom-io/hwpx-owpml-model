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

#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

namespace OWPML {

    class CSerializer
    {
    public:
        CSerializer() {}
        virtual ~CSerializer() {}

    public:
        virtual bool WriteElement(LPCWSTR pCurObjName, CObject* object, CAttribute* attribute, LPCWSTR value, bool bAvailPreserveSpace = true) = 0;
        virtual bool WriteElementWithBuffer(LPCWSTR pCurObjName, CObject* object, CAttribute* attribute, LPCWSTR value, LPCWSTR buffer, int bufferlen, bool bAvailPreserveSpace = true) = 0;
        virtual bool WriteAttribute(CAttribute* attribute) = 0;
        virtual bool WriteBuffer(LPCWSTR buffer, int bufferlen) = 0;

        virtual bool Save(LPCWSTR path, CNamedObject* object) = 0;
        virtual bool Save(hncstd::wstringstream& streambuffer, CNamedObject* object) = 0;
        virtual bool Open(LPCWSTR path) = 0;
    };

}

#endif // _SERIALIZER_H_
