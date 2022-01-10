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
#ifndef  _HWPMLHEADTYPE_H_
#define  _HWPMLHEADTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CBeginNum;
    class CMappingTableType;
    class CForbiddenWordListType;
    class CCompatibleDocumentType;
    class CDocOption;
    class CTrackChangeConfig;

    // CHWPMLHeadType Declaration 
    class CHWPMLHeadType : public CNamedObject
    {
    public:
        CHWPMLHeadType();
    public:
        virtual ~CHWPMLHeadType();
        static CHWPMLHeadType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CBeginNum* SetbeginNum(CBeginNum* beginNum = NULL);
        CBeginNum* GetbeginNum(int index = 0);

        CMappingTableType* SetrefList(CMappingTableType* refList = NULL);
        CMappingTableType* GetrefList(int index = 0);

        CForbiddenWordListType* SetforbiddenWordList(CForbiddenWordListType* forbiddenWordList = NULL);
        CForbiddenWordListType* GetforbiddenWordList(int index = 0);

        CCompatibleDocumentType* SetcompatibleDocument(CCompatibleDocumentType* compatibleDocument = NULL);
        CCompatibleDocumentType* GetcompatibleDocument(int index = 0);

        CDocOption* SetdocOption(CDocOption* docOption = NULL);
        CDocOption* GetdocOption(int index = 0);

        CTrackChangeConfig* SetTrackChangeConfig(CTrackChangeConfig* trackChangeConfig = NULL);
        CTrackChangeConfig* GetTrackChangeConfig(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetVersion(void) { return m_strVersion.c_str(); }
        void SetVersion(LPCWSTR version) { m_strVersion = version; }

        UINT GetSecCnt(void) { return m_uSecCnt; }
        void SetSecCnt(UINT secCnt) { m_uSecCnt = secCnt; }


    private:
        hncstd::wstring m_strVersion;
        UINT m_uSecCnt;
    };
}
#endif // _HWPMLHEADTYPE_H_
