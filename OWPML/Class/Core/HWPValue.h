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
#ifndef  _HWPVALUE_H_
#define  _HWPVALUE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CHWPValue Declaration 
    class CHWPValue : public CExtObject
    {
    public:
        CHWPValue(UINT id = ID_CORE_HWPValue);
    public:
        virtual ~CHWPValue();
        static CHWPValue* Create();
        static CHWPValue* CreateArg(UINT id = ID_CORE_HWPValue);

        CHWPValue* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetValue(void) { return m_nValue; }
        void SetValue(INT value) { m_nValue = value; }

        UINTVALUETYPE GetUnit(void) { return (UINTVALUETYPE)m_uUnit; }
        void SetUnit(UINTVALUETYPE unit) { m_uUnit = (UINT)unit; }


    private:
        INT m_nValue;
        UINT m_uUnit;
    };
}
#endif // _HWPVALUE_H_
