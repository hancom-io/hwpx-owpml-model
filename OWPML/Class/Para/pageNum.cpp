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
#include "pageNum.h"

namespace OWPML {


    CPageNum* CPageNum::Create()
    {
        return new CPageNum();
    }

    CPageNum* CPageNum::Clone()
    {
        CPageNum* clone = new CPageNum();

        clone->SetPos((PAGENUMPOSTYPE)this->m_uPos);
        clone->SetFormatType((NUMBERTYPE)this->m_uFormatType);
        clone->SetSideChar(this->m_strSideChar.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPageNum::CPageNum() : CExtObject(ID_PARA_PageNum), m_uPos(PNPT_TOP_LEFT), m_uFormatType(LNT_DIGIT), m_strSideChar(L"")
    {
    }

    CPageNum::~CPageNum()
    {
    }

    void CPageNum::InitMap(bool /*bRead*/)
    {
    }

    bool CPageNum::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"pos", g_PageNumPosList, m_uPos);
        Util::CXMLAttConverter::SetAttribute(att, L"formatType", g_NumberTypeList, m_uFormatType);
        Util::CXMLAttConverter::SetAttribute(att, L"sideChar", m_strSideChar);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPageNum::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pos", g_PageNumPosList, m_uPos);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"formatType", g_NumberTypeList, m_uFormatType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"sideChar", m_strSideChar);

        return bres;
    }

}
