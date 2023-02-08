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
#ifndef  _GRADATION_H_
#define  _GRADATION_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CGradation Declaration 
    class CGradation : public CExtObject
    {
    private:
        CGradation();
    public:
        virtual ~CGradation();
        static CGradation* Create();

        CGradation* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CColor* Setcolor(CColor* color = NULL);
        CColor* Getcolor(int index = 0);

        // Attribute Set/Get Fucntion
        GRADATIONTYPE GetType(void) { return (GRADATIONTYPE)m_uType; }
        void SetType(GRADATIONTYPE type) { m_uType = (UINT)type; }

        INT GetAngle(void) { return m_nAngle; }
        void SetAngle(INT angle) { m_nAngle = angle; }

        INT GetCenterX(void) { return m_nCenterX; }
        void SetCenterX(INT centerX) { m_nCenterX = centerX; }

        INT GetCenterY(void) { return m_nCenterY; }
        void SetCenterY(INT centerY) { m_nCenterY = centerY; }

        INT GetStep(void) { return m_nStep; }
        void SetStep(INT step) { m_nStep = step; }

        UINT GetColorNum(void) { return m_uColorNum; }
        void SetColorNum(UINT colorNum) { m_uColorNum = colorNum; }

        INT GetStepCenter(void) { return m_nStepCenter; }
        void SetStepCenter(INT stepCenter) { m_nStepCenter = stepCenter; }

        FLOAT GetAlpha(void) { return m_fAlpha; }
        void SetAlpha(FLOAT alpha) { m_fAlpha = alpha; }


    private:
        UINT m_uType;
        INT m_nAngle;
        INT m_nCenterX;
        INT m_nCenterY;
        INT m_nStep;
        UINT m_uColorNum;
        INT m_nStepCenter;
        FLOAT m_fAlpha;
    };
}
#endif // _GRADATION_H_
