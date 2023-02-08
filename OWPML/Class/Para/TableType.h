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
#ifndef  _TABLETYPE_H_
#define  _TABLETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CInsideMarginType;
    class CCellzoneList;
    class CTr;
    class CLabel;

    // CTableType Declaration 
    class CTableType : public CAbstractShapeObjectType
    {
    private:
        CTableType();
    public:
        virtual ~CTableType();
        static CTableType* Create();

        CTableType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CInsideMarginType* SetinMargin(CInsideMarginType* inMargin = NULL);
        CInsideMarginType* GetinMargin(int index = 0);

        CCellzoneList* SetcellzoneList(CCellzoneList* cellzoneList = NULL);
        CCellzoneList* GetcellzoneList(int index = 0);

        CTr* Settr(CTr* tr = NULL);
        CTr* Gettr(int index = 0);

        CLabel* Setlabel(CLabel* plabel = NULL);
        CLabel* Getlabel(int index = 0);

        // Attribute Set/Get Fucntion
        TABLEPAGEBREAKTYPE GetPageBreak(void) { return (TABLEPAGEBREAKTYPE)m_uPageBreak; }
        void SetPageBreak(TABLEPAGEBREAKTYPE pageBreak) { m_uPageBreak = (UINT)pageBreak; }

        BOOL GetRepeatHeader(void) { return m_bRepeatHeader == true ? TRUE : FALSE; }
        void SetRepeatHeader(BOOL repeatHeader) { m_bRepeatHeader = (repeatHeader == TRUE ? true : false); }

        BOOL GetNoAdjust(void) { return m_bNoAdjust == true ? TRUE : FALSE; }
        void SetNoAdjust(BOOL noAdjust) { m_bNoAdjust = (noAdjust == TRUE ? true : false); }

        UINT GetRowCnt(void) { return m_uRowCnt; }
        void SetRowCnt(UINT rowCnt) { m_uRowCnt = rowCnt; }

        UINT GetColCnt(void) { return m_uColCnt; }
        void SetColCnt(UINT colCnt) { m_uColCnt = colCnt; }

        UINT GetCellSpacing(void) { return m_uCellSpacing; }
        void SetCellSpacing(UINT cellSpacing) { m_uCellSpacing = cellSpacing; }

        UINT GetBorderFillIDRef(void) { return m_uBorderFillIDRef; }
        void SetBorderFillIDRef(UINT borderFillIDRef) { m_uBorderFillIDRef = borderFillIDRef; }

    private:
        UINT m_uPageBreak = 0;
        bool m_bRepeatHeader;

        bool m_bNoAdjust;

        UINT m_uRowCnt;
        UINT m_uColCnt;
        UINT m_uCellSpacing = 0;
        UINT m_uBorderFillIDRef = 0;
    };
}
#endif // _TABLETYPE_H_
