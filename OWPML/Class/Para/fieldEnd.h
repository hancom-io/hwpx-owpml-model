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
#ifndef  _FIELDEND_H_
#define  _FIELDEND_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CFieldEnd Declaration 
    class CFieldEnd : public CExtObject
    {
    private:
        CFieldEnd();
    public:
        virtual ~CFieldEnd();
        static CFieldEnd* Create();

        CFieldEnd* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetBeginIDRef(void) { return m_uBeginIDRef; }
        void SetBeginIDRef(UINT beginIDRef) { m_uBeginIDRef = beginIDRef; }

        UINT32 GetFieldId(void) { return m_uFieldid; }
        void SetFieldId(UINT32 uFieldid) { m_uFieldid = uFieldid; }

    private:
        UINT m_uBeginIDRef = 0;
        UINT32 m_uFieldid = 0;
    };
}
#endif // _FIELDEND_H_
