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

 // stdafx.h : 자주 사용하지만 자주 변경되지는 않는
 // 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
 // 들어 있는 포함 파일입니다.
 //

#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.

#include "OWPMLUtil/HncDefine.h"
#include "OWPMLUtil/HncSha1.h"
#include "OWPMLUtil/HncAES.h"
#include <functional>

#include <cstdlib>
// STL
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stdio.h>
#include <queue>
#include <stack>
#include <algorithm>
#include <complex>
#include <memory>

#ifdef _MSC_VER
#pragma once
#include <process.h>
#endif

#define IS_SURROGATE(ch)        (((WCHAR)ch >= 0xD800) && ((WCHAR)ch <= 0xDFFF))
#define IS_SURROGATEHIGH(ch)    (((WCHAR)ch >= 0xD800) && ((WCHAR)ch <= 0xDBFF))
#define IS_SURROGATELOW(ch)     (((WCHAR)ch >= 0xDC00) && ((WCHAR)ch <= 0xDFFF))

#define MAKE_SURCHAR(h, l)      ((((DWORD)(h)) << 16) | (l))
#define SURCHAR_H(surch)        ((WCHAR)(surch >> 16))
#define SURCHAR_L(surch)        ((WCHAR)(surch & 0xffff))

//#include "Engine/Model/HncBase/include/HncBase.h"
#if defined(OS_WIN) && defined(_DEBUG)
#define _REPORT_DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new _REPORT_DEBUG_NEW
#endif // defined(OS_WIN) && defined(_DEBUG)

#include "Base/Object.h"
#include "Class/classinclude.h"

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

#include <fstream>


