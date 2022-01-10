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

#ifndef _HANDLER_H_
#define _HANDLER_H_

namespace OWPML {

    class CPartNameSpaceInfo;

    ////////////////////////////////////////////////////////////////////////////////////////////
    // factory 관련 class
    ////////////////////////////////////////////////////////////////////////////////////////////

    class CObjectFactory
    {
    public:
        CObjectFactory(CObject* obj) : m_pObject(obj), m_bCompatibility(FALSE), m_bSelectChild(FALSE) {}
        virtual ~CObjectFactory() {}

    public:
        virtual CObject* CreateObject(LPCWSTR elename, BOOL bAutoSet = TRUE) = 0;
        virtual CObject* GetObject(void) = 0;
        virtual BOOL HasAnyelement(void) = 0;
        virtual BOOL IsCompatibility(void) { return m_bCompatibility; }
        virtual BOOL IsSelectChild(void) { return m_bSelectChild; }
        virtual void SetCompatibility(BOOL balter) { m_bCompatibility = balter; }
        virtual void SetSelectChild(BOOL bselchild) { m_bSelectChild = bselchild; }

    protected:
        CObject* m_pObject;
        BOOL m_bCompatibility;
        BOOL m_bSelectChild;
    };

    class CRootObjFactory : public CObjectFactory
    {
    public:
        CRootObjFactory(CObject* obj);
        ~CRootObjFactory();
    public:
        virtual CObject* CreateObject(LPCWSTR elename, BOOL bAutoSet = TRUE);
        virtual CObject* GetObject(void);
        virtual BOOL HasAnyelement(void) { return FALSE; }
    };

    class CEleObjectFactory : public CObjectFactory
    {
    public:
        CEleObjectFactory(CObject* obj);
        ~CEleObjectFactory();
    public:
        virtual CObject* CreateObject(LPCWSTR elename, BOOL bAutoSet = TRUE);
        virtual CObject* GetObject(void);
        virtual BOOL HasAnyelement(void) { return (m_pObject) ? m_pObject->HasAnyelement() : FALSE; }
    };



    ////////////////////////////////////////////////////////////////////////////////////////////
    // Sax class
    ////////////////////////////////////////////////////////////////////////////////////////////

    static const int s_maxprefix = 128;
    static const int s_maxqname = s_maxprefix * 2;

    class CHandler : public CDefaultHandler
    {
    public:
        CHandler();
        virtual ~CHandler();

    public:
        virtual void startDocument();
        virtual void endDocument();

        virtual void startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, \
            const CAttribute* attrs);
        virtual void endElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname);

        virtual void startPrefixMapping(LPCWSTR const prefix, LPCWSTR const uri);
        virtual void endPrefixMapping(LPCWSTR const prefix);

        virtual void characters(LPCWSTR const chars, const unsigned int length);

        void AddFactory(CObjectFactory* factory) { m_pFactory.push(factory); }

    protected:
        CObjectFactory* AnyElement(CObjectFactory* pfactory, LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs);
        CObjectFactory* CompatibilityElement(CObjectFactory* prefactory, LPCWSTR const localname, const CAttribute* attrs);
        CObjectFactory* NormalElement(CObjectFactory* prefactory, const CAttribute* attrs, int level = -1);

    private:
        BOOL _CaseRequires(LPCWSTR requires);

    private:
        std::stack<CObjectFactory*> m_pFactory;
        CObject* m_curobject;
        int m_elementlevel;

        hncstd::wstring m_namespaceAnyelemnt;

        CPartNameSpaceInfo* m_NSInfo;

        friend class CSectionHandler;
        friend class CHistoryHandler;
    };

}
#endif // _HANDLER_H_
