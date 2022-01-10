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
#include "grid.h"

namespace OWPML {


    CGrid* CGrid::Create()
    {
        return new CGrid();
    }

    CGrid* CGrid::Clone()
    {
        CGrid* clone = new CGrid();

        clone->SetLineGrid(this->m_uLineGrid);
        clone->SetCharGrid(this->m_uCharGrid);
        clone->SetWonggojiFormat(this->m_bWonggojiFormat);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CGrid::CGrid() : CExtObject(ID_PARA_Grid), m_uLineGrid(0), m_uCharGrid(0), m_bWonggojiFormat(false)
    {
    }

    CGrid::~CGrid()
    {
    }

    void CGrid::InitMap(bool /*bRead*/)
    {
    }

    bool CGrid::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"lineGrid", m_uLineGrid);
        Util::CXMLAttConverter::SetAttribute(att, L"charGrid", m_uCharGrid);
        Util::CXMLAttConverter::SetAttribute(att, L"wonggojiFormat", m_bWonggojiFormat);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CGrid::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineGrid", m_uLineGrid);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charGrid", m_uCharGrid);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"wonggojiFormat", m_bWonggojiFormat);

        return bres;
    }

}
