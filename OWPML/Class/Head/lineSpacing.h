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
#ifndef  _LINESPACING_H_
#define  _LINESPACING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CLineSpacing Declaration 
    class CLineSpacing : public CExtObject
    {
    private:
        CLineSpacing();
    public:
        virtual ~CLineSpacing();
        static CLineSpacing* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LSTYPE GetType(void) { return (LSTYPE)m_uType; }
        void SetType(LSTYPE type) { m_uType = (UINT)type; }

        INT GetValue(void) { return m_nValue; }
        void SetValue(INT value) { m_nValue = value; }

        UINTVALUETYPE GetUnit(void) { return (UINTVALUETYPE)m_uUnit; }
        void SetUnit(UINTVALUETYPE unit) { m_uUnit = (UINT)unit; }


    private:
        UINT m_uType;
        INT m_nValue;
        UINT m_uUnit;
    };
}
#endif // _LINESPACING_H_
