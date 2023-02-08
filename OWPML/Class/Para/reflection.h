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
#ifndef  _REFLECTION_H_
#define  _REFLECTION_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CSkewType;
    class CScaleType;
    class CAlpha;
    class CPos;

    // CReflection Declaration 
    class CReflection : public CExtObject
    {
    private:
        CReflection();
    public:
        virtual ~CReflection();
        static CReflection* Create();

        CReflection* Clone();

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

        CAlpha* Setalpha(CAlpha* alpha = NULL);
        CAlpha* Getalpha(int index = 0);

        CRFPos* Setpos(CRFPos* pos = NULL);
        CRFPos* Getpos(int index = 0);

        // Attribute Set/Get Fucntion
        ALIGNSTYLETYPE GetAlignStyle(void) { return (ALIGNSTYLETYPE)m_uAlignStyle; }
        void SetAlignStyle(ALIGNSTYLETYPE alignStyle) { m_uAlignStyle = (UINT)alignStyle; }

        FLOAT GetRadius(void) { return m_fRadius; }
        void SetRadius(FLOAT radius) { m_fRadius = radius; }

        FLOAT GetDirection(void) { return m_fDirection; }
        void SetDirection(FLOAT direction) { m_fDirection = direction; }

        FLOAT GetDistance(void) { return m_fDistance; }
        void SetDistance(FLOAT distance) { m_fDistance = distance; }

        BOOL GetRotationStyle(void) { return m_bRotationStyle == true ? TRUE : FALSE; }
        void SetRotationStyle(BOOL rotationStyle) { m_bRotationStyle = (rotationStyle == TRUE ? true : false); }

        FLOAT GetFadeDirection(void) { return m_fFadeDirection; }
        void SetFadeDirection(FLOAT fadeDirection) { m_fFadeDirection = fadeDirection; }


    private:
        UINT m_uAlignStyle = 0;
        FLOAT m_fRadius;
        FLOAT m_fDirection;
        FLOAT m_fDistance;
        bool m_bRotationStyle;
        FLOAT m_fFadeDirection;
    };
}
#endif // _REFLECTION_H_
