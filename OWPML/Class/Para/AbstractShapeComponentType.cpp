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
#include "poffset.h"
#include "AbstractShapeObjectType.h"
#include "AbstractShapeComponentType.h"

namespace OWPML {
    CAbstractShapeComponentType::CAbstractShapeComponentType(UINT id) : CAbstractShapeObjectType(id), m_uGroupLevel(0), m_uInstId(0)
    {
    }

    CAbstractShapeComponentType::~CAbstractShapeComponentType()
    {
    }

    void CAbstractShapeComponentType::InitMap(bool /*bRead*/)
    {
    }

    bool CAbstractShapeComponentType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeObjectType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"href", m_strHref);
        Util::CXMLAttConverter::SetAttribute(att, L"groupLevel", m_uGroupLevel);
        Util::CXMLAttConverter::SetAttribute(att, L"instid", m_uInstId);

        return true;
    }

    bool CAbstractShapeComponentType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeObjectType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"href", m_strHref);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"groupLevel", m_uGroupLevel);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"instid", m_uInstId);
        return bres;
    }

    CASCOffset* CAbstractShapeComponentType::Setoffset(CASCOffset* poffset)
    {
        CASCOffset* offset = poffset;
        if (offset == NULL) {
            offset = CASCOffset::Create();
        }
        SetObject((CObject*)offset);

        return offset;
    }

    CASCOffset* CAbstractShapeComponentType::Getoffset(int index)
    {
        return static_cast<CASCOffset*>(GetObjectByID(ID_PARA_ASCOffset, index));
    }

    COrgSz* CAbstractShapeComponentType::SetorgSz(COrgSz* porgSz)
    {
        COrgSz* orgSz = porgSz;
        if (orgSz == NULL) {
            orgSz = COrgSz::Create();
        }
        SetObject((CObject*)orgSz);

        return orgSz;
    }

    COrgSz* CAbstractShapeComponentType::GetorgSz(int index)
    {
        return static_cast<COrgSz*>(GetObjectByID(ID_PARA_OrgSz, index));
    }

    CCurSz* CAbstractShapeComponentType::SetcurSz(CCurSz* pcurSz)
    {
        CCurSz* curSz = pcurSz;
        if (curSz == NULL) {
            curSz = CCurSz::Create();
        }
        SetObject((CObject*)curSz);

        return curSz;
    }

    CCurSz* CAbstractShapeComponentType::GetcurSz(int index)
    {
        return static_cast<CCurSz*>(GetObjectByID(ID_PARA_CurSz, index));
    }

    CFlip* CAbstractShapeComponentType::Setflip(CFlip* pflip)
    {
        CFlip* flip = pflip;
        if (flip == NULL) {
            flip = CFlip::Create();
        }
        SetObject((CObject*)flip);

        return flip;
    }

    CFlip* CAbstractShapeComponentType::Getflip(int index)
    {
        return static_cast<CFlip*>(GetObjectByID(ID_PARA_Flip, index));
    }

    CRotationInfo* CAbstractShapeComponentType::SetrotationInfo(CRotationInfo* protationInfo)
    {
        CRotationInfo* rotationInfo = protationInfo;
        if (rotationInfo == NULL) {
            rotationInfo = CRotationInfo::Create();
        }
        SetObject((CObject*)rotationInfo);

        return rotationInfo;
    }

    CRotationInfo* CAbstractShapeComponentType::GetrotationInfo(int index)
    {
        return static_cast<CRotationInfo*>(GetObjectByID(ID_PARA_RotationInfo, index));
    }

    CRenderingInfo* CAbstractShapeComponentType::SetrenderingInfo(CRenderingInfo* prenderingInfo)
    {
        CRenderingInfo* renderingInfo = prenderingInfo;
        if (renderingInfo == NULL) {
            renderingInfo = CRenderingInfo::Create();
        }
        SetObject((CObject*)renderingInfo);

        return renderingInfo;
    }

    CRenderingInfo* CAbstractShapeComponentType::GetrenderingInfo(int index)
    {
        return static_cast<CRenderingInfo*>(GetObjectByID(ID_PARA_RenderingInfo, index));
    }

}
