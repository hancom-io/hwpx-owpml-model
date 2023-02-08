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
#include "pageNumCtrl.h"

namespace OWPML {


    CPageNumCtrl* CPageNumCtrl::Create()
    {
        return new CPageNumCtrl();
    }

    CPageNumCtrl* CPageNumCtrl::Clone()
    {
        CPageNumCtrl* clone = new CPageNumCtrl();

        clone->SetPageStartsOn((PAGENUMSTARTSONTYPE)this->m_uPageStartsOn);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPageNumCtrl::CPageNumCtrl() : CExtObject(ID_PARA_PageNumCtrl), m_uPageStartsOn(PNST_BOTH)
    {
    }

    CPageNumCtrl::~CPageNumCtrl()
    {
    }

    void CPageNumCtrl::InitMap(bool /*bRead*/)
    {
    }

    bool CPageNumCtrl::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"pageStartsOn", g_PageNumStartsOnList, m_uPageStartsOn);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPageNumCtrl::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageStartsOn", g_PageNumStartsOnList, m_uPageStartsOn);

        return bres;
    }

}
