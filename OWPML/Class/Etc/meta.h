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
#ifndef  _META_H_
#define  _META_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CMeta Declaration 
    class CMeta : public CStringValueObject
    {
    private:
        CMeta();
    public:
        virtual ~CMeta();
        static CMeta* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }


        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        LPCWSTR GetContent(void) { return m_strContent.c_str(); }
        void SetContent(LPCWSTR content) { m_strContent = content; }

        LPCWSTR GetSchme(void) { return m_strSchme.c_str(); }
        void SetSchme(LPCWSTR schme) { m_strSchme = schme; }


    private:
        hncstd::wstring m_strId;
        UINT m_uLang;
        hncstd::wstring m_strName;
        hncstd::wstring m_strContent;
        hncstd::wstring m_strSchme;
    };
}
#endif // _META_H_
