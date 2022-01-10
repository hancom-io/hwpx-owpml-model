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
#ifndef  _TABDEFTYPE_H_
#define  _TABDEFTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CTabItem;

    // CTabDefType Declaration 
    class CTabDefType : public CExtObject
    {
    private:
        CTabDefType();
    public:
        virtual ~CTabDefType();
        static CTabDefType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CTabItem* SettabItem(CTabItem* tabItem = NULL);
        CTabItem* GettabItem(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        BOOL GetAutoTabLeft(void) { return m_bAutoTabLeft == true ? TRUE : FALSE; }
        void SetAutoTabLeft(BOOL autoTabLeft) { m_bAutoTabLeft = (autoTabLeft == TRUE ? true : false); }

        BOOL GetAutoTabRight(void) { return m_bAutoTabRight == true ? TRUE : FALSE; }
        void SetAutoTabRight(BOOL autoTabRight) { m_bAutoTabRight = (autoTabRight == TRUE ? true : false); }


    private:
        UINT m_uId;
        bool m_bAutoTabLeft;
        bool m_bAutoTabRight;
    };
}
#endif // _TABDEFTYPE_H_
