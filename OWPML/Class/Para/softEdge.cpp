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
#include "softEdge.h"

namespace OWPML {


    CSoftEdge* CSoftEdge::Create()
    {
        return new CSoftEdge();
    }

    CSoftEdge* CSoftEdge::Clone()
    {
        CSoftEdge* clone = new CSoftEdge();

        clone->SetRadius(this->m_fRadius);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CSoftEdge::CSoftEdge() : CExtObject(ID_PARA_SoftEdge), m_fRadius(0.0)
    {
    }

    CSoftEdge::~CSoftEdge()
    {
    }

    void CSoftEdge::InitMap(bool /*bRead*/)
    {
    }

    bool CSoftEdge::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"radius", m_fRadius);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CSoftEdge::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"radius", m_fRadius);

        return bres;
    }

}
