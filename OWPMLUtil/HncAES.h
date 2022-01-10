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
#ifndef _HncAES_H_
#define _HncAES_H_

#include "HncDefine.h"

class _CHncAESImpl;


////////////////////////////////////////////////////////////////////////
// CHncAES Declaration
// : AES(Advanced Encryption Standard) 128/192/256(key bit)
class CHncAES
{
public:
    // Operation Modes
    enum { ECB = 0, CBC = 1, CFB = 2, DEF };

private:
    enum { DEFAULT_BLOCK_SIZE = 16 };
    enum { MAX_BLOCK_SIZE = 32 };

public:
    void MakeKey(char const* key, char const* chain = NULL, int keylength = DEFAULT_BLOCK_SIZE, int blockSize = DEFAULT_BLOCK_SIZE);

    void EncryptBlock(char const* in, char* result);
    void DecryptBlock(char const* in, char* result);
    void Encrypt(char const* in, char* result, size_t n, int iMode = ECB);
    void Decrypt(char const* in, char* result, size_t n, int iMode = ECB);

    int GetKeyLength();
    int GetBlockSize();
    int GetRounds();
    void ResetChain();

public:
    CHncAES();
    virtual ~CHncAES();

private:
    _CHncAESImpl* m_pImpl;
};


#endif    // _HncAES_H_
