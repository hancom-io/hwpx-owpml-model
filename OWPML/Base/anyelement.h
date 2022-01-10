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
#ifndef  _ANYELEMENT_H_
#define  _ANYELEMENT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CStringAnyElement Declaration 
    // 하위의 모든 element 를 하나의 string으로 처리
    // element 이름은 없고, string만 존재 
    // (예 "<ds>dss<child>ddkkk</child></ds>" 하위 모든 element를 string으로 처리)
    //  보통 wring 할때 사용
    // 
    class CStringAnyElement : public CExtObject
    {
    private:
        CStringAnyElement();
    public:
        virtual ~CStringAnyElement();
        static CStringAnyElement* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        void ToStringStartElement(LPCWSTR pCurObjName, CAttribute* att, hncstd::wstring& xmlnamespace);
        bool ReadNodeValue(LPCWSTR const value, const unsigned int length);
        void ToStringEndElement(LPCWSTR pCurObjName);

    public:
        // Element Set Fucntion    
        // Attribute Set/Get Fucntion
        LPCWSTR GetValue(void) { return m_anyelementvalue.c_str(); }
        void SetValue(LPCWSTR value) { m_anyelementvalue = value; }

    private:
        hncstd::wstring m_anyelementvalue;
    };


    // CAnyElement Declaration 
    // 임의 element를 처리하기 위한 element
    // element name, attribute, value, 
    // namespace는 attribute로 처리
    // name은 prefix가 붙은 이름으로 처리
    // CAnyElement 는 Child는 CAnyElement 가능
    class CAnyElement : public CExtObject
    {
    private:
        CAnyElement();
    public:
        virtual ~CAnyElement();
        static CAnyElement* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual BOOL HasAnyelement(void) const { return TRUE; }

        void ToStringStartElement(LPCWSTR pCurObjName, CAttribute* att, hncstd::wstring& xmlnamespace);
        bool ReadNodeValue(LPCWSTR const value, const unsigned int length);
        void ToStringEndElement(LPCWSTR pCurObjName);

        CAnyElement* GetChildElement(LPCWSTR pChildObjName, LPCWSTR pAttributeName, LPCWSTR pAttributeValue);

        LPCWSTR Getname(void) { return m_name.c_str(); }
        void Setname(LPCWSTR name) { m_name = name; }

        void SetElemName(LPCWSTR elename) { m_name = elename; }
        LPCWSTR GetElemName() const { return m_name.c_str(); }

        LPCWSTR Getvalue(void) { return m_value.c_str(); }
        void Setvalue(LPCWSTR value) { m_value = value; }

        LPCWSTR Getattribute(LPCWSTR attname);
        void Setattribute(LPCWSTR attname, LPCWSTR attvalue);

        bool GetIgnoreSpace(void) { return m_IgnoreSpace; }
        void SetIgnoreSpace(bool value) { m_IgnoreSpace = value; }

        void ReSetvalue(void);

    public:
        // Element Set Fucntion    
        // Attribute Set/Get Fucntion

    private:
        hncstd::wstring m_name;
        std::map<hncstd::wstring, hncstd::wstring> m_attribute;
        hncstd::wstring m_value;
        bool m_IgnoreSpace = TRUE;
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CRdfAnyElement Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CRdfAnyElement : public CExtObject
    {
    public:
        CRdfAnyElement();
    public:
        virtual ~CRdfAnyElement();
        static CRdfAnyElement* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual CObject* ChildElementCreate(LPCWSTR const qname, const CAttribute* attrs);

    public:
        // Attribute Set/Get Fucntion
        void SetElemName(LPCWSTR elename) { m_name = elename; }
        virtual LPCWSTR GetElemName() const { return m_name.c_str(); }

        LPCWSTR Getnamespace(void) { return m_namespace.c_str(); }
        LPCWSTR Getprefix(void) { return m_prefix.c_str(); }
        void Setnamespace(LPCWSTR prefix, LPCWSTR pnamespace) { m_prefix = prefix; m_namespace = pnamespace; }

        LPCWSTR Getvalue(void) { return m_value.c_str(); }
        void Setvalue(LPCWSTR value) { m_value = value; }

        LPCWSTR GetResource(void) { return m_strResource.c_str(); }
        void SetResource(LPCWSTR resource) { m_strResource = resource; }

    private:
        BOOL m_bvalue;

        hncstd::wstring m_name;

        hncstd::wstring m_prefix;
        hncstd::wstring m_namespace;
        hncstd::wstring m_value;
        hncstd::wstring m_strResource;
    };


}
#endif // _ANYELEMENT_H_
