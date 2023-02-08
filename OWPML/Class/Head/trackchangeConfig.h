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
#ifndef  _TRACKCHANGE_CONFIG_H_
#define  _TRACKCHANGE_CONFIG_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CConfigItemSet;

    // CTrackChangeConfig Declaration 
    class CTrackChangeConfig : public CExtObject
    {
    private:
        CTrackChangeConfig();
    public:
        virtual ~CTrackChangeConfig();
        static CTrackChangeConfig* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CConfigItemSet* SetConfigItemSet(CConfigItemSet* pconfigitemset = NULL);
        CConfigItemSet* GetConfigItemSet(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetFlags(void) { return m_flags; }
        void SetFlags(UINT falgs) { m_flags = falgs; }

        UINT GetProtectSpinCount(void) { return m_protectSpinCount; }
        void SetProtectSpinCount(UINT protectSpinCount) { m_protectSpinCount = protectSpinCount; }

        UINT GetProtectalgSid(void) { return m_protectalgSid; }
        void SetProtectalgSid(UINT protectalgSid) { m_protectalgSid = protectalgSid; }

        LPCWSTR GetProtectHash(void) { return m_protectHash.c_str(); }
        void SetProtectHash(LPCWSTR protectHash) { m_protectHash = protectHash; }

        LPCWSTR GetProtectSalt(void) { return m_protectSalt.c_str(); }
        void SetProtectSalt(LPCWSTR protectSalt) { m_protectSalt = protectSalt; }

    private:
        UINT m_flags;
        UINT m_protectSpinCount;
        UINT m_protectalgSid;
        hncstd::wstring m_protectHash;
        hncstd::wstring m_protectSalt;
    };
}
#endif // _TRACKCHANGE_CONFIG_H_
