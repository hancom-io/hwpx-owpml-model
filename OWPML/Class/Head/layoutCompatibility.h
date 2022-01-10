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
#ifndef  _LAYOUTCOMPATIBILITY_H_
#define  _LAYOUTCOMPATIBILITY_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CApplyFontWeightToBold;
    class CUseInnerUnderline;
    class CFixedUnderlineWidth;
    class CDoNotApplyStrikeoutWithUnderline;
    class CUseLowercaseStrikeout;
    class CExtendLineheightToOffset;
    class CApplyFontspaceToLatin;
    class CTreatQuotationAsLatin;
    class CDoNotApplyDiacSymMarkOfNoneAndSix;
    class CDoNotAlignWhitespaceOnRight;
    class CDoNotAdjustWordInJustify;
    class CBaseCharUnitOnEAsian;
    class CBaseCharUnitOfIndentOnFirstChar;
    class CAdjustLineheightToFont;
    class CAdjustBaselineInFixedLinespacing;
    class CApplyPrevspacingBeneathObject;
    class CApplyNextspacingOfLastPara;
    class CApplyAtLeastToPercent100Pct;
    class CDoNotApplyAutoSpaceEAsianEng;
    class CDoNotApplyAutoSpaceEAsianNum;
    class CAdjustParaBorderfillToSpacing;
    class CConnectParaBorderfillOfEqualBorder;
    class CAdjustParaBorderOffsetWithBorder;
    class CExtendLineheightToParaBorderOffset;
    class CApplyParaBorderToOutside;
    class CApplyMinColumnWidthTo1mm;
    class CApplyTabPosBasedOnSegment;
    class CBreakTabOverLine;
    class CAdjustVertPosOfLine;
    class CDoNotApplyWhiteSpaceHeight;
    class CDoNotAlignLastPeriod;
    class CDoNotAlignLastForbidden;
    class CAdjustMarginFromAdjustLineheight;
    class CBaseLineSpacingOnLineGrid;
    class CApplyCharSpacingToCharGrid;
    class CDoNotApplyGridInHeaderFooter;
    class CApplyExtendHeaderFooterEachSection;
    class CDoNotApplyHeaderFooterAtNoSpace;
    class CDoNotApplyColSeparatorAtNoGap;
    class CDoNotApplyLinegridAtNoLinespacing;
    class CDoNotApplyImageEffect;
    class CDoNotApplyShapeComment;
    class CDoNotAdjustEmptyAnchorLine;
    class COverlapBothAllowOverlap;
    class CDoNotApplyVertOffsetOfForward;
    class CExtendVertLimitToPageMargins;
    class CDoNotHoldAnchorOfTable;
    class CDoNotFormattingAtBeneathAnchor;
    class CAdjustBaselineOfObjectToBottom;
    class CDoNotApplyExtensionCharCompose;

    // CLayoutCompatibility Declaration 
    class CLayoutCompatibility : public CExtObject
    {
    private:
        CLayoutCompatibility();
    public:
        virtual ~CLayoutCompatibility();
        static CLayoutCompatibility* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CApplyFontWeightToBold* SetapplyFontWeightToBold(CApplyFontWeightToBold* applyFontWeightToBold = NULL);
        CApplyFontWeightToBold* GetapplyFontWeightToBold(int index = 0);

        CUseInnerUnderline* SetuseInnerUnderline(CUseInnerUnderline* useInnerUnderline = NULL);
        CUseInnerUnderline* GetuseInnerUnderline(int index = 0);

        CFixedUnderlineWidth* SetfixedUnderlineWidth(CFixedUnderlineWidth* fixedUnderlineWidth = NULL);
        CFixedUnderlineWidth* GetfixedUnderlineWidth(int index = 0);

        CDoNotApplyStrikeoutWithUnderline* SetdoNotApplyStrikeoutWithUnderline(CDoNotApplyStrikeoutWithUnderline* doNotApplyStrikeoutWithUnderline = NULL);
        CDoNotApplyStrikeoutWithUnderline* GetdoNotApplyStrikeoutWithUnderline(int index = 0);

        CUseLowercaseStrikeout* SetuseLowercaseStrikeout(CUseLowercaseStrikeout* useLowercaseStrikeout = NULL);
        CUseLowercaseStrikeout* GetuseLowercaseStrikeout(int index = 0);

        CExtendLineheightToOffset* SetextendLineheightToOffset(CExtendLineheightToOffset* extendLineheightToOffset = NULL);
        CExtendLineheightToOffset* GetextendLineheightToOffset(int index = 0);

        CApplyFontspaceToLatin* SetapplyFontspaceToLatin(CApplyFontspaceToLatin* applyFontspaceToLatin = NULL);
        CApplyFontspaceToLatin* GetapplyFontspaceToLatin(int index = 0);

        CTreatQuotationAsLatin* SettreatQuotationAsLatin(CTreatQuotationAsLatin* treatQuotationAsLatin = NULL);
        CTreatQuotationAsLatin* GettreatQuotationAsLatin(int index = 0);

        CDoNotApplyDiacSymMarkOfNoneAndSix* SetdoNotApplyDiacSymMarkOfNoneAndSix(CDoNotApplyDiacSymMarkOfNoneAndSix* doNotApplyDiacSymMarkOfNoneAndSix = NULL);
        CDoNotApplyDiacSymMarkOfNoneAndSix* GetdoNotApplyDiacSymMarkOfNoneAndSix(int index = 0);

        CDoNotAlignWhitespaceOnRight* SetdoNotAlignWhitespaceOnRight(CDoNotAlignWhitespaceOnRight* doNotAlignWhitespaceOnRight = NULL);
        CDoNotAlignWhitespaceOnRight* GetdoNotAlignWhitespaceOnRight(int index = 0);

        CDoNotAdjustWordInJustify* SetdoNotAdjustWordInJustify(CDoNotAdjustWordInJustify* doNotAdjustWordInJustify = NULL);
        CDoNotAdjustWordInJustify* GetdoNotAdjustWordInJustify(int index = 0);

        CBaseCharUnitOnEAsian* SetbaseCharUnitOnEAsian(CBaseCharUnitOnEAsian* baseCharUnitOnEAsian = NULL);
        CBaseCharUnitOnEAsian* GetbaseCharUnitOnEAsian(int index = 0);

        CBaseCharUnitOfIndentOnFirstChar* SetbaseCharUnitOfIndentOnFirstChar(CBaseCharUnitOfIndentOnFirstChar* baseCharUnitOfIndentOnFirstChar = NULL);
        CBaseCharUnitOfIndentOnFirstChar* GetbaseCharUnitOfIndentOnFirstChar(int index = 0);

        CAdjustLineheightToFont* SetadjustLineheightToFont(CAdjustLineheightToFont* adjustLineheightToFont = NULL);
        CAdjustLineheightToFont* GetadjustLineheightToFont(int index = 0);

        CAdjustBaselineInFixedLinespacing* SetadjustBaselineInFixedLinespacing(CAdjustBaselineInFixedLinespacing* adjustBaselineInFixedLinespacing = NULL);
        CAdjustBaselineInFixedLinespacing* GetadjustBaselineInFixedLinespacing(int index = 0);

        CApplyPrevspacingBeneathObject* SetapplyPrevspacingBeneathObject(CApplyPrevspacingBeneathObject* applyPrevspacingBeneathObject = NULL);
        CApplyPrevspacingBeneathObject* GetapplyPrevspacingBeneathObject(int index = 0);

        CApplyNextspacingOfLastPara* SetapplyNextspacingOfLastPara(CApplyNextspacingOfLastPara* applyNextspacingOfLastPara = NULL);
        CApplyNextspacingOfLastPara* GetapplyNextspacingOfLastPara(int index = 0);

        CApplyAtLeastToPercent100Pct* SetapplyAtLeastToPercent100Pct(CApplyAtLeastToPercent100Pct* applyAtLeastToPercent100Pct = NULL);
        CApplyAtLeastToPercent100Pct* GetapplyAtLeastToPercent100Pct(int index = 0);

        CDoNotApplyAutoSpaceEAsianEng* SetdoNotApplyAutoSpaceEAsianEng(CDoNotApplyAutoSpaceEAsianEng* doNotApplyAutoSpaceEAsianEng = NULL);
        CDoNotApplyAutoSpaceEAsianEng* GetdoNotApplyAutoSpaceEAsianEng(int index = 0);

        CDoNotApplyAutoSpaceEAsianNum* SetdoNotApplyAutoSpaceEAsianNum(CDoNotApplyAutoSpaceEAsianNum* doNotApplyAutoSpaceEAsianNum = NULL);
        CDoNotApplyAutoSpaceEAsianNum* GetdoNotApplyAutoSpaceEAsianNum(int index = 0);

        CAdjustParaBorderfillToSpacing* SetadjustParaBorderfillToSpacing(CAdjustParaBorderfillToSpacing* adjustParaBorderfillToSpacing = NULL);
        CAdjustParaBorderfillToSpacing* GetadjustParaBorderfillToSpacing(int index = 0);

        CConnectParaBorderfillOfEqualBorder* SetconnectParaBorderfillOfEqualBorder(CConnectParaBorderfillOfEqualBorder* connectParaBorderfillOfEqualBorder = NULL);
        CConnectParaBorderfillOfEqualBorder* GetconnectParaBorderfillOfEqualBorder(int index = 0);

        CAdjustParaBorderOffsetWithBorder* SetadjustParaBorderOffsetWithBorder(CAdjustParaBorderOffsetWithBorder* adjustParaBorderOffsetWithBorder = NULL);
        CAdjustParaBorderOffsetWithBorder* GetadjustParaBorderOffsetWithBorder(int index = 0);

        CExtendLineheightToParaBorderOffset* SetextendLineheightToParaBorderOffset(CExtendLineheightToParaBorderOffset* extendLineheightToParaBorderOffset = NULL);
        CExtendLineheightToParaBorderOffset* GetextendLineheightToParaBorderOffset(int index = 0);

        CApplyParaBorderToOutside* SetapplyParaBorderToOutside(CApplyParaBorderToOutside* applyParaBorderToOutside = NULL);
        CApplyParaBorderToOutside* GetapplyParaBorderToOutside(int index = 0);

        CApplyMinColumnWidthTo1mm* SetapplyMinColumnWidthTo1mm(CApplyMinColumnWidthTo1mm* applyMinColumnWidthTo1mm = NULL);
        CApplyMinColumnWidthTo1mm* GetapplyMinColumnWidthTo1mm(int index = 0);

        CApplyTabPosBasedOnSegment* SetapplyTabPosBasedOnSegment(CApplyTabPosBasedOnSegment* applyTabPosBasedOnSegment = NULL);
        CApplyTabPosBasedOnSegment* GetapplyTabPosBasedOnSegment(int index = 0);

        CBreakTabOverLine* SetbreakTabOverLine(CBreakTabOverLine* breakTabOverLine = NULL);
        CBreakTabOverLine* GetbreakTabOverLine(int index = 0);

        CAdjustVertPosOfLine* SetadjustVertPosOfLine(CAdjustVertPosOfLine* adjustVertPosOfLine = NULL);
        CAdjustVertPosOfLine* GetadjustVertPosOfLine(int index = 0);

        CDoNotApplyWhiteSpaceHeight* SetdoNotApplyWhiteSpaceHeight(CDoNotApplyWhiteSpaceHeight* doNotApplyWhiteSpaceHeight = NULL);
        CDoNotApplyWhiteSpaceHeight* GetdoNotApplyWhiteSpaceHeight(int index = 0);

        CDoNotAlignLastPeriod* SetdoNotAlignLastPeriod(CDoNotAlignLastPeriod* doNotAlignLastPeriod = NULL);
        CDoNotAlignLastPeriod* GetdoNotAlignLastPeriod(int index = 0);

        CDoNotAlignLastForbidden* SetdoNotAlignLastForbidden(CDoNotAlignLastForbidden* doNotAlignLastForbidden = NULL);
        CDoNotAlignLastForbidden* GetdoNotAlignLastForbidden(int index = 0);

        CAdjustMarginFromAdjustLineheight* SetadjustMarginFromAdjustLineheight(CAdjustMarginFromAdjustLineheight* padjustMarginFromAdjustLineheight = NULL);
        CAdjustMarginFromAdjustLineheight* GetadjustMarginFromAdjustLineheight(int index = 0);

        CBaseLineSpacingOnLineGrid* SetbaseLineSpacingOnLineGrid(CBaseLineSpacingOnLineGrid* baseLineSpacingOnLineGrid = NULL);
        CBaseLineSpacingOnLineGrid* GetbaseLineSpacingOnLineGrid(int index = 0);

        CApplyCharSpacingToCharGrid* SetapplyCharSpacingToCharGrid(CApplyCharSpacingToCharGrid* applyCharSpacingToCharGrid = NULL);
        CApplyCharSpacingToCharGrid* GetapplyCharSpacingToCharGrid(int index = 0);

        CDoNotApplyGridInHeaderFooter* SetdoNotApplyGridInHeaderFooter(CDoNotApplyGridInHeaderFooter* doNotApplyGridInHeaderFooter = NULL);
        CDoNotApplyGridInHeaderFooter* GetdoNotApplyGridInHeaderFooter(int index = 0);

        CApplyExtendHeaderFooterEachSection* SetapplyExtendHeaderFooterEachSection(CApplyExtendHeaderFooterEachSection* applyExtendHeaderFooterEachSection = NULL);
        CApplyExtendHeaderFooterEachSection* GetapplyExtendHeaderFooterEachSection(int index = 0);

        CDoNotApplyHeaderFooterAtNoSpace* SetdoNotApplyHeaderFooterAtNoSpace(CDoNotApplyHeaderFooterAtNoSpace* doNotApplyHeaderFooterAtNoSpace = NULL);
        CDoNotApplyHeaderFooterAtNoSpace* GetdoNotApplyHeaderFooterAtNoSpace(int index = 0);

        CDoNotApplyColSeparatorAtNoGap* SetdoNotApplyColSeparatorAtNoGap(CDoNotApplyColSeparatorAtNoGap* doNotApplyColSeparatorAtNoGap = NULL);
        CDoNotApplyColSeparatorAtNoGap* GetdoNotApplyColSeparatorAtNoGap(int index = 0);

        CDoNotApplyLinegridAtNoLinespacing* SetdoNotApplyLinegridAtNoLinespacing(CDoNotApplyLinegridAtNoLinespacing* doNotApplyLinegridAtNoLinespacing = NULL);
        CDoNotApplyLinegridAtNoLinespacing* GetdoNotApplyLinegridAtNoLinespacing(int index = 0);

        CDoNotApplyImageEffect* SetdoNotApplyImageEffect(CDoNotApplyImageEffect* doNotApplyImageEffect = NULL);
        CDoNotApplyImageEffect* GetdoNotApplyImageEffect(int index = 0);

        CDoNotApplyShapeComment* SetdoNotApplyShapeComment(CDoNotApplyShapeComment* doNotApplyShapeComment = NULL);
        CDoNotApplyShapeComment* GetdoNotApplyShapeComment(int index = 0);

        CDoNotAdjustEmptyAnchorLine* SetdoNotAdjustEmptyAnchorLine(CDoNotAdjustEmptyAnchorLine* doNotAdjustEmptyAnchorLine = NULL);
        CDoNotAdjustEmptyAnchorLine* GetdoNotAdjustEmptyAnchorLine(int index = 0);

        COverlapBothAllowOverlap* SetoverlapBothAllowOverlap(COverlapBothAllowOverlap* overlapBothAllowOverlap = NULL);
        COverlapBothAllowOverlap* GetoverlapBothAllowOverlap(int index = 0);

        CDoNotApplyVertOffsetOfForward* SetdoNotApplyVertOffsetOfForward(CDoNotApplyVertOffsetOfForward* doNotApplyVertOffsetOfForward = NULL);
        CDoNotApplyVertOffsetOfForward* GetdoNotApplyVertOffsetOfForward(int index = 0);

        CExtendVertLimitToPageMargins* SetextendVertLimitToPageMargins(CExtendVertLimitToPageMargins* extendVertLimitToPageMargins = NULL);
        CExtendVertLimitToPageMargins* GetextendVertLimitToPageMargins(int index = 0);

        CDoNotHoldAnchorOfTable* SetdoNotHoldAnchorOfTable(CDoNotHoldAnchorOfTable* doNotHoldAnchorOfTable = NULL);
        CDoNotHoldAnchorOfTable* GetdoNotHoldAnchorOfTable(int index = 0);

        CDoNotFormattingAtBeneathAnchor* SetdoNotFormattingAtBeneathAnchor(CDoNotFormattingAtBeneathAnchor* doNotFormattingAtBeneathAnchor = NULL);
        CDoNotFormattingAtBeneathAnchor* GetdoNotFormattingAtBeneathAnchor(int index = 0);

        CAdjustBaselineOfObjectToBottom* SetadjustBaselineOfObjectToBottom(CAdjustBaselineOfObjectToBottom* adjustBaselineOfObjectToBottom = NULL);
        CAdjustBaselineOfObjectToBottom* GetadjustBaselineOfObjectToBottom(int index = 0);

        CDoNotApplyExtensionCharCompose* SetdoNotApplyExtensionCharCompose(CDoNotApplyExtensionCharCompose* doNotApplyExtensionCharCompose = NULL);
        CDoNotApplyExtensionCharCompose* GetdoNotApplyExtensionCharCompose(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _LAYOUTCOMPATIBILITY_H_
