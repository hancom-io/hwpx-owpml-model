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
#ifndef  _RDF_H_
#define  _RDF_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CType;
    class CDescription;
    class CObjectFactory;
    class CRdfAnyElement;



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfType Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CRdfType : public CExtObject
    {
    public:
        CRdfType();
    public:
        virtual ~CRdfType();
        static CRdfType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Attribute Set/Get Fucntion
        LPCWSTR GetResource(void) { return m_strResource.c_str(); }
        void SetResource(LPCWSTR resource) { m_strResource = resource; }

    private:
        hncstd::wstring m_strResource;
    };


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfDescription Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CRdfDescription : public CExtObject
    {
    public:
        CRdfDescription();
    public:
        virtual ~CRdfDescription();
        static CRdfDescription* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual BOOL HasAnyelement(void) const { return TRUE; }
        virtual CObject* ChildElementCreate(LPCWSTR const qname, const CAttribute* attrs);

    public:
        // Element Set Fucntion
        CRdfType* Settype(CRdfType* type = NULL);
        CRdfType* Gettype(int index = 0);

        CRdfAnyElement* SetAnyelement(CRdfAnyElement* anyele = NULL);
        CRdfAnyElement* GetAnyelement(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetAbout(void) { return m_strAbout.c_str(); }
        void SetAbout(LPCWSTR about) { m_strAbout = about; }

    private:
        hncstd::wstring m_strAbout;
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfType Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CRdf : public CNamedObject
    {
    public:
        CRdf();
    public:
        virtual ~CRdf();
        static CRdf* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CRdfDescription* SetDescription(CRdfDescription* description = NULL);
        CRdfDescription* GetDescription(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _RDF_H_
