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
#ifndef  _DOCDISTRIBUTE_H_
#define  _DOCDISTRIBUTE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CDocDistribute 배포용 문서 
    class CDocDistribute : public CExtObject
    {
    public:
        CDocDistribute();
        virtual ~CDocDistribute();
        static CDocDistribute* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        // attritute
        void SetKey(LPCWSTR key) { m_key = key; }
        LPCWSTR GetKey(void) { return m_key.c_str(); }

        void SetNoCopy(BOOL nocopy) { m_nocopy = (nocopy == TRUE ? true : false); }
        BOOL GetNoCopy() { return m_nocopy == true ? TRUE : FALSE; }

        void SetNoPrint(BOOL noprint) { m_noprint = (noprint == TRUE ? true : false); }
        BOOL GetNoPrint() { return m_noprint == true ? TRUE : FALSE; }

    private:
        hncstd::wstring m_key;
        bool        m_nocopy;
        bool        m_noprint;
    };

}
#endif // _DOCDISTRIBUTE_H_
