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
#ifndef  _ABSTRACTFORMOBJECTTYPE_H_
#define  _ABSTRACTFORMOBJECTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CFormCharPr;

    // CAbstractFormObjectType Declaration 
    class CAbstractFormObjectType : public CAbstractShapeObjectType
    {
    public:
        CAbstractFormObjectType(UINT id);
    public:
        virtual ~CAbstractFormObjectType();
        //static CAbstractFormObjectType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CFormCharPr* SetformCharPr(CFormCharPr* formCharPr = NULL);
        CFormCharPr* GetformCharPr(int index = 0);

        // Attribute Set/Get Fucntion
        LPCWSTR GetName(void) { return m_strName.c_str(); }
        void SetName(LPCWSTR name) { m_strName = name; }

        COLORREF GetForeColor(void) { return m_cForeColor; }
        void SetForeColor(COLORREF foreColor) { m_cForeColor = foreColor; }

        COLORREF GetBackColor(void) { return m_cBackColor; }
        void SetBackColor(COLORREF backColor) { m_cBackColor = backColor; }

        LPCWSTR GetGroupName(void) { return m_strGroupName.c_str(); }
        void SetGroupName(LPCWSTR groupName) { m_strGroupName = groupName; }

        BOOL GetTabStop(void) { return m_bTabStop == true ? TRUE : FALSE; }
        void SetTabStop(BOOL tabStop) { m_bTabStop = (tabStop == TRUE ? true : false); }

        INT GetTabOrder(void) { return m_nTabOrder; }
        void SetTabOrder(INT tabOrder) { m_nTabOrder = tabOrder; }

        BOOL GetEditable(void) { return m_bEditable == true ? TRUE : FALSE; }
        void SetEditable(BOOL editable) { m_bEditable = (editable == TRUE ? true : false); }

        BOOL GetEnabled(void) { return m_bEnabled == true ? TRUE : FALSE; }
        void SetEnabled(BOOL enabled) { m_bEnabled = (enabled == TRUE ? true : false); }

        UINT GetBorderTypeIDRef(void) { return m_uBorderTypeIDRef; }
        void SetBorderTypeIDRef(UINT borderTypeIDRef) { m_uBorderTypeIDRef = borderTypeIDRef; }

        BOOL GetDrawFrame(void) { return m_bDrawFrame == true ? TRUE : FALSE; }
        void SetDrawFrame(BOOL drawFrame) { m_bDrawFrame = (drawFrame == TRUE ? true : false); }

        BOOL GetPrintable(void) { return m_bPrintable == true ? TRUE : FALSE; }
        void SetPrintable(BOOL printable) { m_bPrintable = (printable == TRUE ? true : false); }

        LPCWSTR GetCommand(void) { return m_strCommand.c_str(); }
        void SetCommand(LPCWSTR command) { m_strCommand = command; }

    private:
        hncstd::wstring m_strName;
        CColorRef m_cForeColor;
        CColorRef m_cBackColor;
        hncstd::wstring m_strGroupName;
        bool m_bTabStop;
        bool m_bEditable;
        INT m_nTabOrder;
        bool m_bEnabled;
        UINT m_uBorderTypeIDRef;
        bool m_bDrawFrame;
        bool m_bPrintable;
        hncstd::wstring m_strCommand;
    };
}
#endif // _ABSTRACTFORMOBJECTTYPE_H_
