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
#ifndef  _COMPOSE_H_
#define  _COMPOSE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCompose Declaration 
    class CCompose : public CExtObject
    {
    private:
        CCompose();
    public:
        virtual ~CCompose();
        static CCompose* Create();

        CCompose* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CCharPr* SetcharPr(CCharPr* charPr = NULL);
        CCharPr* GetcharPr(int index = 0);

        // Attribute Set/Get Fucntion
        SHAPECIRCLETYPE GetCircleType(void) { return (SHAPECIRCLETYPE)m_uCircleType; }
        void SetCircleType(SHAPECIRCLETYPE circleType) { m_uCircleType = (UINT)circleType; }

        INT GetCharSz(void) { return m_nCharSz; }
        void SetCharSz(INT charSz) { m_nCharSz = charSz; }

        COMPOSETYPE GetComposeType(void) { return (COMPOSETYPE)m_uComposeType; }
        void SetComposeType(COMPOSETYPE composeType) { m_uComposeType = (UINT)composeType; }

        UINT GetCharPrCnt(void) { return m_uCharPrCnt; }
        void SetCharPrCnt(UINT charPrCnt) { m_uCharPrCnt = charPrCnt; }

        LPCWSTR GetComposeText(void) { return m_strText.c_str(); }
        void SetComposeText(LPCWSTR text) { m_strText = text; }

    private:
        UINT m_uCircleType;
        INT m_nCharSz;
        UINT m_uComposeType;
        UINT m_uCharPrCnt;
        hncstd::wstring m_strText;
    };
}
#endif // _COMPOSE_H_
