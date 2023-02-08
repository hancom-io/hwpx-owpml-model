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
#include "MatrixType.h"

namespace OWPML {

    CMatrixType* CMatrixType::Create()
    {
        return new CMatrixType(ID_CORE_MatrixType);
    }

    CMatrixType* CMatrixType::CreateArg(UINT id)
    {
        return new CMatrixType(id);
    }

    CMatrixType* CMatrixType::Clone()
    {
        CMatrixType* clone = new CMatrixType();

        clone->SetE1(this->m_fE1);
        clone->SetE2(this->m_fE2);
        clone->SetE3(this->m_fE3);
        clone->SetE4(this->m_fE4);
        clone->SetE5(this->m_fE5);
        clone->SetE6(this->m_fE6);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CMatrixType::CMatrixType(UINT id) : CExtObject(id), m_fE1(0.0), m_fE2(0.0), m_fE3(0.0), m_fE4(0.0), m_fE5(0.0), m_fE6(0.0)
    {
    }

    CMatrixType::~CMatrixType()
    {
    }

    void CMatrixType::InitMap(bool /*bRead*/)
    {
    }

    bool CMatrixType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"e1", m_fE1);
        Util::CXMLAttConverter::SetAttribute(att, L"e2", m_fE2);
        Util::CXMLAttConverter::SetAttribute(att, L"e3", m_fE3);
        Util::CXMLAttConverter::SetAttribute(att, L"e4", m_fE4);
        Util::CXMLAttConverter::SetAttribute(att, L"e5", m_fE5);
        Util::CXMLAttConverter::SetAttribute(att, L"e6", m_fE6);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMatrixType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"e1", m_fE1);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"e2", m_fE2);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"e3", m_fE3);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"e4", m_fE4);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"e5", m_fE5);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"e6", m_fE6);

        return bres;
    }

}
