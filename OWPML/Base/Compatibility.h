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
#ifndef  _ALTERNATE_CONTENT_H_
#define  _ALTERNATE_CONTENT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;



    class CDefault : public CExtObject
    {
    private:
        CDefault();
    public:
        virtual ~CDefault();
        static CDefault* Create();

    public: // read, write function 
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        virtual LPCWSTR FindObjectName(CObject* pChildObj);
    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion

    private:
    };


    // CCase Declaration 
    //
    class CCase : public CExtObject
    {
    private:
        CCase();
    public:
        virtual ~CCase();
        static CCase* Create();

    public: // read, write function 
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        virtual LPCWSTR FindObjectName(CObject* pChildObj);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        void SetRequires(LPCWSTR value) { m_strRequires = value; }
        LPCWSTR GetRequires(void) { if (m_strRequires.empty()) return NULL; return m_strRequires.c_str(); }

    private:
        hncstd::wstring m_strRequires;
    };

    // CSwitch Declaration 
    // 
    class CSwitch : public CNamedObject
    {
    private:
        CSwitch();
    public:
        virtual ~CSwitch();
        static CSwitch* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CCase* SetCase();
        CDefault* SetDefault();

        // Attribute Set/Get Fucntion

    private:
    };




    // CEpubDefault Declaration 
    //
    class CEpubDefault : public CExtObject
    {
    private:
        CEpubDefault();
    public:
        virtual ~CEpubDefault();
        static CEpubDefault* Create();

    public: // read, write function 
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        virtual LPCWSTR FindObjectName(CObject* pChildObj);
    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion

    private:
    };


    // CEpubCase Declaration 
    //
    class CEpubCase : public CExtObject
    {
    private:
        CEpubCase();
    public:
        virtual ~CEpubCase();
        static CEpubCase* Create();

    public: // read, write function 
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        virtual LPCWSTR FindObjectName(CObject* pChildObj);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        void SetRequires(LPCWSTR value) { m_strRequires = value; }
        LPCWSTR GetRequires(void) { if (m_strRequires.empty()) return NULL; return m_strRequires.c_str(); }

    private:
        hncstd::wstring m_strRequires;
    };

    // CEpubSwitch Declaration 
    // 
    class CEpubSwitch : public CNamedObject
    {
    private:
        CEpubSwitch();
    public:
        virtual ~CEpubSwitch();
        static CEpubSwitch* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CEpubCase* SetCase();
        CEpubDefault* SetDefault();

        // Attribute Set/Get Fucntion

    private:
    };

}
#endif // _ALTERNATE_CONTENT_H_
