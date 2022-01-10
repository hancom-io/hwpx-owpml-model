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
#include "imgRect.h"

namespace OWPML {

    CImgRect* CImgRect::Create()
    {
        return new CImgRect();
    }

    CImgRect* CImgRect::Clone()
    {
        CImgRect* clone = new CImgRect();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CImgRect::CImgRect() : CExtObject(ID_PARA_ImgRect)
    {
    }

    CImgRect::~CImgRect()
    {
    }

    void CImgRect::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CImgRect, pt0)
            OWPML_CORE_REDIRECT_FUNC(CImgRect, pt1)
            OWPML_CORE_REDIRECT_FUNC(CImgRect, pt2)
            OWPML_CORE_REDIRECT_FUNC(CImgRect, pt3)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CImgRect)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt0, CPointType, ID_CORE_PointType_Pt0)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt1, CPointType, ID_CORE_PointType_Pt1)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt2, CPointType, ID_CORE_PointType_Pt2)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt3, CPointType, ID_CORE_PointType_Pt3)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CImgRect::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CImgRect::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPointType* CImgRect::Setpt0(CPointType* ppt0)
    {
        CPointType* pt0 = ppt0;
        if (pt0 == NULL) {
            pt0 = CPointType::CreateArg(ID_CORE_PointType_Pt0);
        }
        SetObject((CObject*)pt0);

        return pt0;
    }

    CPointType* CImgRect::Getpt0(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt0, index));
    }

    CPointType* CImgRect::Setpt1(CPointType* ppt1)
    {
        CPointType* pt1 = ppt1;
        if (pt1 == NULL) {
            pt1 = CPointType::CreateArg(ID_CORE_PointType_Pt1);
        }
        SetObject((CObject*)pt1);

        return pt1;
    }

    CPointType* CImgRect::Getpt1(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt1, index));
    }

    CPointType* CImgRect::Setpt2(CPointType* ppt2)
    {
        CPointType* pt2 = ppt2;
        if (pt2 == NULL) {
            pt2 = CPointType::CreateArg(ID_CORE_PointType_Pt2);
        }
        SetObject((CObject*)pt2);

        return pt2;
    }

    CPointType* CImgRect::Getpt2(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt2, index));
    }

    CPointType* CImgRect::Setpt3(CPointType* ppt3)
    {
        CPointType* pt3 = ppt3;
        if (pt3 == NULL) {
            pt3 = CPointType::CreateArg(ID_CORE_PointType_Pt3);
        }
        SetObject((CObject*)pt3);

        return pt3;
    }

    CPointType* CImgRect::Getpt3(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt3, index));
    }

}
