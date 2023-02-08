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
#ifndef  _LINESHAPETYPE_H_
#define  _LINESHAPETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CLineShapeType Declaration 
    class CLineShapeType : public CExtObject
    {
    private:
        CLineShapeType();
    public:
        virtual ~CLineShapeType();
        static CLineShapeType* Create();

        CLineShapeType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        COLORREF GetColor(void) { return m_cColor; }
        void SetColor(COLORREF color) { m_cColor = color; }

        UINT GetWidth(void) { return m_uWidth; }
        void SetWidth(UINT width) { m_uWidth = width; }

        LINETYPE2 GetStyle(void) { return (LINETYPE2)m_uStyle; }
        void SetStyle(LINETYPE2 style) { m_uStyle = (UINT)style; }

        LINEENDCAPTYPE GetEndCap(void) { return (LINEENDCAPTYPE)m_uEndCap; }
        void SetEndCap(LINEENDCAPTYPE endCap) { m_uEndCap = (UINT)endCap; }

        ARROWTYPE GetHeadStyle(void) { return (ARROWTYPE)m_uHeadStyle; }
        void SetHeadStyle(ARROWTYPE headStyle) { m_uHeadStyle = (UINT)headStyle; }

        ARROWTYPE GetTailStyle(void) { return (ARROWTYPE)m_uTailStyle; }
        void SetTailStyle(ARROWTYPE tailStyle) { m_uTailStyle = (UINT)tailStyle; }

        ARROWSIZE GetHeadSz(void) { return (ARROWSIZE)m_uHeadSz; }
        void SetHeadSz(ARROWSIZE headSz) { m_uHeadSz = (UINT)headSz; }

        BOOL GetHeadFill(void) { return m_bHeadFill == true ? TRUE : FALSE; }
        void SetHeadFill(BOOL bfill) { m_bHeadFill = (bfill == TRUE ? true : false); }

        BOOL GetTailFill(void) { return m_bTailFill == true ? TRUE : FALSE; }
        void SetTailFill(BOOL bfill) { m_bTailFill = (bfill == TRUE ? true : false); }

        ARROWSIZE GetTailSz(void) { return (ARROWSIZE)m_uTailSz; }
        void SetTailSz(ARROWSIZE tailSz) { m_uTailSz = (UINT)tailSz; }

        OUTLINESTYLE GetOutlineStyle(void) { return (OUTLINESTYLE)m_uOutlineStyle; }
        void SetOutlineStyle(OUTLINESTYLE outlineStyle) { m_uOutlineStyle = (UINT)outlineStyle; }

        FLOAT GetAlpha(void) { return m_fAlpha; }
        void SetAlpha(FLOAT alpha) { m_fAlpha = alpha; }


    private:
        CColorRef m_cColor;
        UINT m_uWidth;
        UINT m_uStyle;
        UINT m_uEndCap;
        UINT m_uHeadStyle;
        UINT m_uTailStyle;
        UINT m_uHeadSz;
        UINT m_uTailSz;
        bool m_bHeadFill;
        bool m_bTailFill;
        UINT m_uOutlineStyle;
        FLOAT m_fAlpha;
    };
}
#endif // _LINESHAPETYPE_H_
