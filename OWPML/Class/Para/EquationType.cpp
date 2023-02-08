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
#include "EquationType.h"

namespace OWPML {

    CEquationType* CEquationType::Create()
    {
        return new CEquationType();
    }

    CEquationType* CEquationType::Clone()
    {
        CEquationType* clone = new CEquationType();

        clone->SetVersion(this->m_strVersion.c_str());
        clone->SetBaseLine(this->m_uBaseLine);
        clone->SetTextColor(this->m_cTextColor);
        clone->SetBaseUnit(this->m_uBaseUnit);
        clone->SetLineMode((EQUATIONLINETYPE)this->m_uLineMode);
        clone->SetFontName(this->m_strFontName.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEquationType::CEquationType() : CAbstractShapeObjectType(ID_PARA_EquationType), m_strVersion(L""), m_uBaseLine(85), m_cTextColor(0x000000), m_uBaseUnit(1000), m_uLineMode(ELT_CHAR), \
        m_strFontName(L"")
    {

    }

    CEquationType::~CEquationType()
    {
    }

    void CEquationType::InitMap(bool bRead)
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

            OWPML_PARALIST_REDIRECT_FUNC(CEquationType, script)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEquationType)
            // "AbstractShapeObjectType.h"
            OWPML_PARALIST_ADD_REDIRECT_FUNC(sz, CSz, ID_PARA_Sz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pos, CASOPos, ID_PARA_ASOPos)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(outMargin, COutMargin, ID_PARA_OutMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(caption, CCaption, ID_PARA_Caption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(shapeComment, CShapeComment, ID_PARA_ShapeComment)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(parameterset, CParameterList, ID_PARA_ParameterList)
            // metatag & json
            OWPML_PARALIST_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)

            OWPML_PARALIST_ADD_REDIRECT_FUNC(script, CScript, ID_PARA_Script)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEquationType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeObjectType::WriteElement(pCurObjName, serialize, att);

        Util::CXMLAttConverter::SetAttribute(att, L"version", m_strVersion);
        Util::CXMLAttConverter::SetAttribute(att, L"baseLine", m_uBaseLine);
        Util::CXMLAttConverter::SetAttribute(att, L"textColor", m_cTextColor);
        Util::CXMLAttConverter::SetAttribute(att, L"baseUnit", m_uBaseUnit);
        Util::CXMLAttConverter::SetAttribute(att, L"lineMode", g_EquationLineList, m_uLineMode);
        Util::CXMLAttConverter::SetAttribute(att, L"font", m_strFontName);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEquationType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeObjectType::ReadAttribute(att);

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"version", m_strVersion);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"baseLine", m_uBaseLine);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textColor", m_cTextColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"baseUnit", m_uBaseUnit);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineMode", g_EquationLineList, m_uLineMode);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"font", m_strFontName);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CScript* CEquationType::Setscript(CScript* pscript)
    {
        CScript* script = pscript;
        if (script == NULL) {
            script = CScript::Create();
        }
        SetObject((CObject*)script);

        return script;
    }

    CScript* CEquationType::Getscript(int index)
    {
        return static_cast<CScript*>(GetObjectByID(ID_PARA_Script, index));
    }

}
