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
#include "pageHiding.h"

namespace OWPML {


    CPageHiding* CPageHiding::Create()
    {
        return new CPageHiding();
    }

    CPageHiding* CPageHiding::Clone()
    {
        CPageHiding* clone = new CPageHiding();

        clone->SetHideHeader(this->m_bHideHeader);
        clone->SetHideFooter(this->m_bHideFooter);
        clone->SetHideMasterPage(this->m_bHideMasterPage);
        clone->SetHideBorder(this->m_bHideBorder);
        clone->SetHideFill(this->m_bHideFill);
        clone->SetHidePageNum(this->m_bHidePageNum);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPageHiding::CPageHiding() : CExtObject(ID_PARA_PageHiding), m_bHideHeader(false), m_bHideFooter(false), m_bHideMasterPage(false), m_bHideBorder(false), m_bHideFill(false), m_bHidePageNum(false)
    {
    }

    CPageHiding::~CPageHiding()
    {
    }

    void CPageHiding::InitMap(bool /*bRead*/)
    {
    }

    bool CPageHiding::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"hideHeader", m_bHideHeader);
        Util::CXMLAttConverter::SetAttribute(att, L"hideFooter", m_bHideFooter);
        Util::CXMLAttConverter::SetAttribute(att, L"hideMasterPage", m_bHideMasterPage);
        Util::CXMLAttConverter::SetAttribute(att, L"hideBorder", m_bHideBorder);
        Util::CXMLAttConverter::SetAttribute(att, L"hideFill", m_bHideFill);
        Util::CXMLAttConverter::SetAttribute(att, L"hidePageNum", m_bHidePageNum);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPageHiding::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideHeader", m_bHideHeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFooter", m_bHideFooter);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideMasterPage", m_bHideMasterPage);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideBorder", m_bHideBorder);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hideFill", m_bHideFill);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hidePageNum", m_bHidePageNum);

        return bres;
    }

}
