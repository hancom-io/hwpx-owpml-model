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
#include "textart.h"

namespace OWPML {

    CTextart* CTextart::Create()
    {
        return new CTextart();
    }

    CTextart* CTextart::Clone()
    {
        CTextart* clone = new CTextart();

        clone->SetText(this->m_strText.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CTextart::CTextart() : CAbstractDrawingObjectType(ID_PARA_Textart)
    {
    }

    CTextart::~CTextart()
    {
    }

    void CTextart::InitMap(bool bRead)
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

            OWPML_CORE_REDIRECT_FUNC(CTextart, pt0)
            OWPML_CORE_REDIRECT_FUNC(CTextart, pt1)
            OWPML_CORE_REDIRECT_FUNC(CTextart, pt2)
            OWPML_CORE_REDIRECT_FUNC(CTextart, pt3)
            OWPML_PARALIST_REDIRECT_FUNC(CTextart, textartPr)
            OWPML_PARALIST_REDIRECT_FUNC(CTextart, outline)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTextart)
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

            OWPML_CORE_ADD_REDIRECT_FUNC(pt0, CPointType, ID_CORE_PointType_Pt0)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt1, CPointType, ID_CORE_PointType_Pt1)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt2, CPointType, ID_CORE_PointType_Pt2)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt3, CPointType, ID_CORE_PointType_Pt3)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(textartPr, CTextartPr, ID_PARA_TextartPr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outline, CPOutline, ID_PARA_Outline)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTextart::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractDrawingObjectType::WriteElement(pCurObjName, serialize, att);
        Util::CXMLAttConverter::SetAttribute(att, L"text", m_strText);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTextart::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractDrawingObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"text", m_strText);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPointType* CTextart::Setpt0(CPointType* ppt0)
    {
        CPointType* pt0 = ppt0;
        if (pt0 == NULL) {
            pt0 = CPointType::CreateArg(ID_CORE_PointType_Pt0);
        }
        SetObject((CObject*)pt0);

        return pt0;
    }

    CPointType* CTextart::Getpt0(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt0, index));
    }

    CPointType* CTextart::Setpt1(CPointType* ppt1)
    {
        CPointType* pt1 = ppt1;
        if (pt1 == NULL) {
            pt1 = CPointType::CreateArg(ID_CORE_PointType_Pt1);
        }
        SetObject((CObject*)pt1);

        return pt1;
    }

    CPointType* CTextart::Getpt1(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt1, index));
    }

    CPointType* CTextart::Setpt2(CPointType* ppt2)
    {
        CPointType* pt2 = ppt2;
        if (pt2 == NULL) {
            pt2 = CPointType::CreateArg(ID_CORE_PointType_Pt2);
        }
        SetObject((CObject*)pt2);

        return pt2;
    }

    CPointType* CTextart::Getpt2(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt2, index));
    }

    CPointType* CTextart::Setpt3(CPointType* ppt3)
    {
        CPointType* pt3 = ppt3;
        if (pt3 == NULL) {
            pt3 = CPointType::CreateArg(ID_CORE_PointType_Pt3);
        }
        SetObject((CObject*)pt3);

        return pt3;
    }

    CPointType* CTextart::Getpt3(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType_Pt3, index));
    }

    CTextartPr* CTextart::SettextartPr(CTextartPr* ptextartPr)
    {
        CTextartPr* textartPr = ptextartPr;
        if (textartPr == NULL) {
            textartPr = CTextartPr::Create();
        }
        SetObject((CObject*)textartPr);

        return textartPr;
    }

    CTextartPr* CTextart::GettextartPr(int index)
    {
        return static_cast<CTextartPr*>(GetObjectByID(ID_PARA_TextartPr, index));
    }

    CPOutline* CTextart::Setoutline(CPOutline* poutline)
    {
        CPOutline* outline = poutline;
        if (outline == NULL) {
            outline = CPOutline::Create();
        }
        SetObject((CObject*)outline);

        return outline;
    }

    CPOutline* CTextart::Getoutline(int index)
    {
        return static_cast<CPOutline*>(GetObjectByID(ID_PARA_Outline, index));
    }

}
