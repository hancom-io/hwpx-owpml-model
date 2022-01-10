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
#ifndef  _BULLETTYPE_H_
#define  _BULLETTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CImageType;
    class CParaHeadType;

    // CBulletType Declaration 
    class CBulletType : public CExtObject
    {
    private:
        CBulletType();
    public:
        virtual ~CBulletType();
        static CBulletType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CImageType* Setimg(CImageType* img = NULL);
        CImageType* Getimg(int index = 0);

        CParaHeadType* SetparaHead(CParaHeadType* paraHead = NULL);
        CParaHeadType* GetparaHead(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        LPCWSTR GetChar(void) { return m_strChar.c_str(); }
        void SetChar(LPCWSTR szchar) { m_strChar = szchar; }

        LPCWSTR GetCheckedChar(void) { return m_strCheckedChar.c_str(); }
        void SetCheckedChar(LPCWSTR szchar) { m_strCheckedChar = szchar; }

        BOOL GetUseImage(void) { return m_bUseImage == true ? TRUE : FALSE; }
        void SetUseImage(BOOL useImage) { m_bUseImage = (useImage == TRUE ? true : false); }


    private:
        UINT m_uId;
        hncstd::wstring m_strChar;
        hncstd::wstring m_strCheckedChar;
        bool m_bUseImage;
    };
}
#endif // _BULLETTYPE_H_
