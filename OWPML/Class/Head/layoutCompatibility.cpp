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
#include "layoutCompatibility.h"

namespace OWPML {

    CLayoutCompatibility* CLayoutCompatibility::Create()
    {
        return new CLayoutCompatibility();
    }

    CLayoutCompatibility::CLayoutCompatibility() : CExtObject(ID_HEAD_LayoutCompatibility)
    {
    }

    CLayoutCompatibility::~CLayoutCompatibility()
    {
    }

    void CLayoutCompatibility::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyFontWeightToBold)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, useInnerUnderline)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, fixedUnderlineWidth)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyStrikeoutWithUnderline)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, useLowercaseStrikeout)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, extendLineheightToOffset)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyFontspaceToLatin)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, treatQuotationAsLatin)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyDiacSymMarkOfNoneAndSix)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotAlignWhitespaceOnRight)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotAdjustWordInJustify)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, baseCharUnitOnEAsian)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, baseCharUnitOfIndentOnFirstChar)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustLineheightToFont)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustBaselineInFixedLinespacing)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyPrevspacingBeneathObject)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyNextspacingOfLastPara)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyAtLeastToPercent100Pct)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyAutoSpaceEAsianEng)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyAutoSpaceEAsianNum)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustParaBorderfillToSpacing)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, connectParaBorderfillOfEqualBorder)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustParaBorderOffsetWithBorder)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, extendLineheightToParaBorderOffset)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyParaBorderToOutside)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyMinColumnWidthTo1mm)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyTabPosBasedOnSegment)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, breakTabOverLine)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustVertPosOfLine)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyWhiteSpaceHeight)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotAlignLastPeriod)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotAlignLastForbidden)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustMarginFromAdjustLineheight)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, baseLineSpacingOnLineGrid)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyCharSpacingToCharGrid)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyGridInHeaderFooter)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, applyExtendHeaderFooterEachSection)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyHeaderFooterAtNoSpace)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyColSeparatorAtNoGap)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyLinegridAtNoLinespacing)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyImageEffect)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyShapeComment)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotAdjustEmptyAnchorLine)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, overlapBothAllowOverlap)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyVertOffsetOfForward)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, extendVertLimitToPageMargins)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotHoldAnchorOfTable)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotFormattingAtBeneathAnchor)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, adjustBaselineOfObjectToBottom)
            OWPML_HEAD_REDIRECT_FUNC(CLayoutCompatibility, doNotApplyExtensionCharCompose)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CLayoutCompatibility)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyFontWeightToBold, CApplyFontWeightToBold, ID_HEAD_ApplyFontWeightToBold)
            OWPML_HEAD_ADD_REDIRECT_FUNC(useInnerUnderline, CUseInnerUnderline, ID_HEAD_UseInnerUnderline)
            OWPML_HEAD_ADD_REDIRECT_FUNC(fixedUnderlineWidth, CFixedUnderlineWidth, ID_HEAD_FixedUnderlineWidth)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyStrikeoutWithUnderline, CDoNotApplyStrikeoutWithUnderline, ID_HEAD_DoNotApplyStrikeoutWithUnderline)
            OWPML_HEAD_ADD_REDIRECT_FUNC(useLowercaseStrikeout, CUseLowercaseStrikeout, ID_HEAD_UseLowercaseStrikeout)
            OWPML_HEAD_ADD_REDIRECT_FUNC(extendLineheightToOffset, CExtendLineheightToOffset, ID_HEAD_ExtendLineheightToOffset)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyFontspaceToLatin, CApplyFontspaceToLatin, ID_HEAD_ApplyFontspaceToLatin)
            OWPML_HEAD_ADD_REDIRECT_FUNC(treatQuotationAsLatin, CTreatQuotationAsLatin, ID_HEAD_TreatQuotationAsLatin)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyDiacSymMarkOfNoneAndSix, CDoNotApplyDiacSymMarkOfNoneAndSix, ID_HEAD_DoNotApplyDiacSymMarkOfNoneAndSix)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotAlignWhitespaceOnRight, CDoNotAlignWhitespaceOnRight, ID_HEAD_DoNotAlignWhitespaceOnRight)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotAdjustWordInJustify, CDoNotAdjustWordInJustify, ID_HEAD_DoNotAdjustWordInJustify)
            OWPML_HEAD_ADD_REDIRECT_FUNC(baseCharUnitOnEAsian, CBaseCharUnitOnEAsian, ID_HEAD_BaseCharUnitOnEAsian)
            OWPML_HEAD_ADD_REDIRECT_FUNC(baseCharUnitOfIndentOnFirstChar, CBaseCharUnitOfIndentOnFirstChar, ID_HEAD_BaseCharUnitOfIndentOnFirstChar)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustLineheightToFont, CAdjustLineheightToFont, ID_HEAD_AdjustLineheightToFont)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustBaselineInFixedLinespacing, CAdjustBaselineInFixedLinespacing, ID_HEAD_AdjustBaselineInFixedLinespacing)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyPrevspacingBeneathObject, CApplyPrevspacingBeneathObject, ID_HEAD_ApplyPrevspacingBeneathObject)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyNextspacingOfLastPara, CApplyNextspacingOfLastPara, ID_HEAD_ApplyNextspacingOfLastPara)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyAtLeastToPercent100Pct, CApplyAtLeastToPercent100Pct, ID_HEAD_ApplyAtLeastToPercent100Pct)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyAutoSpaceEAsianEng, CDoNotApplyAutoSpaceEAsianEng, ID_HEAD_DoNotApplyAutoSpaceEAsianEng)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyAutoSpaceEAsianNum, CDoNotApplyAutoSpaceEAsianNum, ID_HEAD_DoNotApplyAutoSpaceEAsianNum)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustParaBorderfillToSpacing, CAdjustParaBorderfillToSpacing, ID_HEAD_AdjustParaBorderfillToSpacing)
            OWPML_HEAD_ADD_REDIRECT_FUNC(connectParaBorderfillOfEqualBorder, CConnectParaBorderfillOfEqualBorder, ID_HEAD_ConnectParaBorderfillOfEqualBorder)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustParaBorderOffsetWithBorder, CAdjustParaBorderOffsetWithBorder, ID_HEAD_AdjustParaBorderOffsetWithBorder)
            OWPML_HEAD_ADD_REDIRECT_FUNC(extendLineheightToParaBorderOffset, CExtendLineheightToParaBorderOffset, ID_HEAD_ExtendLineheightToParaBorderOffset)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyParaBorderToOutside, CApplyParaBorderToOutside, ID_HEAD_ApplyParaBorderToOutside)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyMinColumnWidthTo1mm, CApplyMinColumnWidthTo1mm, ID_HEAD_ApplyMinColumnWidthTo1mm)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyTabPosBasedOnSegment, CApplyTabPosBasedOnSegment, ID_HEAD_ApplyTabPosBasedOnSegment)
            OWPML_HEAD_ADD_REDIRECT_FUNC(breakTabOverLine, CBreakTabOverLine, ID_HEAD_BreakTabOverLine)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustVertPosOfLine, CAdjustVertPosOfLine, ID_HEAD_AdjustVertPosOfLine)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyWhiteSpaceHeight, CDoNotApplyWhiteSpaceHeight, ID_HEAD_DoNotApplyWhiteSpaceHeight)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotAlignLastPeriod, CDoNotAlignLastPeriod, ID_HEAD_DoNotAlignLastPeriod)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotAlignLastForbidden, CDoNotAlignLastForbidden, ID_HEAD_DoNotAlignLastForbidden)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustMarginFromAdjustLineheight, CAdjustMarginFromAdjustLineheight, ID_HEAD_AdjustMarginFromAdjustLineheight)
            OWPML_HEAD_ADD_REDIRECT_FUNC(baseLineSpacingOnLineGrid, CBaseLineSpacingOnLineGrid, ID_HEAD_BaseLineSpacingOnLineGrid)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyCharSpacingToCharGrid, CApplyCharSpacingToCharGrid, ID_HEAD_ApplyCharSpacingToCharGrid)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyGridInHeaderFooter, CDoNotApplyGridInHeaderFooter, ID_HEAD_DoNotApplyGridInHeaderFooter)
            OWPML_HEAD_ADD_REDIRECT_FUNC(applyExtendHeaderFooterEachSection, CApplyExtendHeaderFooterEachSection, ID_HEAD_ApplyExtendHeaderFooterEachSection)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyHeaderFooterAtNoSpace, CDoNotApplyHeaderFooterAtNoSpace, ID_HEAD_DoNotApplyHeaderFooterAtNoSpace)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyColSeparatorAtNoGap, CDoNotApplyColSeparatorAtNoGap, ID_HEAD_DoNotApplyColSeparatorAtNoGap)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyLinegridAtNoLinespacing, CDoNotApplyLinegridAtNoLinespacing, ID_HEAD_DoNotApplyLinegridAtNoLinespacing)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyImageEffect, CDoNotApplyImageEffect, ID_HEAD_DoNotApplyImageEffect)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyShapeComment, CDoNotApplyShapeComment, ID_HEAD_DoNotApplyShapeComment)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotAdjustEmptyAnchorLine, CDoNotAdjustEmptyAnchorLine, ID_HEAD_DoNotAdjustEmptyAnchorLine)
            OWPML_HEAD_ADD_REDIRECT_FUNC(overlapBothAllowOverlap, COverlapBothAllowOverlap, ID_HEAD_OverlapBothAllowOverlap)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyVertOffsetOfForward, CDoNotApplyVertOffsetOfForward, ID_HEAD_DoNotApplyVertOffsetOfForward)
            OWPML_HEAD_ADD_REDIRECT_FUNC(extendVertLimitToPageMargins, CExtendVertLimitToPageMargins, ID_HEAD_ExtendVertLimitToPageMargins)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotHoldAnchorOfTable, CDoNotHoldAnchorOfTable, ID_HEAD_DoNotHoldAnchorOfTable)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotFormattingAtBeneathAnchor, CDoNotFormattingAtBeneathAnchor, ID_HEAD_DoNotFormattingAtBeneathAnchor)
            OWPML_HEAD_ADD_REDIRECT_FUNC(adjustBaselineOfObjectToBottom, CAdjustBaselineOfObjectToBottom, ID_HEAD_AdjustBaselineOfObjectToBottom)
            OWPML_HEAD_ADD_REDIRECT_FUNC(doNotApplyExtensionCharCompose, CDoNotApplyExtensionCharCompose, ID_HEAD_DoNotApplyExtensionCharCompose)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CLayoutCompatibility::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CLayoutCompatibility::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CApplyFontWeightToBold* CLayoutCompatibility::SetapplyFontWeightToBold(CApplyFontWeightToBold* papplyFontWeightToBold)
    {
        CApplyFontWeightToBold* applyFontWeightToBold = papplyFontWeightToBold;
        if (applyFontWeightToBold == NULL) {
            applyFontWeightToBold = CApplyFontWeightToBold::Create();
        }
        SetObject((CObject*)applyFontWeightToBold);

        return applyFontWeightToBold;
    }

    CApplyFontWeightToBold* CLayoutCompatibility::GetapplyFontWeightToBold(int index)
    {
        return static_cast<CApplyFontWeightToBold*>(GetObjectByID(ID_HEAD_ApplyFontWeightToBold, index));
    }

    CUseInnerUnderline* CLayoutCompatibility::SetuseInnerUnderline(CUseInnerUnderline* puseInnerUnderline)
    {
        CUseInnerUnderline* useInnerUnderline = puseInnerUnderline;
        if (useInnerUnderline == NULL) {
            useInnerUnderline = CUseInnerUnderline::Create();
        }
        SetObject((CObject*)useInnerUnderline);

        return useInnerUnderline;
    }

    CUseInnerUnderline* CLayoutCompatibility::GetuseInnerUnderline(int index)
    {
        return static_cast<CUseInnerUnderline*>(GetObjectByID(ID_HEAD_UseInnerUnderline, index));
    }

    CFixedUnderlineWidth* CLayoutCompatibility::SetfixedUnderlineWidth(CFixedUnderlineWidth* pfixedUnderlineWidth)
    {
        CFixedUnderlineWidth* fixedUnderlineWidth = pfixedUnderlineWidth;
        if (fixedUnderlineWidth == NULL) {
            fixedUnderlineWidth = CFixedUnderlineWidth::Create();
        }
        SetObject((CObject*)fixedUnderlineWidth);

        return fixedUnderlineWidth;
    }

    CFixedUnderlineWidth* CLayoutCompatibility::GetfixedUnderlineWidth(int index)
    {
        return static_cast<CFixedUnderlineWidth*>(GetObjectByID(ID_HEAD_FixedUnderlineWidth, index));
    }

    CDoNotApplyStrikeoutWithUnderline* CLayoutCompatibility::SetdoNotApplyStrikeoutWithUnderline(CDoNotApplyStrikeoutWithUnderline* pdoNotApplyStrikeoutWithUnderline)
    {
        CDoNotApplyStrikeoutWithUnderline* doNotApplyStrikeoutWithUnderline = pdoNotApplyStrikeoutWithUnderline;
        if (doNotApplyStrikeoutWithUnderline == NULL) {
            doNotApplyStrikeoutWithUnderline = CDoNotApplyStrikeoutWithUnderline::Create();
        }
        SetObject((CObject*)doNotApplyStrikeoutWithUnderline);

        return doNotApplyStrikeoutWithUnderline;
    }

    CDoNotApplyStrikeoutWithUnderline* CLayoutCompatibility::GetdoNotApplyStrikeoutWithUnderline(int index)
    {
        return static_cast<CDoNotApplyStrikeoutWithUnderline*>(GetObjectByID(ID_HEAD_DoNotApplyStrikeoutWithUnderline, index));
    }

    CUseLowercaseStrikeout* CLayoutCompatibility::SetuseLowercaseStrikeout(CUseLowercaseStrikeout* puseLowercaseStrikeout)
    {
        CUseLowercaseStrikeout* useLowercaseStrikeout = puseLowercaseStrikeout;
        if (useLowercaseStrikeout == NULL) {
            useLowercaseStrikeout = CUseLowercaseStrikeout::Create();
        }
        SetObject((CObject*)useLowercaseStrikeout);

        return useLowercaseStrikeout;
    }

    CUseLowercaseStrikeout* CLayoutCompatibility::GetuseLowercaseStrikeout(int index)
    {
        return static_cast<CUseLowercaseStrikeout*>(GetObjectByID(ID_HEAD_UseLowercaseStrikeout, index));
    }

    CExtendLineheightToOffset* CLayoutCompatibility::SetextendLineheightToOffset(CExtendLineheightToOffset* pextendLineheightToOffset)
    {
        CExtendLineheightToOffset* extendLineheightToOffset = pextendLineheightToOffset;
        if (extendLineheightToOffset == NULL) {
            extendLineheightToOffset = CExtendLineheightToOffset::Create();
        }
        SetObject((CObject*)extendLineheightToOffset);

        return extendLineheightToOffset;
    }

    CExtendLineheightToOffset* CLayoutCompatibility::GetextendLineheightToOffset(int index)
    {
        return static_cast<CExtendLineheightToOffset*>(GetObjectByID(ID_HEAD_ExtendLineheightToOffset, index));
    }

    CApplyFontspaceToLatin* CLayoutCompatibility::SetapplyFontspaceToLatin(CApplyFontspaceToLatin* papplyFontspaceToLatin)
    {
        CApplyFontspaceToLatin* applyFontspaceToLatin = papplyFontspaceToLatin;
        if (applyFontspaceToLatin == NULL) {
            applyFontspaceToLatin = CApplyFontspaceToLatin::Create();
        }
        SetObject((CObject*)applyFontspaceToLatin);

        return applyFontspaceToLatin;
    }

    CApplyFontspaceToLatin* CLayoutCompatibility::GetapplyFontspaceToLatin(int index)
    {
        return static_cast<CApplyFontspaceToLatin*>(GetObjectByID(ID_HEAD_ApplyFontspaceToLatin, index));
    }

    CTreatQuotationAsLatin* CLayoutCompatibility::SettreatQuotationAsLatin(CTreatQuotationAsLatin* ptreatQuotationAsLatin)
    {
        CTreatQuotationAsLatin* treatQuotationAsLatin = ptreatQuotationAsLatin;
        if (treatQuotationAsLatin == NULL) {
            treatQuotationAsLatin = CTreatQuotationAsLatin::Create();
        }
        SetObject((CObject*)treatQuotationAsLatin);

        return treatQuotationAsLatin;
    }

    CTreatQuotationAsLatin* CLayoutCompatibility::GettreatQuotationAsLatin(int index)
    {
        return static_cast<CTreatQuotationAsLatin*>(GetObjectByID(ID_HEAD_TreatQuotationAsLatin, index));
    }

    CDoNotApplyDiacSymMarkOfNoneAndSix* CLayoutCompatibility::SetdoNotApplyDiacSymMarkOfNoneAndSix(CDoNotApplyDiacSymMarkOfNoneAndSix* pdoNotApplyDiacSymMarkOfNoneAndSix)
    {
        CDoNotApplyDiacSymMarkOfNoneAndSix* doNotApplyDiacSymMarkOfNoneAndSix = pdoNotApplyDiacSymMarkOfNoneAndSix;
        if (doNotApplyDiacSymMarkOfNoneAndSix == NULL) {
            doNotApplyDiacSymMarkOfNoneAndSix = CDoNotApplyDiacSymMarkOfNoneAndSix::Create();
        }
        SetObject((CObject*)doNotApplyDiacSymMarkOfNoneAndSix);

        return doNotApplyDiacSymMarkOfNoneAndSix;
    }

    CDoNotApplyDiacSymMarkOfNoneAndSix* CLayoutCompatibility::GetdoNotApplyDiacSymMarkOfNoneAndSix(int index)
    {
        return static_cast<CDoNotApplyDiacSymMarkOfNoneAndSix*>(GetObjectByID(ID_HEAD_DoNotApplyDiacSymMarkOfNoneAndSix, index));
    }

    CDoNotAlignWhitespaceOnRight* CLayoutCompatibility::SetdoNotAlignWhitespaceOnRight(CDoNotAlignWhitespaceOnRight* pdoNotAlignWhitespaceOnRight)
    {
        CDoNotAlignWhitespaceOnRight* doNotAlignWhitespaceOnRight = pdoNotAlignWhitespaceOnRight;
        if (doNotAlignWhitespaceOnRight == NULL) {
            doNotAlignWhitespaceOnRight = CDoNotAlignWhitespaceOnRight::Create();
        }
        SetObject((CObject*)doNotAlignWhitespaceOnRight);

        return doNotAlignWhitespaceOnRight;
    }

    CDoNotAlignWhitespaceOnRight* CLayoutCompatibility::GetdoNotAlignWhitespaceOnRight(int index)
    {
        return static_cast<CDoNotAlignWhitespaceOnRight*>(GetObjectByID(ID_HEAD_DoNotAlignWhitespaceOnRight, index));
    }

    CDoNotAdjustWordInJustify* CLayoutCompatibility::SetdoNotAdjustWordInJustify(CDoNotAdjustWordInJustify* pdoNotAdjustWordInJustify)
    {
        CDoNotAdjustWordInJustify* doNotAdjustWordInJustify = pdoNotAdjustWordInJustify;
        if (doNotAdjustWordInJustify == NULL) {
            doNotAdjustWordInJustify = CDoNotAdjustWordInJustify::Create();
        }
        SetObject((CObject*)doNotAdjustWordInJustify);

        return doNotAdjustWordInJustify;
    }

    CDoNotAdjustWordInJustify* CLayoutCompatibility::GetdoNotAdjustWordInJustify(int index)
    {
        return static_cast<CDoNotAdjustWordInJustify*>(GetObjectByID(ID_HEAD_DoNotAdjustWordInJustify, index));
    }

    CBaseCharUnitOnEAsian* CLayoutCompatibility::SetbaseCharUnitOnEAsian(CBaseCharUnitOnEAsian* pbaseCharUnitOnEAsian)
    {
        CBaseCharUnitOnEAsian* baseCharUnitOnEAsian = pbaseCharUnitOnEAsian;
        if (baseCharUnitOnEAsian == NULL) {
            baseCharUnitOnEAsian = CBaseCharUnitOnEAsian::Create();
        }
        SetObject((CObject*)baseCharUnitOnEAsian);

        return baseCharUnitOnEAsian;
    }

    CBaseCharUnitOnEAsian* CLayoutCompatibility::GetbaseCharUnitOnEAsian(int index)
    {
        return static_cast<CBaseCharUnitOnEAsian*>(GetObjectByID(ID_HEAD_BaseCharUnitOnEAsian, index));
    }

    CBaseCharUnitOfIndentOnFirstChar* CLayoutCompatibility::SetbaseCharUnitOfIndentOnFirstChar(CBaseCharUnitOfIndentOnFirstChar* pbaseCharUnitOfIndentOnFirstChar)
    {
        CBaseCharUnitOfIndentOnFirstChar* baseCharUnitOfIndentOnFirstChar = pbaseCharUnitOfIndentOnFirstChar;
        if (baseCharUnitOfIndentOnFirstChar == NULL) {
            baseCharUnitOfIndentOnFirstChar = CBaseCharUnitOfIndentOnFirstChar::Create();
        }
        SetObject((CObject*)baseCharUnitOfIndentOnFirstChar);

        return baseCharUnitOfIndentOnFirstChar;
    }

    CBaseCharUnitOfIndentOnFirstChar* CLayoutCompatibility::GetbaseCharUnitOfIndentOnFirstChar(int index)
    {
        return static_cast<CBaseCharUnitOfIndentOnFirstChar*>(GetObjectByID(ID_HEAD_BaseCharUnitOfIndentOnFirstChar, index));
    }

    CAdjustLineheightToFont* CLayoutCompatibility::SetadjustLineheightToFont(CAdjustLineheightToFont* padjustLineheightToFont)
    {
        CAdjustLineheightToFont* adjustLineheightToFont = padjustLineheightToFont;
        if (adjustLineheightToFont == NULL) {
            adjustLineheightToFont = CAdjustLineheightToFont::Create();
        }
        SetObject((CObject*)adjustLineheightToFont);

        return adjustLineheightToFont;
    }

    CAdjustLineheightToFont* CLayoutCompatibility::GetadjustLineheightToFont(int index)
    {
        return static_cast<CAdjustLineheightToFont*>(GetObjectByID(ID_HEAD_AdjustLineheightToFont, index));
    }

    CAdjustBaselineInFixedLinespacing* CLayoutCompatibility::SetadjustBaselineInFixedLinespacing(CAdjustBaselineInFixedLinespacing* padjustBaselineInFixedLinespacing)
    {
        CAdjustBaselineInFixedLinespacing* adjustBaselineInFixedLinespacing = padjustBaselineInFixedLinespacing;
        if (adjustBaselineInFixedLinespacing == NULL) {
            adjustBaselineInFixedLinespacing = CAdjustBaselineInFixedLinespacing::Create();
        }
        SetObject((CObject*)adjustBaselineInFixedLinespacing);

        return adjustBaselineInFixedLinespacing;
    }

    CAdjustBaselineInFixedLinespacing* CLayoutCompatibility::GetadjustBaselineInFixedLinespacing(int index)
    {
        return static_cast<CAdjustBaselineInFixedLinespacing*>(GetObjectByID(ID_HEAD_AdjustBaselineInFixedLinespacing, index));
    }

    CApplyPrevspacingBeneathObject* CLayoutCompatibility::SetapplyPrevspacingBeneathObject(CApplyPrevspacingBeneathObject* papplyPrevspacingBeneathObject)
    {
        CApplyPrevspacingBeneathObject* applyPrevspacingBeneathObject = papplyPrevspacingBeneathObject;
        if (applyPrevspacingBeneathObject == NULL) {
            applyPrevspacingBeneathObject = CApplyPrevspacingBeneathObject::Create();
        }
        SetObject((CObject*)applyPrevspacingBeneathObject);

        return applyPrevspacingBeneathObject;
    }

    CApplyPrevspacingBeneathObject* CLayoutCompatibility::GetapplyPrevspacingBeneathObject(int index)
    {
        return static_cast<CApplyPrevspacingBeneathObject*>(GetObjectByID(ID_HEAD_ApplyPrevspacingBeneathObject, index));
    }

    CApplyNextspacingOfLastPara* CLayoutCompatibility::SetapplyNextspacingOfLastPara(CApplyNextspacingOfLastPara* papplyNextspacingOfLastPara)
    {
        CApplyNextspacingOfLastPara* applyNextspacingOfLastPara = papplyNextspacingOfLastPara;
        if (applyNextspacingOfLastPara == NULL) {
            applyNextspacingOfLastPara = CApplyNextspacingOfLastPara::Create();
        }
        SetObject((CObject*)applyNextspacingOfLastPara);

        return applyNextspacingOfLastPara;
    }

    CApplyNextspacingOfLastPara* CLayoutCompatibility::GetapplyNextspacingOfLastPara(int index)
    {
        return static_cast<CApplyNextspacingOfLastPara*>(GetObjectByID(ID_HEAD_ApplyNextspacingOfLastPara, index));
    }

    CApplyAtLeastToPercent100Pct* CLayoutCompatibility::SetapplyAtLeastToPercent100Pct(CApplyAtLeastToPercent100Pct* papplyAtLeastToPercent100Pct)
    {
        CApplyAtLeastToPercent100Pct* applyAtLeastToPercent100Pct = papplyAtLeastToPercent100Pct;
        if (applyAtLeastToPercent100Pct == NULL) {
            applyAtLeastToPercent100Pct = CApplyAtLeastToPercent100Pct::Create();
        }
        SetObject((CObject*)applyAtLeastToPercent100Pct);

        return applyAtLeastToPercent100Pct;
    }

    CApplyAtLeastToPercent100Pct* CLayoutCompatibility::GetapplyAtLeastToPercent100Pct(int index)
    {
        return static_cast<CApplyAtLeastToPercent100Pct*>(GetObjectByID(ID_HEAD_ApplyAtLeastToPercent100Pct, index));
    }

    CDoNotApplyAutoSpaceEAsianEng* CLayoutCompatibility::SetdoNotApplyAutoSpaceEAsianEng(CDoNotApplyAutoSpaceEAsianEng* pdoNotApplyAutoSpaceEAsianEng)
    {
        CDoNotApplyAutoSpaceEAsianEng* doNotApplyAutoSpaceEAsianEng = pdoNotApplyAutoSpaceEAsianEng;
        if (doNotApplyAutoSpaceEAsianEng == NULL) {
            doNotApplyAutoSpaceEAsianEng = CDoNotApplyAutoSpaceEAsianEng::Create();
        }
        SetObject((CObject*)doNotApplyAutoSpaceEAsianEng);

        return doNotApplyAutoSpaceEAsianEng;
    }

    CDoNotApplyAutoSpaceEAsianEng* CLayoutCompatibility::GetdoNotApplyAutoSpaceEAsianEng(int index)
    {
        return static_cast<CDoNotApplyAutoSpaceEAsianEng*>(GetObjectByID(ID_HEAD_DoNotApplyAutoSpaceEAsianEng, index));
    }

    CDoNotApplyAutoSpaceEAsianNum* CLayoutCompatibility::SetdoNotApplyAutoSpaceEAsianNum(CDoNotApplyAutoSpaceEAsianNum* pdoNotApplyAutoSpaceEAsianNum)
    {
        CDoNotApplyAutoSpaceEAsianNum* doNotApplyAutoSpaceEAsianNum = pdoNotApplyAutoSpaceEAsianNum;
        if (doNotApplyAutoSpaceEAsianNum == NULL) {
            doNotApplyAutoSpaceEAsianNum = CDoNotApplyAutoSpaceEAsianNum::Create();
        }
        SetObject((CObject*)doNotApplyAutoSpaceEAsianNum);

        return doNotApplyAutoSpaceEAsianNum;
    }

    CDoNotApplyAutoSpaceEAsianNum* CLayoutCompatibility::GetdoNotApplyAutoSpaceEAsianNum(int index)
    {
        return static_cast<CDoNotApplyAutoSpaceEAsianNum*>(GetObjectByID(ID_HEAD_DoNotApplyAutoSpaceEAsianNum, index));
    }

    CAdjustParaBorderfillToSpacing* CLayoutCompatibility::SetadjustParaBorderfillToSpacing(CAdjustParaBorderfillToSpacing* padjustParaBorderfillToSpacing)
    {
        CAdjustParaBorderfillToSpacing* adjustParaBorderfillToSpacing = padjustParaBorderfillToSpacing;
        if (adjustParaBorderfillToSpacing == NULL) {
            adjustParaBorderfillToSpacing = CAdjustParaBorderfillToSpacing::Create();
        }
        SetObject((CObject*)adjustParaBorderfillToSpacing);

        return adjustParaBorderfillToSpacing;
    }

    CAdjustParaBorderfillToSpacing* CLayoutCompatibility::GetadjustParaBorderfillToSpacing(int index)
    {
        return static_cast<CAdjustParaBorderfillToSpacing*>(GetObjectByID(ID_HEAD_AdjustParaBorderfillToSpacing, index));
    }

    CConnectParaBorderfillOfEqualBorder* CLayoutCompatibility::SetconnectParaBorderfillOfEqualBorder(CConnectParaBorderfillOfEqualBorder* pconnectParaBorderfillOfEqualBorder)
    {
        CConnectParaBorderfillOfEqualBorder* connectParaBorderfillOfEqualBorder = pconnectParaBorderfillOfEqualBorder;
        if (connectParaBorderfillOfEqualBorder == NULL) {
            connectParaBorderfillOfEqualBorder = CConnectParaBorderfillOfEqualBorder::Create();
        }
        SetObject((CObject*)connectParaBorderfillOfEqualBorder);

        return connectParaBorderfillOfEqualBorder;
    }

    CConnectParaBorderfillOfEqualBorder* CLayoutCompatibility::GetconnectParaBorderfillOfEqualBorder(int index)
    {
        return static_cast<CConnectParaBorderfillOfEqualBorder*>(GetObjectByID(ID_HEAD_ConnectParaBorderfillOfEqualBorder, index));
    }

    CAdjustParaBorderOffsetWithBorder* CLayoutCompatibility::SetadjustParaBorderOffsetWithBorder(CAdjustParaBorderOffsetWithBorder* padjustParaBorderOffsetWithBorder)
    {
        CAdjustParaBorderOffsetWithBorder* adjustParaBorderOffsetWithBorder = padjustParaBorderOffsetWithBorder;
        if (adjustParaBorderOffsetWithBorder == NULL) {
            adjustParaBorderOffsetWithBorder = CAdjustParaBorderOffsetWithBorder::Create();
        }
        SetObject((CObject*)adjustParaBorderOffsetWithBorder);

        return adjustParaBorderOffsetWithBorder;
    }

    CAdjustParaBorderOffsetWithBorder* CLayoutCompatibility::GetadjustParaBorderOffsetWithBorder(int index)
    {
        return static_cast<CAdjustParaBorderOffsetWithBorder*>(GetObjectByID(ID_HEAD_AdjustParaBorderOffsetWithBorder, index));
    }

    CExtendLineheightToParaBorderOffset* CLayoutCompatibility::SetextendLineheightToParaBorderOffset(CExtendLineheightToParaBorderOffset* pextendLineheightToParaBorderOffset)
    {
        CExtendLineheightToParaBorderOffset* extendLineheightToParaBorderOffset = pextendLineheightToParaBorderOffset;
        if (extendLineheightToParaBorderOffset == NULL) {
            extendLineheightToParaBorderOffset = CExtendLineheightToParaBorderOffset::Create();
        }
        SetObject((CObject*)extendLineheightToParaBorderOffset);

        return extendLineheightToParaBorderOffset;
    }

    CExtendLineheightToParaBorderOffset* CLayoutCompatibility::GetextendLineheightToParaBorderOffset(int index)
    {
        return static_cast<CExtendLineheightToParaBorderOffset*>(GetObjectByID(ID_HEAD_ExtendLineheightToParaBorderOffset, index));
    }

    CApplyParaBorderToOutside* CLayoutCompatibility::SetapplyParaBorderToOutside(CApplyParaBorderToOutside* papplyParaBorderToOutside)
    {
        CApplyParaBorderToOutside* applyParaBorderToOutside = papplyParaBorderToOutside;
        if (applyParaBorderToOutside == NULL) {
            applyParaBorderToOutside = CApplyParaBorderToOutside::Create();
        }
        SetObject((CObject*)applyParaBorderToOutside);

        return applyParaBorderToOutside;
    }

    CApplyParaBorderToOutside* CLayoutCompatibility::GetapplyParaBorderToOutside(int index)
    {
        return static_cast<CApplyParaBorderToOutside*>(GetObjectByID(ID_HEAD_ApplyParaBorderToOutside, index));
    }

    CApplyMinColumnWidthTo1mm* CLayoutCompatibility::SetapplyMinColumnWidthTo1mm(CApplyMinColumnWidthTo1mm* papplyMinColumnWidthTo1mm)
    {
        CApplyMinColumnWidthTo1mm* applyMinColumnWidthTo1mm = papplyMinColumnWidthTo1mm;
        if (applyMinColumnWidthTo1mm == NULL) {
            applyMinColumnWidthTo1mm = CApplyMinColumnWidthTo1mm::Create();
        }
        SetObject((CObject*)applyMinColumnWidthTo1mm);

        return applyMinColumnWidthTo1mm;
    }

    CApplyMinColumnWidthTo1mm* CLayoutCompatibility::GetapplyMinColumnWidthTo1mm(int index)
    {
        return static_cast<CApplyMinColumnWidthTo1mm*>(GetObjectByID(ID_HEAD_ApplyMinColumnWidthTo1mm, index));
    }

    CApplyTabPosBasedOnSegment* CLayoutCompatibility::SetapplyTabPosBasedOnSegment(CApplyTabPosBasedOnSegment* papplyTabPosBasedOnSegment)
    {
        CApplyTabPosBasedOnSegment* applyTabPosBasedOnSegment = papplyTabPosBasedOnSegment;
        if (applyTabPosBasedOnSegment == NULL) {
            applyTabPosBasedOnSegment = CApplyTabPosBasedOnSegment::Create();
        }
        SetObject((CObject*)applyTabPosBasedOnSegment);

        return applyTabPosBasedOnSegment;
    }

    CApplyTabPosBasedOnSegment* CLayoutCompatibility::GetapplyTabPosBasedOnSegment(int index)
    {
        return static_cast<CApplyTabPosBasedOnSegment*>(GetObjectByID(ID_HEAD_ApplyTabPosBasedOnSegment, index));
    }

    CBreakTabOverLine* CLayoutCompatibility::SetbreakTabOverLine(CBreakTabOverLine* pbreakTabOverLine)
    {
        CBreakTabOverLine* breakTabOverLine = pbreakTabOverLine;
        if (breakTabOverLine == NULL) {
            breakTabOverLine = CBreakTabOverLine::Create();
        }
        SetObject((CObject*)breakTabOverLine);

        return breakTabOverLine;
    }

    CBreakTabOverLine* CLayoutCompatibility::GetbreakTabOverLine(int index)
    {
        return static_cast<CBreakTabOverLine*>(GetObjectByID(ID_HEAD_BreakTabOverLine, index));
    }

    CAdjustVertPosOfLine* CLayoutCompatibility::SetadjustVertPosOfLine(CAdjustVertPosOfLine* padjustVertPosOfLine)
    {
        CAdjustVertPosOfLine* adjustVertPosOfLine = padjustVertPosOfLine;
        if (adjustVertPosOfLine == NULL) {
            adjustVertPosOfLine = CAdjustVertPosOfLine::Create();
        }
        SetObject((CObject*)adjustVertPosOfLine);

        return adjustVertPosOfLine;
    }

    CAdjustVertPosOfLine* CLayoutCompatibility::GetadjustVertPosOfLine(int index)
    {
        return static_cast<CAdjustVertPosOfLine*>(GetObjectByID(ID_HEAD_AdjustVertPosOfLine, index));
    }

    CDoNotApplyWhiteSpaceHeight* CLayoutCompatibility::SetdoNotApplyWhiteSpaceHeight(CDoNotApplyWhiteSpaceHeight* pdoNotApplyWhiteSpaceHeight)
    {
        CDoNotApplyWhiteSpaceHeight* doNotApplyWhiteSpaceHeight = pdoNotApplyWhiteSpaceHeight;
        if (doNotApplyWhiteSpaceHeight == NULL) {
            doNotApplyWhiteSpaceHeight = CDoNotApplyWhiteSpaceHeight::Create();
        }
        SetObject((CObject*)doNotApplyWhiteSpaceHeight);

        return doNotApplyWhiteSpaceHeight;
    }

    CDoNotApplyWhiteSpaceHeight* CLayoutCompatibility::GetdoNotApplyWhiteSpaceHeight(int index)
    {
        return static_cast<CDoNotApplyWhiteSpaceHeight*>(GetObjectByID(ID_HEAD_DoNotApplyWhiteSpaceHeight, index));
    }

    CDoNotAlignLastPeriod* CLayoutCompatibility::SetdoNotAlignLastPeriod(CDoNotAlignLastPeriod* pdoNotAlignLastPeriod)
    {
        CDoNotAlignLastPeriod* doNotAlignLastPeriod = pdoNotAlignLastPeriod;
        if (doNotAlignLastPeriod == NULL) {
            doNotAlignLastPeriod = CDoNotAlignLastPeriod::Create();
        }
        SetObject((CObject*)doNotAlignLastPeriod);

        return doNotAlignLastPeriod;
    }

    CDoNotAlignLastPeriod* CLayoutCompatibility::GetdoNotAlignLastPeriod(int index)
    {
        return static_cast<CDoNotAlignLastPeriod*>(GetObjectByID(ID_HEAD_DoNotAlignLastPeriod, index));
    }

    CDoNotAlignLastForbidden* CLayoutCompatibility::SetdoNotAlignLastForbidden(CDoNotAlignLastForbidden* pdoNotAlignLastForbidden)
    {
        CDoNotAlignLastForbidden* doNotAlignLastForbidden = pdoNotAlignLastForbidden;
        if (doNotAlignLastForbidden == NULL) {
            doNotAlignLastForbidden = CDoNotAlignLastForbidden::Create();
        }
        SetObject((CObject*)doNotAlignLastForbidden);

        return doNotAlignLastForbidden;
    }

    CDoNotAlignLastForbidden* CLayoutCompatibility::GetdoNotAlignLastForbidden(int index)
    {
        return static_cast<CDoNotAlignLastForbidden*>(GetObjectByID(ID_HEAD_DoNotAlignLastForbidden, index));
    }

    CAdjustMarginFromAdjustLineheight* CLayoutCompatibility::SetadjustMarginFromAdjustLineheight(CAdjustMarginFromAdjustLineheight* padjustMarginFromAdjustLineheight)
    {
        CAdjustMarginFromAdjustLineheight* adjustMarginFromAdjustLineheight = padjustMarginFromAdjustLineheight;
        if (adjustMarginFromAdjustLineheight == NULL) {
            adjustMarginFromAdjustLineheight = CAdjustMarginFromAdjustLineheight::Create();
        }
        SetObject((CObject*)adjustMarginFromAdjustLineheight);

        return adjustMarginFromAdjustLineheight;

    }

    CAdjustMarginFromAdjustLineheight* CLayoutCompatibility::GetadjustMarginFromAdjustLineheight(int index)
    {
        return static_cast<CAdjustMarginFromAdjustLineheight*>(GetObjectByID(ID_HEAD_AdjustMarginFromAdjustLineheight, index));
    }

    CBaseLineSpacingOnLineGrid* CLayoutCompatibility::SetbaseLineSpacingOnLineGrid(CBaseLineSpacingOnLineGrid* pbaseLineSpacingOnLineGrid)
    {
        CBaseLineSpacingOnLineGrid* baseLineSpacingOnLineGrid = pbaseLineSpacingOnLineGrid;
        if (baseLineSpacingOnLineGrid == NULL) {
            baseLineSpacingOnLineGrid = CBaseLineSpacingOnLineGrid::Create();
        }
        SetObject((CObject*)baseLineSpacingOnLineGrid);

        return baseLineSpacingOnLineGrid;
    }

    CBaseLineSpacingOnLineGrid* CLayoutCompatibility::GetbaseLineSpacingOnLineGrid(int index)
    {
        return static_cast<CBaseLineSpacingOnLineGrid*>(GetObjectByID(ID_HEAD_BaseLineSpacingOnLineGrid, index));
    }

    CApplyCharSpacingToCharGrid* CLayoutCompatibility::SetapplyCharSpacingToCharGrid(CApplyCharSpacingToCharGrid* papplyCharSpacingToCharGrid)
    {
        CApplyCharSpacingToCharGrid* applyCharSpacingToCharGrid = papplyCharSpacingToCharGrid;
        if (applyCharSpacingToCharGrid == NULL) {
            applyCharSpacingToCharGrid = CApplyCharSpacingToCharGrid::Create();
        }
        SetObject((CObject*)applyCharSpacingToCharGrid);

        return applyCharSpacingToCharGrid;
    }

    CApplyCharSpacingToCharGrid* CLayoutCompatibility::GetapplyCharSpacingToCharGrid(int index)
    {
        return static_cast<CApplyCharSpacingToCharGrid*>(GetObjectByID(ID_HEAD_ApplyCharSpacingToCharGrid, index));
    }

    CDoNotApplyGridInHeaderFooter* CLayoutCompatibility::SetdoNotApplyGridInHeaderFooter(CDoNotApplyGridInHeaderFooter* pdoNotApplyGridInHeaderFooter)
    {
        CDoNotApplyGridInHeaderFooter* doNotApplyGridInHeaderFooter = pdoNotApplyGridInHeaderFooter;
        if (doNotApplyGridInHeaderFooter == NULL) {
            doNotApplyGridInHeaderFooter = CDoNotApplyGridInHeaderFooter::Create();
        }
        SetObject((CObject*)doNotApplyGridInHeaderFooter);

        return doNotApplyGridInHeaderFooter;
    }

    CDoNotApplyGridInHeaderFooter* CLayoutCompatibility::GetdoNotApplyGridInHeaderFooter(int index)
    {
        return static_cast<CDoNotApplyGridInHeaderFooter*>(GetObjectByID(ID_HEAD_DoNotApplyGridInHeaderFooter, index));
    }

    CApplyExtendHeaderFooterEachSection* CLayoutCompatibility::SetapplyExtendHeaderFooterEachSection(CApplyExtendHeaderFooterEachSection* papplyExtendHeaderFooterEachSection)
    {
        CApplyExtendHeaderFooterEachSection* applyExtendHeaderFooterEachSection = papplyExtendHeaderFooterEachSection;
        if (applyExtendHeaderFooterEachSection == NULL) {
            applyExtendHeaderFooterEachSection = CApplyExtendHeaderFooterEachSection::Create();
        }
        SetObject((CObject*)applyExtendHeaderFooterEachSection);

        return applyExtendHeaderFooterEachSection;
    }

    CApplyExtendHeaderFooterEachSection* CLayoutCompatibility::GetapplyExtendHeaderFooterEachSection(int index)
    {
        return static_cast<CApplyExtendHeaderFooterEachSection*>(GetObjectByID(ID_HEAD_ApplyExtendHeaderFooterEachSection, index));
    }

    CDoNotApplyHeaderFooterAtNoSpace* CLayoutCompatibility::SetdoNotApplyHeaderFooterAtNoSpace(CDoNotApplyHeaderFooterAtNoSpace* pdoNotApplyHeaderFooterAtNoSpace)
    {
        CDoNotApplyHeaderFooterAtNoSpace* doNotApplyHeaderFooterAtNoSpace = pdoNotApplyHeaderFooterAtNoSpace;
        if (doNotApplyHeaderFooterAtNoSpace == NULL) {
            doNotApplyHeaderFooterAtNoSpace = CDoNotApplyHeaderFooterAtNoSpace::Create();
        }
        SetObject((CObject*)doNotApplyHeaderFooterAtNoSpace);

        return doNotApplyHeaderFooterAtNoSpace;
    }

    CDoNotApplyHeaderFooterAtNoSpace* CLayoutCompatibility::GetdoNotApplyHeaderFooterAtNoSpace(int index)
    {
        return static_cast<CDoNotApplyHeaderFooterAtNoSpace*>(GetObjectByID(ID_HEAD_DoNotApplyHeaderFooterAtNoSpace, index));
    }

    CDoNotApplyColSeparatorAtNoGap* CLayoutCompatibility::SetdoNotApplyColSeparatorAtNoGap(CDoNotApplyColSeparatorAtNoGap* pdoNotApplyColSeparatorAtNoGap)
    {
        CDoNotApplyColSeparatorAtNoGap* doNotApplyColSeparatorAtNoGap = pdoNotApplyColSeparatorAtNoGap;
        if (doNotApplyColSeparatorAtNoGap == NULL) {
            doNotApplyColSeparatorAtNoGap = CDoNotApplyColSeparatorAtNoGap::Create();
        }
        SetObject((CObject*)doNotApplyColSeparatorAtNoGap);

        return doNotApplyColSeparatorAtNoGap;
    }

    CDoNotApplyColSeparatorAtNoGap* CLayoutCompatibility::GetdoNotApplyColSeparatorAtNoGap(int index)
    {
        return static_cast<CDoNotApplyColSeparatorAtNoGap*>(GetObjectByID(ID_HEAD_DoNotApplyColSeparatorAtNoGap, index));
    }

    CDoNotApplyLinegridAtNoLinespacing* CLayoutCompatibility::SetdoNotApplyLinegridAtNoLinespacing(CDoNotApplyLinegridAtNoLinespacing* pdoNotApplyLinegridAtNoLinespacing)
    {
        CDoNotApplyLinegridAtNoLinespacing* doNotApplyLinegridAtNoLinespacing = pdoNotApplyLinegridAtNoLinespacing;
        if (doNotApplyLinegridAtNoLinespacing == NULL) {
            doNotApplyLinegridAtNoLinespacing = CDoNotApplyLinegridAtNoLinespacing::Create();
        }
        SetObject((CObject*)doNotApplyLinegridAtNoLinespacing);

        return doNotApplyLinegridAtNoLinespacing;
    }

    CDoNotApplyLinegridAtNoLinespacing* CLayoutCompatibility::GetdoNotApplyLinegridAtNoLinespacing(int index)
    {
        return static_cast<CDoNotApplyLinegridAtNoLinespacing*>(GetObjectByID(ID_HEAD_DoNotApplyLinegridAtNoLinespacing, index));
    }

    CDoNotApplyImageEffect* CLayoutCompatibility::SetdoNotApplyImageEffect(CDoNotApplyImageEffect* pdoNotApplyImageEffect)
    {
        CDoNotApplyImageEffect* doNotApplyImageEffect = pdoNotApplyImageEffect;
        if (doNotApplyImageEffect == NULL) {
            doNotApplyImageEffect = CDoNotApplyImageEffect::Create();
        }
        SetObject((CObject*)doNotApplyImageEffect);

        return doNotApplyImageEffect;
    }

    CDoNotApplyImageEffect* CLayoutCompatibility::GetdoNotApplyImageEffect(int index)
    {
        return static_cast<CDoNotApplyImageEffect*>(GetObjectByID(ID_HEAD_DoNotApplyImageEffect, index));
    }

    CDoNotApplyShapeComment* CLayoutCompatibility::SetdoNotApplyShapeComment(CDoNotApplyShapeComment* pdoNotApplyShapeComment)
    {
        CDoNotApplyShapeComment* doNotApplyShapeComment = pdoNotApplyShapeComment;
        if (doNotApplyShapeComment == NULL) {
            doNotApplyShapeComment = CDoNotApplyShapeComment::Create();
        }
        SetObject((CObject*)doNotApplyShapeComment);

        return doNotApplyShapeComment;
    }

    CDoNotApplyShapeComment* CLayoutCompatibility::GetdoNotApplyShapeComment(int index)
    {
        return static_cast<CDoNotApplyShapeComment*>(GetObjectByID(ID_HEAD_DoNotApplyShapeComment, index));
    }

    CDoNotAdjustEmptyAnchorLine* CLayoutCompatibility::SetdoNotAdjustEmptyAnchorLine(CDoNotAdjustEmptyAnchorLine* pdoNotAdjustEmptyAnchorLine)
    {
        CDoNotAdjustEmptyAnchorLine* doNotAdjustEmptyAnchorLine = pdoNotAdjustEmptyAnchorLine;
        if (doNotAdjustEmptyAnchorLine == NULL) {
            doNotAdjustEmptyAnchorLine = CDoNotAdjustEmptyAnchorLine::Create();
        }
        SetObject((CObject*)doNotAdjustEmptyAnchorLine);

        return doNotAdjustEmptyAnchorLine;
    }

    CDoNotAdjustEmptyAnchorLine* CLayoutCompatibility::GetdoNotAdjustEmptyAnchorLine(int index)
    {
        return static_cast<CDoNotAdjustEmptyAnchorLine*>(GetObjectByID(ID_HEAD_DoNotAdjustEmptyAnchorLine, index));
    }

    COverlapBothAllowOverlap* CLayoutCompatibility::SetoverlapBothAllowOverlap(COverlapBothAllowOverlap* poverlapBothAllowOverlap)
    {
        COverlapBothAllowOverlap* overlapBothAllowOverlap = poverlapBothAllowOverlap;
        if (overlapBothAllowOverlap == NULL) {
            overlapBothAllowOverlap = COverlapBothAllowOverlap::Create();
        }
        SetObject((CObject*)overlapBothAllowOverlap);

        return overlapBothAllowOverlap;
    }

    COverlapBothAllowOverlap* CLayoutCompatibility::GetoverlapBothAllowOverlap(int index)
    {
        return static_cast<COverlapBothAllowOverlap*>(GetObjectByID(ID_HEAD_OverlapBothAllowOverlap, index));
    }

    CDoNotApplyVertOffsetOfForward* CLayoutCompatibility::SetdoNotApplyVertOffsetOfForward(CDoNotApplyVertOffsetOfForward* pdoNotApplyVertOffsetOfForward)
    {
        CDoNotApplyVertOffsetOfForward* doNotApplyVertOffsetOfForward = pdoNotApplyVertOffsetOfForward;
        if (doNotApplyVertOffsetOfForward == NULL) {
            doNotApplyVertOffsetOfForward = CDoNotApplyVertOffsetOfForward::Create();
        }
        SetObject((CObject*)doNotApplyVertOffsetOfForward);

        return doNotApplyVertOffsetOfForward;
    }

    CDoNotApplyVertOffsetOfForward* CLayoutCompatibility::GetdoNotApplyVertOffsetOfForward(int index)
    {
        return static_cast<CDoNotApplyVertOffsetOfForward*>(GetObjectByID(ID_HEAD_DoNotApplyVertOffsetOfForward, index));
    }

    CExtendVertLimitToPageMargins* CLayoutCompatibility::SetextendVertLimitToPageMargins(CExtendVertLimitToPageMargins* pextendVertLimitToPageMargins)
    {
        CExtendVertLimitToPageMargins* extendVertLimitToPageMargins = pextendVertLimitToPageMargins;
        if (extendVertLimitToPageMargins == NULL) {
            extendVertLimitToPageMargins = CExtendVertLimitToPageMargins::Create();
        }
        SetObject((CObject*)extendVertLimitToPageMargins);

        return extendVertLimitToPageMargins;
    }

    CExtendVertLimitToPageMargins* CLayoutCompatibility::GetextendVertLimitToPageMargins(int index)
    {
        return static_cast<CExtendVertLimitToPageMargins*>(GetObjectByID(ID_HEAD_ExtendVertLimitToPageMargins, index));
    }

    CDoNotHoldAnchorOfTable* CLayoutCompatibility::SetdoNotHoldAnchorOfTable(CDoNotHoldAnchorOfTable* pdoNotHoldAnchorOfTable)
    {
        CDoNotHoldAnchorOfTable* doNotHoldAnchorOfTable = pdoNotHoldAnchorOfTable;
        if (doNotHoldAnchorOfTable == NULL) {
            doNotHoldAnchorOfTable = CDoNotHoldAnchorOfTable::Create();
        }
        SetObject((CObject*)doNotHoldAnchorOfTable);

        return doNotHoldAnchorOfTable;
    }

    CDoNotHoldAnchorOfTable* CLayoutCompatibility::GetdoNotHoldAnchorOfTable(int index)
    {
        return static_cast<CDoNotHoldAnchorOfTable*>(GetObjectByID(ID_HEAD_DoNotHoldAnchorOfTable, index));
    }

    CDoNotFormattingAtBeneathAnchor* CLayoutCompatibility::SetdoNotFormattingAtBeneathAnchor(CDoNotFormattingAtBeneathAnchor* pdoNotFormattingAtBeneathAnchor)
    {
        CDoNotFormattingAtBeneathAnchor* doNotFormattingAtBeneathAnchor = pdoNotFormattingAtBeneathAnchor;
        if (doNotFormattingAtBeneathAnchor == NULL) {
            doNotFormattingAtBeneathAnchor = CDoNotFormattingAtBeneathAnchor::Create();
        }
        SetObject((CObject*)doNotFormattingAtBeneathAnchor);

        return doNotFormattingAtBeneathAnchor;
    }

    CDoNotFormattingAtBeneathAnchor* CLayoutCompatibility::GetdoNotFormattingAtBeneathAnchor(int index)
    {
        return static_cast<CDoNotFormattingAtBeneathAnchor*>(GetObjectByID(ID_HEAD_DoNotFormattingAtBeneathAnchor, index));
    }

    CAdjustBaselineOfObjectToBottom* CLayoutCompatibility::SetadjustBaselineOfObjectToBottom(CAdjustBaselineOfObjectToBottom* padjustBaselineOfObjectToBottom)
    {
        CAdjustBaselineOfObjectToBottom* adjustBaselineOfObjectToBottom = padjustBaselineOfObjectToBottom;
        if (adjustBaselineOfObjectToBottom == NULL) {
            adjustBaselineOfObjectToBottom = CAdjustBaselineOfObjectToBottom::Create();
        }
        SetObject((CObject*)adjustBaselineOfObjectToBottom);

        return adjustBaselineOfObjectToBottom;
    }

    CAdjustBaselineOfObjectToBottom* CLayoutCompatibility::GetadjustBaselineOfObjectToBottom(int index)
    {
        return static_cast<CAdjustBaselineOfObjectToBottom*>(GetObjectByID(ID_HEAD_AdjustBaselineOfObjectToBottom, index));
    }

    CDoNotApplyExtensionCharCompose* CLayoutCompatibility::SetdoNotApplyExtensionCharCompose(CDoNotApplyExtensionCharCompose* pdoNotApplyExtensionCharCompose)
    {
        CDoNotApplyExtensionCharCompose* doNotApplyExtensionCharCompose = pdoNotApplyExtensionCharCompose;
        if (doNotApplyExtensionCharCompose == NULL) {
            doNotApplyExtensionCharCompose = CDoNotApplyExtensionCharCompose::Create();
        }
        SetObject((CObject*)doNotApplyExtensionCharCompose);

        return doNotApplyExtensionCharCompose;
    }

    CDoNotApplyExtensionCharCompose* CLayoutCompatibility::GetdoNotApplyExtensionCharCompose(int index)
    {
        return static_cast<CDoNotApplyExtensionCharCompose*>(GetObjectByID(ID_HEAD_DoNotApplyExtensionCharCompose, index));
    }

}
