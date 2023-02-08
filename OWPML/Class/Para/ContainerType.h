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
#ifndef  _CONTAINERTYPE_H_
#define  _CONTAINERTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CContainerType;
    class CLineType;
    class CRectangleType;
    class CEllipseType;
    class CArcType;
    class CPolygonType;
    class CCurveType;
    class CConnectLineType;
    class CPictureType;
    class COLEType;

    // CContainerType Declaration 
    class CContainerType : public CAbstractShapeComponentType
    {
    private:
        CContainerType();
    public:
        virtual ~CContainerType();
        static CContainerType* Create();

        CContainerType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CContainerType* Setcontainer(CContainerType* container = NULL);
        CContainerType* Getcontainer(int index = 0);

        CLineType* Setline(CLineType* line = NULL);
        CLineType* Getline(int index = 0);

        CRectangleType* Setrect(CRectangleType* rect = NULL);
        CRectangleType* Getrect(int index = 0);

        CEllipseType* Setellipse(CEllipseType* ellipse = NULL);
        CEllipseType* Getellipse(int index = 0);

        CArcType* Setarc(CArcType* arc = NULL);
        CArcType* Getarc(int index = 0);

        CPolygonType* Setpolygon(CPolygonType* polygon = NULL);
        CPolygonType* Getpolygon(int index = 0);

        CCurveType* Setcurve(CCurveType* curve = NULL);
        CCurveType* Getcurve(int index = 0);

        CConnectLineType* SetconnectLine(CConnectLineType* connectLine = NULL);
        CConnectLineType* GetconnectLine(int index = 0);

        CPictureType* Setpic(CPictureType* pic = NULL);
        CPictureType* Getpic(int index = 0);

        COLEType* Setole(COLEType* ole = NULL);
        COLEType* Getole(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _CONTAINERTYPE_H_
