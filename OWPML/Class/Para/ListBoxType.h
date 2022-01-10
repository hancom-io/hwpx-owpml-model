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
#ifndef  _LISTBOXTYPE_H_
#define  _LISTBOXTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CListBoxType Declaration 
    class CListBoxType : public CAbstractFormObjectType
    {
    private:
        CListBoxType();
    public:
        virtual ~CListBoxType();
        static CListBoxType* Create();

        CListBoxType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CListItemType* SetlistItem(CListItemType* listItem = NULL);
        CListItemType* GetlistItem(int index = 0);

        // Attribute Set/Get Fucntion
        INT GetItemHeight(void) { return m_nItemHeight; }
        void SetItemHeight(INT itemHeight) { m_nItemHeight = itemHeight; }

        UINT GetTopIdx(void) { return m_uTopIdx; }
        void SetTopIdx(UINT topIdx) { m_uTopIdx = topIdx; }

        LPCWSTR GetSelectedValue(void) { return m_strSelectedValue.c_str(); }
        void SetSelectedValue(LPCWSTR selectedValue) { m_strSelectedValue = selectedValue; }


    private:
        INT m_nItemHeight;
        UINT m_uTopIdx;
        hncstd::wstring m_strSelectedValue;
    };
}
#endif // _LISTBOXTYPE_H_
