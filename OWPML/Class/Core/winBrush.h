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
#ifndef  _WINBRUSH_H_
#define  _WINBRUSH_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CWinBrush Declaration 
    class CWinBrush : public CExtObject
    {
    private:
        CWinBrush();
    public:
        virtual ~CWinBrush();
        static CWinBrush* Create();

        CWinBrush* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        COLORREF GetFaceColor(void) { return m_cFaceColor; }
        void SetFaceColor(COLORREF faceColor) { m_cFaceColor = faceColor; }

        COLORREF GetHatchColor(void) { return m_cHatchColor; }
        void SetHatchColor(COLORREF hatchColor) { m_cHatchColor = hatchColor; }

        HATCHSTYLETYPE GetHatchStyle(void) { return (HATCHSTYLETYPE)m_uHatchStyle; }
        void SetHatchStyle(HATCHSTYLETYPE hatchStyle) { m_uHatchStyle = (UINT)hatchStyle; }

        FLOAT GetAlpha(void) { return m_fAlpha; }
        void SetAlpha(FLOAT alpha) { m_fAlpha = alpha; }


    private:
        CColorRef m_cFaceColor;
        CColorRef m_cHatchColor;
        UINT m_uHatchStyle;
        FLOAT m_fAlpha;
    };
}
#endif // _WINBRUSH_H_
