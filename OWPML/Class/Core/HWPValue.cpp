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
#include "HWPValue.h"

namespace OWPML {

    CHWPValue* CHWPValue::Create()
    {
        return new CHWPValue(ID_CORE_HWPValue);
    }

    CHWPValue* CHWPValue::CreateArg(UINT id)
    {
        return new CHWPValue(id);
    }

    CHWPValue* CHWPValue::Clone()
    {
        CHWPValue* clone = new CHWPValue();

        clone->SetValue(this->m_nValue);
        clone->SetUnit((UINTVALUETYPE)this->m_uUnit);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CHWPValue::CHWPValue(UINT id) : CExtObject(id), m_nValue(-1), m_uUnit(UVT_HWPUNIT)
    {
    }

    CHWPValue::~CHWPValue()
    {
    }

    void CHWPValue::InitMap(bool /*bRead*/)
    {
    }

    bool CHWPValue::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"value", m_nValue);
        Util::CXMLAttConverter::SetAttribute(att, L"unit", g_UnitValueList, m_uUnit);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHWPValue::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"value", m_nValue);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"unit", g_UnitValueList, m_uUnit);

        return bres;
    }

}
