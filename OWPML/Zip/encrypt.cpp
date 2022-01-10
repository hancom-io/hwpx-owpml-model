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
#include "encrypt.h"
#include "OWPMLUtil/HncBlowfish.h"

#ifdef _MSC_VER
#pragma once
#include <time.h>
#endif

namespace OWPML {

    void CEncryptInfo::Init()
    {
        ciperclear();
        m_ciper = NULL;
        m_filesize = m_iterationcount = 0;
        m_keysizeofdrivation = 16;
        m_keysizeofgerneration = 20;
        m_zipindex = -1;
        m_filename.empty();
        m_checksumtype = CSHash_Undefined;
        m_algorithmname = Cipher_Undefined;
        m_keyderivationname = KeyDerivation_Undefined;
        m_keygenerationname = Hash_SHA1;
        m_checksum.clear();
        m_initvector.clear();
        m_salt.clear();
        m_hash.clear();
        m_password = 0;
        m_aessize = 0;
        m_bend = false;
    }

    bool CEncryptInfo::decodeInit()
    {
        if (m_password == NULL)
            return false;

        m_bend = false;
        BYTE passbuffer[64] = { 0, };
        BYTE keybuffer[64] = { 0, };

        // password key 생성
        if (m_keygenerationname == CEncryptInfo::Hash_SHA256) {
            HNC_SHA256_ALG_INFO sha256;
            HNC_SHA256_Init(&sha256);
            HNC_SHA256_Update(&sha256, (BYTE*)m_password, strlen(m_password));
            HNC_SHA256_Final(&sha256, passbuffer);
        } else if (m_keygenerationname == CEncryptInfo::Hash_SHA1) {
            HNC_SHA1_ALG_INFO sha1;
            HNC_SHA1_Init(&sha1);
            HNC_SHA1_Update(&sha1, (BYTE*)m_password, strlen(m_password));
            HNC_SHA1_Final(&sha1, passbuffer);
        } else {
            return false;
        }

        //  Key drivation
        if (m_keyderivationname == KeyDerivation_PBKDF2) {
            HNC_PBKDF2_SHA1((const char*)passbuffer, m_keysizeofgerneration, m_salt.data(), m_salt.size(), m_iterationcount, (char*)keybuffer, m_keysizeofdrivation);
        } else {
            return false;
        }

        // init
        ciperclear();
        if ((m_algorithmname == Cipher_AES128) || (m_algorithmname == Cipher_AES192) || (m_algorithmname == Cipher_AES256)) {
            CHncAES* aes = new CHncAES;

            aes->MakeKey((const char*)keybuffer, (const char*)m_initvector.data(), m_keysizeofdrivation, m_initvector.size());
            m_ciper = aes;
        } else {
            m_ciper = NULL;
            return false;
        }

        return true;
    }

    bool CEncryptInfo::encodeInit()
    {
        if (m_password == NULL)
            return false;

        m_bend = false;

        BYTE passbuffer[64] = { 0, };
        BYTE keybuffer[64] = { 0, };
        BYTE tempbuffer[32] = { 0, };

        // salt
        randomizeBuffer(tempbuffer, 0x10);
        m_salt.assign(&tempbuffer[0], &tempbuffer[0x10]);

        // intivector
        randomizeBuffer(tempbuffer, 0x10);
        m_initvector.assign(&tempbuffer[0], &tempbuffer[0x10]);

        m_keygenerationname = CEncryptInfo::Hash_SHA256;
        m_algorithmname = Cipher_AES256;
        m_keysizeofdrivation = 32;
        m_keysizeofgerneration = 32;
        m_iterationcount = 1024;
        m_keyderivationname = KeyDerivation_PBKDF2;

        // password key 생성
        if (m_keygenerationname == CEncryptInfo::Hash_SHA256) {
            HNC_SHA256_ALG_INFO sha256;
            HNC_SHA256_Init(&sha256);
            HNC_SHA256_Update(&sha256, (BYTE*)m_password, strlen(m_password));
            HNC_SHA256_Final(&sha256, passbuffer);
        } else if (m_keygenerationname == CEncryptInfo::Hash_SHA1) {
            HNC_SHA1_ALG_INFO sha1;
            HNC_SHA1_Init(&sha1);
            HNC_SHA1_Update(&sha1, (BYTE*)m_password, strlen(m_password));
            HNC_SHA1_Final(&sha1, passbuffer);
        } else {
            return false;
        }

        //  Key drivation
        if (m_keyderivationname == KeyDerivation_PBKDF2) {
            HNC_PBKDF2_SHA1((const char*)passbuffer, m_keysizeofgerneration, m_salt.data(), m_salt.size(), m_iterationcount, (char*)keybuffer, m_keysizeofdrivation);
        } else {
            return false;
        }

        // init
        ciperclear();
        if ((m_algorithmname == Cipher_AES128) || (m_algorithmname == Cipher_AES192) || (m_algorithmname == Cipher_AES256)) {
            CHncAES* aes = new CHncAES;

            aes->MakeKey((const char*)keybuffer, (const char*)m_initvector.data(), m_keysizeofdrivation, m_initvector.size());
            m_ciper = aes;
        } else {
            m_ciper = NULL;
            return false;
        }

        return true;
    }

    bool CEncryptInfo::decode(unsigned char* buffer, unsigned int size, bool end)
    {
        if ((m_password == NULL) || (m_ciper == NULL))
            return false;

        const unsigned int blocksize = 1024;

        char blockbuffer[blocksize];
        unsigned int readsize = blocksize;
        int totalsize = size;

        bool isAes = ((m_algorithmname == Cipher_AES128) || (m_algorithmname == Cipher_AES192) || (m_algorithmname == Cipher_AES256));

        if (m_ciper == 0)
            return false;

        if (isAes) {
            CHncAES* aes = (CHncAES*)m_ciper;

            while (totalsize > 0) {
                if (totalsize > blocksize) {
                    readsize = blocksize;
                } else {
                    readsize = totalsize;
                }

                if (isAes) {
                    aes->Decrypt((const char*)buffer, (char*)blockbuffer, readsize, CHncAES::CBC);
                }

                memcpy(buffer, blockbuffer, blocksize);
                buffer += readsize;
                totalsize -= readsize;
            }

            if (end) {
                if (isAes) {
                    delete aes;
                }
                m_ciper = NULL;
            }
            return true;
        }

        return false;
    }

    bool CEncryptInfo::encode(unsigned char* buffer, unsigned int size, bool end)
    {
        if ((m_password == NULL) || (m_ciper == NULL))
            return false;

        const unsigned int blocksize = 1024;

        char blockbuffer[blocksize];
        unsigned int readsize = blocksize;
        int totalsize = size;

        bool isAes = ((m_algorithmname == Cipher_AES128) || (m_algorithmname == Cipher_AES192) || (m_algorithmname == Cipher_AES256));

        if (m_ciper == 0)
            return false;

        if (isAes) {
            CHncAES* aes = (CHncAES*)m_ciper;

            while (totalsize > 0) {
                if (totalsize > blocksize) {
                    readsize = blocksize;
                } else {
                    readsize = totalsize;
                }

                if (isAes) {
                    aes->Encrypt((const char*)buffer, (char*)blockbuffer, readsize, CHncAES::CBC);
                }

                memcpy(buffer, blockbuffer, readsize);
                buffer += readsize;
                totalsize -= readsize;
            }

            if (end) {
                if (isAes) {
                    delete aes;
                }
                m_ciper = NULL;
            }
            return true;
        }

        return false;
    }

    void CEncryptInfo::finial()
    {
        bool isAes = ((m_algorithmname == Cipher_AES128) || (m_algorithmname == Cipher_AES192) || (m_algorithmname == Cipher_AES256));
        if (isAes) {
            CHncAES* aes = (CHncAES*)m_ciper;
            delete aes;
        } else {
            HNC_BF_Final(m_ciper);
        }
        m_ciper = NULL;
    }

    void CEncryptInfo::randomizeBuffer(unsigned char* buffer, unsigned int size)
    {
        ::srand((unsigned int)::time(NULL));

        DWORD idx = 0;
        while (idx < size) {
            *(buffer + idx) = (unsigned char)((float)(::rand()) / (float)RAND_MAX * (float)0xff);

            ++idx;
        }
    }

    void CEncryptInfo::ciperclear()
    {
        if (m_ciper != NULL) {
            if ((m_algorithmname == Cipher_AES128) || (m_algorithmname == Cipher_AES192) || (m_algorithmname == Cipher_AES256)) {
                CHncAES* aes = (CHncAES*)m_ciper;
                delete aes;
            }
        }
    }
}
