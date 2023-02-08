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

 /*************** Header files *********************************************/
#include "stdafx.h"
#include "HncBlowfish.h"
#include "cipher.h"

HNC_BF_INFO HNC_BF_Create(void)
{
    return rtl_cipher_create(rtl_Cipher_AlgorithmBF, rtl_Cipher_ModeStream);
}

void HNC_BF_Init(HNC_BF_INFO AlgInfo, bool bdecode, const char* key, uint32_t keylen, const char* arg, uint32_t arglen)
{
    rtlCipherDirection chiperdir = bdecode ? rtl_Cipher_DirectionDecode : rtl_Cipher_DirectionEncode;
    rtl_cipher_init(AlgInfo, chiperdir, (const uint8_t*)key, keylen, (const uint8_t*)arg, arglen);
}

void HNC_BF_Update(HNC_BF_INFO AlgInfo, bool bdecode, const char* data, uint32_t datLen, char* buffer, uint32_t bufferlen)
{
    if (bdecode)
        rtl_cipher_decode(AlgInfo, data, datLen, (uint8_t  *)buffer, bufferlen);
    else
        rtl_cipher_encode(AlgInfo, data, datLen, (uint8_t  *)buffer, bufferlen);
}

void HNC_BF_Final(HNC_BF_INFO AlgInfo)
{
    rtl_cipher_destroy(AlgInfo);
}

/*************** END OF FILE **********************************************/
