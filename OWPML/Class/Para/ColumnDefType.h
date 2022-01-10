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
#ifndef  _COLUMNDEFTYPE_H_
#define  _COLUMNDEFTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CColumnDefType Declaration 
    class CColumnDefType : public CExtObject
    {
    private:
        CColumnDefType();
    public:
        virtual ~CColumnDefType();
        static CColumnDefType* Create();

        CColumnDefType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CColLine* SetcolLine(CColLine* colLine = NULL);
        CColLine* GetcolLine(int index = 0);

        CColSz* SetcolSz(CColSz* colSz = NULL);
        CColSz* GetcolSz(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        COLDEFTYPE GetType(void) { return (COLDEFTYPE)m_uType; }
        void SetType(COLDEFTYPE type) { m_uType = (UINT)type; }

        COLDEFLAYOUT GetLayout(void) { return (COLDEFLAYOUT)m_uLayout; }
        void SetLayout(COLDEFLAYOUT layout) { m_uLayout = (UINT)layout; }

        UINT GetColCount(void) { return m_nColCount; }
        void SetColCount(UINT colCount) { m_nColCount = colCount; }

        BOOL GetSameSz(void) { return m_bSameSz == true ? TRUE : FALSE; }
        void SetSameSz(BOOL sameSz) { m_bSameSz = (sameSz == TRUE ? true : false); }

        UINT GetSameGap(void) { return m_uSameGap; }
        void SetSameGap(UINT sameGap) { m_uSameGap = sameGap; }


    private:
        hncstd::wstring m_strId;
        UINT m_uType;
        UINT m_uLayout;
        UINT m_nColCount;
        bool m_bSameSz;
        UINT m_uSameGap;
    };
}
#endif // _COLUMNDEFTYPE_H_
