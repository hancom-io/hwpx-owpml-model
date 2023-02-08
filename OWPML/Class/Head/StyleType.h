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
#ifndef  _STYLETYPE_H_
#define  _STYLETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CStyleType Declaration 
    class CStyleType : public CExtObject
    {
    private:
        CStyleType();
    public:
        virtual ~CStyleType();
        static CStyleType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        STYLETYPE GetType(void) { return (STYLETYPE)m_uType; }
        void SetType(STYLETYPE type) { m_uType = (UINT)type; }

        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        LPCWSTR GetEngName(void) { return m_strEngName.c_str(); }
        void SetEngName(LPCWSTR engName) { m_strEngName = engName; }

        UINT GetParaPrIDRef(void) { return m_uParaPrIDRef; }
        void SetParaPrIDRef(UINT paraPrIDRef) { m_uParaPrIDRef = paraPrIDRef; }

        UINT GetCharPrIDRef(void) { return m_uCharPrIDRef; }
        void SetCharPrIDRef(UINT charPrIDRef) { m_uCharPrIDRef = charPrIDRef; }

        UINT GetNextStyleIDRef(void) { return m_uNextStyleIDRef; }
        void SetNextStyleIDRef(UINT nextStyleIDRef) { m_uNextStyleIDRef = nextStyleIDRef; }

        INT GetLangID(void) { return m_nLangID; }
        void SetLangID(INT langID) { m_nLangID = langID; }

        BOOL GetLockForm(void) { return m_bLockForm == true ? TRUE : FALSE; }
        void SetLockForm(BOOL lockForm) { m_bLockForm = (lockForm == TRUE ? true : false); }


    private:
        UINT m_uId = 0;
        UINT m_uType = 0;
        hncstd::wstring m_strName;
        hncstd::wstring m_strEngName;
        UINT m_uParaPrIDRef = 0;
        UINT m_uCharPrIDRef = 0;
        UINT m_uNextStyleIDRef = 0;
        INT m_nLangID = 0;
        bool m_bLockForm = false;
    };
}
#endif // _STYLETYPE_H_
