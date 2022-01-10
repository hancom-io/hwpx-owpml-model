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
#include "docoption.h"

namespace OWPML {

    CDocOption* CDocOption::Create()
    {
        return new CDocOption();
    }

    CDocOption::CDocOption() : CExtObject(ID_HEAD_DocOption)
    {
    }

    CDocOption::~CDocOption()
    {
    }

    void CDocOption::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CDocOption, linkinfo)
            OWPML_HEAD_REDIRECT_FUNC(CDocOption, licensemark)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CDocOption)
            OWPML_HEAD_ADD_REDIRECT_FUNC(linkinfo, CDocOptionLinkInfo, ID_HEAD_DocOption_LinkInfo)
            OWPML_HEAD_ADD_REDIRECT_FUNC(licensemark, CDocOptionLicenseMark, ID_HEAD_DocOption_LicenseMark)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CDocOption::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CDocOption::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CDocOptionLinkInfo* CDocOption::SetdocOptionLinkInfo(CDocOptionLinkInfo* docOptionLinkInfo)
    {
        CDocOptionLinkInfo* pdocoptionlinkinfo = docOptionLinkInfo;
        if (pdocoptionlinkinfo == NULL) {
            pdocoptionlinkinfo = CDocOptionLinkInfo::Create();
        }
        SetObject((CObject*)pdocoptionlinkinfo);

        return pdocoptionlinkinfo;
    }

    CDocOptionLinkInfo* CDocOption::GetdocOptionLinkInfo(int index)
    {
        return static_cast<CDocOptionLinkInfo*>(GetObjectByID(ID_HEAD_DocOption_LinkInfo, index));
    }



    CDocOptionLicenseMark* CDocOption::SetdocOptionLicenseMark(CDocOptionLicenseMark* docOptionLicenseMark)
    {
        CDocOptionLicenseMark* pdocOptionLicenseMark = docOptionLicenseMark;
        if (pdocOptionLicenseMark == NULL) {
            pdocOptionLicenseMark = CDocOptionLicenseMark::Create();
        }
        SetObject((CObject*)pdocOptionLicenseMark);

        return pdocOptionLicenseMark;
    }

    CDocOptionLicenseMark* CDocOption::GetdocOptionLicenseMark(int index)
    {
        return static_cast<CDocOptionLicenseMark*>(GetObjectByID(ID_HEAD_DocOption_LicenseMark, index));
    }



}
