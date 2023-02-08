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
#ifndef  _PSHADOW_H_
#define  _PSHADOW_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPShadow Declaration 
    class CPShadow : public CExtObject
    {
    private:
        CPShadow();
    public:
        virtual ~CPShadow();
        static CPShadow* Create();

        CPShadow* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CSkewType* Setskew(CSkewType* skew = NULL);
        CSkewType* Getskew(int index = 0);

        CScaleType* Setscale(CScaleType* scale = NULL);
        CScaleType* Getscale(int index = 0);

        CEffectsColorType* SeteffectsColor(CEffectsColorType* effectsColor = NULL);
        CEffectsColorType* GeteffectsColor(int index = 0);

        // Attribute Set/Get Fucntion
        SHADOWSTYLETYPE GetStyle(void) { return (SHADOWSTYLETYPE)m_uStyle; }
        void SetStyle(SHADOWSTYLETYPE style) { m_uStyle = (UINT)style; }

        FLOAT GetAlpha(void) { return m_fAlpha; }
        void SetAlpha(FLOAT alpha) { m_fAlpha = alpha; }

        FLOAT GetRadius(void) { return m_fRadius; }
        void SetRadius(FLOAT radius) { m_fRadius = radius; }

        FLOAT GetDirection(void) { return m_fDirection; }
        void SetDirection(FLOAT direction) { m_fDirection = direction; }

        FLOAT GetDistance(void) { return m_fDistance; }
        void SetDistance(FLOAT distance) { m_fDistance = distance; }

        ALIGNSTYLETYPE GetAlignStyle(void) { return (ALIGNSTYLETYPE)m_uAlignStyle; }
        void SetAlignStyle(ALIGNSTYLETYPE alignStyle) { m_uAlignStyle = (UINT)alignStyle; }

        BOOL GetRotationStyle(void) { return m_bRotationStyle == true ? TRUE : FALSE; }
        void SetRotationStyle(BOOL rotationStyle) { m_bRotationStyle = (rotationStyle == TRUE ? true : false); }


    private:
        UINT m_uStyle = 0;
        FLOAT m_fAlpha;
        FLOAT m_fRadius;
        FLOAT m_fDirection;
        FLOAT m_fDistance;
        UINT m_uAlignStyle = 0;
        bool m_bRotationStyle;
    };
}
#endif // _PSHADOW_H_
