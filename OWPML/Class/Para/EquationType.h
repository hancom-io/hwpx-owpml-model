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
#ifndef  _EQUATIONTYPE_H_
#define  _EQUATIONTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CScript;

    // CEquationType Declaration 
    class CEquationType : public CAbstractShapeObjectType
    {
    private:
        CEquationType();
    public:
        virtual ~CEquationType();
        static CEquationType* Create();

        CEquationType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CScript* Setscript(CScript* script = NULL);
        CScript* Getscript(int index = 0);

        LPCWSTR GetVersion(void) { return m_strVersion.c_str(); }
        void SetVersion(LPCWSTR version) { m_strVersion = version; }

        UINT GetBaseLine(void) { return m_uBaseLine; }
        void SetBaseLine(UINT baseLine) { m_uBaseLine = baseLine; }

        COLORREF GetTextColor(void) { return m_cTextColor; }
        void SetTextColor(COLORREF textColor) { m_cTextColor = textColor; }

        UINT GetBaseUnit(void) { return m_uBaseUnit; }
        void SetBaseUnit(UINT baseUnit) { m_uBaseUnit = baseUnit; }

        EQUATIONLINETYPE GetLineMode(void) { return (EQUATIONLINETYPE)m_uLineMode; }
        void SetLineMode(EQUATIONLINETYPE lineMode) { m_uLineMode = (UINT)lineMode; }

        LPCWSTR GetFontName(void) { return m_strFontName.c_str(); }
        void SetFontName(LPCWSTR fontName) { m_strFontName = fontName; }

    private:
        hncstd::wstring m_strVersion;
        UINT m_uBaseLine;
        CColorRef m_cTextColor;
        UINT m_uBaseUnit;
        UINT m_uLineMode;
        hncstd::wstring m_strFontName;
    };
}
#endif // _EQUATIONTYPE_H_
