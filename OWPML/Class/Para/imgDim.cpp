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
#include "imgDim.h"

namespace OWPML {


    CImgDim* CImgDim::Create()
    {
        return new CImgDim();
    }

    CImgDim* CImgDim::Clone()
    {
        CImgDim* clone = new CImgDim();

        clone->SetWidth(this->m_uWidth);
        clone->SetHeight(this->m_uHeight);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CImgDim::CImgDim() : CExtObject(ID_PARA_ImgDim), m_uWidth(0), m_uHeight(0)
    {
    }

    CImgDim::~CImgDim()
    {
    }

    void CImgDim::InitMap(bool /*bRead*/)
    {
    }

    bool CImgDim::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"dimwidth", m_uWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"dimheight", m_uHeight);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CImgDim::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"dimwidth", m_uWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"dimheight", m_uHeight);

        return bres;
    }

}
