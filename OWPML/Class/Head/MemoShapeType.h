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
#ifndef  _MEMOSHAPETYPE_H_
#define  _MEMOSHAPETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CMemoShapeType Declaration 
    class CMemoShapeType : public CExtObject
    {
    private:
        CMemoShapeType();
    public:
        virtual ~CMemoShapeType();
        static CMemoShapeType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        UINT GetWidth(void) { return m_uWidth; }
        void SetWidth(UINT width) { m_uWidth = width; }

        UINT GetLineWidth(void) { return m_uLineWidth; }
        void SetLineWidth(UINT width) { m_uLineWidth = width; }

        LINETYPE2 GetLineType(void) { return (LINETYPE2)m_uLineType; }
        void SetLineType(LINETYPE2 lineType) { m_uLineType = (UINT)lineType; }

        COLORREF GetLineColor(void) { return m_cLineColor; }
        void SetLineColor(COLORREF lineColor) { m_cLineColor = lineColor; }

        COLORREF GetFillColor(void) { return m_cFillColor; }
        void SetFillColor(COLORREF fillColor) { m_cFillColor = fillColor; }

        COLORREF GetActiveColor(void) { return m_cActiveColor; }
        void SetActiveColor(COLORREF activeColor) { m_cActiveColor = activeColor; }

        MEMOSHAPETYPE GetMemoType(void) { return (MEMOSHAPETYPE)m_uMemoType; }
        void SetMemoType(MEMOSHAPETYPE memoType) { m_uMemoType = (UINT)memoType; }


    private:
        UINT m_uId;
        UINT m_uWidth;
        UINT m_uLineWidth;
        UINT m_uLineType;
        CColorRef m_cLineColor;
        CColorRef m_cFillColor;
        CColorRef m_cActiveColor;
        UINT m_uMemoType;
    };
}
#endif // _MEMOSHAPETYPE_H_
