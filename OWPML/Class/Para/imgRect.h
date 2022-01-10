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
#ifndef  _IMGRECT_H_
#define  _IMGRECT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CImgRect Declaration 
    class CImgRect : public CExtObject
    {
    private:
        CImgRect();
    public:
        virtual ~CImgRect();
        static CImgRect* Create();

        CImgRect* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPointType* Setpt0(CPointType* pt0 = NULL);
        CPointType* Getpt0(int index = 0);

        CPointType* Setpt1(CPointType* pt1 = NULL);
        CPointType* Getpt1(int index = 0);

        CPointType* Setpt2(CPointType* pt2 = NULL);
        CPointType* Getpt2(int index = 0);

        CPointType* Setpt3(CPointType* pt3 = NULL);
        CPointType* Getpt3(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _IMGRECT_H_
