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
#ifndef  _LABEL_H_
#define  _LABEL_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CLabel Declaration 
    class CLabel : public CExtObject
    {
    private:
        CLabel();
    public:
        virtual ~CLabel();
        static CLabel* Create();

        CLabel* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        UINT GetTopMargin(void) { return m_topMargin; }
        void SetTopMargin(UINT topMargin) { m_topMargin = topMargin; }

        UINT GetLeftMargin(void) { return m_leftMargin; }
        void SetLeftMargin(UINT leftMargin) { m_leftMargin = leftMargin; }

        UINT GetBoxWidth(void) { return m_boxWidth; }
        void SetBoxWidth(UINT boxWidth) { m_boxWidth = boxWidth; }

        UINT GetBoxLength(void) { return m_boxLength; }
        void SetBoxLength(UINT boxLength) { m_boxLength = boxLength; }

        UINT GetBoxMarginHor(void) { return m_boxMarginHor; }
        void SetBoxMarginHor(UINT boxMarginHor) { m_boxMarginHor = boxMarginHor; }

        UINT GetBoxMarginVer(void) { return m_boxMarginVer; }
        void SetBoxMarginVer(UINT boxMarginVer) { m_boxMarginVer = boxMarginVer; }

        UINT GetLabelCols(void) { return m_labelCols; }
        void SetLabelCols(UINT labelCols) { m_labelCols = labelCols; }

        UINT GetLabelRows(void) { return m_labelRows; }
        void SetLabelRows(UINT labelRows) { m_labelRows = labelRows; }

        PAGELANDSCAPETYPE GetLandscape(void) { return (PAGELANDSCAPETYPE)m_landScape; }
        void SetLandscape(PAGELANDSCAPETYPE landscape) { m_landScape = (UINT)landscape; }

        UINT GetPageWidth(void) { return m_pageWidth; }
        void SetPageWidth(UINT pageWidth) { m_pageWidth = pageWidth; }

        UINT GetPageHeight(void) { return m_pageHeight; }
        void SetPageHeight(UINT pageHeight) { m_pageHeight = pageHeight; }

    private:
        UINT m_topMargin;
        UINT m_leftMargin;
        UINT m_boxWidth;
        UINT m_boxLength;
        UINT m_boxMarginHor;
        UINT m_boxMarginVer;
        UINT m_labelCols;
        UINT m_labelRows;
        UINT m_landScape;
        UINT m_pageWidth;
        UINT m_pageHeight;
    };
}
#endif // _LABEL_H_
