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
#ifndef  _TRACKCHANGE_H_
#define  _TRACKCHANGE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;


    // CTrackChangeAuthor Declaration 
    class CTrackChangeAuthor : public CExtObject
    {
    private:
        CTrackChangeAuthor();
    public:
        virtual ~CTrackChangeAuthor();
        static CTrackChangeAuthor* Create();

    public: // read, write function 
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        BOOL GetMark(void) { return m_bMark == true ? TRUE : FALSE; }
        void SetMark(BOOL mark) { m_bMark = (mark == TRUE ? true : false); }

        COLORREF GetColor(void) { return m_cColor; }
        void SetColor(COLORREF& color) { m_cColor = color; }

        UINT GetID(void) { return m_Id; }
        void SetID(UINT id) { m_Id = id; }

    private:
        hncstd::wstring m_strName;
        bool m_bMark;
        COLORREF m_cColor;
        UINT    m_Id;
    };


    // CTrackChange Declaration 
    class CTrackChange : public CExtObject
    {
    private:
        CTrackChange();
    public:
        virtual ~CTrackChange();
        static CTrackChange* Create();

    public: // read, write function 
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        TRACKCHANGETYPE GetType(void) { return m_uType; }
        void SetType(TRACKCHANGETYPE type) { m_uType = type; }

        SYSTEMTIME& GetDate(void) { return m_stDate; }
        void SetDate(SYSTEMTIME& time) { m_stDate = time; }

        UINT GetAuthorID(void) { return m_uAuthorID; }
        void SetAuthorID(UINT id) { m_uAuthorID = id; }

        BOOL GetHide(void) { return m_bHide == true ? TRUE : FALSE; }
        void SetHide(BOOL hide) { m_bHide = (hide == TRUE ? true : false); }

        UINT GetCharShapeID(void) { return m_uiCharShapeID; }
        void SetCharShapeID(UINT charshapeID) { m_uiCharShapeID = charshapeID; }

        UINT GetParaShapeID(void) { return m_uiParaShapeID; }
        void SetParaShapeID(UINT parashapeID) { m_uiParaShapeID = parashapeID; }

        UINT GetID(void) { return m_Id; }
        void SetID(UINT id) { m_Id = id; }

    private:
        TRACKCHANGETYPE m_uType;
        SYSTEMTIME m_stDate;
        UINT m_uAuthorID;
        union {
            UINT m_uiCharShapeID;
            UINT m_uiParaShapeID;
        };
        bool m_bHide;
        UINT    m_Id;
    };

    // CTrackChangeAuthors Declaration 
    class CTrackChangeAuthors : public CExtObject
    {
    private:
        CTrackChangeAuthors();
    public:
        virtual ~CTrackChangeAuthors();
        static CTrackChangeAuthors* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CTrackChangeAuthor* SettrackChangeAuthor(CTrackChangeAuthor* ptrackchangeauthor = NULL);
        CTrackChangeAuthor* GettrackChangeAuthor(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetItemCnt(void) { return m_uItemCnt; }
        void SetItemCnt(UINT itemCnt) { m_uItemCnt = itemCnt; }

    private:
        UINT m_uItemCnt;
    };

    // CTrackChanges Declaration 
    class CTrackChanges : public CExtObject
    {
    private:
        CTrackChanges();
    public:
        virtual ~CTrackChanges();
        static CTrackChanges* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CTrackChange* SettrackChange(CTrackChange* ptrackchange = NULL);
        CTrackChange* GettrackChange(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetItemCnt(void) { return m_uItemCnt; }
        void SetItemCnt(UINT itemCnt) { m_uItemCnt = itemCnt; }


    private:
        UINT m_uItemCnt;
    };

}
#endif // _TRACKCHANGE_H_
