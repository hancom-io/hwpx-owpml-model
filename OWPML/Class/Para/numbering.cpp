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
#include "numbering.h"

namespace OWPML {


    CFNNumbering* CFNNumbering::Create()
    {
        return new CFNNumbering();
    }

    CFNNumbering* CFNNumbering::Clone()
    {
        CFNNumbering* clone = new CFNNumbering();

        clone->SetType((FNNUMBERINGTYPE)this->m_uType);
        clone->SetNewNum(this->m_uNewNum);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFNNumbering::CFNNumbering() : CExtObject(ID_PARA_FNNumbering), m_uType(FNNT_CONTINUOUS), m_uNewNum(1)
    {
    }

    CFNNumbering::~CFNNumbering()
    {
    }

    void CFNNumbering::InitMap(bool /*bRead*/)
    {
    }

    bool CFNNumbering::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_FNNumberingTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"newNum", m_uNewNum);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFNNumbering::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_FNNumberingTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"newNum", m_uNewNum);

        return bres;
    }


    CENNumbering* CENNumbering::Create()
    {
        return new CENNumbering();
    }

    CENNumbering* CENNumbering::Clone()
    {
        CENNumbering* clone = new CENNumbering();

        clone->SetType((ENNUMBERINGTYPE)this->m_uType);
        clone->SetNewNum(this->m_uNewNum);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CENNumbering::CENNumbering() : CExtObject(ID_PARA_ENNumbering), m_uType(ENNT_CONTINUOUS), m_uNewNum(1)
    {
    }

    CENNumbering::~CENNumbering()
    {
    }

    void CENNumbering::InitMap(bool /*bRead*/)
    {
    }

    bool CENNumbering::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ENNumberingTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"newNum", m_uNewNum);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CENNumbering::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ENNumberingTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"newNum", m_uNewNum);

        return bres;
    }

}
