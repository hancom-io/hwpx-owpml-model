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
#include "ImageType.h"

namespace OWPML {


    CImageType* CImageType::Create()
    {
        return new CImageType();
    }

    CImageType* CImageType::Clone()
    {
        CImageType* clone = new CImageType();

        clone->SetBinaryItemIDRef(this->m_strBinaryItemIDRef.c_str());
        clone->SetBright(this->m_nBright);
        clone->SetContrast(this->m_nContrast);
        clone->SetEffect((IMAGEEFFECTTYPE)this->m_uEffect);
        clone->SetAlpha(this->m_fAlpha);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CImageType::CImageType() : CExtObject(ID_CORE_ImageType), m_nBright(0), m_nContrast(0), m_uEffect(IET_REAL_PIC), m_fAlpha(0.0)
    {
    }

    CImageType::~CImageType()
    {
    }

    void CImageType::InitMap(bool /*bRead*/)
    {
    }

    bool CImageType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"bright", m_nBright);
        Util::CXMLAttConverter::SetAttribute(att, L"contrast", m_nContrast);
        Util::CXMLAttConverter::SetAttribute(att, L"effect", g_ImageEffectList, m_uEffect);
        Util::CXMLAttConverter::SetAttribute(att, L"alpha", m_fAlpha);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CImageType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"bright", m_nBright);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"contrast", m_nContrast);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"effect", g_ImageEffectList, m_uEffect);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"alpha", m_fAlpha);

        return bres;
    }

}
