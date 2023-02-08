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
#ifndef  _ROTATIONINFO_H_
#define  _ROTATIONINFO_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CRotationInfo Declaration 
    class CRotationInfo : public CExtObject
    {
    private:
        CRotationInfo();
    public:
        virtual ~CRotationInfo();
        static CRotationInfo* Create();

        CRotationInfo* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetAngle(void) { return m_nAngle; }
        void SetAngle(INT angle) { m_nAngle = angle; }

        UINT GetCenterX(void) { return m_uCenterX; }
        void SetCenterX(UINT centerX) { m_uCenterX = centerX; }

        UINT GetCenterY(void) { return m_uCenterY; }
        void SetCenterY(UINT centerY) { m_uCenterY = centerY; }

        BOOL GetRotateImage(void) { return m_bRotateImage == true ? TRUE : FALSE; }
        void SetRotateImage(BOOL bRotateImage) { m_bRotateImage = (bRotateImage == TRUE ? true : false); }

    private:
        INT m_nAngle;
        UINT m_uCenterX;
        UINT m_uCenterY;
        bool m_bRotateImage;
    };
}
#endif // _ROTATIONINFO_H_
