﻿/*
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
#include "doNotApplyStrikeoutWithUnderline.h"

namespace OWPML {


    CDoNotApplyStrikeoutWithUnderline* CDoNotApplyStrikeoutWithUnderline::Create()
    {
        return new CDoNotApplyStrikeoutWithUnderline();
    }

    CDoNotApplyStrikeoutWithUnderline::CDoNotApplyStrikeoutWithUnderline() : CExtObject(ID_HEAD_DoNotApplyStrikeoutWithUnderline)
    {
    }

    CDoNotApplyStrikeoutWithUnderline::~CDoNotApplyStrikeoutWithUnderline()
    {
    }

    void CDoNotApplyStrikeoutWithUnderline::InitMap(bool /*bRead*/)
    {
    }

    bool CDoNotApplyStrikeoutWithUnderline::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDoNotApplyStrikeoutWithUnderline::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

}
