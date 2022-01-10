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

#include "OLEType.h"

namespace OWPML {

    COLEType* COLEType::Create()
    {
        return new COLEType();
    }

    COLEType* COLEType::Clone()
    {
        COLEType* clone = new COLEType();

        clone->SetObjectType((OLEOBJECTTYPE)this->m_uObjectType);
        clone->SetBinaryItemIDRef(this->m_strBinaryItemIDRef.c_str());
        clone->SetHasMoniker(this->m_bHasMoniker);
        clone->SetDrawAspect((OLEDRAWASPECTTYPE)this->m_uDrawAspect);
        clone->SetEqBaseLine(this->m_uEqBaseLine);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    COLEType::COLEType() : CAbstractShapeComponentType(ID_PARA_OLEType), m_bHasMoniker(false), m_uEqBaseLine(85)
    {
    }

    COLEType::~COLEType()
    {
    }

    void COLEType::InitMap(bool bRead)
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

            OWPML_CORE_REDIRECT_FUNC(COLEType, extent)
            OWPML_PARALIST_REDIRECT_FUNC(COLEType, lineShape)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(COLEType)
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

            OWPML_CORE_ADD_REDIRECT_FUNC(extent, CPointType, ID_CORE_PointType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(lineShape, CLineShapeType, ID_PARA_LineShapeType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool COLEType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeComponentType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"objectType", g_OleObjectList, m_uObjectType);
        Util::CXMLAttConverter::SetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"hasMoniker", m_bHasMoniker);
        Util::CXMLAttConverter::SetAttribute(att, L"drawAspect", g_OleDrawAspectList, m_uDrawAspect);
        Util::CXMLAttConverter::SetAttribute(att, L"eqBaseLine", m_uEqBaseLine);
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool COLEType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeComponentType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"objectType", g_OleObjectList, m_uObjectType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"binaryItemIDRef", m_strBinaryItemIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hasMoniker", m_bHasMoniker);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"drawAspect", g_OleDrawAspectList, m_uDrawAspect);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"eqBaseLine", m_uEqBaseLine);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPointType* COLEType::Setextent(CPointType* pextent)
    {
        CPointType* extent = pextent;
        if (extent == NULL) {
            extent = CPointType::Create();
        }
        SetObject((CObject*)extent);

        return extent;
    }

    CPointType* COLEType::Getextent(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType, index));
    }

    CLineShapeType* COLEType::SetlineShape(CLineShapeType* plineShape)
    {
        CLineShapeType* lineShape = plineShape;
        if (lineShape == NULL) {
            lineShape = CLineShapeType::Create();
        }
        SetObject((CObject*)lineShape);

        return lineShape;
    }

    CLineShapeType* COLEType::GetlineShape(int index)
    {
        return static_cast<CLineShapeType*>(GetObjectByID(ID_PARA_LineShapeType, index));
    }

}
