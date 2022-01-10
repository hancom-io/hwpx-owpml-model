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
#ifndef  _INSERTTYPE_H_
#define  _INSERTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CInsertType Declaration 
    class CInsertType : public CAbstractDiffDataType
    {
    private:
        CInsertType();
    public:
        virtual ~CInsertType();
        static CInsertType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        CInsertType* Setinsert(CInsertType* insert = NULL);
        CInsertType* Getinsert(int index = 0);

        void SetOPID(LPCWSTR val) { m_strOPID = val; }
        LPCWSTR GetOPID(void) { return m_strOPID.c_str(); }

    private:
        hncstd::wstring m_strOPID;
    };
}
#endif // _INSERTTYPE_H_
