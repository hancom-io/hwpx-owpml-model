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
#ifndef  _PARAHEADTYPE_H_
#define  _PARAHEADTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CParaHeadType Declaration 
    class CParaHeadType : public CStringValueObject
    {
    public:
        CParaHeadType(UINT id);
    public:
        virtual ~CParaHeadType();
        static CParaHeadType* Create();
        static CParaHeadType* CreateArg(UINT id = ID_HEAD_ParaHeadType);

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool WriteAttribute(CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetLevel(void) { return m_nLevel; }
        void SetLevel(INT level) { m_nLevel = level; }

        PHALIGNTYPE GetAlign(void) { return (PHALIGNTYPE)m_uAlign; }
        void SetAlign(PHALIGNTYPE align) { m_uAlign = (UINT)align; }

        BOOL GetUseInstWidth(void) { return m_bUseInstWidth == true ? TRUE : FALSE; }
        void SetUseInstWidth(BOOL useInstWidth) { m_bUseInstWidth = (useInstWidth == TRUE ? true : false); }

        BOOL GetAutoIndent(void) { return m_bAutoIndent == true ? TRUE : FALSE; }
        void SetAutoIndent(BOOL autoIndent) { m_bAutoIndent = (autoIndent == TRUE ? true : false); }

        INT GetWidthAdjust(void) { return m_nWidthAdjust; }
        void SetWidthAdjust(INT widthAdjust) { m_nWidthAdjust = widthAdjust; }

        TEXTOFFSETTYPE GetTextOffsetType(void) { return (TEXTOFFSETTYPE)m_uTextOffsetType; }
        void SetTextOffsetType(TEXTOFFSETTYPE textOffsetType) { m_uTextOffsetType = (UINT)textOffsetType; }

        INT GetTextOffset(void) { return m_nTextOffset; }
        void SetTextOffset(INT textOffset) { m_nTextOffset = textOffset; }

        NUMBERTYPE GetNumFormat(void) { return (NUMBERTYPE)m_uNumFormat; }
        void SetNumFormat(NUMBERTYPE numFormat) { m_uNumFormat = (UINT)numFormat; }

        UINT GetCharPrIDRef(void) { return m_uCharPrIDRef; }
        void SetCharPrIDRef(UINT charPrIDRef) { m_uCharPrIDRef = charPrIDRef; }

        BOOL GetCheckable(void) { return m_bCheckable == true ? TRUE : FALSE; }
        void SetCheckable(BOOL checkable) { m_bCheckable = (checkable == TRUE ? true : false); }


    private:
        INT m_nLevel;
        UINT m_uAlign;
        bool m_bUseInstWidth;
        bool m_bAutoIndent;
        INT m_nWidthAdjust;
        UINT m_uTextOffsetType;
        INT m_nTextOffset;
        UINT m_uNumFormat;
        UINT m_uCharPrIDRef;
        bool m_bCheckable;
    };

    class CParaHeadType2 : public CParaHeadType
    {
    private:
        CParaHeadType2();
    public:
        virtual ~CParaHeadType2();
        static CParaHeadType2* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        UINT GetStartNumber(void) { return m_StartNumber; }
        void SetStartNumber(UINT startnum) { m_StartNumber = startnum; }

    private:
        UINT m_StartNumber;
    };
}
#endif // _PARAHEADTYPE_H_
