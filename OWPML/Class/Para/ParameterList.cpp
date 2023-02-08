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
#include "ParameterList.h"

namespace OWPML {

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CParam::CParam(unsigned int id) : CExtObject(id)
    {
    }

    CParam::~CParam()
    {
    }

    void CParam::InitMap(bool /*bRead*/)
    {
    }

    bool CParam::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);

        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CParam::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);

        return bres;
    }

    bool CParam::ReadNodeValue(LPCWSTR const value, const unsigned int length)
    {
        if (value && length > 0) {
            if (!m_val.empty()) {
                // 현재 사용하는 SAX 엔진의 경우,
                // value에서 '&' 문자가 들어있으면 잘라서 보내주는 동작을 하고 있다..

                // 우선은 기존 Value에 현재 Value를 추가한다.
                m_val.append(value, length);
            } else {
                m_val.assign(value, length);
            }

            return true;
        }

        return false;
    }


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CBooleanParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    CBooleanParam* CBooleanParam::Create()
    {
        return new CBooleanParam();
    }

    CBooleanParam::CBooleanParam() : CParam(ID_PARA_BooleanParam)
    {
    }

    CBooleanParam::~CBooleanParam()
    {
    }

    CBooleanParam* CBooleanParam::Clone()
    {
        CBooleanParam* clone = new CBooleanParam();

        clone->SetName(this->m_strName.c_str());
        clone->Setval(this->m_val.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CIntegerParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CIntegerParam* CIntegerParam::Create()
    {
        return new CIntegerParam(ID_PARA_IntegerParam);
    }

    CIntegerParam* CIntegerParam::CreateArg(unsigned int id)
    {
        return new CIntegerParam(id);
    }

    CIntegerParam* CIntegerParam::Clone()
    {
        CIntegerParam* clone = new CIntegerParam(ID_PARA_IntegerParam);

        clone->SetName(this->m_strName.c_str());
        clone->Setval(this->m_val.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CIntegerParam::CIntegerParam(unsigned int id) : CParam(id)
    {
    }

    CIntegerParam::~CIntegerParam()
    {
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CFloatParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CFloatParam* CFloatParam::Create()
    {
        return new CFloatParam();
    }

    CFloatParam::CFloatParam() : CParam(ID_PARA_FloatParam)
    {
    }

    CFloatParam* CFloatParam::Clone()
    {
        CFloatParam* clone = new CFloatParam();

        clone->SetName(this->m_strName.c_str());
        clone->Setval(this->m_val.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFloatParam::~CFloatParam()
    {
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CStringParam Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CStringParam* CStringParam::Create()
    {
        return new CStringParam();
    }

    CStringParam::CStringParam() : CParam(ID_PARA_StringParam)
    {
    }

    CStringParam::~CStringParam()
    {
    }

    CStringParam* CStringParam::Clone()
    {
        CStringParam* clone = new CStringParam();

        clone->SetName(this->m_strName.c_str());
        clone->Setval(this->m_val.c_str());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CParameterList Declaration 
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    OWPML_PARALIST_REDIRECT_FUNC(CParameterList, booleanParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, integerParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, unsignedintegerParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, bindataParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, floatParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, stringParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, listParam)
        OWPML_PARALIST_REDIRECT_FUNC(CParameterList, arrayParam)

        CParameterList* CParameterList::Create()
    {
        return new CParameterList(ID_PARA_ParameterList);
    }

    CParameterList* CParameterList::CreateArg(unsigned int id)
    {
        return new CParameterList(id);
    }

    CParameterList* CParameterList::Clone()
    {
        CParameterList* clone = new CParameterList();

        clone->SetCnt(this->m_uCnt);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CParameterList::CParameterList(unsigned int id) : CParam(id), m_uCnt(0)
    {
    }

    CParameterList::~CParameterList()
    {
    }

    void CParameterList::InitMap(bool bRead)
    {
        OWPML_BEGIN_IMPLEMENT_FUNCMAP(CParameterList)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(booleanParam, CBooleanParam, ID_PARA_BooleanParam)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(integerParam, CIntegerParam, ID_PARA_IntegerParam)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(unsignedintegerParam, CIntegerParam, ID_PARA_UnsignedIntegerParam)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(bindataParam, CIntegerParam, ID_PARA_BindataParam)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(floatParam, CFloatParam, ID_PARA_FloatParam)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(stringParam, CStringParam, ID_PARA_StringParam)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(listParam, CParameterList, ID_PARA_ParameterList)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(arrayParam, CParameterList, ID_PARA_ArrayParam)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CParameterList::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        m_uCnt = (UINT)GetChildCount();
        Util::CXMLAttConverter::SetAttribute(att, L"cnt", m_uCnt);
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CParameterList::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"cnt", m_uCnt);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CBooleanParam* CParameterList::SetbooleanParam(CBooleanParam* pbooleanParam)
    {
        CBooleanParam* booleanParam = pbooleanParam;
        if (booleanParam == NULL) {
            booleanParam = CBooleanParam::Create();
        }
        SetObject((CObject*)booleanParam);

        return booleanParam;
    }

    CBooleanParam* CParameterList::GetbooleanParam(int index)
    {
        return static_cast<CBooleanParam*>(GetObjectByID(ID_PARA_BooleanParam, index));
    }

    CIntegerParam* CParameterList::SetintegerParam(CIntegerParam* pintegerParam)
    {
        CIntegerParam* integerParam = pintegerParam;
        if (integerParam == NULL) {
            integerParam = CIntegerParam::CreateArg(ID_PARA_IntegerParam);
        }
        SetObject((CObject*)integerParam);

        return integerParam;
    }

    CIntegerParam* CParameterList::GetintegerParam(int index)
    {
        return static_cast<CIntegerParam*>(GetObjectByID(ID_PARA_IntegerParam, index));
    }

    CFloatParam* CParameterList::SetfloatParam(CFloatParam* pfloatParam)
    {
        CFloatParam* floatParam = pfloatParam;
        if (floatParam == NULL) {
            floatParam = CFloatParam::Create();
        }
        SetObject((CObject*)floatParam);

        return floatParam;
    }

    CFloatParam* CParameterList::GetfloatParam(int index)
    {
        return static_cast<CFloatParam*>(GetObjectByID(ID_PARA_FloatParam, index));
    }

    CStringParam* CParameterList::SetstringParam(CStringParam* pstringParam)
    {
        CStringParam* stringParam = pstringParam;
        if (stringParam == NULL) {
            stringParam = CStringParam::Create();
        }
        SetObject((CObject*)stringParam);

        return stringParam;
    }

    CStringParam* CParameterList::GetstringParam(int index)
    {
        return static_cast<CStringParam*>(GetObjectByID(ID_PARA_StringParam, index));
    }

    CParameterList* CParameterList::SetlistParam(CParameterList* plistParam)
    {
        CParameterList* listParam = plistParam;
        if (listParam == NULL) {
            listParam = CParameterList::Create();
        }
        SetObject((CObject*)listParam);

        return listParam;
    }

    CParameterList* CParameterList::GetlistParam(int index)
    {
        return static_cast<CParameterList*>(GetObjectByID(ID_PARA_ParameterList, index));
    }

    CParam* CParameterList::GetParamItem(LPCWSTR name, unsigned int id)
    {
        OWPML::Objectlist* pchildlist = GetObjectList();

        if (name && pchildlist && !pchildlist->empty()) {
            Objectlist::iterator iter;

            for (iter = pchildlist->begin(); iter != pchildlist->end(); ++iter) {
                if (id != 0) {
                    if ((*iter)->GetID() != id) {
                        continue;
                    }
                }

                CParam* pvalueobj = (CParam*)(*iter);
                if (_ustrcmp(pvalueobj->GetName(), name) == 0) {
                    return pvalueobj;
                }
            }
        }
        return NULL;
    }

}
