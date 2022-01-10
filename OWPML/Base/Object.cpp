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

#include "OWPML/Class/Para/MetaTag.h"
#include "Hwp/include/HwpMetatagDef.h"

namespace OWPML {

#pragma warning (disable: 4512)

    struct ObjectDelete
    {
        void operator()(CObject* pObject) {
            delete pObject;
        }
    };

    struct ObjectCopy
    {
        void operator()(CObject* pObject) {
            pObject;
        }
    };

    struct _FindObjectID : public std::binary_function<CObject*, unsigned int, bool>
    {
        bool operator() (CObject* pobject, const unsigned int id) const {
            return (pobject->GetID() == id);
        }
    };

    struct _SetObjectListID
    {
        _SetObjectListID(Objectlist& rOjjectlist, unsigned int uId) : m_uId(uId), m_rOjjectlist(rOjjectlist)
        {
        }

        void operator() (CObject* pobject) {
            if (m_uId == pobject->GetID()) {
                m_rOjjectlist.push_back(pobject);
            }
        }

    private:
        unsigned int m_uId;
        Objectlist& m_rOjjectlist;
    };

    /////////////////////////////////////////////////////////////////////////////////////
    // CObject Implementation
    CObject::CObject(unsigned int id) : m_ID(id), m_pRootpart(NULL), m_ErrorCode(0), m_pParent(NULL)
    {
    }

    CObject::~CObject()
    {
    }

    void CObject::Delete(CObject* pObject)
    {
        delete pObject;
    }

    bool CObject::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* /*att*/)
    {
        return false;
    }

    bool CObject::ReadAttribute(CAttribute* /*att*/)
    {
        InitMap(true);
        return true;
    }

    bool CObject::ReadNodeValue(LPCWSTR const /*value*/, const unsigned int /*length*/)
    {
        // 이곳이 호출된다면, StringValueObject가 아닌데 Value를 읽는 상태임.. 무시.
        return false;
    }

    void CObject::SetReNewRootPart(IPart* part)
    {
        SetRootpart(part);

        Objectlist* objLst = GetObjectList();
        if (objLst) {
            Objectlist::iterator iter = objLst->begin();
            for (; iter != objLst->end(); ++iter) {
                (*iter)->SetReNewRootPart(part);
            }
        }
    }

    //bool CObject::IsMetaTagVaild(jsonUI::HwpJson* pMetaTag)
    //{
    //    if (pMetaTag == nullptr)
    //        return false;
    //    else if (pMetaTag->isMember(METATAGDEF_NAME) == 0)
    //        return false;
    //
    //    return true;
    //}
    //
    //void CObject::SetMetaTag(jsonUI::HwpJson* pMetaTag)
    //{
    //    if (IsMetaTagVaild(pMetaTag))
    //    {
    //        auto pMetaData = SetMetaTag();
    //        hncstd::wstring strJson;
    //        if (pMetaTag->stringfy(strJson)) {
    //            CMetaTagChild* pMetaTagChild = pMetaData->SetMetaTagChild();
    //            pMetaTagChild->SetJsonValue(strJson.c_str());
    //        }
    //    }
    //}
    //
    //CMetaTag* CObject::SetMetaTag(CMetaTag* pMetaTag)
    //{
    //    CMetaTag* MetaTag = pMetaTag;
    //    if (MetaTag == NULL) {
    //        MetaTag = CMetaTag::Create();
    //    }
    //    SetObject((CObject*)MetaTag);
    //    return MetaTag;
    //}


    /////////////////////////////////////////////////////////////////////////////////////
    // CExtObject Implementation
    CExtObject::CExtObject(unsigned int id)
        : CObject(id), m_pMapStruct(NULL), m_pObjectList(NULL)
    {
    }

    CExtObject::~CExtObject()
    {
        if (m_pObjectList) {
            std::for_each(m_pObjectList->begin(), m_pObjectList->end(), ObjectDelete());

            delete m_pObjectList;
        }
    }

    void CExtObject::InitMap(bool bRead)
    {
        if (m_pMapStruct && m_pMapStruct->m_pMap) {
            if (bRead)
                std::sort(m_pMapStruct->m_pMap->begin(), m_pMapStruct->m_pMap->end(), _MapElem::_foSortByName());
            else
                std::sort(m_pMapStruct->m_pMap->begin(), m_pMapStruct->m_pMap->end(), _MapElem::_foSortById());
        }
    }

    void CExtObject::SetObject(CObject* pobject, BOOL bAutoSet/*= TRUE*/)
    {
        if (bAutoSet) {
            if (!m_pObjectList) {
                m_pObjectList = new Objectlist;
                m_pObjectList->reserve(4);
            }

            m_pObjectList->push_back(pobject);
        }

        pobject->SetParentObj(this);
        pobject->SetRootpart(GetRootpart());
    }

    CObject* CExtObject::CreateObject(LPCWSTR elename, BOOL bAutoSet/*= TRUE*/)
    {
        CObject* pRstChild = NULL;

        if (m_pMapStruct && m_pMapStruct->m_pMap) {
            _MapElem* pPrevCached = m_pMapStruct->m_pCached;
            if (pPrevCached && !_ustrcmp(pPrevCached->elemName, elename)) {
                pRstChild = pPrevCached->elemFunc();
                pRstChild->SetObjectID(pPrevCached->elemId);
            }

            if (!pRstChild) {
                _Maplist::iterator iter = std::lower_bound(m_pMapStruct->m_pMap->begin(), m_pMapStruct->m_pMap->end(), _MapElem(0, elename, NULL), _MapElem::_foSortByName());
                if (iter != m_pMapStruct->m_pMap->end()) {
                    m_pMapStruct->m_pCached = &(*iter);
                    _MapElem* pCurCached = m_pMapStruct->m_pCached;
                    if (!_ustrcmp(pCurCached->elemName, elename))
                        pRstChild = pCurCached->elemFunc();

                    if (pRstChild) {
                        pRstChild->SetObjectID(iter->elemId);
                    }
                }
            }

            if (pRstChild) {
                SetObject(pRstChild, bAutoSet);
                return pRstChild;
            } else {
                // XML파일이 validate하다면, Map을 잘못 만들어주었음.
                if (!HasAnyelement()) {
                    if ((_ustrcmp(elename, EPUB_SWITCH_ELMENT) != 0) && \
                        (_ustrcmp(elename, EPUB_CASE_ELMENT) != 0) && \
                        (_ustrcmp(elename, EPUB_DEFAULT_ELMENT) != 0) && \
                        (_ustrcmp(elename, PARA_SWITCH_ELMENT) != 0) && \
                        (_ustrcmp(elename, PARA_CASE_ELMENT) != 0) && \
                        (_ustrcmp(elename, PARA_DEFAULT_ELMENT) != 0)
                        ) {
                        _ASSERT(FALSE);
                    }
                }
            }
        } else {
            if ((GetID() != ID_STRING_ANYELEMENT_ID) && (GetID() != ID_ANYELEMENT_ID)) {
                // map init() 함수가 호출 안됨
                // 표준문서 팀에 알려주세요
                _ASSERT(FALSE);
            }
        }

        return pRstChild;
    }

    CObject* CExtObject::GetObjectByID(unsigned int id, int index) const
    {
        if (m_pObjectList && !m_pObjectList->empty()) {
            Objectlist::iterator iter;

            if (index == 0) {
                iter = std::find_if(m_pObjectList->begin(), m_pObjectList->end(), std::binder2nd<_FindObjectID>(_FindObjectID(), id));
                if (iter != m_pObjectList->end())
                    return (*iter);
            } else {
                int findex = 0;
                for (iter = m_pObjectList->begin(); iter != m_pObjectList->end(); ++iter) {
                    if ((*iter)->GetID() == id) {
                        if (findex == index) {
                            return (*iter);
                        } else {
                            findex++;
                        }
                    }
                }
            }
        }

        return NULL;
    }

    CObject* CExtObject::GetObjectByIndex(unsigned int index) const
    {
        if (index >= m_pObjectList->size())
            return 0;

        return m_pObjectList->at(index);
    }

    size_t CExtObject::GetObjectListByID(unsigned int id, Objectlist& objectlist) const
    {
        objectlist.clear();

        if (m_pObjectList && !m_pObjectList->empty()) {
            std::for_each(m_pObjectList->begin(), m_pObjectList->end(), _SetObjectListID(objectlist, id));
        }

        return objectlist.size();
    }

    size_t CExtObject::GetObjectCountByID(unsigned int id) const
    {
        size_t findex = 0;
        if (m_pObjectList && !m_pObjectList->empty()) {
            Objectlist::iterator iter;

            for (iter = m_pObjectList->begin(); iter != m_pObjectList->end(); ++iter) {
                if ((*iter)->GetID() == id) {
                    findex++;
                }
            }
        }

        return findex;
    }


    bool CExtObject::HasChildList(void) const
    {
        if (m_pObjectList && !m_pObjectList->empty()) {
            return TRUE;
        }
        return FALSE;
    }

    unsigned int CExtObject::GetChildCount(void) const
    {
        if (m_pObjectList == NULL)
            return 0;

        return (unsigned int)m_pObjectList->size();
    }

    LPCWSTR CExtObject::FindObjectName(CObject* pChildObj)
    {
        InitMap(false);

        if (m_pMapStruct && m_pMapStruct->m_pMap) {
            LPCWSTR pRstName = NULL;
            _MapElem* pPrevCached = m_pMapStruct->m_pCached;
            if (pPrevCached && (pPrevCached->elemId == pChildObj->GetID()))
                pRstName = pPrevCached->elemName;

            if (!pRstName) {
                _Maplist::iterator iter = std::lower_bound(m_pMapStruct->m_pMap->begin(), m_pMapStruct->m_pMap->end(), _MapElem(pChildObj->GetID(), NULL, NULL), _MapElem::_foSortById());
                if ((iter != m_pMapStruct->m_pMap->end()) && ((*iter).elemId == pChildObj->GetID())) {
                    m_pMapStruct->m_pCached = &(*iter);
                    pRstName = m_pMapStruct->m_pCached->elemName;
                }
            }

            if (pRstName)
                return pRstName;

            if (HasAnyelement()) {
                return pChildObj->GetElemName();
            }
        }

        return pChildObj->GetElemName();
    }

    void CExtObject::SetObjectList(Objectlist* objectlist)
    {
        if (objectlist && !objectlist->empty()) {
            Objectlist::iterator iter;

            for (iter = objectlist->begin(); iter != objectlist->end(); ++iter) {
                CObject* clone = (*iter)->Clone();
                if (clone) {
                    SetObject(clone);
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////
    // CExtObject Implementation
    CNamedObject::CNamedObject(unsigned int id)
        : CExtObject(id), m_elemName(L"")
    {
    }

    CNamedObject::~CNamedObject()
    {
    }

    void CNamedObject::SetElemName(LPCWSTR elename)
    {
        m_elemName = elename;
    }

    LPCWSTR CNamedObject::GetElemName() const
    {
        return m_elemName.c_str();
    }


    /////////////////////////////////////////////////////////////////////////////////////
    // CCustomObject Implementation
    CCustomObject::CCustomObject(unsigned int id) : CNamedObject(id)
    {
    }

    CCustomObject::~CCustomObject()
    {
    }

    CObject* CCustomObject::CreateObject(LPCWSTR /*elename*/, BOOL /*bAutoSet = TRUE*/)
    {
        // 반드시 상속받은 쪽에서 구현하시오
        _ASSERT(FALSE);
        return NULL;
    }

    bool CCustomObject::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* /*att*/)
    {
        // 반드시 상속받은 쪽에서 구현하시오
        _ASSERT(FALSE);
        return false;
    }

    bool CCustomObject::ReadAttribute(CAttribute* /*att*/)
    {
        // 반드시 상속받은 쪽에서 구현하시오
        _ASSERT(FALSE);
        return false;
    }




}
