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

#include "stdafx.h"
#include "Object.h"
#include "NamespacePrefix.h"
#include "PartNameSpaceInfo.h"

namespace OWPML {
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // function object
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct _FindSdPrefix : public std::binary_function<std::pair<hncstd::wstring, LPCWSTR>, LPCWSTR, bool>
    {
        bool operator () (std::pair<hncstd::wstring, LPCWSTR> const& value, LPCWSTR prefix) const
        {
            if (value.first.compare(prefix) == 0)
                return true;
            return false;
        }
    };

    struct _FindNsFromSdPrefix : public std::binary_function<std::pair<hncstd::wstring, hncstd::wstring>, LPCWSTR, bool>
    {
        bool operator () (std::pair<hncstd::wstring, hncstd::wstring> const& value, LPCWSTR prefix) const
        {
            if (_ustrcmp(value.second.c_str(), prefix) == 0)
                return true;
            return false;
        }
    };

    struct _FindLocalPrefix : public std::binary_function<std::pair<hncstd::wstring, LPCWSTR>, LPCWSTR, bool>
    {
        bool operator () (std::pair<hncstd::wstring, LPCWSTR> const& value, LPCWSTR prefix) const
        {
            if (value.first.compare(prefix) == 0)
                return true;
            return false;
        }
    };

    struct _FindLocalNamespace : public std::binary_function<std::pair<hncstd::wstring, LPCWSTR>, LPCWSTR, bool>
    {
        bool operator () (std::pair<hncstd::wstring, LPCWSTR> const& value, LPCWSTR localnamespace) const
        {
            if (_ustrcmp(value.second, localnamespace) == 0)
                return true;
            return false;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CPartNameSpaceInfo
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CPartNameSpaceInfo* CPartNameSpaceInfo::GetMgr()
    {
        static CPartNameSpaceInfo mgr;
        return &mgr;
    }

    CPartNameSpaceInfo::~CPartNameSpaceInfo()
    {
    }

    CPartNameSpaceInfo::CPartNameSpaceInfo()
        : m_cachedOrgPrefix(L""), m_cachedStdPrefix(NULL), m_bCachedEqual(false)
    {
        _InitStaticTableNamespace();
    }

    void CPartNameSpaceInfo::_InitStaticTableNamespace()
    {
        unsigned int tmp_lp = 0;
        _PAIR_NAMESPACE_PREFIX* pCurPair = GetStaticNamespacePrefix(tmp_lp);// &(s_pairtable_NamespacePrefix[tmp_lp/* =0 */]);
        while (pCurPair->prefixStr) {
            m_tableStatic.insert(std::pair<hncstd::wstring, hncstd::wstring>(pCurPair->nameSpace, pCurPair->prefixStr));
            pCurPair = GetStaticNamespacePrefix(++tmp_lp);//&(s_pairtable_NamespacePrefix[++tmp_lp]);
        }
    }

    LPCWSTR CPartNameSpaceInfo::FindStandardPrefixFromNamespace(LPCWSTR strNamespace)
    {
        NSMap::iterator iter = m_tableStatic.find(strNamespace);
        if (iter != m_tableStatic.end())
            return iter->second.c_str();

        return NULL;
    }

    LPCWSTR CPartNameSpaceInfo::FindNameSpaceFromStandardPrefix(LPCWSTR strPrefix)
    {
        if (strPrefix == NULL)
            return NULL;

        NSMap::iterator iter;

        iter = std::find_if(m_tableStatic.begin(), m_tableStatic.end(), std::bind2nd<_FindNsFromSdPrefix>(_FindNsFromSdPrefix(), strPrefix));
        if (iter != m_tableStatic.end()) {
            return iter->first.c_str();
        }

        return NULL;
    }

    LPCWSTR CPartNameSpaceInfo::FindStandardPrefix(LPCWSTR strPrefix, bool* bEqual/*= NULL*/)
    {
        if (!strPrefix)
            strPrefix = str_DEFAULT_NAMESPACE_PREFIX;

        if (m_tableCurrent.empty())
            return NULL;

        if (!m_cachedOrgPrefix.compare(strPrefix)) {
            if (bEqual)
                *bEqual = m_bCachedEqual;
            return m_cachedStdPrefix;
        } else {
            // 뒤에서부터 찾는다.
            NSTable::const_reverse_iterator rvIter;
            rvIter = std::find_if(m_tableCurrent.rbegin(), m_tableCurrent.rend(), std::bind2nd<_FindSdPrefix>(_FindSdPrefix(), strPrefix));
            if (rvIter != m_tableCurrent.rend()) {
                m_cachedOrgPrefix = strPrefix;
                m_bCachedEqual = ((*rvIter).second) ? false : true;
                if (bEqual)
                    *bEqual = m_bCachedEqual;
                m_cachedStdPrefix = m_bCachedEqual ? strPrefix : ((*rvIter).second);

                return m_cachedStdPrefix;
            }
        }

        return NULL;
    }

    void CPartNameSpaceInfo::PushNameSpace(LPCWSTR strPrefix, LPCWSTR strNamespace)
    {
        NSMap::iterator iter = m_tableStatic.find(strNamespace);
        if (iter != m_tableStatic.end()) {
            if ((!strPrefix) || (strPrefix[0] == NULL))
                strPrefix = str_DEFAULT_NAMESPACE_PREFIX;

            LPCWSTR standardPrefix = NULL;
            if (_ustricmp(strPrefix, iter->second.c_str()))
                standardPrefix = iter->second.c_str();
            m_tableCurrent.push_back(std::pair<hncstd::wstring, LPCWSTR>(strPrefix, standardPrefix));
            m_cachedOrgPrefix.clear();
            m_bCachedEqual = false;
        } else {
            m_tableLocalNs.push_back(std::pair<hncstd::wstring, LPCWSTR>(strPrefix, strNamespace));
        }
    }

    void CPartNameSpaceInfo::PopNameSpace(LPCWSTR strPrefix)
    {
        if ((!strPrefix) || (strPrefix[0] == NULL))
            strPrefix = str_DEFAULT_NAMESPACE_PREFIX;

        if (!m_tableCurrent.empty()) {
            if (_ustrcmp((*(m_tableCurrent.end() - 1)).first.c_str(), strPrefix) == 0) {
                m_tableCurrent.pop_back();
                m_cachedOrgPrefix.assign(L"");
                m_bCachedEqual = false;
            }
        }

        if (!m_tableLocalNs.empty()) {
            if (_ustrcmp((*(m_tableLocalNs.end() - 1)).first.c_str(), strPrefix) == 0) {
                m_tableLocalNs.pop_back();
            }
        }

#ifdef SD_PRINT_ASSERT
        // Push & Pop 함수 호출 짝이 맞지 않음..
        _ASSERT(FALSE);
#endif
        return;
    }

    BOOL CPartNameSpaceInfo::IsAppNameSpace(LPCWSTR strNamespace)
    {
        AppNSMap::iterator iter;

        iter = m_tableApplicationNS.find(strNamespace);
        if (iter == m_tableApplicationNS.end())
            return FALSE;

        return TRUE;
    }

    LPCWSTR CPartNameSpaceInfo::FindAppPrefix(LPCWSTR strNamespace)
    {
        AppNSMap::iterator iter;

        iter = m_tableApplicationNS.find(strNamespace);
        if (iter != m_tableApplicationNS.end())
            return iter->second.c_str();

        return NULL;
    }

    LPCWSTR CPartNameSpaceInfo::FindLocalNameSpace(LPCWSTR strPrefix)
    {
        // 뒤에서부터 찾는다.
        NSLocalTable::const_reverse_iterator rvIter;
        rvIter = std::find_if(m_tableLocalNs.rbegin(), m_tableLocalNs.rend(), std::bind2nd<_FindLocalPrefix>(_FindLocalPrefix(), strPrefix));
        if (rvIter != m_tableLocalNs.rend()) {
            return ((*rvIter).second);
        }

        return NULL;
    }

    LPCWSTR CPartNameSpaceInfo::FindLocalPrefix(LPCWSTR strNamespace)
    {
        // 뒤에서부터 찾는다.
        NSLocalTable::const_reverse_iterator rvIter;
        rvIter = std::find_if(m_tableLocalNs.rbegin(), m_tableLocalNs.rend(), std::bind2nd<_FindLocalNamespace>(_FindLocalNamespace(), strNamespace));
        if (rvIter != m_tableLocalNs.rend()) {
            return ((*rvIter).first.c_str());
        }

        return NULL;
    }

    CObject* CPartNameSpaceInfo::CreateAppObject(LPCWSTR strElename, BOOL& bMarkupCP)
    {
        AppCreateFunc::iterator iter;

        iter = m_tableApplicationFunc.find(strElename);
        if (iter != m_tableApplicationFunc.end()) {
            return (*iter->second.pfucnion)();
        }

        // 호환 관련 class인지 확인한다.
        if ((_ustrcmp(strElename, EPUB_SWITCH_ELMENT) == 0) || \
            (_ustrcmp(strElename, EPUB_CASE_ELMENT) == 0) || \
            (_ustrcmp(strElename, EPUB_DEFAULT_ELMENT) == 0)) {
            bMarkupCP = TRUE;
        } else {
            bMarkupCP = FALSE;
        }

        return NULL;
    }

    BOOL CPartNameSpaceInfo::SetApplicationNs(LPCWSTR strNamespace, LPCWSTR strPrefix)
    {
        AppNSMap::iterator iter;

        // 같은 Napespace가 존재하는지 검사
        iter = m_tableApplicationNS.find(strNamespace);
        if (iter != m_tableApplicationNS.end()) {
            return FALSE;
        }

        iter = std::find_if(m_tableApplicationNS.begin(), m_tableApplicationNS.end(), std::bind2nd<_FindNsFromSdPrefix>(_FindNsFromSdPrefix(), strPrefix));
        if (iter != m_tableApplicationNS.end()) {
            return FALSE;
        }

        m_tableApplicationNS[strNamespace] = strPrefix;
        return TRUE;
    }

    BOOL CPartNameSpaceInfo::DelectApplicationNs(LPCWSTR strNamespace)
    {
        AppNSMap::iterator iter;

        // 같은 Napespace가 존재하는지 검사
        iter = m_tableApplicationNS.find(strNamespace);
        if (iter == m_tableApplicationNS.end()) {
            return FALSE;
        }

        m_tableApplicationNS.erase(strNamespace);
        return TRUE;
    }

    BOOL CPartNameSpaceInfo::SetApplicationFucnion(LPCWSTR strElename, CREATEFUNCTION fucntion, unsigned int id)
    {
        AppCreateFunc::iterator iter;
        iter = m_tableApplicationFunc.find(strElename);

        if (iter != m_tableApplicationFunc.end()) {
            _ASSERTE(FALSE); // 같은 function이 존재한다
            return FALSE;
        }

        CREATEFUNCSET stFucntionset;
        stFucntionset.pfucnion = fucntion;
        stFucntionset.id = id;

        m_tableApplicationFunc[strElename] = stFucntionset;
        return TRUE;
    }

}