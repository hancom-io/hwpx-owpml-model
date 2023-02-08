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
#ifndef  _SLASHTYPE_H_
#define  _SLASHTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CSlashType Declaration 
    class CSlashType : public CExtObject
    {
    private:
        CSlashType(UINT id);
    public:
        virtual ~CSlashType();
        static CSlashType* Create();
        static CSlashType* CreateArg(UINT id);

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        SLASHTYPE GetType(void) { return (SLASHTYPE)m_uType; }
        void SetType(SLASHTYPE type) { m_uType = (UINT)type; }

        UINT GetCrooked(void) { return m_uCrooked; }
        void SetCrooked(UINT Crooked) { m_uCrooked = Crooked; }

        BOOL GetIsCounter(void) { return m_bIsCounter == true ? TRUE : FALSE; }
        void SetIsCounter(BOOL isCounter) { m_bIsCounter = (isCounter == TRUE ? true : false); }


    private:
        UINT m_uType;
        UINT m_uCrooked;
        bool m_bIsCounter;
    };
}
#endif // _SLASHTYPE_H_
