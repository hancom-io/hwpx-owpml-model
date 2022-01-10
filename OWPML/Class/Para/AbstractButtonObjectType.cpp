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
#include "AbstractButtonObjectType.h"

namespace OWPML {

    CAbstractButtonObjectType* CAbstractButtonObjectType::Create()
    {
        return new CAbstractButtonObjectType(ID_PARA_AbstractButtonObjectType);
    }

    CAbstractButtonObjectType* CAbstractButtonObjectType::CreateArg(UINT id)
    {
        return new CAbstractButtonObjectType(id);
    }

    CAbstractButtonObjectType::CAbstractButtonObjectType(UINT id) : CAbstractFormObjectType(id)
    {
    }

    CAbstractButtonObjectType::~CAbstractButtonObjectType()
    {
    }

    void CAbstractButtonObjectType::InitMap(bool bRead)
    {
        // CAbstractShapeObjectType
        OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, sz)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, pos)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, outMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, caption)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, shapeComment)
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, parameterset)
            // metatag & json
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractShapeObjectType, metaTag)

            // CAbstractFormObjectType
            OWPML_PARALIST_REDIRECT_FUNC(CAbstractFormObjectType, formCharPr)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CAbstractButtonObjectType)
            // CAbstractShapeObjectType
            OWPML_PARALIST_ADD_REDIRECT_FUNC(sz, CSz, ID_PARA_Sz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CASOPos, ID_PARA_ASOPos)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outMargin, COutMargin, ID_PARA_OutMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(caption, CCaption, ID_PARA_Caption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shapeComment, CShapeComment, ID_PARA_ShapeComment)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)
            // CAbstractFormObjectType
            OWPML_PARALIST_ADD_REDIRECT_FUNC(formCharPr, CFormCharPr, ID_PARA_FormCharPr)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CAbstractButtonObjectType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"caption", m_strCaption);
        Util::CXMLAttConverter::SetAttribute(att, L"value", g_ButtonValueList, m_uValue);
        Util::CXMLAttConverter::SetAttribute(att, L"radioGroupName", m_strRadioGroupName);
        Util::CXMLAttConverter::SetAttribute(att, L"triState", m_bTriState);
        Util::CXMLAttConverter::SetAttribute(att, L"backStyle", g_ButtonbackStyleList, m_uBackStyle);

        CAbstractFormObjectType::WriteElement(pCurObjName, serialize, att);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAbstractButtonObjectType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractFormObjectType::ReadAttribute(att);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"caption", m_strCaption);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", g_ButtonValueList, m_uValue);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"radioGroupName", m_strRadioGroupName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"triState", m_bTriState);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"backStyle", g_ButtonbackStyleList, m_uBackStyle);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

}
