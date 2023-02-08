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
#ifndef  _EDITTYPE_H_
#define  _EDITTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CText;

    // CEditType Declaration 
    class CEditType : public CAbstractFormObjectType
    {
    private:
        CEditType();
    public:
        virtual ~CEditType();
        static CEditType* Create();

        CEditType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CText* Settext(CText* text = NULL);
        CText* Gettext(int index = 0);

        // Attribute Set/Get Fucntion
        BOOL GetMultiLine(void) { return m_bMultiLine == true ? TRUE : FALSE; }
        void SetMultiLine(BOOL multiLine) { m_bMultiLine = (multiLine == TRUE ? true : false); }

        LPCWSTR GetPasswordChar(void) { return m_strPasswordChar.c_str(); }
        void SetPasswordChar(LPCWSTR passwordChar) { m_strPasswordChar = passwordChar; }

        UINT GetMaxLength(void) { return m_uMaxLength; }
        void SetMaxLength(UINT maxLength) { m_uMaxLength = maxLength; }

        EDSCROLLBARSTYPE GetScrollBars(void) { return (EDSCROLLBARSTYPE)m_uScrollBars; }
        void SetScrollBars(EDSCROLLBARSTYPE scrollBars) { m_uScrollBars = (UINT)scrollBars; }

        EDTABKEYBHTYPE GetTabKeyBehavior(void) { return (EDTABKEYBHTYPE)m_uTabKeyBehavior; }
        void SetTabKeyBehavior(EDTABKEYBHTYPE tabKeyBehavior) { m_uTabKeyBehavior = (UINT)tabKeyBehavior; }

        BOOL GetNumOnly(void) { return m_bNumOnly == true ? TRUE : FALSE; }
        void SetNumOnly(BOOL numOnly) { m_bNumOnly = (numOnly == TRUE ? true : false); }

        BOOL GetReadOnly(void) { return m_bReadOnly == true ? TRUE : FALSE; }
        void SetReadOnly(BOOL readOnly) { m_bReadOnly = (readOnly == TRUE ? true : false); }

        EDITALIGNTYPE GetAlignText(void) { return (EDITALIGNTYPE)m_uAlignText; }
        void SetAlignText(EDITALIGNTYPE alignText) { m_uAlignText = (UINT)alignText; }


    private:
        bool m_bMultiLine;
        hncstd::wstring m_strPasswordChar;
        UINT m_uMaxLength;
        UINT m_uScrollBars;
        UINT m_uTabKeyBehavior = 0;
        bool m_bNumOnly;
        bool m_bReadOnly;
        UINT m_uAlignText;
    };
}
#endif // _EDITTYPE_H_
