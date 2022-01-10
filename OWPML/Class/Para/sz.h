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
#ifndef  _SZ_H_
#define  _SZ_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CSz Declaration 
    class CSz : public CExtObject
    {
    private:
        CSz();
    public:
        virtual ~CSz();
        static CSz* Create();

        CSz* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetWidth(void) { return m_uWidth; }
        void SetWidth(UINT width) { m_uWidth = width; }

        WIDTHRELTOTYPE GetWidthRelTo(void) { return (WIDTHRELTOTYPE)m_uWidthRelTo; }
        void SetWidthRelTo(WIDTHRELTOTYPE widthRelTo) { m_uWidthRelTo = (UINT)widthRelTo; }

        UINT GetHeight(void) { return m_uHeight; }
        void SetHeight(UINT height) { m_uHeight = height; }

        HEIGHTRELTOTYPE GetHeightRelTo(void) { return (HEIGHTRELTOTYPE)m_uHeightRelTo; }
        void SetHeightRelTo(HEIGHTRELTOTYPE heightRelTo) { m_uHeightRelTo = (UINT)heightRelTo; }

        BOOL GetProtect(void) { return m_bProtect == true ? TRUE : FALSE; }
        void SetProtect(BOOL protect) { m_bProtect = (protect == TRUE ? true : false); }

    private:
        UINT m_uWidth;
        UINT m_uWidthRelTo;
        UINT m_uHeight;
        UINT m_uHeightRelTo;
        bool m_bProtect;
    };
}
#endif // _SZ_H_
