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
#ifndef  _EFFECT_H_
#define  _EFFECT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CEffect Declaration 
    class CEffect : public CExtObject
    {
    private:
        CEffect();
    public:
        virtual ~CEffect();
        static CEffect* Create();

        CEffect* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        EFFECTTYPE GetType(void) { return (EFFECTTYPE)m_uType; }
        void SetType(EFFECTTYPE type) { m_uType = (UINT)type; }

        FLOAT GetValue(void) { return m_fValue; }
        void SetValue(FLOAT value) { m_fValue = value; }


    private:
        UINT m_uType = 0;
        FLOAT m_fValue = 0;
    };
}
#endif // _EFFECT_H_
