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
#ifndef  _DUTMAL_H_
#define  _DUTMAL_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CMainText;
    class CSubText;

    // CDutmal Declaration 
    class CDutmal : public CExtObject
    {
    private:
        CDutmal();
    public:
        virtual ~CDutmal();
        static CDutmal* Create();

        CDutmal* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CMainText* SetmainText(CMainText* mainText = NULL);
        CMainText* GetmainText(int index = 0);

        CSubText* SetsubText(CSubText* subText = NULL);
        CSubText* GetsubText(int index = 0);

        // Attribute Set/Get Fucntion
        DUTMALPOSTYPE GetPosType(void) { return (DUTMALPOSTYPE)m_uPosType; }
        void SetPosType(DUTMALPOSTYPE posType) { m_uPosType = (UINT)posType; }

        UINT GetSzRatio(void) { return m_uSzRatio; }
        void SetSzRatio(UINT szRatio) { m_uSzRatio = szRatio; }

        UINT GetOption(void) { return m_uOption; }
        void SetOption(UINT option) { m_uOption = option; }

        UINT GetStyleIDRef(void) { return m_uStyleIDRef; }
        void SetStyleIDRef(UINT styleIDRef) { m_uStyleIDRef = styleIDRef; }

        DUTMALALIGNTYPE GetAlign(void) { return (DUTMALALIGNTYPE)m_uAlign; }
        void SetAlign(DUTMALALIGNTYPE align) { m_uAlign = (UINT)align; }


    private:
        UINT m_uPosType;
        UINT m_uSzRatio;
        UINT m_uOption;
        UINT m_uStyleIDRef;
        UINT m_uAlign;
    };
}
#endif // _DUTMAL_H_
