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
#include "dutmal.h"

namespace OWPML {

    CDutmal* CDutmal::Create()
    {
        return new CDutmal();
    }

    CDutmal* CDutmal::Clone()
    {
        CDutmal* clone = new CDutmal();

        clone->SetPosType((DUTMALPOSTYPE)this->m_uPosType);
        clone->SetSzRatio(this->m_uSzRatio);
        clone->SetOption(this->m_uOption);
        clone->SetStyleIDRef(this->m_uStyleIDRef);
        clone->SetAlign((DUTMALALIGNTYPE)this->m_uAlign);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CDutmal::CDutmal() : CExtObject(ID_PARA_Dutmal), m_uPosType(DPT_TOP), m_uSzRatio(0), m_uOption(0), m_uAlign(DAT_CENTER), m_uStyleIDRef(0)
    {
    }

    CDutmal::~CDutmal()
    {
    }

    void CDutmal::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CDutmal, mainText)
            OWPML_PARALIST_REDIRECT_FUNC(CDutmal, subText)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CDutmal)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(mainText, CMainText, ID_PARA_MainText)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subText, CSubText, ID_PARA_SubText)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CDutmal::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"posType", g_DutmalPosList, m_uPosType);
        Util::CXMLAttConverter::SetAttribute(att, L"szRatio", m_uSzRatio);
        Util::CXMLAttConverter::SetAttribute(att, L"option", m_uOption);
        Util::CXMLAttConverter::SetAttribute(att, L"styleIDRef", m_uStyleIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"align", g_DutmalAlignList, m_uAlign);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDutmal::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"posType", g_DutmalPosList, m_uPosType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"szRatio", m_uSzRatio);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"option", m_uOption);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"styleIDRef", m_uStyleIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"align", g_DutmalAlignList, m_uAlign);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CMainText* CDutmal::SetmainText(CMainText* pmainText)
    {
        CMainText* mainText = pmainText;
        if (mainText == NULL) {
            mainText = CMainText::Create();
        }
        SetObject((CObject*)mainText);

        return mainText;
    }

    CMainText* CDutmal::GetmainText(int index)
    {
        return static_cast<CMainText*>(GetObjectByID(ID_PARA_MainText, index));
    }

    CSubText* CDutmal::SetsubText(CSubText* psubText)
    {
        CSubText* subText = psubText;
        if (subText == NULL) {
            subText = CSubText::Create();
        }
        SetObject((CObject*)subText);

        return subText;
    }

    CSubText* CDutmal::GetsubText(int index)
    {
        return static_cast<CSubText*>(GetObjectByID(ID_PARA_SubText, index));
    }

}
