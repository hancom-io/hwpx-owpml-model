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
#include "doNotAlignLastForbidden.h"

namespace OWPML {


    CDoNotAlignLastForbidden* CDoNotAlignLastForbidden::Create()
    {
        return new CDoNotAlignLastForbidden();
    }

    CDoNotAlignLastForbidden::CDoNotAlignLastForbidden() : CExtObject(ID_HEAD_DoNotAlignLastForbidden)
    {
    }

    CDoNotAlignLastForbidden::~CDoNotAlignLastForbidden()
    {
    }

    void CDoNotAlignLastForbidden::InitMap(bool /*bRead*/)
    {
    }

    bool CDoNotAlignLastForbidden::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDoNotAlignLastForbidden::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

    CAdjustMarginFromAdjustLineheight* CAdjustMarginFromAdjustLineheight::Create()
    {
        return new CAdjustMarginFromAdjustLineheight();
    }

    CAdjustMarginFromAdjustLineheight::CAdjustMarginFromAdjustLineheight() : CExtObject(ID_HEAD_AdjustMarginFromAdjustLineheight)
    {
    }

    CAdjustMarginFromAdjustLineheight::~CAdjustMarginFromAdjustLineheight()
    {
    }

    void CAdjustMarginFromAdjustLineheight::InitMap(bool /*bRead*/)
    {
    }

    bool CAdjustMarginFromAdjustLineheight::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAdjustMarginFromAdjustLineheight::ReadAttribute(CAttribute* /*att*/)
    {
        bool bres = TRUE;

        return bres;
    }

}
