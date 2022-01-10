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
#ifndef HNCDEFINE_H
#define HNCDEFINE_H

// OS 정의가 없으면 OS_WIN으로 간주한다.
#if !defined(OS_UNIX) && !defined(OS_MAC) && !defined(OS_WIN)
#define OS_WIN 1
#endif //


#include <sstream>

#include "HncBaseStringDef.h"

#include <wtypes.h>
#include <tchar.h>
#include <string.h>
#include <string>
#include "StringDef.h"
#include "HncAlloca.h"

#ifdef OS_WIN
// 공통 전처리기 정의
#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE 1 // UNICODE is used by Windows headers
#endif
#endif

#ifdef UNICODE
#ifndef _UNICODE
#define _UNICODE 1 // _UNICODE is used by C-runtime/MFC headers
#endif
#endif
#endif

#ifdef _DEBUG
#ifndef DEBUG
#define DEBUG 1
#endif
#endif

#if defined(DEBUG) && defined(OS_UNIX)
#define _ASSERT(expr) assert(expr)
#define _ASSERTE(expr) assert(expr)
#endif

#define NOMINMAX
#ifndef WINVER
#define WINVER            0x0600
#define _WIN32_WINNT      0x0600
#define _WIN32_IE         0x0700
#endif // WINVER



#define __L(x)                L##x
#define __W(defined_str)    __L(defined_str)

#ifndef _W
# define _W(defined_str)    __W(defined_str)
#endif // _L

#define HNC_DIR_SEPARATOR '\\'
#define HNC_DIR_SEPARATOR_S "\\"
#define HNC_DIR_SEPARATOR_W L'\\'
#define HNC_DIR_SEPARATOR_WS L"\\"
#define HNC_DIR_SEPARATOR_T _T('\\')
#define HNC_DIR_SEPARATOR_TS _T("\\")

inline LPCWSTR ConvertA2U(UINT codePage, LPCSTR s) {
    CHncAlloca __hnc_alloca;
    void *_ptemp = NULL;
    int _ltemp = 0;

    _ltemp = strlen(s) * 3 + 4;

    if (s == NULL)
        return NULL;

    _ptemp = (WCHAR*)((size_t)(_ltemp) < (256 * 1024) ? _alloca((size_t)(_ltemp)) : __hnc_alloca._AllocBuffer((size_t)(_ltemp)));
    MultiByteToWideChar(codePage, 0, s, -1, (LPWSTR)_ptemp, _ltemp / sizeof(WCHAR));
    return (LPCWSTR)_ptemp;
}

inline LPCSTR ConvertU2A(UINT codePage, LPCWSTR s) {
    CHncAlloca __hnc_alloca;
    void *_ptemp = NULL;
    int _ltemp = 0;

    _ltemp = _ustrlen(s) * 3 + 4;

    if (s == NULL)
        return NULL;

    _ptemp = (TCHAR*)((size_t)(_ltemp) < (256 * 1024) ? _alloca((size_t)(_ltemp)) : __hnc_alloca._AllocBuffer((size_t)(_ltemp)));
    WideCharToMultiByte(codePage, 0, s, -1, (LPSTR)_ptemp, _ltemp, NULL, NULL);
    return (LPCSTR)_ptemp;
}

#define _A2U(s)                ConvertA2U(CP_ACP, s)
#define _U2A(s)                ConvertU2A(CP_ACP, s)
#define _U2L(s)             ConvertU2A(CP_ACP, s)

#ifdef _UNICODE
#    define _SYS_T2U(s)                (const WCHAR *)(s)
#    define _SYS_U2T(s)                (const WCHAR *)(s)
#else // _UNICODE
#    define _SYS_T2U(s)                ConvertA2U(CP_ACP, s)
#    define _SYS_U2T(s)                ConvertU2A(CP_ACP, s)
#endif // _UNICODE


#ifdef _DEBUG
#define _VERIFY(e)    _ASSERTE((e) != 0)
#else // _DEBUG    _RELEASE
#define _VERIFY(x)    ((void)(x))
#endif

#define NELEM(x) (sizeof(x) / sizeof(x[0]))

#if defined(__GNUC__)
#  define _HNC_INSECURE_DEPRECATE1(Replacement) __attribute__((deprecated("This function or variable may be unsafe.\r\n          Please Use: '" #Replacement "'"), unused))
#  define _HNC_INSECURE_DEPRECATE0 __attribute__((deprecated("This function or variable may be unsafe."), unused))
#elif defined(_MSC_VER)
#  define _HNC_INSECURE_DEPRECATE1(Replacement) __declspec(deprecated("This function or variable may be unsafe.\r\n          Please Use: '" #Replacement "'"))
#  define _HNC_INSECURE_DEPRECATE0 __declspec(deprecated("This function or variable may be unsafe."))
#else
#  define _HNC_INSECURE_DEPRECATE1(Replacement)
#  define _HNC_INSECURE_DEPRECATE0
#endif


// _ultoa() 및 _ultoa_s()와 unsigned long to ascii와의 의미 충돌 해결
inline _HNC_INSECURE_DEPRECATE1(_ultoa_s) wchar_t* _ultoa(long _Value, wchar_t* _Dest, int _Radix)
{
    __pragma(warning(push))
    __pragma(warning(disable:4996))

    return _ltow(_Value, _Dest, _Radix);

    __pragma(warning(pop))

}

inline _HNC_INSECURE_DEPRECATE1(_uultoa_s) wchar_t* _uultoa(unsigned long _Value, wchar_t* _Dest, int _Radix)
{

    __pragma(warning(push))
    __pragma(warning(disable:4996))

    return _ultow(_Value, _Dest, _Radix);

    __pragma(warning(pop))

}

inline errno_t _ultoa_s(long _Value, wchar_t* _DstBuf, size_t _SizeInWords, int _Radix)
{
    return _ltow_s(_Value, _DstBuf, _SizeInWords, _Radix);
}

inline errno_t _uultoa_s(unsigned long _Value, wchar_t* _DstBuf, size_t _SizeInWords, int _Radix)
{
    return _ultow_s(_Value, _DstBuf, _SizeInWords, _Radix);
}


//////////////////////////////////////////////////////////////
// ASCII to BASE64 Encoding , BASE64 to ASCII Decoding
//////////////////////////////////////////////////////////////
// 인코딩 및 디코딩 루틴
// memchunk 는 ASCII 데이터와 그 크기
static const char* to_b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
// 한라인 당 72 문자 
#define CHARS_PER_LINE  72

inline int Base64Encoding(LPCSTR asciistr, const int slen, char** string)
{
    if (asciistr == NULL || slen <= 0) {
        return 0;
    }

    int div = slen / 3;
    int rem = slen % 3;
    int charCount = ((slen + 2) / 3) * 4;//div*4 + rem + 1;
    int newlines = (charCount + CHARS_PER_LINE - 1) / CHARS_PER_LINE;

    const BYTE* data = (const BYTE*)asciistr;

    if (*string == NULL) {
        *string = (char*)malloc(charCount + static_cast<size_t>(newlines) + 1);
    }

    int chars = charCount;

    if (string != NULL && *string != NULL) {
        char* buf = *string;

        if (buf == NULL) {
            return -1;
        }

        chars = 0;

        // Base64 Encoding
        while (div > 0) {
            buf[0] = to_b64[(data[0] >> 2) & 0x3f];
            buf[1] = to_b64[((data[0] << 4) & 0x30) + ((data[1] >> 4) & 0xf)];
            buf[2] = to_b64[((data[1] << 2) & 0x3c) + ((data[2] >> 6) & 0x3)];
            buf[3] = to_b64[data[2] & 0x3f];
            data += 3;
            buf += 4;
            div--;
            chars += 4;
            if (chars == CHARS_PER_LINE) {
                chars = 0;
                *(buf++) = '\n';
            }
        }

        switch (rem) {
        case 2:
            buf[0] = to_b64[(data[0] >> 2) & 0x3f];
            buf[1] = to_b64[((data[0] << 4) & 0x30) + ((data[1] >> 4) & 0xf)];
            buf[2] = to_b64[(data[1] << 2) & 0x3c];
            buf[3] = '=';
            buf += 4;
            chars += 4;
            break;
        case 1:
            buf[0] = to_b64[(data[0] >> 2) & 0x3f];
            buf[1] = to_b64[(data[0] << 4) & 0x30];
            buf[2] = '=';
            buf[3] = '=';
            buf += 4;
            chars += 4;
            break;
        }

        *buf = '\0';
    }

    return (chars + newlines * (CHARS_PER_LINE + 1));    // 메모리의 소유권은 Caller에게 넘어간다.
}


inline int HncAsciiToBase64(LPCSTR asciistr, const int slen, char** string)
{
    return Base64Encoding(asciistr, slen, string);
}



inline int Base64Decoding(LPCSTR string, char** asciistr)
{
    if (string == NULL) {
        return 0;
    }

    int length = static_cast<int>(strlen(string));
    if (length < 1) {
        return 0;
    }

    int count = 0, rem = 0;
    const char* tmp = string;

    while (0 < length) {
        int skip = static_cast<int>(strspn(tmp, to_b64));
        count += skip;
        length -= skip;
        tmp += skip;
        if (0 < length) {
            int i, vrfy = static_cast<int>(strcspn(tmp, to_b64));

            for (i = 0; i < vrfy; i++) {
                if (isspace(tmp[i]))
                    continue;
                if (tmp[i] == '=') {
                    /* we should check if we're close to the end of the string */
                    rem = count % 4;
                    // rem이 2또는 3일 경우에만 "=" 가 존재해야 한다.
                    if (rem < 2)
                        return 0;
                    // 종료 마크 인식
                    break;
                } else {
                    return 0;
                }
            }
            length -= vrfy;
            tmp += vrfy;
        }
    }

    int asciistrlen = (count / 4) * 3 + (rem ? (rem - 1) : 0);
    if (asciistrlen < 1) {
        return 0;
    }

    if (*asciistr == NULL) {
        *asciistr = (char*)malloc(asciistrlen * sizeof(char));
    }

    if (*asciistr) {
        if (count > 0) {
            int i, qw = 0, tw = 0;
            BYTE* data = (BYTE*)*asciistr;

            length = static_cast<int>(strlen(tmp = string));

            for (i = 0; i < length; i++) {
                char ch = string[i];
                BYTE bits;

                if (isspace(ch))
                    continue;

                bits = 0;

                if ((ch >= 'A') && (ch <= 'Z')) {
                    bits = (BYTE)(ch - 'A');
                } else if ((ch >= 'a') && (ch <= 'z')) {
                    bits = (BYTE)(ch - 'a' + 26);
                } else if ((ch >= '0') && (ch <= '9')) {
                    bits = (BYTE)(ch - '0' + 52);
                } else if (ch == '+') {
                    bits = (BYTE)62;
                } else if (ch == '/') {
                    bits = (BYTE)63;
                } else if (ch == '=') {
                    break;
                } else { // 무시해도됨.
                    continue;
                }

                switch (qw++) {
                case 0:
                    if (tw < asciistrlen) {
                        data[tw + 0] = (bits << 2) & 0xfc;
                    }
                    break;
                case 1:
                    if (tw < asciistrlen) {
                        data[tw + 0] |= (bits >> 4) & 0x03;
                    }
                    if ((tw + 1) < asciistrlen) {
                        data[tw + 1] = (bits << 4) & 0xf0;
                    }
                    break;
                case 2:
                    if ((tw + 1) < asciistrlen) {
                        data[tw + 1] |= (bits >> 2) & 0x0f;
                    }
                    if ((tw + 2) < asciistrlen) {
                        data[tw + 2] = (bits << 6) & 0xc0;
                    }
                    break;
                case 3:
                    if ((tw + 2) < asciistrlen) {
                        data[tw + 2] |= bits & 0x3f;
                    }
                    break;
                }

                if (qw == 4) {
                    qw = 0;
                    tw += 3;
                }
            }
        }
    }

    return ((count / 4) * 3 + (rem ? (rem - 1) : 0));
}

/**
 * @brief Base64를 Ascii으로 Decoding한다..
 * @ingroup HncCode
 *
 * @param string 변환할 Base64형 문자열.
 * @param asciistr 변환된 문자열을 저장할 버퍼의 포인터.
 * @return 성공여부 성공시 변환된 문자열의 길이, 실패시 0 리턴.
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see
 */
inline int HncBase64ToAscii(LPCSTR string, char** asciistr)
{
    return Base64Decoding(string, asciistr);
}
#endif //HNCDEFINE_H