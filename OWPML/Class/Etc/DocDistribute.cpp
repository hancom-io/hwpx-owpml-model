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
#include "DocDistribute.h"

namespace OWPML {

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CDocDistribute
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    CDocDistribute* CDocDistribute::Create()
    {
        return new CDocDistribute();
    }

    CDocDistribute::CDocDistribute() : CExtObject(ID_DOC_Distribute), m_nocopy(false), m_noprint(false)
    {
    }

    CDocDistribute::~CDocDistribute()
    {
    }

    void CDocDistribute::InitMap(bool /*bRead*/)
    {
    }

    bool CDocDistribute::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"key", m_key);
        Util::CXMLAttConverter::SetAttribute(att, L"nocopy", m_nocopy);
        Util::CXMLAttConverter::SetAttribute(att, L"noprint", m_noprint);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDocDistribute::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"key", m_key);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"nocopy", m_nocopy);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"noprint", m_noprint);
        return bres;
    }

}
