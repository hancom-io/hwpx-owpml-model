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
#ifndef _PART_NAMESPACE_INFO_H_
#define _PART_NAMESPACE_INFO_H_

namespace OWPML {

#define EPUB_SWITCH_ELMENT                L"epub:switch"
#define EPUB_CASE_ELMENT                  L"epub:case"
#define EPUB_DEFAULT_ELMENT               L"epub:default"

#define PARA_SWITCH_ELMENT                L"hp:switch"
#define PARA_CASE_ELMENT                  L"hp:case"
#define PARA_DEFAULT_ELMENT               L"hp:default"


    class CPartNameSpaceInfo
    {
    public:
        static CPartNameSpaceInfo* GetMgr();
        ~CPartNameSpaceInfo();

    private:
        CPartNameSpaceInfo();

    protected:
        void _InitStaticTableNamespace();

    protected:
        class _foCompare
        {
        public:
            bool operator() (LPCWSTR val1, LPCWSTR val2) const
            {
                return (_ustrcmp(val1, val2) < 0) ? true : false;
            }
        };

        //typedef std::map<LPCWSTR /* namespace */, LPCWSTR /* prefix */ , _foCompare>                        NSMap;
        typedef std::map<hncstd::wstring /* namespace */, hncstd::wstring /* prefix */>                                NSMap;
        typedef std::deque<std::pair<hncstd::wstring /* currentdoc prefix */, LPCWSTR /* standard prefix */> >    NSTable;
        typedef std::deque<std::pair<hncstd::wstring /* prefix */, LPCWSTR /* uri */> >    NSLocalTable;
    public:
        typedef std::map<hncstd::wstring /* element name */, CREATEFUNCSET /*pfunc*/>        AppCreateFunc;
        typedef std::map<hncstd::wstring /* namespace */, hncstd::wstring /* prefix */>                AppNSMap; // application에서 지원하는 Name space


    public:
        LPCWSTR FindStandardPrefix(LPCWSTR strPrefix, bool* bEqual = NULL);
        LPCWSTR FindStandardPrefixFromNamespace(LPCWSTR strNamespace);
        LPCWSTR FindNameSpaceFromStandardPrefix(LPCWSTR strPrefix);
        void PushNameSpace(LPCWSTR strPrefix, LPCWSTR strNamespace);
        void PopNameSpace(LPCWSTR strPrefix);

        BOOL IsAppNameSpace(LPCWSTR strNamespace);
        LPCWSTR FindAppPrefix(LPCWSTR strNamespace);
        LPCWSTR FindLocalNameSpace(LPCWSTR strPrefix);
        LPCWSTR FindLocalPrefix(LPCWSTR strNamespace);

        CObject* CreateAppObject(LPCWSTR strElename, BOOL& bMarkupCP);

        BOOL SetApplicationNs(LPCWSTR strNamespace, LPCWSTR strPrefix);
        BOOL DelectApplicationNs(LPCWSTR strNamespace);
        AppNSMap* GetApplicationNsTable(void) { return &m_tableApplicationNS; }

        BOOL SetApplicationFucnion(LPCWSTR strElename, CREATEFUNCTION fucntion, unsigned int id);

    private:
        NSTable         m_tableCurrent;
        NSMap           m_tableStatic;
        AppNSMap        m_tableApplicationNS;
        NSLocalTable    m_tableLocalNs;
        AppCreateFunc   m_tableApplicationFunc;
        hncstd::wstring m_cachedOrgPrefix;
        LPCWSTR         m_cachedStdPrefix;
        bool            m_bCachedEqual;
    };

}
#endif    // _PART_NAMESPACE_INFO_H_
