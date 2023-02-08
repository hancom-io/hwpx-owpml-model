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

#ifndef _OWPML_FOR_DEC_H_
#define _OWPML_FOR_DEC_H_

namespace OWPML {

    class CDocOptionLinkInfo;
    class CDocOption;
    class CHWPMLHeadType;
    class CBeginNum;
    class CMappingTableType;
    class CForbiddenWordListType;
    class CCompatibleDocumentType;
    class CFontfaces;
    class CBorderFills;
    class CCharProperties;
    class CTabProperties;
    class CNumberings;
    class CBullets;
    class CParaProperties;
    class CStyles;
    class CMemoProperties;
    class CFontfaceType;
    class CBorderFillType;
    class CCharShapeType;
    class CTabDefType;
    class CNumberingType;
    class CBulletType;
    class CParaShapeType;
    class CStyleType;
    class CMemoShapeType;
    class CTrackChange;
    class CTrackChanges;
    class CTrackChangeAuthor;
    class CTrackChangeAuthors;
    class CTrackChangeConfig;
    class CFont;
    class CSubstFont;
    class CTypeInfo;
    class CSlashType;
    class CBorderType;
    class CFillBrushType;
    class CFontRef;
    class CRatio;
    class CSpacing;
    class CRelSz;
    class COffset;
    class CItalic;
    class CBold;
    class CUnderline;
    class CStrikeout;
    class COutline;
    class CShadow;
    class CEmboss;
    class CEngrave;
    class CSupscript;
    class CSubscript;
    class CTabItem;
    class CParaHeadType;
    class CImageType;
    class CAlign;
    class CHeading;
    class CBreakSetting;
    class CMargin;
    class CLineSpacing;
    class CBorder;
    class CAutoSpacing;
    class CHWPValue;
    class CString;
    class CLayoutCompatibility;
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
    class CLineSeg;
    class CLineSegArray;
    class CPType;
    class CRunType;
    class CSectionDefinitionType;
    class CCtrl;
    class CT;
    class CAbstractShapeObjectType;
    class CTableType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CPictureType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class COLEType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CContainerType;
    class CAbstractShapeObjectType;
    class CEquationType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CLineType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CRectangleType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CEllipseType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CArcType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CPolygonType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CCurveType;
    class CAbstractShapeObjectType;
    class CAbstractShapeComponentType;
    class CAbstractDrawingObjectType;
    class CConnectLineType;
    class CTextart;
    class CCompose;
    class CDutmal;
    class CAbstractShapeObjectType;
    class CAbstractFormObjectType;
    class CAbstractButtonObjectType;
    class CAbstractShapeObjectType;
    class CAbstractFormObjectType;
    class CComboBoxType;
    class CAbstractShapeObjectType;
    class CAbstractFormObjectType;
    class CListBoxType;
    class CAbstractShapeObjectType;
    class CAbstractFormObjectType;
    class CEditType;
    class CAbstractShapeObjectType;
    class CAbstractFormObjectType;
    class CScrollBarType;
    class CColumnDefType;
    class CFieldBegin;
    class CFieldEnd;
    class CBookmark;
    class CHeaderFooterType;
    class CNoteType;
    class CAutoNumNewNumType;
    class CPageNumCtrl;
    class CPageHiding;
    class CPageNum;
    class CIndexmark;
    class CHiddenComment;
    class CParameterList;
    class CParaListType;
    class CFirstKey;
    class CSecondKey;
    class CMarkpenBegin;
    class CMarkpenEnd;
    class CTitleMark;
    class CTab;
    class CLineBreak;
    class CHypen;
    class CNbSpace;
    class CFwSpace;
    class CPointType;
    class CTextartPr;
    class COutline;
    class CShadowType;
    class CCharPr;
    class CMainText;
    class CSubText;
    class CStartNum;
    class CGrid;
    class CVisibility;
    class CPagePr;
    class CNoteShapeType;
    class CFootNoteShapeType;
    class CNoteShapeType;
    class CEndNoteShapeType;
    class CPageBorderFill;
    class CMasterPage;
    class CMargin;
    class COffset;
    class CAutoNumFormatType;
    class CNoteLine;
    class CNoteSpacing;
    class CNumbering;
    class CPlacement;
    class CNumbering;
    class CPlacement;
    class CColLine;
    class CColSz;
    class CShadow;
    class CGlow;
    class CSoftEdge;
    class CReflection;
    class CSkewType;
    class CScaleType;
    class CEffectsColorType;
    class CAlpha;
    class CPos;
    class CRgb;
    class CCmyk;
    class CScheme;
    class CSystem;
    class CEffect;
    class CSz;
    class CPos;
    class COutMargin;
    class CCaption;
    class CShapeComment;
    class CInsideMarginType;
    class CCellzoneList;
    class CTr;
    class CCellzone;
    class CTc;
    class CCellAddr;
    class CCellSpan;
    class CCellSz;
    class CCellMargin;
    class CScript;
    class COffset;
    class COrgSz;
    class CCurSz;
    class CFlip;
    class CRotationInfo;
    class CRenderingInfo;
    class CMatrixType;
    class CLineShapeType;
    class CImgRect;
    class CImgClip;
    class CEffectsType;
    class CDrawText;
    class CTextMargin;
    class CSeg;
    class CPointType;
    class CConnectPointType;
    class CConnectControlPointType;
    class CConnectControlPoints;
    class CFormCharPr;
    class CListItemType;
    class CText;
    class CBooleanParam;
    class CIntegerParam;
    class CFloatParam;
    class CStringParam;
    class CWinBrush;
    class CGradation;
    class CImgBrush;
    class CColor;
    class CVersion;
    class CHWPApplicationSetting;
    class CCaretPosition;
    class CParameterItemtype;
    class CParameterSetType;
    class CParameterArrayType;
    class CParameterBinary;
    class CSectionType;
    class CAbstractDiffDataType;
    class CHWPMLHistoryType;
    class CHistoryEntryType;
    class CDiffEntryType;
    class CInsertType;
    class CUpdateType;
    class CDeleteType;
    class CPositionType;
    class CMasterPageType;
    class CPackage;
    class CMetadataType;
    class CManifestType;
    class CSpineType;
    class CToursType;
    class CGuideType;
    class CTitle;
    class CLanguage;
    class CIdentifier;
    class CMeta;
    class CItem;
    class CItemref;
    class CTour;
    class CSite;
    class CReference;
    class CParaHeadType2;
    class CObject;
    class CUnknownObjectType;
    class CTrackChangeTag;
    class CConfigItemSet;
    class CHWPApplicationSetting;
    class CDocument;
    class CEncryptInfo;
    class CFileEntry;
    class CPresentation;
    class CLabel;

    typedef struct fieldInfo
    {
        fieldInfo() : m_instid(0), m_fieldid(0), m_zorder(0), m_editable(0), m_prop(0) {}
        UINT m_instid;
        UINT m_fieldid;
        UINT m_zorder;
        BOOL m_editable;
        UINT m_prop;
    } FieldInfo;

    typedef std::vector<CObject*> Objectlist;
}

#endif // _OWPML_FOR_DEC_H_