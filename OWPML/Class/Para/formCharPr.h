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
#ifndef  _FORMCHARPR_H_
#define  _FORMCHARPR_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CFormCharPr Declaration 
    class CFormCharPr : public CExtObject
    {
    private:
        CFormCharPr();
    public:
        virtual ~CFormCharPr();
        static CFormCharPr* Create();

        CFormCharPr* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetCharPrIDRef(void) { return m_uCharPrIDRef; }
        void SetCharPrIDRef(UINT charPrIDRef) { m_uCharPrIDRef = charPrIDRef; }

        BOOL GetFollowContext(void) { return m_bFollowContext == true ? TRUE : FALSE; }
        void SetFollowContext(BOOL followContext) { m_bFollowContext = (followContext == TRUE ? true : false); }

        BOOL GetAutoSz(void) { return m_bAutoSz == true ? TRUE : FALSE; }
        void SetAutoSz(BOOL autoSz) { m_bAutoSz = (autoSz == TRUE ? true : false); }

        BOOL GetWordWrap(void) { return m_bWordWrap == true ? TRUE : FALSE; }
        void SetWordWrap(BOOL wordWrap) { m_bWordWrap = (wordWrap == TRUE ? true : false); }


    private:
        UINT m_uCharPrIDRef = 0;
        bool m_bFollowContext;
        bool m_bAutoSz;
        bool m_bWordWrap;
    };
}
#endif // _FORMCHARPR_H_
