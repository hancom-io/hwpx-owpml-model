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
#ifndef  _MATRIXTYPE_H_
#define  _MATRIXTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CMatrixType Declaration 
    class CMatrixType : public CExtObject
    {
    private:
        CMatrixType(UINT id = ID_CORE_MatrixType);
    public:
        virtual ~CMatrixType();
        static CMatrixType* Create();
        static CMatrixType* CreateArg(UINT id = ID_CORE_MatrixType);

        CMatrixType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        FLOAT GetE1(void) { return m_fE1; }
        void SetE1(FLOAT e1) { m_fE1 = e1; }

        FLOAT GetE2(void) { return m_fE2; }
        void SetE2(FLOAT e2) { m_fE2 = e2; }

        FLOAT GetE3(void) { return m_fE3; }
        void SetE3(FLOAT e3) { m_fE3 = e3; }

        FLOAT GetE4(void) { return m_fE4; }
        void SetE4(FLOAT e4) { m_fE4 = e4; }

        FLOAT GetE5(void) { return m_fE5; }
        void SetE5(FLOAT e5) { m_fE5 = e5; }

        FLOAT GetE6(void) { return m_fE6; }
        void SetE6(FLOAT e6) { m_fE6 = e6; }


    private:
        FLOAT m_fE1;
        FLOAT m_fE2;
        FLOAT m_fE3;
        FLOAT m_fE4;
        FLOAT m_fE5;
        FLOAT m_fE6;
    };
}
#endif // _MATRIXTYPE_H_
