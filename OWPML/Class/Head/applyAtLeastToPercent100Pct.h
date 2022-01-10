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
#ifndef  _APPLYATLEASTTOPERCENT100PCT_H_
#define  _APPLYATLEASTTOPERCENT100PCT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CApplyAtLeastToPercent100Pct Declaration 
    class CApplyAtLeastToPercent100Pct : public CExtObject
    {
    private:
        CApplyAtLeastToPercent100Pct();
    public:
        virtual ~CApplyAtLeastToPercent100Pct();
        static CApplyAtLeastToPercent100Pct* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _APPLYATLEASTTOPERCENT100PCT_H_
