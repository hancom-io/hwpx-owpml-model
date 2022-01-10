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
#ifndef  _IMGCLIP_H_
#define  _IMGCLIP_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CImgClip Declaration 
    class CImgClip : public CExtObject
    {
    private:
        CImgClip();
    public:
        virtual ~CImgClip();
        static CImgClip* Create();

        CImgClip* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetLeft(void) { return m_nLeft; }
        void SetLeft(INT left) { m_nLeft = left; }

        INT GetRight(void) { return m_nRight; }
        void SetRight(INT right) { m_nRight = right; }

        INT GetTop(void) { return m_nTop; }
        void SetTop(INT top) { m_nTop = top; }

        INT GetBottom(void) { return m_nBottom; }
        void SetBottom(INT bottom) { m_nBottom = bottom; }


    private:
        INT m_nLeft;
        INT m_nRight;
        INT m_nTop;
        INT m_nBottom;
    };
}
#endif // _IMGCLIP_H_
