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
#include "NumberingType.h"

namespace OWPML {

    CNumberingType* CNumberingType::Create()
    {
        return new CNumberingType();
    }

    CNumberingType::CNumberingType() : CExtObject(ID_HEAD_NumberingType), m_nStart(1), m_uId(0)
    {
    }

    CNumberingType::~CNumberingType()
    {
    }

    void CNumberingType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CNumberingType, paraHead)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CNumberingType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(paraHead, CParaHeadType2, ID_HEAD_ParaHeadType2)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CNumberingType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"start", m_nStart);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNumberingType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"start", m_nStart);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaHeadType2* CNumberingType::SetparaHead(CParaHeadType2* pparaHead)
    {
        CParaHeadType2* paraHead = pparaHead;
        if (paraHead == NULL) {
            paraHead = CParaHeadType2::Create();
        }
        SetObject((CObject*)paraHead);

        return paraHead;
    }

    CParaHeadType2* CNumberingType::GetparaHead(int index)
    {
        return static_cast<CParaHeadType2*>(GetObjectByID(ID_HEAD_ParaHeadType2, index));
    }

}
