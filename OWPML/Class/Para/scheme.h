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
#ifndef  _SCHEME_H_
#define  _SCHEME_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CScheme Declaration 
    class CScheme : public CExtObject
    {
    private:
        CScheme();
    public:
        virtual ~CScheme();
        static CScheme* Create();

        CScheme* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetR(void) { return m_uR; }
        void SetR(UINT r) { m_uR = r; }

        UINT GetG(void) { return m_uG; }
        void SetG(UINT g) { m_uG = g; }

        UINT GetB(void) { return m_uB; }
        void SetB(UINT b) { m_uB = b; }


    private:
        UINT m_uR;
        UINT m_uG;
        UINT m_uB;
    };
}
#endif // _SCHEME_H_
