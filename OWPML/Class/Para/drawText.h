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
#ifndef  _DRAWTEXT_H_
#define  _DRAWTEXT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CTextMargin;
    class CParaListType;

    // CDrawText Declaration 
    class CDrawText : public CExtObject
    {
    private:
        CDrawText();
    public:
        virtual ~CDrawText();
        static CDrawText* Create();

        CDrawText* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CTextMargin* SettextMargin(CTextMargin* textMargin = NULL);
        CTextMargin* GettextMargin(int index = 0);

        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetLastWidth(void) { return m_uLastWidth; }
        void SetLastWidth(UINT lastWidth) { m_uLastWidth = lastWidth; }

        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        BOOL GetEditable(void) { return m_bEditable == true ? TRUE : FALSE; }
        void SetEditable(BOOL editable) { m_bEditable = (editable == TRUE ? true : false); }


    private:
        UINT m_uLastWidth;
        hncstd::wstring m_strName;
        bool m_bEditable;
    };
}
#endif // _DRAWTEXT_H_
