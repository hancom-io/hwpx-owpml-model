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
#ifndef  _ITEM_H_
#define  _ITEM_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CItem Declaration 
    class CItem : public CExtObject
    {
    private:
        CItem();
    public:
        virtual ~CItem();
        static CItem* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        LPCWSTR GetHref(void) { return m_strHref.c_str(); }
        void SetHref(LPCWSTR href) { m_strHref = href; }

        LPCWSTR GetMediatype(void) { return m_strMediatype.c_str(); }
        void SetMediatype(LPCWSTR mediatype) { m_strMediatype = mediatype; }

        BOOL GetEmbeded(void) { return m_bEmbeded == true ? TRUE : FALSE; }
        void SetEmbeded(BOOL embeded) { m_bEmbeded = (embeded == TRUE ? true : false); m_useEmbeded = TRUE; }

    private:
        hncstd::wstring m_strId;
        hncstd::wstring m_strHref;
        hncstd::wstring m_strMediatype;
        bool m_bEmbeded;
        BOOL m_useEmbeded;
    };
}
#endif // _ITEM_H_
