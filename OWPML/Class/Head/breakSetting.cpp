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
#include "breakSetting.h"

namespace OWPML {


    CBreakSetting* CBreakSetting::Create()
    {
        return new CBreakSetting();
    }

    CBreakSetting::CBreakSetting() : CExtObject(ID_HEAD_BreakSetting), m_bWidowOrphan(false), m_bKeepWithNext(false), m_bKeepLines(false), m_bPageBreakBefore(false), m_uBreakNonLatinWord(0), m_uLineWrap(0)
    {
    }

    CBreakSetting::~CBreakSetting()
    {
    }

    void CBreakSetting::InitMap(bool /*bRead*/)
    {
    }

    bool CBreakSetting::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"breakLatinWord", g_BreakLatinWordList, m_uBreakLatinWord);
        Util::CXMLAttConverter::SetAttribute(att, L"breakNonLatinWord", g_BreakNonLatinWordList, m_uBreakNonLatinWord);
        Util::CXMLAttConverter::SetAttribute(att, L"widowOrphan", m_bWidowOrphan);
        Util::CXMLAttConverter::SetAttribute(att, L"keepWithNext", m_bKeepWithNext);
        Util::CXMLAttConverter::SetAttribute(att, L"keepLines", m_bKeepLines);
        Util::CXMLAttConverter::SetAttribute(att, L"pageBreakBefore", m_bPageBreakBefore);
        Util::CXMLAttConverter::SetAttribute(att, L"lineWrap", g_LineWrapList, m_uLineWrap);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBreakSetting::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"breakLatinWord", g_BreakLatinWordList, m_uBreakLatinWord);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"breakNonLatinWord", g_BreakNonLatinWordList, m_uBreakNonLatinWord);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"widowOrphan", m_bWidowOrphan);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"keepWithNext", m_bKeepWithNext);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"keepLines", m_bKeepLines);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"pageBreakBefore", m_bPageBreakBefore);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"lineWrap", g_LineWrapList, m_uLineWrap);

        return bres;
    }

}
