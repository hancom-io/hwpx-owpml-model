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
#ifndef  _RUNTYPE_H_
#define  _RUNTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CSectionDefinitionType;
    class CCtrl;
    class CT;
    class CTableType;
    class CPictureType;
    class COLEType;
    class CContainerType;
    class CEquationType;
    class CLineType;
    class CRectangleType;
    class CEllipseType;
    class CArcType;
    class CPolygonType;
    class CCurveType;
    class CConnectLineType;
    class CTextart;
    class CCompose;
    class CDutmal;
    class CAbstractButtonObjectType;
    class CAbstractButtonObjectType;
    class CAbstractButtonObjectType;
    class CComboBoxType;
    class CListBoxType;
    class CEditType;
    class CScrollBarType;
    class CVideoType;
    class CChartType;

    // CPType Declaration 
    class CRunType : public CExtObject
    {
    private:
        CRunType();
    public:
        virtual ~CRunType();
        static CRunType* Create();

        CRunType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CSectionDefinitionType* SetsecPr(CSectionDefinitionType* secPr = NULL);
        CSectionDefinitionType* GetsecPr(int index = 0);

        CCtrl* Setctrl(CCtrl* ctrl = NULL);
        CCtrl* Getctrl(int index = 0);

        CT* Sett(CT* t = NULL);
        CT* Gett(int index = 0);

        CTableType* Settbl(CTableType* tbl = NULL);
        CTableType* Gettbl(int index = 0);

        CPictureType* Setpic(CPictureType* pic = NULL);
        CPictureType* Getpic(int index = 0);

        COLEType* Setole(COLEType* ole = NULL);
        COLEType* Getole(int index = 0);

        CContainerType* Setcontainer(CContainerType* container = NULL);
        CContainerType* Getcontainer(int index = 0);

        CEquationType* Setequation(CEquationType* equation = NULL);
        CEquationType* Getequation(int index = 0);

        CLineType* Setline(CLineType* line = NULL);
        CLineType* Getline(int index = 0);

        CRectangleType* Setrect(CRectangleType* rect = NULL);
        CRectangleType* Getrect(int index = 0);

        CEllipseType* Setellipse(CEllipseType* ellipse = NULL);
        CEllipseType* Getellipse(int index = 0);

        CArcType* Setarc(CArcType* arc = NULL);
        CArcType* Getarc(int index = 0);

        CPolygonType* Setpolygon(CPolygonType* polygon = NULL);
        CPolygonType* Getpolygon(int index = 0);

        CCurveType* Setcurve(CCurveType* curve = NULL);
        CCurveType* Getcurve(int index = 0);

        CConnectLineType* SetconnectLine(CConnectLineType* connectLine = NULL);
        CConnectLineType* GetconnectLine(int index = 0);

        CTextart* Settextart(CTextart* textart = NULL);
        CTextart* Gettextart(int index = 0);

        CCompose* Setcompose(CCompose* compose = NULL);
        CCompose* Getcompose(int index = 0);

        CDutmal* Setdutmal(CDutmal* dutmal = NULL);
        CDutmal* Getdutmal(int index = 0);

        CAbstractButtonObjectType* Setbtn(CAbstractButtonObjectType* btn = NULL);
        CAbstractButtonObjectType* Getbtn(int index = 0);

        CAbstractButtonObjectType* SetradioBtn(CAbstractButtonObjectType* radioBtn = NULL);
        CAbstractButtonObjectType* GetradioBtn(int index = 0);

        CAbstractButtonObjectType* SetcheckBtn(CAbstractButtonObjectType* checkBtn = NULL);
        CAbstractButtonObjectType* GetcheckBtn(int index = 0);

        CComboBoxType* SetcomboBox(CComboBoxType* comboBox = NULL);
        CComboBoxType* GetcomboBox(int index = 0);

        CListBoxType* SetlistBox(CListBoxType* listBox = NULL);
        CListBoxType* GetlistBox(int index = 0);

        CEditType* Setedit(CEditType* edit = NULL);
        CEditType* Getedit(int index = 0);

        CScrollBarType* SetscrollBar(CScrollBarType* scrollBar = NULL);
        CScrollBarType* GetscrollBar(int index = 0);

        CVideoType* Setvideo(CVideoType* pvideo = NULL);
        CVideoType* Getvideo(int index = 0);

        CMarkpenBegin* SetmarkpenBegin(CMarkpenBegin* markpenBegin = NULL);
        CMarkpenBegin* GetmarkpenBegin(int index = 0);

        CMarkpenEnd* SetmarkpenEnd(CMarkpenEnd* markpenEnd = NULL);
        CMarkpenEnd* GetmarkpenEnd(int index = 0);

        CChartType* Setchart(CChartType* pchart = NULL);
        CChartType* Getchart(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetCharPrIDRef(void) { return m_uCharPrIDRef; }
        void SetCharPrIDRef(UINT charPrIDRef) { m_uCharPrIDRef = charPrIDRef; }

        UINT GetTrackchageID(void) { return m_charTCId; }
        void SetTrackchageID(UINT tcid) { m_charTCId = tcid; }

    private:
        UINT m_uCharPrIDRef;
        UINT m_charTCId;
    };
}
#endif // _RUNTYPE_H_
