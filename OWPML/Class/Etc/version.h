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
#ifndef  _VERSION_H_
#define  _VERSION_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CVersion Declaration 
    class CVersion : public CNamedObject
    {
    public:
        CVersion();
    public:
        virtual ~CVersion();
        static CVersion* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        TAGETAPPLICATIONTYPE GetTagetApplication(void) { return (TAGETAPPLICATIONTYPE)m_uTagetApplication; }
        void SetTagetApplication(TAGETAPPLICATIONTYPE tagetApplication) { m_uTagetApplication = (UINT)tagetApplication; }

        UINT GetMajor(void) { return m_uMajor; }
        void SetMajor(UINT major) { m_uMajor = major; }

        UINT GetMinor(void) { return m_uMinor; }
        void SetMinor(UINT minor) { m_uMinor = minor; }

        UINT GetPatch(void) { return m_uPatch; }
        void SetPatch(UINT patch) { m_uPatch = patch; }

        UINT GetRevision(void) { return m_uRevision; }
        void SetRevision(UINT revision) { m_uRevision = revision; }

        UINT GetOS(void) { return m_uOS; }
        void SetOS(UINT os) { m_uOS = os; }

        LPCWSTR GetXmlVersion(void) { return m_strXmlVersion.c_str(); }
        void SetXmlVersion(LPCWSTR xmlVersion) { m_strXmlVersion = xmlVersion; }

        LPCWSTR GetApplication(void) { return m_strApplication.c_str(); }
        void SetApplication(LPCWSTR application) { m_strApplication = application; }

        LPCWSTR GetAppVersion(void) { return m_strAppVersion.c_str(); }
        void SetAppVersion(LPCWSTR appVersion) { m_strAppVersion = appVersion; }

    private:
        UINT m_uTagetApplication;
        UINT m_uMajor;
        UINT m_uMinor;
        UINT m_uPatch;
        INT m_uRevision;
        INT m_uOS;
        hncstd::wstring m_strXmlVersion;
        hncstd::wstring m_strApplication;
        hncstd::wstring m_strAppVersion;
    };
}
#endif // _VERSION_H_
