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
#include "trackchangeConfig.h"

namespace OWPML {
    CTrackChangeConfig* CTrackChangeConfig::Create()
    {
        return new CTrackChangeConfig();
    }

    CTrackChangeConfig::CTrackChangeConfig() : CExtObject(ID_HEAD_TrackChangeConfig), m_flags(0), m_protectSpinCount(0), m_protectalgSid(0)
    {
    }

    CTrackChangeConfig::~CTrackChangeConfig()
    {
    }

    void CTrackChangeConfig::InitMap(bool bRead)
    {
        OWPML_ODFCONFIG_REDIRECT_FUNC1(CTrackChangeConfig, configitemset, config - item - set)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTrackChangeConfig)
            OWPML_ODFCONFIG_ADD_REDIRECT_FUNC(configitemset, CConfigItemSet, ID_ODF_ConfigItemSet)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTrackChangeConfig::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"flags", m_flags);
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTrackChangeConfig::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"flags", m_flags);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }


    CConfigItemSet* CTrackChangeConfig::SetConfigItemSet(CConfigItemSet* pconfigitemset)
    {
        CConfigItemSet* configitemset = pconfigitemset;
        if (configitemset == NULL) {
            configitemset = CConfigItemSet::Create();
        }
        SetObject((CObject*)configitemset);

        return configitemset;
    }

    CConfigItemSet* CTrackChangeConfig::GetConfigItemSet(int index)
    {
        return static_cast<CConfigItemSet*>(GetObjectByID(ID_ODF_ConfigItemSet, index));
    }


}
