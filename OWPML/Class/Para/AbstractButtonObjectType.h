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
#ifndef  _ABSTRACTBUTTONOBJECTTYPE_H_
#define  _ABSTRACTBUTTONOBJECTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CAbstractButtonObjectType Declaration 
    class CAbstractButtonObjectType : public CAbstractFormObjectType
    {
    public:
        CAbstractButtonObjectType(UINT id);
    public:
        virtual ~CAbstractButtonObjectType();
        static CAbstractButtonObjectType* Create();
        static CAbstractButtonObjectType* CreateArg(UINT id);

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        LPCWSTR GetCaption(void) { return m_strCaption.c_str(); }
        void SetCaption(LPCWSTR caption) { m_strCaption = caption; }

        BUTTONVALUETYPE GetValue(void) { return (BUTTONVALUETYPE)m_uValue; }
        void SetValue(BUTTONVALUETYPE value) { m_uValue = (UINT)value; }

        LPCWSTR GetRadioGroupName(void) { return m_strRadioGroupName.c_str(); }
        void SetRadioGroupName(LPCWSTR radioGroupName) { m_strRadioGroupName = radioGroupName; }

        BOOL GetTriState(void) { return m_bTriState == true ? TRUE : FALSE; }
        void SetTriState(BOOL triState) { m_bTriState = (triState == TRUE ? true : false); }

        BUTTONBACKSTYLETYPE GetBackStyle(void) { return (BUTTONBACKSTYLETYPE)m_uBackStyle; }
        void SetBackStyle(BUTTONBACKSTYLETYPE backStyle) { m_uBackStyle = (UINT)backStyle; }


    private:
        hncstd::wstring m_strCaption;
        UINT m_uValue = (UINT)-1; // g_ButtonValueList 범위에서 벗어난 값으로 지정: 실제 값(g_ButtonValueList)을 지정할 경우만 Write
        hncstd::wstring m_strRadioGroupName;
        bool m_bTriState = false;
        UINT m_uBackStyle = (UINT)-1; // g_ButtonbackStyleList 범위에서 벗어난 값으로 지정: 실제 값(g_ButtonbackStyleList)을 지정할 경우만 Write
    };
}
#endif // _ABSTRACTBUTTONOBJECTTYPE_H_
