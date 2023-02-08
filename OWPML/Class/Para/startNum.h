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
#ifndef  _STARTNUM_H_
#define  _STARTNUM_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CStartNum Declaration 
    class CStartNum : public CExtObject
    {
    private:
        CStartNum();
    public:
        virtual ~CStartNum();
        static CStartNum* Create();

        CStartNum* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        STARTNUMSTARTONTYPE GetPageStartsOn(void) { return (STARTNUMSTARTONTYPE)m_uPageStartsOn; }
        void SetPageStartsOn(STARTNUMSTARTONTYPE pageStartsOn) { m_uPageStartsOn = (UINT)pageStartsOn; }

        UINT GetPage(void) { return m_uPage; }
        void SetPage(UINT page) { m_uPage = page; }

        UINT GetPic(void) { return m_uPic; }
        void SetPic(UINT pic) { m_uPic = pic; }

        UINT GetTbl(void) { return m_uTbl; }
        void SetTbl(UINT tbl) { m_uTbl = tbl; }

        UINT GetEquation(void) { return m_uEquation; }
        void SetEquation(UINT equation) { m_uEquation = equation; }


    private:
        UINT m_uPageStartsOn;
        UINT m_uPage;
        UINT m_uPic;
        UINT m_uTbl;
        UINT m_uEquation;
    };
}
#endif // _STARTNUM_H_
