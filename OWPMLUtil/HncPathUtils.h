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
#ifndef HNCPATHUTIL_H
#define HNCPATHUTIL_H

#include "HncDefine.h"

typedef struct tagDirItem
{
    WCHAR szKey[32];
    WCHAR szPath[_MAX_PATH];
} DIRITEM, *LPDIRITEM;

void HncRemoveBackSlash(LPWSTR path);
BOOL HncRegisterPath(LPCWSTR szDirKey, LPCWSTR szPath);
void HncUnregisterPath(LPCWSTR szDirKey);
UINT HncPathMakeTemp(LPCWSTR prefix, UINT num, LPWSTR path, size_t pathlen);
UINT HncPathMakeTempEx(LPCWSTR subdir, LPCWSTR prefix, UINT num, LPCWSTR ext, LPWSTR path, size_t pathlen, UINT random = 0);
void HncPathToAbsolute(LPCWSTR relpath, LPWSTR abspath, size_t abspathlen);
BOOL HncPathCreate(LPCWSTR relpath);
UINT HncGetTempFileName(LPCWSTR lpPathName, LPCWSTR lpPrefixString, UINT uUnique, LPWSTR lpTempFileName, size_t nTempFileNameLen);
void HncAppendBackSlash(LPWSTR path);
BOOL _IsUNCPath(LPCWSTR path);
BOOL HncExistDir(LPCWSTR dirname);
DWORD HncGetFileAttributes(LPCWSTR lpFileName);
BOOL HncCreateDirectory(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
BOOL HncDeleteFile_s(LPCWSTR lpFileName);

#endif //HNCPATHUTIL_H