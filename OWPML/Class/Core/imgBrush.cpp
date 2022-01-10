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
#include "imgBrush.h"

namespace OWPML {

    CImgBrush* CImgBrush::Create()
    {
        return new CImgBrush();
    }

    CImgBrush* CImgBrush::Clone()
    {
        CImgBrush* clone = new CImgBrush();

        clone->SetMode((IMGBRUSHMODETYPE)this->m_uMode);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CImgBrush::CImgBrush() : CExtObject(ID_CORE_ImgBrush), m_uMode(IBMT_TILE)
    {
    }

    CImgBrush::~CImgBrush()
    {
    }

    void CImgBrush::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CImgBrush, img)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CImgBrush)
            OWPML_CORE_ADD_REDIRECT_FUNC(img, CImageType, ID_CORE_ImageType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CImgBrush::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"mode", g_ImgBrushModeList, m_uMode);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CImgBrush::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"mode", g_ImgBrushModeList, m_uMode);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CImageType* CImgBrush::Setimg(CImageType* pimg)
    {
        CImageType* img = pimg;
        if (img == NULL) {
            img = CImageType::Create();
        }
        SetObject((CObject*)img);

        return img;
    }

    CImageType* CImgBrush::Getimg(int index)
    {
        return static_cast<CImageType*>(GetObjectByID(ID_CORE_ImageType, index));
    }

}
