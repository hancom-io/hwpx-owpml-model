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



#ifndef OWPML_ZIP_H
#define OWPML_ZIP_H

namespace OWPML {

    class CZipHandle;
    class CEncryptInfo;

    typedef struct zipinfo
    {
        hncstd::wstring localfilepath;
        int zipindex;

        zipinfo() : zipindex(-1)
        {}

    } ZIP_INFO;

    typedef std::map<hncstd::wstring, ZIP_INFO> ZIP_INFOS;

    class CZip
    {
    public:
        CZip(void);
        virtual ~CZip(void);

    public:
        // Zipping
        BOOL CreareZipFile(LPCWSTR strZipfile);
        BOOL CreareZipFile(void* pbuffer, int bufferlen);
        // 하위 디렉토리에 있는 모든 파일을 압축한다.
        BOOL CreareZipFile(LPCWSTR strZipfile, LPCWSTR strDirectory);

        BOOL Compress(LPCWSTR strZippath, LPCWSTR strLocalfilepath, BOOL bCompress = TRUE, CEncryptInfo* pencryptinfo = NULL);
        BOOL Compress(LPCWSTR strZippath, void* pbuffer, int bufflen, BOOL bCompress = TRUE, CEncryptInfo* pencryptinfo = NULL);
        // 하위 디렉토리에 있는 모든 파일을 압축한다.
        BOOL Compress(LPCWSTR strDirectory);
        BOOL CompressDirectory(LPCWSTR strZippath, LPCWSTR strDirectory);

        BOOL GetItem(ZIP_INFOS* zipinfos, LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& resdsize);
        //    BOOL GetItem(ZIP_INFOS* zipinfos, LPCWSTR strZippath, LPCWSTR strLocalfilepath);

        BOOL MakeZipfile(LPCWSTR strZippath, LPCWSTR strLocalfilepath);

        long GetCompSize(int zipindex);

        BOOL CloseFile();

        BOOL FindFile(LPCWSTR strZippath);

        BOOL GetZipInfos(ZIP_INFOS* zipinfos);

    private:
        BOOL _CompressDirFiles(LPCWSTR strZippath, LPCWSTR strDirectory);
        void _FindFile(LPCWSTR strpath);

    private:
        std::vector<hncstd::wstring> *m_zippathlist;
        std::vector<hncstd::wstring> *m_dirfiles;
        CZipHandle* m_pHzip;
    };

    class CUnZip
    {
    public:
        CUnZip();
        virtual ~CUnZip();

    public:
        BOOL OpenZipFile(LPCWSTR strZipfile);
        BOOL OpenZipFile(void* pbuffer, int bufferlen);

        BOOL Decompress(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& decompress);
        BOOL Decompress(LPCWSTR strZippath, LPCWSTR strLocalfilepath);
        BOOL GetItem(LPCWSTR strZippath, void* pbuffer, int bufferlen, BOOL& bend, int& decompress);
        BOOL GetItem(LPCWSTR strZippath, LPCWSTR strLocalfilepath);
        BOOL FindFile(LPCWSTR strZippath);

        BOOL Compress(LPCWSTR strZippath, LPCWSTR strLocalfilepath, BOOL bCompress = TRUE, CEncryptInfo* pencryptinfo = NULL);

        LPCWSTR GetZipFileLocalPath(LPCWSTR strZippath);
        long GetCompSize(int zipindex);

        void SetEncryptInfo(LPCWSTR strZippath, CEncryptInfo* encryptinfo);

        ZIP_INFOS* GetZipInfo(void) { return m_zipInfo; }

        BOOL CloseFile();

    private:
        BOOL _SetZipInfo();
        void _DeleteFile(LPCWSTR strZippath);
        ZIP_INFOS::iterator _Find(LPCWSTR strZippath);

    private:
        ZIP_INFOS* m_zipInfo;
        CZipHandle* m_pHzip;
    };

}

#endif OWPML_ZIP_H