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

#ifndef _SHA1_H
#define _SHA1_H

 /*************** Header files *********************************************/
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdint.h>
#include <string.h>

#include "HncDefine.h"
/*************** Macros ***************************************************/
////////    rotate by using shift operations    ////////
#if defined(_MSC_VER)
#define ROTL_DWORD(x, n) _lrotl((x), (n))
#define ROTR_DWORD(x, n) _lrotr((x), (n))
#else
#define ROTL_DWORD(x, n) ( (DWORD)((x) << (n)) | (DWORD)((x) >> (32-(n))) )
#define ROTR_DWORD(x, n) ( (DWORD)((x) >> (n)) | (DWORD)((x) << (32-(n))) )
#endif

#define ROTL_64(x,n) ( ((x) << (n)) | ((x) >> (64-(n))) )

////////    reverse the byte order of DWORD(DWORD:4-bytes integer) and WORD.
#define ENDIAN_REVERSE_DWORD(dwS)    ( (ROTL_DWORD((dwS),  8) & 0x00ff00ff)    \
                                     | (ROTL_DWORD((dwS), 24) & 0xff00ff00) )

////////    move DWORD type to BYTE type and BYTE type to DWORD type
#if (HNC_BYTE_ORDER == HNC_BIG_ENDIAN)        ////    Big-Endian machine
#define BIG_B2D(B, D)        D = *(DWORD *)(B)
#define BIG_D2B(D, B)        *(DWORD *)(B) = (DWORD)(D)
#define LITTLE_B2D(B, D)    D = ENDIAN_REVERSE_DWORD(*(DWORD *)(B))
#define LITTLE_D2B(D, B)    *(DWORD *)(B) = ENDIAN_REVERSE_DWORD(D)
#elif (HNC_BYTE_ORDER == HNC_LITTLE_ENDIAN)    ////    Little-Endian machine
#define BIG_B2D(B, D)        D = ENDIAN_REVERSE_DWORD(*(DWORD *)(B))
#define BIG_D2B(D, B)        *(DWORD *)(B) = ENDIAN_REVERSE_DWORD(D)
#define LITTLE_B2D(B, D)    D = *(DWORD *)(B)
#define LITTLE_D2B(D, B)    *(DWORD *)(B) = (DWORD)(D)
#else
#error ERROR : Invalid DataChangeType
#endif

/*************** Definitions / Macros  ************************************/
////    SHA1에 관련된 상수들
#define HNC_SHA1_DIGEST_BLOCKLEN    64        //    in bytes
#define HNC_SHA1_DIGEST_VALUELEN    20        //    in bytes

#define HNC_SHA384_DIGEST_BLOCKLEN  128
#define HNC_SHA384_DIGEST_VALUELEN 48

#define HNC_SHA512_DIGEST_BLOCKLEN  128
#define HNC_SHA512_DIGEST_VALUELEN 64

////    SHA1..
typedef struct {
    DWORD ChainVar[HNC_SHA1_DIGEST_VALUELEN / 4];    //    Chaining Variable 저장
    DWORD Count[4];                            //    
    BYTE Buffer[HNC_SHA1_DIGEST_BLOCKLEN];        //    Buffer for unfilled block
} HNC_SHA1_ALG_INFO;

typedef struct sha256_info {
    uint32_t state[8];

    uint32_t total[2];
    size_t buflen;
    uint32_t buffer[32];
} HNC_SHA256_ALG_INFO;

typedef struct sha512_info {
    uint64_t state[8];

    uint64_t total[2];
    uint64_t buflen;
    uint64_t buffer[32];
} HNC_SHA512_ALG_INFO;

/*************** Constant (Error Code) ************************************/
////    Error Code - 정리하고, 적당히 출력해야 함.
//#define CTR_SUCCESS                    0

/*************** Prototypes ***********************************************/
////    Init/Update/Final 형식을 복호화.

// SHA1
void HNC_SHA1_Init(
    HNC_SHA1_ALG_INFO *AlgInfo);

void HNC_SHA1_Update(
    HNC_SHA1_ALG_INFO *AlgInfo,
    BYTE            *Message,        //    데이타가 입력됨
    DWORD            MessageLen);

void HNC_SHA1_Final(
    HNC_SHA1_ALG_INFO    *AlgInfo,
    BYTE            *Digest);        //    해쉬값이 출력됨

// SHA256
void HNC_SHA256_Init(HNC_SHA256_ALG_INFO* pAlgInfo);
void HNC_SHA256_Update_Block(HNC_SHA256_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen);
void HNC_SHA256_Update(HNC_SHA256_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen);
BYTE* HNC_SHA256_Final(HNC_SHA256_ALG_INFO* pAlgInfo, BYTE* Message);


// SHA512
void HNC_SHA512_Init(HNC_SHA512_ALG_INFO* pAlgInfo);
void HNC_SHA384_Init(HNC_SHA512_ALG_INFO* pAlgInfo);

// len == 128의 배수
void HNC_SHA512_Update_Block(HNC_SHA512_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen);

// len == 임의 수
void HNC_SHA512_Update(HNC_SHA512_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen);

// resbuf == 64 (48) bytes little endian
//  that RESBUF be correctly aligned for a 64 bits value.
BYTE* HNC_SHA512_Final(HNC_SHA512_ALG_INFO* pAlgInfo, BYTE* Message);
BYTE* HNC_SHA384_Final(HNC_SHA512_ALG_INFO* pAlgInfo, BYTE* Message);


// PBKDF2
bool HNC_PBKDF2_SHA1(const char *P, size_t Plen, const char *S, size_t Slen, unsigned int c, char *DK, size_t dkLen);

bool HncGetSHAHashA(LPCTSTR path, char* hashString, size_t hashStringSize);
bool HncGetSHAHashW(LPCWSTR path, WCHAR* hashString, size_t hashStringSize);

#ifdef UNICODE
#define HncGetSHAHash HncGetSHAHashW
#else // #ifdef UNICODE
#define HncGetSHAHash HncGetSHAHashA
#endif // #ifdef UNICODE

/*************** END OF FILE **********************************************/
#endif    //    _SHA1_H
