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
#ifndef  _BREAKSETTING_H_
#define  _BREAKSETTING_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CBreakSetting Declaration 
    class CBreakSetting : public CExtObject
    {
    private:
        CBreakSetting();
    public:
        virtual ~CBreakSetting();
        static CBreakSetting* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        BRLATINTYPE GetBreakLatinWord(void) { return (BRLATINTYPE)m_uBreakLatinWord; }
        void SetBreakLatinWord(BRLATINTYPE breakLatinWord) { m_uBreakLatinWord = (UINT)breakLatinWord; }

        BRNONLATINTYPE GetBreakNonLatinWord(void) { return (BRNONLATINTYPE)m_uBreakNonLatinWord; }
        void SetBreakNonLatinWord(BRNONLATINTYPE breakNonLatinWord) { m_uBreakNonLatinWord = (UINT)breakNonLatinWord; }

        BOOL GetWidowOrphan(void) { return m_bWidowOrphan == true ? TRUE : FALSE; }
        void SetWidowOrphan(BOOL widowOrphan) { m_bWidowOrphan = (widowOrphan == TRUE ? true : false); }

        BOOL GetKeepWithNext(void) { return m_bKeepWithNext == true ? TRUE : FALSE; }
        void SetKeepWithNext(BOOL keepWithNext) { m_bKeepWithNext = (keepWithNext == TRUE ? true : false); }

        BOOL GetKeepLines(void) { return m_bKeepLines == true ? TRUE : FALSE; }
        void SetKeepLines(BOOL keepLines) { m_bKeepLines = (keepLines == TRUE ? true : false); }

        BOOL GetPageBreakBefore(void) { return m_bPageBreakBefore == true ? TRUE : FALSE; }
        void SetPageBreakBefore(BOOL pageBreakBefore) { m_bPageBreakBefore = (pageBreakBefore == TRUE ? true : false); }

        LINEWRAPTYPE GetLineWrap(void) { return (LINEWRAPTYPE)m_uLineWrap; }
        void SetLineWrap(LINEWRAPTYPE lineWrap) { m_uLineWrap = (UINT)lineWrap; }


    private:
        UINT m_uBreakLatinWord = 0;
        UINT m_uBreakNonLatinWord;
        bool m_bWidowOrphan;
        bool m_bKeepWithNext;
        bool m_bKeepLines;
        bool m_bPageBreakBefore;
        UINT m_uLineWrap;
    };
}
#endif // _BREAKSETTING_H_
