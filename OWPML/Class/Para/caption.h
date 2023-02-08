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
#ifndef  _CAPTION_H_
#define  _CAPTION_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCaption Declaration 
    class CCaption : public CExtObject
    {
    private:
        CCaption();
    public:
        virtual ~CCaption();
        static CCaption* Create();

        CCaption* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        CAPTIONSIDETYPE GetSide(void) { return (CAPTIONSIDETYPE)m_uSide; }
        void SetSide(CAPTIONSIDETYPE side) { m_uSide = (UINT)side; }

        BOOL GetFullSz(void) { return m_bFullSz == true ? TRUE : FALSE; }
        void SetFullSz(BOOL fullSz) { m_bFullSz = (fullSz == TRUE ? true : false); }

        INT GetWidth(void) { return m_nWidth; }
        void SetWidth(INT width) { m_nWidth = width; }

        INT GetGap(void) { return m_nGap; }
        void SetGap(INT gap) { m_nGap = gap; }

        UINT GetLastWidth(void) { return m_uLastWidth; }
        void SetLastWidth(UINT lastWidth) { m_uLastWidth = lastWidth; }


    private:
        UINT m_uSide;
        bool m_bFullSz;
        INT m_nWidth;
        INT m_nGap;
        UINT m_uLastWidth;
    };
}
#endif // _CAPTION_H_
