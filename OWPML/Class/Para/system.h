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
#ifndef  _SYSTEM_H_
#define  _SYSTEM_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CSystem Declaration 
    class CSystem : public CExtObject
    {
    private:
        CSystem();
    public:
        virtual ~CSystem();
        static CSystem* Create();

        CSystem* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetH(void) { return m_uH; }
        void SetH(UINT h) { m_uH = h; }

        UINT GetS(void) { return m_uS; }
        void SetS(UINT s) { m_uS = s; }

        UINT GetL(void) { return m_uL; }
        void SetL(UINT l) { m_uL = l; }


    private:
        UINT m_uH;
        UINT m_uS;
        UINT m_uL;
    };
}
#endif // _SYSTEM_H_
