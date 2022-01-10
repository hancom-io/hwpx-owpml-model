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
#include "PointType.h"

namespace OWPML {

    CPointType* CPointType::Create()
    {
        return new CPointType(ID_CORE_PointType);
    }

    CPointType* CPointType::Clone()
    {
        CPointType* clone = new CPointType();

        clone->SetX(this->m_nX);
        clone->SetY(this->m_nY);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPointType* CPointType::CreateArg(UINT id)
    {
        return new CPointType(id);
    }

    CPointType::CPointType(UINT id) : CExtObject(id), m_nX(-1), m_nY(-1)
    {
    }

    CPointType::~CPointType()
    {
    }

    void CPointType::InitMap(bool /*bRead*/)
    {
    }

    bool CPointType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"x", m_nX);
        Util::CXMLAttConverter::SetAttribute(att, L"y", m_nY);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPointType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"x", m_nX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"y", m_nY);

        return bres;
    }

}
