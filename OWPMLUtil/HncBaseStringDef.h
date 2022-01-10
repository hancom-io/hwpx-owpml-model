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

#ifndef __HNCBASESTRINGDEF_H_
#define __HNCBASESTRINGDEF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <ctype.h>

/////////////////////////////////////////////////////////////////////////////////
// Unicode 루틴. 모든 명칭이 '_u'로 시작한다.

#define        _ustrcmp        wcscmp
#define        _ustrncmp       wcsncmp
#define        _ustrstr        wcsstr
#define        _ustrchr        wcschr
#define        _ustrrchr       wcsrchr
#define        _ustrlen        wcslen
#define        _uvsnprintf     _vsnwprintf
#define        _uisdigit       iswdigit
#define        _uisspace       iswspace
#define        _uisxdigit      iswxdigit
#define        _ustrncnt       _wcsncnt
#define        _utolower       towlower
#define        _uatoi          _wtoi
#define        _ustrtol        wcstol
#define        _ustrtoul       wcstoul
#define        _uaccess_s      _waccess_s
#define        _uitoa_s        _itow_s
#define        _umakepath_s    _wmakepath_s
#define        _umemcpy_s      wmemcpy_s
#define        _usplitpath_s   _wsplitpath_s
#define        _usprintf_s     swprintf_s
#define        _usscanf_s      swscanf_s
#define        _ustrcpy_s      wcscpy_s
#define        _ustrncpy_s     wcsncpy_s
#define        _ustrtok_s      wcstok_s
#define        _uvsnprintf_s   _vsnwprintf_s
#define        _urename        _wrename
// _ustricmp 와 _ustrnicmp 가 다국어를 고려해서 수정된 이후에 기존 CRT보다 느려지는 문제가 발생한다.
// 하여, CRT 를 직접 사용하도록 변경한다.

#define    _ustricmp           _wcsicmp
#define    _ustrnicmp          _wcsnicmp


#endif //__HNCBASESTRINGDEF_H_
