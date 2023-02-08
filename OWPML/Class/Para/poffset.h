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
#ifndef  _POFFSET_H_
#define  _POFFSET_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPBFOffset Declaration 
    class CPBFOffset : public CExtObject
    {
    private:
        CPBFOffset();
    public:
        virtual ~CPBFOffset();
        static CPBFOffset* Create();

        CPBFOffset* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetLeft(void) { return m_uLeft; }
        void SetLeft(UINT left) { m_uLeft = left; }

        UINT GetRight(void) { return m_uRight; }
        void SetRight(UINT right) { m_uRight = right; }

        UINT GetTop(void) { return m_uTop; }
        void SetTop(UINT top) { m_uTop = top; }

        UINT GetBottom(void) { return m_uBottom; }
        void SetBottom(UINT bottom) { m_uBottom = bottom; }


    private:
        UINT m_uLeft;
        UINT m_uRight;
        UINT m_uTop;
        UINT m_uBottom;
    };

    // CASCOffset Declaration 
    class CASCOffset : public CExtObject
    {
    private:
        CASCOffset();
    public:
        virtual ~CASCOffset();
        static CASCOffset* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetX(void) { return m_uX; }
        void SetX(UINT x) { m_uX = x; }

        UINT GetY(void) { return m_uY; }
        void SetY(UINT y) { m_uY = y; }


    private:
        UINT m_uX;
        UINT m_uY;
    };
}
#endif // _OFFSET_H_
