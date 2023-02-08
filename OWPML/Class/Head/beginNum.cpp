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
#include "beginNum.h"

namespace OWPML {


    CBeginNum* CBeginNum::Create()
    {
        return new CBeginNum();
    }

    CBeginNum::CBeginNum() : CExtObject(ID_HEAD_BeginNum), m_uPage(0), m_uFootnote(0), m_uEndnote(0), m_uPic(0), m_uTbl(0), m_uEquation(0)
    {
    }

    CBeginNum::~CBeginNum()
    {
    }

    void CBeginNum::InitMap(bool /*bRead*/)
    {
    }

    bool CBeginNum::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"page", m_uPage);
        Util::CXMLAttConverter::SetAttribute(att, L"footnote", m_uFootnote);
        Util::CXMLAttConverter::SetAttribute(att, L"endnote", m_uEndnote);
        Util::CXMLAttConverter::SetAttribute(att, L"pic", m_uPic);
        Util::CXMLAttConverter::SetAttribute(att, L"tbl", m_uTbl);
        Util::CXMLAttConverter::SetAttribute(att, L"equation", m_uEquation);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBeginNum::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"page", m_uPage);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"footnote", m_uFootnote);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"endnote", m_uEndnote);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pic", m_uPic);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tbl", m_uTbl);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"equation", m_uEquation);

        return bres;
    }

}
