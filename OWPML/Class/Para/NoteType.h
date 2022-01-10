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
#ifndef  _NOTETYPE_H_
#define  _NOTETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CNoteType Declaration 
    class CNoteType : public CExtObject
    {
    private:
        CNoteType(UINT id);
    public:
        virtual ~CNoteType();
        static CNoteType* Create();
        static CNoteType* CreateArg(UINT id);

        CNoteType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        // property가 아니지만, 쓰레기값을 방지하여 불필요한 업데이트를 줄이기 위해 serialize한다.
        UINT32 GetFlags(void) { return m_Flags; }
        void SetFlags(UINT32 flag) { m_Flags = flag; }

        UINT32 GetNumber(void) { return m_Number; }
        void SetNumber(UINT32 number) { m_Number = (UINT16)number; }

        WCHAR GetUserChar(void) { return m_UserChar; }
        void SetUserChar(WCHAR uchar) { m_UserChar = uchar; }

        WCHAR GetPrefixChar(void) { return m_PrefixChar; }
        void SetPrefixChar(WCHAR pchar) { m_PrefixChar = pchar; }

        WCHAR GetSuffixChar(void) { return m_SuffixChar; }
        void SetSuffixChar(WCHAR schar) { m_SuffixChar = schar; }

        UINT32 GetInstID(void) { return m_InstID; }
        void SetInstID(UINT32 id) { m_InstID = id; }

    private:
        // property가 아니지만, 쓰레기값을 방지하여 불필요한 업데이트를 줄이기 위해 serialize한다.
        UINT32                m_Flags;
        UINT16                m_Number;
        WCHAR                 m_UserChar;
        WCHAR                 m_PrefixChar;
        WCHAR                 m_SuffixChar;
        UINT32                m_InstID;
    };
}
#endif // _NOTETYPE_H_
