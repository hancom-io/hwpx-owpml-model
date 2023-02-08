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
#include "NoteShapeType.h"
#include "EndNoteShapeType.h"

namespace OWPML {
    CEndNoteShapeType* CEndNoteShapeType::Create()
    {
        return new CEndNoteShapeType();
    }

    CEndNoteShapeType* CEndNoteShapeType::Clone()
    {
        CEndNoteShapeType* clone = new CEndNoteShapeType();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CEndNoteShapeType::CEndNoteShapeType() : CNoteShapeType(ID_PARA_EndNoteShapeType)
    {
    }

    CEndNoteShapeType::~CEndNoteShapeType()
    {
    }

    void CEndNoteShapeType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CNoteShapeType, autoNumFormat)
            OWPML_PARALIST_REDIRECT_FUNC(CNoteShapeType, noteLine)
            OWPML_PARALIST_REDIRECT_FUNC(CNoteShapeType, noteSpacing)

            OWPML_PARALIST_REDIRECT_FUNC(CEndNoteShapeType, numbering)
            OWPML_PARALIST_REDIRECT_FUNC(CEndNoteShapeType, placement)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEndNoteShapeType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(autoNumFormat, CAutoNumFormatType, ID_PARA_AutoNumFormatType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(noteLine, CNoteLine, ID_PARA_NoteLine)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(noteSpacing, CNoteSpacing, ID_PARA_NoteSpacing)

            OWPML_PARALIST_ADD_REDIRECT_FUNC(numbering, CENNumbering, ID_PARA_ENNumbering)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(placement, CENPlacement, ID_PARA_ENPlacement)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEndNoteShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEndNoteShapeType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CENNumbering* CEndNoteShapeType::Setnumbering(CENNumbering* pnumbering)
    {
        CENNumbering* numbering = pnumbering;
        if (numbering == NULL) {
            numbering = CENNumbering::Create();
        }
        SetObject((CObject*)numbering);

        return numbering;
    }

    CENNumbering* CEndNoteShapeType::Getnumbering(int index)
    {
        return static_cast<CENNumbering*>(GetObjectByID(ID_PARA_ENNumbering, index));
    }

    CENPlacement* CEndNoteShapeType::Setplacement(CENPlacement* pplacement)
    {
        CENPlacement* placement = pplacement;
        if (placement == NULL) {
            placement = CENPlacement::Create();
        }
        SetObject((CObject*)placement);

        return placement;
    }

    CENPlacement* CEndNoteShapeType::Getplacement(int index)
    {
        return static_cast<CENPlacement*>(GetObjectByID(ID_PARA_ENPlacement, index));
    }

}
