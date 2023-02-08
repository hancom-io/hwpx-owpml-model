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
#include "HncAES.h"
#include "Rijndael.h"


////////////////////////////////////////////////////////////////////////
// _CHncAESImpl Declaration / Implementation
class _CHncAESImpl : public CRijndael
{
public:
    _CHncAESImpl() : CRijndael() {}
    virtual ~_CHncAESImpl() {}
};


////////////////////////////////////////////////////////////////////////
// CHncAES Implementation
void CHncAES::MakeKey(char const* key, char const* chain/*= NULL*/, int keylength/*= DEFAULT_BLOCK_SIZE*/, int blockSize/*= DEFAULT_BLOCK_SIZE*/)
{
    if (!chain)
        chain = CRijndael::sm_chain0;

    return m_pImpl->MakeKey(key, chain, keylength, blockSize);
}

void CHncAES::EncryptBlock(char const* in, char* result)
{
    return m_pImpl->EncryptBlock(in, result);
}

void CHncAES::DecryptBlock(char const* in, char* result)
{
    return m_pImpl->DecryptBlock(in, result);
}

void CHncAES::Encrypt(char const* in, char* result, size_t n, int iMode/*= ECB*/)
{
    return m_pImpl->Encrypt(in, result, n, iMode);
}

void CHncAES::Decrypt(char const* in, char* result, size_t n, int iMode/*= ECB*/)
{
    return m_pImpl->Decrypt(in, result, n, iMode);
}

int CHncAES::GetKeyLength()
{
    return m_pImpl->GetKeyLength();
}

int CHncAES::GetBlockSize()
{
    return m_pImpl->GetBlockSize();
}

int CHncAES::GetRounds()
{
    return m_pImpl->GetRounds();
}

void CHncAES::ResetChain()
{
    return m_pImpl->ResetChain();
}

CHncAES::CHncAES()
    : m_pImpl(new _CHncAESImpl)
{
}

CHncAES::~CHncAES()
{
    if (m_pImpl) {
        delete m_pImpl;
        m_pImpl = NULL;
    }
}
