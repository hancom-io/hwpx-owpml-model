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
#include "trackchange.h"

namespace OWPML {

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CTrackChangeAuthor
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    CTrackChangeAuthor* CTrackChangeAuthor::Create()
    {
        return new CTrackChangeAuthor();
    }

    CTrackChangeAuthor::CTrackChangeAuthor() : CExtObject(ID_HEAD_TrackChangeAuthor), m_bMark(false), m_cColor(0), m_Id(0)
    {
    }

    CTrackChangeAuthor::~CTrackChangeAuthor()
    {
    }

    bool CTrackChangeAuthor::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"name", m_strName);
        Util::CXMLAttConverter::SetAttribute(att, L"mark", m_bMark);
        //    Util::CXMLAttConverter::SetAttribute(att, L"color", m_cColor);
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_Id);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTrackChangeAuthor::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"name", m_strName);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"mark", m_bMark);
        //    bres &= Util::CXMLAttConverter::GetAttribute(att, L"color", m_cColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_Id);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CTrackChange
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    CTrackChange* CTrackChange::Create()
    {
        return new CTrackChange();
    }

    CTrackChange::CTrackChange() : CExtObject(ID_HEAD_TrackChange), m_uType(TCT_UNKNOWN), m_uAuthorID(0), m_uiCharShapeID(0), m_bHide(false)
    {
        memset(&m_stDate, 0, sizeof(m_stDate));
    }

    CTrackChange::~CTrackChange()
    {
    }

    bool CTrackChange::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"type", g_TrackChangeTypeList, (UINT)m_uType);

        // YYYY-MM-DDTHH:MM:SSZ
        WCHAR datebuffer[_MAX_PATH] = { 0, };
        _usprintf_s(datebuffer, _MAX_PATH, L"%04d-%02d-%02dT%02d:%02d:%02dZ", m_stDate.wYear, m_stDate.wMonth, m_stDate.wDay, m_stDate.wHour, m_stDate.wMinute, 0);

        Util::CXMLAttConverter::SetAttribute(att, L"date", datebuffer);
        Util::CXMLAttConverter::SetAttribute(att, L"authorID", m_uAuthorID);
        Util::CXMLAttConverter::SetAttribute(att, L"hide", m_bHide);
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_Id);

        if (m_uType == TCT_CHARSHAPE) {
            Util::CXMLAttConverter::SetAttribute(att, L"charshapeID", m_uiCharShapeID);
        } else if (m_uType == TCT_PARASHAPE) {
            Util::CXMLAttConverter::SetAttribute(att, L"parashapeID", m_uiParaShapeID);
        }

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTrackChange::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"type", g_TrackChangeTypeList, (UINT&)m_uType);
        hncstd::wstring strdate;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"date", strdate);
        if (!strdate.empty()) {
            // YYYY-MM-DDTHH:MM:SSZ
            m_stDate.wMilliseconds = 0;
            _usscanf_s(strdate.c_str(), L"%04hu-%02hu-%02huT%02hu:%02hu:%02huZ", &m_stDate.wYear, &m_stDate.wMonth, &m_stDate.wDay, &m_stDate.wHour, &m_stDate.wMinute, &m_stDate.wSecond);
        }

        bres &= Util::CXMLAttConverter::GetAttribute(att, L"authorID", m_uAuthorID);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"hide", m_bHide);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_Id);

        if (m_uType == TCT_CHARSHAPE) {
            bres &= Util::CXMLAttConverter::GetAttribute(att, L"charshapeID", m_uiCharShapeID);
        } else if (m_uType == TCT_PARASHAPE) {
            bres &= Util::CXMLAttConverter::GetAttribute(att, L"parashapeID", m_uiParaShapeID);
        }

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CTrackChangeAuthors
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    CTrackChangeAuthors* CTrackChangeAuthors::Create()
    {
        return new CTrackChangeAuthors();
    }

    CTrackChangeAuthors::CTrackChangeAuthors() : CExtObject(ID_HEAD_TrackChangeAuthors), m_uItemCnt(0)
    {
    }

    CTrackChangeAuthors::~CTrackChangeAuthors()
    {
    }

    void CTrackChangeAuthors::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CTrackChangeAuthors, trackChangeAuthor)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTrackChangeAuthors)
            OWPML_HEAD_ADD_REDIRECT_FUNC(trackChangeAuthor, CTrackChangeAuthor, ID_HEAD_TrackChangeAuthor)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTrackChangeAuthors::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTrackChangeAuthors::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTrackChangeAuthor* CTrackChangeAuthors::SettrackChangeAuthor(CTrackChangeAuthor* ptrackchangeauthor)
    {
        CTrackChangeAuthor* trackchangeauthor = ptrackchangeauthor;
        if (trackchangeauthor == NULL) {
            trackchangeauthor = CTrackChangeAuthor::Create();
        }
        SetObject((CObject*)trackchangeauthor);

        return trackchangeauthor;
    }

    CTrackChangeAuthor* CTrackChangeAuthors::GettrackChangeAuthor(int index)
    {
        return static_cast<CTrackChangeAuthor*>(GetObjectByID(ID_HEAD_TrackChangeAuthor, index));
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CTrackChanges
    /////////////////////////////////////////////////////////////////////////////////////////////////////

    CTrackChanges* CTrackChanges::Create()
    {
        return new CTrackChanges();
    }

    CTrackChanges::CTrackChanges() : CExtObject(ID_HEAD_TrackChanges), m_uItemCnt(0)
    {
    }

    CTrackChanges::~CTrackChanges()
    {
    }

    void CTrackChanges::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CTrackChanges, trackChange)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CTrackChanges)
            OWPML_HEAD_ADD_REDIRECT_FUNC(trackChange, CTrackChange, ID_HEAD_TrackChange)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CTrackChanges::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CTrackChanges::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CTrackChange* CTrackChanges::SettrackChange(CTrackChange* ptrackchange)
    {
        CTrackChange* trackchange = ptrackchange;
        if (trackchange == NULL) {
            trackchange = CTrackChange::Create();
        }
        SetObject((CObject*)trackchange);

        return trackchange;
    }

    CTrackChange* CTrackChanges::GettrackChange(int index)
    {
        return static_cast<CTrackChange*>(GetObjectByID(ID_HEAD_TrackChange, index));
    }

}
