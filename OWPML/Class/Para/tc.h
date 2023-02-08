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
#ifndef  _TC_H_
#define  _TC_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CTc Declaration 
    class CTc : public CExtObject
    {
    private:
        CTc();
    public:
        virtual ~CTc();
        static CTc* Create();

        CTc* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CCellAddr* SetcellAddr(CCellAddr* cellAddr = NULL);
        CCellAddr* GetcellAddr(int index = 0);

        CCellSpan* SetcellSpan(CCellSpan* cellSpan = NULL);
        CCellSpan* GetcellSpan(int index = 0);

        CCellSz* SetcellSz(CCellSz* cellSz = NULL);
        CCellSz* GetcellSz(int index = 0);

        CCellMargin* SetcellMargin(CCellMargin* cellMargin = NULL);
        CCellMargin* GetcellMargin(int index = 0);

        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        BOOL GetHeader(void) { return m_bHeader == true ? TRUE : FALSE; }
        void SetHeader(BOOL header) { m_bHeader = (header == TRUE ? true : false); }

        BOOL GetHasMargin(void) { return m_bHasMargin == true ? TRUE : FALSE; }
        void SetHasMargin(BOOL hasMargin) { m_bHasMargin = (hasMargin == TRUE ? true : false); }

        BOOL GetProtect(void) { return m_bProtect == true ? TRUE : FALSE; }
        void SetProtect(BOOL protect) { m_bProtect = (protect == TRUE ? true : false); }

        BOOL GetEditable(void) { return m_bEditable == true ? TRUE : FALSE; }
        void SetEditable(BOOL editable) { m_bEditable = (editable == TRUE ? true : false); }

        BOOL GetDirty(void) { return m_bDirty == true ? TRUE : FALSE; }
        void SetDirty(BOOL dirty) { m_bDirty = (dirty == TRUE ? true : false); }

        UINT GetBorderFillIDRef(void) { return (UINT)m_uBorderFillIDRef; }
        void SetBorderFillIDRef(UINT borderFillIDRef) { m_uBorderFillIDRef = (UINT16)borderFillIDRef; }

    private:
        hncstd::wstring m_strName;
        bool m_bHeader;
        bool m_bHasMargin;
        bool m_bProtect;
        bool m_bEditable;
        bool m_bDirty;
        UINT16 m_uBorderFillIDRef = 0;
    };
}
#endif // _TC_H_
