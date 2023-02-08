﻿/*
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
#ifndef  _ALIGN_H_
#define  _ALIGN_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CAlign Declaration 
    class CAlign : public CExtObject
    {
    private:
        CAlign();
    public:
        virtual ~CAlign();
        static CAlign* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        ALIGNHORZ GetHorizontal(void) { return (ALIGNHORZ)m_uHorizontal; }
        void SetHorizontal(ALIGNHORZ horizontal) { m_uHorizontal = (UINT)horizontal; }

        ALIGNVERT GetVertical(void) { return (ALIGNVERT)m_uVertical; }
        void SetVertical(ALIGNVERT vertical) { m_uVertical = (UINT)vertical; }


    private:
        UINT m_uHorizontal;
        UINT m_uVertical;
    };
}
#endif // _ALIGN_H_
