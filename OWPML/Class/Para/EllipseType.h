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
#ifndef  _ELLIPSETYPE_H_
#define  _ELLIPSETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CEllipseType Declaration 
    class CEllipseType : public CAbstractDrawingObjectType
    {
    private:
        CEllipseType();
    public:
        virtual ~CEllipseType();
        static CEllipseType* Create();

        CEllipseType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPointType* Setcenter(CPointType* center = NULL);
        CPointType* Getcenter(int index = 0);

        CPointType* Setax1(CPointType* ax1 = NULL);
        CPointType* Getax1(int index = 0);

        CPointType* Setax2(CPointType* ax2 = NULL);
        CPointType* Getax2(int index = 0);

        CPointType* Setstart1(CPointType* start1 = NULL);
        CPointType* Getstart1(int index = 0);

        CPointType* Setstart2(CPointType* start2 = NULL);
        CPointType* Getstart2(int index = 0);

        CPointType* Setend1(CPointType* end1 = NULL);
        CPointType* Getend1(int index = 0);

        CPointType* Setend2(CPointType* end2 = NULL);
        CPointType* Getend2(int index = 0);

        // Attribute Set/Get Fucntion
        BOOL GetIntervalDirty(void) { return m_bIntervalDirty == true ? TRUE : FALSE; }
        void SetIntervalDirty(BOOL intervalDirty) { m_bIntervalDirty = (intervalDirty == TRUE ? true : false); }

        BOOL GetHasArcPr(void) { return m_bHasArcPr == true ? TRUE : FALSE; }
        void SetHasArcPr(BOOL hasArcPr) { m_bHasArcPr = (hasArcPr == TRUE ? true : false); }

        ARCTYPE GetArcType(void) { return (ARCTYPE)m_uArcType; }
        void SetArcType(ARCTYPE arcType) { m_uArcType = (UINT)arcType; }


    private:
        bool m_bIntervalDirty;
        bool m_bHasArcPr;
        UINT m_uArcType;
    };
}
#endif // _ELLIPSETYPE_H_
