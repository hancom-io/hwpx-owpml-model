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
#include "AutoNumFormatType.h"

namespace OWPML {


    CAutoNumFormatType* CAutoNumFormatType::Create()
    {
        return new CAutoNumFormatType();
    }

    CAutoNumFormatType* CAutoNumFormatType::Clone()
    {
        CAutoNumFormatType* clone = new CAutoNumFormatType();

        clone->SetType((NUMBERTYPE)this->m_uType);
        clone->SetUserChar(this->m_strUserChar.c_str());
        clone->SetPrefixChar(this->m_strPrefixChar.c_str());
        clone->SetSuffixChar(this->m_strSuffixChar.c_str());
        clone->SetSupscript(this->m_bSupscript);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CAutoNumFormatType::CAutoNumFormatType() : CExtObject(ID_PARA_AutoNumFormatType), m_uType(LNT_DIGIT), m_bSupscript(false)
    {
    }

    CAutoNumFormatType::~CAutoNumFormatType()
    {
    }

    void CAutoNumFormatType::InitMap(bool /*bRead*/)
    {
    }

    bool CAutoNumFormatType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_NumberTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"userChar", m_strUserChar);
        Util::CXMLAttConverter::SetAttribute(att, L"prefixChar", m_strPrefixChar);
        Util::CXMLAttConverter::SetAttribute(att, L"suffixChar", m_strSuffixChar);
        Util::CXMLAttConverter::SetAttribute(att, L"supscript", m_bSupscript);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAutoNumFormatType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_NumberTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"userChar", m_strUserChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"prefixChar", m_strPrefixChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"suffixChar", m_strSuffixChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"supscript", m_bSupscript);

        return bres;
    }

}
