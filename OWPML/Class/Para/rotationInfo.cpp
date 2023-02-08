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
#include "rotationInfo.h"

namespace OWPML {


    CRotationInfo* CRotationInfo::Create()
    {
        return new CRotationInfo();
    }

    CRotationInfo* CRotationInfo::Clone()
    {
        CRotationInfo* clone = new CRotationInfo();

        clone->SetAngle(this->m_nAngle);
        clone->SetCenterX(this->m_uCenterX);
        clone->SetCenterY(this->m_uCenterY);
        clone->SetRotateImage(this->m_bRotateImage);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CRotationInfo::CRotationInfo() : CExtObject(ID_PARA_RotationInfo), m_nAngle(0), m_uCenterX(0), m_uCenterY(0), m_bRotateImage(false)
    {
    }

    CRotationInfo::~CRotationInfo()
    {
    }

    void CRotationInfo::InitMap(bool /*bRead*/)
    {
    }

    bool CRotationInfo::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"angle", m_nAngle);
        Util::CXMLAttConverter::SetAttribute(att, L"centerX", m_uCenterX);
        Util::CXMLAttConverter::SetAttribute(att, L"centerY", m_uCenterY);
        Util::CXMLAttConverter::SetAttribute(att, L"rotateimage", m_bRotateImage);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRotationInfo::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"angle", m_nAngle);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"centerX", m_uCenterX);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"centerY", m_uCenterY);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"rotateimage", m_bRotateImage);

        return bres;
    }

}
