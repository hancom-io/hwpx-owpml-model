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
#ifndef  _DIFFENTRYTYPE_H_
#define  _DIFFENTRYTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CInsertType;
    class CUpdateType;
    class CDeleteType;
    class CPositionType;

    // CDiffEntryType Declaration 
    class CDiffEntryType : public CExtObject
    {
    private:
        CDiffEntryType(UINT id);
    public:
        virtual ~CDiffEntryType();
        static CDiffEntryType* Create();
        static CDiffEntryType* CreateArg(UINT id);

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Function
        CInsertType* Setinsert(CInsertType* insert = NULL);
        CInsertType* Getinsert(int index = 0);

        CUpdateType* Setupdate(CUpdateType* update = NULL);
        CUpdateType* Getupdate(int index = 0);

        CDeleteType* Setdelete(CDeleteType* _delete = NULL);
        CDeleteType* Getdelete(int index = 0);

        CPositionType* Setposition(CPositionType* position = NULL);
        CPositionType* Getposition(int index = 0);

        // Attribute Set/Get Function
        LPCWSTR GetHref(void) { return m_strHref.c_str(); }
        void SetHref(LPCWSTR href) { m_strHref = href; }

    private:
        hncstd::wstring m_strHref;
    };
}
#endif // _DIFFENTRYTYPE_H_
