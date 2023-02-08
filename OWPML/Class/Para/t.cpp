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
#include "t.h"

namespace OWPML {

    CT* CT::Create()
    {
        return new CT();
    }

    CT::CT() : CExtObject(ID_PARA_T), m_uCharStyleIDRef((UINT)-1)
    {
    }

    CT* CT::Clone()
    {
        CT* clone = new CT();

        clone->SetCharStyleIDRef(this->m_uCharStyleIDRef);

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CT::~CT()
    {
    }

    void CT::InitMap(bool bRead)
    {
        OWPML_PARALIST_REDIRECT_FUNC(CT, markpenBegin)
            OWPML_PARALIST_REDIRECT_FUNC(CT, markpenEnd)
            OWPML_PARALIST_REDIRECT_FUNC(CT, titleMark)
            OWPML_PARALIST_REDIRECT_FUNC(CT, tab)
            OWPML_PARALIST_REDIRECT_FUNC(CT, lineBreak)
            OWPML_PARALIST_REDIRECT_FUNC(CT, hypen)
            OWPML_PARALIST_REDIRECT_FUNC(CT, nbSpace)
            OWPML_PARALIST_REDIRECT_FUNC(CT, fwSpace)
            OWPML_PARALIST_REDIRECT_FUNC(CT, chval)
            OWPML_PARALIST_REDIRECT_FUNC(CT, insertBegin)
            OWPML_PARALIST_REDIRECT_FUNC(CT, insertEnd)
            OWPML_PARALIST_REDIRECT_FUNC(CT, deleteBegin)
            OWPML_PARALIST_REDIRECT_FUNC(CT, deleteEnd)
            OWPML_PARALIST_REDIRECT_FUNC(CUnknownChar, unknownch)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CT)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(markpenBegin, CMarkpenBegin, ID_PARA_MarkpenBegin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(markpenEnd, CMarkpenEnd, ID_PARA_MarkpenEnd)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(titleMark, CTitleMark, ID_PARA_TitleMark)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(tab, CTab, ID_PARA_Tab)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(lineBreak, CLineBreak, ID_PARA_LineBreak)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(hypen, CHypen, ID_PARA_Hypen)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(nbSpace, CNbSpace, ID_PARA_NbSpace)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(fwSpace, CFwSpace, ID_PARA_FwSpace)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(chval, CChar, ID_PARA_Char)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(unknownch, CUnknownChar, ID_PARA_UnknownChar)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(insertBegin, CTrackChangeTag, ID_PARA_TC_InsertBegin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(insertEnd, CTrackChangeTag, ID_PARA_TC_InsertEnd)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(deleteBegin, CTrackChangeTag, ID_PARA_TC_DeleteBegin)
            OWPML_PARALIST_ADD_REDIRECT_FUNC(deleteEnd, CTrackChangeTag, ID_PARA_TC_DeleteEnd)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CT::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (m_uCharStyleIDRef != -1)
            Util::CXMLAttConverter::SetAttribute(att, L"charStyleIDRef", m_uCharStyleIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CT::ReadNodeValue(LPCWSTR const value, const unsigned int length)
    {
        hncstd::wstring strvalue(value, length);

        Setval(strvalue.c_str(), true);
        return true;
    }

    bool CT::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"charStyleIDRef", m_uCharStyleIDRef);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CMarkpenBegin* CT::SetmarkpenBegin(CMarkpenBegin* pmarkpenBegin)
    {
        CMarkpenBegin* markpenBegin = pmarkpenBegin;
        if (markpenBegin == NULL) {
            markpenBegin = CMarkpenBegin::Create();
        }
        SetObject((CObject*)markpenBegin);

        return markpenBegin;
    }

    CMarkpenBegin* CT::GetmarkpenBegin(int index)
    {
        return static_cast<CMarkpenBegin*>(GetObjectByID(ID_PARA_MarkpenBegin, index));
    }

    CMarkpenEnd* CT::SetmarkpenEnd(CMarkpenEnd* pmarkpenEnd)
    {
        CMarkpenEnd* markpenEnd = pmarkpenEnd;
        if (markpenEnd == NULL) {
            markpenEnd = CMarkpenEnd::Create();
        }
        SetObject((CObject*)markpenEnd);

        return markpenEnd;
    }

    CMarkpenEnd* CT::GetmarkpenEnd(int index)
    {
        return static_cast<CMarkpenEnd*>(GetObjectByID(ID_PARA_MarkpenEnd, index));
    }

    CTrackChangeTag* CT::SettcInsertBegin(CTrackChangeTag* ptcbegin)
    {
        CTrackChangeTag* tcbegin = ptcbegin;
        if (tcbegin == NULL) {
            tcbegin = CTrackChangeTag::CreateArg(TRUE, TRUE);
        }
        SetObject((CObject*)tcbegin);

        return tcbegin;
    }

    CTrackChangeTag* CT::GettcInsertBegin(int index)
    {
        return static_cast<CTrackChangeTag*>(GetObjectByID(ID_PARA_TC_InsertBegin, index));
    }

    CTrackChangeTag* CT::SettcInsertEnd(CTrackChangeTag* ptcend)
    {
        CTrackChangeTag* tcend = ptcend;
        if (tcend == NULL) {
            tcend = CTrackChangeTag::CreateArg(TRUE, FALSE);
        }
        SetObject((CObject*)tcend);

        return tcend;
    }

    CTrackChangeTag* CT::GettcInsertEnd(int index)
    {
        return static_cast<CTrackChangeTag*>(GetObjectByID(ID_PARA_TC_InsertEnd, index));
    }

    CTrackChangeTag* CT::SettcDeleteBegin(CTrackChangeTag* ptcbegin)
    {
        CTrackChangeTag* tcbegin = ptcbegin;
        if (tcbegin == NULL) {
            tcbegin = CTrackChangeTag::CreateArg(FALSE, TRUE);
        }
        SetObject((CObject*)tcbegin);

        return tcbegin;
    }

    CTrackChangeTag* CT::GettcDeleteBegin(int index)
    {
        return static_cast<CTrackChangeTag*>(GetObjectByID(ID_PARA_TC_DeleteBegin, index));
    }

    CTrackChangeTag* CT::SettcDeleteEnd(CTrackChangeTag* ptcend)
    {
        CTrackChangeTag* tcend = ptcend;
        if (tcend == NULL) {
            tcend = CTrackChangeTag::CreateArg(FALSE, FALSE);
        }
        SetObject((CObject*)tcend);

        return tcend;
    }

    CTrackChangeTag* CT::GettcDeleteEnd(int index)
    {
        return static_cast<CTrackChangeTag*>(GetObjectByID(ID_PARA_TC_DeleteEnd, index));
    }

    CTitleMark* CT::SettitleMark(CTitleMark* ptitleMark)
    {
        CTitleMark* titleMark = ptitleMark;
        if (titleMark == NULL) {
            titleMark = CTitleMark::Create();
        }
        SetObject((CObject*)titleMark);

        return titleMark;
    }

    CTitleMark* CT::GettitleMark(int index)
    {
        return static_cast<CTitleMark*>(GetObjectByID(ID_PARA_TitleMark, index));
    }

    CTab* CT::Settab(CTab* ptab)
    {
        CTab* tab = ptab;
        if (tab == NULL) {
            tab = CTab::Create();
        }
        SetObject((CObject*)tab);

        return tab;
    }

    CTab* CT::Gettab(int index)
    {
        return static_cast<CTab*>(GetObjectByID(ID_PARA_Tab, index));
    }

    CLineBreak* CT::SetlineBreak(CLineBreak* plineBreak)
    {
        CLineBreak* lineBreak = plineBreak;
        if (lineBreak == NULL) {
            lineBreak = CLineBreak::Create();
        }
        SetObject((CObject*)lineBreak);

        return lineBreak;
    }

    CLineBreak* CT::GetlineBreak(int index)
    {
        return static_cast<CLineBreak*>(GetObjectByID(ID_PARA_LineBreak, index));
    }

    CHypen* CT::Sethypen(CHypen* phypen)
    {
        CHypen* hypen = phypen;
        if (hypen == NULL) {
            hypen = CHypen::Create();
        }
        SetObject((CObject*)hypen);

        return hypen;
    }

    CHypen* CT::Gethypen(int index)
    {
        return static_cast<CHypen*>(GetObjectByID(ID_PARA_Hypen, index));
    }

    CNbSpace* CT::SetnbSpace(CNbSpace* pnbSpace)
    {
        CNbSpace* nbSpace = pnbSpace;
        if (nbSpace == NULL) {
            nbSpace = CNbSpace::Create();
        }
        SetObject((CObject*)nbSpace);

        return nbSpace;
    }

    CNbSpace* CT::GetnbSpace(int index)
    {
        return static_cast<CNbSpace*>(GetObjectByID(ID_PARA_NbSpace, index));
    }

    CFwSpace* CT::SetfwSpace(CFwSpace* pfwSpace)
    {
        CFwSpace* fwSpace = pfwSpace;
        if (fwSpace == NULL) {
            fwSpace = CFwSpace::Create();
        }
        SetObject((CObject*)fwSpace);

        return fwSpace;
    }

    CFwSpace* CT::GetfwSpace(int index)
    {
        return static_cast<CFwSpace*>(GetObjectByID(ID_PARA_FwSpace, index));
    }


    void CT::Setval(LPCWSTR val, BOOL bread)
    {
        if (bread) {
            SetObject((CObject*)new CChar(val));
            return;
        }

        size_t len = _ustrlen(val);
        BOOL bCorrectChar = TRUE;
        size_t i = 0;

        for (i = 0; i < len; ++i) {
            if ((val[i] & 0xF800) == 0xD800) {
                if ((val[i] & 0xFC00) == 0xDC00) {
                    // 처음부터 low만 온경우
                    bCorrectChar = FALSE;
                    break;
                } else {
                    if (i + 1 < len) {
                        if ((val[i + 1] & 0xFC00) == 0xDC00) { //정상적인 경우
                            ++i;
                            continue;
                        } else {
                            // high 만 온경우
                            bCorrectChar = FALSE;
                            break;
                        }
                    } else {
                        // 마직막 CHAR에 HIGH 만 온경우
                        bCorrectChar = FALSE;
                        break;
                    }
                }
            } else if (val[i] <= 29 && val[i] >= 25) {
                bCorrectChar = FALSE;
                break;
            }
        }

        if (bCorrectChar) {
            SetObject((CObject*)new CChar(val));
        } else {
            hncstd::wstring newval(val, i);
            SetObject((CObject*)new CChar(newval.c_str()));

            SetObject((CObject*)new CUnknownChar(val[i]));

            Setval(&val[i + 1]);
        }
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CChar
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    CChar::CChar(LPCWSTR val) : CStringValueObject(ID_PARA_Char)
    {
        Setval(val);
    }

    CChar::~CChar()
    {
    }

    CChar* CChar::Clone()
    {
        CChar* clone = new CChar(this->Getval());

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    void CChar::InitMap(bool /*bRead*/)
    {
    }

    bool CChar::WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* serialize, CAttribute* /*att*/)
    {
        // value에 들어가는 금지문자를 Symbol of Signs로 변경
        hncstd::wstring modifiedValue;
        Util::CXMLAttConverter::_Val2SymbolOfSignsStr(this->Getval(), modifiedValue, true);

        serialize->WriteBuffer(modifiedValue.c_str(), modifiedValue.length());
        return TRUE;
    }

    bool CChar::ReadAttribute(CAttribute* /*att*/)
    {
        return TRUE;
    }

    void CChar::Setval(LPCWSTR val)
    {
        if (val == NULL) {
            return;
        }

        m_val.assign(val);
    }


    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  CUnknownChar
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    CUnknownChar* CUnknownChar::Create()
    {
        return new CUnknownChar();
    }

    CUnknownChar::CUnknownChar(WCHAR unchar) : CExtObject(ID_PARA_UnknownChar), m_wUnknownChar(0)
    {
        if (unchar != 0)
            SetUnknownChar(unchar);
    }

    CUnknownChar::~CUnknownChar()
    {
    }

    void CUnknownChar::InitMap(bool /*bRead*/)
    {
    }

    bool CUnknownChar::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        if (m_wUnknownChar)
            Util::CXMLAttConverter::SetAttribute(att, L"unknownchar", (const unsigned short&)m_wUnknownChar);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CUnknownChar::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"unknownchar", (unsigned short&)m_wUnknownChar);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }


}
