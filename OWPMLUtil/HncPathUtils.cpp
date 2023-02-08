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
#include <Shlwapi.h>
#include <vector>
#include <map>
#include "HncDefine.h"
#include "HncPathUtils.h"

// ===================================================================
// Inner class
class RegisterPath {
private:
    class PathItem
    {
    public:
        PathItem(std::wstring path) {
            this->path = path;
            refCount = 0;
        }

        std::wstring path;
        int refCount;
    };
    typedef std::map<std::wstring, PathItem> PathMap;

public:
    RegisterPath() {};
    ~RegisterPath() {};

    bool regist(LPCWSTR szDirKey, LPCWSTR szPath);
    void unregist(LPCWSTR szDirKey);
    PathMap& getMap() { return pathMap; }

private:


    PathMap pathMap;
};

bool RegisterPath::regist(LPCWSTR szDirKey, LPCWSTR szPath)
{
    if (szDirKey == NULL || szPath == NULL) {
        return false;
    }

    PathMap::iterator itrMap;

    itrMap = pathMap.find(szDirKey);
    if (itrMap == pathMap.end()) {
        pathMap.insert({ szDirKey, PathItem(szPath) });

        itrMap = pathMap.find(szDirKey);
    }
#ifdef DEBUG
    else {
        if ((*itrMap).second.path.compare(szPath) != 0) {
            _ASSERT(!"서로 다른 경로를 가리키고 있음");
        }
    }
#endif // DEBUG
    
    // Inc refcount
    (*itrMap).second.refCount++;
    return true;
}

void RegisterPath::unregist(LPCWSTR szDirKey)
{
    if (szDirKey == NULL) {
        return;
    }

    PathMap::iterator itrMap;

    itrMap = pathMap.find(szDirKey);
    if (itrMap != pathMap.end()) {
        // Dec refcount
        (*itrMap).second.refCount--;

        if ((*itrMap).second.refCount == 0) {
            pathMap.erase(szDirKey);
        } // if
    } // if
}

// ===================================================================

RegisterPath& getRegisterPath()
{
    static RegisterPath registerPath;
    return registerPath;
}

BOOL HncRegisterPath(LPCWSTR szDirKey, LPCWSTR szPath)
{
    return getRegisterPath().regist(szDirKey, szPath);
}

void HncUnregisterPath(LPCWSTR szDirKey)
{
    getRegisterPath().unregist(szDirKey);
}

/**
 * @brief 문자열에 백슬래쉬(\) or 슬래쉬(/)를 제거한다.
 * @ingroup HncPath
 *
 * @param path  백슬래쉬(\) or 슬래쉬(/)를 제거할 문자열
 * @return 없음
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see
 */
void  HncRemoveBackSlash(LPWSTR path)
{
    size_t len = _ustrlen(path);

    if (len && (_ustrrchr(path, L'\\') == (path + len - 1) || _ustrrchr(path, L'/') == (path + len - 1))) {
        if (len == 1 || path[len - 2] == L':')
            return;
        path[len - 1] = L'\0';
    }
}

///**
// * @brief 임시 파일의 경로를 만든다.
// * @ingroup HncPath
// *
// * @param prefix 임시 파일의 파일명을 지정. 이때 3문자까지만 지정이 가능하며, 이상을 썼을 때는 앞에 3문자까지만 남는다.
// * @param num 0이면 임시 파일을 생성하고, 그 이상의 값을 전달하면 파일 이름만 구하고 실제로 파일을 생성하진 않는다.
// * @param path 임시 파일의 이름을 저장할 포인터.
// * @return 성공여부 성공시 유일한 파일명, 실패시 0을 리턴.
// * @par 예제:
// * @code
//
// * @endcode
// * @Remarks
//<pre>
//</pre>
// * @see
// */
UINT  HncPathMakeTemp(LPCWSTR prefix, UINT num, LPWSTR path, size_t pathlen)
{
    WCHAR tmpdir[_MAX_PATH];
    UINT  ret;

    HncPathToAbsolute(L"${Temp}", tmpdir, _MAX_PATH);
    PathAddBackslash(tmpdir);

    if (num == 0 && !HncPathCreate(tmpdir))
        return 0;

    ret = HncGetTempFileName(tmpdir, prefix, num, path, pathlen);

    return ret;
}


/**
 * @brief 상대경로를 절대경로로 변환한다.
 * @ingroup HncPath
 *
 * @param relpath 절대경로로 변환할 상대경로를 가리키는 포인터.
 * @param abspath 변환된 절대경로를 저장하는 버퍼는 가리키는 포인터.
 * @return 없음
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see
 */

void HncPathToAbsolute(LPCWSTR relpath, LPWSTR abspath, size_t abspathlen)
{
    LPWSTR pKey;
    int relkeylen, keylen;

#ifdef _DEBUG_PATH
    LPCWSTR relpath0 = relpath;
#endif // _DEBUG
    LPCWSTR  abspath0 = abspath;

    *abspath = 0;
    while (*relpath) {
        if (getRegisterPath().getMap().empty() == false && (*relpath == _W('$')) && (*(relpath + 1) == _W('{'))) {
            relpath += 2;
            pKey = (LPWSTR)relpath;
            keylen = 0;
            while (*relpath && *relpath != _W('}')) {
                keylen++;
                relpath = _tcsinc(relpath);
            }
            if (*relpath) {
                relpath = _tcsinc(relpath);

                relkeylen = keylen;
                for (auto itrMap : getRegisterPath().getMap()) {
                    keylen = itrMap.first.length();
                    if (relkeylen == keylen && _wcsnicmp(pKey, itrMap.first.c_str(), keylen) == 0) {
                        _ustrcpy_s(abspath, abspathlen - (abspath - abspath0), itrMap.second.path.c_str());
                        abspath += _ustrlen(abspath);
                        abspathlen -= _ustrlen(abspath);
                        keylen = -1;    // 성공
                        break;
                    }
                }
                // 정의되지 않은 키(key)의 경우 그냥 건너 뛴다.
                _ASSERT(keylen == -1 && "HncPathToAbsolute : 정의되지 않은 키(key)입니다.");
            }
        } else {
                *abspath++ = *relpath++;
        }
    }

    *abspath = 0;

#ifdef _DEBUG_PATH
    _TRACE(_T("AbsolutePath : [%s] <-- [%s]\n"), abspath0, relpath0);
#endif // _DEBUG_PATH
}

static BOOL _CreateFullPath(LPCWSTR pDir)
{
    WCHAR path[_MAX_PATH] = { 0, };
    WCHAR *pSlash = NULL, *pStart = NULL;

    _ustrcpy_s(path, pDir);
    HncAppendBackSlash(path);

    if (_IsUNCPath(path)) {
        pStart = _ustrchr(path + 2, HNC_DIR_SEPARATOR_W);
        pStart++;
    } else {
        pStart = _ustrchr(path, HNC_DIR_SEPARATOR_W);
        pStart++;
    }

    if (pStart == NULL) // L"" 임.
        return FALSE;

    while ((pSlash = _ustrchr(pStart, HNC_DIR_SEPARATOR_W)) != 0) {

        *pSlash = L'\0';
        if (!HncExistDir(path) && !HncCreateDirectory(path, NULL))
            return FALSE;

        *pSlash++ = HNC_DIR_SEPARATOR_W;
        if (*pSlash)
            pStart = pSlash;
        else
            break;
    }

    return TRUE;
}


/**
 * @brief 파일이름을 제외한 경로를 생성한다.
 * @ingroup HncPath
 *
 * @param 상대경로를 가리키는 포인터.
 * @return 없음
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see
 */
BOOL HncPathCreate(LPCWSTR relpath)
{
    WCHAR abspath[_MAX_PATH], *p;

    HncPathToAbsolute(relpath, abspath, _MAX_PATH);

    // 마지막 문자가 Path separator가 아니면 파일이름까지 포함하고 있는 것이므로 파일이름을 잘라낸다.
    if ((p = _ustrrchr(abspath, HNC_DIR_SEPARATOR_W)) != (abspath + _ustrlen(abspath) - 1)) {
        if (p) {
            *p = L'\0';
        } else {
            // path separator가 없는 경우 상대경로로 판단하고 path 생성을 하지 않는다.
            return TRUE;
        }
    }

    return _CreateFullPath(abspath);
}

// GetTempFileName
/**
 * @brief 임시 파일의 이름을 얻어온다.(유닉스/리눅스용)
 * @param lpPathName 임시 파일이 생성될 디렉토리 이름.
 * @param lpPrefixString 임시 파일의 파일명을 지정. 이때 3문자까지만 지정이 가능하며, 이상을 썼을 때는 앞에 3문자까지만 남는다.
 * @param uUnique 0이면 임시 파일을 생성하고, 그 이상의 값을 전달하면 파일 이름만 구하고 실제로 파일을 생성하진 않는다.
 * @param lpTempFileName 임시 파일의 이름을 저장할 포인터.
 * @return 성공여부 성공시 유일한 파일명, 실패시 0을 리턴.
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
 <pre>
 </pre>
 * @see
 */
UINT HncGetTempFileName(LPCWSTR lpPathName, LPCWSTR lpPrefixString, UINT uUnique,
    LPWSTR lpTempFileName, size_t nTempFileNameLen)
{
    // 성능을 위해 충분한 버퍼 크기가 전달되었을 경우는 직접 API 함수를 호출한다.
    if (nTempFileNameLen >= _MAX_PATH)
        return GetTempFileNameW(lpPathName, lpPrefixString, uUnique, lpTempFileName);

    WCHAR buf[_MAX_PATH];
    UINT  ures = GetTempFileNameW(lpPathName, lpPrefixString, uUnique, buf);

    if (ures > 0)
        _ustrcpy_s(lpTempFileName, nTempFileNameLen, buf);
    return ures;
}

BOOL _IsUNCPath(LPCWSTR path)    // UNC(Universal Naming Convention) ex) \\server\share
{
    return (_ustrlen(path) > 2 && path[0] == HNC_DIR_SEPARATOR_W && path[1] == HNC_DIR_SEPARATOR_W);
}

BOOL HncExistDir(LPCWSTR dirname)
{
    DWORD attr;

    attr = HncGetFileAttributes(dirname);

    if (attr == 0xFFFFFFFF)
        return FALSE;

    return (attr & FILE_ATTRIBUTE_DIRECTORY);
}


// HncCreateDirectory
/**
 * @brief 디렉토리를 생성한다.
 * @param lpPathName 생성할 디렉토리의 경로.
 * @param lpSecurityAttributes 생성할 디렉토리의 security특성을 설정.
 * @return 성공여부 성공시 0이 아닌 값, 실패시 0을 리턴.
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see CreateDirectory
 */
BOOL HncCreateDirectory(LPCWSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes)
{
    return CreateDirectoryW(lpPathName, lpSecurityAttributes);
}


// GetFileAttributes
/**
 * @brief 파일의 속성을 얻어온다.
 * @param lpFileName 속성을 얻어올 파일의 이름.
 * @return 성공여부 성공시 파일의 속성, 실패시 INVALID_FILE_ATTRIBUTES를 리턴.
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see GetFileAttributes
 */
DWORD HncGetFileAttributes(LPCWSTR lpFileName)
{
    return GetFileAttributesW(lpFileName);
}

/**
 * @brief 문자열에 백슬래쉬(\) or 슬래쉬(/)를 추가한다.
 * @ingroup HncPath
 *
 * @param path  백슬래쉬(\) or 슬래쉬(/)를 추가할 문자열
 * @return 없음
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see
 */
void HncAppendBackSlash(LPWSTR path)
{
    size_t len = _ustrlen(path);

    if (len && _ustrrchr(path, HNC_DIR_SEPARATOR_W) != (path + len - 1)) {
        path[len] = HNC_DIR_SEPARATOR_W;
        path[len + 1] = L'\0';
    }
}

/**
 * @brief  임시 파일의 확장 경로를 만든다.
 * @param subdir 서브디렉토리.
 * @param prefix 임시 파일의 파일명을 지정. 이때 3문자까지만 지정이 가능하며, 이상을 썼을 때는 앞에 3문자까지만 남는다.
 * @param num 0이면 임시 파일을 생성하고, 그 이상의 값을 전달하면 파일 이름만 구하고 실제로 파일을 생성하진 않는다.
 * @param ext 확장디렉토리.
 * @param path 임시 파일의 이름을 저장할 포인터.
 * @param random 임시 파일명에 사용할 난수로 기본값은 0이고 기본값 사용시 메인 스레드 아이디로 지정한다.
 * @return 성공여부 성공시 생성된 num값, 실패시 0 리턴.
 * @par 예제:
 * @code

 * @endcode
 * @Remarks
<pre>
</pre>
 * @see HncPathToAbsolute(HNC 정의 함수), GetSystemTimeAsFileTime, FileTimeToDosDateTime
 */
UINT  HncPathMakeTempEx(LPCWSTR subdir, LPCWSTR prefix, UINT num, LPCWSTR ext, LPWSTR path, size_t pathlen, UINT random/* = 0*/)
{
    static WCHAR format[] = L"%s%s%08x%04x.%s";
    static WORD time = 0;
    WCHAR tmpdir[_MAX_PATH], tmp[_MAX_PATH];

    //    random = (random == 0) ? HncGetCurMainThreadID() : random;

    _ASSERT(num <= 0xffff);

    _ustrcpy_s(tmp, L"${Temp}\\");

    if (subdir)
        wcscat_s(tmp, subdir);

    HncPathToAbsolute(tmp, tmpdir, _MAX_PATH);

    if (num == 0 && !HncPathCreate(tmpdir))
        return 0;

    // 1. num 값이 지정된 경우
    if (num) {
        _usprintf_s(path, pathlen, format, tmpdir, prefix, random, num, ext);
        return num;
    }

    // 2. num 값이 0으로 호출된 경우
    if (time == 0) {
        FILETIME filetime;
        WORD date;

        GetSystemTimeAsFileTime(&filetime);
        FileTimeToDosDateTime(&filetime, &date, &time);        // time 임의 값으로 초기화
    } else {
        time = (time == 0xffff) ? 1 : time + 1;        // 이후로는 1씩 증가시켜 사용
                                                    // 임의 값, ..., 65534, 65535, 1, 2, ...
    }

    num = time ? time : time + 1;

    for (;;) {
        _usprintf_s(path, pathlen, format, tmpdir, prefix, random, num, ext);

        if (_waccess(path, 0) == -1)
            break;

        num = (num == 0xffff) ? 1 : num + 1;

        if (num == time) {
            _ASSERT(FALSE);        // 65535개의 시도가 모두 실패
            return 0;
        }
    }

    return num;    // 반환 값: 성공일 때는 생성된 num 값, 실패일 때는 0 반환해야 한다.
}

BOOL HncDeleteFile_s(LPCWSTR lpFileName)
{
    WCHAR szPath[_MAX_PATH] = { 0, };
    HncPathToAbsolute(L"${Common}\\hncfile.bin", szPath, _MAX_PATH);
    if (_uaccess_s(szPath, 0) == 0) {
        CopyFileW(lpFileName, szPath, FALSE);
    } else {
        WCHAR szSignature[] = L"Hnc File Dump"; //Dump로 채워졌다는 시그니처
        FILE *pf = NULL;
        if ((_wfopen_s(&pf, lpFileName, L"wb") == 0) && (pf != NULL)) {
            fwrite(szSignature, sizeof(WCHAR), _ustrlen(szSignature), pf);
            fclose(pf);
        }
    }
    return DeleteFileW(lpFileName);
}
