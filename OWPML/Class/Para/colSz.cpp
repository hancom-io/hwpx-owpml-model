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
#include "colSz.h"

namespace OWPML {


    CColSz* CColSz::Create()
    {
        return new CColSz();
    }

    CColSz* CColSz::Clone()
    {
        CColSz* clone = new CColSz();

        clone->SetWidth(this->m_uWidth);
        clone->SetGap(this->m_uGap);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CColSz::CColSz() : CExtObject(ID_PARA_ColSz), m_uWidth(0), m_uGap(0)
    {
    }

    CColSz::~CColSz()
    {
    }

    void CColSz::InitMap(bool /*bRead*/)
    {
    }

    bool CColSz::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"gap", m_uGap);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CColSz::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"gap", m_uGap);

        return bres;
    }

}
