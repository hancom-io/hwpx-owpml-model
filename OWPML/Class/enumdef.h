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

#ifndef _OWPML_ENUMDEF_H_
#define _OWPML_ENUMDEF_H_

namespace OWPML {

    typedef enum
    {
        CT_HWP201X = 0x00000000,
        CT_HWP200X = 0x00000001,
        CT_MSWORD = 0x00000002,
        CT_HUNMIN = 0x00000004
    } COMPATIBLEDOCTYPE;

    static const ENUMLIST g_CompatiblieDocList[] = {
        {    CT_HWP201X,                             L"HWP201X"    },
        {    CT_HWP200X,                             L"HWP200X"    },
        {    CT_MSWORD,                              L"MS_WORD"    },
        {    CT_HUNMIN,                              L"Hunmin"     },
        {    0,                                      NULL          }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        FLT_HANGUL,
        FLT_LATIN,
        FLT_HANJA,
        FLT_JAPANESE,
        FLT_OTHER,
        FLT_SYMBOL,
        FLT_USER
    } FONTFACELANGTYPE;

    static const ENUMLIST g_FontFaceLangList[] = {
        {    FLT_HANGUL,                         L"HANGUL"     },
        {    FLT_LATIN,                          L"LATIN"      },
        {    FLT_HANJA,                          L"HANJA"      },
        {    FLT_JAPANESE,                       L"JAPANESE"   },
        {    FLT_OTHER,                          L"OTHER"      },
        {    FLT_SYMBOL,                         L"SYMBOL"     },
        {    FLT_USER,                           L"USER"       },
        {    0,                                  NULL          }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        CLT_NONE,
        CLT_VERTICAL,
        CLT_HORIZONTAL,
        CLT_CROSS
    } CENTERLINETYPE;

    static const ENUMLIST g_CenterLineList[] = {
        {    CLT_NONE,                             L"NONE"         },
        {    CLT_VERTICAL,                         L"VERTICAL"     },
        {    CLT_HORIZONTAL,                       L"HORIZONTAL"   },
        {    CLT_CROSS,                            L"CROSS"        },
        {    0,                                    NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SMT_NONE,
        SMT_DOT_ABOVE,
        SMT_RING_ABOVE,
        SMT_TILDE,
        SMT_CARON,
        SMT_SIDE,
        SMT_COLON,
        SMT_GRAVE_ACCENT,
        SMT_ACUTE_ACCENT,
        SMT_CIRCUMFLEX,
        SMT_MACRON,
        SMT_HOOK_ABOVE,
        SMT_DOT_BELOW,
    } SYMBOLMARKTYPE;

    static const ENUMLIST g_SymblolMarkList[] = {
        {    SMT_NONE,                             L"NONE"           },
        {    SMT_DOT_ABOVE,                        L"DOT_ABOVE"      },
        {    SMT_RING_ABOVE,                       L"RING_ABOVE"     },
        {    SMT_TILDE,                            L"TILDE"          },
        {    SMT_CARON,                            L"CARON"          },
        {    SMT_SIDE,                             L"SIDE"           },
        {    SMT_COLON,                            L"COLON"          },
        {    SMT_GRAVE_ACCENT,                     L"GRAVE_ACCENT"   },
        {    SMT_ACUTE_ACCENT,                     L"ACUTE_ACCENT"   },
        {    SMT_CIRCUMFLEX,                       L"CIRCUMFLEX"     },
        {    SMT_MACRON,                           L"MACRON"         },
        {    SMT_HOOK_ABOVE,                       L"HOOK_ABOVE"     },
        {    SMT_DOT_BELOW,                        L"DOT_BELOW"      },
        {    0,                                    NULL              }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ST_PARA,
        ST_CHAR
    } STYLETYPE;

    static const ENUMLIST g_StyleList[] = {
        {    ST_PARA,                             L"PARA"        },
        {    ST_CHAR,                             L"CHAR"        },
        {    0,                                   NULL           }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LT2_NONE = 0,
        LT2_SOLID,
        LT2_DOT,
        LT2_DASH,
        LT2_DASH_DOT,
        LT2_DASH_DOT_DOT,
        LT2_LONG_DASH,
        LT2_CIRCLE,
        LT2_DOUBLE_SLIM,
        LT2_SLIM_THICK,
        LT2_THICK_SLIM,
        LT2_SLIM_THICK_SLIM,
        LT2_WAVE,
        LT2_DOUBLEWAVE,
        LT2_THICK3D,
        LT2_THICKREV3D,
        LT2_3D,
        LT2_REV3D
    } LINETYPE2;

    static const ENUMLIST g_LineTypeList2[] = {
        {    LT2_NONE,                             L"NONE"               },
        {    LT2_SOLID,                            L"SOLID"              },
        {    LT2_DOT,                              L"DOT"                },
        {    LT2_DASH,                             L"DASH"               },
        {    LT2_DASH_DOT,                         L"DASH_DOT"           },
        {    LT2_DASH_DOT_DOT,                     L"DASH_DOT_DOT"       },
        {    LT2_LONG_DASH,                        L"LONG_DASH"          },
        {    LT2_CIRCLE,                           L"CIRCLE"             },
        {    LT2_DOUBLE_SLIM,                      L"DOUBLE_SLIM"        },
        {    LT2_SLIM_THICK,                       L"SLIM_THICK"         },
        {    LT2_THICK_SLIM,                       L"THICK_SLIM"         },
        {    LT2_SLIM_THICK_SLIM,                  L"SLIM_THICK_SLIM"    },
        {    LT2_WAVE,                             L"WAVE"               },
        {    LT2_DOUBLEWAVE,                       L"DOUBLEWAVE"         },
        {    LT2_THICK3D,                          L"THICK3D"            },
        {    LT2_THICKREV3D,                       L"THICKREV3D"         },
        {    LT2_3D,                               L"3D"                 },
        {    LT2_REV3D,                            L"REV3D"              },
        {    0,                                    NULL                  }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        MST_NOMAL,
        MST_USER_INSERT,
        MST_USER_DELETE,
        MST_USER_UPDATE
    } MEMOSHAPETYPE;

    static const ENUMLIST g_MemoShapeTypeList[] = {
        {    MST_NOMAL,                                 L"NOMAL"        },
        {    MST_USER_INSERT,                           L"USER_INSERT"  },
        {    MST_USER_DELETE,                           L"USER_DELETE"  },
        {    MST_USER_UPDATE,                           L"USER_UPDATE"  },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        FT_REP,
        FT_TTF,
        FT_HFT
    } FONTTYPE;

    static const ENUMLIST g_FontTypeList[] = {
        {    FT_REP,                                 L"REP"    },
        {    FT_TTF,                                 L"TTF"    },
        {    FT_HFT,                                 L"HFT"    },
        {    0,                                      NULL      }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SFT_REP,
        SFT_TTF,
        SFT_HFT
    } SUBSFONTTYPE;

    static const ENUMLIST g_SubsFontTypeList[] = {
        {    SFT_REP,                                 L"REP"    },
        {    SFT_TTF,                                 L"TTF"    },
        {    SFT_HFT,                                 L"HFT"    },
        {    0,                                       NULL      }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        FT_FCAT_UNKNOWN = 0 /*FCAT_UNKNOWN*/,
        FT_FCAT_MYUNGJO = 1 /*FCAT_MYUNGJO*/,
        FT_FCAT_GOTHIC = 2 /*FCAT_GOTHIC*/,
        FT_FCAT_SSERIF = 3 /*FCAT_SSERIF*/,
        FT_FCAT_BRUSHSCRIPT = 4 /*FCAT_BRUSHSCRIPT*/,
        FT_FCAT_DECORATIVE = 5 /*FCAT_DECORATIVE*/,
        FT_FCAT_NONRECTMJ = 6 /*FCAT_NONRECTMJ*/,
        FT_FCAT_NONRECTGT = 7 /*FCAT_NONRECTGT*/
    } FAMILYTYPE;

    static const ENUMLIST g_FamilyTypeList[] = {
        {    FT_FCAT_UNKNOWN,                     L"FCAT_UNKNOWN"        },
        {    FT_FCAT_MYUNGJO,                     L"FCAT_MYUNGJO"        },
        {    FT_FCAT_GOTHIC,                      L"FCAT_GOTHIC"         },
        {    FT_FCAT_SSERIF,                      L"FCAT_SSERIF"         },
        {    FT_FCAT_BRUSHSCRIPT,                 L"FCAT_BRUSHSCRIPT"    },
        {    FT_FCAT_DECORATIVE,                  L"FCAT_DECORATIVE"     },
        {    FT_FCAT_NONRECTMJ,                   L"FCAT_NONRECTMJ"      },
        {    FT_FCAT_NONRECTGT,                   L"FCAT_NONRECTGT"      },
        {    0,                                   NULL                   }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SLT_NONE = 0,
        SLT_CENTER = 2,
        SLT_CENTER_BELOW = 3,
        SLT_CENTER_ABOVE = 6,
        SLT_ALL = 7
    } SLASHTYPE;

    static const ENUMLIST g_SlashTypeList[] = {
        {   SLT_NONE,                               L"NONE"          },
        {    SLT_CENTER,                            L"CENTER"        },
        {    SLT_CENTER_BELOW,                      L"CENTER_BELOW"  },
        {    SLT_CENTER_ABOVE,                      L"CENTER_ABOVE"  },
        {    SLT_ALL,                               L"ALL"           },
        {    0,                                     NULL             }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LWT_0_1 = 0,    // HWPBF_WIDTH_0010
        LWT_0_12,       // HWPBF_WIDTH_0012
        LWT_0_15,       // HWPBF_WIDTH_0015
        LWT_0_2,        // HWPBF_WIDTH_0020
        LWT_0_25,       // HWPBF_WIDTH_0025
        LWT_0_3,        // HWPBF_WIDTH_0030
        LWT_0_4,        // HWPBF_WIDTH_0040
        LWT_0_5,        // HWPBF_WIDTH_0050
        LWT_0_6,        // HWPBF_WIDTH_0060
        LWT_0_7,        // HWPBF_WIDTH_0070
        LWT_1_0,        // HWPBF_WIDTH_0100
        LWT_1_5,        // HWPBF_WIDTH_0150
        LWT_2_0,        // HWPBF_WIDTH_0200
        LWT_3_0,        // HWPBF_WIDTH_0300
        LWT_4_0,        // HWPBF_WIDTH_0400
        LWT_5_0         // HWPBF_WIDTH_0500
    } LINEWITHTYPE;

    static const ENUMLIST g_LineWithList[] = {
        {    LWT_0_1,                             L"0.1 mm"    },
        {    LWT_0_12,                             L"0.12 mm"    },
        {    LWT_0_15,                             L"0.15 mm"    },
        {    LWT_0_2,                             L"0.2 mm"    },
        {    LWT_0_25,                             L"0.25 mm"    },
        {    LWT_0_3,                             L"0.3 mm"    },
        {    LWT_0_4,                             L"0.4 mm"    },
        {    LWT_0_5,                             L"0.5 mm"    },
        {    LWT_0_6,                             L"0.6 mm"    },
        {    LWT_0_7,                             L"0.7 mm"    },
        {    LWT_1_0,                             L"1.0 mm"    },
        {    LWT_1_5,                             L"1.5 mm"    },
        {    LWT_2_0,                             L"2.0 mm"    },
        {    LWT_3_0,                             L"3.0 mm"    },
        {    LWT_4_0,                             L"4.0 mm"    },
        {    LWT_5_0,                             L"5.0 mm"    },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ULT_NONE = 0,
        ULT_BOTTOM,
        ULT_CENTER,
        ULT_TOP
    } UNDERLINETYPE;

    static const ENUMLIST g_UnderlineTypeList[] = {
        {   ULT_NONE,                               L"NONE" },
        {    ULT_BOTTOM,                             L"BOTTOM"    },
        {    ULT_CENTER,                             L"CENTER"    },
        {    ULT_TOP,                                 L"TOP"        },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LT1_NONE = 0,
        LT1_SOLID,
        LT1_DOT,
        LT1_THICK,
        LT1_DASH,
        LT1_DASH_DOT,
        LT1_DASH_DOT_DOT
    } LINETYPE1;

    static const ENUMLIST g_LineTypeList1[] = {
        {    LT1_NONE,                             L"NONE"            },
        {    LT1_SOLID,                             L"SOLID"        },
        {    LT1_DOT,                             L"DOT"            },
        {    LT1_THICK,                             L"THICK"        },
        {    LT1_DASH,                             L"DASH"            },
        {    LT1_DASH_DOT,                         L"DASH_DOT"        },
        {    LT1_DASH_DOT_DOT,                     L"DASH_DOT_DOT"    },
        {    0,                                     NULL            }
    };


    ///////////////////////////////////////////////////////////////////

    // ���� �׸���
    typedef enum
    {
        CSHT_NONE = 0,
        CSHT_DROP,
        CSHT_CONTINUOUS
    } CSHADOWTYPE;

    static const ENUMLIST g_CharShadowTypeList[] = {
        {    CSHT_NONE,                                 L"NONE"            },
        {    CSHT_DROP,                                 L"DROP"            },
        {    CSHT_CONTINUOUS,                         L"CONTINUOUS"    },
        {    0,                                         NULL            }
    };

    // ���� �׸���
    typedef enum
    {
        SHT_NONE = 0,
        SHT_PARELLEL_LEFTTOP,
        SHT_PARELLEL_RIGHTTOP,
        SHT_PARELLEL_LEFTBOTTOM,
        SHT_PARELLEL_RIGHTBOTTOM,
        SHT_SHEAR_LEFTTOP,
        SHT_SHEAR_RIGHTTOP,
        SHT_SHEAR_LEFTBOTTOM,
        SHT_SHEAR_RIGHTBOTTOM,
        SHT_PERS_LEFTTOP,
        SHT_PERS_RIGHTTOP,
        SHT_PERS_LEFTBOTTOM,
        SHT_PERS_RIGHTBOTTOM,
        SHT_SCALE_NARROW,
        SHT_SCALE_ENLARGE,
    } SHADOWTYPE;

    static const ENUMLIST g_ShadowTypeList[] = {
        { SHT_NONE,                 L"NONE" },
        { SHT_PARELLEL_LEFTTOP,     L"PARELLEL_LEFTTOP" },
        { SHT_PARELLEL_RIGHTTOP,    L"PARELLEL_RIGHTTOP" },
        { SHT_PARELLEL_LEFTBOTTOM,  L"PARELLEL_LEFTBOTTOM" },
        { SHT_PARELLEL_RIGHTBOTTOM, L"PARELLEL_RIGHTBOTTOM" },
        { SHT_SHEAR_LEFTTOP,        L"SHEAR_LEFTTOP" },
        { SHT_SHEAR_RIGHTTOP,       L"SHEAR_RIGHTTOP" },
        { SHT_SHEAR_LEFTBOTTOM,     L"SHEAR_LEFTBOTTOM" },
        { SHT_SHEAR_RIGHTBOTTOM,    L"SHEAR_RIGHTBOTTOM" },
        { SHT_PERS_LEFTTOP,         L"PERS_LEFTTOP" },
        { SHT_PERS_RIGHTTOP,        L"PERS_RIGHTTOP" },
        { SHT_PERS_LEFTBOTTOM,      L"PERS_LEFTBOTTOM" },
        { SHT_PERS_RIGHTBOTTOM,     L"PERS_RIGHTBOTTOM" },
        { SHT_SCALE_NARROW,         L"SCALE_NARROW" },
        { SHT_SCALE_ENLARGE,        L"SCALE_ENLARGE" },

        { SHT_PARELLEL_LEFTTOP,     L"DROP" },              // �������� ȣȯ�� read������ ����
        { SHT_PARELLEL_RIGHTTOP,    L"CONTINUOUS" },       // �������� ȣȯ�� read������ ����
        { 0,                        NULL }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TIT_LEFT = 0,
        TIT_RIGHT,
        TIT_CENTER,
        TIT_DECIMAL,
        TIT_VERTBAR,
    } TABITEMTYPE;

    static const ENUMLIST g_TabItemTypeList[] = {
        {    TIT_LEFT,                                 L"LEFT"        },
        {    TIT_RIGHT,                                 L"RIGHT"    },
        {    TIT_CENTER,                             L"CENTER"    },
        {    TIT_DECIMAL,                             L"DECIMAL"    },
        {    TIT_VERTBAR,                             L"VERTBAR"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PHAT_LEFT = 0,
        PHAT_CENTER,
        PHAT_RIGHT
    } PHALIGNTYPE;

    static const ENUMLIST g_ParaHeadAlignList[] = {
        {    PHAT_LEFT,                             L"LEFT"        },
        {    PHAT_CENTER,                         L"CENTER"    },
        {    PHAT_RIGHT,                         L"RIGHT"    },
        {    0,                                     NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TOT_PERCENT = 0,
        TOT_HWPUNIT
    } TEXTOFFSETTYPE;

    static const ENUMLIST g_TextOffsetTypeList[] = {
        {    TOT_PERCENT,                             L"PERCENT"    },
        {    TOT_HWPUNIT,                             L"HWPUNIT"    },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        IET_REAL_PIC = 0,
        IET_GRAY_SCALE,
        IET_BLACK_WHITE
    } IMAGEEFFECTTYPE;

    static const ENUMLIST g_ImageEffectList[] = {
        {    IET_REAL_PIC,                             L"REAL_PIC"        },
        {    IET_GRAY_SCALE,                         L"GRAY_SCALE"    },
        {    IET_BLACK_WHITE,                         L"BLACK_WHITE"    },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        AH_JUSTIFY = 0,
        AH_LEFT,
        AH_RIGHT,
        AH_CENTER,
        AH_DISTRIBUTE,
        AH_DISTRIBUTE_SPACE
    } ALIGNHORZ;

    static const ENUMLIST g_AlignHorizontalList[] = {
        {    AH_JUSTIFY,                         L"JUSTIFY"            },
        {    AH_LEFT,                             L"LEFT"                },
        {    AH_RIGHT,                             L"RIGHT"            },
        {    AH_CENTER,                             L"CENTER"            },
        {    AH_DISTRIBUTE,                         L"DISTRIBUTE"        },
        {    AH_DISTRIBUTE_SPACE,                 L"DISTRIBUTE_SPACE"    },
        {    0,                                     NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        AV_BASELINE = 0,
        AV_TOP,
        AV_CENTER,
        AV_BOTTOM
    } ALIGNVERT;

    static const ENUMLIST g_AlignVerticalList[] = {
        {    AV_BASELINE,                         L"BASELINE"    },
        {    AV_TOP,                             L"TOP"        },
        {    AV_CENTER,                             L"CENTER"    },
        {    AV_BOTTOM,                             L"BOTTOM"    },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        HT_NONE = 0,
        HT_OUTLINE,
        HT_NUMBER,
        HT_BULLET
    } HEADINGTYPE;

    static const ENUMLIST g_HeadingTypeList[] = {
        {    HT_NONE,                             L"NONE"        },
        {    HT_OUTLINE,                         L"OUTLINE"    },
        {    HT_NUMBER,                             L"NUMBER"    },
        {    HT_BULLET,                             L"BULLET"    },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        BT_KEEP_WORD = 0,
        BT_HYPHENATION,
        BT_BREAK_WORD
    } BRLATINTYPE;

    static const ENUMLIST g_BreakLatinWordList[] = {
        {    BT_KEEP_WORD,                         L"KEEP_WORD"    },
        {    BT_HYPHENATION,                     L"HYPHENATION"    },
        {    BT_BREAK_WORD,                         L"BREAK_WORD"    },
        {    0,                                     NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        BLT_KEEP_WORD = 0,
        BLT_BREAK_WORD
    } BRNONLATINTYPE;

    static const ENUMLIST g_BreakNonLatinWordList[] = {
        {    BLT_KEEP_WORD,                             L"KEEP_WORD"    },
        {    BLT_BREAK_WORD,                         L"BREAK_WORD"    },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LWT_BREAK = 0,
        LWT_SQUEEZE,
        LWT_KEEP
    } LINEWRAPTYPE;

    static const ENUMLIST g_LineWrapList[] = {
        {    LWT_BREAK,                             L"BREAK"    },
        {    LWT_SQUEEZE,                         L"SQUEEZE"    },
        {    LWT_KEEP,                             L"KEEP"        },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LST_PERCENT = 0,
        LST_FIXED,
        LST_BETWEEN_LINES,
        LST_AT_LEAST
    } LSTYPE;

    static const ENUMLIST g_LinespacingTypeList[] = {
        {    LST_PERCENT,                         L"PERCENT"            },
        {    LST_FIXED,                             L"FIXED"            },
        {    LST_BETWEEN_LINES,                     L"BETWEEN_LINES"    },
        {    LST_AT_LEAST,                         L"AT_LEAST"            },
        {    0,                                     NULL                }
    };


    typedef enum
    {
        UVT_CHAR = 0,
        UVT_HWPUNIT
    } UINTVALUETYPE;

    static const ENUMLIST g_LinespacingUnitList[] = {
        {    UVT_CHAR,                                 L"CHAR"        },
        {    UVT_HWPUNIT,                             L"HWPUNIT"    },
        {    0,                                         NULL        }
    };

    static const ENUMLIST g_UnitValueList[] = {
        {    UVT_CHAR,                                 L"CHAR"        },
        {    UVT_HWPUNIT,                             L"HWPUNIT"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SCT_CHAR = 0,
        SCT_SHAPE_CIRCLE,
        SCT_SHAPE_REVERSAL_CIRCLE,
        SCT_SHAPE_RECTANGLE,
        SCT_SHAPE_REVERSAL_RECTANGLE,
        SCT_SHAPE_TRIANGLE,
        SCT_SHAPE_REVERSAL_TIRANGLE,
        SCT_SHAPE_LIGHT,
        SCT_SHAPE_RHOMBUS,
        SCT_SHAPE_REVERSAL_RHOMBUS,
        SCT_SHAPE_ROUNDED_RECTANGLE,
        SCT_SHAPE_EMPTY_CIRCULATE_TRIANGLE,
        SCT_SHAPE_THIN_CIRCULATE_TRIANGLE,
        SCT_SHAPE_THICK_CIRCULATE_TRIANGLE
    } SHAPECIRCLETYPE;

    static const ENUMLIST g_ShapeCircleList[] = {
        {    SCT_CHAR,                                 L"CHAR"                                },
        {    SCT_SHAPE_CIRCLE,                         L"SHAPE_CIRCLE"                        },
        {    SCT_SHAPE_REVERSAL_CIRCLE,                 L"SHAPE_REVERSAL_CIRCLE"            },
        {    SCT_SHAPE_RECTANGLE,                     L"SHAPE_RECTANGLE"                    },
        {    SCT_SHAPE_REVERSAL_RECTANGLE,            L"SHAPE_REVERSAL_RECTANGLE"            },
        {    SCT_SHAPE_TRIANGLE,                     L"SHAPE_TRIANGLE"                    },
        {    SCT_SHAPE_REVERSAL_TIRANGLE,             L"SHAPE_REVERSAL_TIRANGLE"            },
        {    SCT_SHAPE_LIGHT,                         L"SHAPE_LIGHT"                        },
        {    SCT_SHAPE_RHOMBUS,                         L"SHAPE_RHOMBUS"                    },
        {    SCT_SHAPE_REVERSAL_RHOMBUS,             L"SHAPE_REVERSAL_RHOMBUS"            },
        {    SCT_SHAPE_ROUNDED_RECTANGLE,             L"SHAPE_ROUNDED_RECTANGLE"            },
        {    SCT_SHAPE_EMPTY_CIRCULATE_TRIANGLE,     L"SHAPE_EMPTY_CIRCULATE_TRIANGLE"    },
        {    SCT_SHAPE_THIN_CIRCULATE_TRIANGLE,         L"SHAPE_THIN_CIRCULATE_TRIANGLE"    },
        {    SCT_SHAPE_THICK_CIRCULATE_TRIANGLE,     L"SHAPE_THICK_CIRCULATE_TRIANGLE"    },
        {    0,                                         NULL                                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        CT_SPREAD = 0,
        CT_OVERLAP
    } COMPOSETYPE;

    static const ENUMLIST g_ComposeList[] = {
        {    CT_SPREAD,                                 L"SPREAD"    },
        {    CT_OVERLAP,                             L"OVERLAP"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        DPT_TOP = 0,
        DPT_BOTTOM
    } DUTMALPOSTYPE;

    static const ENUMLIST g_DutmalPosList[] = {
        {    DPT_TOP,                                 L"TOP"        },
        {    DPT_BOTTOM,                             L"BOTTOM"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        DAT_JUSTIFY = 0,
        DAT_LEFT,
        DAT_RIGHT,
        DAT_CENTER,
        DAT_DISTRIBUTE,
        DAT_DISTRIBUTE_SPACE
    } DUTMALALIGNTYPE;

    static const ENUMLIST g_DutmalAlignList[] = {
        {    DAT_JUSTIFY,                         L"JUSTIFY"            },
        {    DAT_LEFT,                             L"LEFT"                },
        {    DAT_RIGHT,                             L"RIGHT"            },
        {    DAT_CENTER,                         L"CENTER"            },
        {    DAT_DISTRIBUTE,                     L"DISTRIBUTE"        },
        {    DAT_DISTRIBUTE_SPACE,                 L"DISTRIBUTE_SPACE"    },
        {    0,                                     NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        FT_NONE = -1,
        FT_CLICK_HERE = 0,
        FT_HYPERLINK,
        FT_BOOKMARK,
        FT_FORMULA,
        FT_SUMMERY,
        FT_USER_INFO,
        FT_DATE,
        FT_DOC_DATE,
        FT_PATH,
        FT_CROSSREF,
        FT_MAILMERGE,
        FT_MEMO,
        FT_PROOFREADING_MARKS_CHANGE,
        FT_PROOFREADING_MARKS_SIGN,
        FT_PROOFREADING_MARKS_DELETE,
        FT_PROOFREADING_MARKS_ATTACH,
        FT_PROOFREADING_MARKS_CLIPPING,
        FT_PROOFREADING_MARKS_SAWTOOTH,
        FT_PROOFREADING_MARKS_THINKING,
        FT_PROOFREADING_MARKS_PRAISE,
        FT_PROOFREADING_MARKS_LINE,
        FT_PROOFREADING_MARKS_SIMPLECHANGE,
        FT_PROOFREADING_MARKS_HYPERLINK,
        FT_PROOFREADING_MARKS_LINEATTACH,
        FT_PROOFREADING_MARKS_LINELINK,
        FT_PROOFREADING_MARKS_LINETRANSFER,
        FT_PROOFREADING_MARKS_RIGHTMOVE,
        FT_PROOFREADING_MARKS_LEFTMOVE,
        FT_PROOFREADING_MARKS_TRANSFER,
        FT_PROOFREADING_MARKS_SPLIT,
        FT_PROOFREADING_MARKS_SIMPLEINSERT,
        FT_PRIVATE_INFO,
        FT_TABLEOFCONTENTS,
        FT_CITATION,
        FT_BIBLIOGRAPHY,
        FT_METADATA,
    } FIELDTYPE;


    static const ENUMLIST g_FieldList[] = {
        {    FT_CLICK_HERE,                             L"CLICK_HERE"                            },
        {    FT_HYPERLINK,                             L"HYPERLINK"                            },
        {    FT_BOOKMARK,                             L"BOOKMARK"                                },
        {    FT_FORMULA,                             L"FORMULA"                                },
        {    FT_SUMMERY,                             L"SUMMERY"                                },
        {    FT_USER_INFO,                             L"USER_INFO"                            },
        {    FT_DATE,                                 L"DATE"                                    },
        {    FT_DOC_DATE,                             L"DOC_DATE"                                },
        {    FT_PATH,                                 L"PATH"                                    },
        {    FT_CROSSREF,                             L"CROSSREF"                                },
        {    FT_MAILMERGE,                             L"MAILMERGE"                            },
        {    FT_MEMO,                                 L"MEMO"                                    },
        {    FT_PROOFREADING_MARKS_CHANGE,            L"PROOFREADING_MARKS_CHANGE"            },
        {    FT_PROOFREADING_MARKS_SIGN,                L"PROOFREADING_MARKS_SIGN"                },
        {    FT_PROOFREADING_MARKS_DELETE,            L"PROOFREADING_MARKS_DELETE"            },
        {    FT_PROOFREADING_MARKS_ATTACH,            L"PROOFREADING_MARKS_ATTACH"            },
        {    FT_PROOFREADING_MARKS_CLIPPING,            L"PROOFREADING_MARKS_CLIPPING"            },
        {    FT_PROOFREADING_MARKS_SAWTOOTH,            L"PROOFREADING_MARKS_SAWTOOTH"            },
        {    FT_PROOFREADING_MARKS_THINKING,            L"PROOFREADING_MARKS_THINKING"            },
        {    FT_PROOFREADING_MARKS_PRAISE,            L"PROOFREADING_MARKS_PRAISE"            },
        {    FT_PROOFREADING_MARKS_LINE,                L"PROOFREADING_MARKS_LINE"                },
        {    FT_PROOFREADING_MARKS_SIMPLECHANGE,        L"PROOFREADING_MARKS_SIMPLECHANGE"        },
        {    FT_PROOFREADING_MARKS_HYPERLINK,        L"PROOFREADING_MARKS_HYPERLINK"            },
        {    FT_PROOFREADING_MARKS_LINEATTACH,        L"PROOFREADING_MARKS_LINEATTACH"        },
        {    FT_PROOFREADING_MARKS_LINELINK,            L"PROOFREADING_MARKS_LINELINK"            },
        {    FT_PROOFREADING_MARKS_LINETRANSFER,        L"PROOFREADING_MARKS_LINETRANSFER"        },
        {    FT_PROOFREADING_MARKS_RIGHTMOVE,        L"PROOFREADING_MARKS_RIGHTMOVE"            },
        {    FT_PROOFREADING_MARKS_LEFTMOVE,            L"PROOFREADING_MARKS_LEFTMOVE"            },
        {    FT_PROOFREADING_MARKS_TRANSFER,            L"PROOFREADING_MARKS_TRANSFER"            },
        {    FT_PROOFREADING_MARKS_SPLIT,            L"PROOFREADING_MARKS_SPLIT"                },
        {    FT_PROOFREADING_MARKS_SIMPLEINSERT,        L"PROOFREADING_MARKS_SIMPLEINSERT"        },
        {    FT_PRIVATE_INFO,                         L"PRIVATE_INFO"                            },
        {    FT_TABLEOFCONTENTS,                     L"TABLEOFCONTENTS"                        },
        {    FT_CITATION,                            L"CITATION"                                },
        {    FT_BIBLIOGRAPHY,                        L"BIBLIOGRAPHY"                            },
        {    FT_METADATA,                            L"METADATA"                             },
        { 0, NULL }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PNST_BOTH = 0,
        PNST_EVEN,
        PNST_ODD
    } PAGENUMSTARTSONTYPE;

    static const ENUMLIST g_PageNumStartsOnList[] = {
        {    PNST_BOTH,                             L"BOTH"        },
        {    PNST_EVEN,                             L"EVEN"        },
        {    PNST_ODD,                             L"ODD"        },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PNPT_NONE = 0,
        PNPT_TOP_LEFT,
        PNPT_TOP_CENTER,
        PNPT_TOP_RIGHT,
        PNPT_BOTTOM_LEFT,
        PNPT_BOTTOM_CENTER,
        PNPT_BOTTOM_RIGHT,
        PNPT_OUTSIDE_TOP,
        PNPT_OUTSIDE_BOTTOM,
        PNPT_INSIDE_TOP,
        PNPT_INSIDE_BOTTOM
    } PAGENUMPOSTYPE;

    static const ENUMLIST g_PageNumPosList[] = {
        {    PNPT_NONE,                                 L"NONE"                },
        {    PNPT_TOP_LEFT,                             L"TOP_LEFT"            },
        {    PNPT_TOP_CENTER,                         L"TOP_CENTER"        },
        {    PNPT_TOP_RIGHT,                         L"TOP_RIGHT"        },
        {    PNPT_BOTTOM_LEFT,                         L"BOTTOM_LEFT"        },
        {    PNPT_BOTTOM_CENTER,                     L"BOTTOM_CENTER"    },
        {    PNPT_BOTTOM_RIGHT,                         L"BOTTOM_RIGHT"        },
        {    PNPT_OUTSIDE_TOP,                         L"OUTSIDE_TOP"        },
        {    PNPT_OUTSIDE_BOTTOM,                     L"OUTSIDE_BOTTOM"    },
        {    PNPT_INSIDE_TOP,                         L"INSIDE_TOP"        },
        {    PNPT_INSIDE_BOTTOM,                     L"INSIDE_BOTTOM"    },
        {    0,                                         NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TAFT_TTF = 1,
        TAFT_HTF,
    } TEXTARTFONTTYPE;

    static const ENUMLIST g_TextartFontList[] = {
        {    TAFT_TTF,                                 L"TTF"    },
        {    TAFT_HTF,                                 L"HTF"    },
        {    0,                                         NULL    }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TAST_PARALLELOGRAM = 0,
        TAST_INVERTED_PARALLELOGRAM,
        TAST_INVERTED_UPWARD_CASCADE,
        TAST_INVERTED_DOWNWARD_CASCADE,
        TAST_UPWARD_CASCADE,
        TAST_DOWNWARD_CASCADE,
        TAST_REDUCE_RIGHT,
        TAST_REDUCE_LEFT,
        TAST_ISOSCELES_TRAPEZOID,
        TAST_INVERTED_ISOSCELES_TRAPEZOID,
        TAST_TOP_RIBBON_RECTANGLE,
        TAST_BOTTOM_RIBBON_RECTANGLE,
        TAST_CHEVRON_DOWN,
        TAST_CHEVRON,
        TAST_BOW_TIE,
        TAST_HEXAGON,
        TAST_WAVE1,
        TAST_WAVE2,
        TAST_WAVE3,
        TAST_WAVE4,
        TAST_LEFT_TILT_CYLINDER,
        TAST_RIGHT_TILT_CYLINDER,
        TAST_BOTTOM_WIDE_CYLINDER,
        TAST_TOP_WIDE_CYLINDER,
        TAST_THIN_CURVE_UP1,
        TAST_THIN_CURVE_UP2,
        TAST_THIN_CURVE_DOWN1,
        TAST_THIN_CURVE_DOWN2,
        TAST_INVERSED_FINGERNAIL,
        TAST_FINGERNAIL,
        TAST_GINKO_LEAF1,
        TAST_GINKO_LEAF2,
        TAST_INFLATE_RIGHT,
        TAST_INFLATE_LEFT,
        TAST_INFLATE_UP_CONVEX,
        TAST_INFLATE_BOTTOM_CONVEX,
        TAST_DEFLATE_TOP,
        TAST_DEFLATE_BOTTOM,
        TAST_DEFLATE,
        TAST_INFLATE,
        TAST_INFLATE_TOP,
        TAST_INFLATE_BOTTOM,
        TAST_RECTANGLE,
        TAST_LEFT_CYLINDER,
        TAST_CYLINDER,
        TAST_RIGHT_CYLINDER,
        TAST_CIRCLE,
        TAST_CURVE_DOWN,
        TAST_ARCH_UP,
        TAST_ARCH_DOWN,
        TAST_SINGLE_LINE_CIRCLE1,
        TAST_SINGLE_LINE_CIRCLE2,
        TAST_TRIPLE_LINE_CIRCLE1,
        TAST_TRIPLE_LINE_CIRCLE2,
        TAST_DOUBLE_LINE_CIRCLE
    } TEXTARTSHAPETYPE;

    static const ENUMLIST g_TextartShapeList[] = {
        {    TAST_PARALLELOGRAM,                     L"PARALLELOGRAM"                },
        {    TAST_INVERTED_PARALLELOGRAM,             L"INVERTED_PARALLELOGRAM"        },
        {    TAST_INVERTED_UPWARD_CASCADE,             L"INVERTED_UPWARD_CASCADE"        },
        {    TAST_INVERTED_DOWNWARD_CASCADE,         L"INVERTED_DOWNWARD_CASCADE"    },
        {    TAST_UPWARD_CASCADE,                     L"UPWARD_CASCADE"                },
        {    TAST_DOWNWARD_CASCADE,                     L"DOWNWARD_CASCADE"                },
        {    TAST_REDUCE_RIGHT,                         L"REDUCE_RIGHT"                    },
        {    TAST_REDUCE_LEFT,                         L"REDUCE_LEFT"                    },
        {    TAST_ISOSCELES_TRAPEZOID,                 L"ISOSCELES_TRAPEZOID"            },
        {    TAST_INVERTED_ISOSCELES_TRAPEZOID,         L"INVERTED_ISOSCELES_TRAPEZOID"    },
        {    TAST_TOP_RIBBON_RECTANGLE,                 L"TOP_RIBBON_RECTANGLE"            },
        {    TAST_BOTTOM_RIBBON_RECTANGLE,             L"BOTTOM_RIBBON_RECTANGLE"        },
        {    TAST_CHEVRON_DOWN,                         L"CHEVRON_DOWN"                    },
        {    TAST_CHEVRON,                             L"CHEVRON"                        },
        {    TAST_BOW_TIE,                             L"BOW_TIE"                        },
        {    TAST_HEXAGON,                             L"HEXAGON"                        },
        {    TAST_WAVE1,                             L"WAVE1"                        },
        {    TAST_WAVE2,                             L"WAVE2"                        },
        {    TAST_WAVE3,                             L"WAVE3"                        },
        {    TAST_WAVE4,                             L"WAVE4"                        },
        {    TAST_LEFT_TILT_CYLINDER,                 L"LEFT_TILT_CYLINDER"            },
        {    TAST_RIGHT_TILT_CYLINDER,                 L"RIGHT_TILT_CYLINDER"            },
        {    TAST_BOTTOM_WIDE_CYLINDER,                 L"BOTTOM_WIDE_CYLINDER"            },
        {    TAST_TOP_WIDE_CYLINDER,                 L"TOP_WIDE_CYLINDER"            },
        {    TAST_THIN_CURVE_UP1,                     L"THIN_CURVE_UP1"                },
        {    TAST_THIN_CURVE_UP2,                     L"THIN_CURVE_UP2"                },
        {    TAST_THIN_CURVE_DOWN1,                     L"THIN_CURVE_DOWN1"                },
        {    TAST_THIN_CURVE_DOWN2,                     L"THIN_CURVE_DOWN2"                },
        {    TAST_INVERSED_FINGERNAIL,                 L"INVERSED_FINGERNAIL"            },
        {    TAST_FINGERNAIL,                         L"FINGERNAIL"                    },
        {    TAST_GINKO_LEAF1,                         L"GINKO_LEAF1"                    },
        {    TAST_GINKO_LEAF2,                         L"GINKO_LEAF2"                    },
        {    TAST_INFLATE_RIGHT,                     L"INFLATE_RIGHT"                },
        {    TAST_INFLATE_LEFT,                         L"INFLATE_LEFT"                    },
        {    TAST_INFLATE_UP_CONVEX,                 L"INFLATE_UP_CONVEX"            },
        {    TAST_INFLATE_BOTTOM_CONVEX,             L"INFLATE_BOTTOM_CONVEX"        },
        {    TAST_DEFLATE_TOP,                         L"DEFLATE_TOP"                    },
        {    TAST_DEFLATE_BOTTOM,                     L"DEFLATE_BOTTOM"                },
        {    TAST_DEFLATE,                             L"DEFLATE"                        },
        {    TAST_INFLATE,                             L"INFLATE"                        },
        {    TAST_INFLATE_TOP,                         L"INFLATE_TOP"                    },
        {    TAST_INFLATE_BOTTOM,                     L"INFLATE_BOTTOM"                },
        {    TAST_RECTANGLE,                         L"RECTANGLE"                    },
        {    TAST_LEFT_CYLINDER,                     L"LEFT_CYLINDER"                },
        {    TAST_CYLINDER,                             L"CYLINDER"                        },
        {    TAST_RIGHT_CYLINDER,                     L"RIGHT_CYLINDER"                },
        {    TAST_CIRCLE,                             L"CIRCLE"                        },
        {    TAST_CURVE_DOWN,                         L"CURVE_DOWN"                    },
        {    TAST_ARCH_UP,                             L"ARCH_UP"                        },
        {    TAST_ARCH_DOWN,                         L"ARCH_DOWN"                    },
        {    TAST_SINGLE_LINE_CIRCLE1,                 L"SINGLE_LINE_CIRCLE1"            },
        {    TAST_SINGLE_LINE_CIRCLE2,                 L"SINGLE_LINE_CIRCLE2"            },
        {    TAST_TRIPLE_LINE_CIRCLE1,                 L"TRIPLE_LINE_CIRCLE1"            },
        {    TAST_TRIPLE_LINE_CIRCLE2,                 L"TRIPLE_LINE_CIRCLE2"            },
        {    TAST_DOUBLE_LINE_CIRCLE,                 L"DOUBLE_LINE_CIRCLE"            },
        {    0,                                         NULL                            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TAAT_LEFT = 0,
        TAAT_RIGHT,
        TAAT_CENTER,
        TAAT_FULL,
        TAAT_TABLE
    } TEXTARTALIGNTYPE;

    static const ENUMLIST g_TextartAlignList[] = {
        {    TAAT_LEFT,                             L"LEFT"        },
        {    TAAT_RIGHT,                         L"RIGHT"    },
        {    TAAT_CENTER,                         L"CENTER"    },
        {    TAAT_FULL,                             L"FULL"        },
        {    TAAT_TABLE,                         L"TABLE"    },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SNST_BOTH = 0,
        SNST_EVEN,
        SNST_ODD
    } STARTNUMSTARTONTYPE;

    static const ENUMLIST g_StartNumStartOnList[] = {
        {    SNST_BOTH,                             L"BOTH"    },
        {    SNST_EVEN,                             L"EVEN"    },
        {    SNST_ODD,                             L"ODD"    },
        {    0,                                     NULL    }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        VVT_HIDE_FIRST = 0,
        VVT_SHOW_FIRST,
        VVT_SHOW_ALL
    } VISIBILITYVALUETYPE;

    static const ENUMLIST g_VisibilityValueList[] = {
        {    VVT_HIDE_FIRST,                         L"HIDE_FIRST"    },
        {    VVT_SHOW_FIRST,                         L"SHOW_FIRST"    },
        {    VVT_SHOW_ALL,                             L"SHOW_ALL"        },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PLT_WIDELY = 0,
        PLT_NARROWLY
    } PAGELANDSCAPETYPE;

    static const ENUMLIST g_PageLandscapeList[] = {
        {    PLT_WIDELY,                             L"WIDELY"    },
        {    PLT_NARROWLY,                             L"NARROWLY"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PGT_LEFT_ONLY = 0,
        PGT_LEFT_RIGHT,
        PGT_TOP_BOTTOM
    } PAGEGUTTERTYPE;

    static const ENUMLIST g_PageGutterList[] = {
        {    PGT_LEFT_ONLY,                             L"LEFT_ONLY"    },
        {    PGT_LEFT_RIGHT,                         L"LEFT_RIGHT"    },
        {    PGT_TOP_BOTTOM,                         L"TOP_BOTTOM"    },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PBFT_BOTH = 0,
        PBFT_EVEN,
        PBFT_ODD
    } PBFTYPE;

    static const ENUMLIST g_PBFTypeList[] = {
        {    PBFT_BOTH,                             L"BOTH"    },
        {    PBFT_EVEN,                             L"EVEN"    },
        {    PBFT_ODD,                             L"ODD"    },
        {    0,                                     NULL    }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PBTBT_CONTENT = 0,
        PBTBT_PAPER
    } PBFTEXTBORDERTYPE;

    static const ENUMLIST g_PBFTextBorderList[] = {
        {    PBTBT_CONTENT,                             L"CONTENT"    },
        {    PBTBT_PAPER,                             L"PAPER"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PBFAT_PAPER = 0,
        PBFAT_PAGE,
        PBFAT_BORDER
    } PBFFILLAREATYPE;

    static const ENUMLIST g_PBFFillAreaList[] = {
        {    PBFAT_PAPER,                             L"PAPER"    },
        {    PBFAT_PAGE,                             L"PAGE"        },
        {    PBFAT_BORDER,                             L"BORDER"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        FNNT_CONTINUOUS = 0,
        FNNT_ON_SECTION,
        FNNT_ON_PAGE
    } FNNUMBERINGTYPE;

    static const ENUMLIST g_FNNumberingTypeList[] = {
        {    FNNT_CONTINUOUS,                         L"CONTINUOUS"    },
        {    FNNT_ON_SECTION,                         L"ON_SECTION"    },
        {    FNNT_ON_PAGE,                             L"ON_PAGE"        },
        {    0,                                         NULL            }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ENNT_CONTINUOUS = 0,
        ENNT_ON_SECTION,
    } ENNUMBERINGTYPE;

    static const ENUMLIST g_ENNumberingTypeList[] = {
        {    ENNT_CONTINUOUS,                         L"CONTINUOUS"    },
        {    ENNT_ON_SECTION,                         L"ON_SECTION"    },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        FNPT_EACH_COLUMN = 0,
        FNPT_MERGED_COLUMN,
        FNPT_RIGHT_MOST_COLUMN
    } FNPLACEMENTTYPE;

    static const ENUMLIST g_FNPlacementList[] = {
        {    FNPT_EACH_COLUMN,                         L"EACH_COLUMN"            },
        {    FNPT_MERGED_COLUMN,                     L"MERGED_COLUMN"        },
        {    FNPT_RIGHT_MOST_COLUMN,                 L"RIGHT_MOST_COLUMN"    },
        {    0,                                         NULL                    }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ENPT_END_OF_DOCUMENT = 0,
        ENPT_END_OF_SECTION
    } ENPLACEMENTTYPE;

    static const ENUMLIST g_ENPlacementList[] = {
        {    ENPT_END_OF_DOCUMENT,                     L"END_OF_DOCUMENT"    },
        {    ENPT_END_OF_SECTION,                     L"END_OF_SECTION"    },
        {    0,                                         NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SST_OUTSIDE = 0,
        SST_INSIDE
    } SHADOWSTYLETYPE;

    static const ENUMLIST g_ShadowStyleList[] = {
        {    SST_OUTSIDE,                             L"OUTSIDE"    },
        {    SST_INSIDE,                             L"INSIDE"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        AST_TOP_LEFT = 0,
        AST_TOP,
        AST_TOP_RIGHT,
        AST_LEFT,
        AST_CENTER,
        AST_RIGHT,
        AST_BOTTOM_LEFT,
        AST_BOTTOM,
        AST_BOTTOM_RIGHT
    } ALIGNSTYLETYPE;

    static const ENUMLIST g_AlignStyleList[] = {
        {    AST_TOP_LEFT,                         L"TOP_LEFT"        },
        {    AST_TOP,                             L"TOP"            },
        {    AST_TOP_RIGHT,                         L"TOP_RIGHT"    },
        {    AST_LEFT,                             L"LEFT"            },
        {    AST_CENTER,                         L"CENTER"        },
        {    AST_RIGHT,                             L"RIGHT"        },
        {    AST_BOTTOM_LEFT,                     L"BOTTOM_LEFT"    },
        {    AST_BOTTOM,                         L"BOTTOM"        },
        {    AST_BOTTOM_RIGHT,                     L"BOTTOM_RIGHT"    },
        {    0,                                     NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ET_ALPHA = 500,
        ET_ALPHA_MOD,
        ET_ALPHA_OFF,
        ET_RED,
        ET_RED_MOD,
        ET_RED_OFF,
        ET_GREEN,
        ET_GREEN_MOD,
        ET_GREEN_OFF,
        ET_BLUE,
        ET_BLUE_MOD,
        ET_BLUE_OFF,
        ET_HUE,
        ET_HUE_MOD,
        ET_HUE_OFF,
        ET_SAT,
        ET_SAT_MOD,
        ET_SAT_OFF,
        ET_LUM,
        ET_LUM_MOD,
        ET_LUM_OFF,
        ET_SHADE,
        ET_TINT,
        ET_GRAY,
        ET_COMP,
        ET_GAMMA,
        ET_INV_GAMMA,
        ET_INV
    } EFFECTTYPE;

    static const ENUMLIST g_EffectList[] = {
        {    ET_ALPHA,                             L"ALPHA"        },
        {    ET_ALPHA_MOD,                         L"ALPHA_MOD"    },
        {    ET_ALPHA_OFF,                         L"ALPHA_OFF"    },
        {    ET_RED,                             L"RED"            },
        {    ET_RED_MOD,                         L"RED_MOD"        },
        {    ET_RED_OFF,                         L"RED_OFF"        },
        {    ET_GREEN,                             L"GREEN"        },
        {    ET_GREEN_MOD,                         L"GREEN_MOD"    },
        {    ET_GREEN_OFF,                         L"GREEN_OFF"    },
        {    ET_BLUE,                             L"BLUE"            },
        {    ET_BLUE_MOD,                         L"BLUE_MOD"        },
        {    ET_BLUE_OFF,                         L"BLUE_OFF"        },
        {    ET_HUE,                             L"HUE"            },
        {    ET_HUE_MOD,                         L"HUE_MOD"        },
        {    ET_HUE_OFF,                         L"HUE_OFF"        },
        {    ET_SAT,                             L"SAT"            },
        {    ET_SAT_MOD,                         L"SAT_MOD"        },
        {    ET_SAT_OFF,                         L"SAT_OFF"        },
        {    ET_LUM,                             L"LUM"            },
        {    ET_LUM_MOD,                         L"LUM_MOD"        },
        {    ET_LUM_OFF,                         L"LUM_OFF"        },
        {    ET_SHADE,                             L"SHADE"        },
        {    ET_TINT,                             L"TINT"            },
        {    ET_GRAY,                             L"GRAY"            },
        {    ET_COMP,                             L"COMP"            },
        {    ET_GAMMA,                             L"GAMMA"        },
        {    ET_INV_GAMMA,                         L"INV_GAMMA"    },
        {    ET_INV,                             L"INV"            },
        {    0,                                     NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        WRT_PAPER = 0,
        WRT_PAGE,
        WRT_COLUMN,
        WRT_PARA,
        WRT_ABSOLUTE
    } WIDTHRELTOTYPE;

    static const ENUMLIST g_WidthRelToList[] = {
        {    WRT_PAPER,                             L"PAPER"    },
        {    WRT_PAGE,                             L"PAGE"        },
        {    WRT_COLUMN,                         L"COLUMN"    },
        {    WRT_PARA,                             L"PARA"        },
        {    WRT_ABSOLUTE,                         L"ABSOLUTE"    },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        HGRT_PAPER = 0,
        HGRT_PAGE,
        HGRT_ABSOLUTE
    } HEIGHTRELTOTYPE;

    static const ENUMLIST g_HeightRelToList[] = {
        {    HGRT_PAPER,                             L"PAPER"    },
        {    HGRT_PAGE,                                 L"PAGE"        },
        {    HGRT_ABSOLUTE,                             L"ABSOLUTE"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        VRT_PAPER = 0,
        VRT_PAGE,
        VRT_PARA
    } VERTRELTOTYPE;

    static const ENUMLIST g_VertRelToList[] = {
        {    VRT_PAPER,                             L"PAPER"    },
        {    VRT_PAGE,                             L"PAGE"        },
        {    VRT_PARA,                             L"PARA"        },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        HRT_PAPER = 0,
        HRT_PAGE,
        HRT_COLUMN,
        HRT_PARA
    } HORZRELTOTYPE;

    static const ENUMLIST g_HorzRelToList[] = {
        {    HRT_PAPER,                             L"PAPER"    },
        {    HRT_PAGE,                             L"PAGE"        },
        {    HRT_COLUMN,                         L"COLUMN"    },
        {    HRT_PARA,                             L"PARA"        },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        VAT_TOP = 0,
        VAT_CENTER,
        VAT_BOTTOM,
        VAT_INSIDE,
        VAT_OUTSIDE
    } VERTALIGNTYPE;

    static const ENUMLIST g_VertAlignList[] = {
        {    VAT_TOP,                                 L"TOP"        },
        {    VAT_CENTER,                             L"CENTER"    },
        {    VAT_BOTTOM,                             L"BOTTOM"    },
        {    VAT_INSIDE,                             L"INSIDE"    },
        {    VAT_OUTSIDE,                             L"OUTSIDE"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        HAT_LEFT = 0,
        HAT_CENTER,
        HAT_RIGHT,
        HAT_INSIDE,
        HAT_OUTSIDE
    } HORZALIGNTYPE;

    static const ENUMLIST g_HorzAlignList[] = {
        {    HAT_LEFT,                                 L"LEFT"        },
        {    HAT_CENTER,                             L"CENTER"    },
        {    HAT_RIGHT,                                 L"RIGHT"    },
        {    HAT_INSIDE,                             L"INSIDE"    },
        {    HAT_OUTSIDE,                             L"OUTSIDE"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        CST_LEFT = 0,
        CST_RIGHT,
        CST_TOP,
        CST_BOTTOM
    } CAPTIONSIDETYPE;

    static const ENUMLIST g_CaptionSideList[] = {
        {    CST_LEFT,                                 L"LEFT"        },
        {    CST_RIGHT,                                 L"RIGHT"    },
        {    CST_TOP,                                 L"TOP"        },
        {    CST_BOTTOM,                             L"BOTTOM"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SEGT_LINE = 0,
        SEGT_CURVE
    } SEGTYPE;

    static const ENUMLIST g_SegTypeList[] = {
        {    SEGT_LINE,                                 L"LINE"        },
        {    SEGT_CURVE,                             L"CURVE"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        HST_HORIZONTAL = 0,
        HST_VERTICAL = 1,
        HST_BACK_SLASH = 3,
        HST_SLASH = 2,
        HST_CROSS = 4,
        HST_CROSS_DIAGONAL = 5
    } HATCHSTYLETYPE;

    static const ENUMLIST g_HatchStyleList[] = {
        {    HST_HORIZONTAL,                         L"HORIZONTAL"        },
        {    HST_VERTICAL,                             L"VERTICAL"            },
        {    HST_BACK_SLASH,                         L"BACK_SLASH"        },
        {    HST_SLASH,                                 L"SLASH"            },
        {    HST_CROSS,                                 L"CROSS"            },
        {    HST_CROSS_DIAGONAL,                     L"CROSS_DIAGONAL"    },
        {    0,                                         NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        GT_LINEAR = 1,
        GT_RADIAL,
        GT_CONICAL,
        GT_SQUARE
    } GRADATIONTYPE;

    static const ENUMLIST g_GradationTypeList[] = {
        {    GT_LINEAR,                             L"LINEAR"    },
        {    GT_RADIAL,                             L"RADIAL"    },
        {    GT_CONICAL,                         L"CONICAL"    },
        {    GT_SQUARE,                             L"SQUARE"    },
        {    0,                                     NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        IBMT_TILE = 0,
        IBMT_TILE_HORZ_TOP,
        IBMT_TILE_HORZ_BOTTOM,
        IBMT_TILE_VERT_LEFT,
        IBMT_TILE_VERT_RIGHT,
        IBMT_TOTAL,
        IBMT_CENTER,
        IBMT_CENTER_TOP,
        IBMT_CENTER_BOTTOM,
        IBMT_LEFT_CENTER,
        IBMT_LEFT_TOP,
        IBMT_LEFT_BOTTOM,
        IBMT_RIGHT_CENTER,
        IBMT_RIGHT_TOP,
        IBMT_RIGHT_BOTTOM,
        IBMT_ZOOM
    } IMGBRUSHMODETYPE;

    static const ENUMLIST g_ImgBrushModeList[] = {
        {    IBMT_TILE,                                 L"TILE"                },
        {    IBMT_TILE_HORZ_TOP,                     L"TILE_HORZ_TOP"    },
        {    IBMT_TILE_HORZ_BOTTOM,                     L"TILE_HORZ_BOTTOM"    },
        {    IBMT_TILE_VERT_LEFT,                     L"TILE_VERT_LEFT"    },
        {    IBMT_TILE_VERT_RIGHT,                     L"TILE_VERT_RIGHT"    },
        {    IBMT_TOTAL,                             L"TOTAL"            },
        {    IBMT_CENTER,                             L"CENTER"            },
        {    IBMT_CENTER_TOP,                         L"CENTER_TOP"        },
        {    IBMT_CENTER_BOTTOM,                     L"CENTER_BOTTOM"    },
        {    IBMT_LEFT_CENTER,                         L"LEFT_CENTER"        },
        {    IBMT_LEFT_TOP,                             L"LEFT_TOP"            },
        {    IBMT_LEFT_BOTTOM,                         L"LEFT_BOTTOM"        },
        {    IBMT_RIGHT_CENTER,                         L"RIGHT_CENTER"        },
        {    IBMT_RIGHT_TOP,                         L"RIGHT_TOP"        },
        {    IBMT_RIGHT_BOTTOM,                         L"RIGHT_BOTTOM"        },
        {    IBMT_ZOOM,                                 L"ZOOM"                },
        {    0,                                         NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TAT_WORDPROCESSOR = 1,
        TAT_PRESENTATION,
        TAT_SPREADSHEET
    } TAGETAPPLICATIONTYPE;

    static const ENUMLIST g_tagetApplicationList[] = {
        {    TAT_WORDPROCESSOR,                         L"WORDPROCESSOR"    },
        {    TAT_PRESENTATION,                         L"PRESENTATION"        },
        {    TAT_SPREADSHEET,                         L"SPREADSHEET"        },
        {    0,                                         NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PAIT_STRING = 0,
        PAIT_INTEGER,
        PAIT_UNSIGNEDINTEGER,
        PAIT_FLOAT,
        PAIT_DOUBLE,
        PAIT_SET,
        PAIT_ARRAY,
        PAIT_BINARY
    } PARAMETERITEMTYPE;

    static const ENUMLIST g_ParameterItemList[] = {
        {    PAIT_STRING,                             L"STRING"    },
        {    PAIT_INTEGER,                             L"INTEGER"    },
        {    PAIT_UNSIGNEDINTEGER,                     L"UNSIGNEDINTEGER"    },
        {    PAIT_FLOAT,                             L"FLOAT"    },
        {    PAIT_DOUBLE,                             L"DOUBLE"    },
        {    PAIT_SET,                                 L"SET"        },
        {    PAIT_ARRAY,                             L"ARRAY"    },
        {    PAIT_BINARY,                             L"BINARY"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        STDT_HORIZONTAL = 0,
        STDT_VERTICAL = 1,
        STDT_VERTICALALL = 2
    } SECTEXTDIRECTTYPE;

    static const ENUMLIST g_SecTextDirectList[] = {
        {    STDT_HORIZONTAL,                         L"HORIZONTAL"    },
        {    STDT_VERTICAL,                             L"VERTICAL"        },
        {    STDT_VERTICALALL,                         L"VERTICALALL"        },
        {    0,                                         NULL            }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        CDT_NEWSPAPER = 0,
        CDT_BALANCED_NEWSPAPER,
        CDT_PARALLEL,
    } COLDEFTYPE;

    static const ENUMLIST g_ColDefTypeList[] = {
        {    CDT_NEWSPAPER,                         L"NEWSPAPER"            },
        {    CDT_BALANCED_NEWSPAPER,             L"BALANCED_NEWSPAPER"    },
        {    CDT_PARALLEL,                         L"PARALLEL"                },
        {    0,                                     NULL                    }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        CDL_LEFT = 0,
        CDL_RIGHT,
        CDL_MIRROR
    } COLDEFLAYOUT;

    static const ENUMLIST g_ColDefLayoutList[] = {
        {    CDL_LEFT,                                 L"LEFT"        },
        {    CDL_RIGHT,                                 L"RIGHT"    },
        {    CDL_MIRROR,                             L"MIRROR"    },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        APT_BOTH = 0,
        APT_EVEN,
        APT_ODD
    } APPLYPAGETYPE;

    static const ENUMLIST g_ApplyPageTypeList[] = {
        {    APT_BOTH,                                 L"BOTH"    },
        {    APT_EVEN,                                 L"EVEN"    },
        {    APT_ODD,                                 L"ODD"    },
        {    0,                                         NULL    }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ANT_PAGE = 0,
        ANT_FOOTNOTE,
        ANT_ENDNOTE,
        ANT_PICTURE,
        ANT_TABLE,
        ANT_EQUATION,
        ANT_TOTAL_PAGE
    } AUTONUMTYPE;

    static const ENUMLIST g_AutoNumTypeList[] = {
        {    ANT_PAGE,                             L"PAGE"            },
        {    ANT_FOOTNOTE,                         L"FOOTNOTE"        },
        {    ANT_ENDNOTE,                         L"ENDNOTE"        },
        {    ANT_PICTURE,                         L"PICTURE"        },
        {    ANT_TABLE,                             L"TABLE"        },
        {    ANT_EQUATION,                         L"EQUATION"        },
        {    ANT_TOTAL_PAGE,                     L"TOTAL_PAGE"    },
        {    0,                                     NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PTDT_HORIZONTAL = 0,
        PTDT_VERTICAL,
        PTDT_VERTICALALL
    } PARATEXTDIRECTTYPE;

    static const ENUMLIST g_ParaTextDirectList[] = {
        {    PTDT_HORIZONTAL,                         L"HORIZONTAL"    },
        {    PTDT_VERTICAL,                             L"VERTICAL"        },
        {    PTDT_VERTICALALL,                         L"VERTICALALL"    },
        {    0,                                         NULL            }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PLWT_BREAK = 0,
        PLWT_SQUEEZE,
        PLWT_KEEP
    } PARALINEWRAPTYPE;

    static const ENUMLIST g_ParaLineWrapList[] = {
        {    PLWT_BREAK,                             L"BREAK"    },
        {    PLWT_SQUEEZE,                             L"SQUEEZE"    },
        {    PLWT_KEEP,                                 L"KEEP"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ELT_LINE = 0,
        ELT_CHAR
    } EQUATIONLINETYPE;

    static const ENUMLIST g_EquationLineList[] = {
        {    ELT_LINE,                             L"LINE"        },
        {    ELT_CHAR,                             L"CHAR"        },
        {    0,                                     L"NULL"        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PVAT_TOP = 0,
        PVAT_CENTER,
        PVAT_BOTTOM
    } PARAVERTALIGNTYPE;

    static const ENUMLIST g_ParaVertAlignList[] = {
        {    PVAT_TOP,                                 L"TOP"        },
        {    PVAT_CENTER,                             L"CENTER"    },
        {    PVAT_BOTTOM,                             L"BOTTOM"    },
        {    0,                                         NULL        }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LNT_DIGIT = 0,
        LNT_CIRCLED_DIGIT,
        LNT_ROMAN_CAPITAL,
        LNT_ROMAN_SMALL,
        LNT_LATIN_CAPITAL,
        LNT_LATIN_SMALL,
        LNT_CIRCLED_LATIN_CAPITAL,
        LNT_CIRCLED_LATIN_SMALL,
        LNT_HANGUL_SYLLABLE,
        LNT_CIRCLED_HANGUL_SYLLABLE,
        LNT_HANGUL_JAMO,
        LNT_CIRCLED_HANGUL_JAMO,
        LNT_HANGUL_PHONETIC,
        LNT_IDEOGRAPH,
        LNT_CIRCLED_IDEOGRAPH,
        LNT_DECAGON_CIRCLE,
        LNT_DECAGON_CIRCLE_HANJA,
        LNT_SYMBOL = 0x80,
        LNT_USER_CHAR,
        LNT_MS_SYMBOL,
        LNT_MS_IMAGE,
        LNT_MS_2_DIGIT

    } NUMBERTYPE;

    static const ENUMLIST g_NumberTypeList[] = {
        {    LNT_DIGIT,                             L"DIGIT"                    },
        {    LNT_CIRCLED_DIGIT,                     L"CIRCLED_DIGIT"            },
        {    LNT_ROMAN_CAPITAL,                     L"ROMAN_CAPITAL"            },
        {    LNT_ROMAN_SMALL,                     L"ROMAN_SMALL"                },
        {    LNT_LATIN_CAPITAL,                     L"LATIN_CAPITAL"            },
        {    LNT_LATIN_SMALL,                     L"LATIN_SMALL"                },
        {    LNT_CIRCLED_LATIN_CAPITAL,             L"CIRCLED_LATIN_CAPITAL"    },
        {    LNT_CIRCLED_LATIN_SMALL,             L"CIRCLED_LATIN_SMALL"        },
        {    LNT_HANGUL_SYLLABLE,                 L"HANGUL_SYLLABLE"            },
        {    LNT_CIRCLED_HANGUL_SYLLABLE,         L"CIRCLED_HANGUL_SYLLABLE"    },
        {    LNT_HANGUL_JAMO,                     L"HANGUL_JAMO"                },
        {    LNT_CIRCLED_HANGUL_JAMO,             L"CIRCLED_HANGUL_JAMO"        },
        {    LNT_HANGUL_PHONETIC,                 L"HANGUL_PHONETIC"            },
        {    LNT_IDEOGRAPH,                         L"IDEOGRAPH"                },
        {    LNT_CIRCLED_IDEOGRAPH,                 L"CIRCLED_IDEOGRAPH"        },
        {    LNT_DECAGON_CIRCLE,                 L"DECAGON_CIRCLE"            },
        {    LNT_DECAGON_CIRCLE_HANJA,             L"DECAGON_CIRCLE_HANJA"        },
        {    LNT_SYMBOL,                         L"SYMBOL"                    },
        {    LNT_USER_CHAR,                         L"USER_CHAR"                },
        {    LNT_MS_SYMBOL,                         L"SYMBOL2"                    },
        {    LNT_MS_IMAGE,                         L"IMAGE"                    },
        {    LNT_MS_2_DIGIT,                     L"2DIGIT"                    },
        {    0,                                     NULL                        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ECT_RGB = 0,
        ECT_CMYK,
        ECT_SCHEME,
        ECT_SYSTEM,
        ECT_PRESET,
        ECT_SCRGB,
        ECT_HSL
    } EFFECTCOLORTYPE;

    static const ENUMLIST g_EffectColorList[] = {
        {    ECT_RGB,                                 L"RGB"        },
        {    ECT_CMYK,                                 L"CMYK"        },
        {    ECT_SCHEME,                             L"SCHEME"    },
        {    ECT_SYSTEM,                             L"SYSTEM"    },
        {    ECT_PRESET,                             L"PRESET"    },
        {    ECT_SCRGB,                                 L"SCRGB"    },
        {    ECT_HSL,                                 L"HSL"    },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        LECT_ROUND = 0,
        LECT_FLAT
    } LINEENDCAPTYPE;

    static const ENUMLIST g_LineEndCapList[] = {
        {    LECT_ROUND,                             L"ROUND"    },
        {    LECT_FLAT,                                 L"FLAT"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        AT_NORMAL = 0,
        AT_ARROW,
        AT_SPEAR,
        AT_CONCAVE_ARROW,
        AT_EMPTY_DIAMOND,
        AT_EMPTY_CIRCLE,
        AT_EMPTY_BOX,
    } ARROWTYPE;

#define OWPML_ATFILL            0x1000

    static const ENUMLIST g_ArrowTypeList[] = {
        {    AT_NORMAL,                                 L"NORMAL"            },
        {    AT_ARROW,                                 L"ARROW"            },
        {    AT_SPEAR,                                 L"SPEAR"            },
        {    AT_CONCAVE_ARROW,                         L"CONCAVE_ARROW"    },
        {    AT_EMPTY_DIAMOND,                         L"EMPTY_DIAMOND"    },
        {    AT_EMPTY_CIRCLE,                         L"EMPTY_CIRCLE"        },
        {    AT_EMPTY_BOX,                             L"EMPTY_BOX"        },
        {    0,                                         NULL            }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        AST_SMALL_SMALL = 0,
        AST_SMALL_MEDIUM,
        AST_SMALL_LARGE,
        AST_MEDIUM_SMALL,
        AST_MEDIUM_MEDIUM,
        AST_MEDIUM_LARGE,
        AST_LARGE_SMALL,
        AST_LARGE_MEDIUM,
        AST_LARGE_LARGE
    } ARROWSIZE;

    static const ENUMLIST g_ArrowSizeList[] = {
        {    AST_SMALL_SMALL,                     L"SMALL_SMALL"        },
        {    AST_SMALL_MEDIUM,                     L"SMALL_MEDIUM"        },
        {    AST_SMALL_LARGE,                     L"SMALL_LARGE"        },
        {    AST_MEDIUM_SMALL,                     L"MEDIUM_SMALL"        },
        {    AST_MEDIUM_MEDIUM,                     L"MEDIUM_MEDIUM"    },
        {    AST_MEDIUM_LARGE,                     L"MEDIUM_LARGE"        },
        {    AST_LARGE_SMALL,                     L"LARGE_SMALL"        },
        {    AST_LARGE_MEDIUM,                     L"LARGE_MEDIUM"        },
        {    AST_LARGE_LARGE,                     L"LARGE_LARGE"        },
        {    0,                                     NULL                }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        OLST_NORMAL = 0,
        OLST_OUTER,
        OLST_INNER
    } OUTLINESTYLE;

    static const ENUMLIST g_OutLineStyleList[] = {
        {    OLST_NORMAL,                             L"NORMAL"    },
        {    OLST_OUTER,                             L"OUTER"    },
        {    OLST_INNER,                             L"INNER"    },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        MPT_BOTH = 0,
        MPT_EVEN,
        MPT_ODD,
        MPT_LAST_PAGE,
        MPT_OPTIONAL_PAGE
    } MASTERPAGETYPE;

    static const ENUMLIST g_MasterPageTypeList[] = {
        {    MPT_BOTH,                             L"BOTH"                },
        {    MPT_EVEN,                             L"EVEN"                },
        {    MPT_ODD,                             L"ODD"                },
        {    MPT_LAST_PAGE,                         L"LAST_PAGE"        },
        {    MPT_OPTIONAL_PAGE,                     L"OPTIONAL_PAGE"    },
        {    0,                                     NULL                }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ASONT_NONE = 0,
        ASONT_PICTURE,
        ASONT_TABLE,
        ASONT_EQUATION
    } ASONUMBERINGTYPE;

    static const ENUMLIST g_ASONumberingTypeList[] = {
        {    ASONT_NONE,                             L"NONE"        },
        {    ASONT_PICTURE,                             L"PICTURE"    },
        {    ASONT_TABLE,                             L"TABLE"    },
        {    ASONT_EQUATION,                         L"EQUATION"    },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ASOTWT_SQUARE = 0,
        ASOTWT_TOP_AND_BOTTOM,
        ASOTWT_BEHIND_TEXT,
        ASOTWT_IN_FRONT_OF_TEXT
    } ASOTEXTWRAPTYPE;

    static const ENUMLIST g_ASOTextWrapList[] = {
        {    ASOTWT_SQUARE,                             L"SQUARE"            },
        {    ASOTWT_TOP_AND_BOTTOM,                     L"TOP_AND_BOTTOM"    },
        {    ASOTWT_BEHIND_TEXT,                     L"BEHIND_TEXT"        },
        {    ASOTWT_IN_FRONT_OF_TEXT,                 L"IN_FRONT_OF_TEXT"    },
        {    0,                                         NULL                }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ASOTFT_BOTH_SIDES = 0,
        ASOTFT_LEFT_ONLY,
        ASOTFT_RIGHT_ONLY,
        ASOTFT_LARGEST_ONLY
    } ASOTEXTFLOWTYPE;

    static const ENUMLIST g_ASOTextFlowList[] = {
        {    ASOTFT_BOTH_SIDES,                         L"BOTH_SIDES"        },
        {    ASOTFT_LEFT_ONLY,                         L"LEFT_ONLY"        },
        {    ASOTFT_RIGHT_ONLY,                         L"RIGHT_ONLY"        },
        {    ASOTFT_LARGEST_ONLY,                     L"LARGEST_ONLY"        },
        {    0,                                         NULL                }
    };


    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SAT_NORMAL = 0,
        SAT_PIE,
        SAT_CHORD,
    } ARCTYPE;

    static const ENUMLIST g_ArcTypeList[] = {
        {    SAT_NORMAL,                             L"NORMAL"        },
        {    SAT_PIE,                                 L"PIE"        },
        {    SAT_CHORD,                                 L"CHORD"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        CLT_STRAIGHT_NOARROW = 0,
        CLT_STRAIGHT_ONEWAY,
        CLT_STRAIGHT_BOTH,
        CLT_STROKE_NOARROW,
        CLT_STROKE_ONEWAY,
        CLT_STROKE_BOTH,
        CLT_ARC_NOARROW,
        CLT_ARC_ONEWAY,
        CLT_ARC_BOTH
    } CONNECTLINETYPE;

    static const ENUMLIST g_ConnectLineList[] = {
        {    CLT_STRAIGHT_NOARROW,                 L"STRAIGHT_NOARROW"    },
        {    CLT_STRAIGHT_ONEWAY,                 L"STRAIGHT_ONEWAY"    },
        {    CLT_STRAIGHT_BOTH,                     L"STRAIGHT_BOTH"    },
        {    CLT_STROKE_NOARROW,                 L"STROKE_NOARROW"    },
        {    CLT_STROKE_ONEWAY,                     L"STROKE_ONEWAY"    },
        {    CLT_STROKE_BOTH,                     L"STROKE_BOTH"        },
        {    CLT_ARC_NOARROW,                     L"ARC_NOARROW"        },
        {    CLT_ARC_ONEWAY,                     L"ARC_ONEWAY"        },
        {    CLT_ARC_BOTH,                         L"ARC_BOTH"            },
        {    0,                                     NULL                }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TPBT_NONE = 0,
        TPBT_TABLE,
        TPBT_CELL
    } TABLEPAGEBREAKTYPE;

    static const ENUMLIST g_TablePageBreakList[] = {
        {    TPBT_NONE,                             L"NONE"        },
        {    TPBT_TABLE,                         L"TABLE"    },
        {    TPBT_CELL,                             L"CELL"        },
        {    0,                                     NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        OLET_UNKNOWN = 0,
        OLET_EMBEDDED,
        OLET_LINK,
        OLET_STATIC,
        OLET_EQUATION
    } OLEOBJECTTYPE;

    static const ENUMLIST g_OleObjectList[] = {
        {    OLET_UNKNOWN,                             L"UNKNOWN"        },
        {    OLET_EMBEDDED,                         L"EMBEDDED"        },
        {    OLET_LINK,                             L"LINK"        },
        {    OLET_STATIC,                             L"STATIC"        },
        {    OLET_EQUATION,                         L"EQUATION"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        OLEDA_NONE = 0,
        OLEDA_CONTENT = 1,
        OLEDA_THUMB_NAIL = 2,
        OLEDA_ICON = 4,
        OLEDA_DOC_PRINT = 8
    } OLEDRAWASPECTTYPE;

    static const ENUMLIST g_OleDrawAspectList[] = {
        {    OLEDA_CONTENT,                             L"CONTENT"        },
        {    OLEDA_THUMB_NAIL,                         L"THUMB_NAIL"        },
        {    OLEDA_ICON,                             L"ICON"        },
        {    OLEDA_DOC_PRINT,                         L"DOC_PRINT"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        VBT_UNCHECKED = 0,
        VBT_CHECKED,
        VBT_INDETERMINATE
    } BUTTONVALUETYPE;

    static const ENUMLIST g_ButtonValueList[] = {
        {    VBT_UNCHECKED,                         L"UNCHECKED"        },
        {    VBT_CHECKED,                         L"CHECKED"        },
        {    VBT_INDETERMINATE,                     L"INDETERMINATE"        },
        {    0,                                     NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        BBST_TRANSPARENT = 0,
        BBST_OPAQUE
    } BUTTONBACKSTYLETYPE;

    static const ENUMLIST g_ButtonbackStyleList[] = {
        {    BBST_TRANSPARENT,                         L"TRANSPARENT"        },
        {    BBST_OPAQUE,                             L"OPAQUE"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        SBT_HORIZONTAL = 0,
        SBT_VERTICAL
    } SCROLLBARTYPE;

    static const ENUMLIST g_ScrollBarList[] = {
        {    SBT_HORIZONTAL,                     L"HORIZONTAL"        },
        {    SBT_VERTICAL,                         L"VERTICAL"        },
        {    0,                                     NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ESBT_NONE = 0,
        ESBT_VERTICAL,
        ESBT_HORIZONTAL,
        ESBT_BOTH
    } EDSCROLLBARSTYPE;

    static const ENUMLIST g_EdScrollBarsList[] = {
        {    ESBT_NONE,                             L"NONE"        },
        {    ESBT_VERTICAL,                         L"VERTICAL"        },
        {    ESBT_HORIZONTAL,                     L"HORIZONTAL"        },
        {    ESBT_BOTH,                             L"BOTH"        },
        {    0,                                     NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        ETT_NEXT_OBJECT = 0,
        ETT_INSERT_TAB
    } EDTABKEYBHTYPE;

    static const ENUMLIST g_EdTabKeyBhList[] = {
        {    ETT_NEXT_OBJECT,                         L"NEXT_OBJECT"        },
        {    ETT_INSERT_TAB,                         L"INSERT_TAB"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        EAT_LEFT = 0,
        EAT_CENTER,
        EAT_RIGHT
    } EDITALIGNTYPE;

    static const ENUMLIST g_EditAlignList[] = {
        {    EAT_LEFT,                             L"LEFT"        },
        {    EAT_CENTER,                             L"CENTER"        },
        {    EAT_RIGHT,                             L"RIGHT"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        IRT_yes = 0,
        IRT_no
    } ITEMREFTYPE;

    static const ENUMLIST g_ItemRefList[] = {
        {    IRT_yes,                                 L"yes"        },
        {    IRT_no,                                 L"no"        },
        {    0,                                         NULL        }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        TCT_UNKNOWN = 0,
        TCT_INSERT,
        TCT_DELETE,
        TCT_CHARSHAPE,
        TCT_PARASHAPE,
    } TRACKCHANGETYPE;

    static const ENUMLIST g_TrackChangeTypeList[] = {
        { TCT_UNKNOWN,                L"UnKown" },
        { TCT_INSERT,                L"Insert" },
        { TCT_DELETE,                L"Delete" },
        { TCT_CHARSHAPE,            L"CharShape" },
        { TCT_PARASHAPE,            L"ParaShape" },
        { 0,                        NULL }
    };



    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        PRAT_WHOLE_DOCUMENT = 0,
        PRAT_NEWSECTION,
    } PRESENTATIONAPPLYTO;

    static const ENUMLIST g_PresentationApplyToList[] = {
        { PRAT_WHOLE_DOCUMENT, L"WholeDoc" },
        { PRAT_NEWSECTION, L"NewSection" },
        { 0,                        NULL }
    };

    ///////////////////////////////////////////////////////////////////

    typedef enum
    {
        PRE_NONE = 0,
        PRE_OVER_LEFT,
        PRE_OVER_RIGHT,
        PRE_OVER_UP,
        PRE_OVER_DOWN,

        PRE_RECT_OUT,
        PRE_RECT_IN,

        PRE_BLIND_LEFT,
        PRE_BLIND_RIGHT,
        PRE_BLIND_UP,
        PRE_BLIND_DOWN,

        PRE_CUTTON_HORZ_OUT,
        PRE_CUTTON_HORZ_IN,
        PRE_CUTTON_VERT_OUT,
        PRE_CUTTON_VERT_IN,

        PRE_MOVE_LEFT,
        PRE_MOVE_RIGHT,
        PRE_MOVE_UP,
        PRE_MOVE_DOWN,
        PRE_RANDOM,
    } PRESENTATIONEFFECTS;

    static const ENUMLIST g_PresentationEffectsList[] = {
        { PRE_NONE,             L"none" },
        { PRE_OVER_LEFT,        L"overLeft" },
        { PRE_OVER_RIGHT,       L"overRight" },
        { PRE_OVER_UP,          L"overUp" },
        { PRE_OVER_DOWN,        L"overDown" },

        { PRE_RECT_OUT,         L"rectOut" },
        { PRE_RECT_IN,          L"rectIn" },

        { PRE_BLIND_LEFT,       L"blindLeft" },
        { PRE_BLIND_RIGHT,      L"blindRight" },
        { PRE_BLIND_UP,         L"blindUp" },
        { PRE_BLIND_DOWN,       L"blindDown" },

        { PRE_CUTTON_HORZ_OUT,  L"cuttonHorzOut" },
        { PRE_CUTTON_HORZ_IN,   L"cuttonHorzIn" },
        { PRE_CUTTON_VERT_OUT,  L"cuttonVertOut" },
        { PRE_CUTTON_VERT_IN,   L"cuttonVertIn" },

        { PRE_MOVE_LEFT,        L"moveLeft" },
        { PRE_MOVE_RIGHT,       L"moveRight" },
        { PRE_MOVE_UP,          L"moveUp" },
        { PRE_MOVE_DOWN,        L"moveDown" },
        { PRE_RANDOM,           L"random" },
        { 0, NULL }
    };

    ///////////////////////////////////////////////////////////////////
    // Dropcap Style

    typedef enum
    {
        DCS_NONE = 0,
        DCS_DOUBLELINE,
        DCS_TRIPLELINE,
        DCS_MARGIN,
    } DROPCAPSTYLE;

    static const ENUMLIST g_DropcapStyleList[] = {
        { DCS_NONE, L"None" },
        { DCS_DOUBLELINE, L"DoubleLine" },
        { DCS_TRIPLELINE, L"TripleLine" },
        { DCS_MARGIN, L"Margin" },
        { 0, NULL }
    };

    ////////////////////////////////////////////////////////////////////////////
    // ������ Ÿ��
    typedef enum
    {
        VT_LOCAL = 0,
        VT_WEB,
    } VIDEOTYPE;

    static const ENUMLIST g_VideoTypeList[] = {
        { VT_LOCAL, L"Local" },
        { VT_WEB, L"Web" },
        { VT_LOCAL, L"0" },
        { VT_WEB, L"1" },
        { 0, NULL }
    };

    ///////////////////////////////////////////////////////////////////
    typedef enum
    {
        OPLT_CCL = 0, // ccl
        OPLT_KOGL     // 공공누리
    } LICENSTYPE;

    static const ENUMLIST g_LicensTypeList[] = {
        { OPLT_CCL, L"CCL" },
        { OPLT_KOGL, L"KOGL" },
        { 0, NULL }
    };

}

#endif //
///////////////////////////////////////////////////////////////////
