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
#ifndef  _FIELDBEGIN_H_
#define  _FIELDBEGIN_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CParameterList;
    class CParaListType;

    // CFieldBegin Declaration 
    class CFieldBegin : public CExtObject
    {
    private:
        CFieldBegin();
    public:
        virtual ~CFieldBegin();
        static CFieldBegin* Create();

        CFieldBegin* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CParameterList* Setparameters(CParameterList* parameters = NULL);
        CParameterList* Getparameters(int index = 0);

        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        FIELDTYPE GetType(void) { return (FIELDTYPE)m_uType; }
        void SetType(FIELDTYPE type) { m_uType = (UINT)type; }

        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        BOOL GetEditable(void) { return m_bEditable == true ? TRUE : FALSE; }
        void SetEditable(BOOL editable) { m_bEditable = (editable == TRUE ? true : false); }

        BOOL GetDirty(void) { return m_bDirty == true ? TRUE : FALSE; }
        void SetDirty(BOOL dirty) { m_bDirty = (dirty == TRUE ? true : false); }

        INT GetZorder(void) { return m_nZorder; }
        void SetZorder(INT zorder) { m_nZorder = zorder; }

        UINT32 GetFieldId(void) { return m_uFieldid; }
        void SetFieldId(UINT32 uFieldid) { m_uFieldid = uFieldid; }

    private:
        UINT m_uId = 0;
        UINT m_uType;
        hncstd::wstring m_strName;
        bool m_bEditable;
        bool m_bDirty;
        INT m_nZorder;
        UINT32 m_uFieldid = 0;
    };
}
#endif // _FIELDBEGIN_H_
