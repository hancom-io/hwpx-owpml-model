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
#ifndef  _GRAPHTYPE_H_
#define  _GRAPHTYPE_H_

namespace OWPML {
#ifdef _GRAPH
    class CAttribute;
    class CSerializer;

    // CGraphType Declaration 
    class CGraphType : public CAbstractShapeComponentType
    {
    private:
        CGraphType();
    public:
        virtual ~CGraphType();
        static CGraphType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        LPCWSTR GetPropJSON(void) { return m_strJSON; }
        void SetPropJSON(LPCWSTR strJSON) { m_strJSON = strJSON; }

        LPCWSTR GetImageID(void) { return m_strImageID; }
        void SetImageID(LPCWSTR imageid) { m_strImageID = imageid; }

    private:
        hncstd::wstring        m_strJSON;
        hncstd::wstring        m_strImageID;
    };
#endif // _GRAPH
}

#endif // _GRAPHTYPE_H_
