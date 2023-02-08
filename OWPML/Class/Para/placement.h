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
#ifndef  _PLACEMENT_H_
#define  _PLACEMENT_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPlacement Declaration 
    class CFNPlacement : public CExtObject
    {
    private:
        CFNPlacement();
    public:
        virtual ~CFNPlacement();
        static CFNPlacement* Create();

        CFNPlacement* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        FNPLACEMENTTYPE GetPlace(void) { return (FNPLACEMENTTYPE)m_uPlace; }
        void SetPlace(FNPLACEMENTTYPE place) { m_uPlace = (UINT)place; }

        BOOL GetBeneathText(void) { return m_bBeneathText == true ? TRUE : FALSE; }
        void SetBeneathText(BOOL beneathText) { m_bBeneathText = (beneathText == TRUE ? true : false); }


    private:
        UINT m_uPlace;
        bool m_bBeneathText;
    };

    // CPlacement Declaration 
    class CENPlacement : public CExtObject
    {
    private:
        CENPlacement();
    public:
        virtual ~CENPlacement();
        static CENPlacement* Create();

        CENPlacement* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        ENPLACEMENTTYPE GetPlace(void) { return (ENPLACEMENTTYPE)m_uPlace; }
        void SetPlace(ENPLACEMENTTYPE place) { m_uPlace = (UINT)place; }

        BOOL GetBeneathText(void) { return m_bBeneathText == true ? TRUE : FALSE; }
        void SetBeneathText(BOOL beneathText) { m_bBeneathText = (beneathText == TRUE ? true : false); }


    private:
        UINT m_uPlace;
        bool m_bBeneathText;
    };
}
#endif // _PLACEMENT_H_
