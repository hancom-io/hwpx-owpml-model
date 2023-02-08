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
#ifndef  _EFFECTSCOLORTYPE_H_
#define  _EFFECTSCOLORTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CRgb;
    class CCmyk;
    class CScheme;
    class CSystem;
    class CEffect;

    // CEffectsColorType Declaration 
    class CEffectsColorType : public CExtObject
    {
    private:
        CEffectsColorType();
    public:
        virtual ~CEffectsColorType();
        static CEffectsColorType* Create();

        CEffectsColorType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CRgb* Setrgb(CRgb* rgb = NULL);
        CRgb* Getrgb(int index = 0);

        CCmyk* Setcmyk(CCmyk* cmyk = NULL);
        CCmyk* Getcmyk(int index = 0);

        CScheme* Setscheme(CScheme* scheme = NULL);
        CScheme* Getscheme(int index = 0);

        CSystem* Setsystem(CSystem* system = NULL);
        CSystem* Getsystem(int index = 0);

        CEffect* Seteffect(CEffect* effect = NULL);
        CEffect* Geteffect(int index = 0);

        // Attribute Set/Get Fucntion
        EFFECTCOLORTYPE GetType(void) { return (EFFECTCOLORTYPE)m_uType; }
        void SetType(EFFECTCOLORTYPE type) { m_uType = (UINT)type; }

        INT GetSchemeIdx(void) { return m_nSchemeIdx; }
        void SetSchemeIdx(INT schemeIdx) { m_nSchemeIdx = schemeIdx; }

        INT GetSystemIdx(void) { return m_nSystemIdx; }
        void SetSystemIdx(INT systemIdx) { m_nSystemIdx = systemIdx; }

        INT GetPresetIdx(void) { return m_nPresetIdx; }
        void SetPresetIdx(INT presetIdx) { m_nPresetIdx = presetIdx; }


    private:
        UINT m_uType = 0;
        INT m_nSchemeIdx;
        INT m_nSystemIdx;
        INT m_nPresetIdx;
    };
}
#endif // _EFFECTSCOLORTYPE_H_
