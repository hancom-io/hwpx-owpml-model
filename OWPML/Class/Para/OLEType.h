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
#ifndef  _OLETYPE_H_
#define  _OLETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // COLEType Declaration 
    class COLEType : public CAbstractShapeComponentType
    {
    private:
        COLEType();
    public:
        virtual ~COLEType();
        static COLEType* Create();

        COLEType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPointType* Setextent(CPointType* extent = NULL);
        CPointType* Getextent(int index = 0);

        CLineShapeType* SetlineShape(CLineShapeType* lineShape = NULL);
        CLineShapeType* GetlineShape(int index = 0);

        // Attribute Set/Get Fucntion
        OLEOBJECTTYPE GetObjectType(void) { return (OLEOBJECTTYPE)m_uObjectType; }
        void SetObjectType(OLEOBJECTTYPE objectType) { m_uObjectType = (UINT)objectType; }

        LPCWSTR GetBinaryItemIDRef(void) { return m_strBinaryItemIDRef.c_str(); }
        void SetBinaryItemIDRef(LPCWSTR binaryItemIDRef) { m_strBinaryItemIDRef = binaryItemIDRef; }

        BOOL GetHasMoniker(void) { return m_bHasMoniker == true ? TRUE : FALSE; }
        void SetHasMoniker(BOOL hasMoniker) { m_bHasMoniker = (hasMoniker == TRUE ? true : false); }

        OLEDRAWASPECTTYPE GetDrawAspect(void) { return (OLEDRAWASPECTTYPE)m_uDrawAspect; }
        void SetDrawAspect(OLEDRAWASPECTTYPE drawAspect) { m_uDrawAspect = (UINT)drawAspect; }

        UINT GetEqBaseLine(void) { return m_uEqBaseLine; }
        void SetEqBaseLine(UINT eqBaseLine) { m_uEqBaseLine = eqBaseLine; }


    private:
        UINT m_uObjectType = 0;
        hncstd::wstring m_strBinaryItemIDRef;
        bool m_bHasMoniker;
        UINT m_uDrawAspect = 0;
        UINT m_uEqBaseLine;
    };
}
#endif // _OLETYPE_H_
