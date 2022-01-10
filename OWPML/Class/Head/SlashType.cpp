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
#include "SlashType.h"

namespace OWPML {

    CSlashType* CSlashType::Create()
    {
        return new CSlashType(ID_HEAD_SlashType);
    }

    CSlashType* CSlashType::CreateArg(UINT id)
    {
        return new CSlashType(id);
    }

    CSlashType::CSlashType(UINT id) : CExtObject(id), m_uCrooked(0), m_bIsCounter(false), m_uType(0)
    {
    }

    CSlashType::~CSlashType()
    {
    }

    void CSlashType::InitMap(bool /*bRead*/)
    {
    }

    bool CSlashType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_SlashTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"Crooked", m_uCrooked);
        Util::CXMLAttConverter::SetAttribute(att, L"isCounter", m_bIsCounter);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSlashType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_SlashTypeList, m_uType);
        if (Util::CXMLAttConverter::GetAttribute(att, L"Crooked", m_uCrooked)) {
            bres &= TRUE;
        } else {
            bres &= Util::CXMLAttConverter::GetAttribute(att, L"isCrooked", m_uCrooked); // 하위 버젼 (설령 잘못된 값이라도 읽어줌)
        }
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"isCounter", m_bIsCounter);

        return bres;
    }

}
