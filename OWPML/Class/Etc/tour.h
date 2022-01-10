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
#ifndef  _TOUR_H_
#define  _TOUR_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CSite;

    // CTour Declaration 
    class CTour : public CExtObject
    {
    private:
        CTour();
    public:
        virtual ~CTour();
        static CTour* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CSite* Setsite(CSite* site = NULL);
        CSite* Getsite(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        LPCWSTR GetTitle(void) { return m_strTitle.c_str(); }
        void SetTitle(LPCWSTR title) { m_strTitle = title; }


    private:
        hncstd::wstring m_strId;
        hncstd::wstring m_strTitle;
    };
}
#endif // _TOUR_H_
