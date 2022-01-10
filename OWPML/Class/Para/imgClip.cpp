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
#include "imgClip.h"

namespace OWPML {


    CImgClip* CImgClip::Create()
    {
        return new CImgClip();
    }

    CImgClip* CImgClip::Clone()
    {
        CImgClip* clone = new CImgClip();

        clone->SetLeft(this->m_nLeft);
        clone->SetRight(this->m_nRight);
        clone->SetTop(this->m_nTop);
        clone->SetBottom(this->m_nBottom);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CImgClip::CImgClip() : CExtObject(ID_PARA_ImgClip), m_nLeft(-1), m_nRight(-1), m_nTop(-1), m_nBottom(-1)
    {
    }

    CImgClip::~CImgClip()
    {
    }

    void CImgClip::InitMap(bool /*bRead*/)
    {
    }

    bool CImgClip::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"left", m_nLeft);
        Util::CXMLAttConverter::SetAttribute(att, L"right", m_nRight);
        Util::CXMLAttConverter::SetAttribute(att, L"top", m_nTop);
        Util::CXMLAttConverter::SetAttribute(att, L"bottom", m_nBottom);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CImgClip::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"left", m_nLeft);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"right", m_nRight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"top", m_nTop);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"bottom", m_nBottom);

        return bres;
    }

}
