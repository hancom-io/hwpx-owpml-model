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
#include "HWPMLHeadType.h"

namespace OWPML {

    CHWPMLHeadType* CHWPMLHeadType::Create()
    {
        return new CHWPMLHeadType();
    }

    CHWPMLHeadType::CHWPMLHeadType() : CNamedObject(ID_HEAD_HWPMLHeadType), m_uSecCnt(0)
    {
        SetElemName(L"hh:head");
    }

    CHWPMLHeadType::~CHWPMLHeadType()
    {
    }

    void CHWPMLHeadType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, beginNum)
            OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, refList)
            OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, forbiddenWordList)
            OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, compatibleDocument)
            OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, docOption)
            OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, trackchageConfig)
            // metatag & json
            OWPML_HEAD_REDIRECT_FUNC(CHWPMLHeadType, metaTag)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CHWPMLHeadType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(beginNum, CBeginNum, ID_HEAD_BeginNum)
            OWPML_HEAD_ADD_REDIRECT_FUNC(refList, CMappingTableType, ID_HEAD_MappingTableType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(forbiddenWordList, CForbiddenWordListType, ID_HEAD_ForbiddenWordListType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(compatibleDocument, CCompatibleDocumentType, ID_HEAD_CompatibleDocumentType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(docOption, CDocOption, ID_HEAD_DocOption)
            OWPML_HEAD_ADD_REDIRECT_FUNC(trackchageConfig, CTrackChangeConfig, ID_HEAD_TrackChangeConfig)
            // metatag & json
            OWPML_HEAD_ADD_REDIRECT_FUNC(metaTag, CMetaTag, ID_PARA_METATAG)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CHWPMLHeadType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"version", m_strVersion);
        Util::CXMLAttConverter::SetAttribute(att, L"secCnt", m_uSecCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CHWPMLHeadType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"version", m_strVersion);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"secCnt", m_uSecCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CBeginNum* CHWPMLHeadType::SetbeginNum(CBeginNum* pbeginNum)
    {
        CBeginNum* beginNum = pbeginNum;
        if (beginNum == NULL) {
            beginNum = CBeginNum::Create();
        }
        SetObject((CObject*)beginNum);

        return beginNum;
    }

    CBeginNum* CHWPMLHeadType::GetbeginNum(int index)
    {
        return static_cast<CBeginNum*>(GetObjectByID(ID_HEAD_BeginNum, index));
    }

    CMappingTableType* CHWPMLHeadType::SetrefList(CMappingTableType* prefList)
    {
        CMappingTableType* refList = prefList;
        if (refList == NULL) {
            refList = CMappingTableType::Create();
        }
        SetObject((CObject*)refList);

        return refList;
    }

    CMappingTableType* CHWPMLHeadType::GetrefList(int index)
    {
        return static_cast<CMappingTableType*>(GetObjectByID(ID_HEAD_MappingTableType, index));
    }

    CForbiddenWordListType* CHWPMLHeadType::SetforbiddenWordList(CForbiddenWordListType* pforbiddenWordList)
    {
        CForbiddenWordListType* forbiddenWordList = pforbiddenWordList;
        if (forbiddenWordList == NULL) {
            forbiddenWordList = CForbiddenWordListType::Create();
        }
        SetObject((CObject*)forbiddenWordList);

        return forbiddenWordList;
    }

    CForbiddenWordListType* CHWPMLHeadType::GetforbiddenWordList(int index)
    {
        return static_cast<CForbiddenWordListType*>(GetObjectByID(ID_HEAD_ForbiddenWordListType, index));
    }

    CCompatibleDocumentType* CHWPMLHeadType::SetcompatibleDocument(CCompatibleDocumentType* pcompatibleDocument)
    {
        CCompatibleDocumentType* compatibleDocument = pcompatibleDocument;
        if (compatibleDocument == NULL) {
            compatibleDocument = CCompatibleDocumentType::Create();
        }
        SetObject((CObject*)compatibleDocument);

        return compatibleDocument;
    }

    CCompatibleDocumentType* CHWPMLHeadType::GetcompatibleDocument(int index)
    {
        return static_cast<CCompatibleDocumentType*>(GetObjectByID(ID_HEAD_CompatibleDocumentType, index));
    }

    CDocOption* CHWPMLHeadType::SetdocOption(CDocOption* docOption)
    {
        CDocOption* pdocoption = docOption;
        if (pdocoption == NULL) {
            pdocoption = CDocOption::Create();
        }
        SetObject((CObject*)pdocoption);

        return pdocoption;
    }

    CDocOption* CHWPMLHeadType::GetdocOption(int index)
    {
        return static_cast<CDocOption*>(GetObjectByID(ID_HEAD_DocOption, index));
    }

    CTrackChangeConfig* CHWPMLHeadType::SetTrackChangeConfig(CTrackChangeConfig* trackChangeConfig)
    {
        CTrackChangeConfig* ptrackChangeConfig = trackChangeConfig;
        if (ptrackChangeConfig == NULL) {
            ptrackChangeConfig = CTrackChangeConfig::Create();
        }
        SetObject((CObject*)ptrackChangeConfig);

        return ptrackChangeConfig;
    }

    CTrackChangeConfig* CHWPMLHeadType::GetTrackChangeConfig(int index)
    {
        return static_cast<CTrackChangeConfig*>(GetObjectByID(ID_HEAD_TrackChangeConfig, index));
    }
}
