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
#ifndef  _UNKNOWNOBJECTTYPE_H_
#define  _UNKNOWNOBJECTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CUnknownObjectType Declaration 
    class CUnknownObjectType : public CAbstractDrawingObjectType
    {
    private:
        CUnknownObjectType();
    public:
        virtual ~CUnknownObjectType();
        static CUnknownObjectType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CPointType* Setpt0(CPointType* pt0 = NULL);
        CPointType* Getpt0(int index = 0);

        CPointType* Setpt1(CPointType* pt1 = NULL);
        CPointType* Getpt1(int index = 0);

        CPointType* Setpt2(CPointType* pt2 = NULL);
        CPointType* Getpt2(int index = 0);

        CPointType* Setpt3(CPointType* pt3 = NULL);
        CPointType* Getpt3(int index = 0);

        // Attribute Set/Get Fucntion
        unsigned int GetnativeCtrlid(void) { return m_native_ctrlid; }
        void SetnativeCtrlid(unsigned int native_ctrlid) { m_native_ctrlid = native_ctrlid; }

        // Unknown개체가 생성된 이유 확인
        bool GetUnidentified() { return m_bUnidentified; }
        void SetUnidentified(bool bUnidentified) { m_bUnidentified = bUnidentified; }

    private:
        unsigned int m_native_ctrlid;
        bool m_bUnidentified;            // 현재 버전에서는 처리할 수 없어서 생성된 Unknown개체인지, UnknownObj로 저장이 된 개체로 Unknown개체인지 확인
    };

}
#endif // _PICTURETYPE_H_
