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
#include "margin.h"

namespace OWPML {

    CMargin* CMargin::Create()
    {
        return new CMargin();
    }

    CMargin::CMargin() : CExtObject(ID_HEAD_Margin)
    {
    }

    CMargin::~CMargin()
    {
    }

    void CMargin::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CMargin, intent)
            OWPML_CORE_REDIRECT_FUNC(CMargin, left)
            OWPML_CORE_REDIRECT_FUNC(CMargin, right)
            OWPML_CORE_REDIRECT_FUNC(CMargin, prev)
            OWPML_CORE_REDIRECT_FUNC(CMargin, next)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CMargin)
            OWPML_CORE_ADD_REDIRECT_FUNC(intent, CHWPValue, ID_CORE_Margin_Indent)
            OWPML_CORE_ADD_REDIRECT_FUNC(left, CHWPValue, ID_CORE_Margin_Left)
            OWPML_CORE_ADD_REDIRECT_FUNC(right, CHWPValue, ID_CORE_Margin_Right)
            OWPML_CORE_ADD_REDIRECT_FUNC(prev, CHWPValue, ID_CORE_Margin_Prev)
            OWPML_CORE_ADD_REDIRECT_FUNC(next, CHWPValue, ID_CORE_Margin_Next)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CMargin::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMargin::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CHWPValue* CMargin::Setintent(CHWPValue* pintent)
    {
        CHWPValue* intent = pintent;
        if (intent == NULL) {
            intent = CHWPValue::CreateArg(ID_CORE_Margin_Indent);
        }
        SetObject((CObject*)intent);

        return intent;
    }

    CHWPValue* CMargin::Getintent(int index)
    {
        return static_cast<CHWPValue*>(GetObjectByID(ID_CORE_Margin_Indent, index));
    }

    CHWPValue* CMargin::Setleft(CHWPValue* pleft)
    {
        CHWPValue* left = pleft;
        if (left == NULL) {
            left = CHWPValue::CreateArg(ID_CORE_Margin_Left);
        }
        SetObject((CObject*)left);

        return left;
    }

    CHWPValue* CMargin::Getleft(int index)
    {
        return static_cast<CHWPValue*>(GetObjectByID(ID_CORE_Margin_Left, index));
    }

    CHWPValue* CMargin::Setright(CHWPValue* pright)
    {
        CHWPValue* right = pright;
        if (right == NULL) {
            right = CHWPValue::CreateArg(ID_CORE_Margin_Right);
        }
        SetObject((CObject*)right);

        return right;
    }

    CHWPValue* CMargin::Getright(int index)
    {
        return static_cast<CHWPValue*>(GetObjectByID(ID_CORE_Margin_Right, index));
    }

    CHWPValue* CMargin::Setprev(CHWPValue* pprev)
    {
        CHWPValue* prev = pprev;
        if (prev == NULL) {
            prev = CHWPValue::CreateArg(ID_CORE_Margin_Prev);
        }
        SetObject((CObject*)prev);

        return prev;
    }

    CHWPValue* CMargin::Getprev(int index)
    {
        return static_cast<CHWPValue*>(GetObjectByID(ID_CORE_Margin_Prev, index));
    }

    CHWPValue* CMargin::Setnext(CHWPValue* pnext)
    {
        CHWPValue* next = pnext;
        if (next == NULL) {
            next = CHWPValue::CreateArg(ID_CORE_Margin_Next);
        }
        SetObject((CObject*)next);

        return next;
    }

    CHWPValue* CMargin::Getnext(int index)
    {
        return static_cast<CHWPValue*>(GetObjectByID(ID_CORE_Margin_Next, index));
    }

}
