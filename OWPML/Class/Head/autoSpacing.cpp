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
#include "autoSpacing.h"

namespace OWPML {


    CAutoSpacing* CAutoSpacing::Create()
    {
        return new CAutoSpacing();
    }

    CAutoSpacing::CAutoSpacing() : CExtObject(ID_HEAD_AutoSpacing), m_bEAsianEng(false), m_bEAsianNum(false)
    {
    }

    CAutoSpacing::~CAutoSpacing()
    {
    }

    void CAutoSpacing::InitMap(bool /*bRead*/)
    {
    }

    bool CAutoSpacing::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"eAsianEng", m_bEAsianEng);
        Util::CXMLAttConverter::SetAttribute(att, L"eAsianNum", m_bEAsianNum);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAutoSpacing::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"eAsianEng", m_bEAsianEng);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"eAsianNum", m_bEAsianNum);

        return bres;
    }

}
