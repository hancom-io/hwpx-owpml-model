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

namespace OWPML {

    CNoteShapeType* CNoteShapeType::Clone()
    {
        CNoteShapeType* clone = new CNoteShapeType(this->GetID());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CNoteShapeType::CNoteShapeType(UINT id) : CExtObject(id)
    {
    }

    CNoteShapeType::~CNoteShapeType()
    {
    }

    void CNoteShapeType::InitMap(bool /*bRead*/)
    {
    }

    bool CNoteShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CNoteShapeType::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

    CAutoNumFormatType* CNoteShapeType::SetautoNumFormat(CAutoNumFormatType* pautoNumFormat)
    {
        CAutoNumFormatType* autoNumFormat = pautoNumFormat;
        if (autoNumFormat == NULL) {
            autoNumFormat = CAutoNumFormatType::Create();
        }
        SetObject((CObject*)autoNumFormat);

        return autoNumFormat;
    }

    CAutoNumFormatType* CNoteShapeType::GetautoNumFormat(int index)
    {
        return static_cast<CAutoNumFormatType*>(GetObjectByID(ID_PARA_AutoNumFormatType, index));
    }

    CNoteLine* CNoteShapeType::SetnoteLine(CNoteLine* pnoteLine)
    {
        CNoteLine* noteLine = pnoteLine;
        if (noteLine == NULL) {
            noteLine = CNoteLine::Create();
        }
        SetObject((CObject*)noteLine);

        return noteLine;
    }

    CNoteLine* CNoteShapeType::GetnoteLine(int index)
    {
        return static_cast<CNoteLine*>(GetObjectByID(ID_PARA_NoteLine, index));
    }

    CNoteSpacing* CNoteShapeType::SetnoteSpacing(CNoteSpacing* pnoteSpacing)
    {
        CNoteSpacing* noteSpacing = pnoteSpacing;
        if (noteSpacing == NULL) {
            noteSpacing = CNoteSpacing::Create();
        }
        SetObject((CObject*)noteSpacing);

        return noteSpacing;
    }

    CNoteSpacing* CNoteShapeType::GetnoteSpacing(int index)
    {
        return static_cast<CNoteSpacing*>(GetObjectByID(ID_PARA_NoteSpacing, index));
    }

}