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
#include "ColumnDefType.h"

namespace OWPML {

    CColumnDefType* CColumnDefType::Create()
    {
        return new CColumnDefType();
    }

    CColumnDefType* CColumnDefType::Clone()
    {
        CColumnDefType* clone = new CColumnDefType();

        clone->SetId(this->m_strId.c_str());
        clone->SetType((COLDEFTYPE)this->m_uType);
        clone->SetLayout((COLDEFLAYOUT)this->m_uLayout);
        clone->SetColCount(this->m_nColCount);
        clone->SetSameSz(this->m_bSameSz);
        clone->SetSameGap(this->m_uSameGap);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CColumnDefType::CColumnDefType() : CExtObject(ID_PARA_ColumnDefType), m_uType(CDT_NEWSPAPER), m_uLayout(CDL_LEFT), m_nColCount(1), m_bSameSz(false), m_uSameGap(0)
    {
    }

    CColumnDefType::~CColumnDefType()
    {
    }

    void CColumnDefType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CColumnDefType, colLine)
            OWPML_PARALIST_REDIRECT_FUNC(CColumnDefType, colSz)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CColumnDefType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(colLine, CColLine, ID_PARA_ColLine)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(colSz, CColSz, ID_PARA_ColSz)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CColumnDefType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_ColDefTypeList, m_uType);
        Util::CXMLAttConverter::SetAttribute(att, L"layout", g_ColDefLayoutList, m_uLayout);
        Util::CXMLAttConverter::SetAttribute(att, L"colCount", m_nColCount);
        Util::CXMLAttConverter::SetAttribute(att, L"sameSz", m_bSameSz);
        Util::CXMLAttConverter::SetAttribute(att, L"sameGap", m_uSameGap);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CColumnDefType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_ColDefTypeList, m_uType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"layout", g_ColDefLayoutList, m_uLayout);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"colCount", m_nColCount);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"sameSz", m_bSameSz);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"sameGap", m_uSameGap);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CColLine* CColumnDefType::SetcolLine(CColLine* pcolLine)
    {
        CColLine* colLine = pcolLine;
        if (colLine == NULL) {
            colLine = CColLine::Create();
        }
        SetObject((CObject*)colLine);

        return colLine;
    }

    CColLine* CColumnDefType::GetcolLine(int index)
    {
        return static_cast<CColLine*>(GetObjectByID(ID_PARA_ColLine, index));
    }

    CColSz* CColumnDefType::SetcolSz(CColSz* pcolSz)
    {
        CColSz* colSz = pcolSz;
        if (colSz == NULL) {
            colSz = CColSz::Create();
        }
        SetObject((CObject*)colSz);

        return colSz;
    }

    CColSz* CColumnDefType::GetcolSz(int index)
    {
        return static_cast<CColSz*>(GetObjectByID(ID_PARA_ColSz, index));
    }

}
