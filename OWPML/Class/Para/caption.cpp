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
#include "caption.h"

namespace OWPML {

    CCaption* CCaption::Create()
    {
        return new CCaption();
    }

    CCaption* CCaption::Clone()
    {
        CCaption* clone = new CCaption();

        clone->SetSide((CAPTIONSIDETYPE)this->m_uSide);
        clone->SetFullSz(this->m_bFullSz);
        clone->SetWidth(this->m_nWidth);
        clone->SetGap(this->m_nGap);
        clone->SetLastWidth(this->m_uLastWidth);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCaption::CCaption() : CExtObject(ID_PARA_Caption), m_uSide(CST_LEFT), m_bFullSz(false), m_nWidth(-1), m_nGap(850), m_uLastWidth(0)
    {
    }

    CCaption::~CCaption()
    {
    }

    void CCaption::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CCaption, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCaption)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCaption::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"side", g_CaptionSideList, m_uSide);
        Util::CXMLAttConverter::SetAttribute(att, L"fullSz", m_bFullSz);
        Util::CXMLAttConverter::SetAttribute(att, L"width", m_nWidth);
        Util::CXMLAttConverter::SetAttribute(att, L"gap", m_nGap);
        Util::CXMLAttConverter::SetAttribute(att, L"lastWidth", m_uLastWidth);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCaption::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"side", g_CaptionSideList, m_uSide);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"fullSz", m_bFullSz);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"width", m_nWidth);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"gap", m_nGap);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lastWidth", m_uLastWidth);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaListType* CCaption::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CCaption::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
