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
#ifndef  _CTRL_H_
#define  _CTRL_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CColumnDefType;
    class CFieldBegin;
    class CFieldEnd;
    class CBookmark;
    class CHeaderFooterType;
    class CHeaderFooterType;
    class CNoteType;
    class CNoteType;
    class CAutoNumNewNumType;
    class CAutoNumNewNumType;
    class CPageNumCtrl;
    class CPageHiding;
    class CPageNum;
    class CIndexmark;
    class CHiddenComment;

    // CCtrl Declaration 
    class CCtrl : public CExtObject
    {
    private:
        CCtrl();
    public:
        virtual ~CCtrl();
        static CCtrl* Create();

        CCtrl* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CColumnDefType* SetcolPr(CColumnDefType* colPr = NULL);
        CColumnDefType* GetcolPr(int index = 0);

        CFieldBegin* SetfieldBegin(CFieldBegin* fieldBegin = NULL);
        CFieldBegin* GetfieldBegin(int index = 0);

        CFieldEnd* SetfieldEnd(CFieldEnd* fieldEnd = NULL);
        CFieldEnd* GetfieldEnd(int index = 0);

        CBookmark* Setbookmark(CBookmark* bookmark = NULL);
        CBookmark* Getbookmark(int index = 0);

        CHeaderFooterType* Setheader(CHeaderFooterType* header = NULL);
        CHeaderFooterType* Getheader(int index = 0);

        CHeaderFooterType* Setfooter(CHeaderFooterType* footer = NULL);
        CHeaderFooterType* Getfooter(int index = 0);

        CNoteType* SetfootNote(CNoteType* footNote = NULL);
        CNoteType* GetfootNote(int index = 0);

        CNoteType* SetendNote(CNoteType* endNote = NULL);
        CNoteType* GetendNote(int index = 0);

        CAutoNumNewNumType* SetautoNum(CAutoNumNewNumType* autoNum = NULL);
        CAutoNumNewNumType* GetautoNum(int index = 0);

        CAutoNumNewNumType* SetnewNum(CAutoNumNewNumType* newNum = NULL);
        CAutoNumNewNumType* GetnewNum(int index = 0);

        CPageNumCtrl* SetpageNumCtrl(CPageNumCtrl* pageNumCtrl = NULL);
        CPageNumCtrl* GetpageNumCtrl(int index = 0);

        CPageHiding* SetpageHiding(CPageHiding* pageHiding = NULL);
        CPageHiding* GetpageHiding(int index = 0);

        CPageNum* SetpageNum(CPageNum* pageNum = NULL);
        CPageNum* GetpageNum(int index = 0);

        CIndexmark* Setindexmark(CIndexmark* indexmark = NULL);
        CIndexmark* Getindexmark(int index = 0);

        CHiddenComment* SethiddenComment(CHiddenComment* hiddenComment = NULL);
        CHiddenComment* GethiddenComment(int index = 0);

        UINT GetCharStyleIDRef(void) { return m_uCharStyleIDRef; }
        void SetCharStyleIDRef(UINT charStyleIDRef) { m_uCharStyleIDRef = charStyleIDRef; }

    private:
        // UINT m_uCharPrIDRef;
        UINT m_uCharStyleIDRef;
    };
}
#endif // _CTRL_H_
