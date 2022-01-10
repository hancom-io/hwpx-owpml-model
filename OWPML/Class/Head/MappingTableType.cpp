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
#include "MappingTableType.h"

namespace OWPML {

    CMappingTableType* CMappingTableType::Create()
    {
        return new CMappingTableType();
    }

    CMappingTableType::CMappingTableType() : CExtObject(ID_HEAD_MappingTableType)
    {
    }

    CMappingTableType::~CMappingTableType()
    {
    }

    void CMappingTableType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, fontfaces)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, borderFills)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, charProperties)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, tabProperties)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, numberings)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, bullets)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, paraProperties)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, styles)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, memoProperties)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, trackChanges)
            OWPML_HEAD_REDIRECT_FUNC(CMappingTableType, trackChangeAuthors)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CMappingTableType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(fontfaces, CFontfaces, ID_HEAD_Fontfaces)
            OWPML_HEAD_ADD_REDIRECT_FUNC(borderFills, CBorderFills, ID_HEAD_BorderFills)
            OWPML_HEAD_ADD_REDIRECT_FUNC(charProperties, CCharProperties, ID_HEAD_CharProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(tabProperties, CTabProperties, ID_HEAD_TabProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(numberings, CNumberings, ID_HEAD_Numberings)
            OWPML_HEAD_ADD_REDIRECT_FUNC(bullets, CBullets, ID_HEAD_Bullets)
            OWPML_HEAD_ADD_REDIRECT_FUNC(paraProperties, CParaProperties, ID_HEAD_ParaProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(styles, CStyles, ID_HEAD_Styles)
            OWPML_HEAD_ADD_REDIRECT_FUNC(memoProperties, CMemoProperties, ID_HEAD_MemoProperties)
            OWPML_HEAD_ADD_REDIRECT_FUNC(trackChanges, CTrackChanges, ID_HEAD_TrackChanges)
            OWPML_HEAD_ADD_REDIRECT_FUNC(trackChangeAuthors, CTrackChangeAuthors, ID_HEAD_TrackChangeAuthors)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CMappingTableType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CMappingTableType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFontfaces* CMappingTableType::Setfontfaces(CFontfaces* pfontfaces)
    {
        CFontfaces* fontfaces = pfontfaces;
        if (fontfaces == NULL) {
            fontfaces = CFontfaces::Create();
        }
        SetObject((CObject*)fontfaces);

        return fontfaces;
    }

    CFontfaces* CMappingTableType::Getfontfaces(int index)
    {
        return static_cast<CFontfaces*>(GetObjectByID(ID_HEAD_Fontfaces, index));
    }

    CBorderFills* CMappingTableType::SetborderFills(CBorderFills* pborderFills)
    {
        CBorderFills* borderFills = pborderFills;
        if (borderFills == NULL) {
            borderFills = CBorderFills::Create();
        }
        SetObject((CObject*)borderFills);

        return borderFills;
    }

    CBorderFills* CMappingTableType::GetborderFills(int index)
    {
        return static_cast<CBorderFills*>(GetObjectByID(ID_HEAD_BorderFills, index));
    }

    CCharProperties* CMappingTableType::SetcharProperties(CCharProperties* pcharProperties)
    {
        CCharProperties* charProperties = pcharProperties;
        if (charProperties == NULL) {
            charProperties = CCharProperties::Create();
        }
        SetObject((CObject*)charProperties);

        return charProperties;
    }

    CCharProperties* CMappingTableType::GetcharProperties(int index)
    {
        return static_cast<CCharProperties*>(GetObjectByID(ID_HEAD_CharProperties, index));
    }

    CTabProperties* CMappingTableType::SettabProperties(CTabProperties* ptabProperties)
    {
        CTabProperties* tabProperties = ptabProperties;
        if (tabProperties == NULL) {
            tabProperties = CTabProperties::Create();
        }
        SetObject((CObject*)tabProperties);

        return tabProperties;
    }

    CTabProperties* CMappingTableType::GettabProperties(int index)
    {
        return static_cast<CTabProperties*>(GetObjectByID(ID_HEAD_TabProperties, index));
    }

    CNumberings* CMappingTableType::Setnumberings(CNumberings* pnumberings)
    {
        CNumberings* numberings = pnumberings;
        if (numberings == NULL) {
            numberings = CNumberings::Create();
        }
        SetObject((CObject*)numberings);

        return numberings;
    }

    CNumberings* CMappingTableType::Getnumberings(int index)
    {
        return static_cast<CNumberings*>(GetObjectByID(ID_HEAD_Numberings, index));
    }

    CBullets* CMappingTableType::Setbullets(CBullets* pbullets)
    {
        CBullets* bullets = pbullets;
        if (bullets == NULL) {
            bullets = CBullets::Create();
        }
        SetObject((CObject*)bullets);

        return bullets;
    }

    CBullets* CMappingTableType::Getbullets(int index)
    {
        return static_cast<CBullets*>(GetObjectByID(ID_HEAD_Bullets, index));
    }

    CParaProperties* CMappingTableType::SetparaProperties(CParaProperties* pparaProperties)
    {
        CParaProperties* paraProperties = pparaProperties;
        if (paraProperties == NULL) {
            paraProperties = CParaProperties::Create();
        }
        SetObject((CObject*)paraProperties);

        return paraProperties;
    }

    CParaProperties* CMappingTableType::GetparaProperties(int index)
    {
        return static_cast<CParaProperties*>(GetObjectByID(ID_HEAD_ParaProperties, index));
    }

    CStyles* CMappingTableType::Setstyles(CStyles* pstyles)
    {
        CStyles* styles = pstyles;
        if (styles == NULL) {
            styles = CStyles::Create();
        }
        SetObject((CObject*)styles);

        return styles;
    }

    CStyles* CMappingTableType::Getstyles(int index)
    {
        return static_cast<CStyles*>(GetObjectByID(ID_HEAD_Styles, index));
    }

    CMemoProperties* CMappingTableType::SetmemoProperties(CMemoProperties* pmemoProperties)
    {
        CMemoProperties* memoProperties = pmemoProperties;
        if (memoProperties == NULL) {
            memoProperties = CMemoProperties::Create();
        }
        SetObject((CObject*)memoProperties);

        return memoProperties;
    }

    CMemoProperties* CMappingTableType::GetmemoProperties(int index)
    {
        return static_cast<CMemoProperties*>(GetObjectByID(ID_HEAD_MemoProperties, index));
    }

    CTrackChanges* CMappingTableType::SettrackChanges(CTrackChanges* trackchanges)
    {
        CTrackChanges* ptrackchages = trackchanges;
        if (ptrackchages == NULL) {
            ptrackchages = CTrackChanges::Create();
        }
        SetObject((CObject*)ptrackchages);

        return ptrackchages;
    }

    CTrackChanges* CMappingTableType::GettrackChanges(int index)
    {
        return static_cast<CTrackChanges*>(GetObjectByID(ID_HEAD_TrackChanges, index));
    }

    CTrackChangeAuthors* CMappingTableType::SettrackChangeAuthors(CTrackChangeAuthors* trackchangeAuthors)
    {
        CTrackChangeAuthors* ptrackchangeAuthors = trackchangeAuthors;
        if (ptrackchangeAuthors == NULL) {
            ptrackchangeAuthors = CTrackChangeAuthors::Create();
        }
        SetObject((CObject*)ptrackchangeAuthors);

        return ptrackchangeAuthors;
    }

    CTrackChangeAuthors* CMappingTableType::GettrackChangeAuthors(int index)
    {
        return static_cast<CTrackChangeAuthors*>(GetObjectByID(ID_HEAD_TrackChangeAuthors, index));
    }



}
