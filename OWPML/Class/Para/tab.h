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
#ifndef  _TAB_H_
#define  _TAB_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CTab Declaration 
    class CTab : public CExtObject
    {
    private:
        CTab();
    public:
        virtual ~CTab();
        static CTab* Create();

        CTab* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        UINT Getwidth(void) { return m_uWidth; }
        void Setwidth(UINT value) { m_uWidth = value; }

        UINT Getleader(void) { return m_uLeader; }
        void Setleader(UINT value) { m_uLeader = value; }

        UINT Gettype(void) { return m_uType; }
        void Settype(UINT value) { m_uType = value; }

    private:
        UINT m_uWidth;
        UINT m_uLeader;
        UINT m_uType;
    private:
    };
}
#endif // _TAB_H_
