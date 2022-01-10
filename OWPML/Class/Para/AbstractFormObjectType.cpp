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

namespace OWPML {

    CAbstractFormObjectType::CAbstractFormObjectType(UINT id) : CAbstractShapeObjectType(id), m_bTabStop(true), m_bEditable(true), m_nTabOrder(-1), m_bEnabled(true), m_bDrawFrame(true), m_bPrintable(true), m_uBorderTypeIDRef(0)
    {
    }

    CAbstractFormObjectType::~CAbstractFormObjectType()
    {
    }

    void CAbstractFormObjectType::InitMap(bool /*bRead*/)
    {
    }

    bool CAbstractFormObjectType::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"foreColor", m_cForeColor);
        Util::CXMLAttConverter::SetAttribute(att, L"backColor", m_cBackColor);
        Util::CXMLAttConverter::SetAttribute(att, L"groupName", m_strGroupName);
        Util::CXMLAttConverter::SetAttribute(att, L"tabStop", m_bTabStop);
        Util::CXMLAttConverter::SetAttribute(att, L"editable", m_bEditable);
        Util::CXMLAttConverter::SetAttribute(att, L"tabOrder", m_nTabOrder);
        Util::CXMLAttConverter::SetAttribute(att, L"enabled", m_bEnabled);
        Util::CXMLAttConverter::SetAttribute(att, L"borderTypeIDRef", m_uBorderTypeIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"drawFrame", m_bDrawFrame);
        Util::CXMLAttConverter::SetAttribute(att, L"printable", m_bPrintable);
        Util::CXMLAttConverter::SetAttribute(att, L"command", m_strCommand);

        return TRUE;
    }

    bool CAbstractFormObjectType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"foreColor", m_cForeColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"backColor", m_cBackColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"groupName", m_strGroupName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabStop", m_bTabStop);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"editable", m_bEditable);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"tabOrder", m_nTabOrder);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"enabled", m_bEnabled);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderTypeIDRef", m_uBorderTypeIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"drawFrame", m_bDrawFrame);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"printable", m_bPrintable);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"command", m_strCommand);

        return bres;
    }

    CFormCharPr* CAbstractFormObjectType::SetformCharPr(CFormCharPr* pformCharPr)
    {
        CFormCharPr* formCharPr = pformCharPr;
        if (formCharPr == NULL) {
            formCharPr = CFormCharPr::Create();
        }
        SetObject((CObject*)formCharPr);

        return formCharPr;
    }

    CFormCharPr* CAbstractFormObjectType::GetformCharPr(int index)
    {
        return static_cast<CFormCharPr*>(GetObjectByID(ID_PARA_FormCharPr, index));
    }

}
