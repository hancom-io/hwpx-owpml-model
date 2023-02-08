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

#pragma once
#ifndef  _PACKAGE_H_
#define  _PACKAGE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CMetadataType;
    class CManifestType;
    class CSpineType;
    class CToursType;
    class CGuideType;

    // CPackage Declaration 
    class CPackage : public CNamedObject
    {
    public:
        CPackage();
    public:
        virtual ~CPackage();
        static CPackage* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CMetadataType* Setmetadata(CMetadataType* metadata = NULL);
        CMetadataType* Getmetadata(int index = 0);

        CManifestType* Setmanifest(CManifestType* manifest = NULL);
        CManifestType* Getmanifest(int index = 0);

        CSpineType* Setspine(CSpineType* spine = NULL);
        CSpineType* Getspine(int index = 0);

        CToursType* Settours(CToursType* tours = NULL);
        CToursType* Gettours(int index = 0);

        CGuideType* Setguide(CGuideType* guide = NULL);
        CGuideType* Getguide(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetVersion(void) { return m_strVersion.c_str(); }
        void SetVersion(LPCWSTR version) { m_strVersion = version; }

        LPCWSTR GetUniqueidentifier(void) { return m_strUniqueidentifier.c_str(); }
        void SetUniqueidentifier(LPCWSTR uniqueidentifier) { m_strUniqueidentifier = uniqueidentifier; }

        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        bool GetDistributionFlag(void) { return m_bDistributionFlag; }
        void SetDistributionFlag(bool value) { m_bDistributionFlag = value; }

    private:
        hncstd::wstring m_strVersion;
        hncstd::wstring m_strUniqueidentifier;
        hncstd::wstring m_strId;
        bool        m_bDistributionFlag = false;
    };
}
#endif // _PACKAGE_H_
