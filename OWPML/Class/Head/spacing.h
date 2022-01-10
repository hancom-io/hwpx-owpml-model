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
#ifndef  _SPACING_H_
#define  _SPACING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CSpacing Declaration 
    class CSpacing : public CExtObject
    {
    private:
        CSpacing();
    public:
        virtual ~CSpacing();
        static CSpacing* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetHangul(void) { return m_nHangul; }
        void SetHangul(INT hangul) { m_nHangul = hangul; }

        INT GetLatin(void) { return m_nLatin; }
        void SetLatin(INT latin) { m_nLatin = latin; }

        INT GetHanja(void) { return m_nHanja; }
        void SetHanja(INT hanja) { m_nHanja = hanja; }

        INT GetJapanese(void) { return m_nJapanese; }
        void SetJapanese(INT japanese) { m_nJapanese = japanese; }

        INT GetOther(void) { return m_nOther; }
        void SetOther(INT other) { m_nOther = other; }

        INT GetSymbol(void) { return m_nSymbol; }
        void SetSymbol(INT symbol) { m_nSymbol = symbol; }

        INT GetUser(void) { return m_nUser; }
        void SetUser(INT user) { m_nUser = user; }


    private:
        INT m_nHangul;
        INT m_nLatin;
        INT m_nHanja;
        INT m_nJapanese;
        INT m_nOther;
        INT m_nSymbol;
        INT m_nUser;
    };
}
#endif // _SPACING_H_
