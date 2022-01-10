/*
 * Copyright Hancom Inc. All rights reserved.
 *
 * http://www.hancom.com/
 */

#ifndef HncBase_unix_HncCodeUnix_h
#define HncBase_unix_HncCodeUnix_h

#include <stdlib.h>
#include "./libhsp/hspconvert.h"
 // HncCode.h에 있는 매크로는 로컬 변수로 _ptemp,와 _ltemp를 사용하기 때문에 한
 // 라인에서 _U2A()같은 매크로를 여러번 사용하는 경우 문제가 되었다.  이를
 // 해결하기 위해서 class를 이용하여 구현하였는데, 이 역시 몇가지 문제가 있어서
 // class를 사용하지 않고 GCC의 extention 
 // "Statements and Declaration in Expression" 을 사용하여 구현한다.
 // 하지만 큰 사이즈로 alloca를 할 경우 죽는 문제가 있어 추가로 HncCode.h에 있는 매크로의
 // 문제를 일부 해결한 _CAutoFreeMallocUnix를 구현한다.
 // 만약 class를 이용한 구현의 문제를 해결할수 있다면 제거하도록 하자. LHSP-786

#ifdef __GNUC__

#undef  HNC_STR_CONV
#undef  _CP_A2U
#undef  _CP_U2A
#undef  _CP_T2U
#undef  _CP_U2T
#undef  _U2USP
#undef  _CP_A2A
#undef  _BASE642A
#undef  _A2BASE64
#undef  _U2UTF8
#undef  _UTF82U
#undef  _U2L
#undef  _L2U

/**
 * @brief The _CAutoFreeMallocUnix class
 *
 * malloc한 포인터 주소를 클래스에 추가하면 자동으로 free 해준다.
 * 최초 8개의 StackBufferCount로 m_pStackBuffer를 선언하여 사용하고 m_pStackBuffer의
 * 크기를 다 사용하면 m_pAllocBuffer를 realloc하여 사용한다.
 * m_pAllocBuffer의 크기가 부족하면 m_nCapacity의 8개 증가된 크기로 m_pAllocBuffer를
 * 다시 realloc하여 사용한다. realloc이 실패하면 NULL을 리턴한다.
 */
class _CAutoFreeMallocUnix {
public:
    enum {
        StackBufferCount = 8
    };

    size_t m_nCapacity;
    size_t m_nCount;
    void** m_pAllocBuffer;
    void*  m_pStackBuffer[StackBufferCount];

public:
    _CAutoFreeMallocUnix()
    {
        m_nCapacity = 0;
        m_nCount = 0;
        m_pAllocBuffer = NULL;
    }

    ~_CAutoFreeMallocUnix()
    {
        size_t i = m_nCount;
        while (i > StackBufferCount) {
            --i;
            free(m_pAllocBuffer[i - StackBufferCount]);
        }

        while (i > 0) {
            --i;
            free(m_pStackBuffer[i]);
        }

        free(m_pAllocBuffer);
    }

    void* AddAddress(void* ptr)
    {
        if (m_nCount >= m_nCapacity + StackBufferCount) {
            m_nCapacity += 8;
            void* tmp = realloc(m_pAllocBuffer, sizeof(void*) * m_nCapacity);
            // realloc이 실패했을때 m_pAllocBuffer의 주소를 잃어 버리지 않고
            // 이전까지의 포인터를 free할 수 있도록 NULL을 리턴한다.
            if (tmp == NULL) {
                return NULL;
            } else {
                m_pAllocBuffer = (void**)tmp;
            }
        }

        if (m_nCount < StackBufferCount) {
            m_pStackBuffer[m_nCount] = ptr;
            ++m_nCount;
        } else {
            if (m_pAllocBuffer) {
                m_pAllocBuffer[m_nCount - StackBufferCount] = ptr;
                ++m_nCount;
            }
        }

        return ptr;
    }
};

#define HNC_STR_CONV _CAutoFreeMallocUnix afm_STR_CONV;

// CodePage로 인코딩된 스트링을 utf-16으로 변환했을때 최대 길이는,
// s가 모두 surrogate pair로 표현되는 글자인 경우다. 이런 글자들은
// 최소 2byte 이상으로 인코딩 되어 있을 것이기 때문에 strlen()
// 이상으로 길어지지 않을 것이다.
#define _CP_A2U(cp, s)       ({                                                \
		WCHAR* _tmpbuf = NULL;                                                 \
		if ((LPCSTR)(s) != NULL) {                                             \
			int _tmplen = strlen(s) * 2 + 1;                                       \
            if (_tmplen <= 1024) {                                             \
                _tmpbuf = (WCHAR*)alloca(_tmplen * sizeof(WCHAR));             \
            } else {                                                           \
                _tmpbuf = (WCHAR*)malloc(_tmplen * sizeof(WCHAR));             \
                afm_STR_CONV.AddAddress(_tmpbuf);                              \
            }                                                                  \
			MultiByteToWideChar(cp, 0, s, -1, _tmpbuf, _tmplen);            \
		}                                                                      \
		_tmpbuf;                                                               \
	})

#define _CP_U2A(cp, s)       ({                                                \
		char* _tmpbuf = NULL;                                                  \
		if ((LPCWSTR)(s) != NULL) {                                            \
			int _tmplen = _ustrlen(s) * 6 + 1;                                 \
            if (_tmplen <= 1024) {                                             \
                _tmpbuf = (char*)alloca(_tmplen * sizeof(char));               \
            } else {                                                           \
                _tmpbuf = (char*)malloc(_tmplen * sizeof(char));               \
                afm_STR_CONV.AddAddress(_tmpbuf);                              \
            }                                                                  \
			WideCharToMultiByte(cp, 0, s, -1, _tmpbuf, _tmplen, NULL, FALSE);            \
		}                                                                      \
		_tmpbuf;                                                               \
	})

#define _U2L(s)       ({											           \
		char* _tmpbuf = NULL;                                                  \
		if ((LPCWSTR)(s) != NULL) {                                            \
			int _tmplen = _ustrlen(s) * 6 + 1;                                 \
            if (_tmplen <= 1024) {                                             \
                _tmpbuf = (char*)alloca(_tmplen * sizeof(char));               \
            } else {                                                           \
                _tmpbuf = (char*)malloc(_tmplen * sizeof(char));               \
                afm_STR_CONV.AddAddress(_tmpbuf);                              \
            }                                                                  \
			_wcscpy_to_locale(_tmpbuf, _tmplen, s, -1);                        \
		}                                                                      \
		_tmpbuf;                                                               \
	})

// #define _A2U(s)				_CP_A2U(CP_ACP, s)
// #define _U2A(s)				_CP_U2A(CP_ACP, s)

#endif // __GNUC__

#endif // HncBase_unix_HncCodeUnix_h
