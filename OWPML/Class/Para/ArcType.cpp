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
#include "AbstractShapeObjectType.h"
#include "AbstractFormObjectType.h"
#include "AbstractDrawingObjectType.h"
#include "ArcType.h"

namespace OWPML {

    CArcType* CArcType::Create()
    {
        return new CArcType();
    }

    CArcType::CArcType() : CAbstractDrawingObjectType(ID_PARA_ArcType), m_uType(SAT_NORMAL)
    {
    }

    CArcType::~CArcType()
    {
    }

    void CArcType::InitMap(bool bRead)
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

            // AbstractDrawingObjectType.h
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractDrawingObjectType, lineShape)
            OWPML_CORE_REDIRECT_FUNC(CAbstractDrawingObjectType, fillBrush)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractDrawingObjectType, drawText)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractDrawingObjectType, shadow)

            OWPML_CORE_REDIRECT_FUNC(CArcType, center)
            OWPML_CORE_REDIRECT_FUNC(CArcType, ax1)
            OWPML_CORE_REDIRECT_FUNC(CArcType, ax2)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CArcType)
            // "AbstractShapeObjectType.h"
            OWPML_PARALIST_ADD_REDIRECT_FUNC(lineShape, CLineShapeType, ID_PARA_LineShapeType)
            OWPML_CORE_ADD_REDIRECT_FUNC(fillBrush, CFillBrushType, ID_CORE_FillBrushType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(drawText, CDrawText, ID_PARA_DrawText)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shadow, CShadowType, ID_PARA_ShadowType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)

            // AbstractShapeComponentType.h
            OWPML_PARALIST_ADD_REDIRECT_FUNC(sz, CSz, ID_PARA_Sz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CASOPos, ID_PARA_ASOPos)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outMargin, COutMargin, ID_PARA_OutMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(caption, CCaption, ID_PARA_Caption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shapeComment, CShapeComment, ID_PARA_ShapeComment)

            // CAbstractShapeComponentType.h
            OWPML_PARALIST_ADD_REDIRECT_FUNC(offset, CASCOffset, ID_PARA_ASCOffset)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(orgSz, COrgSz, ID_PARA_OrgSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(curSz, CCurSz, ID_PARA_CurSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(flip, CFlip, ID_PARA_Flip)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(rotationInfo, CRotationInfo, ID_PARA_RotationInfo)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(renderingInfo, CRenderingInfo, ID_PARA_RenderingInfo)

            OWPML_CORE_ADD_REDIRECT_FUNC(center, CPointType, ID_CORE_PointType_Center)
            OWPML_CORE_ADD_REDIRECT_FUNC(ax1, CPointType, ID_CORE_PointType_Ax1)
            OWPML_CORE_ADD_REDIRECT_FUNC(ax2, CPointType, ID_CORE_PointType_Ax2)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CArcType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractDrawingObjectType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ArcTypeList, m_uType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CArcType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractDrawingObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ArcTypeList, m_uType);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPointType* CArcType::Setcenter(CPointType* pcenter)
    {
        CPointType* center = pcenter;
        if (center == NULL) {
            center = CPointType::CreateArg(ID_CORE_PointType_Center);
        }
        SetObject((CObject*)center);

        return center;
    }

    CPointType* CArcType::Getcenter(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Center, index));
    }

    CPointType* CArcType::Setax1(CPointType* pax1)
    {
        CPointType* ax1 = pax1;
        if (ax1 == NULL) {
            ax1 = CPointType::CreateArg(ID_CORE_PointType_Ax1);
        }
        SetObject((CObject*)ax1);

        return ax1;
    }

    CPointType* CArcType::Getax1(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Ax1, index));
    }

    CPointType* CArcType::Setax2(CPointType* pax2)
    {
        CPointType* ax2 = pax2;
        if (ax2 == NULL) {
            ax2 = CPointType::CreateArg(ID_CORE_PointType_Ax2);
        }
        SetObject((CObject*)ax2);

        return ax2;
    }

    CPointType* CArcType::Getax2(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Ax2, index));
    }

}
