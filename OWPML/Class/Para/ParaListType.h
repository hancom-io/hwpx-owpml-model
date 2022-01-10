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
#ifndef  _PARALISTTYPE_H_
#define  _PARALISTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CParaListType Declaration 
    class CParaListType : public CExtObject
    {
    private:
        CParaListType();
    public:
        virtual ~CParaListType();
        static CParaListType* Create();

        CParaListType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPType* Setp(CPType* p = NULL);
        CPType* Getp(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        PARATEXTDIRECTTYPE GetTextDirection(void) { return (PARATEXTDIRECTTYPE)m_uTextDirection; }
        void SetTextDirection(PARATEXTDIRECTTYPE textDirection) { m_uTextDirection = (UINT)textDirection; }

        PARALINEWRAPTYPE GetLineWrap(void) { return (PARALINEWRAPTYPE)m_uLineWrap; }
        void SetLineWrap(PARALINEWRAPTYPE lineWrap) { m_uLineWrap = (UINT)lineWrap; }

        PARAVERTALIGNTYPE GetVertAlign(void) { return (PARAVERTALIGNTYPE)m_uVertAlign; }
        void SetVertAlign(PARAVERTALIGNTYPE vertAlign) { m_uVertAlign = (UINT)vertAlign; }

        UINT GetLinkListIDRef(void) { return m_uLinkListIDRef; }
        void SetLinkListIDRef(UINT linkListIDRef) { m_uLinkListIDRef = linkListIDRef; }

        UINT GetLinkListNextIDRef(void) { return m_uLinkListNextIDRef; }
        void SetLinkListNextIDRef(UINT linkListNextIDRef) { m_uLinkListNextIDRef = linkListNextIDRef; }

        UINT GetTextWidth(void) { return m_uTextWidth; }
        void SetTextWidth(UINT textWidth) { m_uTextWidth = textWidth; }

        UINT GetTextHeight(void) { return m_uTextHeight; }
        void SetTextHeight(UINT textHeight) { m_uTextHeight = textHeight; }

        BOOL GetHasTextRef(void) { return m_bHasTextRef == true ? TRUE : FALSE; }
        void SetHasTextRef(BOOL hasTextRef) { m_bHasTextRef = (hasTextRef == TRUE ? true : false); }

        BOOL GetHasNumRef(void) { return m_bHasNumRef == true ? TRUE : FALSE; }
        void SetHasNumRef(BOOL hasNumRef) { m_bHasNumRef = (hasNumRef == TRUE ? true : false); }

        // metatag & json
        LPCWSTR GetMetaTag(void) { return m_stMetaTag.c_str(); }
        void SetMetaTag(LPCWSTR psMetaTag) { if (psMetaTag) m_stMetaTag = psMetaTag; }

    private:
        hncstd::wstring m_strId;
        UINT m_uTextDirection;
        UINT m_uLineWrap;
        UINT m_uVertAlign;
        UINT m_uLinkListIDRef = 0;
        UINT m_uLinkListNextIDRef = 0;
        UINT m_uTextWidth;
        UINT m_uTextHeight;
        bool m_bHasTextRef;
        bool m_bHasNumRef;

        hncstd::wstring m_stMetaTag;
    };
}
#endif // _PARALISTTYPE_H_
