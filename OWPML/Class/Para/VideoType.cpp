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
#include "VideoType.h"

namespace OWPML {

    CVideoType* CVideoType::Create()
    {
        return new CVideoType();
    }

    CVideoType::CVideoType() : CAbstractShapeComponentType(ID_PARA_VideoType), m_uVideoType(VT_LOCAL)
    {
    }

    CVideoType::~CVideoType()
    {
    }

    void CVideoType::InitMap(bool bRead)
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
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CVideoType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeComponentType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"videotype", g_VideoTypeList, m_uVideoType);
        Util::CXMLAttConverter::SetAttribute(att, L"fileIDRef", m_strFileID);
        Util::CXMLAttConverter::SetAttribute(att, L"imageIDRef", m_strImageID);
        Util::CXMLAttConverter::SetAttribute(att, L"tag", m_strTag);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CVideoType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeComponentType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"videotype", g_VideoTypeList, m_uVideoType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fileIDRef", m_strFileID);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"imageIDRef", m_strImageID);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tag", m_strTag);
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }


}
