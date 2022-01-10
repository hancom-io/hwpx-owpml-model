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
#include "package.h"

namespace OWPML {

    CPackage* CPackage::Create()
    {
        return new CPackage();
    }

    CPackage::CPackage() : CNamedObject(ID_OPF_Package)
    {
        SetElemName(L"opf:package");
    }

    CPackage::~CPackage()
    {
    }

    void CPackage::InitMap(bool bRead)
    {
        OWPML_OPF_REDIRECT_FUNC(CPackage, metadata)
            OWPML_OPF_REDIRECT_FUNC(CPackage, manifest)
            OWPML_OPF_REDIRECT_FUNC(CPackage, spine)
            OWPML_OPF_REDIRECT_FUNC(CPackage, tours)
            OWPML_OPF_REDIRECT_FUNC(CPackage, guide)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CPackage)
            OWPML_OPF_ADD_REDIRECT_FUNC(metadata, CMetadataType, ID_OPF_MetadataType)
            OWPML_OPF_ADD_REDIRECT_FUNC(manifest, CManifestType, ID_OPF_ManifestType)
            OWPML_OPF_ADD_REDIRECT_FUNC(spine, CSpineType, ID_OPF_SpineType)
            OWPML_OPF_ADD_REDIRECT_FUNC(tours, CToursType, ID_OPF_ToursType)
            OWPML_OPF_ADD_REDIRECT_FUNC(guide, CGuideType, ID_OPF_GuideType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CPackage::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"version", m_strVersion);
        Util::CXMLAttConverter::SetAttribute(att, L"unique-identifier", m_strUniqueidentifier);
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_strId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CPackage::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"version", m_strVersion);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"unique-identifier", m_strUniqueidentifier);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_strId);

        bres &= CNamedObject::ReadAttribute(att);
        return bres;
    }

    CMetadataType* CPackage::Setmetadata(CMetadataType* pmetadata)
    {
        CMetadataType* metadata = pmetadata;
        if (metadata == NULL) {
            metadata = CMetadataType::Create();
        }
        SetObject((CObject*)metadata);

        return metadata;
    }

    CMetadataType* CPackage::Getmetadata(int index)
    {
        return static_cast<CMetadataType*>(GetObjectByID(ID_OPF_MetadataType, index));
    }

    CManifestType* CPackage::Setmanifest(CManifestType* pmanifest)
    {
        CManifestType* manifest = pmanifest;
        if (manifest == NULL) {
            manifest = CManifestType::Create();
        }
        SetObject((CObject*)manifest);

        return manifest;
    }

    CManifestType* CPackage::Getmanifest(int index)
    {
        return static_cast<CManifestType*>(GetObjectByID(ID_OPF_ManifestType, index));
    }

    CSpineType* CPackage::Setspine(CSpineType* pspine)
    {
        CSpineType* spine = pspine;
        if (spine == NULL) {
            spine = CSpineType::Create();
        }
        SetObject((CObject*)spine);

        return spine;
    }

    CSpineType* CPackage::Getspine(int index)
    {
        return static_cast<CSpineType*>(GetObjectByID(ID_OPF_SpineType, index));
    }

    CToursType* CPackage::Settours(CToursType* ptours)
    {
        CToursType* tours = ptours;
        if (tours == NULL) {
            tours = CToursType::Create();
        }
        SetObject((CObject*)tours);

        return tours;
    }

    CToursType* CPackage::Gettours(int index)
    {
        return static_cast<CToursType*>(GetObjectByID(ID_OPF_ToursType, index));
    }

    CGuideType* CPackage::Setguide(CGuideType* pguide)
    {
        CGuideType* guide = pguide;
        if (guide == NULL) {
            guide = CGuideType::Create();
        }
        SetObject((CObject*)guide);

        return guide;
    }

    CGuideType* CPackage::Getguide(int index)
    {
        return static_cast<CGuideType*>(GetObjectByID(ID_OPF_GuideType, index));
    }

}
