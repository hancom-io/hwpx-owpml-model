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
#ifndef  _PARASHAPETYPE_H_
#define  _PARASHAPETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CParaShapeType Declaration 
    class CParaShapeType : public CExtObject
    {
    private:
        CParaShapeType();
    public:
        virtual ~CParaShapeType();
        static CParaShapeType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CAlign* Setalign(CAlign* align = NULL);
        CAlign* Getalign(int index = 0);

        CHeading* Setheading(CHeading* heading = NULL);
        CHeading* Getheading(int index = 0);

        CBreakSetting* SetbreakSetting(CBreakSetting* breakSetting = NULL);
        CBreakSetting* GetbreakSetting(int index = 0);

        CMargin* Setmargin(CMargin* margin = NULL);
        CMargin* Getmargin(int index = 0);

        CLineSpacing* SetlineSpacing(CLineSpacing* lineSpacing = NULL);
        CLineSpacing* GetlineSpacing(int index = 0);

        CBorder* Setborder(CBorder* border = NULL);
        CBorder* Getborder(int index = 0);

        CAutoSpacing* SetautoSpacing(CAutoSpacing* autoSpacing = NULL);
        CAutoSpacing* GetautoSpacing(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        UINT GetTabPrIDRef(void) { return m_uTabPrIDRef; }
        void SetTabPrIDRef(UINT tabPrIDRef) { m_uTabPrIDRef = tabPrIDRef; }

        UINT GetCondense(void) { return m_uCondense; }
        void SetCondense(UINT condense) { m_uCondense = condense; }

        BOOL GetFontLineHeight(void) { return m_bFontLineHeight == true ? TRUE : FALSE; }
        void SetFontLineHeight(BOOL fontLineHeight) { m_bFontLineHeight = (fontLineHeight == TRUE ? true : false); }

        BOOL GetSnapToGrid(void) { return m_bSnapToGrid == true ? TRUE : FALSE; }
        void SetSnapToGrid(BOOL snapToGrid) { m_bSnapToGrid = (snapToGrid == TRUE ? true : false); }

        BOOL GetSuppressLineNumbers(void) { return m_bSuppressLineNumbers == true ? TRUE : FALSE; }
        void SetSuppressLineNumbers(BOOL suppressLineNumbers) { m_bSuppressLineNumbers = (suppressLineNumbers == TRUE ? true : false); }

        BOOL GetChecked(void) { return m_bChecked == true ? TRUE : FALSE; }
        void SetChecked(BOOL checked) { m_bChecked = (checked == TRUE ? true : false); }

    private:
        UINT m_uId = 0;
        UINT m_uTabPrIDRef;
        UINT m_uCondense;
        bool m_bFontLineHeight;
        bool m_bSnapToGrid;
        bool m_bSuppressLineNumbers;
        bool m_bChecked;
    };
}
#endif // _PARASHAPETYPE_H_
