﻿/*
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
#include "cellSz.h"

namespace OWPML {


    CCellSz* CCellSz::Create()
    {
        return new CCellSz();
    }

    CCellSz* CCellSz::Clone()
    {
        CCellSz* clone = new CCellSz();

        clone->SetWidth(this->m_uWidth);
        clone->SetHeight(this->m_uHeight);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCellSz::CCellSz() : CExtObject(ID_PARA_CellSz), m_uWidth(0), m_uHeight(0)
    {
    }

    CCellSz::~CCellSz()
    {
    }

    void CCellSz::InitMap(bool /*bRead*/)
    {
    }

    bool CCellSz::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"height", m_uHeight);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCellSz::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"height", m_uHeight);

        return bres;
    }

}
