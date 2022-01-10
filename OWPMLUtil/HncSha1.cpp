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
#include "HncSha1.h"

/*************** Macros ***************************************************/
//    define boolean operations
#define F(x, y, z)    ( (z)^( (x) & ((y) ^ (z)) ) )
#define G(x, y, z)    ( (x) ^ (y) ^ (z) )
#define H(x, y, z)    ( ((x)&(y)) | ( (z)&((x) | (y)) ) )

//    define step operations
#define FF(a,b,c,d,e,X) {                                \
    (e) += ROTL_DWORD((a), 5) + F((b),(c),(d)) + X + K;    \
    (b) = ROTL_DWORD((b), 30);                            \
}
#define GG(a,b,c,d,e,X) {                                \
    (e) += ROTL_DWORD((a), 5) + G((b),(c),(d)) + X + K;    \
    (b) = ROTL_DWORD((b), 30);                            \
}
#define HH(a,b,c,d,e,X) {                                \
    (e) += ROTL_DWORD((a), 5) + H((b),(c),(d)) + X + K;    \
    (b) = ROTL_DWORD((b), 30);                            \
}
#define II(a,b,c,d,e,X) {                                \
    (e) += ROTL_DWORD((a), 5) + G((b),(c),(d)) + X + K;    \
    (b) = ROTL_DWORD((b), 30);                            \
}

/*************** Function *************************************************
*    SHA1 core fuction
*/
static void SHA1_Transform(DWORD *Y, DWORD *DigestValue)
{
    DWORD a, b, c, d, e, X[80], K;

#if (HNC_BYTE_ORDER == HNC_BIG_ENDIAN)
#define GetData(x)    x
#elif (HNC_BYTE_ORDER == HNC_LITTLE_ENDIAN)
#define GetData(x)    ENDIAN_REVERSE_DWORD(x)
#endif

    //    unroll loops
    X[0] = GetData(Y[0]);
    X[1] = GetData(Y[1]);
    X[2] = GetData(Y[2]);
    X[3] = GetData(Y[3]);
    X[4] = GetData(Y[4]);
    X[5] = GetData(Y[5]);
    X[6] = GetData(Y[6]);
    X[7] = GetData(Y[7]);
    X[8] = GetData(Y[8]);
    X[9] = GetData(Y[9]);
    X[10] = GetData(Y[10]);
    X[11] = GetData(Y[11]);
    X[12] = GetData(Y[12]);
    X[13] = GetData(Y[13]);
    X[14] = GetData(Y[14]);
    X[15] = GetData(Y[15]);

#define TT(t)    X[t] = ROTL_DWORD(X[t-16]^X[t-14]^X[t-8]^X[t-3], 1)
    TT(16);    TT(17);    TT(18);    TT(19);    TT(20);    TT(21);    TT(22);    TT(23);
    TT(24);    TT(25);    TT(26);    TT(27);    TT(28);    TT(29);    TT(30);    TT(31);
    TT(32);    TT(33);    TT(34);    TT(35);    TT(36);    TT(37);    TT(38);    TT(39);
    TT(40);    TT(41);    TT(42);    TT(43);    TT(44);    TT(45);    TT(46);    TT(47);
    TT(48);    TT(49);    TT(50);    TT(51);    TT(52);    TT(53);    TT(54);    TT(55);
    TT(56);    TT(57);    TT(58);    TT(59);    TT(60);    TT(61);    TT(62);    TT(63);
    TT(64);    TT(65);    TT(66);    TT(67);    TT(68);    TT(69);    TT(70);    TT(71);
    TT(72);    TT(73);    TT(74);    TT(75);    TT(76);    TT(77);    TT(78);    TT(79);

    a = DigestValue[0];
    b = DigestValue[1];
    c = DigestValue[2];
    d = DigestValue[3];
    e = DigestValue[4];

    //    1st round
    K = 0x5A827999;
    FF(a, b, c, d, e, X[0]);    FF(e, a, b, c, d, X[1]);
    FF(d, e, a, b, c, X[2]);    FF(c, d, e, a, b, X[3]);
    FF(b, c, d, e, a, X[4]);    FF(a, b, c, d, e, X[5]);
    FF(e, a, b, c, d, X[6]);    FF(d, e, a, b, c, X[7]);
    FF(c, d, e, a, b, X[8]);    FF(b, c, d, e, a, X[9]);
    FF(a, b, c, d, e, X[10]);    FF(e, a, b, c, d, X[11]);
    FF(d, e, a, b, c, X[12]);    FF(c, d, e, a, b, X[13]);
    FF(b, c, d, e, a, X[14]);    FF(a, b, c, d, e, X[15]);
    FF(e, a, b, c, d, X[16]);    FF(d, e, a, b, c, X[17]);
    FF(c, d, e, a, b, X[18]);    FF(b, c, d, e, a, X[19]);

    //    2nd round
    K = 0x6ED9EBA1;
    GG(a, b, c, d, e, X[20]);    GG(e, a, b, c, d, X[21]);
    GG(d, e, a, b, c, X[22]);    GG(c, d, e, a, b, X[23]);
    GG(b, c, d, e, a, X[24]);    GG(a, b, c, d, e, X[25]);
    GG(e, a, b, c, d, X[26]);    GG(d, e, a, b, c, X[27]);
    GG(c, d, e, a, b, X[28]);    GG(b, c, d, e, a, X[29]);
    GG(a, b, c, d, e, X[30]);    GG(e, a, b, c, d, X[31]);
    GG(d, e, a, b, c, X[32]);    GG(c, d, e, a, b, X[33]);
    GG(b, c, d, e, a, X[34]);    GG(a, b, c, d, e, X[35]);
    GG(e, a, b, c, d, X[36]);    GG(d, e, a, b, c, X[37]);
    GG(c, d, e, a, b, X[38]);    GG(b, c, d, e, a, X[39]);

    //    3rd round
    K = 0x8F1BBCDC;
    HH(a, b, c, d, e, X[40]);    HH(e, a, b, c, d, X[41]);
    HH(d, e, a, b, c, X[42]);    HH(c, d, e, a, b, X[43]);
    HH(b, c, d, e, a, X[44]);    HH(a, b, c, d, e, X[45]);
    HH(e, a, b, c, d, X[46]);    HH(d, e, a, b, c, X[47]);
    HH(c, d, e, a, b, X[48]);    HH(b, c, d, e, a, X[49]);
    HH(a, b, c, d, e, X[50]);    HH(e, a, b, c, d, X[51]);
    HH(d, e, a, b, c, X[52]);    HH(c, d, e, a, b, X[53]);
    HH(b, c, d, e, a, X[54]);    HH(a, b, c, d, e, X[55]);
    HH(e, a, b, c, d, X[56]);    HH(d, e, a, b, c, X[57]);
    HH(c, d, e, a, b, X[58]);    HH(b, c, d, e, a, X[59]);

    //    4th round
    K = 0xCA62C1D6;
    II(a, b, c, d, e, X[60]);    II(e, a, b, c, d, X[61]);
    II(d, e, a, b, c, X[62]);    II(c, d, e, a, b, X[63]);
    II(b, c, d, e, a, X[64]);    II(a, b, c, d, e, X[65]);
    II(e, a, b, c, d, X[66]);    II(d, e, a, b, c, X[67]);
    II(c, d, e, a, b, X[68]);    II(b, c, d, e, a, X[69]);
    II(a, b, c, d, e, X[70]);    II(e, a, b, c, d, X[71]);
    II(d, e, a, b, c, X[72]);    II(c, d, e, a, b, X[73]);
    II(b, c, d, e, a, X[74]);    II(a, b, c, d, e, X[75]);
    II(e, a, b, c, d, X[76]);    II(d, e, a, b, c, X[77]);
    II(c, d, e, a, b, X[78]);    II(b, c, d, e, a, X[79]);

    //    chaining variables update
    DigestValue[0] += a;
    DigestValue[1] += b;
    DigestValue[2] += c;
    DigestValue[3] += d;
    DigestValue[4] += e;
}

/*************** Function *************************************************
*
*/
void HNC_SHA1_Init(
    HNC_SHA1_ALG_INFO    *AlgInfo)
{
    //
    AlgInfo->ChainVar[0] = 0x67452301;
    AlgInfo->ChainVar[1] = 0xefcdab89;
    AlgInfo->ChainVar[2] = 0x98badcfe;
    AlgInfo->ChainVar[3] = 0x10325476;
    AlgInfo->ChainVar[4] = 0xC3D2E1F0;

    //
    AlgInfo->Count[0] = AlgInfo->Count[1] = 0;
}

/*************** Function *************************************************
*
*/
void HNC_SHA1_Update(
    HNC_SHA1_ALG_INFO *AlgInfo,
    BYTE            *Message,        //    input Message
    DWORD            MessageLen)        //    in BYTEs
{
    DWORD RemainedLen, PartLen;

    //    Compute the number of hashed bytes mod HNC_SHA1_DIGEST_BLOCKLEN
    RemainedLen = (AlgInfo->Count[0] >> 3) % HNC_SHA1_DIGEST_BLOCKLEN;
    //    compute the number of bytes that can be filled up
    PartLen = HNC_SHA1_DIGEST_BLOCKLEN - RemainedLen;

    //    Update Count (number of toatl data bits)
    if ((AlgInfo->Count[0] += (MessageLen << 3)) < AlgInfo->Count[0])
        AlgInfo->Count[1]++;
    AlgInfo->Count[1] += (MessageLen >> 29);

    //    핵심 updtae 부분
    if (MessageLen >= PartLen) {
        _ASSERTE(PartLen >= 0 && "UINT 음수 보안패치");
        memcpy(AlgInfo->Buffer + RemainedLen, Message, (size_t)PartLen);
        SHA1_Transform((DWORD *)AlgInfo->Buffer, AlgInfo->ChainVar);

        Message += PartLen;
        MessageLen -= PartLen;
        RemainedLen = 0;

        while (MessageLen >= HNC_SHA1_DIGEST_BLOCKLEN) {
            if ((((intptr_t)Message) % 4) == 0) {    //    Speed up technique
                SHA1_Transform((DWORD *)Message, AlgInfo->ChainVar);
            } else {
                memcpy((BYTE *)AlgInfo->Buffer, Message, (int)HNC_SHA1_DIGEST_BLOCKLEN);
                SHA1_Transform((DWORD *)AlgInfo->Buffer, AlgInfo->ChainVar);
            }
            Message += HNC_SHA1_DIGEST_BLOCKLEN;
            MessageLen -= HNC_SHA1_DIGEST_BLOCKLEN;
        }
    }

    //    Buffer remaining input
    _ASSERTE(MessageLen >= 0 && "UINT 음수 보안패치");
    memcpy((BYTE *)AlgInfo->Buffer + RemainedLen, Message, (size_t)MessageLen);
}

/*************** Function *************************************************
*
*/
void HNC_SHA1_Final(
    HNC_SHA1_ALG_INFO *AlgInfo,
    BYTE            *Digest)    //    output Hash Value
{
    DWORD        i, dwIndex, CountL, CountH;

    //    마지박 블록 처리
    CountL = AlgInfo->Count[0];
    CountH = AlgInfo->Count[1];
    dwIndex = (CountL >> 3) % HNC_SHA1_DIGEST_BLOCKLEN;
    AlgInfo->Buffer[dwIndex++] = 0x80;

    if (dwIndex > HNC_SHA1_DIGEST_BLOCKLEN - 8) {
        _ASSERTE(HNC_SHA1_DIGEST_BLOCKLEN - dwIndex >= 0 && "UINT 음수 보안패치");
        memset((BYTE *)AlgInfo->Buffer + dwIndex, 0, (size_t)(HNC_SHA1_DIGEST_BLOCKLEN - dwIndex));

        SHA1_Transform((DWORD *)AlgInfo->Buffer, AlgInfo->ChainVar);

        memset((BYTE *)AlgInfo->Buffer, 0, (size_t)HNC_SHA1_DIGEST_BLOCKLEN - 8);
    } else {
        _ASSERTE(HNC_SHA1_DIGEST_BLOCKLEN - dwIndex - 8 >= 0 && "UINT 음수 보안패치");
        memset((BYTE *)AlgInfo->Buffer + dwIndex, 0, (size_t)(HNC_SHA1_DIGEST_BLOCKLEN - dwIndex - 8));
    }

    //    출력
#if (HNC_BYTE_ORDER == HNC_LITTLE_ENDIAN)
    CountL = ENDIAN_REVERSE_DWORD(CountL);
    CountH = ENDIAN_REVERSE_DWORD(CountH);
#endif
    ((DWORD *)AlgInfo->Buffer)[HNC_SHA1_DIGEST_BLOCKLEN / 4 - 2] = CountH;
    ((DWORD *)AlgInfo->Buffer)[HNC_SHA1_DIGEST_BLOCKLEN / 4 - 1] = CountL;

    SHA1_Transform((DWORD *)AlgInfo->Buffer, AlgInfo->ChainVar);

    for (i = 0; i < HNC_SHA1_DIGEST_VALUELEN; i += 4)
        BIG_D2B((AlgInfo->ChainVar)[i / 4], &(Digest[i]));
}


//////////////////////////////////////////////////////////////////////////////////////
// SHA512 SHA384

# define SWAP(n) \
    (((n) << 56) | (((n) & 0xff00) << 40) | (((n) & 0xff0000UL) << 24) \
     | (((n) & 0xff000000UL) << 8) | (((n) >> 8) & 0xff000000UL) \
     | (((n) >> 24) & 0xff0000UL) | (((n) >> 40) & 0xff00UL) | ((n) >> 56))

static const unsigned char fillbuf[128] = { 0x80, 0 };

void HNC_SHA512_Init(HNC_SHA512_ALG_INFO* pAlgInfo)
{
    pAlgInfo->state[0] = 0x6a09e667f3bcc908ULL;
    pAlgInfo->state[1] = 0xbb67ae8584caa73bULL;
    pAlgInfo->state[2] = 0x3c6ef372fe94f82bULL;
    pAlgInfo->state[3] = 0xa54ff53a5f1d36f1ULL;
    pAlgInfo->state[4] = 0x510e527fade682d1ULL;
    pAlgInfo->state[5] = 0x9b05688c2b3e6c1fULL;
    pAlgInfo->state[6] = 0x1f83d9abfb41bd6bULL;
    pAlgInfo->state[7] = 0x5be0cd19137e2179ULL;

    pAlgInfo->total[0] = pAlgInfo->total[1] = 0;
    pAlgInfo->buflen = 0;
}

void HNC_SHA384_Init(HNC_SHA512_ALG_INFO* pAlgInfo)
{
    pAlgInfo->state[0] = 0xcbbb9d5dc1059ed8ULL;
    pAlgInfo->state[1] = 0x629a292a367cd507ULL;
    pAlgInfo->state[2] = 0x9159015a3070dd17ULL;
    pAlgInfo->state[3] = 0x152fecd8f70e5939ULL;
    pAlgInfo->state[4] = 0x67332667ffc00b31ULL;
    pAlgInfo->state[5] = 0x8eb44a8768581511ULL;
    pAlgInfo->state[6] = 0xdb0c2e0d64f98fa7ULL;
    pAlgInfo->state[7] = 0x47b5481dbefa4fa4ULL;

    pAlgInfo->total[0] = pAlgInfo->total[1] = 0;
    pAlgInfo->buflen = 0;
}

BYTE* HNC_SHA512_Read(const HNC_SHA512_ALG_INFO* pAlgInfo, BYTE* Message)
{
    int i;

    for (i = 0; i < 8; i++)
        ((uint64_t *)Message)[i] = SWAP(pAlgInfo->state[i]);

    return Message;
}

BYTE* HNC_SHA384_Read(const HNC_SHA512_ALG_INFO* pAlgInfo, BYTE* Message)
{
    int i;

    for (i = 0; i < 6; i++)
        ((uint64_t *)Message)[i] = SWAP(pAlgInfo->state[i]);

    return Message;
}

static void HNC_SHA512_Conclude(HNC_SHA512_ALG_INFO* pAlgInfo)
{
    uint64_t bytes = pAlgInfo->buflen;
    size_t size = (bytes < 112) ? 128 / 8 : 128 * 2 / 8;

    pAlgInfo->total[0] += bytes;
    if (pAlgInfo->total[0] < bytes)
        ++pAlgInfo->total[1];

    pAlgInfo->buffer[size - 2] = SWAP((pAlgInfo->total[1] << 3) | (pAlgInfo->total[0] >> 61));
    pAlgInfo->buffer[size - 1] = SWAP(pAlgInfo->total[0] << 3);

    memcpy(&((char *)pAlgInfo->buffer)[bytes], fillbuf, (size - 2) * 8 - (size_t)bytes);

    HNC_SHA512_Update_Block(pAlgInfo, (const BYTE*)pAlgInfo->buffer, static_cast<DWORD>(size * 8));
}

BYTE* HNC_SHA512_Final(HNC_SHA512_ALG_INFO* pAlgInfo, BYTE* Message)
{
    HNC_SHA512_Conclude(pAlgInfo);
    return HNC_SHA512_Read(pAlgInfo, Message);
}

BYTE* HNC_SHA384_Final(HNC_SHA512_ALG_INFO* pAlgInfo, BYTE* Message)
{
    HNC_SHA512_Conclude(pAlgInfo);
    return HNC_SHA384_Read(pAlgInfo, Message);
}

void HNC_SHA512_Update(HNC_SHA512_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen)
{
    if (pAlgInfo->buflen != 0) {
        DWORD left_over = (DWORD)pAlgInfo->buflen;
        DWORD add = 256 - left_over > MessageLen ? MessageLen : 256 - left_over;

        memcpy(&((char *)pAlgInfo->buffer)[left_over], Message, add);
        pAlgInfo->buflen += add;

        if (pAlgInfo->buflen > 128) {
            HNC_SHA512_Update_Block(pAlgInfo, (const BYTE*)pAlgInfo->buffer, pAlgInfo->buflen & ~63);

            pAlgInfo->buflen &= 127;
            memcpy(pAlgInfo->buffer, &((char *)pAlgInfo->buffer)[(left_over + add) & ~127], (size_t)pAlgInfo->buflen);
        }

        Message = (const BYTE*)Message + add;
        MessageLen -= add;
    }

    if (MessageLen >= 128) {
        struct tempstruct { char c; uint64_t x; };

        if (((size_t)Message) % offsetof(tempstruct, x) != 0) {
            while (MessageLen > 128) {
                HNC_SHA512_Update_Block(pAlgInfo, (const BYTE*)memcpy(pAlgInfo->buffer, Message, 128), 128);
                Message = (const BYTE*)Message + 128;
                MessageLen -= 128;
            }
        } else {
            HNC_SHA512_Update_Block(pAlgInfo, (const BYTE*)Message, MessageLen & ~127);
            Message = (const BYTE*)Message + (MessageLen & ~127);
            MessageLen &= 127;
        }
    }

    if (MessageLen > 0) {
        size_t left_over = (size_t)pAlgInfo->buflen;

        memcpy(&((char *)pAlgInfo->buffer)[left_over], Message, MessageLen);
        left_over += MessageLen;

        if (left_over >= 128) {
            HNC_SHA512_Update_Block(pAlgInfo, (const BYTE*)pAlgInfo->buffer, 128);
            left_over -= 128;
            memcpy(pAlgInfo->buffer, &pAlgInfo->buffer[16], left_over);
        }

        pAlgInfo->buflen = left_over;
    }
}


#define K(I) sha512_round_constants[I]
static const uint64_t sha512_round_constants[80] = {
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL, 0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL, 0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL, 0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL, 0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL, 0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL, 0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL, 0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL, 0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL, 0xd192e819d6ef5218ULL, 0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL, 0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL, 0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL, 0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL, 0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL, 0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL,
};

#define F2(A,B,C) ( ( A & B ) | ( C & ( A | B ) ) )
#define F1(E,F,G) ( G ^ ( E & ( F ^ G ) ) )
#define S0(x) (ROTL_64(x,63)^ROTL_64(x,56)^(x>>7))
#define S1(x) (ROTL_64(x,45)^ROTL_64(x,3)^(x>>6))
#define SS0(x) (ROTL_64(x,36)^ROTL_64(x,30)^ROTL_64(x,25))
#define SS1(x) (ROTL_64(x,50)^ROTL_64(x,46)^ROTL_64(x,23))

#define M(I) ( tm =   S1(x[(I-2)&0x0f]) + x[(I-7)&0x0f] \
            + S0(x[(I-15)&0x0f]) + x[I&0x0f]    \
           , x[I&0x0f] = tm )

#define R(A,B,C,D,E,F,G,H,K,M)  do { t0 = SS0(A) + F2(A,B,C); \
                                     t1 = H + SS1(E)  + F1(E,F,G)  + K    + M; \
                                        D += t1;  H = t0 + t1; \
                                } while(0)


void HNC_SHA512_Update_Block(HNC_SHA512_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen)
{
    const uint64_t *words = (uint64_t *)Message;
    DWORD nwords = MessageLen / sizeof(uint64_t);
    const uint64_t *endp = words + nwords;
    uint64_t x[16];
    uint64_t a = pAlgInfo->state[0];
    uint64_t b = pAlgInfo->state[1];
    uint64_t c = pAlgInfo->state[2];
    uint64_t d = pAlgInfo->state[3];
    uint64_t e = pAlgInfo->state[4];
    uint64_t f = pAlgInfo->state[5];
    uint64_t g = pAlgInfo->state[6];
    uint64_t h = pAlgInfo->state[7];

    pAlgInfo->total[0] += MessageLen;
    if (pAlgInfo->total[0] < MessageLen)
        ++pAlgInfo->total[1];

    while (words < endp) {
        uint64_t tm;
        uint64_t t0, t1;
        int t;

        for (t = 0; t < 16; t++) {
            x[t] = SWAP(*words);
            words++;
        }

        R(a, b, c, d, e, f, g, h, K(0), x[0]);
        R(h, a, b, c, d, e, f, g, K(1), x[1]);
        R(g, h, a, b, c, d, e, f, K(2), x[2]);
        R(f, g, h, a, b, c, d, e, K(3), x[3]);
        R(e, f, g, h, a, b, c, d, K(4), x[4]);
        R(d, e, f, g, h, a, b, c, K(5), x[5]);
        R(c, d, e, f, g, h, a, b, K(6), x[6]);
        R(b, c, d, e, f, g, h, a, K(7), x[7]);
        R(a, b, c, d, e, f, g, h, K(8), x[8]);
        R(h, a, b, c, d, e, f, g, K(9), x[9]);
        R(g, h, a, b, c, d, e, f, K(10), x[10]);
        R(f, g, h, a, b, c, d, e, K(11), x[11]);
        R(e, f, g, h, a, b, c, d, K(12), x[12]);
        R(d, e, f, g, h, a, b, c, K(13), x[13]);
        R(c, d, e, f, g, h, a, b, K(14), x[14]);
        R(b, c, d, e, f, g, h, a, K(15), x[15]);
        R(a, b, c, d, e, f, g, h, K(16), M(16));
        R(h, a, b, c, d, e, f, g, K(17), M(17));
        R(g, h, a, b, c, d, e, f, K(18), M(18));
        R(f, g, h, a, b, c, d, e, K(19), M(19));
        R(e, f, g, h, a, b, c, d, K(20), M(20));
        R(d, e, f, g, h, a, b, c, K(21), M(21));
        R(c, d, e, f, g, h, a, b, K(22), M(22));
        R(b, c, d, e, f, g, h, a, K(23), M(23));
        R(a, b, c, d, e, f, g, h, K(24), M(24));
        R(h, a, b, c, d, e, f, g, K(25), M(25));
        R(g, h, a, b, c, d, e, f, K(26), M(26));
        R(f, g, h, a, b, c, d, e, K(27), M(27));
        R(e, f, g, h, a, b, c, d, K(28), M(28));
        R(d, e, f, g, h, a, b, c, K(29), M(29));
        R(c, d, e, f, g, h, a, b, K(30), M(30));
        R(b, c, d, e, f, g, h, a, K(31), M(31));
        R(a, b, c, d, e, f, g, h, K(32), M(32));
        R(h, a, b, c, d, e, f, g, K(33), M(33));
        R(g, h, a, b, c, d, e, f, K(34), M(34));
        R(f, g, h, a, b, c, d, e, K(35), M(35));
        R(e, f, g, h, a, b, c, d, K(36), M(36));
        R(d, e, f, g, h, a, b, c, K(37), M(37));
        R(c, d, e, f, g, h, a, b, K(38), M(38));
        R(b, c, d, e, f, g, h, a, K(39), M(39));
        R(a, b, c, d, e, f, g, h, K(40), M(40));
        R(h, a, b, c, d, e, f, g, K(41), M(41));
        R(g, h, a, b, c, d, e, f, K(42), M(42));
        R(f, g, h, a, b, c, d, e, K(43), M(43));
        R(e, f, g, h, a, b, c, d, K(44), M(44));
        R(d, e, f, g, h, a, b, c, K(45), M(45));
        R(c, d, e, f, g, h, a, b, K(46), M(46));
        R(b, c, d, e, f, g, h, a, K(47), M(47));
        R(a, b, c, d, e, f, g, h, K(48), M(48));
        R(h, a, b, c, d, e, f, g, K(49), M(49));
        R(g, h, a, b, c, d, e, f, K(50), M(50));
        R(f, g, h, a, b, c, d, e, K(51), M(51));
        R(e, f, g, h, a, b, c, d, K(52), M(52));
        R(d, e, f, g, h, a, b, c, K(53), M(53));
        R(c, d, e, f, g, h, a, b, K(54), M(54));
        R(b, c, d, e, f, g, h, a, K(55), M(55));
        R(a, b, c, d, e, f, g, h, K(56), M(56));
        R(h, a, b, c, d, e, f, g, K(57), M(57));
        R(g, h, a, b, c, d, e, f, K(58), M(58));
        R(f, g, h, a, b, c, d, e, K(59), M(59));
        R(e, f, g, h, a, b, c, d, K(60), M(60));
        R(d, e, f, g, h, a, b, c, K(61), M(61));
        R(c, d, e, f, g, h, a, b, K(62), M(62));
        R(b, c, d, e, f, g, h, a, K(63), M(63));
        R(a, b, c, d, e, f, g, h, K(64), M(64));
        R(h, a, b, c, d, e, f, g, K(65), M(65));
        R(g, h, a, b, c, d, e, f, K(66), M(66));
        R(f, g, h, a, b, c, d, e, K(67), M(67));
        R(e, f, g, h, a, b, c, d, K(68), M(68));
        R(d, e, f, g, h, a, b, c, K(69), M(69));
        R(c, d, e, f, g, h, a, b, K(70), M(70));
        R(b, c, d, e, f, g, h, a, K(71), M(71));
        R(a, b, c, d, e, f, g, h, K(72), M(72));
        R(h, a, b, c, d, e, f, g, K(73), M(73));
        R(g, h, a, b, c, d, e, f, K(74), M(74));
        R(f, g, h, a, b, c, d, e, K(75), M(75));
        R(e, f, g, h, a, b, c, d, K(76), M(76));
        R(d, e, f, g, h, a, b, c, K(77), M(77));
        R(c, d, e, f, g, h, a, b, K(78), M(78));
        R(b, c, d, e, f, g, h, a, K(79), M(79));

        a = pAlgInfo->state[0] += a;
        b = pAlgInfo->state[1] += b;
        c = pAlgInfo->state[2] += c;
        d = pAlgInfo->state[3] += d;
        e = pAlgInfo->state[4] += e;
        f = pAlgInfo->state[5] += f;
        g = pAlgInfo->state[6] += g;
        h = pAlgInfo->state[7] += h;
    }
}




//////////////////////////////////////////////////////////////////////////////////////
// SHA256
# define SWAP256(n) \
    (((n) << 24) | (((n) & 0xff00) << 8) | (((n) >> 8) & 0xff00) | ((n) >> 24))

static const unsigned char fillbuf256[64] = { 0x80, 0 /* , 0, 0, ...  */ };


static void set_uint32(BYTE *cp, uint32_t v)
{
    memcpy(cp, &v, sizeof v);
}

BYTE* HNC_SHA256_Read(const HNC_SHA256_ALG_INFO* pAlgInfo, BYTE* Message)
{
    int i;

    for (i = 0; i < 8; i++)
        set_uint32(Message + i * sizeof pAlgInfo->state[0], SWAP256(pAlgInfo->state[i]));

    return Message;
}

static void HNC_SHA256_Conclude(HNC_SHA256_ALG_INFO* pAlgInfo)
{
    size_t bytes = pAlgInfo->buflen;
    size_t size = (bytes < 56) ? 64 / 4 : 64 * 2 / 4;

    pAlgInfo->total[0] += static_cast<int>(bytes);
    if (pAlgInfo->total[0] < bytes)
        ++pAlgInfo->total[1];

    set_uint32((BYTE *)&pAlgInfo->buffer[size - 2], SWAP256((pAlgInfo->total[1] << 3) | (pAlgInfo->total[0] >> 29)));
    set_uint32((BYTE *)&pAlgInfo->buffer[size - 1], SWAP256(pAlgInfo->total[0] << 3));

    memcpy(&((BYTE *)pAlgInfo->buffer)[bytes], fillbuf256, (size - 2) * 4 - bytes);

    /* Process last bytes.  */
    HNC_SHA256_Update_Block(pAlgInfo, (const BYTE*)pAlgInfo->buffer, static_cast<DWORD>(size * 4));
}


/*************** Function *************************************************
*
*/
void HNC_SHA256_Init(HNC_SHA256_ALG_INFO* pAlgInfo)
{
    pAlgInfo->state[0] = 0x6a09e667UL;
    pAlgInfo->state[1] = 0xbb67ae85UL;
    pAlgInfo->state[2] = 0x3c6ef372UL;
    pAlgInfo->state[3] = 0xa54ff53aUL;
    pAlgInfo->state[4] = 0x510e527fUL;
    pAlgInfo->state[5] = 0x9b05688cUL;
    pAlgInfo->state[6] = 0x1f83d9abUL;
    pAlgInfo->state[7] = 0x5be0cd19UL;

    pAlgInfo->total[0] = pAlgInfo->total[1] = 0;
    pAlgInfo->buflen = 0;
}

/*************** Function *************************************************
*
*/
void HNC_SHA256_Update(HNC_SHA256_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen)
{
    if (pAlgInfo->buflen != 0) {
        DWORD left_over = (DWORD)pAlgInfo->buflen;
        DWORD add = 128 - left_over > MessageLen ? MessageLen : 128 - left_over;

        memcpy(&((char *)pAlgInfo->buffer)[left_over], Message, add);
        pAlgInfo->buflen += add;

        if (pAlgInfo->buflen > 64) {
            HNC_SHA256_Update_Block(pAlgInfo, (const BYTE*)pAlgInfo->buffer, pAlgInfo->buflen & ~63);

            pAlgInfo->buflen &= 63;
            memcpy(pAlgInfo->buffer, &((char *)pAlgInfo->buffer)[(left_over + add) & ~63], (size_t)pAlgInfo->buflen);
        }

        Message = (const BYTE*)Message + add;
        MessageLen -= add;
    }

    if (MessageLen >= 64) {
        struct tempstruct { char c; uint64_t x; };

        if (((size_t)Message) % offsetof(tempstruct, x) != 0) {
            while (MessageLen > 64) {
                HNC_SHA256_Update_Block(pAlgInfo, (const BYTE*)memcpy(pAlgInfo->buffer, Message, 64), 64);
                Message = (const BYTE*)Message + 64;
                MessageLen -= 64;
            }
        } else {
            HNC_SHA256_Update_Block(pAlgInfo, (const BYTE*)Message, MessageLen & ~63);
            Message = (const BYTE*)Message + (MessageLen & ~63);
            MessageLen &= 63;
        }
    }

    if (MessageLen > 0) {
        size_t left_over = (size_t)pAlgInfo->buflen;

        memcpy(&((char *)pAlgInfo->buffer)[left_over], Message, MessageLen);
        left_over += MessageLen;

        if (left_over >= 64) {
            HNC_SHA256_Update_Block(pAlgInfo, (const BYTE*)pAlgInfo->buffer, 64);
            left_over -= 64;
            memcpy(pAlgInfo->buffer, &pAlgInfo->buffer[16], left_over);
        }

        pAlgInfo->buflen = left_over;
    }
}

/*************** Function *************************************************
*
*/
BYTE* HNC_SHA256_Final(HNC_SHA256_ALG_INFO* pAlgInfo, BYTE* Message)
{
    HNC_SHA256_Conclude(pAlgInfo);
    return HNC_SHA256_Read(pAlgInfo, Message);
}

#define K256(I) sha256_round_constants[I]
static const uint32_t sha256_round_constants[64] = {
    0x428a2f98UL, 0x71374491UL, 0xb5c0fbcfUL, 0xe9b5dba5UL,
    0x3956c25bUL, 0x59f111f1UL, 0x923f82a4UL, 0xab1c5ed5UL,
    0xd807aa98UL, 0x12835b01UL, 0x243185beUL, 0x550c7dc3UL,
    0x72be5d74UL, 0x80deb1feUL, 0x9bdc06a7UL, 0xc19bf174UL,
    0xe49b69c1UL, 0xefbe4786UL, 0x0fc19dc6UL, 0x240ca1ccUL,
    0x2de92c6fUL, 0x4a7484aaUL, 0x5cb0a9dcUL, 0x76f988daUL,
    0x983e5152UL, 0xa831c66dUL, 0xb00327c8UL, 0xbf597fc7UL,
    0xc6e00bf3UL, 0xd5a79147UL, 0x06ca6351UL, 0x14292967UL,
    0x27b70a85UL, 0x2e1b2138UL, 0x4d2c6dfcUL, 0x53380d13UL,
    0x650a7354UL, 0x766a0abbUL, 0x81c2c92eUL, 0x92722c85UL,
    0xa2bfe8a1UL, 0xa81a664bUL, 0xc24b8b70UL, 0xc76c51a3UL,
    0xd192e819UL, 0xd6990624UL, 0xf40e3585UL, 0x106aa070UL,
    0x19a4c116UL, 0x1e376c08UL, 0x2748774cUL, 0x34b0bcb5UL,
    0x391c0cb3UL, 0x4ed8aa4aUL, 0x5b9cca4fUL, 0x682e6ff3UL,
    0x748f82eeUL, 0x78a5636fUL, 0x84c87814UL, 0x8cc70208UL,
    0x90befffaUL, 0xa4506cebUL, 0xbef9a3f7UL, 0xc67178f2UL,
};

#define rol(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define S0256(x) (rol(x,25)^rol(x,14)^(x>>3))
#define S1256(x) (rol(x,15)^rol(x,13)^(x>>10))
#define SS0256(x) (rol(x,30)^rol(x,19)^rol(x,10))
#define SS1256(x) (rol(x,26)^rol(x,21)^rol(x,7))

#define M256(I) ( tm =   S1256(x[(I-2)&0x0f]) + x[(I-7)&0x0f] \
                    + S0256(x[(I-15)&0x0f]) + x[I&0x0f]    \
               , x[I&0x0f] = tm )

#define R256(A,B,C,D,E,F,G,H,K,M)  do { t0 = SS0256(A) + F2(A,B,C); \
                                     t1 = H + SS1256(E)  \
                                      + F1(E,F,G)     \
                                      + K             \
                                      + M;            \
                                     D += t1;  H = t0 + t1; \
                               } while(0)


/*************** Function *************************************************
*
*/
void HNC_SHA256_Update_Block(HNC_SHA256_ALG_INFO* pAlgInfo, const BYTE* Message, DWORD MessageLen)
{
    const uint32_t *words = (uint32_t *)Message;
    DWORD nwords = MessageLen / sizeof(uint32_t);
    const uint32_t *endp = words + nwords;
    uint32_t x[16];
    uint32_t a = pAlgInfo->state[0];
    uint32_t b = pAlgInfo->state[1];
    uint32_t c = pAlgInfo->state[2];
    uint32_t d = pAlgInfo->state[3];
    uint32_t e = pAlgInfo->state[4];
    uint32_t f = pAlgInfo->state[5];
    uint32_t g = pAlgInfo->state[6];
    uint32_t h = pAlgInfo->state[7];
    uint32_t lolen = MessageLen;

    pAlgInfo->total[0] += lolen;
    pAlgInfo->total[1] += (MessageLen >> 31 >> 1) + (pAlgInfo->total[0] < lolen);


    while (words < endp) {
        uint32_t tm;
        uint32_t t0, t1;
        int t;

        for (t = 0; t < 16; t++) {
            x[t] = SWAP256(*words);
            words++;
        }

        R256(a, b, c, d, e, f, g, h, K256(0), x[0]);
        R256(h, a, b, c, d, e, f, g, K256(1), x[1]);
        R256(g, h, a, b, c, d, e, f, K256(2), x[2]);
        R256(f, g, h, a, b, c, d, e, K256(3), x[3]);
        R256(e, f, g, h, a, b, c, d, K256(4), x[4]);
        R256(d, e, f, g, h, a, b, c, K256(5), x[5]);
        R256(c, d, e, f, g, h, a, b, K256(6), x[6]);
        R256(b, c, d, e, f, g, h, a, K256(7), x[7]);
        R256(a, b, c, d, e, f, g, h, K256(8), x[8]);
        R256(h, a, b, c, d, e, f, g, K256(9), x[9]);
        R256(g, h, a, b, c, d, e, f, K256(10), x[10]);
        R256(f, g, h, a, b, c, d, e, K256(11), x[11]);
        R256(e, f, g, h, a, b, c, d, K256(12), x[12]);
        R256(d, e, f, g, h, a, b, c, K256(13), x[13]);
        R256(c, d, e, f, g, h, a, b, K256(14), x[14]);
        R256(b, c, d, e, f, g, h, a, K256(15), x[15]);
        R256(a, b, c, d, e, f, g, h, K256(16), M256(16));
        R256(h, a, b, c, d, e, f, g, K256(17), M256(17));
        R256(g, h, a, b, c, d, e, f, K256(18), M256(18));
        R256(f, g, h, a, b, c, d, e, K256(19), M256(19));
        R256(e, f, g, h, a, b, c, d, K256(20), M256(20));
        R256(d, e, f, g, h, a, b, c, K256(21), M256(21));
        R256(c, d, e, f, g, h, a, b, K256(22), M256(22));
        R256(b, c, d, e, f, g, h, a, K256(23), M256(23));
        R256(a, b, c, d, e, f, g, h, K256(24), M256(24));
        R256(h, a, b, c, d, e, f, g, K256(25), M256(25));
        R256(g, h, a, b, c, d, e, f, K256(26), M256(26));
        R256(f, g, h, a, b, c, d, e, K256(27), M256(27));
        R256(e, f, g, h, a, b, c, d, K256(28), M256(28));
        R256(d, e, f, g, h, a, b, c, K256(29), M256(29));
        R256(c, d, e, f, g, h, a, b, K256(30), M256(30));
        R256(b, c, d, e, f, g, h, a, K256(31), M256(31));
        R256(a, b, c, d, e, f, g, h, K256(32), M256(32));
        R256(h, a, b, c, d, e, f, g, K256(33), M256(33));
        R256(g, h, a, b, c, d, e, f, K256(34), M256(34));
        R256(f, g, h, a, b, c, d, e, K256(35), M256(35));
        R256(e, f, g, h, a, b, c, d, K256(36), M256(36));
        R256(d, e, f, g, h, a, b, c, K256(37), M256(37));
        R256(c, d, e, f, g, h, a, b, K256(38), M256(38));
        R256(b, c, d, e, f, g, h, a, K256(39), M256(39));
        R256(a, b, c, d, e, f, g, h, K256(40), M256(40));
        R256(h, a, b, c, d, e, f, g, K256(41), M256(41));
        R256(g, h, a, b, c, d, e, f, K256(42), M256(42));
        R256(f, g, h, a, b, c, d, e, K256(43), M256(43));
        R256(e, f, g, h, a, b, c, d, K256(44), M256(44));
        R256(d, e, f, g, h, a, b, c, K256(45), M256(45));
        R256(c, d, e, f, g, h, a, b, K256(46), M256(46));
        R256(b, c, d, e, f, g, h, a, K256(47), M256(47));
        R256(a, b, c, d, e, f, g, h, K256(48), M256(48));
        R256(h, a, b, c, d, e, f, g, K256(49), M256(49));
        R256(g, h, a, b, c, d, e, f, K256(50), M256(50));
        R256(f, g, h, a, b, c, d, e, K256(51), M256(51));
        R256(e, f, g, h, a, b, c, d, K256(52), M256(52));
        R256(d, e, f, g, h, a, b, c, K256(53), M256(53));
        R256(c, d, e, f, g, h, a, b, K256(54), M256(54));
        R256(b, c, d, e, f, g, h, a, K256(55), M256(55));
        R256(a, b, c, d, e, f, g, h, K256(56), M256(56));
        R256(h, a, b, c, d, e, f, g, K256(57), M256(57));
        R256(g, h, a, b, c, d, e, f, K256(58), M256(58));
        R256(f, g, h, a, b, c, d, e, K256(59), M256(59));
        R256(e, f, g, h, a, b, c, d, K256(60), M256(60));
        R256(d, e, f, g, h, a, b, c, K256(61), M256(61));
        R256(c, d, e, f, g, h, a, b, K256(62), M256(62));
        R256(b, c, d, e, f, g, h, a, K256(63), M256(63));

        a = pAlgInfo->state[0] += a;
        b = pAlgInfo->state[1] += b;
        c = pAlgInfo->state[2] += c;
        d = pAlgInfo->state[3] += d;
        e = pAlgInfo->state[4] += e;
        f = pAlgInfo->state[5] += f;
        g = pAlgInfo->state[6] += g;
        h = pAlgInfo->state[7] += h;
    }
}



//////////////////////////////////////////////////////////////////////////////////////
// PBKDF2

bool HNC_HMAC_SHA1(const char* key, DWORD keylen, const char* in, DWORD inlen, char* resbuf)
{
    HNC_SHA1_ALG_INFO context;
    BYTE k_ipad[65];
    BYTE k_opad[65];
    BYTE tk[20];
    int i;

    if (keylen > 64) {
        HNC_SHA1_ALG_INFO tctx;

        HNC_SHA1_Init(&tctx);
        HNC_SHA1_Update(&tctx, (BYTE*)key, keylen);
        HNC_SHA1_Final(&tctx, tk);

        key = (const char*)tk;
        keylen = 20;
    }

    memset(k_ipad, 0, sizeof(k_ipad));
    memset(k_opad, 0, sizeof(k_opad));
    memcpy(k_ipad, key, keylen);
    memcpy(k_opad, key, keylen);

    for (i = 0; i < 64; ++i) {
        k_ipad[i] ^= 0x36;
        k_opad[i] ^= 0x5c;
    }

    HNC_SHA1_Init(&context);
    HNC_SHA1_Update(&context, k_ipad, 64);
    HNC_SHA1_Update(&context, (BYTE*)in, inlen);
    HNC_SHA1_Final(&context, (BYTE*)resbuf);

    HNC_SHA1_Init(&context);
    HNC_SHA1_Update(&context, k_opad, 64);
    HNC_SHA1_Update(&context, (BYTE*)resbuf, 20);
    HNC_SHA1_Final(&context, (BYTE*)resbuf);

    return true;
}

bool HNC_PBKDF2_SHA1(const char *P, size_t Plen, const char *S, size_t Slen, unsigned int c, char *DK, size_t dkLen)
{
    unsigned int hLen = 20;
    char U[20];
    char T[20];
    unsigned int u;
    size_t l;
    size_t r;
    unsigned int i;
    unsigned int k;
    bool rc = false;
    char *tmp;
    size_t tmplen = Slen + 4;

    if (c == 0) {
        _ASSERTE(!"INVALID_ITERATION_COUNT");
        return false;
    }

    if (dkLen == 0) {
        _ASSERTE(!"INVALID_DERIVED_KEY_LENGTH");
        return false;
    }

    if (dkLen > 4294967295U) {
        _ASSERTE(!"DERIVED_KEY_TOO_LONG");
        return false;
    }

    l = ((dkLen - 1) / hLen) + 1;
    r = dkLen - (static_cast<ptrdiff_t>(l) - 1) * hLen;

    tmp = (char*)malloc(tmplen);
    if (tmp == NULL) {
        _ASSERTE(!"MALLOC_ERROR");
        return false;
    }

    memcpy(tmp, S, Slen);

    for (i = 1; i <= l; i++) {
        memset(T, 0, hLen);

        for (u = 1; u <= c; u++) {
            if (u == 1) {
                tmp[Slen + 0] = static_cast<char>((i & 0xff000000) >> 24);
                tmp[Slen + 1] = static_cast<char>((i & 0x00ff0000) >> 16);
                tmp[Slen + 2] = static_cast<char>((i & 0x0000ff00) >> 8);
                tmp[Slen + 3] = static_cast<char>((i & 0x000000ff) >> 0);

                rc = HNC_HMAC_SHA1(P, static_cast<DWORD>(Plen), tmp, static_cast<DWORD>(tmplen), U);
            } else
                rc = HNC_HMAC_SHA1(P, static_cast<DWORD>(Plen), U, hLen, U);

            if (rc == false) {
                free(tmp);
                return rc;
            }

            for (k = 0; k < hLen; k++)
                T[k] ^= U[k];
        }

        memcpy(DK + (static_cast<ptrdiff_t>(i) - 1) * hLen, T, i == l ? r : hLen);
    }

    free(tmp);

    return true;
}

bool HncGetSHAHashA(LPCTSTR path, char* hashString, size_t hashStringSize)
{
    if (path && hashString && hashStringSize > 1) {
        FILE* file = NULL;
        errno_t result = _wfopen_s(&file, path, _T("rb"));
        if (result == 0 && file) {
            size_t bytes = 0;
            const int bufSize = 32768;
            char* buffer = (char*)malloc(bufSize);
            char* hash = new char[hashStringSize];
            if (buffer && hash) {
                HNC_SHA256_ALG_INFO sha256;
                HNC_SHA256_Init(&sha256);
                do {
                    bytes = fread(buffer, 1, bufSize, file);
                    if (bytes > 0) {
                        HNC_SHA256_Update(&sha256, (BYTE*)buffer, static_cast<DWORD>(bytes));
                    }
                } while (bytes > 0);
                free(buffer);
                buffer = 0;
                HNC_SHA256_Final(&sha256, (BYTE*)hash);
                for (size_t index = 0; index < hashStringSize / 2; index++) {
                    sprintf_s(hashString + (index * 2), hashStringSize - (index * 2), "%02x", (unsigned char)hash[index]);
                }
                delete[] hash;
            }
            fclose(file);
            return true;
        }
    }
    return false;
}

bool HncGetSHAHashW(LPCWSTR path, WCHAR* hashString, size_t hashStringSize)
{
#ifdef OS_UNIX
HNC_STR_CONV;
#endif
    bool result = false;
    if (path && hashString && hashStringSize > 1) {
        char* tmpHashString = new char[hashStringSize];

        if (tmpHashString) {
            result = HncGetSHAHashA(path, tmpHashString, hashStringSize);
            _ustrcpy_s(hashString, hashStringSize, _A2U(tmpHashString));
            delete[] tmpHashString;
        }
    }
    return result;
}


/*************** END OF FILE **********************************************/
