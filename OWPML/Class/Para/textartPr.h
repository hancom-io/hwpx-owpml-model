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
#ifndef  _TEXTARTPR_H_
#define  _TEXTARTPR_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CTextartPr Declaration 
    class CTextartPr : public CExtObject
    {
    private:
        CTextartPr();
    public:
        virtual ~CTextartPr();
        static CTextartPr* Create();

        CTextartPr* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CShadowType* Setshadow(CShadowType* shadow = NULL);
        CShadowType* Getshadow(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetFontName(void) { return m_strFontName.c_str(); }
        void SetFontName(LPCWSTR fontName) { m_strFontName = fontName; }

        LPCWSTR GetFontStyle(void) { return m_strFontStyle.c_str(); }
        void SetFontStyle(LPCWSTR fontStyle) { m_strFontStyle = fontStyle; }

        TEXTARTFONTTYPE GetFontType(void) { return (TEXTARTFONTTYPE)m_uFontType; }
        void SetFontType(TEXTARTFONTTYPE fontType) { m_uFontType = (UINT)fontType; }

        TEXTARTSHAPETYPE GetTextShape(void) { return (TEXTARTSHAPETYPE)m_uTextShape; }
        void SetTextShape(TEXTARTSHAPETYPE textShape) { m_uTextShape = (UINT)textShape; }

        UINT GetLineSpacing(void) { return m_uLineSpacing; }
        void SetLineSpacing(UINT lineSpacing) { m_uLineSpacing = lineSpacing; }

        UINT GetCharSpacing(void) { return m_uCharSpacing; }
        void SetCharSpacing(UINT charSpacing) { m_uCharSpacing = charSpacing; }

        TEXTARTALIGNTYPE GetAlign(void) { return (TEXTARTALIGNTYPE)m_uAlign; }
        void SetAlign(TEXTARTALIGNTYPE align) { m_uAlign = (UINT)align; }


    private:
        hncstd::wstring m_strFontName;
        hncstd::wstring m_strFontStyle;
        UINT m_uFontType;
        UINT m_uTextShape;
        UINT m_uLineSpacing;
        UINT m_uCharSpacing;
        UINT m_uAlign;
    };
}
#endif // _TEXTARTPR_H_
