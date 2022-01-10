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
#include "PictureType.h"

namespace OWPML {

    CPictureType* CPictureType::Create()
    {
        return new CPictureType();
    }

    CPictureType* CPictureType::Clone()
    {
        CPictureType* clone = new CPictureType();

        clone->SetReverse(this->m_bReverse);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPictureType::CPictureType() : CAbstractShapeComponentType(ID_PARA_PictureType), m_bReverse(false)
    {
    }

    CPictureType::~CPictureType()
    {
    }

    void CPictureType::InitMap(bool bRead)
    {
        // "AbstractShapeObjectType.h"
        OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, sz)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, pos)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, outMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, caption)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, shapeComment)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, parameterset)
            // metatag & json
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, metaTag)

            // AbstractShapeComponentType.h
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeComponentType, offset)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeComponentType, orgSz)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeComponentType, curSz)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeComponentType, flip)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeComponentType, rotationInfo)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeComponentType, renderingInfo)

            OWPML_PARALIST_REDIRECT_FUNC(CPictureType, lineShape)
            OWPML_PARALIST_REDIRECT_FUNC(CPictureType, imgRect)
            OWPML_PARALIST_REDIRECT_FUNC(CPictureType, imgClip)
            OWPML_PARALIST_REDIRECT_FUNC(CPictureType, effects)
            OWPML_PARALIST_REDIRECT_FUNC(CPictureType, inMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CPictureType, imgDim)
            OWPML_CORE_REDIRECT_FUNC(CPictureType, img)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPictureType)
            // "AbstractShapeObjectType.h"
            OWPML_PARALIST_ADD_REDIRECT_FUNC(sz, CSz, ID_PARA_Sz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CASOPos, ID_PARA_ASOPos)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outMargin, COutMargin, ID_PARA_OutMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(caption, CCaption, ID_PARA_Caption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shapeComment, CShapeComment, ID_PARA_ShapeComment)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)

            // AbstractShapeComponentType.h
            OWPML_PARALIST_ADD_REDIRECT_FUNC(offset, CASCOffset, ID_PARA_ASCOffset)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(orgSz, COrgSz, ID_PARA_OrgSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(curSz, CCurSz, ID_PARA_CurSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(flip, CFlip, ID_PARA_Flip)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(rotationInfo, CRotationInfo, ID_PARA_RotationInfo)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(renderingInfo, CRenderingInfo, ID_PARA_RenderingInfo)

            OWPML_PARALIST_ADD_REDIRECT_FUNC(lineShape, CLineShapeType, ID_PARA_LineShapeType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(imgRect, CImgRect, ID_PARA_ImgRect)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(imgClip, CImgClip, ID_PARA_ImgClip)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(effects, CEffectsType, ID_PARA_EffectsType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(inMargin, CInsideMarginType, ID_PARA_InsideMarginType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(imgDim, CImgDim, ID_PARA_ImgDim)
            OWPML_CORE_ADD_REDIRECT_FUNC(img, CImageType, ID_CORE_ImageType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPictureType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeComponentType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"reverse", m_bReverse);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPictureType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeComponentType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"reverse", m_bReverse);
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CLineShapeType* CPictureType::SetlineShape(CLineShapeType* plineShape)
    {
        CLineShapeType* lineShape = plineShape;
        if (lineShape == NULL) {
            lineShape = CLineShapeType::Create();
        }
        SetObject((CObject*)lineShape);

        return lineShape;
    }

    CLineShapeType* CPictureType::GetlineShape(int index)
    {
        return static_cast<CLineShapeType*>(GetObjectByID(ID_PARA_LineShapeType, index));
    }

    CImgRect* CPictureType::SetimgRect(CImgRect* pimgRect)
    {
        CImgRect* imgRect = pimgRect;
        if (imgRect == NULL) {
            imgRect = CImgRect::Create();
        }
        SetObject((CObject*)imgRect);

        return imgRect;
    }

    CImgRect* CPictureType::GetimgRect(int index)
    {
        return static_cast<CImgRect*>(GetObjectByID(ID_PARA_ImgRect, index));
    }

    CImgClip* CPictureType::SetimgClip(CImgClip* pimgClip)
    {
        CImgClip* imgClip = pimgClip;
        if (imgClip == NULL) {
            imgClip = CImgClip::Create();
        }
        SetObject((CObject*)imgClip);

        return imgClip;
    }

    CImgClip* CPictureType::GetimgClip(int index)
    {
        return static_cast<CImgClip*>(GetObjectByID(ID_PARA_ImgClip, index));
    }

    CEffectsType* CPictureType::Seteffects(CEffectsType* peffects)
    {
        CEffectsType* effects = peffects;
        if (effects == NULL) {
            effects = CEffectsType::Create();
        }
        SetObject((CObject*)effects);

        return effects;
    }

    CEffectsType* CPictureType::Geteffects(int index)
    {
        return static_cast<CEffectsType*>(GetObjectByID(ID_PARA_EffectsType, index));
    }

    CInsideMarginType* CPictureType::SetinMargin(CInsideMarginType* pinMargin)
    {
        CInsideMarginType* inMargin = pinMargin;
        if (inMargin == NULL) {
            inMargin = CInsideMarginType::Create();
        }
        SetObject((CObject*)inMargin);

        return inMargin;
    }

    CInsideMarginType* CPictureType::GetinMargin(int index)
    {
        return static_cast<CInsideMarginType*>(GetObjectByID(ID_PARA_InsideMarginType, index));
    }

    CImageType* CPictureType::Setimg(CImageType* pimg)
    {
        CImageType* img = pimg;
        if (img == NULL) {
            img = CImageType::Create();
        }
        SetObject((CObject*)img);

        return img;
    }

    CImageType* CPictureType::Getimg(int index)
    {
        return static_cast<CImageType*>(GetObjectByID(ID_CORE_ImageType, index));
    }

    CImgDim* CPictureType::SetimgDim(CImgDim* imgDim)
    {
        CImgDim* dim = imgDim;
        if (dim == NULL)
            dim = CImgDim::Create();
        SetObject((CObject*)dim);

        return dim;
    }

    CImgDim* CPictureType::GetimgDim()
    {
        return static_cast<CImgDim*>(GetObjectByID(ID_PARA_ImgDim));
    }

}
