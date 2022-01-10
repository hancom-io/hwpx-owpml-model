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
#ifndef  _AUTONUMFORMATTYPE_H_
#define  _AUTONUMFORMATTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CAutoNumFormatType Declaration 
    class CAutoNumFormatType : public CExtObject
    {
    private:
        CAutoNumFormatType();
    public:
        virtual ~CAutoNumFormatType();
        static CAutoNumFormatType* Create();

        CAutoNumFormatType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        NUMBERTYPE GetType(void) { return (NUMBERTYPE)m_uType; }
        void SetType(NUMBERTYPE type) { m_uType = (UINT)type; }

        LPCWSTR GetUserChar(void) { return m_strUserChar.c_str(); }
        void SetUserChar(LPCWSTR userChar) { m_strUserChar = userChar; }

        LPCWSTR GetPrefixChar(void) { return m_strPrefixChar.c_str(); }
        void SetPrefixChar(LPCWSTR prefixChar) { m_strPrefixChar = prefixChar; }

        LPCWSTR GetSuffixChar(void) { return m_strSuffixChar.c_str(); }
        void SetSuffixChar(LPCWSTR suffixChar) { m_strSuffixChar = suffixChar; }

        BOOL GetSupscript(void) { return m_bSupscript == true ? TRUE : FALSE; }
        void SetSupscript(BOOL supscript) { m_bSupscript = (supscript == TRUE ? true : false); }


    private:
        UINT m_uType;
        hncstd::wstring m_strUserChar;
        hncstd::wstring m_strPrefixChar;
        hncstd::wstring m_strSuffixChar;
        bool m_bSupscript;
    };
}
#endif // _AUTONUMFORMATTYPE_H_
