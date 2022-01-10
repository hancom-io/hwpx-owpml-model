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
#include "odfelement.h"

namespace OWPML {

    /////////////////////////////////////////////////////////////////////////////////////////
    // CStartKeyGerneration
    /////////////////////////////////////////////////////////////////////////////////////////
    CStartKeyGerneration* CStartKeyGerneration::Create()
    {
        return new CStartKeyGerneration();
    }

    CStartKeyGerneration::CStartKeyGerneration() : CExtObject(ID_ODF_StartKeyGerneration), m_keysize(0)
    {
    }

    CStartKeyGerneration::~CStartKeyGerneration()
    {
    }

    void CStartKeyGerneration::InitMap(bool /*bRead*/)
    {
    }

    bool CStartKeyGerneration::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        OWPML::Util::CXMLAttConverter::SetAttribute(att, L"start-key-generation-name", m_strStartkeyGenerationName);
        Util::CXMLAttConverter::SetAttribute(att, L"key-size", m_keysize);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CStartKeyGerneration::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"start-key-generation-name", m_strStartkeyGenerationName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"key-size", m_keysize);

        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CKeyDerivation
    /////////////////////////////////////////////////////////////////////////////////////////
    CKeyDerivation* CKeyDerivation::Create()
    {
        return new CKeyDerivation();
    }

    CKeyDerivation::CKeyDerivation() : CExtObject(ID_ODF_KeyDerivation), m_itercount(0), m_keysize(0)
    {
    }

    CKeyDerivation::~CKeyDerivation()
    {
    }

    void CKeyDerivation::InitMap(bool /*bRead*/)
    {
    }

    bool CKeyDerivation::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"key-derivation-name", m_strKeyDerivationName);
        Util::CXMLAttConverter::SetAttribute(att, L"key-size", m_keysize);
        Util::CXMLAttConverter::SetAttribute(att, L"iteration-count", m_itercount);
        Util::CXMLAttConverter::SetAttribute(att, L"salt", m_strSalt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CKeyDerivation::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"key-derivation-name", m_strKeyDerivationName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"key-size", m_keysize);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"iteration-count", m_itercount);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"salt", m_strSalt);

        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CAlgorithm
    /////////////////////////////////////////////////////////////////////////////////////////
    CAlgorithm* CAlgorithm::Create()
    {
        return new CAlgorithm();
    }

    CAlgorithm::CAlgorithm() : CExtObject(ID_ODF_Algorithm)
    {
    }

    CAlgorithm::~CAlgorithm()
    {
    }

    void CAlgorithm::InitMap(bool /*bRead*/)
    {
    }

    bool CAlgorithm::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"algorithm-name", m_strAlgorithmName);
        Util::CXMLAttConverter::SetAttribute(att, L"initialisation-vector", m_strInitVector);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CAlgorithm::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"algorithm-name", m_strAlgorithmName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"initialisation-vector", m_strInitVector);

        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CEncryptionData
    /////////////////////////////////////////////////////////////////////////////////////////
    CEncryptionData* CEncryptionData::Create()
    {
        return new CEncryptionData();
    }

    CEncryptionData::CEncryptionData() : CExtObject(ID_ODF_EncryptionData)
    {
    }

    CEncryptionData::~CEncryptionData()
    {
    }

    void CEncryptionData::InitMap(bool bRead)
    {
        OWPML_ODF_REDIRECT_FUNC(CEncryptionData, algorithm)
            OWPML_ODF_REDIRECT_FUNC1(CEncryptionData, keyderivation, key - derivation)
            OWPML_ODF_REDIRECT_FUNC1(CEncryptionData, startkeygeneration, start - key - generation)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CEncryptionData)
            OWPML_ODF_ADD_REDIRECT_FUNC(algorithm, CAlgorithm, ID_ODF_Algorithm)
            OWPML_ODF_ADD_REDIRECT_FUNC(keyderivation, CKeyDerivation, ID_ODF_KeyDerivation)
            OWPML_ODF_ADD_REDIRECT_FUNC(startkeygeneration, CStartKeyGerneration, ID_ODF_StartKeyGerneration)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CEncryptionData::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"checksum-type", m_strChecksumType);
        Util::CXMLAttConverter::SetAttribute(att, L"checksum", m_strChecksum);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CEncryptionData::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"checksum-type", m_strChecksumType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"checksum", m_strChecksum);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    CAlgorithm* CEncryptionData::Setalgorithm(CAlgorithm* palgorithm)
    {
        CAlgorithm* algorithm = palgorithm;
        if (algorithm == NULL) {
            algorithm = CAlgorithm::Create();
        }
        SetObject((CObject*)algorithm);

        return algorithm;
    }

    CAlgorithm* CEncryptionData::Getalgorithm(int index)
    {
        return static_cast<CAlgorithm*>(GetObjectByID(ID_ODF_Algorithm, index));
    }

    CKeyDerivation* CEncryptionData::Setkeyderivation(CKeyDerivation* pkeyderivation)
    {
        CKeyDerivation* keyderivation = pkeyderivation;
        if (keyderivation == NULL) {
            keyderivation = CKeyDerivation::Create();
        }
        SetObject((CObject*)keyderivation);

        return keyderivation;
    }

    CKeyDerivation* CEncryptionData::Getkeyderivation(int index)
    {
        return static_cast<CKeyDerivation*>(GetObjectByID(ID_ODF_KeyDerivation, index));
    }

    CStartKeyGerneration* CEncryptionData::Setstartkeygernation(CStartKeyGerneration* pstartkeygernation)
    {
        CStartKeyGerneration* startkeygernation = pstartkeygernation;
        if (startkeygernation == NULL) {
            startkeygernation = CStartKeyGerneration::Create();
        }
        SetObject((CObject*)startkeygernation);

        return startkeygernation;
    }

    CStartKeyGerneration* CEncryptionData::Getstartkeygernation(int index)
    {
        return static_cast<CStartKeyGerneration*>(GetObjectByID(ID_ODF_StartKeyGerneration, index));
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CFileEntry
    /////////////////////////////////////////////////////////////////////////////////////////
    CFileEntry* CFileEntry::Create()
    {
        return new CFileEntry();
    }

    CFileEntry::CFileEntry() : CExtObject(ID_ODF_FileEntry), m_size(0)
    {
    }

    CFileEntry::~CFileEntry()
    {
    }

    void CFileEntry::InitMap(bool bRead)
    {
        OWPML_ODF_REDIRECT_FUNC1(CFileEntry, encryptiondata, encryption - data)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CFileEntry)
            OWPML_ODF_ADD_REDIRECT_FUNC(encryptiondata, CEncryptionData, ID_ODF_EncryptionData)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CFileEntry::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"full-path", m_strFullPath);
        Util::CXMLAttConverter::SetAttribute(att, L"media-type", m_strMediaType);
        if (m_size) Util::CXMLAttConverter::SetAttribute(att, L"size", m_size);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CFileEntry::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"full-path", m_strFullPath);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"media-type", m_strMediaType);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"size", m_size);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    CEncryptionData* CFileEntry::Setencryptiondata(CEncryptionData* pencryptiondata)
    {
        CEncryptionData* encryptiondata = pencryptiondata;
        if (encryptiondata == NULL) {
            encryptiondata = CEncryptionData::Create();
        }
        SetObject((CObject*)encryptiondata);

        return encryptiondata;
    }

    CEncryptionData* CFileEntry::Getencryptiondata(int index)
    {
        return static_cast<CEncryptionData*>(GetObjectByID(ID_ODF_EncryptionData, index));
    }


    /////////////////////////////////////////////////////////////////////////////////////////
    // CODFManifest
    /////////////////////////////////////////////////////////////////////////////////////////
    CODFManifest* CODFManifest::Create()
    {
        return new CODFManifest();
    }

    CODFManifest::CODFManifest() : CNamedObject(ID_ODF_Manifest)
    {
        SetElemName(L"odf:manifest");
    }

    CODFManifest::~CODFManifest()
    {
    }

    void CODFManifest::InitMap(bool bRead)
    {
        OWPML_ODF_REDIRECT_FUNC1(CODFManifest, fileentry, file - entry)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CODFManifest)
            OWPML_ODF_ADD_REDIRECT_FUNC(fileentry, CFileEntry, ID_ODF_FileEntry)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CODFManifest::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CODFManifest::ReadAttribute(CAttribute* att)
    {
        return CNamedObject::ReadAttribute(att);
    }

    CFileEntry* CODFManifest::Setfileentry(CFileEntry* pfileentry)
    {
        CFileEntry* fileentry = pfileentry;
        if (fileentry == NULL) {
            fileentry = CFileEntry::Create();
        }
        SetObject((CObject*)fileentry);

        return fileentry;
    }

    CFileEntry* CODFManifest::Getfileentry(int index)
    {
        return static_cast<CFileEntry*>(GetObjectByID(ID_ODF_FileEntry, index));
    }







    /////////////////////////////////////////////////////////////////////////////////////////
    // CConfigItem
    /////////////////////////////////////////////////////////////////////////////////////////
    CConfigItem* CConfigItem::Create()
    {
        return new CConfigItem();
    }

    CConfigItem::CConfigItem() : CStringValueObject(ID_ODF_ConfigItem)
    {
    }

    CConfigItem::~CConfigItem()
    {
    }

    void CConfigItem::InitMap(bool /*bRead*/)
    {
    }

    bool CConfigItem::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"type", m_strType);

        return serialize->WriteElement(pCurObjName, this, att, m_val.c_str());
    }

    bool CConfigItem::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", m_strType);
        bres &= CStringValueObject::ReadAttribute(att);

        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CConfigItemSet
    /////////////////////////////////////////////////////////////////////////////////////////
    CConfigItemSet* CConfigItemSet::Create()
    {
        return new CConfigItemSet();
    }

    CConfigItemSet::CConfigItemSet() : CExtObject(ID_ODF_ConfigItemSet)
    {
    }

    CConfigItemSet::~CConfigItemSet()
    {
    }

    void CConfigItemSet::InitMap(bool bRead)
    {
        OWPML_ODFCONFIG_REDIRECT_FUNC1(CConfigItemSet, configitem, config - item)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CConfigItemSet)
            OWPML_ODFCONFIG_ADD_REDIRECT_FUNC(configitem, CConfigItem, ID_ODF_ConfigItem)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CConfigItemSet::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CConfigItemSet::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= CExtObject::ReadAttribute(att);

        return bres;
    }

    CConfigItem* CConfigItemSet::Setconfigitem(CConfigItem* pconfigitem)
    {
        CConfigItem* configitem = pconfigitem;
        if (configitem == NULL) {
            configitem = CConfigItem::Create();
        }
        SetObject((CObject*)configitem);

        return configitem;
    }

    CConfigItem* CConfigItemSet::Getconfigitem(int index)
    {
        return static_cast<CConfigItem*>(GetObjectByID(ID_ODF_ConfigItem, index));
    }

}
