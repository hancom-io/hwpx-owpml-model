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
#ifndef  _NOTELINE_H_
#define  _NOTELINE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CNoteLine Declaration 
    class CNoteLine : public CExtObject
    {
    private:
        CNoteLine();
    public:
        virtual ~CNoteLine();
        static CNoteLine* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetLength(void) { return m_nLength; }
        void SetLength(INT length) { m_nLength = length; }

        LINETYPE2 GetType(void) { return (LINETYPE2)m_uType; }
        void SetType(LINETYPE2 type) { m_uType = (UINT)type; }

        LINEWITHTYPE GetWidth(void) { return (LINEWITHTYPE)m_uWidth; }
        void SetWidth(LINEWITHTYPE width) { m_uWidth = (UINT)width; }

        COLORREF GetColor(void) { return m_cColor; }
        void SetColor(COLORREF color) { m_cColor = color; }


    private:
        INT m_nLength;
        UINT m_uType;
        UINT m_uWidth;
        CColorRef m_cColor;
    };
}
#endif // _NOTELINE_H_
