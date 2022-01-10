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
#ifndef  _DELETETYPE_H_
#define  _DELETETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CDeleteType Declaration 
    class CDeleteType : public CAbstractDiffDataType
    {
    private:
        CDeleteType();
    public:
        virtual ~CDeleteType();
        static CDeleteType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual bool ReadNodeValue(LPCWSTR const value, const unsigned int length);

    public:
        void Setval(LPCWSTR val);
        LPCWSTR Getval(void);

        void SetOPID(LPCWSTR val) { m_strOPID = val; }
        LPCWSTR GetOPID(void) { return m_strOPID.c_str(); }

    private:
        hncstd::wstring m_strOPID;
    };

    // CDeleteType의 자식엘리먼트로 오는 ##any Type을 처리하기 위해 생성한 Class
    // 간단히 처리하기 위해 문자열 Object로 처리한다.
    // CAnyType Declaration
    class CAnyType : public CStringValueObject
    {
    public:
        CAnyType(LPCWSTR val);
        virtual ~CAnyType();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
    };

}
#endif // _DELETETYPE_H_
