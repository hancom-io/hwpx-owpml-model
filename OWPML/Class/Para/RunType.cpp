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

#include "stdafx.h"
#include "Object.h"
#include "Attribute.h"
#include "Util.h"
#include "Serialize.h"
#include "RunType.h"

namespace OWPML {

    CRunType* CRunType::Create()
    {
        return new CRunType();
    }

    CRunType* CRunType::Clone()
    {
        CRunType* clone = new CRunType();

        clone->SetCharPrIDRef(this->m_uCharPrIDRef);
        clone->SetTrackchageID(this->m_charTCId);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }


    CRunType::CRunType() : CExtObject(ID_PARA_RunType), m_uCharPrIDRef((UINT)-1), m_charTCId(0)
    {
    }

    CRunType::~CRunType()
    {
    }

    void CRunType::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CRunType, secPr)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, ctrl)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, t)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, tbl)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, pic)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, ole)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, container)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, equation)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, line)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, rect)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, ellipse)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, arc)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, polygon)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, curve)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, connectLine)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, textart)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, compose)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, dutmal)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, btn)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, radioBtn)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, checkBtn)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, comboBox)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, listBox)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, edit)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, scrollBar)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, video)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, markpenBegin)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, markpenEnd)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, chart)
            OWPML_PARALIST_REDIRECT_FUNC(CRunType, unknownObj)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CRunType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(secPr, CSectionDefinitionType, ID_PARA_SectionDefinitionType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(ctrl, CCtrl, ID_PARA_Ctrl)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(t, CT, ID_PARA_T)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(tbl, CTableType, ID_PARA_TableType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pic, CPictureType, ID_PARA_PictureType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(ole, COLEType, ID_PARA_OLEType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(container, CContainerType, ID_PARA_ContainerType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(equation, CEquationType, ID_PARA_EquationType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(line, CLineType, ID_PARA_LineType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(rect, CRectangleType, ID_PARA_RectangleType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(ellipse, CEllipseType, ID_PARA_EllipseType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(arc, CArcType, ID_PARA_ArcType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(polygon, CPolygonType, ID_PARA_PolygonType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(curve, CCurveType, ID_PARA_CurveType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(connectLine, CConnectLineType, ID_PARA_ConnectLineType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(textart, CTextart, ID_PARA_Textart)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(compose, CCompose, ID_PARA_Compose)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(dutmal, CDutmal, ID_PARA_Dutmal)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(btn, CAbstractButtonObjectType, ID_PARA_AbstractButtonObjectType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(radioBtn, CAbstractButtonObjectType, ID_PARA_AbstractRadioButtonObjectType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(checkBtn, CAbstractButtonObjectType, ID_PARA_AbstractCheckButtonObjectType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(comboBox, CComboBoxType, ID_PARA_ComboBoxType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(listBox, CListBoxType, ID_PARA_ListBoxType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(edit, CEditType, ID_PARA_EditType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(scrollBar, CScrollBarType, ID_PARA_ScrollBarType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(video, CVideoType, ID_PARA_VideoType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(markpenBegin, CMarkpenBegin, ID_PARA_MarkpenBegin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(markpenEnd, CMarkpenEnd, ID_PARA_MarkpenEnd)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(chart, CChartType, ID_PARA_ChartType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(unknownObj, CUnknownObjectType, ID_PARA_UnknownObject_ID)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CRunType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        if (m_charTCId)
            Util::CXMLAttConverter::SetAttribute(att, L"charTcId", m_charTCId);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRunType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charPrIDRef", m_uCharPrIDRef);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charTcId", m_charTCId);
        if (!bres)
            bres &= Util::CXMLAttConverter::GetAttribute(att, L"paraTcId", m_charTCId);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CSectionDefinitionType* CRunType::SetsecPr(CSectionDefinitionType* psecPr)
    {
        CSectionDefinitionType* secPr = psecPr;
        if (secPr == NULL) {
            secPr = CSectionDefinitionType::Create();
        }
        SetObject((CObject*)secPr);

        return secPr;
    }

    CSectionDefinitionType* CRunType::GetsecPr(int index)
    {
        return static_cast<CSectionDefinitionType*>(GetObjectByID(ID_PARA_SectionDefinitionType, index));
    }

    CCtrl* CRunType::Setctrl(CCtrl* pctrl)
    {
        CCtrl* ctrl = pctrl;
        if (ctrl == NULL) {
            ctrl = CCtrl::Create();
        }
        SetObject((CObject*)ctrl);

        return ctrl;
    }

    CCtrl* CRunType::Getctrl(int index)
    {
        return static_cast<CCtrl*>(GetObjectByID(ID_PARA_Ctrl, index));
    }

    CT* CRunType::Sett(CT* pt)
    {
        CT* t = pt;
        if (t == NULL) {
            t = CT::Create();
        }
        SetObject((CObject*)t);

        return t;
    }

    CT* CRunType::Gett(int index)
    {
        return static_cast<CT*>(GetObjectByID(ID_PARA_T, index));
    }

    CTableType* CRunType::Settbl(CTableType* ptbl)
    {
        CTableType* tbl = ptbl;
        if (tbl == NULL) {
            tbl = CTableType::Create();
        }
        SetObject((CObject*)tbl);

        return tbl;
    }

    CTableType* CRunType::Gettbl(int index)
    {
        return static_cast<CTableType*>(GetObjectByID(ID_PARA_TableType, index));
    }

    CPictureType* CRunType::Setpic(CPictureType* ppic)
    {
        CPictureType* pic = ppic;
        if (pic == NULL) {
            pic = CPictureType::Create();
        }
        SetObject((CObject*)pic);

        return pic;
    }

    CPictureType* CRunType::Getpic(int index)
    {
        return static_cast<CPictureType*>(GetObjectByID(ID_PARA_PictureType, index));
    }

    COLEType* CRunType::Setole(COLEType* pole)
    {
        COLEType* ole = pole;
        if (ole == NULL) {
            ole = COLEType::Create();
        }
        SetObject((CObject*)ole);

        return ole;
    }

    COLEType* CRunType::Getole(int index)
    {
        return static_cast<COLEType*>(GetObjectByID(ID_PARA_OLEType, index));
    }

    CContainerType* CRunType::Setcontainer(CContainerType* pcontainer)
    {
        CContainerType* container = pcontainer;
        if (container == NULL) {
            container = CContainerType::Create();
        }
        SetObject((CObject*)container);

        return container;
    }

    CContainerType* CRunType::Getcontainer(int index)
    {
        return static_cast<CContainerType*>(GetObjectByID(ID_PARA_ContainerType, index));
    }

    CEquationType* CRunType::Setequation(CEquationType* pequation)
    {
        CEquationType* equation = pequation;
        if (equation == NULL) {
            equation = CEquationType::Create();
        }
        SetObject((CObject*)equation);

        return equation;
    }

    CEquationType* CRunType::Getequation(int index)
    {
        return static_cast<CEquationType*>(GetObjectByID(ID_PARA_EquationType, index));
    }

    CLineType* CRunType::Setline(CLineType* pline)
    {
        CLineType* line = pline;
        if (line == NULL) {
            line = CLineType::Create();
        }
        SetObject((CObject*)line);

        return line;
    }

    CLineType* CRunType::Getline(int index)
    {
        return static_cast<CLineType*>(GetObjectByID(ID_PARA_LineType, index));
    }

    CRectangleType* CRunType::Setrect(CRectangleType* prect)
    {
        CRectangleType* rect = prect;
        if (rect == NULL) {
            rect = CRectangleType::Create();
        }
        SetObject((CObject*)rect);

        return rect;
    }

    CRectangleType* CRunType::Getrect(int index)
    {
        return static_cast<CRectangleType*>(GetObjectByID(ID_PARA_RectangleType, index));
    }

    CEllipseType* CRunType::Setellipse(CEllipseType* pellipse)
    {
        CEllipseType* ellipse = pellipse;
        if (ellipse == NULL) {
            ellipse = CEllipseType::Create();
        }
        SetObject((CObject*)ellipse);

        return ellipse;
    }

    CEllipseType* CRunType::Getellipse(int index)
    {
        return static_cast<CEllipseType*>(GetObjectByID(ID_PARA_EllipseType, index));
    }

    CArcType* CRunType::Setarc(CArcType* parc)
    {
        CArcType* arc = parc;
        if (arc == NULL) {
            arc = CArcType::Create();
        }
        SetObject((CObject*)arc);

        return arc;
    }

    CArcType* CRunType::Getarc(int index)
    {
        return static_cast<CArcType*>(GetObjectByID(ID_PARA_ArcType, index));
    }

    CPolygonType* CRunType::Setpolygon(CPolygonType* ppolygon)
    {
        CPolygonType* polygon = ppolygon;
        if (polygon == NULL) {
            polygon = CPolygonType::Create();
        }
        SetObject((CObject*)polygon);

        return polygon;
    }

    CPolygonType* CRunType::Getpolygon(int index)
    {
        return static_cast<CPolygonType*>(GetObjectByID(ID_PARA_PolygonType, index));
    }

    CCurveType* CRunType::Setcurve(CCurveType* pcurve)
    {
        CCurveType* curve = pcurve;
        if (curve == NULL) {
            curve = CCurveType::Create();
        }
        SetObject((CObject*)curve);

        return curve;
    }

    CCurveType* CRunType::Getcurve(int index)
    {
        return static_cast<CCurveType*>(GetObjectByID(ID_PARA_CurveType, index));
    }

    CConnectLineType* CRunType::SetconnectLine(CConnectLineType* pconnectLine)
    {
        CConnectLineType* connectLine = pconnectLine;
        if (connectLine == NULL) {
            connectLine = CConnectLineType::Create();
        }
        SetObject((CObject*)connectLine);

        return connectLine;
    }

    CConnectLineType* CRunType::GetconnectLine(int index)
    {
        return static_cast<CConnectLineType*>(GetObjectByID(ID_PARA_ConnectLineType, index));
    }

    CTextart* CRunType::Settextart(CTextart* ptextart)
    {
        CTextart* textart = ptextart;
        if (textart == NULL) {
            textart = CTextart::Create();
        }
        SetObject((CObject*)textart);

        return textart;
    }

    CTextart* CRunType::Gettextart(int index)
    {
        return static_cast<CTextart*>(GetObjectByID(ID_PARA_Textart, index));
    }

    CCompose* CRunType::Setcompose(CCompose* pcompose)
    {
        CCompose* compose = pcompose;
        if (compose == NULL) {
            compose = CCompose::Create();
        }
        SetObject((CObject*)compose);

        return compose;
    }

    CCompose* CRunType::Getcompose(int index)
    {
        return static_cast<CCompose*>(GetObjectByID(ID_PARA_Compose, index));
    }

    CDutmal* CRunType::Setdutmal(CDutmal* pdutmal)
    {
        CDutmal* dutmal = pdutmal;
        if (dutmal == NULL) {
            dutmal = CDutmal::Create();
        }
        SetObject((CObject*)dutmal);

        return dutmal;
    }

    CDutmal* CRunType::Getdutmal(int index)
    {
        return static_cast<CDutmal*>(GetObjectByID(ID_PARA_Dutmal, index));
    }

    CAbstractButtonObjectType* CRunType::Setbtn(CAbstractButtonObjectType* pbtn)
    {
        CAbstractButtonObjectType* btn = pbtn;
        if (btn == NULL) {
            btn = CAbstractButtonObjectType::CreateArg(ID_PARA_AbstractButtonObjectType);
        }
        SetObject((CObject*)btn);

        return btn;
    }

    CAbstractButtonObjectType* CRunType::Getbtn(int index)
    {
        return static_cast<CAbstractButtonObjectType*>(GetObjectByID(ID_PARA_AbstractButtonObjectType, index));
    }

    CAbstractButtonObjectType* CRunType::SetradioBtn(CAbstractButtonObjectType* pradioBtn)
    {
        CAbstractButtonObjectType* radioBtn = pradioBtn;
        if (radioBtn == NULL) {
            radioBtn = CAbstractButtonObjectType::CreateArg(ID_PARA_AbstractRadioButtonObjectType);
        }
        SetObject((CObject*)radioBtn);

        return radioBtn;
    }

    CAbstractButtonObjectType* CRunType::GetradioBtn(int index)
    {
        return static_cast<CAbstractButtonObjectType*>(GetObjectByID(ID_PARA_AbstractRadioButtonObjectType, index));
    }

    CAbstractButtonObjectType* CRunType::SetcheckBtn(CAbstractButtonObjectType* pcheckBtn)
    {
        CAbstractButtonObjectType* checkBtn = pcheckBtn;
        if (checkBtn == NULL) {
            checkBtn = CAbstractButtonObjectType::CreateArg(ID_PARA_AbstractCheckButtonObjectType);
        }
        SetObject((CObject*)checkBtn);

        return checkBtn;
    }

    CAbstractButtonObjectType* CRunType::GetcheckBtn(int index)
    {
        return static_cast<CAbstractButtonObjectType*>(GetObjectByID(ID_PARA_AbstractCheckButtonObjectType, index));
    }

    CComboBoxType* CRunType::SetcomboBox(CComboBoxType* pcomboBox)
    {
        CComboBoxType* comboBox = pcomboBox;
        if (comboBox == NULL) {
            comboBox = CComboBoxType::Create();
        }
        SetObject((CObject*)comboBox);

        return comboBox;
    }

    CComboBoxType* CRunType::GetcomboBox(int index)
    {
        return static_cast<CComboBoxType*>(GetObjectByID(ID_PARA_ComboBoxType, index));
    }

    CListBoxType* CRunType::SetlistBox(CListBoxType* plistBox)
    {
        CListBoxType* listBox = plistBox;
        if (listBox == NULL) {
            listBox = CListBoxType::Create();
        }
        SetObject((CObject*)listBox);

        return listBox;
    }

    CListBoxType* CRunType::GetlistBox(int index)
    {
        return static_cast<CListBoxType*>(GetObjectByID(ID_PARA_ListBoxType, index));
    }

    CEditType* CRunType::Setedit(CEditType* pedit)
    {
        CEditType* edit = pedit;
        if (edit == NULL) {
            edit = CEditType::Create();
        }
        SetObject((CObject*)edit);

        return edit;
    }

    CEditType* CRunType::Getedit(int index)
    {
        return static_cast<CEditType*>(GetObjectByID(ID_PARA_EditType, index));
    }

    CScrollBarType* CRunType::SetscrollBar(CScrollBarType* pscrollBar)
    {
        CScrollBarType* scrollBar = pscrollBar;
        if (scrollBar == NULL) {
            scrollBar = CScrollBarType::Create();
        }
        SetObject((CObject*)scrollBar);

        return scrollBar;
    }

    CScrollBarType* CRunType::GetscrollBar(int index)
    {
        return static_cast<CScrollBarType*>(GetObjectByID(ID_PARA_ScrollBarType, index));
    }

    CVideoType* CRunType::Setvideo(CVideoType* pvideo)
    {
        CVideoType* video = pvideo;
        if (video == NULL) {
            video = CVideoType::Create();
        }
        SetObject((CObject*)video);

        return video;
    }

    CVideoType* CRunType::Getvideo(int index)
    {
        return static_cast<CVideoType*>(GetObjectByID(ID_PARA_VideoType, index));
    }

    CMarkpenBegin* CRunType::SetmarkpenBegin(CMarkpenBegin* pmarkpenBegin)
    {
        CMarkpenBegin* markpenBegin = pmarkpenBegin;
        if (markpenBegin == NULL) {
            markpenBegin = CMarkpenBegin::Create();
        }
        SetObject((CObject*)markpenBegin);

        return markpenBegin;
    }

    CMarkpenBegin* CRunType::GetmarkpenBegin(int index)
    {
        return static_cast<CMarkpenBegin*>(GetObjectByID(ID_PARA_MarkpenBegin, index));
    }

    CMarkpenEnd* CRunType::SetmarkpenEnd(CMarkpenEnd* pmarkpenEnd)
    {
        CMarkpenEnd* markpenEnd = pmarkpenEnd;
        if (markpenEnd == NULL) {
            markpenEnd = CMarkpenEnd::Create();
        }
        SetObject((CObject*)markpenEnd);

        return markpenEnd;
    }

    CMarkpenEnd* CRunType::GetmarkpenEnd(int index)
    {
        return static_cast<CMarkpenEnd*>(GetObjectByID(ID_PARA_MarkpenEnd, index));
    }

    CChartType* CRunType::Setchart(CChartType* pchart)
    {
        CChartType* chart = pchart;
        if (chart == NULL) {
            chart = CChartType::Create();
        }
        SetObject((CObject*)chart);

        return chart;
    }

    CChartType* CRunType::Getchart(int index)
    {
        return static_cast<CChartType*>(GetObjectByID(ID_PARA_ChartType, index));
    }


}
