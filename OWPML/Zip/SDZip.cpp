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
#include <algorithm>

#include "zip.h"
#include "unzip.h"
#include "SDZip.h"

namespace OWPML {

    class CZipHandle
    {
    public:
        CZipHandle() : m_hzip(NULL) {}

    public:
        HZIP m_hzip;
    };


    BOOL _GetUnZipInfos(HZIP hz, ZIP_INFOS* zipinfos)
    {
        if ((hz == NULL) || (zipinfos == NULL))
            return FALSE;

        ZIPENTRY entry;
        int nItem, i;

        if (GetUnZipItemInfo(hz, -1, &entry) != ZR_OK) {
            zipinfos->clear();
            return FALSE;
        }

        hncstd::wstring entryPath;
        nItem = entry.index;
        for (i = 0; i < nItem; ++i) {
            if (GetUnZipItemInfo(hz, i, &entry) == ZR_OK) {
                if (entry.attr != FILE_ATTRIBUTE_DIRECTORY) { // 파일만 저장한다.
                    // 일부 압축 프로그램에서 구분자를 Backward Slash로 사용한다. 
                    // Forward Slash로 변환후 검사
                    entryPath = hncstd::wstring(entry.name);
                    std::replace(entryPath.begin(), entryPath.end(), L'\\', L'/');

                    size_t len = _ustrlen(entryPath.c_str());
                    // WARN : emtry.name의 끝이 /로 끝나면 디렉터리이니 저장하지 않는다.
                    // WARN : ODF 파일 크기가 0인 것이 존재한다. (ex : \Configurations2\accelerator\current.xml )
                    if ((entryPath[len - 1] != L'/') && (len != 0) && (entry.unc_size != 0)) {
                        ZIP_INFO zipinfo;

                        zipinfo.zipindex = i;
                        zipinfos->insert(std::pair<hncstd::wstring, ZIP_INFO>(hncstd::wstring(entryPath), zipinfo));
                    }
                }
            }
        }

        return TRUE;
    }

    BOOL _GetZipInfos(HZIP hz, ZIP_INFOS* zipinfos)
    {
        if ((hz == NULL) || (zipinfos == NULL))
            return FALSE;

        TZipFileInfo entry;
        int i = 0;
        hncstd::wstring entryPath;

        while (GetZipItemInfo(hz, i, &entry) == ZR_OK) {
            if (entry.atx != FILE_ATTRIBUTE_DIRECTORY) { // 파일만 저장한다.
                // 일부 압축 프로그램에서 구분자를 Backward Slash로 사용한다. 
                // Forward Slash로 변환후 검사
                entryPath = hncstd::wstring(entry.name);
                std::replace(entryPath.begin(), entryPath.end(), L'\\', L'/');

                size_t len = _ustrlen(entryPath.c_str());
                // WARN : emtry.name의 끝이 /로 끝나면 디렉터리이니 저장하지 않는다.
                // WARN : ODF 파일 크기가 0인 것이 존재한다. (ex : \Configurations2\accelerator\current.xml )
                if ((entryPath[len - 1] != L'/') && (len != 0) && (entry.siz != 0)) {
                    ZIP_INFO zipinfo;

                    zipinfo.zipindex = i;
                    zipinfos->insert(std::pair<hncstd::wstring, ZIP_INFO>(hncstd::wstring(entryPath), zipinfo));
                }
            }

            i++;
        }

        return TRUE;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   CZip
    //////////////////////////////////////////////////////////////////////////////////////////////////////////

    CZip::CZip(void) : m_zippathlist(new std::vector<hncstd::wstring>), m_dirfiles(new std::vector<hncstd::wstring>), m_pHzip(new CZipHandle)
    {
    }

    CZip::~CZip(void)
    {
        if (m_pHzip) {
            if (m_pHzip->m_hzip != NULL)
                CloseFile();
            delete m_pHzip;
        }

        if (m_dirfiles)
            delete m_dirfiles;

        if (m_zippathlist)
            delete m_zippathlist;
    }

    BOOL CZip::CreareZipFile(LPCWSTR strZipfile)
    {
        HZIP hzip;

        if (m_pHzip->m_hzip != NULL) {
            // 이미 압축 파일의 핸들이 존재 한다.
            _ASSERTE(FALSE && "ZipFile Handle Exist!!!");
            return FALSE;
        }

        hzip = CreateZip(strZipfile, NULL);
        if (hzip == NULL) {
            _ASSERTE(FALSE && "CreateZip function error !!!");
            m_pHzip->m_hzip = NULL;
            return FALSE;
        }

        m_pHzip->m_hzip = hzip;
        return TRUE;
    }

    BOOL CZip::CreareZipFile(void* pbuffer, int bufferlen)
    {
        HZIP hzip;

        if (m_pHzip->m_hzip != NULL) {
            // 이미 압축 파일의 핸들이 존재 한다.
            _ASSERTE(FALSE && "ZipFile Handle Exist!!!");
            return FALSE;
        }

        hzip = CreateZip(pbuffer, bufferlen, NULL);
        if (hzip == NULL) {
            _ASSERTE(FALSE && "CreateZip function error !!!");
            m_pHzip->m_hzip = NULL;
            return FALSE;
        }

        m_pHzip->m_hzip = hzip;
        return TRUE;
    }

    BOOL CZip::CreareZipFile(LPCWSTR strZipfile, LPCWSTR strDirectory)
    {
        if (CreareZipFile(strZipfile)) {
            if (CompressDirectory(NULL, strDirectory))
                return TRUE;
        }

        return FALSE;
    }

    BOOL CZip::Compress(LPCWSTR strZippath, LPCWSTR strLocalfilepath, BOOL bCompress, CEncryptInfo* pencryptinfo)
    {
        ZRESULT result;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        if (FindFile(strZippath) == TRUE) {
            _ASSERTE(FALSE && "File is Exist !!!");
            return FALSE;
        }

        if (bCompress)
            result = ZipAdd(m_pHzip->m_hzip, strZippath, strLocalfilepath, pencryptinfo);
        else
            result = ZipAddUnCompress(m_pHzip->m_hzip, strZippath, strLocalfilepath, pencryptinfo);

        if (result == ZR_OK) {
            m_zippathlist->push_back(hncstd::wstring(strZippath));
            return TRUE;
        }

        return FALSE;
    }

    BOOL CZip::Compress(LPCWSTR strZippath, void* pbuffer, int bufflen, BOOL bCompress, CEncryptInfo* pencryptinfo)
    {
        ZRESULT result;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        if (FindFile(strZippath) == TRUE) {
            _ASSERTE(FALSE && "File is Exist !!!");
            return FALSE;
        }

        if (bCompress)
            result = ZipAdd(m_pHzip->m_hzip, strZippath, pbuffer, bufflen, pencryptinfo);
        else
            result = ZipAddUnCompress(m_pHzip->m_hzip, strZippath, pbuffer, bufflen, pencryptinfo);

        if (result == ZR_OK) {
            m_zippathlist->push_back(hncstd::wstring(strZippath));
            return TRUE;
        }

        return FALSE;
    }

    BOOL CZip::Compress(LPCWSTR strDirectory)
    {
        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        if (CompressDirectory(NULL, strDirectory))
            return TRUE;

        return TRUE;
    }

    BOOL CZip::CompressDirectory(LPCWSTR strZippath, LPCWSTR strDirectory)
    {
        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        if (_uaccess_s(strDirectory, 0) != 0) {
            return FALSE;
        }

        _FindFile(strDirectory);

        if (_CompressDirFiles(strZippath, strDirectory)) {
            return TRUE;
        }

        return FALSE;
    }

    BOOL CZip::CloseFile()
    {
        if (m_pHzip->m_hzip != NULL) {
            ZRESULT result = CloseZip(m_pHzip->m_hzip);
            m_pHzip->m_hzip = NULL;

            if (result == ZR_OK)
                return TRUE;
        }

        m_zippathlist->clear();

        return FALSE;
    }


    BOOL CZip::FindFile(LPCWSTR strZippath)
    {
        std::vector<hncstd::wstring>::iterator ifind;
        hncstd::wstring strtemppath(strZippath);
        ifind = find(m_zippathlist->begin(), m_zippathlist->end(), strtemppath);

        if (ifind != m_zippathlist->end()) {
            return TRUE;
        }

        return FALSE;
    }

    BOOL CZip::_CompressDirFiles(LPCWSTR strZippath, LPCWSTR strDirectory)
    {
        int count = (int)m_dirfiles->size();
        int i, strdirlen;
        LPCWSTR strlocalfile;
        hncstd::wstring zippathtemp, zippath;

        strdirlen = (int)_ustrlen(strDirectory);
        if (strDirectory[strdirlen - 1] == L'\\') {
            strdirlen--;
        }

        if (strZippath == NULL) {
            zippathtemp.assign(L"");
        } else {
            int strpathlen = (int)_ustrlen(strZippath);

            if ((strZippath[strpathlen - 1] == L'\\') || (strZippath[strpathlen - 1] == L'/')) {
                strpathlen--;
            }
            zippathtemp.assign(strZippath, strpathlen);
        }

        for (i = 0; i < count; ++i) {
            zippath = zippathtemp;
            strlocalfile = m_dirfiles->at(i).c_str();
            zippath.append(strlocalfile + strdirlen);
            std::replace(zippath.begin(), zippath.end(), L'\\', L'/');

            ZRESULT result;

            result = ZipAdd(m_pHzip->m_hzip, zippath.c_str() + 1, strlocalfile);

            if (result != ZR_OK) {
                return FALSE;
            }

            m_zippathlist->push_back(zippath.c_str() + 1);
        }

        return TRUE;
    }

    void CZip::_FindFile(LPCWSTR strpath)
    {
        HANDLE hSrch;
        WIN32_FIND_DATAW wfd;
        WCHAR fname[_MAX_PATH] = { 0, };
        BOOL bResult = TRUE;
        WCHAR dirve[_MAX_DRIVE] = { 0, };
        WCHAR dir[_MAX_PATH] = { 0, };
        WCHAR newpath[_MAX_PATH] = { 0, };

        hSrch = FindFirstFileW(strpath, &wfd);
        if (hSrch == INVALID_HANDLE_VALUE)
            return;

        while (bResult) {
            _usplitpath_s(strpath, dirve, _MAX_DRIVE, dir, _MAX_PATH, NULL, 0, NULL, 0);

            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (wfd.cFileName[0] != L'.') {
                    _usprintf_s(newpath, _MAX_PATH, L"%s%s%s\\*.*", dirve, dir, wfd.cFileName);
                    _FindFile(newpath);
                }
            } else {
                _usprintf_s(fname, _MAX_PATH, L"%s%s%s", dirve, dir, wfd.cFileName);
                m_dirfiles->push_back(fname);
            }

            bResult = FindNextFileW(hSrch, &wfd);
        }

        FindClose(hSrch);
    }

    BOOL CZip::GetZipInfos(ZIP_INFOS* zipinfos)
    {
        return _GetZipInfos(m_pHzip->m_hzip, zipinfos);
    }

    long CZip::GetCompSize(int zipindex)
    {
        TZipFileInfo entry;

        if (GetZipItemInfo(m_pHzip->m_hzip, zipindex, &entry) != ZR_OK) {
            return -1;
        }

        return entry.siz;
    }

    BOOL CZip::GetItem(ZIP_INFOS* zipinfos, LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& resdsize)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ifind = zipinfos->find(hncstd::wstring(strZippath));
        if (ifind != zipinfos->end()) {
            ZRESULT result;

            result = GetzipItem(m_pHzip->m_hzip, ifind->second.zipindex, pbuffer, bufferlen, resdsize);

            if (result == ZR_OK) {
                bend = TRUE;
                return TRUE;
            } else if (result == ZR_MORE) {
                bend = FALSE;
                return TRUE;
            }
        }

        bend = TRUE;
        return FALSE;
    }

    BOOL CZip::MakeZipfile(LPCWSTR strZippath, LPCWSTR strLocalfilepath)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ZIP_INFOS zipinfos;

        if (!_GetZipInfos(m_pHzip->m_hzip, &zipinfos))
            return FALSE;

        ifind = zipinfos.find(hncstd::wstring(strZippath));
        if (ifind != zipinfos.end()) {
            ZRESULT result;

            result = UnzipItemFile(m_pHzip->m_hzip, ifind->second.zipindex, strLocalfilepath);
            if (result == ZR_OK) {
                return TRUE;
            }
        }

        return FALSE;
    }

    //BOOL CZip::GetItem(ZIP_INFOS* zipinfos, LPCWSTR strZippath, LPCWSTR strLocalfilepath)
    //{
    //    ZIP_INFOS::iterator ifind;
    //
    //    if (m_pHzip->m_hzip == NULL) {
    //        _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
    //        return FALSE;
    //    }
    //
    //    ifind = zipinfos->find(hncstd::wstring(strZippath));
    //    if (ifind != zipinfos->end()) {
    //        ZRESULT result;
    //
    //        result = GetzipItem(m_pHzip->m_hzip, ifind->second.zipindex, strLocalfilepath);
    //        if (result == ZR_OK) {
    //            ifind->second.localfilepath.append(strLocalfilepath);
    //            return TRUE;
    //        }
    //    }
    //
    //    return FALSE;
    //}

    //////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   CUnZip
    //////////////////////////////////////////////////////////////////////////////////////////////////////////


    CUnZip::CUnZip() : m_zipInfo(new ZIP_INFOS), m_pHzip(new CZipHandle)
    {
    }

    CUnZip::~CUnZip()
    {
        if (m_pHzip) {
            if (m_pHzip->m_hzip != NULL)
                CloseFile();
            delete m_pHzip;
        }

        if (m_zipInfo)
            delete m_zipInfo;
    }

    BOOL CUnZip::OpenZipFile(LPCWSTR strZipfile)
    {
        HZIP hzip;

        if (m_pHzip->m_hzip != NULL) {
            // 이미 압축 파일의 핸들이 존재 한다.
            _ASSERTE(FALSE && "ZipFile Handle Exist!!!");
            return FALSE;
        }

        hzip = OpenZip(strZipfile, NULL);

        if (hzip == NULL) {
            m_pHzip->m_hzip = NULL;
            _ASSERTE(FALSE && "CreateZip function error !!!");
            return FALSE;
        }

        m_pHzip->m_hzip = hzip;
        _SetZipInfo();
        return TRUE;
    }

    BOOL CUnZip::OpenZipFile(void* pbuffer, int bufferlen)
    {
        HZIP hzip;

        if (m_pHzip->m_hzip != NULL) {
            // 이미 압축 파일의 핸들이 존재 한다.
            _ASSERTE(FALSE && "ZipFile Handle Exist!!!");
            return FALSE;
        }

        hzip = OpenZip(pbuffer, bufferlen, NULL);

        if (hzip == NULL) {
            m_pHzip->m_hzip = NULL;
            _ASSERTE(FALSE && "CreateZip function error !!!");
            return FALSE;
        }

        m_pHzip->m_hzip = hzip;
        _SetZipInfo();
        return TRUE;
    }

    BOOL CUnZip::Decompress(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& decompress)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ifind = _Find(strZippath);
        if (ifind != m_zipInfo->end()) {
            ZRESULT result;

            result = UnzipItem(m_pHzip->m_hzip, ifind->second.zipindex, pbuffer, bufferlen, decompress);

            if (result == ZR_OK) {
                bend = TRUE;
                return TRUE;
            } else if (result == ZR_MORE) {
                bend = FALSE;
                return TRUE;
            }
        }

        bend = TRUE;
        return FALSE;
    }

    BOOL CUnZip::Decompress(LPCWSTR strZippath, LPCWSTR strLocalfilepath)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ifind = _Find(strZippath);
        if (ifind != m_zipInfo->end()) {
            ZRESULT result;

            result = UnzipItem(m_pHzip->m_hzip, ifind->second.zipindex, strLocalfilepath);
            if (result == ZR_OK) {
                ifind->second.localfilepath.assign(strLocalfilepath);
                return TRUE;
            }
        }

        return FALSE;
    }

    BOOL CUnZip::GetItem(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& decompress)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ifind = _Find(strZippath);
        if (ifind != m_zipInfo->end()) {
            ZRESULT result;

            result = GetUnzipItem(m_pHzip->m_hzip, ifind->second.zipindex, pbuffer, bufferlen, decompress);

            if (result == ZR_OK) {
                bend = TRUE;
                return TRUE;
            } else if (result == ZR_MORE) {
                bend = FALSE;
                return TRUE;
            }
        }

        bend = TRUE;
        return FALSE;
    }

    BOOL CUnZip::GetItem(LPCWSTR strZippath, LPCWSTR strLocalfilepath)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ifind = _Find(strZippath);
        if (ifind != m_zipInfo->end()) {
            ZRESULT result;

            result = GetUnzipItem(m_pHzip->m_hzip, ifind->second.zipindex, strLocalfilepath);
            if (result == ZR_OK) {
                ifind->second.localfilepath.assign(strLocalfilepath);
                return TRUE;
            }
        }

        return FALSE;
    }

    BOOL CUnZip::FindFile(LPCWSTR strZippath)
    {
        ZIP_INFOS::iterator ifind;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        ifind = _Find(strZippath);
        if (ifind != m_zipInfo->end()) {
            return TRUE;
        }

        return FALSE;
    }

    BOOL CUnZip::Compress(LPCWSTR strZippath, LPCWSTR strLocalfilepath, BOOL /*bCompress*/, CEncryptInfo* pencryptinfo)
    {
        ZRESULT result;

        if (m_pHzip->m_hzip == NULL) {
            _ASSERTE((m_pHzip->m_hzip != NULL) && "ZipFile Handle is NULL !!!");
            return FALSE;
        }

        result = ZipAddUnCompress(m_pHzip->m_hzip, strZippath, strLocalfilepath, pencryptinfo);

        return FALSE;
    }

    LPCWSTR CUnZip::GetZipFileLocalPath(LPCWSTR strZippath)
    {
        LPCWSTR strpath = NULL;

        ZIP_INFOS::iterator ifind;

        ifind = _Find(strZippath);
        if (ifind != m_zipInfo->end()) {
            strpath = ifind->second.localfilepath.c_str();
        }

        return strpath;
    }

    long CUnZip::GetCompSize(int zipindex)
    {
        ZIPENTRY entry;

        if (GetUnZipItemInfo(m_pHzip->m_hzip, zipindex, &entry) != ZR_OK) {
            return -1;
        }

        return entry.comp_size;
    }

    void CUnZip::SetEncryptInfo(LPCWSTR strZippath, CEncryptInfo* encryptinfo)
    {
        if (encryptinfo) {
            ZIP_INFOS::iterator iter;
            iter = _Find(strZippath);
            if (iter != m_zipInfo->end()) {
                SetExtEncryptInfo(m_pHzip->m_hzip, iter->second.zipindex, encryptinfo);
            }
        }
    }

    BOOL CUnZip::CloseFile()
    {
        if (m_pHzip->m_hzip != NULL) {
            ZRESULT result = CloseZip(m_pHzip->m_hzip);
            m_pHzip->m_hzip;

            if (result == ZR_OK)
                return TRUE;
        }

        return FALSE;
    }

    BOOL CUnZip::_SetZipInfo()
    {
        return _GetUnZipInfos(m_pHzip->m_hzip, m_zipInfo);
    }

    void CUnZip::_DeleteFile(LPCWSTR strdirectory)
    {
        HANDLE hSrch;
        WIN32_FIND_DATAW wfd;
        WCHAR fname[_MAX_PATH] = { 0, };
        BOOL bResult = TRUE;
        WCHAR dirve[_MAX_DRIVE] = { 0, };
        WCHAR dir[_MAX_PATH] = { 0, };
        WCHAR newpath[_MAX_PATH] = { 0, };

        hSrch = FindFirstFileW(strdirectory, &wfd);
        if (hSrch == INVALID_HANDLE_VALUE)
            return;

        while (bResult) {
            _usplitpath_s(strdirectory, dirve, _MAX_DRIVE, dir, _MAX_PATH, NULL, 0, NULL, 0);

            if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                if (wfd.cFileName[0] != L'.') {
                    _usprintf_s(newpath, _MAX_PATH, L"%s%s%s\\*.*", dirve, dir, wfd.cFileName);
                    _DeleteFile(newpath);

                    _usprintf_s(newpath, _MAX_PATH, L"%s%s%s", dirve, dir, wfd.cFileName);
                    ::RemoveDirectoryW(newpath);
                }
            } else {
                _usprintf_s(fname, _MAX_PATH, L"%s%s%s", dirve, dir, wfd.cFileName);
                ::DeleteFileW(fname);
            }

            bResult = FindNextFileW(hSrch, &wfd);
        }

        FindClose(hSrch);
    }

    ZIP_INFOS::iterator CUnZip::_Find(LPCWSTR strZippath)
    {
        ZIP_INFOS::iterator fiter;
        if (strZippath == NULL)
            return m_zipInfo->end();

        for (fiter = m_zipInfo->begin(); fiter != m_zipInfo->end(); ++fiter) {
            if (_ustricmp(fiter->first.c_str(), strZippath) == 0) {
                return fiter;
            }
        }
        return fiter;
    }

}