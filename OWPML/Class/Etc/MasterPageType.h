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
#ifndef  _MASTERPAGETYPE_H_
#define  _MASTERPAGETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CParaListType;

    // CMasterPageType Declaration 
    class CMasterPageType : public CNamedObject
    {
    public:
        CMasterPageType();
    public:
        virtual ~CMasterPageType();
        static CMasterPageType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        MASTERPAGETYPE GetType(void) { return (MASTERPAGETYPE)m_uType; }
        void SetType(MASTERPAGETYPE type) { m_uType = (UINT)type; }

        UINT GetPageNumber(void) { return m_uPageNumber; }
        void SetPageNumber(UINT pageNumber) { m_uPageNumber = pageNumber; }

        BOOL GetPageDuplicate(void) { return m_bPageDuplicate == true ? TRUE : FALSE; }
        void SetPageDuplicate(BOOL pageDuplicate) { m_bPageDuplicate = (pageDuplicate == TRUE ? true : false); }

        BOOL GetPageFront(void) { return m_bPageFront == true ? TRUE : FALSE; }
        void SetPageFront(BOOL pageFront) { m_bPageFront = (pageFront == TRUE ? true : false); }


    private:
        hncstd::wstring m_strId;
        UINT m_uType;
        UINT m_uPageNumber;
        bool m_bPageDuplicate;
        bool m_bPageFront;
    };
}
#endif // _MASTERPAGETYPE_H_
