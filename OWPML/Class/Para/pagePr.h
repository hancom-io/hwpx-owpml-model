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
#ifndef  _PAGEPR_H_
#define  _PAGEPR_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPagePr Declaration 
    class CPagePr : public CExtObject
    {
    private:
        CPagePr();
    public:
        virtual ~CPagePr();
        static CPagePr* Create();

        CPagePr* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPMargin* Setmargin(CPMargin* margin = NULL);
        CPMargin* Getmargin(int index = 0);

        // Attribute Set/Get Fucntion
        PAGELANDSCAPETYPE GetLandscape(void) { return (PAGELANDSCAPETYPE)m_uLandscape; }
        void SetLandscape(PAGELANDSCAPETYPE landscape) { m_uLandscape = (UINT)landscape; }

        UINT GetWidth(void) { return m_uWidth; }
        void SetWidth(UINT width) { m_uWidth = width; }

        UINT GetHeight(void) { return m_uHeight; }
        void SetHeight(UINT height) { m_uHeight = height; }

        PAGEGUTTERTYPE GetGutterType(void) { return (PAGEGUTTERTYPE)m_uGutterType; }
        void SetGutterType(PAGEGUTTERTYPE gutterType) { m_uGutterType = (UINT)gutterType; }


    private:
        UINT m_uLandscape;
        UINT m_uWidth;
        UINT m_uHeight;
        UINT m_uGutterType;
    };
}
#endif // _PAGEPR_H_
