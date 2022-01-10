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
#include "AutoNumNewNumType.h"

namespace OWPML {

    CAutoNumNewNumType* CAutoNumNewNumType::Create()
    {
        return new CAutoNumNewNumType(ID_PARA_AutoNumType);
    }

    CAutoNumNewNumType* CAutoNumNewNumType::CreateArg(UINT id)
    {
        return new CAutoNumNewNumType(id);
    }

    CAutoNumNewNumType* CAutoNumNewNumType::Clone()
    {
        CAutoNumNewNumType* clone = new CAutoNumNewNumType(ID_PARA_AutoNumType);

        clone->SetNum(this->m_nNum);
        clone->SetNumType((AUTONUMTYPE)this->m_uNumType);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CAutoNumNewNumType::CAutoNumNewNumType(UINT id) : CExtObject(id), m_nNum(1), m_uNumType(ANT_PAGE)
    {
    }

    CAutoNumNewNumType::~CAutoNumNewNumType()
    {
    }

    void CAutoNumNewNumType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CAutoNumNewNumType, autoNumFormat)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CAutoNumNewNumType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(autoNumFormat, CAutoNumFormatType, ID_PARA_AutoNumFormatType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CAutoNumNewNumType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"num", m_nNum);
        Util::CXMLAttConverter::SetAttribute(att, L"numType", g_AutoNumTypeList, m_uNumType);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAutoNumNewNumType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"num", m_nNum);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"numType", g_AutoNumTypeList, m_uNumType);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CAutoNumFormatType* CAutoNumNewNumType::SetautoNumFormat(CAutoNumFormatType* pautoNumFormat)
    {
        CAutoNumFormatType* autoNumFormat = pautoNumFormat;
        if (autoNumFormat == NULL) {
            autoNumFormat = CAutoNumFormatType::Create();
        }
        SetObject((CObject*)autoNumFormat);

        return autoNumFormat;
    }

    CAutoNumFormatType* CAutoNumNewNumType::GetautoNumFormat(int index)
    {
        return static_cast<CAutoNumFormatType*>(GetObjectByID(ID_PARA_AutoNumFormatType, index));
    }

}
