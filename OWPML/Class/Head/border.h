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
#ifndef  _BORDER_H_
#define  _BORDER_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CBorder Declaration 
    class CBorder : public CExtObject
    {
    private:
        CBorder();
    public:
        virtual ~CBorder();
        static CBorder* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetBorderFillIDRef(void) { return m_uBorderFillIDRef; }
        void SetBorderFillIDRef(UINT borderFillIDRef) { m_uBorderFillIDRef = borderFillIDRef; }

        INT GetOffsetLeft(void) { return m_nOffsetLeft; }
        void SetOffsetLeft(INT offsetLeft) { m_nOffsetLeft = offsetLeft; }

        INT GetOffsetRight(void) { return m_nOffsetRight; }
        void SetOffsetRight(INT offsetRight) { m_nOffsetRight = offsetRight; }

        INT GetOffsetTop(void) { return m_nOffsetTop; }
        void SetOffsetTop(INT offsetTop) { m_nOffsetTop = offsetTop; }

        INT GetOffsetBottom(void) { return m_nOffsetBottom; }
        void SetOffsetBottom(INT offsetBottom) { m_nOffsetBottom = offsetBottom; }

        BOOL GetConnect(void) { return m_bConnect == true ? TRUE : FALSE; }
        void SetConnect(BOOL connect) { m_bConnect = (connect == TRUE ? true : false); }

        BOOL GetIgnoreMargin(void) { return m_bIgnoreMargin == true ? TRUE : FALSE; }
        void SetIgnoreMargin(BOOL ignoreMargin) { m_bIgnoreMargin = (ignoreMargin == TRUE ? true : false); }


    private:
        UINT m_uBorderFillIDRef;
        INT m_nOffsetLeft;
        INT m_nOffsetRight;
        INT m_nOffsetTop;
        INT m_nOffsetBottom;
        bool m_bConnect;
        bool m_bIgnoreMargin;
    };
}
#endif // _BORDER_H_
