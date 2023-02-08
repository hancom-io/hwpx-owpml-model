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
#ifndef  _NUMBERINGTYPE_H_
#define  _NUMBERINGTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CParaHeadType2;

    // CNumberingType Declaration 
    class CNumberingType : public CExtObject
    {
    private:
        CNumberingType();
    public:
        virtual ~CNumberingType();
        static CNumberingType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CParaHeadType2* SetparaHead(CParaHeadType2* paraHead = NULL);
        CParaHeadType2* GetparaHead(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        INT GetStart(void) { return m_nStart; }
        void SetStart(INT start) { m_nStart = start; }


    private:
        UINT m_uId;
        INT m_nStart;
    };
}
#endif // _NUMBERINGTYPE_H_
