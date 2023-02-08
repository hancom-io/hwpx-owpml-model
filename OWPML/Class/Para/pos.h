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
#ifndef  _POS_H_
#define  _POS_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CRFPos Declaration 
    class CRFPos : public CExtObject
    {
    private:
        CRFPos();
    public:
        virtual ~CRFPos();
        static CRFPos* Create();

        CRFPos* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        FLOAT GetStart(void) { return m_fStart; }
        void SetStart(FLOAT start) { m_fStart = start; }

        FLOAT GetEnd(void) { return m_fEnd; }
        void SetEnd(FLOAT end) { m_fEnd = end; }


    private:
        FLOAT m_fStart;
        FLOAT m_fEnd;
    };

    // CASOPos Declaration 
    class CASOPos : public CExtObject
    {
    private:
        CASOPos();
    public:
        virtual ~CASOPos();
        static CASOPos* Create();

        CASOPos* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        BOOL GetTreatAsChar(void) { return m_bTreatAsChar == true ? TRUE : FALSE; }
        void SetTreatAsChar(BOOL treatAsChar) { m_bTreatAsChar = (treatAsChar == TRUE ? true : false); }

        BOOL GetAffectLSpacing(void) { return m_bAffectLSpacing == true ? TRUE : FALSE; }
        void SetAffectLSpacing(BOOL affectLSpacing) { m_bAffectLSpacing = (affectLSpacing == TRUE ? true : false); }

        BOOL GetFlowWithText(void) { return m_bFlowWithText == true ? TRUE : FALSE; }
        void SetFlowWithText(BOOL flowWithText) { m_bFlowWithText = (flowWithText == TRUE ? true : false); }

        BOOL GetAllowOverlap(void) { return m_bAllowOverlap == true ? TRUE : FALSE; }
        void SetAllowOverlap(BOOL allowOverlap) { m_bAllowOverlap = (allowOverlap == TRUE ? true : false); }

        BOOL GetHoldAnchorAndSO(void) { return m_bHoldAnchorAndSO == true ? TRUE : FALSE; }
        void SetHoldAnchorAndSO(BOOL holdAnchorAndSO) { m_bHoldAnchorAndSO = (holdAnchorAndSO == TRUE ? true : false); }

        VERTRELTOTYPE GetVertRelTo(void) { return (VERTRELTOTYPE)m_uVertRelTo; }
        void SetVertRelTo(VERTRELTOTYPE vertRelTo) { m_uVertRelTo = (UINT)vertRelTo; }

        HORZRELTOTYPE GetHorzRelTo(void) { return (HORZRELTOTYPE)m_uHorzRelTo; }
        void SetHorzRelTo(HORZRELTOTYPE horzRelTo) { m_uHorzRelTo = (UINT)horzRelTo; }

        VERTALIGNTYPE GetVertAlign(void) { return (VERTALIGNTYPE)m_uVertAlign; }
        void SetVertAlign(VERTALIGNTYPE vertAlign) { m_uVertAlign = (UINT)vertAlign; }

        HORZALIGNTYPE GetHorzAlign(void) { return (HORZALIGNTYPE)m_uHorzAlign; }
        void SetHorzAlign(HORZALIGNTYPE horzAlign) { m_uHorzAlign = (UINT)horzAlign; }

        UINT GetVertOffset(void) { return m_uVertOffset; }
        void SetVertOffset(UINT vertOffset) { m_uVertOffset = vertOffset; }

        UINT GetHorzOffset(void) { return m_uHorzOffset; }
        void SetHorzOffset(UINT horzOffset) { m_uHorzOffset = horzOffset; }


    private:
        bool m_bTreatAsChar;
        bool m_bAffectLSpacing;
        bool m_bFlowWithText;
        bool m_bAllowOverlap;
        bool m_bHoldAnchorAndSO;
        UINT m_uVertRelTo;
        UINT m_uHorzRelTo;
        UINT m_uVertAlign;
        UINT m_uHorzAlign;
        UINT m_uVertOffset;
        UINT m_uHorzOffset;
    };
}
#endif // _POS_H_
