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
#ifndef  _CONTAINER_H_
#define  _CONTAINER_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CRootFile Declaration 
    class CRootFile : public CExtObject
    {
    public:
        CRootFile();
    public:
        virtual ~CRootFile();
        static CRootFile* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetFullpath(void) { return m_strFullpath.c_str(); }
        void SetFullpath(LPCWSTR path) { m_strFullpath = path; }

        LPCWSTR GetMediatype(void) { return m_strMediatype.c_str(); }
        void SetMediatype(LPCWSTR type) { m_strMediatype = type; }

    private:
        hncstd::wstring m_strFullpath;
        hncstd::wstring m_strMediatype;
    };

    // CRootFiles Declaration 
    class CRootFiles : public CExtObject
    {
    public:
        CRootFiles();
    public:
        virtual ~CRootFiles();
        static CRootFiles* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CRootFile* Setrootfile(CRootFile* rootfile = NULL);
        CRootFile* Getrootfile(int index = 0);

        // Attribute Set/Get Fucntion
    };

    // CContainer Declaration 
    class CContainer : public CNamedObject
    {
    public:
        CContainer();
    public:
        virtual ~CContainer();
        static CContainer* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CRootFiles* Setrootfiles(CRootFiles* prootfiles = NULL);
        CRootFiles* Getrootfiles(int index = 0);

        // Attribute Set/Get Fucntion
    };

}
#endif // _CONTAINER_H_
