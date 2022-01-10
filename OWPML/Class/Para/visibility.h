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
#ifndef  _VISIBILITY_H_
#define  _VISIBILITY_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CVisibility Declaration 
    class CVisibility : public CExtObject
    {
    private:
        CVisibility();
    public:
        virtual ~CVisibility();
        static CVisibility* Create();

        CVisibility* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        BOOL GetHideFirstHeader(void) { return m_bHideFirstHeader == true ? TRUE : FALSE; }
        void SetHideFirstHeader(BOOL hideFirstHeader) { m_bHideFirstHeader = (hideFirstHeader == TRUE ? true : false); }

        BOOL GetHideFirstFooter(void) { return m_bHideFirstFooter == true ? TRUE : FALSE; }
        void SetHideFirstFooter(BOOL hideFirstFooter) { m_bHideFirstFooter = (hideFirstFooter == TRUE ? true : false); }

        BOOL GetHideFirstMasterPage(void) { return m_bHideFirstMasterPage == true ? TRUE : FALSE; }
        void SetHideFirstMasterPage(BOOL hideFirstMasterPage) { m_bHideFirstMasterPage = (hideFirstMasterPage == TRUE ? true : false); }

        VISIBILITYVALUETYPE GetBorder(void) { return (VISIBILITYVALUETYPE)m_uBorder; }
        void SetBorder(VISIBILITYVALUETYPE border) { m_uBorder = (UINT)border; }

        VISIBILITYVALUETYPE GetFill(void) { return (VISIBILITYVALUETYPE)m_uFill; }
        void SetFill(VISIBILITYVALUETYPE fill) { m_uFill = (UINT)fill; }

        BOOL GetHideFirstPageNum(void) { return m_bHideFirstPageNum == true ? TRUE : FALSE; }
        void SetHideFirstPageNum(BOOL hideFirstPageNum) { m_bHideFirstPageNum = (hideFirstPageNum == TRUE ? true : false); }

        BOOL GetHideFirstEmptyLine(void) { return m_bHideFirstEmptyLine == true ? TRUE : FALSE; }
        void SetHideFirstEmptyLine(BOOL hideFirstEmptyLine) { m_bHideFirstEmptyLine = (hideFirstEmptyLine == TRUE ? true : false); }

        BOOL GetShowLineNumber(void) { return m_bShowLineNumber == true ? TRUE : FALSE; }
        void SetShowLineNumber(BOOL showLineNumber) { m_bShowLineNumber = (showLineNumber == TRUE ? true : false); }

    private:
        bool m_bHideFirstHeader;
        bool m_bHideFirstFooter;
        bool m_bHideFirstMasterPage;
        UINT m_uBorder = 0;
        UINT m_uFill = 0;
        bool m_bHideFirstPageNum;
        bool m_bHideFirstEmptyLine;
        bool m_bShowLineNumber;
    };

    // CLineNumberShaep Declaration 
    class CLineNumberShape : public CExtObject
    {
    private:
        CLineNumberShape();
    public:
        virtual ~CLineNumberShape();
        static CLineNumberShape* Create();

        CLineNumberShape* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        UINT GetRestartType(void) { return m_RestartType; }
        void SetRestartType(UINT restarttype) { m_RestartType = restarttype; }

        UINT GetCountBy(void) { return m_CountBy; }
        void SetCountBy(UINT countby) { m_CountBy = countby; }

        UINT GetDistance(void) { return m_Distance; }
        void SetDistance(UINT distance) { m_Distance = distance; }

        UINT GetStartNumber(void) { return m_StartNumber; }
        void SetStartNumber(UINT startNumber) { m_StartNumber = startNumber; }

    private:
        UINT        m_RestartType;            // 줄 번호 방식 : new-page/new-section/continuous/
        UINT        m_CountBy;                // 줄 번호 표시 간격
        UINT        m_Distance;                // 본문과의 줄 번호 위치
        UINT        m_StartNumber;            // 줄 번호 시작 번호
    };

}
#endif // _VISIBILITY_H_
