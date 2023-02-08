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
#include "AbstractDiffDataType.h"
#include "DeleteType.h"

namespace OWPML {

    CDeleteType* CDeleteType::Create()
    {
        return new CDeleteType();
    }

    CDeleteType::CDeleteType() : CAbstractDiffDataType(ID_HISTORY_DeleteType)
    {
    }

    CDeleteType::~CDeleteType()
    {
    }

    void CDeleteType::InitMap(bool bRead)
    {
        OWPML_HISTORY_REDIRECT_FUNC(CDeleteType, any)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CDeleteType)
            OWPML_HISTORY_ADD_REDIRECT_FUNC(any, CAnyType, ID_HISTORY_AnyType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CDeleteType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (m_strOPID.length() > 0)
            Util::CXMLAttConverter::SetAttribute(att, L"OPID", m_strOPID);

        CAbstractDiffDataType::WriteElement(pCurObjName, serialize, att);
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDeleteType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        Util::CXMLAttConverter::GetAttribute(att, L"OPID", m_strOPID);

        bres &= CAbstractDiffDataType::ReadAttribute(att);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    bool CDeleteType::ReadNodeValue(LPCWSTR const value, const unsigned int length)
    {
        hncstd::wstring strvalue(value, length);

        Setval(strvalue.c_str());
        return TRUE;
    }

    void CDeleteType::Setval(LPCWSTR val)
    {
        SetObject((CObject*)new CAnyType(val));
    }

    LPCWSTR CDeleteType::Getval(void)
    {
        CAnyType* anytype = static_cast<CAnyType*>(GetObjectByID(ID_HISTORY_AnyType, 0));
        if (anytype)
            return anytype->Getval();
        else
            return NULL;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CAnyType
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    CAnyType::CAnyType(LPCWSTR val) : CStringValueObject(ID_HISTORY_AnyType)
    {
        Setval(val);
    }

    CAnyType::~CAnyType()
    {
    }

    void CAnyType::InitMap(bool /*bRead*/)
    {
    }

    bool CAnyType::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* serialize, CAttribute* /*att*/)
    {
        serialize->WriteBuffer(Getval(), _ustrlen(Getval()));
        return TRUE;
    }

    bool CAnyType::ReadAttribute(CAttribute* /*att*/)
    {
        return TRUE;
    }

}
