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
#include "poutline.h"

namespace OWPML {

    CPOutline* CPOutline::Create()
    {
        return new CPOutline();
    }

    CPOutline* CPOutline::Clone()
    {
        CPOutline* clone = new CPOutline();

        clone->SetCnt(this->m_uCnt);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPOutline::CPOutline() : CExtObject(ID_PARA_Outline), m_uCnt(0)
    {
    }

    CPOutline::~CPOutline()
    {
    }

    void CPOutline::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CPOutline, pt)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPOutline)
            OWPML_CORE_ADD_REDIRECT_FUNC(pt, CPointType, ID_CORE_PointType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPOutline::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"cnt", m_uCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPOutline::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"cnt", m_uCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CPointType* CPOutline::Setpt(CPointType* ppt)
    {
        CPointType* pt = ppt;
        if (pt == NULL) {
            pt = CPointType::Create();
        }
        SetObject((CObject*)pt);

        return pt;
    }

    CPointType* CPOutline::Getpt(int index)
    {
        return static_cast<CPointType*>(GetObjectByID(ID_CORE_PointType, index));
    }

}
