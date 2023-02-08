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
#ifndef  _TRACKCHAGE_TAG_H_
#define  _TRACKCHAGE_TAG_H_

namespace OWPML {
    class CAttribute;
    class CSerializer;
    class CRunType;

    // CTrackChangeTag Declaration 
    class CTrackChangeTag : public CExtObject
    {
    private:
        CTrackChangeTag(UINT id);
    public:
        virtual ~CTrackChangeTag();
        static CTrackChangeTag* Create();
        static CTrackChangeTag* CreateArg(BOOL insert, BOOL begin);

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        UINT GetTcId(void) { return m_uTcId; }
        void SetTcId(UINT id) { m_uTcId = id; }

        BOOL GetParaEnd(void) { return m_bParaEnd == true ? TRUE : FALSE; }
        void SetParaEnd(BOOL paraend) { m_bParaEnd = (paraend == TRUE ? true : false); }

    private:
        UINT m_uId;
        UINT m_uTcId;
        bool m_bParaEnd;
    };
}
#endif // _TRACKCHAGE_TAG_H_
