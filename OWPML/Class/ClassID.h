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

#ifndef    _OWPML_CLASSID_H_
#define    _OWPML_CLASSID_H_

namespace OWPML {

#define OWPML_HEAD_ID                                    0x10000000
#define OWPML_CORE_ID                                    0x20000000
#define OWPML_PARALIST_ID                                0x30000000
#define OWPML_BODY_ID                                    0x40000000
#define OWPML_VERSION_ID                                 0x50000000
#define OWPML_APPLICATION_ID                             0x60000000
#define OWPML_HISTORY_ID                                 0x70000000
#define OWPML_MASTERPAGE_ID                              0x80000000
#define OWPML_OPF_ID                                     0x90000000
#define OWPML_CONTAINER_ID                               0xA0000000
#define OWPML_ODF_MANIFEST_ID                            0xB0000000
#define OWPML_SECURITY_ID                                0xB8000000

#define OWPML_UNKNOWN_ID                                 0xC0000000

#define OWPML_RDF_ID                                     0xD0000000

#define OWPML_EXTELEMENT_ID                              0xE0000000


#define ID_HEAD_HWPMLHeadType                            OWPML_HEAD_ID + 0x0001
#define ID_HEAD_BeginNum                                 OWPML_HEAD_ID + 0x0002
#define ID_HEAD_MappingTableType                         OWPML_HEAD_ID + 0x0003
#define ID_HEAD_ForbiddenWordListType                    OWPML_HEAD_ID + 0x0004
#define ID_HEAD_CompatibleDocumentType                   OWPML_HEAD_ID + 0x0005
#define ID_HEAD_Fontfaces                                OWPML_HEAD_ID + 0x0006
#define ID_HEAD_BorderFills                              OWPML_HEAD_ID + 0x0007
#define ID_HEAD_CharProperties                           OWPML_HEAD_ID + 0x0008
#define ID_HEAD_TabProperties                            OWPML_HEAD_ID + 0x0009
#define ID_HEAD_Numberings                               OWPML_HEAD_ID + 0x000A
#define ID_HEAD_Bullets                                  OWPML_HEAD_ID + 0x000B
#define ID_HEAD_ParaProperties                           OWPML_HEAD_ID + 0x000C
#define ID_HEAD_Styles                                   OWPML_HEAD_ID + 0x000D
#define ID_HEAD_MemoProperties                           OWPML_HEAD_ID + 0x000E
#define ID_HEAD_FontfaceType                             OWPML_HEAD_ID + 0x000F
#define ID_HEAD_BorderFillType                           OWPML_HEAD_ID + 0x0010
#define ID_HEAD_CharShapeType                            OWPML_HEAD_ID + 0x0011
#define ID_HEAD_TabDefType                               OWPML_HEAD_ID + 0x0012
#define ID_HEAD_NumberingType                            OWPML_HEAD_ID + 0x0013
#define ID_HEAD_BulletType                               OWPML_HEAD_ID + 0x0014
#define ID_HEAD_ParaShapeType                            OWPML_HEAD_ID + 0x0015
#define ID_HEAD_StyleType                                OWPML_HEAD_ID + 0x0016
#define ID_HEAD_MemoShapeType                            OWPML_HEAD_ID + 0x0017
#define ID_HEAD_Font                                     OWPML_HEAD_ID + 0x0018
#define ID_HEAD_SubstFont                                OWPML_HEAD_ID + 0x0019
#define ID_HEAD_TypeInfo                                 OWPML_HEAD_ID + 0x001A
#define ID_HEAD_SlashType                                OWPML_HEAD_ID + 0x001B
#define ID_HEAD_BorderType                               OWPML_HEAD_ID + 0x001C

#define ID_HEAD_FontRef                                  OWPML_HEAD_ID + 0x001D
#define ID_HEAD_Ratio                                    OWPML_HEAD_ID + 0x001E
#define ID_HEAD_Spacing                                  OWPML_HEAD_ID + 0x001F
#define ID_HEAD_RelSz                                    OWPML_HEAD_ID + 0x0020
#define ID_HEAD_Offset                                   OWPML_HEAD_ID + 0x0021
#define ID_HEAD_Italic                                   OWPML_HEAD_ID + 0x0022
#define ID_HEAD_Bold                                     OWPML_HEAD_ID + 0x0023
#define ID_HEAD_Underline                                OWPML_HEAD_ID + 0x0024
#define ID_HEAD_Strikeout                                OWPML_HEAD_ID + 0x0025
#define ID_HEAD_Outline                                  OWPML_HEAD_ID + 0x0026
#define ID_HEAD_CharShadow                               OWPML_HEAD_ID + 0x0027
#define ID_HEAD_Emboss                                   OWPML_HEAD_ID + 0x0028
#define ID_HEAD_Engrave                                  OWPML_HEAD_ID + 0x0029
#define ID_HEAD_Supscript                                OWPML_HEAD_ID + 0x002A
#define ID_HEAD_Subscript                                OWPML_HEAD_ID + 0x002B
#define ID_HEAD_TabItem                                  OWPML_HEAD_ID + 0x002C
#define ID_HEAD_ParaHeadType                             OWPML_HEAD_ID + 0x002D

#define ID_HEAD_Align                                    OWPML_HEAD_ID + 0x002E
#define ID_HEAD_Heading                                  OWPML_HEAD_ID + 0x002F
#define ID_HEAD_BreakSetting                             OWPML_HEAD_ID + 0x0030
#define ID_HEAD_Margin                                   OWPML_HEAD_ID + 0x0031
#define ID_HEAD_LineSpacing                              OWPML_HEAD_ID + 0x0032
#define ID_HEAD_Border                                   OWPML_HEAD_ID + 0x0033
#define ID_HEAD_AutoSpacing                              OWPML_HEAD_ID + 0x0034

#define ID_HEAD_String                                   OWPML_HEAD_ID + 0x0035
#define ID_HEAD_LayoutCompatibility                      OWPML_HEAD_ID + 0x0036
#define ID_HEAD_ApplyFontWeightToBold                    OWPML_HEAD_ID + 0x0037
#define ID_HEAD_UseInnerUnderline                        OWPML_HEAD_ID + 0x0038
#define ID_HEAD_FixedUnderlineWidth                      OWPML_HEAD_ID + 0x0039
#define ID_HEAD_DoNotApplyStrikeoutWithUnderline         OWPML_HEAD_ID + 0x003A
#define ID_HEAD_UseLowercaseStrikeout                    OWPML_HEAD_ID + 0x003B
#define ID_HEAD_ExtendLineheightToOffset                 OWPML_HEAD_ID + 0x003C
#define ID_HEAD_ApplyFontspaceToLatin                    OWPML_HEAD_ID + 0x003D
#define ID_HEAD_TreatQuotationAsLatin                    OWPML_HEAD_ID + 0x003E
#define ID_HEAD_DoNotApplyDiacSymMarkOfNoneAndSix        OWPML_HEAD_ID + 0x003F
#define ID_HEAD_DoNotAlignWhitespaceOnRight              OWPML_HEAD_ID + 0x0040
#define ID_HEAD_DoNotAdjustWordInJustify                 OWPML_HEAD_ID + 0x0041
#define ID_HEAD_BaseCharUnitOnEAsian                     OWPML_HEAD_ID + 0x0042
#define ID_HEAD_BaseCharUnitOfIndentOnFirstChar          OWPML_HEAD_ID + 0x0043
#define ID_HEAD_AdjustLineheightToFont                   OWPML_HEAD_ID + 0x0044
#define ID_HEAD_AdjustBaselineInFixedLinespacing         OWPML_HEAD_ID + 0x0045
#define ID_HEAD_ApplyPrevspacingBeneathObject            OWPML_HEAD_ID + 0x0046
#define ID_HEAD_ApplyNextspacingOfLastPara               OWPML_HEAD_ID + 0x0047
#define ID_HEAD_ApplyAtLeastToPercent100Pct              OWPML_HEAD_ID + 0x0048
#define ID_HEAD_DoNotApplyAutoSpaceEAsianEng             OWPML_HEAD_ID + 0x0049
#define ID_HEAD_DoNotApplyAutoSpaceEAsianNum             OWPML_HEAD_ID + 0x004A
#define ID_HEAD_AdjustParaBorderfillToSpacing            OWPML_HEAD_ID + 0x004B
#define ID_HEAD_ConnectParaBorderfillOfEqualBorder       OWPML_HEAD_ID + 0x004C
#define ID_HEAD_AdjustParaBorderOffsetWithBorder         OWPML_HEAD_ID + 0x004D
#define ID_HEAD_ExtendLineheightToParaBorderOffset       OWPML_HEAD_ID + 0x004E
#define ID_HEAD_ApplyParaBorderToOutside                 OWPML_HEAD_ID + 0x004F
#define ID_HEAD_ApplyMinColumnWidthTo1mm                 OWPML_HEAD_ID + 0x0050
#define ID_HEAD_ApplyTabPosBasedOnSegment                OWPML_HEAD_ID + 0x0051
#define ID_HEAD_BreakTabOverLine                         OWPML_HEAD_ID + 0x0052
#define ID_HEAD_AdjustVertPosOfLine                      OWPML_HEAD_ID + 0x0053
#define ID_HEAD_DoNotApplyWhiteSpaceHeight               OWPML_HEAD_ID + 0x0054
#define ID_HEAD_DoNotAlignLastPeriod                     OWPML_HEAD_ID + 0x0055
#define ID_HEAD_DoNotAlignLastForbidden                  OWPML_HEAD_ID + 0x0056
#define ID_HEAD_BaseLineSpacingOnLineGrid                OWPML_HEAD_ID + 0x0057
#define ID_HEAD_ApplyCharSpacingToCharGrid               OWPML_HEAD_ID + 0x0058
#define ID_HEAD_DoNotApplyGridInHeaderFooter             OWPML_HEAD_ID + 0x0059
#define ID_HEAD_ApplyExtendHeaderFooterEachSection       OWPML_HEAD_ID + 0x005A
#define ID_HEAD_DoNotApplyHeaderFooterAtNoSpace          OWPML_HEAD_ID + 0x005B
#define ID_HEAD_DoNotApplyColSeparatorAtNoGap            OWPML_HEAD_ID + 0x005C
#define ID_HEAD_DoNotApplyLinegridAtNoLinespacing        OWPML_HEAD_ID + 0x005D
#define ID_HEAD_DoNotApplyImageEffect                    OWPML_HEAD_ID + 0x005E
#define ID_HEAD_DoNotApplyShapeComment                   OWPML_HEAD_ID + 0x005F
#define ID_HEAD_DoNotAdjustEmptyAnchorLine               OWPML_HEAD_ID + 0x0060
#define ID_HEAD_OverlapBothAllowOverlap                  OWPML_HEAD_ID + 0x0061
#define ID_HEAD_DoNotApplyVertOffsetOfForward            OWPML_HEAD_ID + 0x0062
#define ID_HEAD_ExtendVertLimitToPageMargins             OWPML_HEAD_ID + 0x0063
#define ID_HEAD_DoNotHoldAnchorOfTable                   OWPML_HEAD_ID + 0x0064
#define ID_HEAD_DoNotFormattingAtBeneathAnchor           OWPML_HEAD_ID + 0x0065
#define ID_HEAD_AdjustBaselineOfObjectToBottom           OWPML_HEAD_ID + 0x0066
#define ID_HEAD_DoNotApplyExtensionCharCompose           OWPML_HEAD_ID + 0x0067
#define ID_HEAD_AdjustMarginFromAdjustLineheight         OWPML_HEAD_ID + 0x0068
#define ID_HEAD_ForbiddenWord                            OWPML_HEAD_ID + 0x0069
#define ID_HEAD_ParaHeadType2                            OWPML_HEAD_ID + 0x006A

#define ID_HEAD_BackSlashType                            OWPML_HEAD_ID + 0x006B
#define ID_HEAD_Left_BorderType                          OWPML_HEAD_ID + 0x006C
#define ID_HEAD_Right_BorderType                         OWPML_HEAD_ID + 0x006D
#define ID_HEAD_Top_BorderType                           OWPML_HEAD_ID + 0x006F
#define ID_HEAD_Bottom_BorderType                        OWPML_HEAD_ID + 0x0070
#define ID_HEAD_Diagonal_BorderType                      OWPML_HEAD_ID + 0x0071

#define ID_HEAD_DocOption                                OWPML_HEAD_ID + 0x0072

#define ID_HEAD_DocOption_LinkInfo                       OWPML_HEAD_ID + 0x0073

#define ID_HEAD_TrackChanges                             OWPML_HEAD_ID + 0x0074
#define ID_HEAD_TrackChange                              OWPML_HEAD_ID + 0x0075
#define ID_HEAD_TrackChangeAuthors                       OWPML_HEAD_ID + 0x0076
#define ID_HEAD_TrackChangeAuthor                        OWPML_HEAD_ID + 0x0077

#define ID_HEAD_TrackChangeConfig                        OWPML_HEAD_ID + 0x0078

#define ID_HEAD_DocOption_LicenseMark                    OWPML_HEAD_ID + 0x0079

#define ID_PARA_PType                                    OWPML_PARALIST_ID + 0x0001
#define ID_PARA_SectionDefinitionType                    OWPML_PARALIST_ID + 0x0002
#define ID_PARA_Ctrl                                     OWPML_PARALIST_ID + 0x0003
#define ID_PARA_T                                        OWPML_PARALIST_ID + 0x0004
#define ID_PARA_TableType                                OWPML_PARALIST_ID + 0x0005
#define ID_PARA_PictureType                              OWPML_PARALIST_ID + 0x0006
#define ID_PARA_OLEType                                  OWPML_PARALIST_ID + 0x0007
#define ID_PARA_ContainerType                            OWPML_PARALIST_ID + 0x0008
#define ID_PARA_EquationType                             OWPML_PARALIST_ID + 0x0009
#define ID_PARA_LineType                                 OWPML_PARALIST_ID + 0x000A
#define ID_PARA_RectangleType                            OWPML_PARALIST_ID + 0x000B
#define ID_PARA_EllipseType                              OWPML_PARALIST_ID + 0x000C
#define ID_PARA_ArcType                                  OWPML_PARALIST_ID + 0x000D
#define ID_PARA_PolygonType                              OWPML_PARALIST_ID + 0x000E
#define ID_PARA_CurveType                                OWPML_PARALIST_ID + 0x000F
#define ID_PARA_ConnectLineType                          OWPML_PARALIST_ID + 0x0010
#define ID_PARA_Textart                                  OWPML_PARALIST_ID + 0x0011
#define ID_PARA_Compose                                  OWPML_PARALIST_ID + 0x0012
#define ID_PARA_Dutmal                                   OWPML_PARALIST_ID + 0x0013
#define ID_PARA_AbstractButtonObjectType                 OWPML_PARALIST_ID + 0x0014
#define ID_PARA_ComboBoxType                             OWPML_PARALIST_ID + 0x0015
#define ID_PARA_ListBoxType                              OWPML_PARALIST_ID + 0x0016
#define ID_PARA_EditType                                 OWPML_PARALIST_ID + 0x0017
#define ID_PARA_ScrollBarType                            OWPML_PARALIST_ID + 0x0018
#define ID_PARA_ColumnDefType                            OWPML_PARALIST_ID + 0x0019
#define ID_PARA_FieldBegin                               OWPML_PARALIST_ID + 0x001A
#define ID_PARA_FieldEnd                                 OWPML_PARALIST_ID + 0x001B
#define ID_PARA_Bookmark                                 OWPML_PARALIST_ID + 0x001C
#define ID_PARA_HeaderFooterType                         OWPML_PARALIST_ID + 0x001D
#define ID_PARA_NoteType                                 OWPML_PARALIST_ID + 0x001E
#define ID_PARA_AutoNumNewNumType                        OWPML_PARALIST_ID + 0x001F
#define ID_PARA_PageNumCtrl                              OWPML_PARALIST_ID + 0x0020
#define ID_PARA_PageHiding                               OWPML_PARALIST_ID + 0x0021
#define ID_PARA_PageNum                                  OWPML_PARALIST_ID + 0x0022
#define ID_PARA_Indexmark                                OWPML_PARALIST_ID + 0x0023
#define ID_PARA_HiddenComment                            OWPML_PARALIST_ID + 0x0024
#define ID_PARA_ParameterList                            OWPML_PARALIST_ID + 0x0025
#define ID_PARA_ParaListType                             OWPML_PARALIST_ID + 0x0026
#define ID_PARA_FirstKey                                 OWPML_PARALIST_ID + 0x0027
#define ID_PARA_SecondKey                                OWPML_PARALIST_ID + 0x0028
#define ID_PARA_MarkpenBegin                             OWPML_PARALIST_ID + 0x0029
#define ID_PARA_MarkpenEnd                               OWPML_PARALIST_ID + 0x002A
#define ID_PARA_TitleMark                                OWPML_PARALIST_ID + 0x002B
#define ID_PARA_Tab                                      OWPML_PARALIST_ID + 0x002C
#define ID_PARA_LineBreak                                OWPML_PARALIST_ID + 0x002D
#define ID_PARA_Hypen                                    OWPML_PARALIST_ID + 0x002E
#define ID_PARA_NbSpace                                  OWPML_PARALIST_ID + 0x002F
#define ID_PARA_FwSpace                                  OWPML_PARALIST_ID + 0x0030
#define ID_PARA_TextartPr                                OWPML_PARALIST_ID + 0x0031
#define ID_PARA_Outline                                  OWPML_PARALIST_ID + 0x0032
#define ID_PARA_ShadowType                               OWPML_PARALIST_ID + 0x0033
#define ID_PARA_CharPr                                   OWPML_PARALIST_ID + 0x0034
#define ID_PARA_MainText                                 OWPML_PARALIST_ID + 0x0035
#define ID_PARA_SubText                                  OWPML_PARALIST_ID + 0x0036
#define ID_PARA_StartNum                                 OWPML_PARALIST_ID + 0x0037
#define ID_PARA_Grid                                     OWPML_PARALIST_ID + 0x0038
#define ID_PARA_Visibility                               OWPML_PARALIST_ID + 0x0039
#define ID_PARA_PagePr                                   OWPML_PARALIST_ID + 0x003A
#define ID_PARA_FootNoteShapeType                        OWPML_PARALIST_ID + 0x003B
#define ID_PARA_EndNoteShapeType                         OWPML_PARALIST_ID + 0x003C
#define ID_PARA_PageBorderFill                           OWPML_PARALIST_ID + 0x003D
#define ID_PARA_MasterPage                               OWPML_PARALIST_ID + 0x003E
#define ID_PARA_Margin                                   OWPML_PARALIST_ID + 0x003F
#define ID_PARA_PBFOffset                                OWPML_PARALIST_ID + 0x0040
#define ID_PARA_AutoNumFormatType                        OWPML_PARALIST_ID + 0x0041
#define ID_PARA_NoteLine                                 OWPML_PARALIST_ID + 0x0042
#define ID_PARA_NoteSpacing                              OWPML_PARALIST_ID + 0x0043
#define ID_PARA_FNNumbering                              OWPML_PARALIST_ID + 0x0044
#define ID_PARA_FNPlacement                              OWPML_PARALIST_ID + 0x0045
#define ID_PARA_ENNumbering                              OWPML_PARALIST_ID + 0x0046
#define ID_PARA_ENPlacement                              OWPML_PARALIST_ID + 0x0047
#define ID_PARA_ColLine                                  OWPML_PARALIST_ID + 0x0048
#define ID_PARA_ColSz                                    OWPML_PARALIST_ID + 0x0049
#define ID_PARA_Shadow                                   OWPML_PARALIST_ID + 0x004A
#define ID_PARA_Glow                                     OWPML_PARALIST_ID + 0x004B
#define ID_PARA_SoftEdge                                 OWPML_PARALIST_ID + 0x004C
#define ID_PARA_Reflection                               OWPML_PARALIST_ID + 0x004D
#define ID_PARA_SkewType                                 OWPML_PARALIST_ID + 0x004E
#define ID_PARA_ScaleType                                OWPML_PARALIST_ID + 0x004F
#define ID_PARA_EffectsColorType                         OWPML_PARALIST_ID + 0x0050
#define ID_PARA_Alpha                                    OWPML_PARALIST_ID + 0x0051
#define ID_PARA_RFPos                                    OWPML_PARALIST_ID + 0x0052
#define ID_PARA_Rgb                                      OWPML_PARALIST_ID + 0x0053
#define ID_PARA_Cmyk                                     OWPML_PARALIST_ID + 0x0054
#define ID_PARA_Scheme                                   OWPML_PARALIST_ID + 0x0055
#define ID_PARA_System                                   OWPML_PARALIST_ID + 0x0056
#define ID_PARA_Effect                                   OWPML_PARALIST_ID + 0x0057
#define ID_PARA_Sz                                       OWPML_PARALIST_ID + 0x0058
#define ID_PARA_Pos_1                                    OWPML_PARALIST_ID + 0x0059
#define ID_PARA_OutMargin                                OWPML_PARALIST_ID + 0x005A
#define ID_PARA_Caption                                  OWPML_PARALIST_ID + 0x005B
#define ID_PARA_ShapeComment                             OWPML_PARALIST_ID + 0x005C
#define ID_PARA_InsideMarginType                         OWPML_PARALIST_ID + 0x005D
#define ID_PARA_CellzoneList                             OWPML_PARALIST_ID + 0x005E
#define ID_PARA_Tr                                       OWPML_PARALIST_ID + 0x005F
#define ID_PARA_Cellzone                                 OWPML_PARALIST_ID + 0x0060
#define ID_PARA_Tc                                       OWPML_PARALIST_ID + 0x0061
#define ID_PARA_CellAddr                                 OWPML_PARALIST_ID + 0x0062
#define ID_PARA_CellSpan                                 OWPML_PARALIST_ID + 0x0063
#define ID_PARA_CellSz                                   OWPML_PARALIST_ID + 0x0064
#define ID_PARA_CellMargin                               OWPML_PARALIST_ID + 0x0065
#define ID_PARA_Script                                   OWPML_PARALIST_ID + 0x0066
#define ID_PARA_ASCOffset                                OWPML_PARALIST_ID + 0x0067
#define ID_PARA_OrgSz                                    OWPML_PARALIST_ID + 0x0068
#define ID_PARA_CurSz                                    OWPML_PARALIST_ID + 0x0069
#define ID_PARA_Flip                                     OWPML_PARALIST_ID + 0x006A
#define ID_PARA_RotationInfo                             OWPML_PARALIST_ID + 0x006B
#define ID_PARA_RenderingInfo                            OWPML_PARALIST_ID + 0x006C
#define ID_PARA_LineShapeType                            OWPML_PARALIST_ID + 0x006D
#define ID_PARA_ImgRect                                  OWPML_PARALIST_ID + 0x006E
#define ID_PARA_ImgClip                                  OWPML_PARALIST_ID + 0x006F
#define ID_PARA_EffectsType                              OWPML_PARALIST_ID + 0x0070
#define ID_PARA_DrawText                                 OWPML_PARALIST_ID + 0x0071
#define ID_PARA_TextMargin                               OWPML_PARALIST_ID + 0x0072
#define ID_PARA_Seg                                      OWPML_PARALIST_ID + 0x0073
#define ID_PARA_ConnectPointType                         OWPML_PARALIST_ID + 0x0074
#define ID_PARA_FormCharPr                               OWPML_PARALIST_ID + 0x0075
#define ID_PARA_ListItemType                             OWPML_PARALIST_ID + 0x0076
#define ID_PARA_Text                                     OWPML_PARALIST_ID + 0x0077
#define ID_PARA_BooleanParam                             OWPML_PARALIST_ID + 0x0078
#define ID_PARA_IntegerParam                             OWPML_PARALIST_ID + 0x0079
#define ID_PARA_FloatParam                               OWPML_PARALIST_ID + 0x007A
#define ID_PARA_StringParam                              OWPML_PARALIST_ID + 0x007B
#define ID_PARA_ASOPos                                   OWPML_PARALIST_ID + 0x007C
#define ID_PARA_AbstractShapeObjectType                  OWPML_PARALIST_ID + 0x007D
#define ID_PARA_AbstractShapeComponentType               OWPML_PARALIST_ID + 0x007E
#define ID_PARA_AbstractFormObjectType                   OWPML_PARALIST_ID + 0x007F
#define ID_PARA_AbstractDrawingObjectType                OWPML_PARALIST_ID + 0x0080
#define ID_PARA_Char                                     OWPML_PARALIST_ID + 0x0081
#define ID_PARA_HeaderType                               OWPML_PARALIST_ID + 0x0082
#define ID_PARA_FooterType                               OWPML_PARALIST_ID + 0x0083
#define ID_PARA_AutoNumType                              OWPML_PARALIST_ID + 0x0084
#define ID_PARA_NewNumType                               OWPML_PARALIST_ID + 0x0085
#define ID_PARA_FootNoteType                             OWPML_PARALIST_ID + 0x0086
#define ID_PARA_EndNoteType                              OWPML_PARALIST_ID + 0x0087
#define ID_PARA_AbstractCheckButtonObjectType            OWPML_PARALIST_ID + 0x0088
#define ID_PARA_AbstractRadioButtonObjectType            OWPML_PARALIST_ID + 0x0089
#define ID_PARA_ArrayParam                               OWPML_PARALIST_ID + 0x008A
#define ID_PARA_ConnectStartPointType                    OWPML_PARALIST_ID + 0x008B
#define ID_PARA_ConnectEndPointType                      OWPML_PARALIST_ID + 0x008C
#define ID_PARA_RunType                                  OWPML_PARALIST_ID + 0x008D
#define ID_PARA_LineSegArray                             OWPML_PARALIST_ID + 0x008E
#define ID_PARA_LineSeg                                  OWPML_PARALIST_ID + 0x008F
#define ID_PARA_VideoType                                OWPML_PARALIST_ID + 0x0090
#define ID_PARA_LineNumShape                             OWPML_PARALIST_ID + 0x0091
#define ID_PARA_UnknownChar                              OWPML_PARALIST_ID + 0x0092
#define ID_PARA_BindataParam                             OWPML_PARALIST_ID + 0x0093
#define ID_PARA_UnsignedIntegerParam                     OWPML_PARALIST_ID + 0x0094
#define ID_PARA_ChartType                                OWPML_PARALIST_ID + 0x0095
#define ID_PARA_PresentationType                         OWPML_PARALIST_ID + 0x0096
#define ID_PARA_LabelType                                OWPML_PARALIST_ID + 0x0097

#define ID_PARA_TC_InsertBegin                           OWPML_PARALIST_ID + 0x0098
#define ID_PARA_TC_InsertEnd                             OWPML_PARALIST_ID + 0x0099
#define ID_PARA_TC_DeleteBegin                           OWPML_PARALIST_ID + 0x009A
#define ID_PARA_TC_DeleteEnd                             OWPML_PARALIST_ID + 0x009B

#ifdef _GRAPH
#define ID_PARA_GraphType                                OWPML_PARALIST_ID + 0x009C
#endif // _GRAPH
#define ID_PARA_ImgDim                                   OWPML_PARALIST_ID + 0x009D

#define ID_PARA_METATAG                                  OWPML_PARALIST_ID + 0x009E

#define ID_PARA_ConnectControlPoints                     OWPML_PARALIST_ID + 0x00A0
#define ID_PARA_ConnectControlPointType                  OWPML_PARALIST_ID + 0x00A1

#define ID_PARA_SWITCH                                   OWPML_PARALIST_ID + 0x00B0
#define ID_PARA_CASE                                     OWPML_PARALIST_ID + 0x00B1
#define ID_PARA_DEFAULT                                  OWPML_PARALIST_ID + 0x00B2




#define ID_VERSION_Version                               OWPML_VERSION_ID + 0x0001
#define ID_APPLICATION_HWPApplicationSetting             OWPML_APPLICATION_ID + 0x0001
#define ID_APPLICATION_CaretPosition                     OWPML_APPLICATION_ID + 0x0002
#define ID_APPLICATION_ParameterItemtype                 OWPML_APPLICATION_ID + 0x0003
#define ID_APPLICATION_ParameterSetType                  OWPML_APPLICATION_ID + 0x0004
#define ID_APPLICATION_ParameterArrayType                OWPML_APPLICATION_ID + 0x0005
#define ID_APPLICATION_ParameterBinary                   OWPML_APPLICATION_ID + 0x0006

#define ID_BODY_SectionType                              OWPML_BODY_ID + 0x0001
#define ID_HISTORY_HWPMLHistoryType                      OWPML_HISTORY_ID + 0x0001
#define ID_HISTORY_HistoryEntryType                      OWPML_HISTORY_ID + 0x0002
#define ID_HISTORY_PackageDiffEntryType                  OWPML_HISTORY_ID + 0x0003
#define ID_HISTORY_HeadDiffEntryType                     OWPML_HISTORY_ID + 0x0004
#define ID_HISTORY_BodyDiffEntryType                     OWPML_HISTORY_ID + 0x0005
#define ID_HISTORY_TailDiffEntryType                     OWPML_HISTORY_ID + 0x0006
#define ID_HISTORY_InsertType                            OWPML_HISTORY_ID + 0x0007
#define ID_HISTORY_UpdateType                            OWPML_HISTORY_ID + 0x0008
#define ID_HISTORY_DeleteType                            OWPML_HISTORY_ID + 0x0009
#define ID_HISTORY_PositionType                          OWPML_HISTORY_ID + 0x000A
#define ID_HISTORY_AnyType                               OWPML_HISTORY_ID + 0x000B
#define ID_MASTERPAGE_MasterPageType                     OWPML_MASTERPAGE_ID + 0x0001



#define ID_CORE_FillBrushType                            OWPML_CORE_ID + 0x0001
#define ID_CORE_ImageType                                OWPML_CORE_ID + 0x0002
#define ID_CORE_HWPValue                                 OWPML_CORE_ID + 0x0003
#define ID_CORE_PointType                                OWPML_CORE_ID + 0x0004
#define ID_CORE_MatrixType                               OWPML_CORE_ID + 0x0005
#define ID_CORE_WinBrush                                 OWPML_CORE_ID + 0x0006
#define ID_CORE_Gradation                                OWPML_CORE_ID + 0x0007
#define ID_CORE_ImgBrush                                 OWPML_CORE_ID + 0x0008
#define ID_CORE_Color                                    OWPML_CORE_ID + 0x0009
#define ID_CORE_Margin_Indent                            OWPML_CORE_ID + 0x000A
#define ID_CORE_Margin_Left                              OWPML_CORE_ID + 0x000B
#define ID_CORE_Margin_Right                             OWPML_CORE_ID + 0x000C
#define ID_CORE_Margin_Prev                              OWPML_CORE_ID + 0x000D
#define ID_CORE_Margin_Next                              OWPML_CORE_ID + 0x000E

#define ID_CORE_PointType_Pt0                            OWPML_CORE_ID + 0x000F
#define ID_CORE_PointType_Pt1                            OWPML_CORE_ID + 0x0010
#define ID_CORE_PointType_Pt2                            OWPML_CORE_ID + 0x0011
#define ID_CORE_PointType_Pt3                            OWPML_CORE_ID + 0x0012

#define ID_CORE_PointType_Center                         OWPML_CORE_ID + 0x0013
#define ID_CORE_PointType_Ax1                            OWPML_CORE_ID + 0x0014
#define ID_CORE_PointType_Ax2                            OWPML_CORE_ID + 0x0015

#define ID_CORE_PointType_Start1                         OWPML_CORE_ID + 0x0016
#define ID_CORE_PointType_Start2                         OWPML_CORE_ID + 0x0017
#define ID_CORE_PointType_End1                           OWPML_CORE_ID + 0x0018
#define ID_CORE_PointType_End2                           OWPML_CORE_ID + 0x0019

#define ID_CORE_MatrixType_Trans                         OWPML_CORE_ID + 0x001A
#define ID_CORE_MatrixType_Sca                           OWPML_CORE_ID + 0x001B
#define ID_CORE_MatrixType_Rot                           OWPML_CORE_ID + 0x001C


#define ID_OPF_Package                                   OWPML_OPF_ID + 0x0001
#define ID_OPF_MetadataType                              OWPML_OPF_ID + 0x0002
#define ID_OPF_ManifestType                              OWPML_OPF_ID + 0x0003
#define ID_OPF_SpineType                                 OWPML_OPF_ID + 0x0004
#define ID_OPF_ToursType                                 OWPML_OPF_ID + 0x0005
#define ID_OPF_GuideType                                 OWPML_OPF_ID + 0x0006
#define ID_OPF_Title                                     OWPML_OPF_ID + 0x0007
#define ID_OPF_Language                                  OWPML_OPF_ID + 0x0008
#define ID_OPF_Identifier                                OWPML_OPF_ID + 0x0009
#define ID_OPF_Meta                                      OWPML_OPF_ID + 0x000A
#define ID_OPF_Item                                      OWPML_OPF_ID + 0x000B
#define ID_OPF_Itemref                                   OWPML_OPF_ID + 0x000C
#define ID_OPF_Tour                                      OWPML_OPF_ID + 0x000D
#define ID_OPF_Site                                      OWPML_OPF_ID + 0x000E
#define ID_OPF_Reference                                 OWPML_OPF_ID + 0x000F

#define ID_CON_Container                                 OWPML_CONTAINER_ID + 0x0001
#define ID_CON_RootFiles                                 OWPML_CONTAINER_ID + 0x0002
#define ID_CON_RootFile                                  OWPML_CONTAINER_ID + 0x0003

#define ID_ODF_Manifest                                  OWPML_ODF_MANIFEST_ID + 0x0001
#define ID_ODF_FileEntry                                 OWPML_ODF_MANIFEST_ID + 0x0002
#define ID_ODF_EncryptionData                            OWPML_ODF_MANIFEST_ID + 0x0003
#define ID_ODF_Algorithm                                 OWPML_ODF_MANIFEST_ID + 0x0004
#define ID_ODF_KeyDerivation                             OWPML_ODF_MANIFEST_ID + 0x0005
#define ID_ODF_StartKeyGerneration                       OWPML_ODF_MANIFEST_ID + 0x0006
#define ID_ODF_ConfigItemSet                             OWPML_ODF_MANIFEST_ID + 0x0007
#define ID_ODF_ConfigItem                                OWPML_ODF_MANIFEST_ID + 0x0008


#define ID_SIG_signatures                                OWPML_SECURITY_ID + 0x0001
#define ID_SIG_PublicKey                                 OWPML_SECURITY_ID + 0x0002
#define ID_DOC_Distribute                                OWPML_SECURITY_ID + 0x0003

#define ID_PARA_Unknown_ID                               OWPML_UNKNOWN_ID + 0X0001
#define ID_PARA_UnknownObject_ID                         OWPML_UNKNOWN_ID + 0X0002


#define ID_STRING_ANYELEMENT_ID                          OWPML_EXTELEMENT_ID + 0X0001
#define ID_ANYELEMENT_ID                                 OWPML_EXTELEMENT_ID + 0X0002

#define ID_EPUB_SWITCH                                   OWPML_EXTELEMENT_ID + 0X0005
#define ID_EPUB_CASE                                     OWPML_EXTELEMENT_ID + 0X0006
#define ID_EPUB_DEFAULT                                  OWPML_EXTELEMENT_ID + 0X0007



#define ID_RDF_RDF                                       OWPML_RDF_ID + 0X0001
#define ID_RDF_DESCRIPTION                               OWPML_RDF_ID + 0X0002
#define ID_RDF_TYPE                                      OWPML_RDF_ID + 0X0003
#define ID_RDF_ANYELEMENT                                OWPML_RDF_ID + 0X0004


}

#endif //