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
#include "AbstractShapeComponentType.h"
#include "ContainerType.h"

namespace OWPML {

    CContainerType* CContainerType::Create()
    {
        return new CContainerType();
    }

    CContainerType* CContainerType::Clone()
    {
        CContainerType* clone = new CContainerType();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CContainerType::CContainerType() : CAbstractShapeComponentType(ID_PARA_ContainerType)
    {
    }

    CContainerType::~CContainerType()
    {
    }

    void CContainerType::InitMap(bool bRead)
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

            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, container)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, line)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, rect)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, ellipse)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, arc)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, polygon)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, curve)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, connectLine)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, pic)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, ole)
            OWPML_PARALIST_REDIRECT_FUNC(CContainerType, textart)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CContainerType)
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

            OWPML_PARALIST_ADD_REDIRECT_FUNC(container, CContainerType, ID_PARA_ContainerType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(line, CLineType, ID_PARA_LineType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(rect, CRectangleType, ID_PARA_RectangleType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(ellipse, CEllipseType, ID_PARA_EllipseType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(arc, CArcType, ID_PARA_ArcType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(polygon, CPolygonType, ID_PARA_PolygonType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(curve, CCurveType, ID_PARA_CurveType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(connectLine, CConnectLineType, ID_PARA_ConnectLineType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pic, CPictureType, ID_PARA_PictureType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(ole, COLEType, ID_PARA_OLEType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(textart, CTextart, ID_PARA_Textart)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CContainerType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeComponentType::WriteElement(pCurObjName, serialize, att);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CContainerType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeComponentType::ReadAttribute(att);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CContainerType* CContainerType::Setcontainer(CContainerType* pcontainer)
    {
        CContainerType* container = pcontainer;
        if (container == NULL) {
            container = CContainerType::Create();
        }
        SetObject((CObject*)container);

        return container;
    }

    CContainerType* CContainerType::Getcontainer(int index)
    {
        return static_cast<CContainerType*>(GetObjectByID(ID_PARA_ContainerType, index));
    }

    CLineType* CContainerType::Setline(CLineType* pline)
    {
        CLineType* line = pline;
        if (line == NULL) {
            line = CLineType::Create();
        }
        SetObject((CObject*)line);

        return line;
    }

    CLineType* CContainerType::Getline(int index)
    {
        return static_cast<CLineType*>(GetObjectByID(ID_PARA_LineType, index));
    }

    CRectangleType* CContainerType::Setrect(CRectangleType* prect)
    {
        CRectangleType* rect = prect;
        if (rect == NULL) {
            rect = CRectangleType::Create();
        }
        SetObject((CObject*)rect);

        return rect;
    }

    CRectangleType* CContainerType::Getrect(int index)
    {
        return static_cast<CRectangleType*>(GetObjectByID(ID_PARA_RectangleType, index));
    }

    CEllipseType* CContainerType::Setellipse(CEllipseType* pellipse)
    {
        CEllipseType* ellipse = pellipse;
        if (ellipse == NULL) {
            ellipse = CEllipseType::Create();
        }
        SetObject((CObject*)ellipse);

        return ellipse;
    }

    CEllipseType* CContainerType::Getellipse(int index)
    {
        return static_cast<CEllipseType*>(GetObjectByID(ID_PARA_EllipseType, index));
    }

    CArcType* CContainerType::Setarc(CArcType* parc)
    {
        CArcType* arc = parc;
        if (arc == NULL) {
            arc = CArcType::Create();
        }
        SetObject((CObject*)arc);

        return arc;
    }

    CArcType* CContainerType::Getarc(int index)
    {
        return static_cast<CArcType*>(GetObjectByID(ID_PARA_ArcType, index));
    }

    CPolygonType* CContainerType::Setpolygon(CPolygonType* ppolygon)
    {
        CPolygonType* polygon = ppolygon;
        if (polygon == NULL) {
            polygon = CPolygonType::Create();
        }
        SetObject((CObject*)polygon);

        return polygon;
    }

    CPolygonType* CContainerType::Getpolygon(int index)
    {
        return static_cast<CPolygonType*>(GetObjectByID(ID_PARA_PolygonType, index));
    }

    CCurveType* CContainerType::Setcurve(CCurveType* pcurve)
    {
        CCurveType* curve = pcurve;
        if (curve == NULL) {
            curve = CCurveType::Create();
        }
        SetObject((CObject*)curve);

        return curve;
    }

    CCurveType* CContainerType::Getcurve(int index)
    {
        return static_cast<CCurveType*>(GetObjectByID(ID_PARA_CurveType, index));
    }

    CConnectLineType* CContainerType::SetconnectLine(CConnectLineType* pconnectLine)
    {
        CConnectLineType* connectLine = pconnectLine;
        if (connectLine == NULL) {
            connectLine = CConnectLineType::Create();
        }
        SetObject((CObject*)connectLine);

        return connectLine;
    }

    CConnectLineType* CContainerType::GetconnectLine(int index)
    {
        return static_cast<CConnectLineType*>(GetObjectByID(ID_PARA_ConnectLineType, index));
    }

    CPictureType* CContainerType::Setpic(CPictureType* ppic)
    {
        CPictureType* pic = ppic;
        if (pic == NULL) {
            pic = CPictureType::Create();
        }
        SetObject((CObject*)pic);

        return pic;
    }

    CPictureType* CContainerType::Getpic(int index)
    {
        return static_cast<CPictureType*>(GetObjectByID(ID_PARA_PictureType, index));
    }

    COLEType* CContainerType::Setole(COLEType* pole)
    {
        COLEType* ole = pole;
        if (ole == NULL) {
            ole = COLEType::Create();
        }
        SetObject((CObject*)ole);

        return ole;
    }

    COLEType* CContainerType::Getole(int index)
    {
        return static_cast<COLEType*>(GetObjectByID(ID_PARA_OLEType, index));
    }

}
