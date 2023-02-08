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
#ifndef  _ODF_ELEMENT_H_
#define  _ODF_ELEMENT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CStartKeyGerneration Declaration 
    class CStartKeyGerneration : public CExtObject
    {
    private:
        CStartKeyGerneration();
    public:
        virtual ~CStartKeyGerneration();
        static CStartKeyGerneration* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        LPCWSTR GetStartkeyGenerationName(void) { return m_strStartkeyGenerationName.c_str(); }
        void SetStartkeyGenerationName(LPCWSTR keyname) { m_strStartkeyGenerationName = keyname; }

        UINT GetKeySize(void) { return m_keysize; }
        void SetKeySize(UINT size) { m_keysize = size; }

    private:
        hncstd::wstring m_strStartkeyGenerationName;
        UINT m_keysize;
    };

    // CKeyDerivation Declaration 
    class CKeyDerivation : public CExtObject
    {
    private:
        CKeyDerivation();
    public:
        virtual ~CKeyDerivation();
        static CKeyDerivation* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        LPCWSTR GetKeyDerivationName(void) { return m_strKeyDerivationName.c_str(); }
        void SetKeyDerivationName(LPCWSTR keyderivationname) { m_strKeyDerivationName = keyderivationname; }

        UINT GetKeySize(void) { return m_keysize; }
        void SetKeySize(UINT size) { m_keysize = size; }

        UINT GetIterCount(void) { return m_itercount; }
        void SetIterCount(UINT count) { m_itercount = count; }

        LPCWSTR GetSalt(void) { return m_strSalt.c_str(); }
        void SetSalt(LPCWSTR salt) { m_strSalt = salt; }

    private:
        hncstd::wstring m_strKeyDerivationName;
        UINT        m_keysize;
        UINT        m_itercount;
        hncstd::wstring m_strSalt;
    };

    // CAlgorithm Declaration 
    class CAlgorithm : public CExtObject
    {
    private:
        CAlgorithm();
    public:
        virtual ~CAlgorithm();
        static CAlgorithm* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        LPCWSTR GetAlgorithmName(void) { return m_strAlgorithmName.c_str(); }
        void SetAlgorithmName(LPCWSTR algorithmname) { m_strAlgorithmName = algorithmname; }

        LPCWSTR GetInitVector(void) { return m_strInitVector.c_str(); }
        void SetInitVector(LPCWSTR initvector) { m_strInitVector = initvector; }

    private:
        hncstd::wstring m_strAlgorithmName;
        hncstd::wstring m_strInitVector;
    };

    // CEncryptionData Declaration 
    class CEncryptionData : public CExtObject
    {
    private:
        CEncryptionData();
    public:
        virtual ~CEncryptionData();
        static CEncryptionData* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CAlgorithm* Setalgorithm(CAlgorithm* palgorithm = NULL);
        CAlgorithm* Getalgorithm(int index = 0);

        CKeyDerivation* Setkeyderivation(CKeyDerivation* pkeyderivation = NULL);
        CKeyDerivation* Getkeyderivation(int index = 0);

        CStartKeyGerneration* Setstartkeygernation(CStartKeyGerneration* pstartkeygernation = NULL);
        CStartKeyGerneration* Getstartkeygernation(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetChecksumType(void) { return m_strChecksumType.c_str(); }
        void SetChecksumType(LPCWSTR type) { m_strChecksumType = type; }

        LPCWSTR GetChecksum(void) { return m_strChecksum.c_str(); }
        void SetChecksum(LPCWSTR checksum) { m_strChecksum = checksum; }

    private:
        hncstd::wstring m_strChecksumType;
        hncstd::wstring m_strChecksum;
    };

    // CFileEntry Declaration 
    class CFileEntry : public CExtObject
    {
    public:
        CFileEntry();
    public:
        virtual ~CFileEntry();
        static CFileEntry* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CEncryptionData* Setencryptiondata(CEncryptionData* pencryptriondata = NULL);
        CEncryptionData* Getencryptiondata(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetFullPath(void) { return m_strFullPath.c_str(); }
        void SetFullPath(LPCWSTR fullpath) { m_strFullPath = fullpath; }

        LPCWSTR GetMediaType(void) { return m_strMediaType.c_str(); }
        void SetMediaType(LPCWSTR mediatype) { m_strMediaType = mediatype; }

        UINT GetSize(void) { return m_size; }
        void SetSize(UINT size) { m_size = size; }

    private:
        hncstd::wstring m_strFullPath;
        hncstd::wstring m_strMediaType;
        UINT        m_size;
    };


    // CODFManifest Declaration 
    class CODFManifest : public CNamedObject
    {
    public:
        CODFManifest();
    public:
        virtual ~CODFManifest();
        static CODFManifest* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CFileEntry* Setfileentry(CFileEntry* pfileentry = NULL);
        CFileEntry* Getfileentry(int index = 0);

        // Attribute Set/Get Fucntion
    };


    // CConfigItem Declaration 
    class CConfigItem : public CStringValueObject
    {
    public:
        CConfigItem();
    public:
        virtual ~CConfigItem();
        static CConfigItem* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        LPCWSTR GetType(void) { return m_strType.c_str(); }
        void SetType(LPCWSTR type) { m_strType = type; }

    private:
        hncstd::wstring m_strName;
        hncstd::wstring m_strType;
    };


    // CConfigItemSet Declaration 
    class CConfigItemSet : public CExtObject
    {
    public:
        CConfigItemSet();
    public:
        virtual ~CConfigItemSet();
        static CConfigItemSet* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CConfigItem* Setconfigitem(CConfigItem* pconfigitem = NULL);
        CConfigItem* Getconfigitem(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }


    private:
        hncstd::wstring m_strName;
    };

} // OOXML
#endif // _ODF_ELEMENT_H_
