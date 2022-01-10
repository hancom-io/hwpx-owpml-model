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
#ifndef  _REFERENCE_H_
#define  _REFERENCE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CReference Declaration 
    class CReference : public CExtObject
    {
    private:
        CReference();
    public:
        virtual ~CReference();
        static CReference* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        LPCWSTR GetType(void) { return m_strType.c_str(); }
        void SetType(LPCWSTR type) { m_strType = type; }

        LPCWSTR GetTitle(void) { return m_strTitle.c_str(); }
        void SetTitle(LPCWSTR title) { m_strTitle = title; }

        LPCWSTR GetHref(void) { return m_strHref.c_str(); }
        void SetHref(LPCWSTR href) { m_strHref = href; }


    private:
        hncstd::wstring m_strId;
        hncstd::wstring m_strType;
        hncstd::wstring m_strTitle;
        hncstd::wstring m_strHref;
    };
}
#endif // _REFERENCE_H_
