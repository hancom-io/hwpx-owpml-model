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
#ifndef  _SEG_H_
#define  _SEG_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CSeg Declaration 
    class CSeg : public CExtObject
    {
    private:
        CSeg();
    public:
        virtual ~CSeg();
        static CSeg* Create();

        CSeg* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        SEGTYPE GetType(void) { return (SEGTYPE)m_uType; }
        void SetType(SEGTYPE type) { m_uType = (UINT)type; }

        INT GetX1(void) { return m_nX1; }
        void SetX1(INT x1) { m_nX1 = x1; }

        INT GetY1(void) { return m_nY1; }
        void SetY1(INT y1) { m_nY1 = y1; }

        INT GetX2(void) { return m_nX2; }
        void SetX2(INT x2) { m_nX2 = x2; }

        INT GetY2(void) { return m_nY2; }
        void SetY2(INT y2) { m_nY2 = y2; }


    private:
        UINT m_uType;
        INT m_nX1;
        INT m_nY1;
        INT m_nX2;
        INT m_nY2;
    };
}
#endif // _SEG_H_
