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
#ifndef  _SCROLLBARTYPE_H_
#define  _SCROLLBARTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CScrollBarType Declaration 
    class CScrollBarType : public CAbstractFormObjectType
    {
    private:
        CScrollBarType();
    public:
        virtual ~CScrollBarType();
        static CScrollBarType* Create();

        CScrollBarType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetDelay(void) { return m_uDelay; }
        void SetDelay(UINT delay) { m_uDelay = delay; }

        UINT GetLargeChange(void) { return m_uLargeChange; }
        void SetLargeChange(UINT largeChange) { m_uLargeChange = largeChange; }

        UINT GetSmallChange(void) { return m_uSmallChange; }
        void SetSmallChange(UINT smallChange) { m_uSmallChange = smallChange; }

        INT GetMin(void) { return m_nMin; }
        void SetMin(INT min) { m_nMin = min; }

        INT GetMax(void) { return m_nMax; }
        void SetMax(INT max) { m_nMax = max; }

        INT GetPage(void) { return m_nPage; }
        void SetPage(INT page) { m_nPage = page; }

        INT GetValue(void) { return m_nValue; }
        void SetValue(INT value) { m_nValue = value; }

        SCROLLBARTYPE GetType(void) { return (SCROLLBARTYPE)m_uType; }
        void SetType(SCROLLBARTYPE type) { m_uType = (UINT)type; }


    private:
        UINT m_uDelay = 0;
        UINT m_uLargeChange = 0;
        UINT m_uSmallChange = 0;
        INT m_nMin = 0;
        INT m_nMax = 0;
        INT m_nPage = 0;
        INT m_nValue = 0;
        UINT m_uType = 0;
    };
}
#endif // _SCROLLBARTYPE_H_
