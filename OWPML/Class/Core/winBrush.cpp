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
#include "winBrush.h"

namespace OWPML {


    CWinBrush* CWinBrush::Create()
    {
        return new CWinBrush();
    }

    CWinBrush* CWinBrush::Clone()
    {
        CWinBrush* clone = new CWinBrush();

        clone->SetFaceColor(this->m_cFaceColor);
        clone->SetHatchColor(this->m_cHatchColor);
        clone->SetHatchStyle((HATCHSTYLETYPE)this->m_uHatchStyle);
        clone->SetAlpha(this->m_fAlpha);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CWinBrush::CWinBrush() : CExtObject(ID_CORE_WinBrush), m_cFaceColor(0xFFFFFF), m_cHatchColor(0x000000), m_fAlpha(0.0), m_uHatchStyle((UINT)-1)
    {
    }

    CWinBrush::~CWinBrush()
    {
    }

    void CWinBrush::InitMap(bool /*bRead*/)
    {
    }

    bool CWinBrush::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"faceColor", m_cFaceColor);
        Util::CXMLAttConverter::SetAttribute(att, L"hatchColor", m_cHatchColor);
        Util::CXMLAttConverter::SetAttribute(att, L"hatchStyle", g_HatchStyleList, m_uHatchStyle);
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CWinBrush::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"faceColor", m_cFaceColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hatchColor", m_cHatchColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hatchStyle", g_HatchStyleList, m_uHatchStyle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);

        return bres;
    }

}
