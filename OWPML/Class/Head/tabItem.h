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
#ifndef  _TABITEM_H_
#define  _TABITEM_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CTabItem Declaration 
    class CTabItem : public CExtObject
    {
    private:
        CTabItem();
    public:
        virtual ~CTabItem();
        static CTabItem* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetPos(void) { return m_nPos; }
        void SetPos(INT pos) { m_nPos = pos; }

        TABITEMTYPE GetType(void) { return (TABITEMTYPE)m_uType; }
        void SetType(TABITEMTYPE type) { m_uType = (UINT)type; }

        LINETYPE2 GetLeader(void) { return (LINETYPE2)m_uLeader; }
        void SetLeader(LINETYPE2 leader) { m_uLeader = (UINT)leader; }

        UINTVALUETYPE GetUnit(void) { return (UINTVALUETYPE)m_nUnit; }
        void SetUnit(UINTVALUETYPE leader) { m_nUnit = (INT)leader; }

    private:
        INT m_nPos;
        UINT m_uType = 0;
        UINT m_uLeader;
        INT m_nUnit;
    };
}
#endif // _TABITEM_H_
