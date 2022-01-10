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
#ifndef  _ITEMREF_H_
#define  _ITEMREF_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CItemref Declaration 
    class CItemref : public CExtObject
    {
    private:
        CItemref();
    public:
        virtual ~CItemref();
        static CItemref* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        LPCWSTR GetIdref(void) { return m_strIdref.c_str(); }
        void SetIdref(LPCWSTR idref) { m_strIdref = idref; }

        ITEMREFTYPE GetLinear(void) { return (ITEMREFTYPE)m_uLinear; }
        void SetLinear(ITEMREFTYPE linear) { m_uLinear = (UINT)linear; }


    private:
        hncstd::wstring m_strId;
        hncstd::wstring m_strIdref;
        UINT m_uLinear;
    };
}
#endif // _ITEMREF_H_
