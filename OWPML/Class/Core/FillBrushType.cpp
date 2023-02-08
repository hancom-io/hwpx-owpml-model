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
#include "FillBrushType.h"

namespace OWPML {

    CFillBrushType* CFillBrushType::Create()
    {
        return new CFillBrushType();
    }

    CFillBrushType* CFillBrushType::Clone()
    {
        CFillBrushType* clone = new CFillBrushType();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFillBrushType::CFillBrushType() : CExtObject(ID_CORE_FillBrushType)
    {
    }

    CFillBrushType::~CFillBrushType()
    {
    }

    void CFillBrushType::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CFillBrushType, winBrush)
            OWPML_CORE_REDIRECT_FUNC(CFillBrushType, gradation)
            OWPML_CORE_REDIRECT_FUNC(CFillBrushType, imgBrush)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFillBrushType)
            OWPML_CORE_ADD_REDIRECT_FUNC(winBrush, CWinBrush, ID_CORE_WinBrush)
            OWPML_CORE_ADD_REDIRECT_FUNC(gradation, CGradation, ID_CORE_Gradation)
            OWPML_CORE_ADD_REDIRECT_FUNC(imgBrush, CImgBrush, ID_CORE_ImgBrush)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFillBrushType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFillBrushType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CWinBrush* CFillBrushType::SetwinBrush(CWinBrush* pwinBrush)
    {
        CWinBrush* winBrush = pwinBrush;
        if (winBrush == NULL) {
            winBrush = CWinBrush::Create();
        }
        SetObject((CObject*)winBrush);

        return winBrush;
    }

    CWinBrush* CFillBrushType::GetwinBrush(int index)
    {
        return static_cast<CWinBrush*>(GetObjectByID(ID_CORE_WinBrush, index));
    }

    CGradation* CFillBrushType::Setgradation(CGradation* pgradation)
    {
        CGradation* gradation = pgradation;
        if (gradation == NULL) {
            gradation = CGradation::Create();
        }
        SetObject((CObject*)gradation);

        return gradation;
    }

    CGradation* CFillBrushType::Getgradation(int index)
    {
        return static_cast<CGradation*>(GetObjectByID(ID_CORE_Gradation, index));
    }

    CImgBrush* CFillBrushType::SetimgBrush(CImgBrush* pimgBrush)
    {
        CImgBrush* imgBrush = pimgBrush;
        if (imgBrush == NULL) {
            imgBrush = CImgBrush::Create();
        }
        SetObject((CObject*)imgBrush);

        return imgBrush;
    }

    CImgBrush* CFillBrushType::GetimgBrush(int index)
    {
        return static_cast<CImgBrush*>(GetObjectByID(ID_CORE_ImgBrush, index));
    }

}
