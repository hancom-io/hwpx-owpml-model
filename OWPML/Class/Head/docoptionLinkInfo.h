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
#ifndef  _DOCOPTION_LINKINFO_H_
#define  _DOCOPTION_LINKINFO_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CDocOptionLink Declaration 
    class CDocOptionLinkInfo : public CExtObject
    {
    private:
        CDocOptionLinkInfo();
    public:
        virtual ~CDocOptionLinkInfo();
        static CDocOptionLinkInfo* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR Getpath(void) { return m_Path.c_str(); }
        void Setpath(LPCWSTR path) { m_Path = path; }

        BOOL GetpageInherit(void) { return m_bPageInherit == true ? TRUE : FALSE; }
        void SetpageInherit(BOOL bpageInherit) { m_bPageInherit = (bpageInherit == TRUE ? true : false); }

        BOOL GetfootnoteInherit(void) { return m_bFootnoteInherit == true ? TRUE : FALSE; }
        void SetfootnoteInherit(BOOL bfootnoteInherit) { m_bFootnoteInherit = (bfootnoteInherit == TRUE ? true : false); }

    private:
        hncstd::wstring m_Path;
        bool m_bPageInherit;
        bool m_bFootnoteInherit;
    };

    // ccl, 공공누리
    class CDocOptionLicenseMark : public CExtObject
    {
    private:
        CDocOptionLicenseMark();
    public:
        virtual ~CDocOptionLicenseMark();
        static CDocOptionLicenseMark* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        // attribute
        LICENSTYPE Gettype(void) { return (LICENSTYPE)m_uType; }
        void Settype(LICENSTYPE type) { m_uType = (UINT)type; }

        BYTE Getflag(void) { return m_bFlag; }
        void Setflag(BYTE flag) { m_bFlag = flag; }

        BYTE Getlang(void) { return m_bLang; }
        void Setlang(BYTE lang) { m_bLang = lang; }

    private:
        UINT m_uType;
        BYTE m_bFlag;
        BYTE m_bLang; // Nation 코드
    };

}
#endif // _DOCOPTION_LINKINFO_H_
