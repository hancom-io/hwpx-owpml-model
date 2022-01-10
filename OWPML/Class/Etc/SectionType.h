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
#ifndef  _SECTIONTYPE_H_
#define  _SECTIONTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CPType;

    // CSectionType Declaration 
    class CSectionType : public CNamedObject
    {
    public:
        CSectionType();
    public:
        virtual ~CSectionType();
        static CSectionType* Create();

        CSectionType* Clone();
    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPType* Setp(CPType* p = NULL);
        CPType* Getp(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _SECTIONTYPE_H_
