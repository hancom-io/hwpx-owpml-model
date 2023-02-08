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
#include "typeInfo.h"

namespace OWPML {


    CTypeInfo* CTypeInfo::Create()
    {
        return new CTypeInfo();
    }

    CTypeInfo::CTypeInfo() : CExtObject(ID_HEAD_TypeInfo), m_nWeight(-1), m_nProportion(-1), m_nContrast(-1), m_nStrokeVariation(-1), m_nXHeight(-1), m_nArmStyle(0)
    {
    }

    CTypeInfo::~CTypeInfo()
    {
    }

    void CTypeInfo::InitMap(bool /*bRead*/)
    {
    }

    bool CTypeInfo::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"familyType", g_FamilyTypeList, m_uFamilyType);
        if (!m_strSerifStyle.empty())
            Util::CXMLAttConverter::SetAttribute(att, L"serifStyle", m_strSerifStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"weight", m_nWeight);
        Util::CXMLAttConverter::SetAttribute(att, L"proportion", m_nProportion);
        Util::CXMLAttConverter::SetAttribute(att, L"contrast", m_nContrast);
        Util::CXMLAttConverter::SetAttribute(att, L"strokeVariation", m_nStrokeVariation);
        Util::CXMLAttConverter::SetAttribute(att, L"armStyle", m_nArmStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"letterform", m_nLetterform);
        Util::CXMLAttConverter::SetAttribute(att, L"midline", m_nMidline);
        Util::CXMLAttConverter::SetAttribute(att, L"xHeight", m_nXHeight);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTypeInfo::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"familyType", g_FamilyTypeList, m_uFamilyType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"serifStyle", m_strSerifStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"weight", m_nWeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"proportion", m_nProportion);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"contrast", m_nContrast);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"strokeVariation", m_nStrokeVariation);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"armStyle", m_nArmStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"letterform", m_nLetterform);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"midline", m_nMidline);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"xHeight", m_nXHeight);

        return bres;
    }

}
