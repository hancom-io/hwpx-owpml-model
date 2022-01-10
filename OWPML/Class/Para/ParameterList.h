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
#ifndef  _PARAMETERLIST_H_
#define  _PARAMETERLIST_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CBooleanParam;
    class CIntegerParam;
    class CFloatParam;
    class CStringParam;
    class CParameterList;


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CParam : public CExtObject
    {
    protected:
        CParam(unsigned int id);
    public:
        virtual ~CParam();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual bool ReadNodeValue(LPCWSTR const value, const unsigned int length);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        void                    Setval(LPCWSTR val) { m_val = val; }
        LPCWSTR                 Getval() const { return m_val.c_str(); }

    protected:
        hncstd::wstring m_strName;
        hncstd::wstring m_val;
    };


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CBooleanParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CBooleanParam : public CParam
    {
    private:
        CBooleanParam();
    public:
        virtual ~CBooleanParam();
        static CBooleanParam* Create();

        CBooleanParam* Clone();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CIntegerParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CIntegerParam : public CParam
    {
    private:
        CIntegerParam(unsigned int id);
    public:
        virtual ~CIntegerParam();
        static CIntegerParam* Create();
        static CIntegerParam* CreateArg(unsigned int id);

        CIntegerParam* Clone();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CFloatParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CFloatParam : public CParam
    {
    private:
        CFloatParam();
    public:
        virtual ~CFloatParam();
        static CFloatParam* Create();

        CFloatParam* Clone();
    };

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CStringParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CStringParam : public CParam
    {
    private:
        CStringParam();
    public:
        virtual ~CStringParam();
        static CStringParam* Create();

        CStringParam* Clone();
    };


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CParameterList Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CParameterList : public CParam
    {
    private:
        CParameterList(unsigned int id = ID_PARA_ParameterList);
    public:
        virtual ~CParameterList();
        static CParameterList* Create();
        static CParameterList* CreateArg(unsigned int id = ID_PARA_ParameterList);

        CParameterList* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CBooleanParam* SetbooleanParam(CBooleanParam* booleanParam = NULL);
        CBooleanParam* GetbooleanParam(int index = 0);

        CIntegerParam* SetintegerParam(CIntegerParam* integerParam = NULL);
        CIntegerParam* GetintegerParam(int index = 0);

        CFloatParam* SetfloatParam(CFloatParam* floatParam = NULL);
        CFloatParam* GetfloatParam(int index = 0);

        CStringParam* SetstringParam(CStringParam* stringParam = NULL);
        CStringParam* GetstringParam(int index = 0);

        CParameterList* SetlistParam(CParameterList* listParam = NULL);
        CParameterList* GetlistParam(int index = 0);

        CParam* GetParamItem(LPCWSTR name, unsigned int id = 0);

        // Attribute Set/Get Fucntion
        UINT GetCnt(void) { return m_uCnt; }
        void SetCnt(UINT cnt) { m_uCnt = cnt; }

    private:
        UINT m_uCnt;
    };
}
#endif // _PARAMETERLIST_H_
