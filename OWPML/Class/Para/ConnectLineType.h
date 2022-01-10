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
#ifndef  _CONNECTLINETYPE_H_
#define  _CONNECTLINETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CConnectPointType;
    class CConnectControlPoints;

    // CConnectLineType Declaration 
    class CConnectLineType : public CAbstractDrawingObjectType
    {
    private:
        CConnectLineType();
    public:
        virtual ~CConnectLineType();
        static CConnectLineType* Create();

        CConnectLineType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CConnectPointType* SetstartPt(CConnectPointType* startPt = NULL);
        CConnectPointType* GetstartPt(int index = 0);

        CConnectPointType* SetendPt(CConnectPointType* endPt = NULL);
        CConnectPointType* GetendPt(int index = 0);

        CConnectControlPoints* SetcontrolPts(CConnectControlPoints* pcontrolPts = NULL);
        CConnectControlPoints* GetcontrolPts(int index = 0);

        // Attribute Set/Get Fucntion
        CONNECTLINETYPE GetType(void) { return (CONNECTLINETYPE)m_uType; }
        void SetType(CONNECTLINETYPE type) { m_uType = (UINT)type; }

    private:
        UINT m_uType;
    };
}
#endif // _CONNECTLINETYPE_H_
