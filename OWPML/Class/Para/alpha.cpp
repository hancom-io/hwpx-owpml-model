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
#include "alpha.h"

namespace OWPML {


    CAlpha* CAlpha::Create()
    {
        return new CAlpha();
    }

    CAlpha::CAlpha() : CExtObject(ID_PARA_Alpha), m_fStart(0.0), m_fEnd(0.0)
    {
    }

    CAlpha::~CAlpha()
    {
    }

    void CAlpha::InitMap(bool /*bRead*/)
    {
    }

    bool CAlpha::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"start", m_fStart);
        Util::CXMLAttConverter::SetAttribute(att, L"end", m_fEnd);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAlpha::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"start", m_fStart);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"end", m_fEnd);

        return bres;
    }

}
