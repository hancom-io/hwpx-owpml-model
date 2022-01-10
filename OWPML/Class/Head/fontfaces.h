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
#ifndef  _FONTFACES_H_
#define  _FONTFACES_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CFontfaceType;

    // CFontfaces Declaration 
    class CFontfaces : public CExtObject
    {
    private:
        CFontfaces();
    public:
        virtual ~CFontfaces();
        static CFontfaces* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CFontfaceType* Setfontface(CFontfaceType* fontface = NULL);
        CFontfaceType* Getfontface(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetItemCnt(void) { return m_uItemCnt; }
        void SetItemCnt(UINT itemCnt) { m_uItemCnt = itemCnt; }


    private:
        UINT m_uItemCnt;
    };
}
#endif // _FONTFACES_H_
