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
#ifndef  _UNDERLINE_H_
#define  _UNDERLINE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CUnderline Declaration 
    class CUnderline : public CExtObject
    {
    private:
        CUnderline();
    public:
        virtual ~CUnderline();
        static CUnderline* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UNDERLINETYPE GetType(void) { return (UNDERLINETYPE)m_uType; }
        void SetType(UNDERLINETYPE type) { m_uType = (UINT)type; }

        LINETYPE2 GetShape(void) { return (LINETYPE2)m_uShape; }
        void SetShape(LINETYPE2 shape) { m_uShape = (UINT)shape; }

        COLORREF GetColor(void) { return m_cColor; }
        void SetColor(COLORREF color) { m_cColor = color; }


    private:
        UINT m_uType;
        UINT m_uShape;
        CColorRef m_cColor;
    };
}
#endif // _UNDERLINE_H_
