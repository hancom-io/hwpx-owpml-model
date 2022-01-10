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
#ifndef  _PTYPE_H_
#define  _PTYPE_H_

namespace OWPML {

    class CRunType;

    class CLineSeg : public CExtObject
    {
    private:
        CLineSeg();
    public:
        virtual ~CLineSeg();
        static CLineSeg* Create();

        CLineSeg* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        // Attribute Set/Get Fucntion
        UINT GetTextPos(void) { return m_TextPos; }
        void SetTextPos(UINT pos) { m_TextPos = pos; }

        INT GetVertPos(void) { return m_VertPos; }
        void SetVertPos(INT pos) { m_VertPos = pos; }

        INT GetVertSize(void) { return m_VertSize; }
        void SetVertSize(INT size) { m_VertSize = size; }

        INT GetTextHeight(void) { return m_TextHeight; }
        void SetTextHeight(INT height) { m_TextHeight = height; }

        INT GetBaseLine(void) { return m_BaseLine; }
        void SetBaseLine(INT baseline) { m_BaseLine = baseline; }

        INT GetSpacing(void) { return m_Spacing; }
        void SetSpacing(INT spacing) { m_Spacing = spacing; }

        INT GetHorzPos(void) { return m_HorzPos; }
        void SetHorzPos(INT pos) { m_HorzPos = pos; }

        INT GetHorzSize(void) { return m_HorzSize; }
        void SetHorzSize(INT size) { m_HorzSize = size; }

        UINT GetFlags(void) { return m_Flags; }
        void SetFlags(UINT flags) { m_Flags = flags; }

    private:
        UINT m_TextPos = 0;
        INT m_VertPos = 0;
        INT m_VertSize = 0;
        INT m_TextHeight = 0;
        INT m_BaseLine = 0;
        INT m_Spacing = 0;
        INT m_HorzPos = 0;
        INT m_HorzSize = 0;
        UINT m_Flags = 0;
    };

    class CLineSegArray : public CExtObject
    {
    private:
        CLineSegArray();
    public:
        virtual ~CLineSegArray();
        static CLineSegArray* Create();

        CLineSegArray* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);


    public:
        // Element Set Fucntion
        CLineSeg* SetLineSeg(CLineSeg* plineseg = NULL);
        CLineSeg* GetLineSeg(int index = 0);
    };


    // CPType Declaration 
    class CPType : public CExtObject
    {
    private:
        CPType();
    public:
        virtual ~CPType();
        static CPType* Create();

        CPType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CRunType* Setrun(CRunType* run = NULL);
        CRunType* Getrun(int index = 0);

        CLineSegArray* Setlinesegarray(CLineSegArray* psegarray = NULL);
        CLineSegArray* Getlinesegarray(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        UINT GetParaPrIDRef(void) { return m_uParaPrIDRef; }
        void SetParaPrIDRef(UINT paraPrIDRef) { m_uParaPrIDRef = paraPrIDRef; }

        UINT GetStyleIDRef(void) { return m_uStyleIDRef; }
        void SetStyleIDRef(UINT styleIDRef) { m_uStyleIDRef = styleIDRef; }

        BOOL GetPageBreak(void) { return m_bPageBreak == true ? TRUE : FALSE; }
        void SetPageBreak(BOOL pageBreak) { m_bPageBreak = (pageBreak == TRUE ? true : false); }

        BOOL GetColumnBreak(void) { return m_bColumnBreak == true ? TRUE : FALSE; }
        void SetColumnBreak(BOOL columnBreak) { m_bColumnBreak = (columnBreak == TRUE ? true : false); }

        BOOL GetMerged(void) { return m_bMerged == true ? TRUE : FALSE; }
        void SetMerged(BOOL merged) { m_bMerged = (merged == TRUE ? true : false); }

        UINT GetTrackchageID(void) { return m_paraTCId; }
        void SetTrackchageID(UINT tcid) { m_paraTCId = tcid; }

    private:
        UINT m_uId;
        UINT m_uParaPrIDRef;
        UINT m_uStyleIDRef;
        bool m_bPageBreak;
        bool m_bColumnBreak;
        bool m_bMerged;
        UINT m_paraTCId;
    };
}
#endif // _PTYPE_H_
