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
#include "OWPMLSectionHandler.h"

#include "OWPMLSerialize.h"
#include "OWPMLSerializeModel.h"

#include "OWPMLUtil/HncCtrlChDef.h"

namespace OWPML {

    CSectionHandler::CSectionHandler(COwpmlSerialize* serialize, COwpmlSerializeModel* serializeModel) :
        m_startparalevel(0),
        m_serialize(serialize),
        m_serializeModel(serializeModel)
    {

    }

    CSectionHandler::~CSectionHandler()
    {
    }

    void CSectionHandler::startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs)
    {
        CObjectFactory* pfactory = NULL;

        m_elementlevel++;

        // element create
        pfactory = m_pFactory.top();
        if (pfactory) {
            m_curobject = pfactory->CreateObject(qname, FALSE);

            if (m_curobject) {
                pfactory = NormalElement(pfactory, attrs, m_startparalevel);
                if (m_serializeModel) {
                    if (IsMetaTagAttribute(attrs) || m_curobject->GetID() == ID_PARA_METATAG) {
                        m_serializeModel->PushMataTag(m_curobject);
                    }
                }
            } else {
                // 엘리먼트에 ctrlch속성값이 shapeobject이면 UnknownObject 타입으로 처리
                if (IsShapeObjectElem(attrs)) {
                    m_curobject = CUnknownObjectType::Create();

                    if (m_curobject) {
                        pfactory = NormalElement(pfactory, attrs, m_startparalevel);
                    }
                } else {
                    CObjectFactory* ptempfactory = pfactory;
                    pfactory = AnyElement(ptempfactory, uri, localname, qname, attrs);
                    if (pfactory == NULL) {
                        pfactory = CompatibilityElement(ptempfactory, localname, attrs);
                    }

                    if (pfactory == NULL) {
                        pfactory = NULL; // null factory 추가
                    }
                }
            }
        }

        m_pFactory.push(pfactory);
    }
    void CSectionHandler::endElement(LPCWSTR const /*uri*/, LPCWSTR const /*localname*/, LPCWSTR const /*qname*/)
    {
        if (m_curobject) {
            ProcessingElement();
        }

        _ASSERT(!m_pFactory.empty());
        if (!m_pFactory.empty()) {
            CObjectFactory* pfactory = m_pFactory.top();
            if (pfactory) {
                delete pfactory;
            }
        }

        m_pFactory.pop();

        _ASSERT(!m_pFactory.empty());
        if (!m_pFactory.empty()) {
            CObjectFactory* pfactory = m_pFactory.top();
            if (pfactory) {
                m_curobject = pfactory->GetObject();
            }
        }

        m_elementlevel--;
    }

    BOOL CSectionHandler::IsShapeObjectElem(const CAttribute* attrs)
    {
        LPCWSTR szAttrValue = attrs->getValue(L"ctrlch");

        // UnknownObject 생성 유무 확인
        if (szAttrValue && _uatoi(szAttrValue) == HWPCH_SHAPE_OBJECT)
            return TRUE;
        return FALSE;
    }

    BOOL CSectionHandler::IsMetaTagAttribute(const CAttribute* attrs)
    {
        LPCWSTR szAttrValue = attrs->getValue(L"metatag");

        // UnknownObject 생성 유무 확인
        if (szAttrValue)
            return TRUE;
        return FALSE;
    }

    void CSectionHandler::ProcessingElement()
    {
        UINT elemID = m_curobject->GetID();

        switch (elemID)
        {
        case ID_PARA_PictureType:
        {
            OWPML::CPictureType* pictureType = (OWPML::CPictureType*)m_curobject;
            m_serialize->ReadBindata(pictureType->Getimg()->GetBinaryItemIDRef(), FALSE);
            break;
        }
        default:
            break;
        }
    }

};