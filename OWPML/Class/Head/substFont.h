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
#ifndef  _SUBSTFONT_H_
#define  _SUBSTFONT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CSubstFont Declaration 
    class CSubstFont : public CExtObject
    {
    private:
        CSubstFont();
    public:
        virtual ~CSubstFont();
        static CSubstFont* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetFace(void) { return m_strFace.c_str(); }
        void SetFace(LPCWSTR face) { m_strFace = face; }

        SUBSFONTTYPE GetType(void) { return (SUBSFONTTYPE)m_uType; }
        void SetType(SUBSFONTTYPE type) { m_uType = (UINT)type; }

        BOOL GetIsEmbedded(void) { return m_bIsEmbedded == true ? TRUE : FALSE; }
        void SetIsEmbedded(BOOL isEmbedded) { m_bIsEmbedded = (isEmbedded == TRUE ? true : false); }

        LPCWSTR GetBinaryItemIDRef(void) { return m_strBinaryItemIDRef.c_str(); }
        void SetBinaryItemIDRef(LPCWSTR binaryItemIDRef) { m_strBinaryItemIDRef = binaryItemIDRef; }


    private:
        hncstd::wstring m_strFace;
        UINT m_uType;
        bool m_bIsEmbedded;
        hncstd::wstring m_strBinaryItemIDRef;
    };
}
#endif // _SUBSTFONT_H_
