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
#ifndef  _HEADING_H_
#define  _HEADING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CHeading Declaration 
    class CHeading : public CExtObject
    {
    private:
        CHeading();
    public:
        virtual ~CHeading();
        static CHeading* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        HEADINGTYPE GetType(void) { return (HEADINGTYPE)m_uType; }
        void SetType(HEADINGTYPE type) { m_uType = (UINT)type; }

        UINT GetIdRef(void) { return m_uIdRef; }
        void SetIdRef(UINT idRef) { m_uIdRef = idRef; }

        UINT GetLevel(void) { return m_uLevel; }
        void SetLevel(UINT level) { m_uLevel = level; }


    private:
        UINT m_uType;
        UINT m_uIdRef;
        UINT m_uLevel;
    };
}
#endif // _HEADING_H_
