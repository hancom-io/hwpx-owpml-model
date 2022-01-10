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
#ifndef  _MARGIN_H_
#define  _MARGIN_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CHWPValue;

    // CMargin Declaration 
    class CMargin : public CExtObject
    {
    private:
        CMargin();
    public:
        virtual ~CMargin();
        static CMargin* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CHWPValue* Setintent(CHWPValue* intent = NULL);
        CHWPValue* Getintent(int index = 0);

        CHWPValue* Setleft(CHWPValue* left = NULL);
        CHWPValue* Getleft(int index = 0);

        CHWPValue* Setright(CHWPValue* right = NULL);
        CHWPValue* Getright(int index = 0);

        CHWPValue* Setprev(CHWPValue* prev = NULL);
        CHWPValue* Getprev(int index = 0);

        CHWPValue* Setnext(CHWPValue* next = NULL);
        CHWPValue* Getnext(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _MARGIN_H_
