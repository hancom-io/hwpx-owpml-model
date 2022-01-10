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
#include "FootNoteShapeType.h"

namespace OWPML {
    CFootNoteShapeType* CFootNoteShapeType::Create()
    {
        return new CFootNoteShapeType();
    }

    CFootNoteShapeType* CFootNoteShapeType::Clone()
    {
        CFootNoteShapeType* clone = new CFootNoteShapeType();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CFootNoteShapeType::CFootNoteShapeType() : CNoteShapeType(ID_PARA_FootNoteShapeType)
    {
    }

    CFootNoteShapeType::~CFootNoteShapeType()
    {
    }

    void CFootNoteShapeType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CNoteShapeType, autoNumFormat)
            OWPML_PARALIST_REDIRECT_FUNC(CNoteShapeType, noteLine)
            OWPML_PARALIST_REDIRECT_FUNC(CNoteShapeType, noteSpacing)

            OWPML_PARALIST_REDIRECT_FUNC(CFootNoteShapeType, numbering)
            OWPML_PARALIST_REDIRECT_FUNC(CFootNoteShapeType, placement)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFootNoteShapeType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(autoNumFormat, CAutoNumFormatType, ID_PARA_AutoNumFormatType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(noteLine, CNoteLine, ID_PARA_NoteLine)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(noteSpacing, CNoteSpacing, ID_PARA_NoteSpacing)

            OWPML_PARALIST_ADD_REDIRECT_FUNC(numbering, CFNNumbering, ID_PARA_FNNumbering)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(placement, CFNPlacement, ID_PARA_FNPlacement)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFootNoteShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFootNoteShapeType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFNNumbering* CFootNoteShapeType::Setnumbering(CFNNumbering* pnumbering)
    {
        CFNNumbering* numbering = pnumbering;
        if (numbering == NULL) {
            numbering = CFNNumbering::Create();
        }
        SetObject((CObject*)numbering);

        return numbering;
    }

    CFNNumbering* CFootNoteShapeType::Getnumbering(int index)
    {
        return static_cast<CFNNumbering*>(GetObjectByID(ID_PARA_FNNumbering, index));
    }

    CFNPlacement* CFootNoteShapeType::Setplacement(CFNPlacement* pplacement)
    {
        CFNPlacement* placement = pplacement;
        if (placement == NULL) {
            placement = CFNPlacement::Create();
        }
        SetObject((CObject*)placement);

        return placement;
    }

    CFNPlacement* CFootNoteShapeType::Getplacement(int index)
    {
        return static_cast<CFNPlacement*>(GetObjectByID(ID_PARA_FNPlacement, index));
    }

}
