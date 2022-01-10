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
#include "PType.h"

namespace OWPML {

    CLineSeg* CLineSeg::Create()
    {
        return new CLineSeg();
    }

    CLineSeg* CLineSeg::Clone()
    {
        CLineSeg* clone = new CLineSeg();

        clone->SetTextPos(this->m_TextPos);
        clone->SetVertPos(this->m_VertPos);
        clone->SetVertSize(this->m_VertSize);
        clone->SetTextHeight(this->m_TextHeight);
        clone->SetBaseLine(this->m_BaseLine);
        clone->SetSpacing(this->m_Spacing);
        clone->SetHorzPos(this->m_HorzPos);
        clone->SetHorzSize(this->m_HorzSize);
        clone->SetFlags(this->m_Flags);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CLineSeg::CLineSeg() : CExtObject(ID_PARA_LineSeg)
    {
    }

    CLineSeg::~CLineSeg()
    {
    }

    void CLineSeg::InitMap(bool /*bRead*/)
    {
    }

    bool CLineSeg::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"textpos", m_TextPos);
        Util::CXMLAttConverter::SetAttribute(att, L"vertpos", m_VertPos);
        Util::CXMLAttConverter::SetAttribute(att, L"vertsize", m_VertSize);
        Util::CXMLAttConverter::SetAttribute(att, L"textheight", m_TextHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"baseline", m_BaseLine);
        Util::CXMLAttConverter::SetAttribute(att, L"spacing", m_Spacing);
        Util::CXMLAttConverter::SetAttribute(att, L"horzpos", m_HorzPos);
        Util::CXMLAttConverter::SetAttribute(att, L"horzsize", m_HorzSize);
        Util::CXMLAttConverter::SetAttribute(att, L"flags", m_Flags);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLineSeg::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textpos", m_TextPos);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertpos", m_VertPos);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"vertsize", m_VertSize);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textheight", m_TextHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"baseline", m_BaseLine);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"spacing", m_Spacing);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horzpos", m_HorzPos);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"horzsize", m_HorzSize);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"flags", m_Flags);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }





    CLineSegArray* CLineSegArray::Create()
    {
        return new CLineSegArray();
    }

    CLineSegArray* CLineSegArray::Clone()
    {
        CLineSegArray* clone = new CLineSegArray();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CLineSegArray::CLineSegArray() : CExtObject(ID_PARA_LineSegArray)
    {
    }

    CLineSegArray::~CLineSegArray()
    {
    }

    void CLineSegArray::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CLineSeg, lineseg)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CLineSegArray)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(lineseg, CLineSeg, ID_PARA_LineSeg)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CLineSegArray::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLineSegArray::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CLineSeg* CLineSegArray::SetLineSeg(CLineSeg* plineseg)
    {
        CLineSeg* lineseg = plineseg;
        if (lineseg == NULL) {
            lineseg = CLineSeg::Create();
        }
        SetObject((CObject*)lineseg);

        return lineseg;
    }

    CLineSeg* CLineSegArray::GetLineSeg(int index)
    {
        return static_cast<CLineSeg*>(GetObjectByID(ID_PARA_LineSeg, index));
    }


    /////////////////////////////////////////////////////////////////////////////
    // CPType
    /////////////////////////////////////////////////////////////////////////////


    CPType* CPType::Create()
    {
        return new CPType();
    }

    CPType* CPType::Clone()
    {
        CPType* clone = new CPType();

        clone->SetId(this->m_uId);
        clone->SetParaPrIDRef(this->m_uParaPrIDRef);
        clone->SetStyleIDRef(this->m_uStyleIDRef);
        clone->SetPageBreak(this->m_bPageBreak);
        clone->SetColumnBreak(this->m_bColumnBreak);
        clone->SetMerged(this->m_bMerged);
        clone->SetTrackchageID(this->m_paraTCId);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CPType::CPType() : CExtObject(ID_PARA_PType), m_bPageBreak(false), m_bColumnBreak(false)
        , m_uId((UINT)-1), m_uParaPrIDRef((UINT)-1), m_uStyleIDRef((UINT)-1), m_bMerged(false), m_paraTCId(0)
    {
    }

    CPType::~CPType()
    {
    }

    void CPType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CPType, run)
            OWPML_PARALIST_REDIRECT_FUNC(CPType, linesegarray)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(run, CRunType, ID_PARA_RunType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(linesegarray, CLineSegArray, ID_PARA_LineSegArray)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"paraPrIDRef", m_uParaPrIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"styleIDRef", m_uStyleIDRef);
        Util::CXMLAttConverter::SetAttribute(att, L"pageBreak", m_bPageBreak);
        Util::CXMLAttConverter::SetAttribute(att, L"columnBreak", m_bColumnBreak);
        Util::CXMLAttConverter::SetAttribute(att, L"merged", m_bMerged);
        if (m_paraTCId)
            Util::CXMLAttConverter::SetAttribute(att, L"paraTcId", m_paraTCId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"paraPrIDRef", m_uParaPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"styleIDRef", m_uStyleIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageBreak", m_bPageBreak);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"columnBreak", m_bColumnBreak);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"merged", m_bMerged);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"paraTcId", m_paraTCId);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }


    CRunType* CPType::Setrun(CRunType* prun)
    {
        CRunType* run = prun;
        if (run == NULL) {
            run = CRunType::Create();
        }
        SetObject((CObject*)run);

        return run;
    }

    CRunType* CPType::Getrun(int index)
    {
        return static_cast<CRunType*>(GetObjectByID(ID_PARA_RunType, index));
    }


    CLineSegArray* CPType::Setlinesegarray(CLineSegArray* psegarray)
    {
        CLineSegArray* segarray = psegarray;
        if (segarray == NULL) {
            segarray = CLineSegArray::Create();
        }
        SetObject((CObject*)segarray);

        return segarray;
    }

    CLineSegArray* CPType::Getlinesegarray(int index)
    {
        return static_cast<CLineSegArray*>(GetObjectByID(ID_PARA_LineSegArray, index));
    }

}
