
// Code Changes
// 1. Remove unused header files.
// 2. Change struct call
// 3. Change variable type

/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

/*
 * This file is part of LibreOffice published API.
 */

#ifndef INCLUDED_RTL_CIPHER_H
#define INCLUDED_RTL_CIPHER_H

#include <stdint.h>
#define SAL_MAX_ENUM 0x7fffffff

#ifdef __cplusplus
extern "C" {
#endif

#ifdef OS_UNIX
#define __cdecl 
#endif

/** Cipher Handle opaque type.
 */
typedef void* rtlCipher;

/** Cipher Algorithm enumeration.
    @see rtl_cipher_create()
 */
enum __rtl_CipherAlgorithm
{
    rtl_Cipher_AlgorithmBF,
    rtl_Cipher_AlgorithmARCFOUR,
    rtl_Cipher_AlgorithmInvalid,
    rtl_Cipher_Algorithm_FORCE_EQUAL_SIZE = SAL_MAX_ENUM
};

/** Cipher Algorithm type.
 */
typedef enum __rtl_CipherAlgorithm rtlCipherAlgorithm;

/** Cipher Mode enumeration.
    @see rtl_cipher_create()
 */
enum __rtl_CipherMode
{
    rtl_Cipher_ModeECB,
    rtl_Cipher_ModeCBC,
    rtl_Cipher_ModeStream,
    rtl_Cipher_ModeInvalid,
    rtl_Cipher_Mode_FORCE_EQUAL_SIZE = SAL_MAX_ENUM
};

/** Cipher Mode type.
 */
typedef enum __rtl_CipherMode rtlCipherMode;

/** Cipher Direction enumeration.
    @see rtl_cipher_init()
 */
enum __rtl_CipherDirection
{
    rtl_Cipher_DirectionBoth,
    rtl_Cipher_DirectionDecode,
    rtl_Cipher_DirectionEncode,
    rtl_Cipher_DirectionInvalid,
    rtl_Cipher_Direction_FORCE_EQUAL_SIZE = SAL_MAX_ENUM
};

/** Cipher Direction type.
 */
typedef enum __rtl_CipherDirection rtlCipherDirection;


/** Error Code enumeration.
 */
enum __rtl_CipherError
{
    rtl_Cipher_E_None,
    rtl_Cipher_E_Argument,
    rtl_Cipher_E_Algorithm,
    rtl_Cipher_E_Direction,
    rtl_Cipher_E_Mode,
    rtl_Cipher_E_BufferSize,
    rtl_Cipher_E_Memory,
    rtl_Cipher_E_Unknown,
    rtl_Cipher_E_FORCE_EQUAL_SIZE = SAL_MAX_ENUM
};

/** Error Code type.
 */
typedef enum __rtl_CipherError rtlCipherError;


/** Create a cipher handle for the given algorithm and mode.
    @see rtlCipherAlgorithm
    @see rtlCipherMode

    @param[in] Algorithm cipher algorithm.
    @param[in] Mode      cipher mode.
    @return Cipher handle, or 0 upon failure.
 */
rtlCipher __cdecl rtl_cipher_create(
    rtlCipherAlgorithm Algorithm,
    rtlCipherMode      Mode
);

/** Inititialize a cipher for the given direction.
    @see rtlCipherDirection

    @param[in] Cipher    cipher handle.
    @param[in] Direction cipher direction.
    @param[in] pKeyData  key material buffer.
    @param[in] nKeyLen   key material length in bytes.
    @param[in] pArgData  initialization vector buffer.
    @param[in] nArgLen   initialization vector length in bytes.
    @retval rtl_Cipher_E_None upon success.
 */
rtlCipherError __cdecl rtl_cipher_init(
    rtlCipher           Cipher,
    rtlCipherDirection  Direction,
    const uint8_t    *pKeyData, uint32_t nKeyLen,
    const uint8_t    *pArgData, uint32_t nArgLen
);

/** Encode a buffer under a given cipher algorithm.
    @pre Initialized for a compatible cipher direction.
    @see     rtl_cipher_init()

    @param[in]  Cipher  cipher handle.
    @param[in]  pData   plaintext buffer.
    @param[in]  nDatLen plaintext length in bytes.
    @param[out] pBuffer ciphertext buffer.
    @param[in]  nBufLen ciphertext length in bytes.
    @retval rtl_Cipher_E_None upon success.
 */
rtlCipherError __cdecl rtl_cipher_encode (
    rtlCipher   Cipher,
    const void *pData,   uint32_t nDatLen,
    uint8_t  *pBuffer, uint32_t nBufLen
);

/** Decode a buffer under a given cipher algorithm.
    @pre Initialized for a compatible cipher direction.
    @see     rtl_cipher_init()

    @param[in]  Cipher  cipher handle.
    @param[in]  pData   ciphertext buffer.
    @param[in]  nDatLen ciphertext length in bytes.
    @param[out] pBuffer plaintext buffer.
    @param[in]  nBufLen plaintext length in bytes.
    @retval rtl_Cipher_E_None upon success.
 */
rtlCipherError __cdecl rtl_cipher_decode (
    rtlCipher   Cipher,
    const void *pData,   uint32_t nDatLen,
    uint8_t  *pBuffer, uint32_t nBufLen
);

/** Destroy a cipher handle.
    @param[in] Cipher cipher handle to be destroyed.
    @return None. Cipher handle destroyed and invalid.
 */
 void __cdecl rtl_cipher_destroy (
    rtlCipher Cipher
);

/** Create a Blowfish cipher handle for the given mode.

    The Blowfish block cipher algorithm is specified in
    Bruce Schneier: Applied Cryptography, 2nd edition, ch. 14.3

    @see rtl_cipher_create()
 */
 rtlCipher __cdecl rtl_cipher_createBF (
    rtlCipherMode Mode
);

/** Inititialize a Blowfish cipher for the given direction.
    @see rtl_cipher_init()
 */
 rtlCipherError __cdecl rtl_cipher_initBF (
    rtlCipher          Cipher,
    rtlCipherDirection Direction,
    const uint8_t *pKeyData, uint32_t nKeyLen,
    const uint8_t *pArgData, uint32_t nArgLen
);

/** Encode a buffer under the Blowfish cipher algorithm.
    @see rtl_cipher_encode()
 */
 rtlCipherError __cdecl rtl_cipher_encodeBF (
    rtlCipher   Cipher,
    const void *pData,   uint32_t nDatLen,
    uint8_t  *pBuffer, uint32_t nBufLen
);

/** Decode a buffer under the Blowfish cipher algorithm.
    @see rtl_cipher_decode()
 */
 rtlCipherError __cdecl rtl_cipher_decodeBF (
    rtlCipher   Cipher,
    const void *pData,   uint32_t nDatLen,
    uint8_t  *pBuffer, uint32_t nBufLen
);

/** Destroy a Blowfish cipher handle.
    @see rtl_cipher_destroy()
 */
 void __cdecl rtl_cipher_destroyBF (
    rtlCipher Cipher
);

/** Create a RC4 cipher handle for the given mode.

    The RC4 symmetric stream cipher algorithm is specified in
    Bruce Schneier: Applied Cryptography, 2nd edition, ch. 17.1

    @see rtl_cipher_create()

    @param[in] Mode cipher mode. Must be <code>rtl_Cipher_ModeStream</code>.
    @return Cipher handle, or 0 upon failure.
 */
 rtlCipher __cdecl rtl_cipher_createARCFOUR (
    rtlCipherMode Mode
);

/** Inititialize a RC4 cipher for the given direction.
    @see rtl_cipher_init()
 */
 rtlCipherError __cdecl rtl_cipher_initARCFOUR (
    rtlCipher          Cipher,
    rtlCipherDirection Direction,
    const uint8_t *pKeyData, uint32_t nKeyLen,
    const uint8_t *pArgData, uint32_t nArgLen
);

/** Encode a buffer under the RC4 cipher algorithm.
    @see rtl_cipher_encode()
 */
 rtlCipherError __cdecl rtl_cipher_encodeARCFOUR (
    rtlCipher   Cipher,
    const void *pData,   uint32_t nDatLen,
    uint8_t  *pBuffer, uint32_t nBufLen
);

/** Decode a buffer under the RC4 cipher algorithm.
    @see rtl_cipher_decode()
 */
 rtlCipherError __cdecl rtl_cipher_decodeARCFOUR (
    rtlCipher   Cipher,
    const void *pData,   uint32_t nDatLen,
    uint8_t  *pBuffer, uint32_t nBufLen
);

/** Destroy a RC4 cipher handle.
    @see rtl_cipher_destroy()
 */
 void __cdecl rtl_cipher_destroyARCFOUR (
    rtlCipher Cipher
);

#ifdef __cplusplus
}
#endif

#endif /* ! INCLUDED_RTL_CIPHER_H */

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
