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
#ifndef  _IMAGETYPE_H_
#define  _IMAGETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CImageType Declaration 
    class CImageType : public CExtObject
    {
    private:
        CImageType();
    public:
        virtual ~CImageType();
        static CImageType* Create();

        CImageType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetBinaryItemIDRef(void) { return m_strBinaryItemIDRef.c_str(); }
        void SetBinaryItemIDRef(LPCWSTR binaryItemIDRef) { m_strBinaryItemIDRef = binaryItemIDRef; }

        INT GetBright(void) { return m_nBright; }
        void SetBright(INT bright) { m_nBright = bright; }

        INT GetContrast(void) { return m_nContrast; }
        void SetContrast(INT contrast) { m_nContrast = contrast; }

        IMAGEEFFECTTYPE GetEffect(void) { return (IMAGEEFFECTTYPE)m_uEffect; }
        void SetEffect(IMAGEEFFECTTYPE effect) { m_uEffect = (UINT)effect; }

        FLOAT GetAlpha(void) { return m_fAlpha; }
        void SetAlpha(FLOAT alpha) { m_fAlpha = alpha; }


    private:
        hncstd::wstring m_strBinaryItemIDRef;
        INT m_nBright;
        INT m_nContrast;
        UINT m_uEffect;
        FLOAT m_fAlpha;
    };
}
#endif // _IMAGETYPE_H_
