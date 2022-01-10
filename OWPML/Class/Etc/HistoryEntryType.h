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
#ifndef  _HISTORYENTRYTYPE_H_
#define  _HISTORYENTRYTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CHistoryEntryType Declaration 
    class CHistoryEntryType : public CExtObject
    {
    private:
        CHistoryEntryType();
    public:
        virtual ~CHistoryEntryType();
        static CHistoryEntryType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CDiffEntryType* SetpackageDiff(CDiffEntryType* packageDiff = NULL);
        CDiffEntryType* GetpackageDiff(int index = 0);

        CDiffEntryType* SetheadDiff(CDiffEntryType* headDiff = NULL);
        CDiffEntryType* GetheadDiff(int index = 0);

        CDiffEntryType* SetbodyDiff(CDiffEntryType* bodyDiff = NULL);
        CDiffEntryType* GetbodyDiff(int index = 0);

        CDiffEntryType* SettailDiff(CDiffEntryType* bodyDiff = NULL);
        CDiffEntryType* GettailDiff(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetRevisionNumber(void) { return m_uRevisionNumber; }
        void SetRevisionNumber(UINT revisionNumber) { m_uRevisionNumber = revisionNumber; }

        LPCWSTR GetRevisionDate(void) { return m_strRevisionDate.c_str(); }
        void SetRevisionDate(LPCWSTR revisionDate) { m_strRevisionDate = revisionDate; }

        LPCWSTR GetRevisionAuthor(void) { return m_strRevisionAuthor.c_str(); }
        void SetRevisionAuthor(LPCWSTR revisionAuthor) { m_strRevisionAuthor = revisionAuthor; }

        LPCWSTR GetRevisionDescription(void) { return m_strRevisionDescription.c_str(); }
        void SetRevisionDescription(LPCWSTR revisionDescription) { m_strRevisionDescription = revisionDescription; }

        BOOL GetAutoSave(void) { return m_AutoSave == true ? TRUE : FALSE; }
        void SetAutoSave(BOOL autoSave) { m_AutoSave = (autoSave == TRUE ? true : false); }

#ifdef NEW_VERSION_DIFF
        BOOL GetUsedStandardTime(void) { return m_UsedStandardTime == true ? TRUE : FALSE; }
        void SetUsedStandardTime(BOOL used) { m_UsedStandardTime = (used == TRUE ? true : false); }

        BOOL GetUsedCertificate(void) { return m_UsedCertificate == true ? TRUE : FALSE; }
        void SetUsedCertificate(BOOL used) { m_UsedCertificate = (used == TRUE ? true : false); }
#endif //NEW_VERSION_DIFF


    private:
        UINT m_uRevisionNumber;
        hncstd::wstring m_strRevisionDate;
        hncstd::wstring m_strRevisionAuthor;
        hncstd::wstring m_strRevisionDescription;
        bool m_AutoSave;
#ifdef NEW_VERSION_DIFF
        bool m_UsedStandardTime;
        bool m_UsedCertificate;
#endif //NEW_VERSION_DIFF
    };
}
#endif // _HISTORYENTRYTYPE_H_
