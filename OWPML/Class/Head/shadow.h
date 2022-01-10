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
#ifndef  _SHADOW_H_
#define  _SHADOW_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCharShadow Declaration 
    class CCharShadow : public CExtObject
    {
    private:
        CCharShadow();
    public:
        virtual ~CCharShadow();
        static CCharShadow* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        CSHADOWTYPE GetType(void) { return (CSHADOWTYPE)m_uType; }
        void SetType(CSHADOWTYPE type) { m_uType = (UINT)type; }

        COLORREF GetColor(void) { return m_cColor; }
        void SetColor(COLORREF color) { m_cColor = color; }

        INT GetOffsetX(void) { return m_nOffsetX; }
        void SetOffsetX(INT offsetX) { m_nOffsetX = offsetX; }

        INT GetOffsetY(void) { return m_nOffsetY; }
        void SetOffsetY(INT offsetY) { m_nOffsetY = offsetY; }

    protected:
        UINT m_uType;
        CColorRef m_cColor;
        INT m_nOffsetX;
        INT m_nOffsetY;
    };

}
#endif // _SHADOW_H_
