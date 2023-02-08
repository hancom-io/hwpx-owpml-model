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
#ifndef  _HWPAPPLICATIONSETTING_H_
#define  _HWPAPPLICATIONSETTING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CConfigItemSet;
    class CDocDistribute;

    // CHWPApplicationSetting Declaration 
    class CHWPApplicationSetting : public CNamedObject
    {
    public:
        CHWPApplicationSetting();
    public:
        virtual ~CHWPApplicationSetting();
        static CHWPApplicationSetting* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CCaretPosition* SetCaretPosition(CCaretPosition* CaretPosition = NULL);
        CCaretPosition* GetCaretPosition(int index = 0);

        CConfigItemSet* SetConfigItemSet(CConfigItemSet* pconfigitemset = NULL);
        CConfigItemSet* GetConfigItemSet(int index = 0);

        CDocDistribute* SetDocDistribute(CDocDistribute* distrubute = NULL);
        CDocDistribute* GetDocDistribute(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _HWPAPPLICATIONSETTING_H_
