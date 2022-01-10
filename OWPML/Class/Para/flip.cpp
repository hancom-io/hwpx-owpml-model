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
#include "flip.h"

namespace OWPML {


    CFlip* CFlip::Create()
    {
        return new CFlip();
    }

    CFlip* CFlip::Clone()
    {
        CFlip* clone = new CFlip();

        clone->SetHorizontal(this->m_bHorizontal);
        clone->SetVertical(this->m_bVertical);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFlip::CFlip() : CExtObject(ID_PARA_Flip), m_bHorizontal(false), m_bVertical(false)
    {
    }

    CFlip::~CFlip()
    {
    }

    void CFlip::InitMap(bool /*bRead*/)
    {
    }

    bool CFlip::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"horizontal", m_bHorizontal);
        Util::CXMLAttConverter::SetAttribute(att, L"vertical", m_bVertical);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFlip::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horizontal", m_bHorizontal);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertical", m_bVertical);

        return bres;
    }

}
