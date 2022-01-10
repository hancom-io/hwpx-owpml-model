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
#ifndef  _TYPEINFO_H_
#define  _TYPEINFO_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CTypeInfo Declaration 
    class CTypeInfo : public CExtObject
    {
    private:
        CTypeInfo();
    public:
        virtual ~CTypeInfo();
        static CTypeInfo* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        FAMILYTYPE GetFamilyType(void) { return (FAMILYTYPE)m_uFamilyType; }
        void SetFamilyType(FAMILYTYPE familyType) { m_uFamilyType = (UINT)familyType; }

        LPCWSTR GetSerifStyle(void) { return m_strSerifStyle.c_str(); }
        void SetSerifStyle(LPCWSTR serifStyle) { m_strSerifStyle = serifStyle; }

        INT GetWeight(void) { return m_nWeight; }
        void SetWeight(INT weight) { m_nWeight = weight; }

        INT GetProportion(void) { return m_nProportion; }
        void SetProportion(INT proportion) { m_nProportion = proportion; }

        INT GetContrast(void) { return m_nContrast; }
        void SetContrast(INT contrast) { m_nContrast = contrast; }

        INT GetStrokeVariation(void) { return m_nStrokeVariation; }
        void SetStrokeVariation(INT strokeVariation) { m_nStrokeVariation = strokeVariation; }

        INT GetArmStyle(void) { return m_nArmStyle; }
        void SetArmStyle(INT armStyle) { m_nArmStyle = armStyle; }

        INT GetLetterform(void) { return m_nLetterform; }
        void SetLetterform(INT letterform) { m_nLetterform = letterform; }

        INT GetMidline(void) { return m_nMidline; }
        void SetMidline(INT midline) { m_nMidline = midline; }

        INT GetXHeight(void) { return m_nXHeight; }
        void SetXHeight(INT xHeight) { m_nXHeight = xHeight; }


    private:
        UINT m_uFamilyType = 0;
        hncstd::wstring m_strSerifStyle;
        INT m_nWeight;
        INT m_nProportion;
        INT m_nContrast;
        INT m_nStrokeVariation;
        INT m_nArmStyle;
        INT m_nLetterform = 0;
        INT m_nMidline = 0;
        INT m_nXHeight;
    };
}
#endif // _TYPEINFO_H_
