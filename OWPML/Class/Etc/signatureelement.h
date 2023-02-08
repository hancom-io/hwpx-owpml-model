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
#ifndef  _SIGNATURE_ELEMENT_H_
#define  _SIGNATURE_ELEMENT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPublicKey Declaration 
    class CPublicKey : public CStringValueObject
    {
    private:
        CPublicKey();
    public:
        virtual ~CPublicKey();
        static CPublicKey* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    };

    // CSignatures Declaration 
    class CSignatures : public CNamedObject
    {
    public:
        CSignatures();
    public:
        virtual ~CSignatures();
        static CSignatures* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual BOOL HasAnyelement(void) const { return TRUE; }

    public:
        // Element Set Fucntion
        CPublicKey* SetPublicKey(CPublicKey* ppublickey = NULL);
        CPublicKey* GetPublicKey(int index = 0);

        CStringAnyElement* SetStringAnyElement(CStringAnyElement* panyelement = NULL);
        CStringAnyElement* GetStringAnyElement(int index = 0);

        // Attribute Set/Get Fucntion
    };

} // OOXML
#endif // _SIGNATURE_ELEMENT_H_
