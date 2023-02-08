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
#ifndef  _COMBOBOXTYPE_H_
#define  _COMBOBOXTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CListItemType;

    // CComboBoxType Declaration 
    class CComboBoxType : public CAbstractFormObjectType
    {
    private:
        CComboBoxType();
    public:
        virtual ~CComboBoxType();
        static CComboBoxType* Create();

        CComboBoxType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CListItemType* SetlistItem(CListItemType* listItem = NULL);
        CListItemType* GetlistItem(int index = 0);

        // Attribute Set/Get Fucntion
        INT GetListBoxRows(void) { return m_nListBoxRows; }
        void SetListBoxRows(INT listBoxRows) { m_nListBoxRows = listBoxRows; }

        INT GetListBoxWidth(void) { return m_nListBoxWidth; }
        void SetListBoxWidth(INT listBoxWidth) { m_nListBoxWidth = listBoxWidth; }

        BOOL GetEditEnable(void) { return m_bEditEnable == true ? TRUE : FALSE; }
        void SetEditEnable(BOOL editEnable) { m_bEditEnable = (editEnable == TRUE ? true : false); }

        LPCWSTR GetSelectedValue(void) { return m_strSelectedValue.c_str(); }
        void SetSelectedValue(LPCWSTR selectedValue) { m_strSelectedValue = selectedValue; }


    private:
        INT m_nListBoxRows;
        INT m_nListBoxWidth;
        bool m_bEditEnable;
        hncstd::wstring m_strSelectedValue;
    };
}
#endif // _COMBOBOXTYPE_H_
