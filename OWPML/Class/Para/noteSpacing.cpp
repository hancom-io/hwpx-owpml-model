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
#include "noteSpacing.h"

namespace OWPML {


    CNoteSpacing* CNoteSpacing::Create()
    {
        return new CNoteSpacing();
    }

    CNoteSpacing* CNoteSpacing::Clone()
    {
        CNoteSpacing* clone = new CNoteSpacing();

        clone->SetBetweenNotes(this->m_uBetweenNotes);
        clone->SetBelowLine(this->m_uBelowLine);
        clone->SetAboveLine(this->m_uAboveLine);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CNoteSpacing::CNoteSpacing() : CExtObject(ID_PARA_NoteSpacing), m_uBetweenNotes(850), m_uBelowLine(567), m_uAboveLine(567)
    {
    }

    CNoteSpacing::~CNoteSpacing()
    {
    }

    void CNoteSpacing::InitMap(bool /*bRead*/)
    {
    }

    bool CNoteSpacing::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"betweenNotes", m_uBetweenNotes);
        Util::CXMLAttConverter::SetAttribute(att, L"belowLine", m_uBelowLine);
        Util::CXMLAttConverter::SetAttribute(att, L"aboveLine", m_uAboveLine);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNoteSpacing::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"betweenNotes", m_uBetweenNotes);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"belowLine", m_uBelowLine);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"aboveLine", m_uAboveLine);

        return bres;
    }

}
