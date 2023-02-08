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
#ifndef  _BORDERFILLTYPE_H_
#define  _BORDERFILLTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CSlashType;
    class CBorderType;
    class CFillBrushType;

    // CBorderFillType Declaration 
    class CBorderFillType : public CExtObject
    {
    private:
        CBorderFillType();
    public:
        virtual ~CBorderFillType();
        static CBorderFillType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CSlashType* Setslash(CSlashType* slash = NULL);
        CSlashType* Getslash(int index = 0);

        CSlashType* SetbackSlash(CSlashType* backSlash = NULL);
        CSlashType* GetbackSlash(int index = 0);

        CBorderType* SetleftBorder(CBorderType* leftBorder = NULL);
        CBorderType* GetleftBorder(int index = 0);

        CBorderType* SetrightBorder(CBorderType* rightBorder = NULL);
        CBorderType* GetrightBorder(int index = 0);

        CBorderType* SettopBorder(CBorderType* topBorder = NULL);
        CBorderType* GettopBorder(int index = 0);

        CBorderType* SetbottomBorder(CBorderType* bottomBorder = NULL);
        CBorderType* GetbottomBorder(int index = 0);

        CBorderType* Setdiagonal(CBorderType* diagonal = NULL);
        CBorderType* Getdiagonal(int index = 0);

        CFillBrushType* SetfillBrush(CFillBrushType* fillBrush = NULL);
        CFillBrushType* GetfillBrush(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        BOOL GetThreeD(void) { return m_bThreeD == true ? TRUE : FALSE; }
        void SetThreeD(BOOL threeD) { m_bThreeD = (threeD == TRUE ? true : false); }

        BOOL GetShadow(void) { return m_bShadow == true ? TRUE : FALSE; }
        void SetShadow(BOOL shadow) { m_bShadow = (shadow == TRUE ? true : false); }

        CENTERLINETYPE GetCenterLine(void) { return (CENTERLINETYPE)m_uCenterLine; }
        void SetCenterLine(CENTERLINETYPE centerLine) { m_uCenterLine = (UINT)centerLine; }

        BOOL GetBreakCellSeparateLine(void) { return m_bBreakCellSeparateLine == true ? TRUE : FALSE; }
        void SetBreakCellSeparateLine(BOOL breakCellSeparateLine) { m_bBreakCellSeparateLine = (breakCellSeparateLine == TRUE ? true : false); }


    private:
        UINT m_uId;
        bool m_bThreeD;
        bool m_bShadow;
        UINT m_uCenterLine;
        bool m_bBreakCellSeparateLine;
    };
}
#endif // _BORDERFILLTYPE_H_
