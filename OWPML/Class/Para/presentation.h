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
#ifndef  _PRESENTATION_H_
#define  _PRESENTATION_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CFillBrushType;

    // CPresentation Declaration 
    class CPresentation : public CExtObject
    {
    private:
        CPresentation();
    public:
        virtual ~CPresentation();
        static CPresentation* Create();

        CPresentation* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CFillBrushType* SetfillBrush(CFillBrushType* fillBrush = NULL);
        CFillBrushType* GetfillBrush(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetEffect(void) { return m_effect; }
        void SetEffect(UINT effect) { m_effect = effect; }

        LPCWSTR GetSoundIDRef(void) { return m_soundIDRef.c_str(); }
        void SetSoundIDRef(LPCWSTR soundIDRef) { m_soundIDRef = soundIDRef; }

        BOOL GetInvertText(void) { return m_invertText == true ? TRUE : FALSE; }
        void SetInvertText(BOOL invertText) { m_invertText = (invertText == TRUE ? true : false); }

        BOOL GetAutoshow(void) { return m_autoshow == true ? TRUE : FALSE; }
        void SetAutoshow(BOOL autoshow) { m_autoshow = (autoshow == TRUE ? true : false); }

        UINT GetShowtime(void) { return m_showtime; }
        void SetShowtime(UINT showtime) { m_showtime = showtime; }

        UINT GetApplyto(void) { return m_applyto; }
        void SetApplyto(UINT applyto) { m_applyto = applyto; }

    private:
        UINT m_effect;
        hncstd::wstring m_soundIDRef;
        bool m_invertText;
        bool m_autoshow;
        UINT m_showtime;
        UINT m_applyto;
    };
}
#endif // _PRESENTATION_H_
