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
#include "ExpatSax.h"
#include "SaxReader.h"
#include "DefaultHandler.h"
#include "Handler.h"
#include "ExpatDefaultHandler.h"
#include "ExpatSaxReader.h"
#include "Util.h"
#include "Zip/encrypt.h"
#include "Zip/unzip.h"
#include "Attribute.h"
#include "Zip/SDZip.h"
#include "Base/Thread.h"
#include "Document.h"

OWPML::CDocument gdoc;

namespace OWPML {

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CVersionHandler 핸들러
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CVersionHandler : public CDefaultHandler
    {
    public:
        CVersionHandler(OW_Version* pVersion);
        virtual ~CVersionHandler();

    public:
        void startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs);

    private:
        OW_Version* m_pVersion;
    };

    CVersionHandler::CVersionHandler(OW_Version* pVersion) : m_pVersion(pVersion)
    {
    }

    CVersionHandler::~CVersionHandler()
    {
    }

    void CVersionHandler::startElement(LPCWSTR const /*uri*/, LPCWSTR const localname, LPCWSTR const /*qname*/, const CAttribute* attrs)
    {
        if ((_ustrcmp(localname, L"HCFVersion") == 0) && (m_pVersion)) {
            m_pVersion->Application = attrs->getValue(L"tagetApplication");
            m_pVersion->major = static_cast<UINT>(_uatoi(attrs->getValue(L"major")));

            m_pVersion->minor = static_cast<UINT>(_uatoi(attrs->getValue(L"minor")));
            m_pVersion->micro = static_cast<UINT>(_uatoi(attrs->getValue(L"micro")));
            m_pVersion->buildNumber = static_cast<UINT>(_uatoi(attrs->getValue(L"buildNumber")));
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CContainerHandler 핸들러
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CContainerHandler : public CDefaultHandler
    {
    public:
        CContainerHandler(CDocument* pDocument);
        virtual ~CContainerHandler();

    public:
        void startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs);

    private:
        CDocument* m_pDocument;
    };

    CContainerHandler::CContainerHandler(CDocument* pDocument) : m_pDocument(pDocument)
    {
    }

    CContainerHandler::~CContainerHandler()
    {
    }

    void CContainerHandler::startElement(LPCWSTR const /*uri*/, LPCWSTR const localname, LPCWSTR const /*qname*/, const CAttribute* attrs)
    {
        if (_ustrcmp(localname, L"rootfile") == 0) {
            LPCWSTR pPath = NULL;
            LPCWSTR ptype = NULL;

            ptype = attrs->getValue(L"media-type");

            if (_ustrcmp(ptype, L"application/hwpml-package+xml") == 0) {
                pPath = attrs->getValue(L"full-path");
                if (m_pDocument) {
                    m_pDocument->SetRootFile(pPath);
                }
            }
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CContentHandler 핸들러
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CContentHandler : public CDefaultHandler
    {
    public:
        CContentHandler(CDocument* pDocument);
        virtual ~CContentHandler();

    public:
        void startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs);
        void endElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname);
        void characters(LPCWSTR const chars, const unsigned int length);

    private:
        void MetadataRead(LPCWSTR const localname, const CAttribute* attrs);
        void MainfestRead(LPCWSTR const localname, const CAttribute* attrs);
        void SpineRead(LPCWSTR const localname, const CAttribute* attrs);

    private:
        CDocument* m_pDocument;

        hncstd::wstring m_strTitle;
        hncstd::wstring m_strVaule;

        BOOL m_bMetadataRead;
        BOOL m_bMainFestRead;
        BOOL m_bSpineRead;
    };

    CContentHandler::CContentHandler(CDocument* pDocument) : m_pDocument(pDocument), \
        m_bMetadataRead(FALSE), m_bMainFestRead(FALSE), m_bSpineRead(FALSE)
    {
    }

    CContentHandler::~CContentHandler()
    {
    }

    void CContentHandler::MetadataRead(LPCWSTR const localname, const CAttribute* attrs)
    {
        if (_ustrcmp(localname, L"title") == 0) {
            m_strTitle = L"title";
        } else if (_ustrcmp(localname, L"creator") == 0) {
            m_strTitle = L"creator";
        } else if (_ustrcmp(localname, L"publisher") == 0) {
            m_strTitle = L"publisher";
        } else if (_ustrcmp(localname, L"language") == 0) {
            m_strTitle = L"language";
        } else if (_ustrcmp(localname, L"subject") == 0) {
            m_strTitle = L"subject";
        } else if (_ustrcmp(localname, L"description") == 0) {
            m_strTitle = L"description";
        } else if (_ustrcmp(localname, L"meta") == 0) {
            m_strTitle = attrs->getValue(L"name");
        } else {
            m_strTitle.clear();
        }
    }

    void CContentHandler::MainfestRead(LPCWSTR const localname, const CAttribute* attrs)
    {
        if (m_pDocument) {
            if (_ustrcmp(localname, L"item") == 0) {
                CManifest manifest;
                BOOL bEmbedded = FALSE;
                LPCWSTR strEmbedded = attrs->getValue(L"isEmbeded");
                if (strEmbedded != NULL) {
                    if ((_ustricmp(attrs->getValue(L"isEmbeded"), L"true") == 0) || (_ustricmp(attrs->getValue(L"isEmbeded"), L"1") == 0))
                        bEmbedded = TRUE;
                }

                manifest.SetData(attrs->getValue(L"id"), attrs->getValue(L"href"), attrs->getValue(L"media-type"), \
                    bEmbedded, attrs->getValue(L"sub-path"));
                m_pDocument->AddManifest(manifest);
            }
        }
    }

    void CContentHandler::SpineRead(LPCWSTR const localname, const CAttribute* attrs)
    {
        if (m_pDocument) {
            if (_ustrcmp(localname, L"itemref") == 0) {
                m_pDocument->GetSpine()->AddSpine(attrs->getValue(L"idref"));
            }
        }
    }

    void CContentHandler::startElement(LPCWSTR const /*uri*/, LPCWSTR const localname, LPCWSTR const /*qname*/, const CAttribute* attrs)
    {
        if (m_bMetadataRead == TRUE) {
            SpineRead(localname, attrs);
        } else if (m_bMainFestRead == TRUE) {
            MainfestRead(localname, attrs);
        } else if (m_bSpineRead == TRUE) {
            SpineRead(localname, attrs);
        } else {
            if (!m_bMetadataRead && (_ustrcmp(localname, L"metadata") == 0)) {
                m_bMetadataRead = TRUE;
            } else if (!m_bMainFestRead && (_ustrcmp(localname, L"manifest")) == 0) {
                m_bMainFestRead = TRUE;
            } else if (!m_bSpineRead && (_ustrcmp(localname, L"spine") == 0)) {
                m_bSpineRead = TRUE;
            }
        }
    }

    void CContentHandler::endElement(LPCWSTR const /*uri*/, LPCWSTR const localname, LPCWSTR const /*qname*/)
    {
        if (m_bMetadataRead) {
            if (_ustrcmp(localname, L"metadata") == 0) {
                m_bMetadataRead = FALSE;
            } else {
                if ((!m_strTitle.empty()) && (!m_strVaule.empty())) {
                    if (m_pDocument) {
                        m_pDocument->GetMetadata()->AddMetaData(m_strTitle.c_str(), m_strVaule.c_str());
                    }
                }
            }
        } else if (m_bMainFestRead && (_ustrcmp(localname, L"manifest")) == 0) {
            m_bMainFestRead = FALSE;
        } else if (m_bSpineRead && (_ustrcmp(localname, L"spine") == 0)) {
            m_bSpineRead = FALSE;
        }
    }

    void CContentHandler::characters(LPCWSTR const chars, const unsigned int length)
    {
        if (m_bMetadataRead) {
            m_strVaule.assign(chars, length);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CHistoryHandler 핸들러
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    class CHistoryHandler : public CHandler
    {
    public:
        CHistoryHandler();
        virtual ~CHistoryHandler();

    public:
        virtual void startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs);
        virtual void endElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname);
        virtual void characters(LPCWSTR const chars, const unsigned int length);

    private:
        BOOL m_InnerDeleteType;
        hncstd::wstring m_strValue;
    };

    CHistoryHandler::CHistoryHandler() : m_InnerDeleteType(FALSE), m_strValue()
    {
    }

    CHistoryHandler::~CHistoryHandler()
    {
    }

    void CHistoryHandler::startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs)
    {
        CObjectFactory* pfactory = NULL;
        pfactory = m_pFactory.top();

        if (pfactory && pfactory->GetObject()->GetID() == ID_HISTORY_DeleteType) {
            m_curobject = NULL;
            pfactory = NULL;

            m_pFactory.push(pfactory);
            m_elementlevel++;
        } else {
            CHandler::startElement(uri, localname, qname, attrs);
        }

        if (m_InnerDeleteType) {
            hncstd::wstring strstart;
            UINT attrNum = attrs->getLength();

            if (attrNum > 0) {
                hncstd::wstring strtemp;
                strstart = L'<';
                strstart += qname;

                for (UINT i = 0; i < attrNum; ++i) {
                    strstart.append(L" ");
                    strstart.append(attrs->getQName(i));
                    strstart.append(L"=\"");
                    strstart.append(attrs->getValue(i));
                    strstart.append(L"\"");

                    strstart.append(strtemp);
                }

                strstart.append(L">");
            } else {
                strstart.append(L"<");
                strstart.append(qname);
                strstart.append(L">");
            }
            m_strValue.append(strstart);
        }

        if (m_curobject && m_curobject->GetID() == ID_HISTORY_DeleteType && !_ustrcmp(qname, L"hhs:delete")) {
            _ASSERTE(!m_InnerDeleteType);

            m_InnerDeleteType = TRUE;
            m_strValue = L"";
        }
    }

    void CHistoryHandler::endElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname)
    {
        if (!_ustrcmp(qname, L"hhs:delete")) {
            _ASSERTE(m_InnerDeleteType);
            _ASSERTE(m_curobject && m_curobject->GetID() == ID_HISTORY_DeleteType);

            if (m_curobject && m_curobject->GetID() == ID_HISTORY_DeleteType) {
                static_cast<CDeleteType*>(m_curobject)->Setval(m_strValue.c_str());
            }

            m_InnerDeleteType = FALSE;
            m_strValue = L"";
        }

        if (m_InnerDeleteType) {
            hncstd::wstring strend;
            strend.append(L"</");
            strend.append(qname);
            strend.append(L">");
            m_strValue.append(strend);
        }

        CHandler::endElement(uri, localname, qname);
    }

    void CHistoryHandler::characters(LPCWSTR const chars, const unsigned int length)
    {
        if (m_InnerDeleteType) {
            m_strValue.append(chars, length);
        }

        CHandler::characters(chars, length);
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // CDocument
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    CDocument::CDocument() : m_bEncrypt(FALSE), m_nCanonType(0), m_nSignatureType(0), m_nSigHashType(0)
    {
        m_pSaxReader = CreateSaxReader();
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        m_pfCheckMalware = NULL;
#else
        m_pMalwareChecker = NULL;
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
    }

    CDocument::~CDocument()
    {
#ifdef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (m_pMalwareChecker) {
            HncReleaseMalwareChecker(m_pMalwareChecker);
        }
#endif //#ifdef _CHECK_MALWARE_USING_SPLITE_BUFFER_

        if (m_pSaxReader) {
            ReleaseSaxReader(m_pSaxReader);
        }

        std::map<hncstd::wstring, CEncryptInfo*>::iterator iter;
        for (iter = m_EncryptData.begin(); iter != m_EncryptData.end(); ++iter) {
            delete iter->second;
        }

        OWPML::QuitSerialzeThreadMgr();
    }


    BOOL CDocument::Detect(LPCWSTR path)
    {
        // mimetype의 내용을 확인하다.
        return _Readminetype(path);
    }

    BOOL CDocument::Open(LPCWSTR path)
    {
        // Zip Open
        return m_unzip.OpenZipFile(path);
    }

    BOOL CDocument::Read(LPCWSTR path)
    {
        CPartNameSpaceInfo::GetMgr()->SetApplicationNs(str_HWPML_OOXMLCHART_NAMESPACE, CPartNameSpaceInfo::GetMgr()->FindStandardPrefixFromNamespace(str_HWPML_OOXMLCHART_NAMESPACE));
        CPartNameSpaceInfo::GetMgr()->SetApplicationNs(str_HWPML_PARAGRAPH10_NAMESPACE, CPartNameSpaceInfo::GetMgr()->FindStandardPrefixFromNamespace(str_HWPML_PARAGRAPH10_NAMESPACE));
        CPartNameSpaceInfo::GetMgr()->SetApplicationNs(str_HWPML_HWPUNITCHAR_NAMESPACE, CPartNameSpaceInfo::GetMgr()->FindStandardPrefixFromNamespace(str_HWPML_HWPUNITCHAR_NAMESPACE));



        m_bEncrypt = FALSE;
        // Zip Open
        if (!m_unzip.OpenZipFile(path))
            return FALSE;

        if (!_ReadManifest())
            return FALSE;

        // container.xml
        if (!_Readcontainer())
            return FALSE;

        // content.hpf ==> Docinfo, package
        if (!_Readcontent())
            return FALSE;

        return TRUE;
    }

    void CDocument::ReadFileClose()
    {
        m_unzip.CloseFile();
    }

    BOOL CDocument::WriteFileCreate(LPCWSTR path)
    {
        return m_zip.CreareZipFile(path);
    }

    BOOL CDocument::WriteFileAdd(LPCWSTR zippath, LPCWSTR localpath, LPCWSTR type, LPCWSTR /*idstring*/, BOOL bCompress, BOOL bEncrypt)
    {
        if (m_zip.FindFile(zippath) == TRUE) {
            return FALSE;
        }

        CEncryptInfo* pencryptinfo = _CreateEncryptinfo(zippath, localpath, type, bEncrypt);

        if (m_zip.Compress(zippath, localpath, bCompress, pencryptinfo)) {
            if (pencryptinfo) {
                pencryptinfo->finial();
                SetEncryptData(zippath, pencryptinfo);
            }

            return TRUE;
        }

        if (pencryptinfo)
            delete pencryptinfo;

        return FALSE;
    }

    BOOL CDocument::WriteBufferAdd(LPCWSTR zippath, char* buffer, int cnt, LPCWSTR type, LPCWSTR /*idstring*/, BOOL bCompress, BOOL bEncrypt)
    {
        CEncryptInfo* pencryptinfo = _CreateEncryptinfo(zippath, buffer, cnt, type, bEncrypt);

        if (m_zip.Compress(zippath, (void*)buffer, cnt, bCompress, pencryptinfo)) {
            if (pencryptinfo) {
                pencryptinfo->finial();
                SetEncryptData(zippath, pencryptinfo);
            }

            return TRUE;
        }

        if (pencryptinfo)
            delete pencryptinfo;

        return FALSE;
    }

    void CDocument::WriteFileClose()
    {
        m_zip.CloseFile();
    }

    BOOL CDocument::FindFile(LPCWSTR zippath, BOOL bload)
    {
        if (bload)
            return m_zip.FindFile(zippath);
        else
            return m_unzip.FindFile(zippath);
    }



    BOOL CDocument::_Readminetype(LPCWSTR path)
    {
        HZIP hzip = OpenZip(path, NULL);
        if (hzip == 0)
            return FALSE;

        BYTE buffer[256] = { 0, };
        ZIPENTRY mimetype;
        int index = 0;

        // mimetype
        if (FindZipItem(hzip, L"mimetype", false, &index, &mimetype) == ZR_OK) {
            if (UnzipItem(hzip, index, buffer, mimetype.comp_size) == ZR_OK) {
                int size = strlen("application/hwp+zip");
                if (memcmp(buffer, "application/hwp+zip", size) == 0) {
                    CloseZip(hzip);
                    return TRUE;
                }
            }
        }

        CloseZip(hzip);
        return FALSE;
    }

    BOOL CDocument::_Readversion()
    {
        CVersionHandler handler(&m_version);

        return Parse(L"version.xml", &handler);
    }

    BOOL CDocument::_Readcontainer()
    {
        CContainerHandler handler(this);

        return Parse(L"META-INF/container.xml", &handler);
    }

    BOOL CDocument::_Readcontent()
    {
        CContentHandler handler(this);

        return Parse(m_pRootFile.c_str(), &handler);
    }

    BOOL CDocument::_ReadManifest(void)
    {
        OWPML::CODFManifest manifest;
        if (Parse(L"META-INF/manifest.xml", &manifest)) {
            OWPML::Objectlist fileentrylist;
            int i, count = (int)manifest.GetObjectListByID(ID_ODF_FileEntry, fileentrylist);
            for (i = 0; i < count; i++) {
                OWPML::CFileEntry* pfileentry = (OWPML::CFileEntry*)fileentrylist[i];
                if (pfileentry) {
                    OWPML::CEncryptInfo* pencryptinfo = GetEncryptInfo(pfileentry);
                    if (pencryptinfo) {
                        m_bEncrypt = TRUE;
                    }
                }
            }
        }

        return TRUE;
    }

    BOOL CDocument::SetEncryptInfo(OWPML::CConfigItemSet* pconfigitemset, CEncryptInfo* pencryptinfo)
    {
#ifdef OS_UNIX
        HNC_STR_CONV;
#endif
        pconfigitemset->SetName(L"ModifyPasswordInfo");

        // alroritm-name
        if (pencryptinfo->m_algorithmname == CEncryptInfo::Cipher_PBKDF2) {
            CConfigItem* pconfigitem = pconfigitemset->Setconfigitem();
            if (pconfigitem == NULL)
                return NULL;

            pconfigitem->SetName(L"algorithm-name");
            pconfigitem->SetType(L"string");
            pconfigitem->Setval(L"PBKDF2");
        }

        // salt
        if (pencryptinfo->m_salt.size() > 0) {
            CConfigItem* pconfigitem = pconfigitemset->Setconfigitem();
            if (pconfigitem == NULL)
                return NULL;

            pconfigitem->SetName(L"salt");
            pconfigitem->SetType(L"base64Binary");

            char *pBase64String;
            long nSrcCnt, nDesCnt;

            nSrcCnt = pencryptinfo->m_salt.size();
            HNCALLOCAEX(pBase64String, char *, (nSrcCnt * 3 + 5), 1);
            /*_CAutoFreeMalloca afm;
            pBase64String = (char *)_malloca(nSrcCnt * 3 + 5);
            afm.AddAddress(pBase64String);*/
            nDesCnt = HncAsciiToBase64((char*)pencryptinfo->m_salt.data(), nSrcCnt, &pBase64String);

            pconfigitem->Setval(_A2U(pBase64String));
        }

        // iterator-count
        if (pencryptinfo->m_iterationcount > 0) {
            CConfigItem* pconfigitem = pconfigitemset->Setconfigitem();
            if (pconfigitem == NULL)
                return NULL;

            pconfigitem->SetName(L"iteration-count");
            pconfigitem->SetType(L"int");
            WCHAR temstring[40];
            _uitoa_s(pencryptinfo->m_iterationcount, temstring, 40);
            pconfigitem->Setval(temstring);
        }

        // hash
        if (pencryptinfo->m_hash.size() > 0) {
            CConfigItem* pconfigitem = pconfigitemset->Setconfigitem();
            if (pconfigitem == NULL)
                return NULL;

            pconfigitem->SetName(L"hash");
            pconfigitem->SetType(L"base64Binary");

            char *pBase64String;
            long nSrcCnt, nDesCnt;

            nSrcCnt = pencryptinfo->m_hash.size();
            HNCALLOCAEX(pBase64String, char *, (nSrcCnt * 3 + 5), 1);
            /*_CAutoFreeMalloca afm;
            pBase64String = (char *)_malloca(nSrcCnt * 3 + 5);
            afm.AddAddress(pBase64String);*/
            nDesCnt = HncAsciiToBase64((char*)pencryptinfo->m_hash.data(), nSrcCnt, &pBase64String);

            pconfigitem->Setval(_A2U(pBase64String));
        }

        return TRUE;
    }

    BOOL CDocument::GetEncryptInfo(OWPML::CConfigItemSet* pconfigitemset, OWPML::CEncryptInfo* pencryptinfo)
    {
#ifdef OS_UNIX
        HNC_STR_CONV;
#endif
        if (pconfigitemset == NULL || pencryptinfo == NULL)
            return NULL;

        if (_ustrcmp(pconfigitemset->GetName(), L"ModifyPasswordInfo") != 0)
            return NULL;

        pencryptinfo->Init();

        pencryptinfo->m_filename = L"ModifyPasswordInfo";

        int len = 0;
        char buffer[64] = { 0, };
        char* tempbuffer = buffer;
        LPCWSTR value = NULL, type = NULL, name = NULL;

        OWPML::Objectlist configitemlist;
        int i, count = (int)pconfigitemset->GetObjectListByID(ID_ODF_ConfigItem, configitemlist);
        for (i = 0; i < count; i++) {
            OWPML::CConfigItem* pconfigitem = (OWPML::CConfigItem*)configitemlist[i];
            if (pconfigitem == NULL)
                continue;

            name = pconfigitem->GetName();
            value = pconfigitem->Getval();
            type = pconfigitem->GetType();

            if (_ustrcmp(name, L"algorithm-name") == 0) { // algorithm-name
                if ((_ustrcmp(value, L"PBKDF2") == 0) && (_ustrcmp(type, L"string") == 0)) {
                    pencryptinfo->m_algorithmname = OWPML::CEncryptInfo::Cipher_PBKDF2;
                }
            } else if (_ustrcmp(name, L"salt") == 0) { // salt
                if (_ustrcmp(type, L"base64Binary") == 0) {
                    len = HncBase64ToAscii(_U2A(value), &tempbuffer);
                    if (len > 0) {
                        pencryptinfo->m_salt.assign(tempbuffer, tempbuffer + len);
                    }
                }
            } else if (_ustrcmp(name, L"iteration-count") == 0) { // iteration-count
                if (_ustrcmp(type, L"int") == 0) {
                    pencryptinfo->m_iterationcount = _uatoi(value);
                }
            } else if (_ustrcmp(name, L"hash") == 0) { // hash
                if (_ustrcmp(type, L"base64Binary") == 0) {
                    len = HncBase64ToAscii(_U2A(value), &tempbuffer);
                    if (len > 0) {
                        pencryptinfo->m_hash.assign(tempbuffer, tempbuffer + len);
                    }
                }
            }
        }

        return TRUE;
    }


    BOOL CDocument::SetEncryptInfo(OWPML::CFileEntry* pfileentry, CEncryptInfo* pencryptinfo)
    {
#ifdef OS_UNIX
        HNC_STR_CONV;
#endif
        // "encryptiondata"
        CEncryptionData* pencryptiondata = CEncryptionData::Create();
        if (pencryptiondata == NULL)
            return FALSE;


        if (pencryptiondata) {
            if (pencryptinfo->m_checksumtype == CEncryptInfo::CSHash_SHA256_1K) {
                pencryptiondata->SetChecksumType(L"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#sha256-1k");
            }

            // "initialisation-vector"
            char *pBase64String;
            long nSrcCnt, nDesCnt;

            nSrcCnt = pencryptinfo->m_checksum.size();
            HNCALLOCAEX(pBase64String, char *, (nSrcCnt * 3 + 5), 1);
            /*_CAutoFreeMalloca afm;
            pBase64String = (char *)_malloca(nSrcCnt * 3 + 5);
            afm.AddAddress(pBase64String);*/
            nDesCnt = HncAsciiToBase64((char*)pencryptinfo->m_checksum.data(), nSrcCnt, &pBase64String);

            pencryptiondata->SetChecksum(_A2U(pBase64String));
        }

        // "algorithm"
        CAlgorithm* palgorithm = CAlgorithm::Create();
        if (palgorithm) {
            // "algorithm-name"
            if (pencryptinfo->m_algorithmname == CEncryptInfo::Cipher_AES256) {
                palgorithm->SetAlgorithmName(L"http://www.w3.org/2001/04/xmlenc#aes256-cbc");
            } else if (pencryptinfo->m_algorithmname == CEncryptInfo::Cipher_AES192) {
                palgorithm->SetAlgorithmName(L"http://www.w3.org/2001/04/xmlenc#aes192-cbc");
            } else if (pencryptinfo->m_algorithmname == CEncryptInfo::Cipher_AES128) {
                palgorithm->SetAlgorithmName(L"http://www.w3.org/2001/04/xmlenc#aes128-cbc");
            }

            // "initialisation-vector"
            char *pBase64String;
            long nSrcCnt, nDesCnt;

            nSrcCnt = pencryptinfo->m_initvector.size();
            HNCALLOCAEX(pBase64String, char *, (nSrcCnt * 3 + 5), 1);
            /*_CAutoFreeMalloca afm;
            pBase64String = (char *)_malloca(nSrcCnt * 3 + 5);
            afm.AddAddress(pBase64String);*/
            nDesCnt = HncAsciiToBase64((char*)pencryptinfo->m_initvector.data(), nSrcCnt, &pBase64String);

            palgorithm->SetInitVector(_A2U(pBase64String));

            pencryptiondata->SetObject(palgorithm);
        }

        // "keyderivation"
        CKeyDerivation* pkeyderivation = CKeyDerivation::Create();
        if (pkeyderivation) {
            // "key-derivation-name"
            if (pencryptinfo->m_keyderivationname == CEncryptInfo::KeyDerivation_PBKDF2) {
                pkeyderivation->SetKeyDerivationName(L"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#pbkdf2");
            }

            // "key-size"
            pkeyderivation->SetKeySize(pencryptinfo->m_keysizeofdrivation);

            // "iteration-count"
            pkeyderivation->SetIterCount(pencryptinfo->m_iterationcount);

            // "salt"
            char *pBase64String;
            long nSrcCnt, nDesCnt;

            nSrcCnt = pencryptinfo->m_salt.size();
            HNCALLOCAEX(pBase64String, char *, (nSrcCnt * 3 + 5), 1);
            /*_CAutoFreeMalloca afm;
            pBase64String = (char *)_malloca(nSrcCnt * 3 + 5);
            afm.AddAddress(pBase64String);*/
            nDesCnt = HncAsciiToBase64((char*)pencryptinfo->m_salt.data(), nSrcCnt, &pBase64String);

            pkeyderivation->SetSalt(_A2U(pBase64String));

            pencryptiondata->SetObject(pkeyderivation);
        }

        // "startkeygeneration"
        CStartKeyGerneration* pstartkeygerneration = CStartKeyGerneration::Create();
        if (pstartkeygerneration) {
            // "startkeygeneration"
            if (pencryptinfo->m_keygenerationname == CEncryptInfo::Hash_SHA256) {
                pstartkeygerneration->SetStartkeyGenerationName(L"http://www.w3.org/2000/09/xmldsig#sha256");
            }

            // size
            pstartkeygerneration->SetKeySize(pencryptinfo->m_keysizeofgerneration);

            pencryptiondata->SetObject(pstartkeygerneration);
        }

        pfileentry->SetObject(pencryptiondata);

        return TRUE;
    }

    OWPML::CEncryptInfo* CDocument::GetEncryptInfo(OWPML::CFileEntry* pfileentry)
    {
#ifdef OS_UNIX
        HNC_STR_CONV;
#endif
        // "encryptiondata"
        CEncryptionData* pencryptiondata = pfileentry->Getencryptiondata();
        if (pencryptiondata == NULL)
            return NULL;

        OWPML::CEncryptInfo* pencryptinfo = new OWPML::CEncryptInfo;
        pencryptinfo->Init();

        int len = 0;
        char buffer[64] = { 0, };
        char* tempbuffer = buffer;
        LPCWSTR attvalue = NULL;

        if (pencryptiondata) {
            attvalue = pencryptiondata->GetChecksumType();
            if (_ustricmp(attvalue, L"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#sha256-1k") == 0) {
                pencryptinfo->m_checksumtype = OWPML::CEncryptInfo::CSHash_SHA256_1K;
            }

            // check sum
            len = HncBase64ToAscii(_U2A(pencryptiondata->GetChecksum()), &tempbuffer);
            if (len > 0) {
                pencryptinfo->m_checksum.assign(tempbuffer, tempbuffer + len);
            }
        }

        // "algorithm"
        CAlgorithm* palgorithm = pencryptiondata->Getalgorithm();
        if (palgorithm) {
            // "algorithm-name"
            attvalue = palgorithm->GetAlgorithmName();
            if (_ustricmp(attvalue, L"http://www.w3.org/2001/04/xmlenc#aes256-cbc") == 0) {
                pencryptinfo->m_algorithmname = CEncryptInfo::Cipher_AES256;
            } else if (_ustricmp(attvalue, L"http://www.w3.org/2001/04/xmlenc#aes192-cbc") == 0) {
                pencryptinfo->m_algorithmname = CEncryptInfo::Cipher_AES192;
            } else if (_ustricmp(attvalue, L"http://www.w3.org/2001/04/xmlenc#aes128-cbc") == 0) {
                pencryptinfo->m_algorithmname = CEncryptInfo::Cipher_AES128;
            }

            // initialisation-vector
            len = HncBase64ToAscii(_U2A(palgorithm->GetInitVector()), &tempbuffer);
            if (len > 0) {
                pencryptinfo->m_initvector.assign(tempbuffer, tempbuffer + len);
            }
        }

        // "keyderivation"
        CKeyDerivation* pkeyderivation = pencryptiondata->Getkeyderivation();
        if (pkeyderivation) {
            // "key-derivation-name"
            if (_ustricmp(pkeyderivation->GetKeyDerivationName(), L"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0#pbkdf2") == 0) {
                pencryptinfo->m_keyderivationname = CEncryptInfo::KeyDerivation_PBKDF2;
            }

            // "key-size"
            pencryptinfo->m_keysizeofdrivation = pkeyderivation->GetKeySize();

            // "iteration-count"
            pencryptinfo->m_iterationcount = pkeyderivation->GetIterCount();

            // "salt"
            len = HncBase64ToAscii(_U2A(pkeyderivation->GetSalt()), &tempbuffer);
            if (len > 0) {
                pencryptinfo->m_salt.assign(tempbuffer, tempbuffer + len);
            }
        }

        // "startkeygeneration"
        CStartKeyGerneration* pstartkeygerneration = pencryptiondata->Getstartkeygernation();
        if (pstartkeygerneration) {
            // "startkeygeneration"
            if (_ustricmp(pstartkeygerneration->GetStartkeyGenerationName(), L"http://www.w3.org/2000/09/xmldsig#sha256") == 0) {
                pencryptinfo->m_keygenerationname = CEncryptInfo::Hash_SHA256;
            }

            // size
            pencryptinfo->m_keysizeofgerneration = pstartkeygerneration->GetKeySize();
        }

        pencryptinfo->m_filesize = pfileentry->GetSize();
        pencryptinfo->m_filename = pfileentry->GetFullPath();
        pencryptinfo->m_filetype = pfileentry->GetMediaType();
        SetEncryptData(pencryptinfo->m_filename.c_str(), pencryptinfo);

        return pencryptinfo;
    }

    BOOL CDocument::CheckWitePassword(CEncryptInfo* pencryptinfo)
    {
        if (pencryptinfo == NULL)
            return FALSE;

        if (m_strwritepassword.length() <= 0)
            return FALSE;

        if (m_strwritepassword[0]) {
            char key[64] = { 0, };
            HNC_PBKDF2_SHA1((const char*)m_strwritepassword.c_str(), m_strwritepassword.length(), pencryptinfo->m_salt.data(), pencryptinfo->m_salt.size(), pencryptinfo->m_iterationcount, key, pencryptinfo->m_hash.size());

            // key pinitout 비교 같으면 쓰기 암호  성공
            if (memcmp(key, pencryptinfo->m_hash.data(), pencryptinfo->m_hash.size()) == 0)
                return TRUE;
        }

        return FALSE;
    }

    CEncryptInfo* CDocument::CreateEncryptinfo()
    {
        if (m_strwritepassword.length() <= 0)
            return NULL;

        CEncryptInfo* pencryptinfo = NULL;
        if (m_strwritepassword[0]) {
            pencryptinfo = new CEncryptInfo;
            if (pencryptinfo) {
                pencryptinfo->Init();

                pencryptinfo->m_filename = L"ModifyPasswordInfo";

                // salt
                BYTE tempbuffer[32] = { 0, };

                pencryptinfo->randomizeBuffer(tempbuffer, 0x10);
                pencryptinfo->m_salt.assign(&tempbuffer[0], &tempbuffer[0x10]);
                pencryptinfo->m_iterationcount = 1024;
                pencryptinfo->m_algorithmname = CEncryptInfo::Cipher_PBKDF2;

                char hash[64] = { 0, };
                HNC_PBKDF2_SHA1((const char*)m_strwritepassword.c_str(), m_strwritepassword.length(), pencryptinfo->m_salt.data(), pencryptinfo->m_salt.size(), pencryptinfo->m_iterationcount, hash, 16);

                pencryptinfo->m_hash.assign(&hash[0], &hash[16]);
            }
        }

        return pencryptinfo;
    }

    CEncryptInfo* CDocument::_CreateEncryptinfo(LPCWSTR zippath, LPCWSTR localpath, LPCWSTR type, BOOL bEncrypt)
    {
        CEncryptInfo* pencryptinfo = NULL;
        if (type == NULL)
            type = L"";

        if (bEncrypt == FALSE)
            return NULL;

        if ((GetPassword() == NULL) || strlen(GetPassword()) <= 0)
            return NULL;

        pencryptinfo = new CEncryptInfo;
        if (pencryptinfo) {
            pencryptinfo->m_filename = zippath;
            pencryptinfo->m_filetype = type;
            pencryptinfo->m_password = GetPassword();

            // check sum           
            char readbuffer[1024] = { 0, };
            DWORD red;
            HANDLE hFile = CreateFile(localpath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
            if (hFile) {
                if (ReadFile(hFile, readbuffer, 1024, &red, NULL)) {
                    _CreateChecksum(pencryptinfo, readbuffer, red);
                }
                CloseHandle(hFile);
            }

            /*char readbuffer[1024] = { 0, };
            size_t readlen = 0;

            FILE* fchecksum = _ufopen(localpath, L"rb");
            if (fchecksum) {
                readlen = fread(readbuffer, 1, 1024, fchecksum);
                fclose(fchecksum);

                _CreateChecksum(pencryptinfo, readbuffer, readlen);
            }*/
        }

        return pencryptinfo;
    }

    CEncryptInfo* CDocument::_CreateEncryptinfo(LPCWSTR zippath, char* buffer, int len, LPCWSTR type, BOOL bEncrypt)
    {
        CEncryptInfo* pencryptinfo = NULL;
        if (type == NULL)
            type = L"";

        if (bEncrypt == FALSE)
            return NULL;

        if ((GetPassword() == NULL) || strlen(GetPassword()) <= 0)
            return NULL;

        pencryptinfo = new CEncryptInfo;
        if (pencryptinfo) {
            pencryptinfo->m_filename = zippath;
            pencryptinfo->m_filetype = type;
            pencryptinfo->m_password = GetPassword();

            // check sum
            if (len > 1024)
                len = 1024;

            _CreateChecksum(pencryptinfo, buffer, len);
        }

        return pencryptinfo;
    }

    void CDocument::_CreateChecksum(CEncryptInfo* pencryptinfo, char* pbuffer, int len)
    {
        BYTE plantextOut[64] = { 0, };

        HNC_SHA256_ALG_INFO sha11;
        HNC_SHA256_Init(&sha11);
        HNC_SHA256_Update(&sha11, (BYTE*)pbuffer, len);
        HNC_SHA256_Final(&sha11, plantextOut);

        pencryptinfo->m_checksumtype = CEncryptInfo::CSHash_SHA256_1K;
        pencryptinfo->m_checksum.assign(plantextOut, plantextOut + 32);
    }

#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
    BOOL CDocument::_CheckMalware(LPCWSTR zippath)
    {
        BOOL bres = TRUE;
        if (m_pfCheckMalware) {
            const unsigned int BUFBASESIZE = 40960;
            const unsigned int BUFMULTIPLY = 4;
            BOOL bend = FALSE;
            char buffer[BUFFSIZE];
            int readbuffer = 0;
            unsigned int readallbuffer = 0;
            char* allbuffer = NULL;
            char* tmpbuf = NULL;
            unsigned int allbuffersize = BUFBASESIZE;

            allbuffer = (char*)malloc(BUFBASESIZE);
            if (allbuffer) {
                while (Decompress(zippath, buffer, BUFFSIZE, bend, readbuffer)) {
                    if (allbuffersize < readallbuffer + readbuffer) {
                        allbuffersize = allbuffersize * BUFMULTIPLY;
                        tmpbuf = (char*)realloc(allbuffer, allbuffersize);
                        if (tmpbuf == NULL) {
                            break;
                        } else {
                            allbuffer = tmpbuf;
                        }
                    }

                    memcpy_s(allbuffer + readallbuffer, readallbuffer + readbuffer, buffer, readbuffer);
                    readallbuffer += readbuffer;
                }
                if (allbuffer) {
                    bres = m_pfCheckMalware((BYTE*)allbuffer, readallbuffer, L"XMLFile", zippath);
                    if (allbuffer) {
                        free(allbuffer);
                    }
                }
            }
        }
        return bres;
    }
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_

    BOOL CDocument::Parse(LPCWSTR zippath, CDefaultHandler* handler)
    {
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (_CheckMalware(zippath) == FALSE) {
            return FALSE;
        }
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_

        BOOL bend = FALSE;
        char buffer[BUFFSIZE];
        int readbuffer = 0;
        m_pSaxReader->setContentHandler(handler);
        if (m_pSaxReader->parsestart()) {
            while (Decompress(zippath, buffer, BUFFSIZE, bend, readbuffer)) {
                if (readbuffer > 0) {
                    if (!m_pSaxReader->continueparse(buffer, readbuffer, bend)) {
                        m_pSaxReader->parseend();
                        return FALSE;
                    }
                }
            }

            m_pSaxReader->parseend();
        }

        return TRUE;
    }

    BOOL CDocument::Parse(LPCWSTR zippath, OWPML::CObject* pobject)
    {
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (_CheckMalware(zippath) == FALSE) {
            return FALSE;
        }
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_

        BOOL bend = FALSE;
        char buffer[BUFFSIZE];
        int readbuffer = 0;
        CHandler handle;

        CRootObjFactory* pnewfactory = NULL;
        pnewfactory = new CRootObjFactory(pobject);
        handle.AddFactory(pnewfactory);

        m_pSaxReader->setContentHandler(&handle);

        if (m_pSaxReader->parsestart()) {
            while (Decompress(zippath, buffer, BUFFSIZE, bend, readbuffer)) {
                if (readbuffer > 0) {
                    if (!m_pSaxReader->continueparse(buffer, readbuffer, bend)) {
                        m_pSaxReader->parseend();
                        return FALSE;
                    }
                }
            }

            m_pSaxReader->parseend();
        }

        return TRUE;
    }

    BOOL CDocument::FileParse(LPCWSTR path, OWPML::CObject* pobject)
    {
        BOOL bend = FALSE;
        char buffer[BUFFSIZE];
        CHandler handle;
        HANDLE hFile = CreateFile(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile == NULL)
            return FALSE;

        CRootObjFactory* pnewfactory = NULL;
        pnewfactory = new CRootObjFactory(pobject);
        handle.AddFactory(pnewfactory);

        m_pSaxReader->setContentHandler(&handle);

        if (m_pSaxReader->parsestart()) {
            DWORD red;

            while (ReadFile(hFile, buffer, BUFFSIZE, &red, NULL)) {
                if (red == 0)
                    break;

                if (!m_pSaxReader->continueparse(buffer, red, bend)) {
                    m_pSaxReader->parseend();
                    CloseHandle(hFile);
                    return FALSE;
                }
            }

            m_pSaxReader->parseend();
        }

        CloseHandle(hFile);


        /*BOOL bend = FALSE;
        char buffer[1024];
        int readbuffer = 0;
        CHandler handle;
        FILE* hfile = _wfopen(path, L"rb");
        if (hfile == NULL)
            return FALSE;

        CRootObjFactory* pnewfactory = NULL;
        pnewfactory = new CRootObjFactory(pobject);
        handle.AddFactory(pnewfactory);

        m_pSaxReader->setContentHandler(&handle);

        if (m_pSaxReader->parsestart()) {
            fseek(hfile, 0, SEEK_END);
            long flen = ftell(hfile), fpos = 0;
            fseek(hfile, 0, SEEK_SET);

            while ((readbuffer = fread(buffer, 1, 1024, hfile)) > 0) {
                fpos = ftell(hfile);
                bend = fpos >= flen;
                if (readbuffer > 0) {
                    if (!m_pSaxReader->continueparse(buffer, readbuffer, bend)) {
                        m_pSaxReader->parseend();
                        fclose(hfile);
                        return FALSE;
                    }
                }
            }

            m_pSaxReader->parseend();
        }

        fclose(hfile);*/
        return TRUE;
    }

    BOOL CDocument::BufferParse(LPCWSTR buffer, int bufferlen, OWPML::CObject* pobject)
    {
        CHandler handle;
        CRootObjFactory* pnewfactory = NULL;

        if (buffer == NULL || bufferlen <= 0)
            return FALSE;

        pnewfactory = new CRootObjFactory(pobject);
        handle.AddFactory(pnewfactory);

        m_pSaxReader->setContentHandler(&handle);

        if (m_pSaxReader->parsestart()) {
            if (bufferlen > 0) {
                if (!m_pSaxReader->continueparse(buffer, bufferlen, TRUE)) {
                    m_pSaxReader->parseend();
                    return FALSE;
                }
            }

            m_pSaxReader->parseend();
        }

        return TRUE;
    }

    BOOL CDocument::SectionParse(LPCWSTR zippath, LPCWSTR temppath, OWPML::CObject* pobject, CHandler* handler)
    {
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (_CheckMalware(zippath) == FALSE) {
            return FALSE;
        }
#endif
        if (Decompress(zippath, temppath) == FALSE)
            return FALSE;

        CSaxReader* pSaxReader = CreateSaxReader();

        if (pSaxReader == NULL)
            return FALSE;

        DWORD red;
        HANDLE hFile = CreateFile(temppath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hFile) {
            CRootObjFactory* pnewfactory = NULL;
            pnewfactory = new CRootObjFactory(pobject);
            handler->AddFactory(pnewfactory);

            pSaxReader->setContentHandler(handler);

            if (pSaxReader->parsestart()) {
                BOOL bend = FALSE;
                char buffer[BUFFSIZE];

                while (ReadFile(hFile, buffer, BUFFSIZE, &red, NULL)) {
                    if (red == 0)
                        break;
                    if (!pSaxReader->continueparse(buffer, red, bend)) {
                        pSaxReader->parseend();
                        CloseHandle(hFile);
                        ReleaseSaxReader(pSaxReader);
                        return FALSE;
                    }
                }

                pSaxReader->parseend();
            }
            CloseHandle(hFile);
        }

        ReleaseSaxReader(pSaxReader);
        return TRUE;

    }

    BOOL CDocument::HistoryParse(LPCWSTR zippath, OWPML::CObject* pobject)
    {
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (_CheckMalware(zippath) == FALSE) {
            return FALSE;
        }
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_

        BOOL bend = FALSE;
        char buffer[BUFFSIZE];
        int readbuffer = 0;
        CHistoryHandler handle;

        CRootObjFactory* pnewfactory = NULL;
        pnewfactory = new CRootObjFactory(pobject);
        handle.AddFactory(pnewfactory);

        m_pSaxReader->setContentHandler(&handle);

        if (m_pSaxReader->parsestart()) {
            while (m_unzip.Decompress(zippath, buffer, BUFFSIZE, bend, readbuffer)) {
                if (readbuffer > 0) {
                    if (!m_pSaxReader->continueparse(buffer, readbuffer, bend)) {
                        m_pSaxReader->parseend();
                        return FALSE;
                    }
                }
            }

            m_pSaxReader->parseend();
        }

        return TRUE;
    }

    BOOL CDocument::GetDecompressBibPath(LPCWSTR zippath, LPCWSTR temppath)
    {
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (_CheckMalware(zippath) == FALSE) {
            return FALSE;
        }
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_

        if (Decompress(zippath, temppath) == FALSE) {
            return FALSE;
        }

        return TRUE;
    }

    BOOL CDocument::Decompress(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& size)
    {
        CEncryptInfo* pencryptinfo = GetEncryptData(strZippath);
        if (pencryptinfo) {
            if (m_strpassword.length() > 0) {
                pencryptinfo->m_password = m_strpassword.c_str();
                m_unzip.SetEncryptInfo(strZippath, pencryptinfo);
            }
        }

        BOOL bres = m_unzip.Decompress(strZippath, pbuffer, bufferlen, bend, size);

#ifdef _CHECK_MALWARE_USING_SPLITE_BUFFER_
        if (bres == TRUE && m_pMalwareChecker != NULL) {
            bres = m_pMalwareChecker->Check(strZippath, HncGetZipFileType(strZippath), (BYTE*)pbuffer, bufferlen, bend);
        }
#endif //#ifdef _CHECK_MALWARE_USING_SPLITE_BUFFER_

        return bres;
    }

    BOOL CDocument::Decompress(LPCWSTR strZippath, LPCWSTR localpath)
    {
        CEncryptInfo* pencryptinfo = GetEncryptData(strZippath);
        if (pencryptinfo) {
            if (m_strpassword.length() > 0) {
                pencryptinfo->m_password = m_strpassword.c_str();
                m_unzip.SetEncryptInfo(strZippath, pencryptinfo);
            }
        }

        return m_unzip.Decompress(strZippath, localpath);
    }

    BOOL CDocument::GetZipitem(LPCWSTR strZippath, LPCWSTR localpath)
    {
        return m_unzip.GetItem(strZippath, localpath);
    }

    BOOL CDocument::GetZipitem(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& size)
    {
        return m_unzip.GetItem(strZippath, pbuffer, bufferlen, bend, size);
    }

    LPCWSTR CDocument::GetZipImageFilePath(LPCWSTR idstring, BOOL* pEmbed, LPWSTR strtype)
    {
        std::vector<CManifest>::iterator iter;

        for (iter = m_manifest.begin(); iter != m_manifest.end(); ++iter) {
            if (_ustrcmp(iter->GetId(), idstring) == 0) {
                // embed
                if (pEmbed) {
                    *pEmbed = iter->Getemdedded();
                }

                // type
                LPCWSTR mediatype = iter->Gettype();
                if (mediatype) {
                    LPCWSTR type = _ustrrchr(mediatype, L'/');
                    if (type && ++type) {
                        _ustrcpy_s(strtype, _MAX_PATH, type);
                    }
                }
                return iter->Gethref();
            }
        }
        return NULL;
    }
    LPCWSTR CDocument::GetZipFilePath(LPCWSTR idstring)
    {
        std::vector<CManifest>::iterator iter;

        for (iter = m_manifest.begin(); iter != m_manifest.end(); ++iter) {
            if (_ustrcmp(iter->GetId(), idstring) == 0) {
                return iter->Gethref();
            }
        }

        return NULL;
    }

    void CDocument::SetEncryptData(LPCWSTR path, CEncryptInfo* endata)
    {
        std::map<hncstd::wstring, CEncryptInfo*>::iterator fiter;
        fiter = m_EncryptData.find(path);
        if (fiter != m_EncryptData.end()) {
            delete fiter->second;
        }

        m_EncryptData.insert(std::map<hncstd::wstring, CEncryptInfo*>::value_type(path, endata));
    }

    CEncryptInfo* CDocument::GetEncryptData(LPCWSTR path)
    {
        std::map<hncstd::wstring, CEncryptInfo*>::iterator fiter;
        fiter = m_EncryptData.find(path);
        if (fiter != m_EncryptData.end()) {
            return fiter->second;
        }
        return NULL;
    }

#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
    void CDocument::SetCheckMalware(CheckMalware pfCheckMalware)
    {
        m_pfCheckMalware = pfCheckMalware;
    }
#else
    void CDocument::SetCheckMalware(IMalwareChecker* pMalwareChecker)
    {
        if (m_pMalwareChecker) {
            ::HncReleaseMalwareChecker(pMalwareChecker);
        }

        m_pMalwareChecker = pMalwareChecker;
    }
#endif




};