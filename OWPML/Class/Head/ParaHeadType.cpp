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
#include "ParaHeadType.h"

namespace OWPML {

    //////////////////////////////////////////////////////////////////////////////
    // CParaHeadType
    //////////////////////////////////////////////////////////////////////////////
    CParaHeadType* CParaHeadType::Create()
    {
        return new CParaHeadType(ID_HEAD_ParaHeadType);
    }

    CParaHeadType* CParaHeadType::CreateArg(UINT id)
    {
        return new CParaHeadType(id);
    }

    CParaHeadType::CParaHeadType(UINT id) : CStringValueObject(id), m_nLevel(0), m_uAlign(PHAT_LEFT), m_bUseInstWidth(true), m_bAutoIndent(true), m_nWidthAdjust(0), m_uTextOffsetType(TOT_PERCENT), m_nTextOffset(50), m_uNumFormat(LNT_DIGIT), m_bCheckable(false), m_uCharPrIDRef(0)
    {
    }

    CParaHeadType::~CParaHeadType()
    {
    }

    void CParaHeadType::InitMap(bool /*bRead*/)
    {
    }

    bool CParaHeadType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        WriteAttribute(att);

        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CParaHeadType::WriteAttribute(CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"level", m_nLevel);
        Util::CXMLAttConverter::SetAttribute(att, L"align", g_ParaHeadAlignList, m_uAlign);
        Util::CXMLAttConverter::SetAttribute(att, L"useInstWidth", m_bUseInstWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"autoIndent", m_bAutoIndent);
        Util::CXMLAttConverter::SetAttribute(att, L"widthAdjust", m_nWidthAdjust);
        Util::CXMLAttConverter::SetAttribute(att, L"textOffsetType", g_TextOffsetTypeList, m_uTextOffsetType);
        Util::CXMLAttConverter::SetAttribute(att, L"textOffset", m_nTextOffset);
        Util::CXMLAttConverter::SetAttribute(att, L"numFormat", g_NumberTypeList, m_uNumFormat);
        Util::CXMLAttConverter::SetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"checkable", m_bCheckable);

        return true;
    }

    bool CParaHeadType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"level", m_nLevel);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"align", g_ParaHeadAlignList, m_uAlign);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"useInstWidth", m_bUseInstWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"autoIndent", m_bAutoIndent);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"widthAdjust", m_nWidthAdjust);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textOffsetType", g_TextOffsetTypeList, m_uTextOffsetType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textOffset", m_nTextOffset);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"numFormat", g_NumberTypeList, m_uNumFormat);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"checkable", m_bCheckable);

        return bres;
    }

    //////////////////////////////////////////////////////////////////////////////
    // CParaHeadType2
    //////////////////////////////////////////////////////////////////////////////
    CParaHeadType2* CParaHeadType2::Create()
    {
        return new CParaHeadType2();
    }

    CParaHeadType2::CParaHeadType2() : CParaHeadType(ID_HEAD_ParaHeadType2), m_StartNumber(0)
    {
    }

    CParaHeadType2::~CParaHeadType2()
    {
    }

    void CParaHeadType2::InitMap(bool /*bRead*/)
    {
    }

    bool CParaHeadType2::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"start", m_StartNumber);
        CParaHeadType::WriteAttribute(att);

        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CParaHeadType2::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"start", m_StartNumber);
        bres &= CParaHeadType::ReadAttribute(att);

        return bres;
    }

}
