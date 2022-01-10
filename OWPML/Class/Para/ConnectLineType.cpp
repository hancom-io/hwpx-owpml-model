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
#include "ConnectLineType.h"

namespace OWPML {

    CConnectLineType* CConnectLineType::Create()
    {
        return new CConnectLineType();
    }

    CConnectLineType* CConnectLineType::Clone()
    {
        CConnectLineType* clone = new CConnectLineType();

        clone->SetType((CONNECTLINETYPE)this->m_uType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CConnectLineType::CConnectLineType() : CAbstractDrawingObjectType(ID_PARA_ConnectLineType), m_uType(0)
    {
    }

    CConnectLineType::~CConnectLineType()
    {
    }

    void CConnectLineType::InitMap(bool bRead)
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

            OWPML_PARALIST_REDIRECT_FUNC(CConnectLineType, startPt)
            OWPML_PARALIST_REDIRECT_FUNC(CConnectLineType, endPt)
            OWPML_PARALIST_REDIRECT_FUNC(CConnectControlPoints, controlPoints)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CConnectLineType)
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

            OWPML_PARALIST_ADD_REDIRECT_FUNC(startPt, CConnectPointType, ID_PARA_ConnectStartPointType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(endPt, CConnectPointType, ID_PARA_ConnectEndPointType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(controlPoints, CConnectControlPoints, ID_PARA_ConnectControlPoints)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CConnectLineType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractDrawingObjectType::WriteElement(pCurObjName, serialize, att);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ConnectLineList, m_uType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CConnectLineType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractDrawingObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ConnectLineList, m_uType);
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CConnectPointType* CConnectLineType::SetstartPt(CConnectPointType* pstartPt)
    {
        CConnectPointType* startPt = pstartPt;
        if (startPt == NULL) {
            startPt = CConnectPointType::CreateArg(ID_PARA_ConnectStartPointType);
        }
        SetObject((CObject*)startPt);

        return startPt;
    }

    CConnectPointType* CConnectLineType::GetstartPt(int index)
    {
        return static_cast<CConnectPointType*>(GetObjectByID(ID_PARA_ConnectStartPointType, index));
    }

    CConnectPointType* CConnectLineType::SetendPt(CConnectPointType* pendPt)
    {
        CConnectPointType* endPt = pendPt;
        if (endPt == NULL) {
            endPt = CConnectPointType::CreateArg(ID_PARA_ConnectEndPointType);
        }
        SetObject((CObject*)endPt);

        return endPt;
    }

    CConnectPointType* CConnectLineType::GetendPt(int index)
    {
        return static_cast<CConnectPointType*>(GetObjectByID(ID_PARA_ConnectEndPointType, index));
    }


    CConnectControlPoints* CConnectLineType::SetcontrolPts(CConnectControlPoints* pcontrolPts)
    {
        CConnectControlPoints* controlPts = pcontrolPts;
        if (controlPts == NULL) {
            controlPts = CConnectControlPoints::Create();
        }
        SetObject((CObject*)controlPts);

        return controlPts;

    }

    CConnectControlPoints* CConnectLineType::GetcontrolPts(int index)
    {
        return static_cast<CConnectControlPoints*>(GetObjectByID(ID_PARA_ConnectControlPoints, index));
    }

}
