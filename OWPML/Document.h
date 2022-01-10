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

#ifndef _OWPML_DOCUMENT_H_
#define _OWPML_DOCUMENT_H_

static const int BUFFSIZE = 40960;
namespace OWPML {

    class CConfigItemSet;
    class CFileEntry;

    typedef struct version
    {
        hncstd::wstring Application;
        UINT major = 0;
        UINT minor = 0;
        UINT micro = 0;
        UINT buildNumber = 0;
    } OW_Version;

    class CMetaData
    {
    public:
        void AddMetaData(LPCWSTR title, LPCWSTR value)
        {
            m_mMetadata.insert(std::map<hncstd::wstring, hncstd::wstring>::value_type(title, value));
        }
        LPCWSTR GetMeataData(LPCWSTR title)
        {
            return m_mMetadata.find(title)->second.c_str();
        }

    private:
        // key, value
        std::map<hncstd::wstring, hncstd::wstring> m_mMetadata;
    };

    class CManifest
    {
    public:
        CManifest() { m_bEmbedded = FALSE; }
        ~CManifest() {}

    public:
        void SetData(LPCWSTR id, LPCWSTR href, LPCWSTR type, BOOL embedded = FALSE, LPCWSTR subpath = NULL)
        {
            m_id = id; m_href = href; m_type = type; m_bEmbedded = embedded;
            if (subpath) m_subpath = subpath;
        }
        void SetId(LPCWSTR id) { m_id = id; }
        void Sethref(LPCWSTR href) { m_href = href; }
        void Settype(LPCWSTR type) { m_type = type; }
        void Setemdedded(BOOL embedded) { m_bEmbedded = embedded; }
        void Setsubpath(LPCWSTR subpath) { m_subpath = subpath; }

        LPCWSTR GetId(void) { return m_id.c_str(); }
        LPCWSTR Gethref(void) { return m_href.c_str(); }
        LPCWSTR Gettype(void) { return m_type.c_str(); }
        BOOL Getemdedded(void) { return m_bEmbedded; }
        LPCWSTR Getsubpath(void) { return m_subpath.c_str(); }

    private:
        hncstd::wstring m_id;
        hncstd::wstring m_href;
        hncstd::wstring m_type;
        BOOL m_bEmbedded;
        hncstd::wstring m_subpath;
    };

    class CSpine
    {
    public:
        CSpine() {}
        ~CSpine() {}

    public:
        void AddSpine(LPCWSTR spine) { m_vSpine.push_back(spine); }
        std::vector<hncstd::wstring>& GetSpine(void) { return m_vSpine; }

    private:
        std::vector<hncstd::wstring> m_vSpine;
    };


    class CDocument// : public COwpmlDocument
    {
    public:
        CDocument();
        ~CDocument();

    public:
        BOOL Detect(LPCWSTR path);

        BOOL Open(LPCWSTR path);
        BOOL Read(LPCWSTR path);
        void ReadFileClose();
        BOOL WriteFileCreate(LPCWSTR path);
        BOOL WriteFileAdd(LPCWSTR zippath, LPCWSTR localpath, LPCWSTR type, LPCWSTR idstring, BOOL bCompress = TRUE, BOOL bEncrypt = TRUE);
        BOOL WriteBufferAdd(LPCWSTR zippath, char* buffer, int cnt, LPCWSTR type, LPCWSTR idstring, BOOL bCompress = TRUE, BOOL bEncrypt = FALSE);
        void WriteFileClose();
        BOOL FindFile(LPCWSTR zippath, BOOL bload);

    public:
        BOOL Parse(LPCWSTR zippath, CDefaultHandler* handler);
        BOOL Parse(LPCWSTR zippath, OWPML::CObject* pobject);
        BOOL FileParse(LPCWSTR path, OWPML::CObject* pobject);
        BOOL BufferParse(LPCWSTR buffer, int bufferlen, OWPML::CObject* pobject);
        BOOL SectionParse(LPCWSTR zippath, LPCWSTR temppath, OWPML::CObject* pobject, CHandler* handler);
        BOOL HistoryParse(LPCWSTR zippath, OWPML::CObject* pobject);
        BOOL GetDecompressBibPath(LPCWSTR zippath, LPCWSTR temppath);


        LPCWSTR GetZipImageFilePath(LPCWSTR idstring, BOOL* pEmbed, LPWSTR strtype);
        LPCWSTR GetZipFilePath(LPCWSTR idstring);
        BOOL Decompress(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& size);
        BOOL Decompress(LPCWSTR strZippath, LPCWSTR localpath);

        BOOL GetZipitem(LPCWSTR strZippath, LPCWSTR localpath);
        BOOL GetZipitem(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& size);

        void SetRootFile(LPCWSTR path) { m_pRootFile = path; }
        CMetaData* GetMetadata(void) { return &m_metadata; }
        void AddManifest(CManifest& manifest) { m_manifest.push_back(manifest); }
        std::vector<CManifest>& GetManifest(void) { return m_manifest; }
        CSpine* GetSpine(void) { return &m_spine; }

        void SetEncryptData(LPCWSTR path, CEncryptInfo* endata);
        CEncryptInfo* GetEncryptData(LPCWSTR path);
        std::map<hncstd::wstring, CEncryptInfo*>* GetEncryptDataCon(void) { return &m_EncryptData; }

        void SetPassword(LPCSTR password) { m_strpassword = password; }
        LPCSTR GetPassword(void) { return m_strpassword.c_str(); }
        void SetWritePassword(LPCSTR password) { m_strwritepassword = password; }
        LPCSTR GetWritePassword(void) { return m_strwritepassword.c_str(); }

        BOOL IsEncryption(void) { return m_bEncrypt; }

        BOOL SetEncryptInfo(OWPML::CConfigItemSet* pconfigitemset, CEncryptInfo* pencryptinfo);
        BOOL GetEncryptInfo(OWPML::CConfigItemSet* pconfigitemset, OWPML::CEncryptInfo* pencryptinfo);

        BOOL SetEncryptInfo(OWPML::CFileEntry* pfileentry, CEncryptInfo* pencryptinfo);
        OWPML::CEncryptInfo* GetEncryptInfo(OWPML::CFileEntry* pfileentry);

        BOOL CheckWitePassword(CEncryptInfo* pencryptinfo);
        CEncryptInfo* CreateEncryptinfo();

        CUnZip* GetUnZip(void) { return &m_unzip; }
        CZip* GetZip(void) { return &m_zip; }

        void SetSignatureKey(LPCWSTR key) { m_sigKey = key; }
        void SetSignaturePrivInfo(LPCWSTR privinfo) { m_sigPrivInfo = privinfo; }
        void SetSignatureCert(LPCWSTR cert) { m_sigCert = cert; }
        void SetSignatureCertAll(LPCWSTR cert) { m_sigCertAll = cert; }
        void SetSignatureCanonType(int canontype) { m_nCanonType = canontype; }
        void SetSignatureType(int sigtype) { m_nSignatureType = sigtype; }
        void SetSignatureHashType(int hashtype) { m_nSigHashType = hashtype; }

        LPCWSTR GetSignatureKey(void) { return m_sigKey.c_str(); }
        LPCWSTR GetSignaturePrivInfo(void) { return m_sigPrivInfo.c_str(); }
        LPCWSTR GetSignatureCert(void) { return m_sigCert.c_str(); }
        LPCWSTR GetSignatureCertAll(void) { return m_sigCertAll.c_str(); }
        int GetSignatureCanonType(void) { return m_nCanonType; }
        int GetSignatureType(void) { return m_nSignatureType; }
        int GetSignatureHashType(void) { return m_nSigHashType; }

    private:
        BOOL _Readminetype(LPCWSTR path);
        BOOL _Readversion();
        BOOL _Readcontainer();
        BOOL _Readcontent();
        BOOL _ReadManifest(void);

        CEncryptInfo* _CreateEncryptinfo(LPCWSTR zippath, LPCWSTR localpath, LPCWSTR type, BOOL bEncrypt);
        CEncryptInfo* _CreateEncryptinfo(LPCWSTR zippath, char* buffer, int len, LPCWSTR type, BOOL bEncrypt);
        void _CreateChecksum(CEncryptInfo* pencryptinfo, char* pbuffer, int len);

    private:
        CSaxReader* m_pSaxReader;
        CUnZip m_unzip;
        CZip m_zip;

        hncstd::wstring m_pRootFile;
        OW_Version m_version;
        CMetaData m_metadata;
        std::vector<CManifest> m_manifest;
        std::map<hncstd::wstring, CEncryptInfo*> m_EncryptData;
        CSpine m_spine;
        hncstd::string m_strpassword;
        hncstd::string m_strwritepassword;
        BOOL m_bEncrypt;

        // signature 
        hncstd::wstring     m_sigKey;
        hncstd::wstring     m_sigPrivInfo;
        hncstd::wstring     m_sigCert;
        hncstd::wstring     m_sigCertAll;
        int             m_nCanonType;
        int             m_nSignatureType;
        int             m_nSigHashType;

        //#define _CHECK_MALWARE_USING_SPLITE_BUFFER_
#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
    private:
        BOOL _CheckMalware(LPCWSTR zippath);
        typedef BOOL(*CheckMalware)(BYTE* pdata, size_t dataLen, LPCWSTR szStreamName, LPCWSTR szpath);
        CheckMalware m_pfCheckMalware;
    public:
        void SetCheckMalware(CheckMalware pfCheckMalware);
#else
    private:
        IMalwareChecker* m_pMalwareChecker;
    public:
        void SetCheckMalware(IMalwareChecker* pMalwareChecker);
#endif //#ifndef _CHECK_MALWARE_USING_SPLITE_BUFFER_
    };

}

#endif //_OWPML_DOCUMENT_H_