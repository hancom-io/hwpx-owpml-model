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
#ifndef  _PAGEBORDERFILL_H_
#define  _PAGEBORDERFILL_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPageBorderFill Declaration 
    class CPageBorderFill : public CExtObject
    {
    private:
        CPageBorderFill();
    public:
        virtual ~CPageBorderFill();
        static CPageBorderFill* Create();

        CPageBorderFill* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPBFOffset* Setoffset(CPBFOffset* offset = NULL);
        CPBFOffset* Getoffset(int index = 0);

        // Attribute Set/Get Fucntion
        PBFTYPE GetType(void) { return (PBFTYPE)m_uType; }
        void SetType(PBFTYPE type) { m_uType = (UINT)type; }

        UINT GetBorderFillIDRef(void) { return m_uBorderFillIDRef; }
        void SetBorderFillIDRef(UINT borderFillIDRef) { m_uBorderFillIDRef = borderFillIDRef; }

        PBFTEXTBORDERTYPE GetTextBorder(void) { return (PBFTEXTBORDERTYPE)m_uTextBorder; }
        void SetTextBorder(PBFTEXTBORDERTYPE textBorder) { m_uTextBorder = (UINT)textBorder; }

        BOOL GetHeaderInside(void) { return m_bHeaderInside == true ? TRUE : FALSE; }
        void SetHeaderInside(BOOL headerInside) { m_bHeaderInside = (headerInside == TRUE ? true : false); }

        BOOL GetFooterInside(void) { return m_bFooterInside == true ? TRUE : FALSE; }
        void SetFooterInside(BOOL footerInside) { m_bFooterInside = (footerInside == TRUE ? true : false); }

        PBFFILLAREATYPE GetFillArea(void) { return (PBFFILLAREATYPE)m_uFillArea; }
        void SetFillArea(PBFFILLAREATYPE fillArea) { m_uFillArea = (UINT)fillArea; }


    private:
        UINT m_uType = 0;
        UINT m_uBorderFillIDRef;
        UINT m_uTextBorder = 0;
        bool m_bHeaderInside;
        bool m_bFooterInside;
        UINT m_uFillArea = 0;
    };
}
#endif // _PAGEBORDERFILL_H_
