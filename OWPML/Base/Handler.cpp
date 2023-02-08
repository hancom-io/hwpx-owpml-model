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
#include "Attribute.h"
#include "PartNameSpaceInfo.h"
#include "DefaultHandler.h"

#include "Handler.h"

namespace OWPML {
    CHandler::CHandler() : m_curobject(NULL), m_elementlevel(0)
    {
        m_NSInfo = CPartNameSpaceInfo::GetMgr();
    }

    CHandler::~CHandler()
    {
        _ASSERT(m_pFactory.empty());        // 문서가 validate 하지 않음(closing elem 부족)

        while (!m_pFactory.empty()) {
            CObjectFactory* pfactory = m_pFactory.top();
            if (pfactory) {
                // pfactory 내부 object중 CPType이 가장 최상위 object이므로 이를 삭제해준다.
                // 삭제하지 않을 경우 메모리릭이 발생한다.
                CObject* pobj = pfactory->GetObject();
                if (pobj && pobj->GetID() == ID_PARA_PType) {
                    if (pobj->GetParentObj() && pobj->GetParentObj()->GetID() == ID_BODY_SectionType) {
                        delete pobj;
                    }
                }
                delete pfactory;
            }
            m_pFactory.pop();
        }
    }


    void CHandler::startDocument()
    {
    }

    void CHandler::endDocument()
    {
        CObjectFactory* pfactory = m_pFactory.top();
        if (pfactory)
            delete pfactory;

        m_pFactory.pop();
    }

    void CHandler::startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs)
    {
        CObjectFactory* pfactory = NULL;

        m_elementlevel++;

        // element create
        pfactory = m_pFactory.top();
        if (pfactory) {
            m_curobject = pfactory->CreateObject(qname, FALSE);

            if (m_curobject) {
                pfactory = NormalElement(pfactory, attrs, -1);
            } else {
                CObjectFactory* ptempfactory = pfactory;
                pfactory = CompatibilityElement(ptempfactory, localname, attrs);
                if (pfactory == NULL) {
                    pfactory = AnyElement(ptempfactory, uri, localname, qname, attrs);
                }
            }
        }

        m_pFactory.push(pfactory);
    }

    void CHandler::endElement(LPCWSTR const /*uri*/, LPCWSTR const /*localname*/, LPCWSTR const qname)
    {
        CObjectFactory* pfactory = m_pFactory.top();
        if (pfactory) {
            CObject* pCurParent = pfactory->GetObject();
            if (pCurParent && (pCurParent->GetID() == ID_STRING_ANYELEMENT_ID)) {
                OWPML::CStringAnyElement* panyelement = (OWPML::CStringAnyElement*)pCurParent;
                panyelement->ToStringEndElement(qname);
            } else if (pCurParent && (pCurParent->GetID() == ID_ANYELEMENT_ID)) {
                OWPML::CAnyElement* panyelement = (OWPML::CAnyElement*)pCurParent;
                if (panyelement->GetIgnoreSpace())
                    panyelement->ReSetvalue();
            }

            delete pfactory;
        }

        m_pFactory.pop();
        pfactory = m_pFactory.top();
        if (pfactory)
            m_curobject = pfactory->GetObject();

        m_elementlevel--;
    }

    void CHandler::startPrefixMapping(LPCWSTR const prefix, LPCWSTR const uri)
    {
        if (!m_namespaceAnyelemnt.empty())
            m_namespaceAnyelemnt.append(L" ");

        if (m_curobject) { // root는 제외
            if (m_curobject->HasAnyelement() || (m_curobject->GetID() == ID_STRING_ANYELEMENT_ID)) {
                m_namespaceAnyelemnt.append(L"xmlns:");
                m_namespaceAnyelemnt.append(prefix);
                m_namespaceAnyelemnt.append(L"=");
                m_namespaceAnyelemnt.append(L"\"");
                m_namespaceAnyelemnt.append(uri);
                m_namespaceAnyelemnt.append(L"\"");
            }
        }

        CPartNameSpaceInfo::GetMgr()->PushNameSpace(prefix, uri);
    }

    void CHandler::endPrefixMapping(LPCWSTR const prefix)
    {
        CPartNameSpaceInfo::GetMgr()->PopNameSpace(prefix);
    }

    void CHandler::characters(LPCWSTR const chars, const unsigned int length)
    {
        if (m_curobject) {
            m_curobject->ReadNodeValue(chars, length);
        }
    }

    CObjectFactory* CHandler::NormalElement(CObjectFactory* pfactory, const CAttribute* attrs, int level)
    {
        if (m_curobject) {
            CObject* pCurParent = pfactory->GetObject();
            if (pCurParent == m_curobject)                    // Root Element의 경우에는 ParentSetting이 불필요.
                pCurParent = NULL;

            if (pCurParent)
                m_curobject->SetRootpart(pCurParent->GetRootpart());

            // attribute Read
            m_curobject->ReadAttribute((CAttribute*)attrs);

            // Factory 등록
            pfactory = new CEleObjectFactory(m_curobject);

            if (pCurParent) {
                if (level == -1) {
                    pCurParent->SetObject(m_curobject);
                } else {
                    if (m_elementlevel != level) {
                        pCurParent->SetObject(m_curobject);
                    }
                }
            }
        }

        return pfactory;
    }

    CObjectFactory* CHandler::AnyElement(CObjectFactory* pfactory, LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs)
    {
        CObjectFactory* panyfactory = NULL;
        // anyelement 처리
        CObject* pCurParent = pfactory->GetObject();
        if (pCurParent != NULL) {
            if (pCurParent->HasAnyelement()) {
                CObject* panyelement = pCurParent->ChildElementCreate(localname, attrs);
                if (panyelement && (panyelement->GetID() == ID_RDF_ANYELEMENT)) {
                    CRdfAnyElement* prdfanyelemnt = (CRdfAnyElement*)panyelement;
                    m_curobject = panyelement;
                    panyfactory = new CEleObjectFactory(pCurParent);

                    if (uri) {
                        prdfanyelemnt->Setnamespace(CPartNameSpaceInfo::GetMgr()->FindLocalPrefix(uri), uri);
                    }
                    // attribute Read
                    m_curobject->ReadAttribute((CAttribute*)attrs);

                    pCurParent->SetObject(m_curobject);

                    if (!m_namespaceAnyelemnt.empty())
                        m_namespaceAnyelemnt.clear();
                } else if (panyelement && (panyelement->GetID() == ID_STRING_ANYELEMENT_ID)) {
                    OWPML::CStringAnyElement* panyelement2 = (CStringAnyElement*)panyelement;
                    panyelement2->ToStringStartElement(qname, (CAttribute*)attrs, m_namespaceAnyelemnt);
                    m_curobject = panyelement2;

                    panyfactory = new CEleObjectFactory(m_curobject);
                    pCurParent->SetObject(m_curobject);

                    if (!m_namespaceAnyelemnt.empty())
                        m_namespaceAnyelemnt.clear();
                } else {
                    // element id를 추가한다.
                    OWPML::CAnyElement* panyelement2 = OWPML::CAnyElement::Create();

                    m_curobject = panyelement2;
                    panyfactory = new CEleObjectFactory(m_curobject);

                    panyelement2->Setname(qname);
                    // attribute Read
                    panyelement2->ReadAttribute((CAttribute*)attrs);


                    pCurParent->SetObject(m_curobject);

                    if (!m_namespaceAnyelemnt.empty())
                        m_namespaceAnyelemnt.clear();
                }
            } else if (pCurParent->GetID() == ID_STRING_ANYELEMENT_ID) {
                OWPML::CStringAnyElement* panyelement = (OWPML::CStringAnyElement*)pCurParent;
                panyelement->ToStringStartElement(qname, (CAttribute*)attrs, m_namespaceAnyelemnt);
                m_curobject = panyelement;

                panyfactory = new CEleObjectFactory(pCurParent);

                if (!m_namespaceAnyelemnt.empty())
                    m_namespaceAnyelemnt.clear();
            } else {
                CObject* panyelement = pCurParent->ChildElementCreate(qname, attrs);
                if (panyelement) {
                    m_curobject = panyelement;
                    panyfactory = new CEleObjectFactory(pCurParent);

                    pCurParent->SetObject(m_curobject);

                    if (!m_namespaceAnyelemnt.empty())
                        m_namespaceAnyelemnt.clear();
                }
            }
        }

        return panyfactory;
    }

    CObjectFactory* CHandler::CompatibilityElement(CObjectFactory* prefactory, LPCWSTR const localname, const CAttribute* attrs)
    {
        LPCWSTR strEpubRequires = L"epub:required-namespace";
        LPCWSTR strRequires = L"hp:required-namespace";
        LPCWSTR strSwitch = L"switch";
        LPCWSTR strCase = L"case";
        LPCWSTR strDefault = L"default";
        CObjectFactory* pfactory = NULL;

        if (prefactory == NULL)
            return NULL;

        if ((_ustrcmp(localname, strSwitch) != 0) && (_ustrcmp(localname, strCase) != 0) && (_ustrcmp(localname, strDefault) != 0)) {
            return NULL;
        }

        if (prefactory->IsCompatibility()) {
            BOOL baddchild = FALSE;
            // 성공적으로 등록되었는지를 판단하기 위해, 리스트의 카운트를 확인
            if (prefactory->IsSelectChild()) {
                baddchild = TRUE;
            }

            if (!baddchild) {
                if (_ustrcmp(localname, strCase) == 0) {
                    if (_CaseRequires(attrs->getValue(strRequires)) || _CaseRequires(attrs->getValue(strEpubRequires))) {

                        prefactory->SetSelectChild(TRUE);
                        pfactory = new CEleObjectFactory(prefactory->GetObject());
                    }
                } else if (_ustrcmp(localname, strDefault) == 0) {
                    prefactory->SetSelectChild(TRUE);
                    pfactory = new CEleObjectFactory(prefactory->GetObject());
                }
            }
        }

        if (_ustrcmp(localname, strSwitch) == 0) {
            pfactory = new CEleObjectFactory(prefactory->GetObject());
            pfactory->SetCompatibility(TRUE);
        }

        return pfactory;
    }

    BOOL CHandler::_CaseRequires(LPCWSTR requires)
    {
        WCHAR szDelim[] = L" \t\r\n";
        WCHAR* pToken = NULL;
        WCHAR* pNextToken = NULL;
        hncstd::wstring strRequires;
        if (requires != NULL) {
            strRequires.assign(requires);
        }
        std::map<hncstd::wstring, hncstd::wstring>::iterator iter;

        pToken = _ustrtok_s((LPWSTR)strRequires.c_str(), szDelim, &pNextToken);

        if ((requires == NULL) || (requires[0] == 0))
            return FALSE;

        while (pToken != NULL) {
            // application이 지원하는 namespace인지 확인한다.
            if (!CPartNameSpaceInfo::GetMgr()->IsAppNameSpace(pToken))
                return FALSE;

            pToken = _ustrtok_s(NULL, szDelim, &pNextToken);
        }

        return TRUE;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    // factory 관련 class
    ////////////////////////////////////////////////////////////////////////////////////////////

    CRootObjFactory::CRootObjFactory(CObject* obj) : CObjectFactory(obj)
    {
    }

    CRootObjFactory::~CRootObjFactory()
    {
    }

    CObject* CRootObjFactory::CreateObject(LPCWSTR elename, BOOL /*bAutoSet = TRUE*/)
    {
        if (m_pObject->GetID() == ID_ANYELEMENT_ID) {
            ((CAnyElement*)m_pObject)->Setname(elename);
        }

        return m_pObject;
    }

    CObject* CRootObjFactory::GetObject(void)
    {
        return m_pObject;
    }

    CEleObjectFactory::CEleObjectFactory(CObject* obj) : CObjectFactory(obj)
    {
    }

    CEleObjectFactory::~CEleObjectFactory()
    {
    }

    CObject* CEleObjectFactory::CreateObject(LPCWSTR elename, BOOL bAutoSet/*= TRUE*/)
    {
        if (m_pObject) {
            return m_pObject->CreateObject(elename, bAutoSet);
        }

        return NULL;
    }

    CObject* CEleObjectFactory::GetObject(void)
    {
        return m_pObject;
    }

}