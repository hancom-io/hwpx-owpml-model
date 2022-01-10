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
#ifndef  _METADATATYPE_H_
#define  _METADATATYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CMetadataType Declaration 
    class CMetadataType : public CExtObject
    {
    private:
        CMetadataType();
    public:
        virtual ~CMetadataType();
        static CMetadataType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CTitle* Settitle(CTitle* title = NULL);
        CTitle* Gettitle(int index = 0);

        CLanguage* Setlanguage(CLanguage* language = NULL);
        CLanguage* Getlanguage(int index = 0);

        CIdentifier* Setidentifier(CIdentifier* identifier = NULL);
        CIdentifier* Getidentifier(int index = 0);

        CMeta* Setmeta(CMeta* meta = NULL);
        CMeta* Getmeta(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }


    private:
        hncstd::wstring m_strId;
    };
}
#endif // _METADATATYPE_H_
