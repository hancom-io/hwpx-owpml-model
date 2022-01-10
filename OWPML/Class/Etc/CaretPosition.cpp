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
#include "CaretPosition.h"

namespace OWPML {


    CCaretPosition* CCaretPosition::Create()
    {
        return new CCaretPosition();
    }

    CCaretPosition::CCaretPosition() : CExtObject(ID_APPLICATION_CaretPosition), m_uListID(0), m_uParaID(0), m_uPos(0)
    {
    }

    CCaretPosition::~CCaretPosition()
    {
    }

    void CCaretPosition::InitMap(bool /*bRead*/)
    {
    }

    bool CCaretPosition::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"listIDRef", m_uListID);
        Util::CXMLAttConverter::SetAttribute(att, L"paraIDRef", m_uParaID);
        Util::CXMLAttConverter::SetAttribute(att, L"pos", m_uPos);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCaretPosition::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"listIDRef", m_uListID);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"paraIDRef", m_uParaID);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pos", m_uPos);

        return bres;
    }

}
