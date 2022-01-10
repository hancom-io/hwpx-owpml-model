﻿/*
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
#ifndef  _FONTREF_H_
#define  _FONTREF_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CFontRef Declaration 
    class CFontRef : public CExtObject
    {
    private:
        CFontRef();
    public:
        virtual ~CFontRef();
        static CFontRef* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetHangul(void) { return m_uHangul; }
        void SetHangul(UINT hangul) { m_uHangul = hangul; }

        UINT GetLatin(void) { return m_uLatin; }
        void SetLatin(UINT latin) { m_uLatin = latin; }

        UINT GetHanja(void) { return m_uHanja; }
        void SetHanja(UINT hanja) { m_uHanja = hanja; }

        UINT GetJapanese(void) { return m_uJapanese; }
        void SetJapanese(UINT japanese) { m_uJapanese = japanese; }

        UINT GetOther(void) { return m_uOther; }
        void SetOther(UINT other) { m_uOther = other; }

        UINT GetSymbol(void) { return m_uSymbol; }
        void SetSymbol(UINT symbol) { m_uSymbol = symbol; }

        UINT GetUser(void) { return m_uUser; }
        void SetUser(UINT user) { m_uUser = user; }


    private:
        UINT m_uHangul = 0;
        UINT m_uLatin = 0;
        UINT m_uHanja = 0;
        UINT m_uJapanese = 0;
        UINT m_uOther = 0;
        UINT m_uSymbol = 0;
        UINT m_uUser = 0;
    };
}
#endif // _FONTREF_H_
