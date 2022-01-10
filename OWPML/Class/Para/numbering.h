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
#ifndef  _NUMBERING_H_
#define  _NUMBERING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CNumbering Declaration 
    class CFNNumbering : public CExtObject
    {
    private:
        CFNNumbering();
    public:
        virtual ~CFNNumbering();
        static CFNNumbering* Create();

        CFNNumbering* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        FNNUMBERINGTYPE GetType(void) { return (FNNUMBERINGTYPE)m_uType; }
        void SetType(FNNUMBERINGTYPE type) { m_uType = (UINT)type; }

        UINT GetNewNum(void) { return m_uNewNum; }
        void SetNewNum(UINT newNum) { m_uNewNum = newNum; }


    private:
        UINT m_uType;
        UINT m_uNewNum;
    };

    // CENNumbering Declaration 
    class CENNumbering : public CExtObject
    {
    private:
        CENNumbering();
    public:
        virtual ~CENNumbering();
        static CENNumbering* Create();

        CENNumbering* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        ENNUMBERINGTYPE GetType(void) { return (ENNUMBERINGTYPE)m_uType; }
        void SetType(ENNUMBERINGTYPE type) { m_uType = (UINT)type; }

        UINT GetNewNum(void) { return m_uNewNum; }
        void SetNewNum(UINT newNum) { m_uNewNum = newNum; }


    private:
        UINT m_uType;
        UINT m_uNewNum;
    };
}
#endif // _NUMBERING_H_
