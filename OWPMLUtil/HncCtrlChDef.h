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
#ifndef HNCCTRL_CH_DEF_H
#define HNCCTRL_CH_DEF_H
 ////////////////////////////////////////////////////////////////////////////
 // Control character related defintions

 // [ch]    = 하나의 문차로 취급되는 char 컨트롤 / size = 1
 // [in] = 별도의 오브젝트 포인터를 가리키지 않는 단순한 inline 컨트롤 / size = 8
 // [ex]    = 별도의 오브젝트가 데이터를 표현하는 extended 컨트롤 / size = 8
enum {
    HWPCH_NULL,                    // 0  [ch] unusable
    HWPCH_RESERVED_1,            // 1  [ex] reserved
    HWPCH_PROPERTY,                // 2  [ex] SecDef / ColDef
    HWPCH_FIELD_BEGIN,            // 3  [ex] field begin
    HWPCH_FIELD_END,            // 4  [in] field end
    HWPCH_RESERVED_5,            // 5  [in] reserved
    HWPCH_RESERVED_6,            // 6  [in] reserved
    HWPCH_RESERVED_7,            // 7  [in] reserved
    HWPCH_TITLEMARK,            // 8  [in] title mark        // Title Mark (by tootoo : 2003.6.18 : HWP6.0)
    HWPCH_TAB,                    // 9  [in] tab
    HWPCH_LINE_BREAK,            // 10 [ch] line break
    HWPCH_SHAPE_OBJECT,            // 11 [ex] drawing object / table
    HWPCH_RESERVED_12,            // 12 [ex] reserved
    HWPCH_PARA_BREAK,            // 13 [ch] para break
    HWPCH_RESERVED_14,            // 14 [ex] reserved
    HWPCH_COMMENT,                // 15 [ex] comment
    HWPCH_HEADER,                // 16 [ex] header / footer
    HWPCH_FOOTNOTE,                // 17 [ex] footnote / endnote
    HWPCH_AUTO_NUM,                // 18 [ex] auto-numbering (footnote, table, .. etc)
    HWPCH_RESERVED_19,            // 19 [in] reserved
    HWPCH_RESERVED_20,            // 20 [in] reserved
    HWPCH_PAGE_PROC,            // 21 [ex] pagination control (hide, new number, .. etc)
    HWPCH_MARK_CODE,            // 22 [ex] single bookmark / index mark
    HWPCH_TEXT_CODE,            // 23 [ex] dutmal / compose
    HWPCH_HYPHEN,                // 24 [ch] hyphenation point
    HWPCH_RESERVED_25,            // 25 [ch] reserved
    HWPCH_RESERVED_26,            // 26 [ch] reserved
    HWPCH_RESERVED_27,            // 27 [ch] reserved
    HWPCH_RESERVED_28,            // 28 [ch] reserved
    HNCCH_EDITTAB,                // 29 [ch] reserved        HNCCH_EDITTAB -- EditControl에서 HWPCH_TAB대신 tab으로 쓰기 위한 코드.
    HWPCH_NON_BREAKING_SPACE,    // 30 [ch] non-breaking-space
    HWPCH_FIXED_WIDTH_SPACE,    // 31 [ch] fixed-width-space
};

#define    HWPCH_RESERVED_29        HNCCH_EDITTAB


#define MAKE_HWPCH_MASK(ch)            static_cast<UINT32>(1 << (ch))
#define HWPCH_IN_MASK(ch, mask)        static_cast<UINT32>((ch) < 32 && ((mask) & MAKE_HWPCH_MASK(ch)))

// char 타입 컨트롤 마스크
#define HWPCH_MASK_CHAR \
        ( MAKE_HWPCH_MASK(HWPCH_NULL) | MAKE_HWPCH_MASK(HWPCH_LINE_BREAK) \
        | MAKE_HWPCH_MASK(HWPCH_PARA_BREAK) | MAKE_HWPCH_MASK(HWPCH_HYPHEN) \
        | MAKE_HWPCH_MASK(HWPCH_NON_BREAKING_SPACE) | MAKE_HWPCH_MASK(HWPCH_FIXED_WIDTH_SPACE) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_25) | MAKE_HWPCH_MASK(HWPCH_RESERVED_26) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_27) | MAKE_HWPCH_MASK(HWPCH_RESERVED_28) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_29))

// inline 타입 컨트롤 마스크
#define HWPCH_MASK_INLINE \
        ( MAKE_HWPCH_MASK(HWPCH_FIELD_END) | MAKE_HWPCH_MASK(HWPCH_TAB) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_5) | MAKE_HWPCH_MASK(HWPCH_RESERVED_6) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_7) | MAKE_HWPCH_MASK(HWPCH_TITLEMARK) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_19) | MAKE_HWPCH_MASK(HWPCH_RESERVED_20))

// extended 타입 컨트롤 마스크
#define HWPCH_MASK_CTRL \
        ( MAKE_HWPCH_MASK(HWPCH_PROPERTY) | MAKE_HWPCH_MASK(HWPCH_FIELD_BEGIN) \
        | MAKE_HWPCH_MASK(HWPCH_SHAPE_OBJECT) | MAKE_HWPCH_MASK(HWPCH_COMMENT) \
        | MAKE_HWPCH_MASK(HWPCH_HEADER) | MAKE_HWPCH_MASK(HWPCH_FOOTNOTE) \
        | MAKE_HWPCH_MASK(HWPCH_AUTO_NUM) | MAKE_HWPCH_MASK(HWPCH_PAGE_PROC) \
        | MAKE_HWPCH_MASK(HWPCH_MARK_CODE) | MAKE_HWPCH_MASK(HWPCH_TEXT_CODE) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_1) | MAKE_HWPCH_MASK(HWPCH_RESERVED_12) \
        | MAKE_HWPCH_MASK(HWPCH_RESERVED_14))

#define HNCCH_SIZEOF_CTRLCH            8
#define HWPCH_SIZEOF_CTRLCH            HNCCH_SIZEOF_CTRLCH

#define HNCCH_CHAR_INC(ch)            (HWPCH_IN_MASK(ch, HWPCH_MASK_INLINE | HWPCH_MASK_CTRL) ? HWPCH_SIZEOF_CTRLCH : 1)
#define HWPCH_CHAR_INC                HNCCH_CHAR_INC

// 컨트롤은 아니나 특별한 의미로 사용되는 문자들
#define HNCCH_SPACE                    32            // 공백
#define HWPCH_SPACE                    HNCCH_SPACE

#endif //HNCCTRL_CH_DEF_H