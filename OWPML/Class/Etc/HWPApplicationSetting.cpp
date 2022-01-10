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
#include "HWPApplicationSetting.h"

namespace OWPML {

    CHWPApplicationSetting* CHWPApplicationSetting::Create()
    {
        return new CHWPApplicationSetting();
    }

    CHWPApplicationSetting::CHWPApplicationSetting() : CNamedObject(ID_APPLICATION_HWPApplicationSetting)
    {
        SetElemName(L"ha:HWPApplicationSetting");
    }

    CHWPApplicationSetting::~CHWPApplicationSetting()
    {
    }

    void CHWPApplicationSetting::InitMap(bool bRead)
    {
        OWPML_APPLICATION_REDIRECT_FUNC(CHWPApplicationSetting, CaretPosition)
            OWPML_APPLICATION_REDIRECT_FUNC(CHWPApplicationSetting, docdistribute)
            OWPML_ODFCONFIG_REDIRECT_FUNC1(CHWPApplicationSetting, configitemset, config - item - set)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CHWPApplicationSetting)
            OWPML_APPLICATION_ADD_REDIRECT_FUNC(CaretPosition, CCaretPosition, ID_APPLICATION_CaretPosition)
            OWPML_APPLICATION_ADD_REDIRECT_FUNC(docdistribute, CDocDistribute, ID_DOC_Distribute)
            OWPML_ODFCONFIG_ADD_REDIRECT_FUNC(configitemset, CConfigItemSet, ID_ODF_ConfigItemSet)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CHWPApplicationSetting::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHWPApplicationSetting::ReadAttribute(CAttribute* att)
    {
        return CExtObject::ReadAttribute(att);
    }

    CCaretPosition* CHWPApplicationSetting::SetCaretPosition(CCaretPosition* pCaretPosition)
    {
        CCaretPosition* CaretPosition = pCaretPosition;
        if (CaretPosition == NULL) {
            CaretPosition = CCaretPosition::Create();
        }
        SetObject((CObject*)CaretPosition);

        return CaretPosition;
    }

    CCaretPosition* CHWPApplicationSetting::GetCaretPosition(int index)
    {
        return static_cast<CCaretPosition*>(GetObjectByID(ID_APPLICATION_CaretPosition, index));
    }

    CConfigItemSet* CHWPApplicationSetting::SetConfigItemSet(CConfigItemSet* pconfigitemset)
    {
        CConfigItemSet* configitemset = pconfigitemset;
        if (configitemset == NULL) {
            configitemset = CConfigItemSet::Create();
        }
        SetObject((CObject*)configitemset);

        return configitemset;
    }

    CConfigItemSet* CHWPApplicationSetting::GetConfigItemSet(int index)
    {
        return static_cast<CConfigItemSet*>(GetObjectByID(ID_ODF_ConfigItemSet, index));
    }

    CDocDistribute* CHWPApplicationSetting::SetDocDistribute(CDocDistribute* distrubute)
    {
        CDocDistribute* docdistribute = distrubute;
        if (docdistribute == NULL) {
            docdistribute = CDocDistribute::Create();
        }
        SetObject((CObject*)docdistribute);

        return docdistribute;
    }

    CDocDistribute* CHWPApplicationSetting::GetDocDistribute(int index)
    {
        return static_cast<CDocDistribute*>(GetObjectByID(ID_DOC_Distribute, index));
    }


}
