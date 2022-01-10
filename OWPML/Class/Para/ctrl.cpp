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
#include "ctrl.h"

namespace OWPML {

    CCtrl* CCtrl::Create()
    {
        return new CCtrl();
    }

    CCtrl* CCtrl::Clone()
    {
        CCtrl* clone = new CCtrl();

        clone->SetCharStyleIDRef(this->m_uCharStyleIDRef);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CCtrl::CCtrl() : CExtObject(ID_PARA_Ctrl), m_uCharStyleIDRef((UINT)-1)
    {
    }

    CCtrl::~CCtrl()
    {
    }

    void CCtrl::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CCtrl, colPr)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, fieldBegin)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, fieldEnd)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, bookmark)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, header)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, footer)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, footNote)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, endNote)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, autoNum)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, newNum)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, pageNumCtrl)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, pageHiding)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, pageNum)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, indexmark)
            OWPML_PARALIST_REDIRECT_FUNC(CCtrl, hiddenComment)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCtrl)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(colPr, CColumnDefType, ID_PARA_ColumnDefType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(fieldBegin, CFieldBegin, ID_PARA_FieldBegin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(fieldEnd, CFieldEnd, ID_PARA_FieldEnd)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(bookmark, CBookmark, ID_PARA_Bookmark)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(header, CHeaderFooterType, ID_PARA_HeaderType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(footer, CHeaderFooterType, ID_PARA_FooterType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(footNote, CNoteType, ID_PARA_FootNoteType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(endNote, CNoteType, ID_PARA_EndNoteType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(autoNum, CAutoNumNewNumType, ID_PARA_AutoNumType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(newNum, CAutoNumNewNumType, ID_PARA_NewNumType)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pageNumCtrl, CPageNumCtrl, ID_PARA_PageNumCtrl)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pageHiding, CPageHiding, ID_PARA_PageHiding)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(pageNum, CPageNum, ID_PARA_PageNum)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(indexmark, CIndexmark, ID_PARA_Indexmark)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(hiddenComment, CHiddenComment, ID_PARA_HiddenComment)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCtrl::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (m_uCharStyleIDRef != -1)
            Util::CXMLAttConverter::SetAttribute(att, L"charStyleIDRef", m_uCharStyleIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCtrl::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charStyleIDRef", m_uCharStyleIDRef);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CColumnDefType* CCtrl::SetcolPr(CColumnDefType* pcolPr)
    {
        CColumnDefType* colPr = pcolPr;
        if (colPr == NULL) {
            colPr = CColumnDefType::Create();
        }
        SetObject((CObject*)colPr);

        return colPr;
    }

    CColumnDefType* CCtrl::GetcolPr(int index)
    {
        return static_cast<CColumnDefType*>(GetObjectByID(ID_PARA_ColumnDefType, index));
    }

    CFieldBegin* CCtrl::SetfieldBegin(CFieldBegin* pfieldBegin)
    {
        CFieldBegin* fieldBegin = pfieldBegin;
        if (fieldBegin == NULL) {
            fieldBegin = CFieldBegin::Create();
        }
        SetObject((CObject*)fieldBegin);

        return fieldBegin;
    }

    CFieldBegin* CCtrl::GetfieldBegin(int index)
    {
        return static_cast<CFieldBegin*>(GetObjectByID(ID_PARA_FieldBegin, index));
    }

    CFieldEnd* CCtrl::SetfieldEnd(CFieldEnd* pfieldEnd)
    {
        CFieldEnd* fieldEnd = pfieldEnd;
        if (fieldEnd == NULL) {
            fieldEnd = CFieldEnd::Create();
        }
        SetObject((CObject*)fieldEnd);

        return fieldEnd;
    }

    CFieldEnd* CCtrl::GetfieldEnd(int index)
    {
        return static_cast<CFieldEnd*>(GetObjectByID(ID_PARA_FieldEnd, index));
    }

    CBookmark* CCtrl::Setbookmark(CBookmark* pbookmark)
    {
        CBookmark* bookmark = pbookmark;
        if (bookmark == NULL) {
            bookmark = CBookmark::Create();
        }
        SetObject((CObject*)bookmark);

        return bookmark;
    }

    CBookmark* CCtrl::Getbookmark(int index)
    {
        return static_cast<CBookmark*>(GetObjectByID(ID_PARA_Bookmark, index));
    }

    CHeaderFooterType* CCtrl::Setheader(CHeaderFooterType* pheader)
    {
        CHeaderFooterType* header = pheader;
        if (header == NULL) {
            header = CHeaderFooterType::CreateArg(ID_PARA_HeaderType);
        }
        SetObject((CObject*)header);

        return header;
    }

    CHeaderFooterType* CCtrl::Getheader(int index)
    {
        return static_cast<CHeaderFooterType*>(GetObjectByID(ID_PARA_HeaderType, index));
    }

    CHeaderFooterType* CCtrl::Setfooter(CHeaderFooterType* pfooter)
    {
        CHeaderFooterType* footer = pfooter;
        if (footer == NULL) {
            footer = CHeaderFooterType::CreateArg(ID_PARA_FooterType);
        }
        SetObject((CObject*)footer);

        return footer;
    }

    CHeaderFooterType* CCtrl::Getfooter(int index)
    {
        return static_cast<CHeaderFooterType*>(GetObjectByID(ID_PARA_FooterType, index));
    }

    CNoteType* CCtrl::SetfootNote(CNoteType* pfootNote)
    {
        CNoteType* footNote = pfootNote;
        if (footNote == NULL) {
            footNote = CNoteType::CreateArg(ID_PARA_FootNoteType);
        }
        SetObject((CObject*)footNote);

        return footNote;
    }

    CNoteType* CCtrl::GetfootNote(int index)
    {
        return static_cast<CNoteType*>(GetObjectByID(ID_PARA_FootNoteType, index));
    }

    CNoteType* CCtrl::SetendNote(CNoteType* pendNote)
    {
        CNoteType* endNote = pendNote;
        if (endNote == NULL) {
            endNote = CNoteType::CreateArg(ID_PARA_EndNoteType);
        }
        SetObject((CObject*)endNote);

        return endNote;
    }

    CNoteType* CCtrl::GetendNote(int index)
    {
        return static_cast<CNoteType*>(GetObjectByID(ID_PARA_EndNoteType, index));
    }

    CAutoNumNewNumType* CCtrl::SetautoNum(CAutoNumNewNumType* pautoNum)
    {
        CAutoNumNewNumType* autoNum = pautoNum;
        if (autoNum == NULL) {
            autoNum = CAutoNumNewNumType::CreateArg(ID_PARA_AutoNumType);
        }
        SetObject((CObject*)autoNum);

        return autoNum;
    }

    CAutoNumNewNumType* CCtrl::GetautoNum(int index)
    {
        return static_cast<CAutoNumNewNumType*>(GetObjectByID(ID_PARA_AutoNumType, index));
    }

    CAutoNumNewNumType* CCtrl::SetnewNum(CAutoNumNewNumType* pnewNum)
    {
        CAutoNumNewNumType* newNum = pnewNum;
        if (newNum == NULL) {
            newNum = CAutoNumNewNumType::CreateArg(ID_PARA_NewNumType);
        }
        SetObject((CObject*)newNum);

        return newNum;
    }

    CAutoNumNewNumType* CCtrl::GetnewNum(int index)
    {
        return static_cast<CAutoNumNewNumType*>(GetObjectByID(ID_PARA_NewNumType, index));
    }

    CPageNumCtrl* CCtrl::SetpageNumCtrl(CPageNumCtrl* ppageNumCtrl)
    {
        CPageNumCtrl* pageNumCtrl = ppageNumCtrl;
        if (pageNumCtrl == NULL) {
            pageNumCtrl = CPageNumCtrl::Create();
        }
        SetObject((CObject*)pageNumCtrl);

        return pageNumCtrl;
    }

    CPageNumCtrl* CCtrl::GetpageNumCtrl(int index)
    {
        return static_cast<CPageNumCtrl*>(GetObjectByID(ID_PARA_PageNumCtrl, index));
    }

    CPageHiding* CCtrl::SetpageHiding(CPageHiding* ppageHiding)
    {
        CPageHiding* pageHiding = ppageHiding;
        if (pageHiding == NULL) {
            pageHiding = CPageHiding::Create();
        }
        SetObject((CObject*)pageHiding);

        return pageHiding;
    }

    CPageHiding* CCtrl::GetpageHiding(int index)
    {
        return static_cast<CPageHiding*>(GetObjectByID(ID_PARA_PageHiding, index));
    }

    CPageNum* CCtrl::SetpageNum(CPageNum* ppageNum)
    {
        CPageNum* pageNum = ppageNum;
        if (pageNum == NULL) {
            pageNum = CPageNum::Create();
        }
        SetObject((CObject*)pageNum);

        return pageNum;
    }

    CPageNum* CCtrl::GetpageNum(int index)
    {
        return static_cast<CPageNum*>(GetObjectByID(ID_PARA_PageNum, index));
    }

    CIndexmark* CCtrl::Setindexmark(CIndexmark* pindexmark)
    {
        CIndexmark* indexmark = pindexmark;
        if (indexmark == NULL) {
            indexmark = CIndexmark::Create();
        }
        SetObject((CObject*)indexmark);

        return indexmark;
    }

    CIndexmark* CCtrl::Getindexmark(int index)
    {
        return static_cast<CIndexmark*>(GetObjectByID(ID_PARA_Indexmark, index));
    }

    CHiddenComment* CCtrl::SethiddenComment(CHiddenComment* phiddenComment)
    {
        CHiddenComment* hiddenComment = phiddenComment;
        if (hiddenComment == NULL) {
            hiddenComment = CHiddenComment::Create();
        }
        SetObject((CObject*)hiddenComment);

        return hiddenComment;
    }

    CHiddenComment* CCtrl::GethiddenComment(int index)
    {
        return static_cast<CHiddenComment*>(GetObjectByID(ID_PARA_HiddenComment, index));
    }

}
