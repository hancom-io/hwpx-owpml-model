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
#ifndef  _CHARSHAPETYPE_H_
#define  _CHARSHAPETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CFontRef;
    class CRatio;
    class CSpacing;
    class CRelSz;
    class COffset;
    class CItalic;
    class CBold;
    class CUnderline;
    class CStrikeout;
    class COutline;
    class CCharShadow;
    class CEmboss;
    class CEngrave;
    class CSupscript;
    class CSubscript;

    // CCharShapeType Declaration 
    class CCharShapeType : public CExtObject
    {
    private:
        CCharShapeType();
    public:
        virtual ~CCharShapeType();
        static CCharShapeType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CFontRef* SetfontRef(CFontRef* fontRef = NULL);
        CFontRef* GetfontRef(int index = 0);

        CRatio* Setratio(CRatio* ratio = NULL);
        CRatio* Getratio(int index = 0);

        CSpacing* Setspacing(CSpacing* spacing = NULL);
        CSpacing* Getspacing(int index = 0);

        CRelSz* SetrelSz(CRelSz* relSz = NULL);
        CRelSz* GetrelSz(int index = 0);

        COffset* Setoffset(COffset* offset = NULL);
        COffset* Getoffset(int index = 0);

        CItalic* Setitalic(CItalic* italic = NULL);
        CItalic* Getitalic(int index = 0);

        CBold* Setbold(CBold* bold = NULL);
        CBold* Getbold(int index = 0);

        CUnderline* Setunderline(CUnderline* underline = NULL);
        CUnderline* Getunderline(int index = 0);

        CStrikeout* Setstrikeout(CStrikeout* strikeout = NULL);
        CStrikeout* Getstrikeout(int index = 0);

        COutline* Setoutline(COutline* outline = NULL);
        COutline* Getoutline(int index = 0);

        CCharShadow* Setshadow(CCharShadow* shadow = NULL);
        CCharShadow* Getshadow(int index = 0);

        CEmboss* Setemboss(CEmboss* emboss = NULL);
        CEmboss* Getemboss(int index = 0);

        CEngrave* Setengrave(CEngrave* engrave = NULL);
        CEngrave* Getengrave(int index = 0);

        CSupscript* Setsupscript(CSupscript* supscript = NULL);
        CSupscript* Getsupscript(int index = 0);

        CSubscript* Setsubscript(CSubscript* subscript = NULL);
        CSubscript* Getsubscript(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        INT GetHeight(void) { return m_nHeight; }
        void SetHeight(INT height) { m_nHeight = height; }

        COLORREF GetTextColor(void) { return m_cTextColor; }
        void SetTextColor(COLORREF textColor) { m_cTextColor = textColor; }

        COLORREF GetShadeColor(void) { return m_cShadeColor; }
        void SetShadeColor(COLORREF shadeColor) { m_cShadeColor = shadeColor; }

        BOOL GetUseFontSpace(void) { return m_bUseFontSpace == true ? TRUE : FALSE; }
        void SetUseFontSpace(BOOL useFontSpace) { m_bUseFontSpace = (useFontSpace == TRUE ? true : false); }

        BOOL GetUseKerning(void) { return m_bUseKerning == true ? TRUE : FALSE; }
        void SetUseKerning(BOOL useKerning) { m_bUseKerning = (useKerning == TRUE ? true : false); }

        SYMBOLMARKTYPE GetSymMark(void) { return (SYMBOLMARKTYPE)m_uSymMark; }
        void SetSymMark(SYMBOLMARKTYPE symMark) { m_uSymMark = (UINT)symMark; }

        UINT GetBorderFillIDRef(void) { return m_uBorderFillIDRef; }
        void SetBorderFillIDRef(UINT borderFillIDRef) { m_uBorderFillIDRef = borderFillIDRef; }


    private:
        UINT m_uId;
        INT m_nHeight;
        CColorRef m_cTextColor;
        CColorRef m_cShadeColor;
        bool m_bUseFontSpace;
        bool m_bUseKerning;
        UINT m_uSymMark;
        UINT m_uBorderFillIDRef;
    };
}
#endif // _CHARSHAPETYPE_H_
