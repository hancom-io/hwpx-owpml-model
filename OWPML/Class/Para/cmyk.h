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
#ifndef  _CMYK_H_
#define  _CMYK_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCmyk Declaration 
    class CCmyk : public CExtObject
    {
    private:
        CCmyk();
    public:
        virtual ~CCmyk();
        static CCmyk* Create();

        CCmyk* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetC(void) { return m_uC; }
        void SetC(UINT c) { m_uC = c; }

        UINT GetM(void) { return m_uM; }
        void SetM(UINT m) { m_uM = m; }

        UINT GetY(void) { return m_uY; }
        void SetY(UINT y) { m_uY = y; }

        UINT GetK(void) { return m_uK; }
        void SetK(UINT k) { m_uK = k; }


    private:
        UINT m_uC;
        UINT m_uM;
        UINT m_uY;
        UINT m_uK;
    };
}
#endif // _CMYK_H_
