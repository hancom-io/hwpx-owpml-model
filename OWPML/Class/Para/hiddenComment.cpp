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
#include "hiddenComment.h"

namespace OWPML {

    CHiddenComment* CHiddenComment::Create()
    {
        return new CHiddenComment();
    }

    CHiddenComment* CHiddenComment::Clone()
    {
        CHiddenComment* clone = new CHiddenComment();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CHiddenComment::CHiddenComment() : CExtObject(ID_PARA_HiddenComment)
    {
    }

    CHiddenComment::~CHiddenComment()
    {
    }

    void CHiddenComment::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CHiddenComment, subList)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CHiddenComment)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(subList, CParaListType, ID_PARA_ParaListType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CHiddenComment::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHiddenComment::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CParaListType* CHiddenComment::SetsubList(CParaListType* psubList)
    {
        CParaListType* subList = psubList;
        if (subList == NULL) {
            subList = CParaListType::Create();
        }
        SetObject((CObject*)subList);

        return subList;
    }

    CParaListType* CHiddenComment::GetsubList(int index)
    {
        return static_cast<CParaListType*>(GetObjectByID(ID_PARA_ParaListType, index));
    }

}
