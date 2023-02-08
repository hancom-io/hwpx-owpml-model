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
#include "sz.h"

namespace OWPML {


    CSz* CSz::Create()
    {
        return new CSz();
    }

    CSz* CSz::Clone()
    {
        CSz* clone = new CSz();

        clone->SetWidthRelTo((WIDTHRELTOTYPE)this->m_uWidthRelTo);
        clone->SetHeight(this->m_uHeight);
        clone->SetHeightRelTo((HEIGHTRELTOTYPE)this->m_uHeightRelTo);
        clone->SetProtect(this->m_bProtect);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CSz::CSz() : CExtObject(ID_PARA_Sz), m_uWidth(0), m_uWidthRelTo(ABSOLUTE), m_uHeight(0), m_uHeightRelTo(ABSOLUTE), m_bProtect(false)
    {
    }

    CSz::~CSz()
    {
    }

    void CSz::InitMap(bool /*bRead*/)
    {
    }

    bool CSz::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"widthRelTo", g_WidthRelToList, m_uWidthRelTo);
        Util::CXMLAttConverter::SetAttribute(att, L"height", m_uHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"heightRelTo", g_HeightRelToList, m_uHeightRelTo);
        Util::CXMLAttConverter::SetAttribute(att, L"protect", m_bProtect);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSz::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"widthRelTo", g_WidthRelToList, m_uWidthRelTo);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"height", m_uHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"heightRelTo", g_HeightRelToList, m_uHeightRelTo);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"protect", m_bProtect);

        return bres;
    }

}
