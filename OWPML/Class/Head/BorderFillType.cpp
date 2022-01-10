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
#include "BorderFillType.h"

namespace OWPML {

    CBorderFillType* CBorderFillType::Create()
    {
        return new CBorderFillType();
    }

    CBorderFillType::CBorderFillType() : CExtObject(ID_HEAD_BorderFillType), m_bThreeD(false), m_bShadow(false), m_bBreakCellSeparateLine(false), m_uCenterLine(0), m_uId(0)
    {
    }

    CBorderFillType::~CBorderFillType()
    {
    }

    void CBorderFillType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, slash)
            OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, backSlash)
            OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, leftBorder)
            OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, rightBorder)
            OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, topBorder)
            OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, bottomBorder)
            OWPML_HEAD_REDIRECT_FUNC(CBorderFillType, diagonal)
            OWPML_CORE_REDIRECT_FUNC(CBorderFillType, fillBrush)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CBorderFillType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(slash, CSlashType, ID_HEAD_SlashType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(backSlash, CSlashType, ID_HEAD_BackSlashType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(leftBorder, CBorderType, ID_HEAD_Left_BorderType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(rightBorder, CBorderType, ID_HEAD_Right_BorderType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(topBorder, CBorderType, ID_HEAD_Top_BorderType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(bottomBorder, CBorderType, ID_HEAD_Bottom_BorderType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(diagonal, CBorderType, ID_HEAD_Diagonal_BorderType)
            OWPML_CORE_ADD_REDIRECT_FUNC(fillBrush, CFillBrushType, ID_CORE_FillBrushType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CBorderFillType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"threeD", m_bThreeD);
        Util::CXMLAttConverter::SetAttribute(att, L"shadow", m_bShadow);
        Util::CXMLAttConverter::SetAttribute(att, L"centerLine", g_CenterLineList, m_uCenterLine);
        Util::CXMLAttConverter::SetAttribute(att, L"breakCellSeparateLine", m_bBreakCellSeparateLine);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBorderFillType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"threeD", m_bThreeD);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"shadow", m_bShadow);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"centerLine", g_CenterLineList, m_uCenterLine);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"breakCellSeparateLine", m_bBreakCellSeparateLine);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CSlashType* CBorderFillType::Setslash(CSlashType* pslash)
    {
        CSlashType* slash = pslash;
        if (slash == NULL) {
            slash = CSlashType::CreateArg(ID_HEAD_SlashType);
        }
        SetObject((CObject*)slash);

        return slash;
    }

    CSlashType* CBorderFillType::Getslash(int index)
    {
        return static_cast<CSlashType*>(GetObjectByID(ID_HEAD_SlashType, index));
    }

    CSlashType* CBorderFillType::SetbackSlash(CSlashType* pbackSlash)
    {
        CSlashType* backSlash = pbackSlash;
        if (backSlash == NULL) {
            backSlash = CSlashType::CreateArg(ID_HEAD_BackSlashType);
        }
        SetObject((CObject*)backSlash);

        return backSlash;
    }

    CSlashType* CBorderFillType::GetbackSlash(int index)
    {
        return static_cast<CSlashType*>(GetObjectByID(ID_HEAD_BackSlashType, index));
    }

    CBorderType* CBorderFillType::SetleftBorder(CBorderType* pleftBorder)
    {
        CBorderType* leftBorder = pleftBorder;
        if (leftBorder == NULL) {
            leftBorder = CBorderType::CreateArg(ID_HEAD_Left_BorderType);
        }
        SetObject((CObject*)leftBorder);

        return leftBorder;
    }

    CBorderType* CBorderFillType::GetleftBorder(int index)
    {
        return static_cast<CBorderType*>(GetObjectByID(ID_HEAD_Left_BorderType, index));
    }

    CBorderType* CBorderFillType::SetrightBorder(CBorderType* prightBorder)
    {
        CBorderType* rightBorder = prightBorder;
        if (rightBorder == NULL) {
            rightBorder = CBorderType::CreateArg(ID_HEAD_Right_BorderType);
        }
        SetObject((CObject*)rightBorder);

        return rightBorder;
    }

    CBorderType* CBorderFillType::GetrightBorder(int index)
    {
        return static_cast<CBorderType*>(GetObjectByID(ID_HEAD_Right_BorderType, index));
    }

    CBorderType* CBorderFillType::SettopBorder(CBorderType* ptopBorder)
    {
        CBorderType* topBorder = ptopBorder;
        if (topBorder == NULL) {
            topBorder = CBorderType::CreateArg(ID_HEAD_Top_BorderType);
        }
        SetObject((CObject*)topBorder);

        return topBorder;
    }

    CBorderType* CBorderFillType::GettopBorder(int index)
    {
        return static_cast<CBorderType*>(GetObjectByID(ID_HEAD_Top_BorderType, index));
    }

    CBorderType* CBorderFillType::SetbottomBorder(CBorderType* pbottomBorder)
    {
        CBorderType* bottomBorder = pbottomBorder;
        if (bottomBorder == NULL) {
            bottomBorder = CBorderType::CreateArg(ID_HEAD_Bottom_BorderType);
        }
        SetObject((CObject*)bottomBorder);

        return bottomBorder;
    }

    CBorderType* CBorderFillType::GetbottomBorder(int index)
    {
        return static_cast<CBorderType*>(GetObjectByID(ID_HEAD_Bottom_BorderType, index));
    }

    CBorderType* CBorderFillType::Setdiagonal(CBorderType* pdiagonal)
    {
        CBorderType* diagonal = pdiagonal;
        if (diagonal == NULL) {
            diagonal = CBorderType::CreateArg(ID_HEAD_Diagonal_BorderType);
        }
        SetObject((CObject*)diagonal);

        return diagonal;
    }

    CBorderType* CBorderFillType::Getdiagonal(int index)
    {
        return static_cast<CBorderType*>(GetObjectByID(ID_HEAD_Diagonal_BorderType, index));
    }

    CFillBrushType* CBorderFillType::SetfillBrush(CFillBrushType* pfillBrush)
    {
        CFillBrushType* fillBrush = pfillBrush;
        if (fillBrush == NULL) {
            fillBrush = CFillBrushType::Create();
        }
        SetObject((CObject*)fillBrush);

        return fillBrush;
    }

    CFillBrushType* CBorderFillType::GetfillBrush(int index)
    {
        return static_cast<CFillBrushType*>(GetObjectByID(ID_CORE_FillBrushType, index));
    }

}
