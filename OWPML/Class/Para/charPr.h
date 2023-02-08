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
#ifndef  _CHARPR_H_
#define  _CHARPR_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCharPr Declaration 
    class CCharPr : public CExtObject
    {
    private:
        CCharPr();
    public:
        virtual ~CCharPr();
        static CCharPr* Create();

        CCharPr* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetPrIDRef(void) { return m_uPrIDRef; }
        void SetPrIDRef(UINT prIDRef) { m_uPrIDRef = prIDRef; }

    private:
        UINT m_uPrIDRef;
    };
}
#endif // _CHARPR_H_
