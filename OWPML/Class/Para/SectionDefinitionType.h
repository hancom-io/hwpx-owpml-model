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
#ifndef  _SECTIONDEFINITIONTYPE_H_
#define  _SECTIONDEFINITIONTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CStartNum;
    class CGrid;
    class CVisibility;
    class CLineNumberShape;
    class CPagePr;
    class CFootNoteShapeType;
    class CEndNoteShapeType;
    class CPageBorderFill;
    class CMasterPage;
    class CPresentation;

    // CSectionDefinitionType Declaration 
    class CSectionDefinitionType : public CExtObject
    {
    private:
        CSectionDefinitionType();
    public:
        virtual ~CSectionDefinitionType();
        static CSectionDefinitionType* Create();

        CSectionDefinitionType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CStartNum* SetstartNum(CStartNum* startNum = NULL);
        CStartNum* GetstartNum(int index = 0);

        CGrid* Setgrid(CGrid* grid = NULL);
        CGrid* Getgrid(int index = 0);

        CVisibility* Setvisibility(CVisibility* visibility = NULL);
        CVisibility* Getvisibility(int index = 0);

        CLineNumberShape* SetlineNumberShape(CLineNumberShape* plinenumbershape = NULL);
        CLineNumberShape* GetlineNumberShape(int index = 0);

        CPagePr* SetpagePr(CPagePr* pagePr = NULL);
        CPagePr* GetpagePr(int index = 0);

        CFootNoteShapeType* SetfootNotePr(CFootNoteShapeType* footNotePr = NULL);
        CFootNoteShapeType* GetfootNotePr(int index = 0);

        CEndNoteShapeType* SetendNotePr(CEndNoteShapeType* endNotePr = NULL);
        CEndNoteShapeType* GetendNotePr(int index = 0);

        CPageBorderFill* SetpageBorderFill(CPageBorderFill* pageBorderFill = NULL);
        CPageBorderFill* GetpageBorderFill(int index = 0);

        CMasterPage* SetmasterPage(CMasterPage* masterPage = NULL);
        CMasterPage* GetmasterPage(int index = 0);

        CPresentation* Setpresentation(CPresentation* ppresentation = NULL);
        CPresentation* Getpresentation(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetId(void) { return m_strId.c_str(); }
        void SetId(LPCWSTR id) { m_strId = id; }

        SECTEXTDIRECTTYPE GetTextDirection(void) { return (SECTEXTDIRECTTYPE)m_uTextDirection; }
        void SetTextDirection(SECTEXTDIRECTTYPE textDirection) { m_uTextDirection = (UINT)textDirection; }

        INT GetSpaceColumns(void) { return m_nSpaceColumns; }
        void SetSpaceColumns(INT spaceColumns) { m_nSpaceColumns = spaceColumns; }

        INT GetTabStop(void) { return m_nTabStop; }
        void SetTabStop(INT tabStop) { m_nTabStop = tabStop; }

        INT GetTabStopVal(void) { return m_nTabStopVal; }
        void SetTabStopVal(INT tabStopVal) { m_nTabStopVal = tabStopVal; }

        UINTVALUETYPE GetTabStopUnit(void) { return (UINTVALUETYPE)m_nTabStopUnit; }
        void SetTabStopUnit(UINTVALUETYPE tabStopUnit) { m_nTabStopUnit = (UINT)tabStopUnit; }


        UINT GetOutlineShapeIDRef(void) { return m_uOutlineShapeIDRef; }
        void SetOutlineShapeIDRef(UINT outlineShapeIDRef) { m_uOutlineShapeIDRef = outlineShapeIDRef; }

        UINT GetMemoShapeIDRef(void) { return m_uMemoShapeIDRef; }
        void SetMemoShapeIDRef(UINT memoShapeIDRef) { m_uMemoShapeIDRef = memoShapeIDRef; }

        BOOL GetTextVerticalWidthHead(void) { return m_bTextVerticalWidthHead == true ? TRUE : FALSE; }
        void SetTextVerticalWidthHead(BOOL textVerticalWidthHead) { m_bTextVerticalWidthHead = (textVerticalWidthHead == TRUE ? true : false); }

        UINT GetMasterPageCnt(void) { return m_uMasterPageCnt; }
        void SetMasterPageCnt(UINT masterPageCnt) { m_uMasterPageCnt = masterPageCnt; }


    private:
        hncstd::wstring m_strId;
        UINT m_uTextDirection;
        INT m_nSpaceColumns;
        INT m_nTabStop;  // 구버전 (단위랑 쉬프트 연산되어 있어 보기 어렵다)
        INT m_nTabStopVal; // 1.31 버전 이후에는 m_nTabStop를 안쓴다.
        UINT m_nTabStopUnit;
        UINT m_uOutlineShapeIDRef;
        UINT m_uMemoShapeIDRef;
        bool m_bTextVerticalWidthHead;
        UINT m_uMasterPageCnt;
    };
}
#endif // _SECTIONDEFINITIONTYPE_H_
