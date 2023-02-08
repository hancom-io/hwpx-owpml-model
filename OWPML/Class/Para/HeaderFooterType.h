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
#ifndef  _HEADERFOOTERTYPE_H_
#define  _HEADERFOOTERTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CHeaderFooterType Declaration 
    class CHeaderFooterType : public CExtObject
    {
    private:
        CHeaderFooterType(UINT id = ID_PARA_HeaderType);
    public:
        virtual ~CHeaderFooterType();
        static CHeaderFooterType* Create();
        static CHeaderFooterType* CreateArg(UINT id = ID_PARA_HeaderType);

        CHeaderFooterType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CParaListType* SetsubList(CParaListType* subList = NULL);
        CParaListType* GetsubList(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        APPLYPAGETYPE GetApplyPageType(void) { return (APPLYPAGETYPE)m_uApplyPageType; }
        void SetApplyPageType(APPLYPAGETYPE applyPageType) { m_uApplyPageType = (UINT)applyPageType; }


    private:
        UINT m_uId = 0;
        UINT m_uApplyPageType;
    };
}
#endif // _HEADERFOOTERTYPE_H_
