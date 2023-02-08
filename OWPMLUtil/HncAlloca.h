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
#ifndef HNCALLOCA_H_
#define HNCALLOCA_H_

#define _AFM_STACK_BUFFER_SIZE 2

class _CAutoFreeMalloca
{
public:
    _CAutoFreeMalloca()
    {
        m_parAddress = m_pStackBuffer;
        m_nCount = 0;
    }
    ~_CAutoFreeMalloca()
    {
        int i;

        for (i = 0; i < m_nCount; ++i)
            _freea(m_parAddress[i]);

        if (m_nCount > _AFM_STACK_BUFFER_SIZE)
            free(m_parAddress);

    }
    void* AddAddress(void* ptr)
    {
        if (m_nCount >= _AFM_STACK_BUFFER_SIZE) {
            _ASSERTE(m_nCount >= 0 && "UINT 음수 보안패치");

            void** ptrTemp = (void**)malloc(sizeof(void*) * (static_cast<size_t>(m_nCount) + 1));
            if (ptrTemp) {
                memcpy(ptrTemp, m_parAddress, sizeof(void*) * m_nCount);
                if (m_nCount > _AFM_STACK_BUFFER_SIZE)
                    free(m_parAddress);
                m_parAddress = ptrTemp;
            }
        }

        if (m_parAddress) {
            m_parAddress[m_nCount] = ptr;
            ++m_nCount;
        }

        return ptr;
    }
public:
    int m_nCount = 0;
    void** m_parAddress = NULL;
    void*  m_pStackBuffer[_AFM_STACK_BUFFER_SIZE] = { NULL, };
};


//////////////////////////////////////////////////////////////////////
// CHncAlloca : _alloca()를 실패할 경우 malloc을 대치.
//////////////////////////////////////////////////////////////////////

class CHncAlloca
{
public:
    CHncAlloca();
    ~CHncAlloca();

    void *_AllocBuffer(size_t size);

public:
    void *m_pBuff;
};

inline CHncAlloca::CHncAlloca()
{
    m_pBuff = NULL;
}

inline CHncAlloca::~CHncAlloca()
{
    free(m_pBuff);
}

inline void *CHncAlloca::_AllocBuffer(size_t size)
{
    return m_pBuff = malloc(size);
}



#define MAX_HNCALLOCA_SIZE                    (256 * 1024)
#define GETNAME_HNCALLOCA()                   __hnc_alloca
#define GETNAME_HNCALLOCAEX(varname)          __hnc_alloca_##varname

#define DECLARE_HNCALLOCA()                   CHncAlloca GETNAME_HNCALLOCA();
#define DECLARE_HNCALLOCAEX(varname)          CHncAlloca GETNAME_HNCALLOCAEX(##varname);

#define IMPLEMENT_HNCALLOCA(size) \
            __pragma(warning(suppress: 6255)) \
            ((size_t)(size) < MAX_HNCALLOCA_SIZE ? _alloca((size_t)(size)) : GETNAME_HNCALLOCA()._AllocBuffer((size_t)(size))) 

#define IMPLEMENT_HNCALLOCAEX(size, varname) \
            __pragma(warning(suppress: 6255)) \
            ((size_t)(size) < MAX_HNCALLOCA_SIZE ? _alloca((size_t)(size)) : GETNAME_HNCALLOCAEX(##varname)._AllocBuffer((size_t)(size)))

#define HNCALLOCA(pbuf, valtype, size) \
        DECLARE_HNCALLOCA() \
        (pbuf) = (valtype) IMPLEMENT_HNCALLOCA(size)

#define HNCALLOCAEX(pbuf, valtype, size, varname) \
        DECLARE_HNCALLOCAEX(##varname) \
        (pbuf) = (valtype) IMPLEMENT_HNCALLOCAEX(size, ##varname)

#endif //HNCALLOCA_H_