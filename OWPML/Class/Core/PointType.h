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
#ifndef  _POINTTYPE_H_
#define  _POINTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPointType Declaration 
    class CPointType : public CExtObject
    {
    private:
        CPointType(UINT id = ID_CORE_PointType);
    public:
        virtual ~CPointType();
        static CPointType* Create();
        static CPointType* CreateArg(UINT id = ID_CORE_PointType);

        CPointType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        INT GetX(void) { return m_nX; }
        void SetX(INT x) { m_nX = x; }

        INT GetY(void) { return m_nY; }
        void SetY(INT y) { m_nY = y; }


    private:
        INT m_nX;
        INT m_nY;
    };
}
#endif // _POINTTYPE_H_
