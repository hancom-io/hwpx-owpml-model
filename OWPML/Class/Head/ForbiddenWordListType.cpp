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
#include "ForbiddenWordListType.h"

namespace OWPML {

    // CForbiddenWord Declaration 
    CForbiddenWord* CForbiddenWord::Create()
    {
        return new CForbiddenWord();
    }

    CForbiddenWord::CForbiddenWord() : CStringValueObject(ID_HEAD_ForbiddenWord), m_space(NULL)
    {
    }

    CForbiddenWord::~CForbiddenWord()
    {
    }

    void CForbiddenWord::InitMap(bool /*bRead*/)
    {
    }

    bool CForbiddenWord::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return CStringValueObject::WriteElement(pCurObjName, serialize, att);
    }

    bool CForbiddenWord::ReadAttribute(CAttribute* att)
    {
        hncstd::wstring space;
        if (Util::CXMLAttConverter::GetAttribute(att, L"space", space))
            Setspace(space);

        return CStringValueObject::ReadAttribute(att);
    }

    void CForbiddenWord::Setspace(const hncstd::wstring& space)
    {
        if (!m_space)
            m_space = new hncstd::wstring;

        *m_space = space;
    }

    bool CForbiddenWord::Getspace(hncstd::wstring& space) const
    {
        if (!m_space)
            return false;

        space = *m_space;
        return true;
    }



    // CForbiddenWordListType
    OWPML_HEAD_REDIRECT_FUNC(CForbiddenWordListType, forbiddenWord)

        CForbiddenWordListType* CForbiddenWordListType::Create()
    {
        return new CForbiddenWordListType();
    }

    CForbiddenWordListType::CForbiddenWordListType() : CExtObject(ID_HEAD_ForbiddenWordListType), m_uItemCnt(0)
    {
    }

    CForbiddenWordListType::~CForbiddenWordListType()
    {
    }

    void CForbiddenWordListType::InitMap(bool bRead)
    {
        OWPML_BEGIN_IMPLEMENT_FUNCMAP(CForbiddenWordListType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(forbiddenWord, CForbiddenWord, ID_HEAD_ForbiddenWord)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CForbiddenWordListType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CForbiddenWordListType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CForbiddenWord* CForbiddenWordListType::SetforbiddenWord(CForbiddenWord* pforbiddenWord)
    {
        CForbiddenWord* forbiddenWord = pforbiddenWord;
        if (forbiddenWord == NULL) {
            forbiddenWord = CForbiddenWord::Create();
        }
        SetObject((CObject*)forbiddenWord);

        return forbiddenWord;
    }

    CForbiddenWord* CForbiddenWordListType::GetforbiddenWord(int index)
    {
        return static_cast<CForbiddenWord*>(GetObjectByID(ID_HEAD_ForbiddenWord, index));
    }

}
