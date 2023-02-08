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

#ifndef _encrypt_H
#define _encrypt_H

namespace OWPML {

    class CEncryptInfo
    {
    public:
        enum Cipher {
            Cipher_Undefined = 0,
            Cipher_AES128,
            Cipher_AES192,
            Cipher_AES256,
            Cipher_PBKDF2,
        };

        enum Hash {
            Hash_Undefined = 0,
            Hash_SHA1,
            Hash_SHA256,
        };

        enum KeyDerivation {
            KeyDerivation_Undefined = 0,
            KeyDerivation_PBKDF2,
        };

        enum ChecksumHash {
            CSHash_Undefined = 0,
            CSHash_SHA256_1K,
        };

    public:
        CEncryptInfo()
        {
            m_ciper = NULL;
            m_filesize = m_iterationcount = 0;
            m_keysizeofdrivation = 16;
            m_keysizeofgerneration = 20;
            m_zipindex = -1;
            m_checksumtype = CSHash_Undefined;
            m_algorithmname = Cipher_Undefined;
            m_keyderivationname = KeyDerivation_Undefined;
            m_keygenerationname = Hash_SHA1;
            m_password = NULL;
            m_aessize = 0;
            m_bend = false;
        }
        virtual ~CEncryptInfo()
        {
            ciperclear();
        }

    public:
        void Init();

    public:
        bool decodeInit();
        bool encodeInit();
        bool decode(unsigned char* buffer, unsigned int size, bool end);
        bool encode(unsigned char* buffer, unsigned int size, bool end);
        void finial();

        void randomizeBuffer(unsigned char* buffer, unsigned int size);
    private:
        void ciperclear();

    public:
        hncstd::wstring     m_filename;
        hncstd::wstring     m_filetype;
        unsigned int        m_filesize;
        ChecksumHash        m_checksumtype;
        Cipher              m_algorithmname;
        KeyDerivation       m_keyderivationname;
        unsigned int        m_keysizeofdrivation;
        unsigned int        m_iterationcount;
        Hash                m_keygenerationname;
        unsigned int        m_keysizeofgerneration;
        std::vector<char>   m_checksum;
        std::vector<char>   m_initvector;
        std::vector<char>   m_salt;
        std::vector<char>   m_hash;
        int                 m_zipindex;
        const char*         m_password;
        unsigned int        m_aessize;
        bool                m_bend;
    private:
        void*               m_ciper;
    };
}

#endif // _encrypt_H
