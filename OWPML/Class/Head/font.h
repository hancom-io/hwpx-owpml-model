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
#ifndef  _FONT_H_
#define  _FONT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CSubstFont;
    class CTypeInfo;

    // CFont Declaration 
    class CFont : public CExtObject
    {
    private:
        CFont();
    public:
        virtual ~CFont();
        static CFont* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CSubstFont* SetsubstFont(CSubstFont* substFont = NULL);
        CSubstFont* GetsubstFont(int index = 0);

        CTypeInfo* SettypeInfo(CTypeInfo* typeInfo = NULL);
        CTypeInfo* GettypeInfo(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        LPCWSTR GetFace(void) { return m_strFace.c_str(); }
        void SetFace(LPCWSTR face) { m_strFace = face; }

        FONTTYPE GetType(void) { return (FONTTYPE)m_uType; }
        void SetType(FONTTYPE type) { m_uType = (UINT)type; }

        BOOL GetIsEmbedded(void) { return m_bIsEmbedded == true ? TRUE : FALSE; }
        void SetIsEmbedded(BOOL isEmbedded) { m_bIsEmbedded = (isEmbedded == TRUE ? true : false); }

        LPCWSTR GetBinaryItemIDRef(void) { return m_strBinaryItemIDRef.c_str(); }
        void SetBinaryItemIDRef(LPCWSTR binaryItemIDRef) { m_strBinaryItemIDRef = binaryItemIDRef; }


    private:
        UINT m_uId;
        hncstd::wstring m_strFace;
        UINT m_uType;
        bool m_bIsEmbedded;
        hncstd::wstring m_strBinaryItemIDRef;
    };
}
#endif // _FONT_H_
