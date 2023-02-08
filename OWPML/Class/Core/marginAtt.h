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
#ifndef  _MARGIN_ATT_H_
#define  _MARGIN_ATT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CColor Declaration 
    class CMarginAttrubute
    {
    public:
        CMarginAttrubute();
        virtual ~CMarginAttrubute();

    public: // read, write function 
        bool SetAttribute(CAttribute* att);
        bool ReadAttribute(CAttribute* att);

    public:
        // Attribute Set/Get Fucntion
        UINT GetLeft(void) { return m_uLeft; }
        void SetLeft(UINT left) { m_uLeft = left; }

        UINT GetRight(void) { return m_uRight; }
        void SetRight(UINT right) { m_uRight = right; }

        UINT GetTop(void) { return m_uTop; }
        void SetTop(UINT top) { m_uTop = top; }

        UINT GetBottom(void) { return m_uBottom; }
        void SetBottom(UINT bottom) { m_uBottom = bottom; }

    public:
        UINT m_uLeft;
        UINT m_uRight;
        UINT m_uTop;
        UINT m_uBottom;
    };
}
#endif // _MARGIN_ATT_H_
