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
#include "EllipseType.h"

namespace OWPML {

    CEllipseType* CEllipseType::Create()
    {
        return new CEllipseType();
    }

    CEllipseType* CEllipseType::Clone()
    {
        CEllipseType* clone = new CEllipseType();

        clone->SetIntervalDirty(this->m_bIntervalDirty);
        clone->SetHasArcPr(this->m_bHasArcPr);
        clone->SetArcType((ARCTYPE)this->m_uArcType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEllipseType::CEllipseType() : CAbstractDrawingObjectType(ID_PARA_EllipseType), m_bIntervalDirty(false), m_bHasArcPr(false), m_uArcType(SAT_NORMAL)
    {
    }

    CEllipseType::~CEllipseType()
    {
    }

    void CEllipseType::InitMap(bool bRead)
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

            OWPML_CORE_REDIRECT_FUNC(CEllipseType, center)
            OWPML_CORE_REDIRECT_FUNC(CEllipseType, ax1)
            OWPML_CORE_REDIRECT_FUNC(CEllipseType, ax2)
            OWPML_CORE_REDIRECT_FUNC(CEllipseType, start1)
            OWPML_CORE_REDIRECT_FUNC(CEllipseType, start2)
            OWPML_CORE_REDIRECT_FUNC(CEllipseType, end1)
            OWPML_CORE_REDIRECT_FUNC(CEllipseType, end2)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEllipseType)
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

            // AbstractDrawingObjectType.h
            OWPML_PARALIST_ADD_REDIRECT_FUNC(offset, CASCOffset, ID_PARA_ASCOffset)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(orgSz, COrgSz, ID_PARA_OrgSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(curSz, CCurSz, ID_PARA_CurSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(flip, CFlip, ID_PARA_Flip)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(rotationInfo, CRotationInfo, ID_PARA_RotationInfo)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(renderingInfo, CRenderingInfo, ID_PARA_RenderingInfo)

            OWPML_CORE_ADD_REDIRECT_FUNC(center, CPointType, ID_CORE_PointType_Center)
            OWPML_CORE_ADD_REDIRECT_FUNC(ax1, CPointType, ID_CORE_PointType_Ax1)
            OWPML_CORE_ADD_REDIRECT_FUNC(ax2, CPointType, ID_CORE_PointType_Ax2)
            OWPML_CORE_ADD_REDIRECT_FUNC(start1, CPointType, ID_CORE_PointType_Start1)
            OWPML_CORE_ADD_REDIRECT_FUNC(start2, CPointType, ID_CORE_PointType_Start2)
            OWPML_CORE_ADD_REDIRECT_FUNC(end1, CPointType, ID_CORE_PointType_End1)
            OWPML_CORE_ADD_REDIRECT_FUNC(end2, CPointType, ID_CORE_PointType_End2)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEllipseType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractDrawingObjectType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"intervalDirty", m_bIntervalDirty);
        Util::CXMLAttConverter::SetAttribute(att, L"hasArcPr", m_bHasArcPr);
        Util::CXMLAttConverter::SetAttribute(att, L"arcType", g_ArcTypeList, m_uArcType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEllipseType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractDrawingObjectType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"intervalDirty", m_bIntervalDirty);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hasArcPr", m_bHasArcPr);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"arcType", g_ArcTypeList, m_uArcType);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPointType* CEllipseType::Setcenter(CPointType* pcenter)
    {
        CPointType* center = pcenter;
        if (center == NULL) {
            center = CPointType::CreateArg(ID_CORE_PointType_Center);
        }
        SetObject((CObject*)center);

        return center;
    }

    CPointType* CEllipseType::Getcenter(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Center, index));
    }

    CPointType* CEllipseType::Setax1(CPointType* pax1)
    {
        CPointType* ax1 = pax1;
        if (ax1 == NULL) {
            ax1 = CPointType::CreateArg(ID_CORE_PointType_Ax1);
        }
        SetObject((CObject*)ax1);

        return ax1;
    }

    CPointType* CEllipseType::Getax1(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Ax1, index));
    }

    CPointType* CEllipseType::Setax2(CPointType* pax2)
    {
        CPointType* ax2 = pax2;
        if (ax2 == NULL) {
            ax2 = CPointType::CreateArg(ID_CORE_PointType_Ax2);
        }
        SetObject((CObject*)ax2);

        return ax2;
    }

    CPointType* CEllipseType::Getax2(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Ax2, index));
    }

    CPointType* CEllipseType::Setstart1(CPointType* pstart1)
    {
        CPointType* start1 = pstart1;
        if (start1 == NULL) {
            start1 = CPointType::CreateArg(ID_CORE_PointType_Start1);
        }
        SetObject((CObject*)start1);

        return start1;
    }

    CPointType* CEllipseType::Getstart1(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Start1, index));
    }

    CPointType* CEllipseType::Setstart2(CPointType* pstart2)
    {
        CPointType* start2 = pstart2;
        if (start2 == NULL) {
            start2 = CPointType::CreateArg(ID_CORE_PointType_Start2);
        }
        SetObject((CObject*)start2);

        return start2;
    }

    CPointType* CEllipseType::Getstart2(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Start2, index));
    }

    CPointType* CEllipseType::Setend1(CPointType* pend1)
    {
        CPointType* end1 = pend1;
        if (end1 == NULL) {
            end1 = CPointType::CreateArg(ID_CORE_PointType_End1);
        }
        SetObject((CObject*)end1);

        return end1;
    }

    CPointType* CEllipseType::Getend1(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_End1, index));
    }

    CPointType* CEllipseType::Setend2(CPointType* pend2)
    {
        CPointType* end2 = pend2;
        if (end2 == NULL) {
            end2 = CPointType::CreateArg(ID_CORE_PointType_End2);
        }
        SetObject((CObject*)end2);

        return end2;
    }

    CPointType* CEllipseType::Getend2(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_End2, index));
    }

}
