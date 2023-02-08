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
#ifndef  _LINETYPE_H_
#define  _LINETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CLineType Declaration 
    class CLineType : public CAbstractDrawingObjectType
    {
    private:
        CLineType();
    public:
        virtual ~CLineType();
        static CLineType* Create();

        CLineType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPointType* SetstartPt(CPointType* startPt = NULL);
        CPointType* GetstartPt(int index = 0);

        CPointType* SetendPt(CPointType* endPt = NULL);
        CPointType* GetendPt(int index = 0);

        // Attribute Set/Get Fucntion
        BOOL GetReverseHV(void) { return m_isReverseHV == true ? TRUE : FALSE; }
        void SetReverseHV(BOOL reverse) { m_isReverseHV = (reverse == TRUE ? true : false); }

    private:
        bool m_isReverseHV;
    };
}
#endif // _LINETYPE_H_
