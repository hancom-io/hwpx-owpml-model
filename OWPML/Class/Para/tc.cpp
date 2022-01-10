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
#include "tc.h"

namespace OWPML {

    CTc* CTc::Create()
    {
        return new CTc();
    }

    CTc* CTc::Clone()
    {
        CTc* clone = new CTc();

        clone->SetName(this->m_strName.c_str());
        clone->SetHeader(this->m_bHeader);
        clone->SetHasMargin(this->m_bHasMargin);
        clone->SetProtect(this->m_bProtect);
        clone->SetEditable(this->m_bEditable);
        clone->SetDirty(this->m_bDirty);
        clone->SetBorderFillIDRef(this->m_uBorderFillIDRef);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CTc::CTc() : CExtObject(ID_PARA_Tc), m_bHeader(false), m_bHasMargin(false), m_bProtect(false), m_bEditable(false), m_bDirty(false)
    {
    }

    CTc::~CTc()
    {
    }

    void CTc::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CTc, cellAddr)
            OWPML_PARALIST_REDIRECT_FUNC(CTc, cellSpan)
            OWPML_PARALIST_REDIRECT_FUNC(CTc, cellSz)
            OWPML_PARALIST_REDIRECT_FUNC(CTc, cellMargin)
            OWPML_PARALIST_REDIRECT_FUNC(CTc, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTc)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cellAddr, CCellAddr, ID_PARA_CellAddr)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cellSpan, CCellSpan, ID_PARA_CellSpan)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cellSz, CCellSz, ID_PARA_CellSz)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(cellMargin, CCellMargin, ID_PARA_CellMargin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTc::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"header", m_bHeader);
        Util::CXMLAttConverter::SetAttribute(att, L"hasMargin", m_bHasMargin);
        Util::CXMLAttConverter::SetAttribute(att, L"protect", m_bProtect);
        Util::CXMLAttConverter::SetAttribute(att, L"editable", m_bEditable);
        Util::CXMLAttConverter::SetAttribute(att, L"dirty", m_bDirty);
        Util::CXMLAttConverter::SetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTc::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"header", m_bHeader);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hasMargin", m_bHasMargin);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"protect", m_bProtect);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"editable", m_bEditable);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"dirty", m_bDirty);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CCellAddr* CTc::SetcellAddr(CCellAddr* pcellAddr)
    {
        CCellAddr* cellAddr = pcellAddr;
        if (cellAddr == NULL) {
            cellAddr = CCellAddr::Create();
        }
        SetObject((CObject*)cellAddr);

        return cellAddr;
    }

    CCellAddr* CTc::GetcellAddr(int index)
    {
        return static_cast<CCellAddr*>(GetObjectByID(ID_PARA_CellAddr, index));
    }

    CCellSpan* CTc::SetcellSpan(CCellSpan* pcellSpan)
    {
        CCellSpan* cellSpan = pcellSpan;
        if (cellSpan == NULL) {
            cellSpan = CCellSpan::Create();
        }
        SetObject((CObject*)cellSpan);

        return cellSpan;
    }

    CCellSpan* CTc::GetcellSpan(int index)
    {
        return static_cast<CCellSpan*>(GetObjectByID(ID_PARA_CellSpan, index));
    }

    CCellSz* CTc::SetcellSz(CCellSz* pcellSz)
    {
        CCellSz* cellSz = pcellSz;
        if (cellSz == NULL) {
            cellSz = CCellSz::Create();
        }
        SetObject((CObject*)cellSz);

        return cellSz;
    }

    CCellSz* CTc::GetcellSz(int index)
    {
        return static_cast<CCellSz*>(GetObjectByID(ID_PARA_CellSz, index));
    }

    CCellMargin* CTc::SetcellMargin(CCellMargin* pcellMargin)
    {
        CCellMargin* cellMargin = pcellMargin;
        if (cellMargin == NULL) {
            cellMargin = CCellMargin::Create();
        }
        SetObject((CObject*)cellMargin);

        return cellMargin;
    }

    CCellMargin* CTc::GetcellMargin(int index)
    {
        return static_cast<CCellMargin*>(GetObjectByID(ID_PARA_CellMargin, index));
    }

    CParaListType* CTc::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CTc::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
