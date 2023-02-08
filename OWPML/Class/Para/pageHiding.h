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
#ifndef  _PAGEHIDING_H_
#define  _PAGEHIDING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CPageHiding Declaration 
    class CPageHiding : public CExtObject
    {
    private:
        CPageHiding();
    public:
        virtual ~CPageHiding();
        static CPageHiding* Create();

        CPageHiding* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        BOOL GetHideHeader(void) { return m_bHideHeader == true ? TRUE : FALSE; }
        void SetHideHeader(BOOL hideHeader) { m_bHideHeader = (hideHeader == TRUE ? true : false); }

        BOOL GetHideFooter(void) { return m_bHideFooter == true ? TRUE : FALSE; }
        void SetHideFooter(BOOL hideFooter) { m_bHideFooter = (hideFooter == TRUE ? true : false); }

        BOOL GetHideMasterPage(void) { return m_bHideMasterPage == true ? TRUE : FALSE; }
        void SetHideMasterPage(BOOL hideMasterPage) { m_bHideMasterPage = (hideMasterPage == TRUE ? true : false); }

        BOOL GetHideBorder(void) { return m_bHideBorder == true ? TRUE : FALSE; }
        void SetHideBorder(BOOL hideBorder) { m_bHideBorder = (hideBorder == TRUE ? true : false); }

        BOOL GetHideFill(void) { return m_bHideFill == true ? TRUE : FALSE; }
        void SetHideFill(BOOL hideFill) { m_bHideFill = (hideFill == TRUE ? true : false); }

        BOOL GetHidePageNum(void) { return m_bHidePageNum == true ? TRUE : FALSE; }
        void SetHidePageNum(BOOL hidePageNum) { m_bHidePageNum = (hidePageNum == TRUE ? true : false); }

    private:
        bool m_bHideHeader;
        bool m_bHideFooter;
        bool m_bHideMasterPage;
        bool m_bHideBorder;
        bool m_bHideFill;
        bool m_bHidePageNum;
    };
}
#endif // _PAGEHIDING_H_
