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
#include "Util.h"
#include "Serialize.h"
#include "ConnectPointType.h"

namespace OWPML {

    ////////////////////////////////////////////////////////////////////////////
    // CConnectPointType Declaration 
    ////////////////////////////////////////////////////////////////////////////
    CConnectPointType* CConnectPointType::Create()
    {
        return new CConnectPointType(ID_PARA_ConnectPointType);
    }

    CConnectPointType* CConnectPointType::CreateArg(UINT id)
    {
        return new CConnectPointType(id);
    }

    CConnectPointType* CConnectPointType::Clone()
    {
        CConnectPointType* clone = new CConnectPointType();

        clone->SetX(this->m_nX);
        clone->SetY(this->m_nY);
        clone->SetSubjectIDRef(this->m_uSubjectIDRef);
        clone->SetSubjectIdx(this->m_uSubjectIdx);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CConnectPointType::CConnectPointType(UINT id) : CExtObject(id), m_nX(-1), m_nY(-1), m_uSubjectIDRef(0), m_uSubjectIdx(0)
    {
    }

    CConnectPointType::~CConnectPointType()
    {
    }

    void CConnectPointType::InitMap(bool /*bRead*/)
    {
    }

    bool CConnectPointType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"x", m_nX);
        Util::CXMLAttConverter::SetAttribute(att, L"y", m_nY);

        Util::CXMLAttConverter::SetAttribute(att, L"subjectIDRef", m_uSubjectIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"subjectIdx", m_uSubjectIdx);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CConnectPointType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x", m_nX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y", m_nY);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"subjectIDRef", m_uSubjectIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"subjectIdx", m_uSubjectIdx);
        return bres;
    }

    ////////////////////////////////////////////////////////////////////////////
    // CConnectControlPointType Declaration 
    ////////////////////////////////////////////////////////////////////////////

    CConnectControlPointType* CConnectControlPointType::Create()
    {
        return new CConnectControlPointType(ID_PARA_ConnectControlPointType);
    }

    CConnectControlPointType::CConnectControlPointType(UINT id) : CExtObject(id), m_nX(-1), m_nY(-1), m_uType(0)
    {
    }

    CConnectControlPointType::~CConnectControlPointType()
    {
    }

    void CConnectControlPointType::InitMap(bool /*bRead*/)
    {
    }

    bool CConnectControlPointType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"x", m_nX);
        Util::CXMLAttConverter::SetAttribute(att, L"y", m_nY);

        Util::CXMLAttConverter::SetAttribute(att, L"type", m_uType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CConnectControlPointType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x", m_nX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y", m_nY);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", m_uType);
        return bres;
    }


    ////////////////////////////////////////////////////////////////////////////
    // CConnectControlPoints Declaration 
    ////////////////////////////////////////////////////////////////////////////
    CConnectControlPoints* CConnectControlPoints::Create()
    {
        return new CConnectControlPoints(ID_PARA_ConnectControlPoints);
    }

    CConnectControlPoints::CConnectControlPoints(UINT id) : CExtObject(id)
    {
    }

    CConnectControlPoints::~CConnectControlPoints()
    {
    }

    void CConnectControlPoints::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CConnectControlPointType, point)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CConnectControlPoints)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(point, CConnectControlPointType, ID_PARA_ConnectControlPointType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CConnectControlPoints::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CConnectControlPoints::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CConnectControlPointType* CConnectControlPoints::SetcontrolPt(CConnectControlPointType* pcontrolPt)
    {
        CConnectControlPointType* controlPt = pcontrolPt;
        if (controlPt == NULL) {
            controlPt = CConnectControlPointType::Create();
        }
        SetObject((CObject*)controlPt);

        return controlPt;

    }

    CConnectControlPointType* CConnectControlPoints::GetcontrolPt(int index)
    {
        return static_cast<CConnectControlPointType*>(GetObjectByID(ID_PARA_ConnectControlPointType, index));
    }

}
