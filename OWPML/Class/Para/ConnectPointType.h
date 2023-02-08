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
#ifndef  _CONNECTPOINTTYPE_H_
#define  _CONNECTPOINTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CConnectPointType Declaration 
    class CConnectPointType : public CExtObject
    {
    private:
        CConnectPointType(UINT id = ID_PARA_ConnectPointType);
    public:
        virtual ~CConnectPointType();
        static CConnectPointType* Create();
        static CConnectPointType* CreateArg(UINT id = ID_PARA_ConnectPointType);

        CConnectPointType* Clone();

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

        UINT GetSubjectIDRef(void) { return m_uSubjectIDRef; }
        void SetSubjectIDRef(UINT subjectIDRef) { m_uSubjectIDRef = subjectIDRef; }

        UINT GetSubjectIdx(void) { return m_uSubjectIdx; }
        void SetSubjectIdx(UINT subjectIdx) { m_uSubjectIdx = subjectIdx; }


    private:
        INT m_nX;
        INT m_nY;

        UINT m_uSubjectIDRef;
        UINT m_uSubjectIdx;
    };


    // CConnectControlPointType Declaration 
    class CConnectControlPointType : public CExtObject
    {
    private:
        CConnectControlPointType(UINT id = ID_PARA_ConnectControlPointType);
    public:
        virtual ~CConnectControlPointType();
        static CConnectControlPointType* Create();

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

        UINT GetType(void) { return m_uType; }
        void SetType(UINT type) { m_uType = type; }

    private:
        INT m_nX;
        INT m_nY;
        UINT m_uType;
    };

    // CConnectControlPoints Declaration 
    class CConnectControlPoints : public CExtObject
    {
    private:
        CConnectControlPoints(UINT id = ID_PARA_ConnectControlPoints);
    public:
        virtual ~CConnectControlPoints();
        static CConnectControlPoints* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CConnectControlPointType* SetcontrolPt(CConnectControlPointType* pcontrolPt = NULL);
        CConnectControlPointType* GetcontrolPt(int index = 0);
    };



}
#endif // _CONNECTPOINTTYPE_H_
