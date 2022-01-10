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

#ifndef XML_SERIALIZER_H
#define XML_SERIALIZER_H

namespace OWPML {

    class IPart;
    class CBaseStream;
    class CAnyElement;


    ///////////////////////////////////////////////////////
    // CXMLSerializer Declaration
    class CXMLSerializer : public CSerializer
    {
    public:
        CXMLSerializer();
        virtual ~CXMLSerializer();

    public:
        bool WriteElement(LPCWSTR pCurObjName, CObject* object, CAttribute* attribute, LPCWSTR value, bool bAvailPreserveSpace = true);
        bool WriteElementWithBuffer(LPCWSTR pCurObjName, CObject* object, CAttribute* attribute, LPCWSTR value, LPCWSTR buffer, int bufferlen, bool bAvailPreserveSpace = true);
        bool WriteAttribute(CAttribute* attribute);
        bool WriteBuffer(LPCWSTR buffer, int bufferlen);

        bool WriteRequiresAttribute(LPCWSTR requires, CAttribute* attribute);

        bool Save(LPCWSTR path, CNamedObject* object);
        bool Save(hncstd::wstringstream& streambuffer, CNamedObject* object);
        bool SaveAnyElement(hncstd::wstringstream& streambuffer, CAnyElement* object, bool bheadcontain = true);
        bool Open(LPCWSTR path);
        void CloseStream();

    private:
        void _SetNamespace(CAttribute* attribute, LPCWSTR strNamespace);
        void _SetNamespaces(IPart* rootpart, unsigned int id, CAttribute* attribute);
        BOOL _NeedPreserveWhiteSpace(LPCWSTR valueStr);

    protected:
        CBaseStream* m_bufStream;

    };

}

#endif // XML_SERIALIZER_H
