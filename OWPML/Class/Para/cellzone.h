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
#ifndef  _CELLZONE_H_
#define  _CELLZONE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCellzone Declaration 
    class CCellzone : public CExtObject
    {
    private:
        CCellzone();
    public:
        virtual ~CCellzone();
        static CCellzone* Create();

        CCellzone* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetStartRowAddr(void) { return m_uStartRowAddr; }
        void SetStartRowAddr(UINT startRowAddr) { m_uStartRowAddr = startRowAddr; }

        UINT GetStartColAddr(void) { return m_uStartColAddr; }
        void SetStartColAddr(UINT startColAddr) { m_uStartColAddr = startColAddr; }

        UINT GetEndRowAddr(void) { return m_uEndRowAddr; }
        void SetEndRowAddr(UINT endRowAddr) { m_uEndRowAddr = endRowAddr; }

        UINT GetEndColAddr(void) { return m_uEndColAddr; }
        void SetEndColAddr(UINT endColAddr) { m_uEndColAddr = endColAddr; }

        UINT GetBorderFillIDRef(void) { return m_uBorderFillIDRef; }
        void SetBorderFillIDRef(UINT borderFillIDRef) { m_uBorderFillIDRef = borderFillIDRef; }


    private:
        UINT m_uStartRowAddr;
        UINT m_uStartColAddr;
        UINT m_uEndRowAddr;
        UINT m_uEndColAddr;
        UINT m_uBorderFillIDRef;
    };
}
#endif // _CELLZONE_H_
