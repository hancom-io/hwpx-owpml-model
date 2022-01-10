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
#include "cellzone.h"

namespace OWPML {


    CCellzone* CCellzone::Create()
    {
        return new CCellzone();
    }

    CCellzone::CCellzone() : CExtObject(ID_PARA_Cellzone), m_uStartRowAddr(0), m_uStartColAddr(0), m_uEndRowAddr(0), m_uEndColAddr(0), m_uBorderFillIDRef(0)
    {
    }

    CCellzone::~CCellzone()
    {
    }

    CCellzone* CCellzone::Clone()
    {
        CCellzone* clone = new CCellzone();

        clone->SetStartRowAddr(this->m_uStartRowAddr);
        clone->SetStartColAddr(this->m_uStartColAddr);
        clone->SetEndRowAddr(this->m_uEndRowAddr);
        clone->SetEndColAddr(this->m_uEndColAddr);
        clone->SetBorderFillIDRef(this->m_uBorderFillIDRef);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    void CCellzone::InitMap(bool /*bRead*/)
    {
    }

    bool CCellzone::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"startRowAddr", m_uStartRowAddr);
        Util::CXMLAttConverter::SetAttribute(att, L"startColAddr", m_uStartColAddr);
        Util::CXMLAttConverter::SetAttribute(att, L"endRowAddr", m_uEndRowAddr);
        Util::CXMLAttConverter::SetAttribute(att, L"endColAddr", m_uEndColAddr);
        Util::CXMLAttConverter::SetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCellzone::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"startRowAddr", m_uStartRowAddr);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"startColAddr", m_uStartColAddr);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"endRowAddr", m_uEndRowAddr);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"endColAddr", m_uEndColAddr);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);

        return bres;
    }

}
