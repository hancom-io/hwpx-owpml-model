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
#include "compose.h"

namespace OWPML {

    CCompose* CCompose::Create()
    {
        return new CCompose();
    }

    CCompose* CCompose::Clone()
    {
        CCompose* clone = new CCompose();

        clone->SetCircleType((SHAPECIRCLETYPE)this->m_uCircleType);
        clone->SetCharSz(this->m_nCharSz);
        clone->SetComposeType((COMPOSETYPE)this->m_uComposeType);
        clone->SetCharPrCnt(this->m_uCharPrCnt);
        clone->SetComposeText(this->m_strText.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCompose::CCompose() : CExtObject(ID_PARA_Compose), m_uCircleType(SCT_SHAPE_CIRCLE), m_nCharSz(-4), m_uCharPrCnt(0), m_uComposeType(0)
    {
    }

    CCompose::~CCompose()
    {
    }

    void CCompose::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CCompose, charPr)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCompose)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(charPr, CCharPr, ID_PARA_CharPr)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCompose::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"circleType", g_ShapeCircleList, m_uCircleType);
        Util::CXMLAttConverter::SetAttribute(att, L"charSz", m_nCharSz);
        Util::CXMLAttConverter::SetAttribute(att, L"composeType", g_ComposeList, m_uComposeType);
        Util::CXMLAttConverter::SetAttribute(att, L"charPrCnt", m_uCharPrCnt);
        Util::CXMLAttConverter::SetAttribute(att, L"composeText", m_strText);
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCompose::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"circleType", g_ShapeCircleList, m_uCircleType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charSz", m_nCharSz);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"composeType", g_ComposeList, m_uComposeType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charPrCnt", m_uCharPrCnt);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"composeText", m_strText);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CCharPr* CCompose::SetcharPr(CCharPr* pcharPr)
    {
        CCharPr* charPr = pcharPr;
        if (charPr == NULL) {
            charPr = CCharPr::Create();
        }
        SetObject((CObject*)charPr);

        return charPr;
    }

    CCharPr* CCompose::GetcharPr(int index)
    {
        return static_cast<CCharPr*>(GetObjectByID(ID_PARA_CharPr, index));
    }

}
