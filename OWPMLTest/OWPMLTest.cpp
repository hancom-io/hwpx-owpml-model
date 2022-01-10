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

#include <Shlwapi.h>
#include "OWPMLApi/OWPMLApi.h"

typedef enum {
    CONVERROR_NO_ARG = 0,
    CONVERROR_ARG_INCORRECT,
    CONVERROR_ARG_UNKNOWN,
    CONVERROR_ARG_INSUFFICIENT,
    CONVERROR_OPEN_FAIL,
    CONVERROR_OPEN_SUCCESS,
    CONVERROR_CONV_FAIL,
    CONVERROR_CONV_SUCCESS,
    CONVERROR_FILE_NOT_EXIST,
    CONVERROR_FILE_IN_EXT_ERROR,
    CONVERROR_FILE_OUT_EXT_ERROR,
    CONVERROR_FILE_IS_DIR,
    CONVERROR_DIR_NOT_CREATE,
}CONVERROR;

void InfoText(const LONG type) {
    WCHAR text[600] = { 0, };
    BOOL IsError = TRUE;
    switch (type) {
    case CONVERROR_NO_ARG:
        swprintf_s(text, _countof(text), L"%s", L"프로그램을 실행하려면 커맨드 창으로 실행하여 "
            L"변환할 파일의 경로를 입력해주세요\n\n"
            L"사용법 : OWPMLTest.exe [/c] \"InputFile\" [\"OutputFile\"]\n\n"
            L"default -    InputFile을 변환합니다.\n"
            L"/c -         파일을 변환합니다.\n"
            L"InputFile -  변환할 파일의 경로입니다. 생략 시 InputFile과 같은 디렉토리에 owpml파일로 변환됩니다.\n"
            L"OutputFile - 결과 파일의 경로입니다. 결과 파일의 이름이 중복될 경우 _1, _2, ... 순의 숫자가 파일 이름 뒤에 붙어 저장됩니다."
            L"\n주의 : 파일 이름에 공백이 있을 경우 \"파일 경로\" 로 적어주세요. 파일 이름에 공백이 없을 경우 생략 가능합니다.");
        break;
    case CONVERROR_ARG_INCORRECT:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 인자의 순서가 잘못되었습니다. 확인 후 다시 입력해주세요\n"
            L"사용법 : OWPMLTest.exe [/c] \"InputFile\" [\"OutputFile\"]");
        break;
    case CONVERROR_ARG_UNKNOWN:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 잘못된 인자가 들어왔습니다. 확인 후 다시 입력해주세요\n"
            L"사용법 : OWPMLTest.exe [/c] \"InputFile\" [\"OutputFile\"]");
        break;
    case CONVERROR_ARG_INSUFFICIENT:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 인자가 불충분합니다. 변환할 파일의 경로를 입력해주세요.\n"
            L"사용법 : OWPMLTest.exe [/c] \"InputFile\" [\"OutputFile\"]");
        break;
    case CONVERROR_CONV_FAIL:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 변환 과정이 실패되었습니다.");
        break;
    case CONVERROR_CONV_SUCCESS:
        IsError = FALSE;
        swprintf_s(text, _countof(text), L"%s", L"변환이 완료되었습니다.");
        break;
    case CONVERROR_FILE_NOT_EXIST:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 변환할 파일이 존재하지 않습니다.\n파일 경로를 다시 확인해주세요");
        break;
    case CONVERROR_FILE_IN_EXT_ERROR:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 변환할 파일의 형식이 owpml이 아닙니다.\n파일 확장자를 다시 확인해주세요");
        break;
    case CONVERROR_FILE_OUT_EXT_ERROR:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 결과 파일의 형식이 owpml가 아닙니다.\n파일 확장자를 다시 확인해주세요");
        break;
    case CONVERROR_FILE_IS_DIR:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 올바른 파일의 확장가 아닙니다. \n확장자를 포함하여 전체 경로를 다 입력했는지 확인해주세요");
        break;
    case CONVERROR_DIR_NOT_CREATE:
        swprintf_s(text, _countof(text), L"%s", L"\n에러 : 디렉토리 생성에 실패하였습니다. \n출력 파일의 경로를 다시 설정해주세요.");
        break;
    }

    wprintf(L"%s\n", text);

}

int wmain(int argc, wchar_t* argv[])
{
    BOOL IsConvert = FALSE;       // 파일의 변환 여부
    BOOL HasInputPath = FALSE;    // 변환할 파일의 경로가 인자로 전달된 경우
    BOOL HasOutputPath = FALSE;   // 변활될 파일의 경로가 인자로 전달된 경우
    WCHAR szOrgPath[_MAX_PATH] = { 0, };
    WCHAR szDesPath[_MAX_PATH] = { 0, };
    WCHAR szTempPath[_MAX_PATH] = { 0, };
    WCHAR szIndex[10] = { 0, };
    INT index = 1;
    LONG IResult = 0;

    if (argc == 1) {
        InfoText(CONVERROR_NO_ARG);
    } else {
        for (int i = 1; i < argc; i++) {
            if (*argv[i] == L'/' || *argv[i] == L'-') {
                if (HasInputPath == TRUE) {
                    InfoText(CONVERROR_ARG_INCORRECT);
                    return 0;
                }
                switch (towlower(argv[i][1])) {
                case L'c':
                    IsConvert = TRUE;
                    break;
                default:
                    InfoText(CONVERROR_ARG_UNKNOWN);
                    return 0;
                    break;
                }
            } else {
                if (HasInputPath == FALSE) {
                    wcscpy_s(szOrgPath, _MAX_PATH, argv[i]);
                    HasInputPath = TRUE;
                } else {
                    if (IsConvert == FALSE) {
                        InfoText(CONVERROR_ARG_INCORRECT);
                        return 0;
                    }
                    wcscpy_s(szDesPath, _MAX_PATH, argv[i]);
                    HasOutputPath = TRUE;
                }
            }
        }
        
        if (HasInputPath == TRUE) {
            //InputPath의 확장자 확인
            if (_wcsicmp(PathFindExtensionW(szOrgPath), L".hwpx") != 0) {
                InfoText(CONVERROR_FILE_IN_EXT_ERROR);
                return 0;
            }

            //InputPath의 파일 존재 여부 확인
            if (PathFileExistsW(szOrgPath) == FALSE) {
                InfoText(CONVERROR_FILE_NOT_EXIST);
                return 0;
            }

            //OutputPath가 존재하지 않으면 InputPath를 기준으로 OutputPath를 만듦
            if (HasOutputPath == FALSE) {
                wcscpy_s(szDesPath, _countof(szDesPath), szOrgPath);
                PathRenameExtensionW(szDesPath, L".hwpx");
            } else {
                //OutputPath의 확장자 확인
                if (_wcsicmp(PathFindExtensionW(szDesPath), L".hwpx") != 0) {
                    InfoText(CONVERROR_FILE_OUT_EXT_ERROR);
                    return 0;
                }
                ZeroMemory(szTempPath, _MAX_PATH);
                wcsncpy_s(szTempPath, _countof(szTempPath), szDesPath, StrRChrW(szDesPath, NULL, L'\\') - szDesPath + 1);
                CreateDirectoryW(szTempPath, NULL);
                if (GetLastError() == ERROR_PATH_NOT_FOUND) {
                    InfoText(CONVERROR_DIR_NOT_CREATE);
                    return 0;
                }
            }

            ZeroMemory(szTempPath, _MAX_PATH);
            wcscpy_s(szTempPath, _countof(szTempPath), szDesPath);

            //파일 중복 체크 중복 시 파일 이름 뒤에 _1, _2, ... 붙인다
            while (PathFileExistsW(szTempPath)) {
                ZeroMemory(szTempPath, _MAX_PATH);
                wcscpy_s(szTempPath, _countof(szTempPath), szDesPath);
                PathRemoveExtensionW(szTempPath);
                swprintf_s(szIndex, _countof(szIndex), L"_%d", index++);
                wcscat_s(szTempPath, _countof(szTempPath), szIndex);
                PathAddExtensionW(szTempPath, L".hwpx");
            }
            ZeroMemory(szDesPath, _MAX_PATH);
            wcscpy_s(szDesPath, _countof(szDesPath), szTempPath);
        } else {
            if (IsConvert == TRUE) { // 변환 옵션이 켜졌으나 파일 경로가 없을 경우
                InfoText(CONVERROR_ARG_INSUFFICIENT);
                return 0;
            }
        }

        if (HasInputPath == TRUE) {
            OWPML::COwpmlDocumnet* document = OWPML::COwpmlDocumnet::OpenDocument(szOrgPath);
            if (document == NULL) {
                return 0;
            }

            document->SaveDocument(szDesPath);

            delete document;
        }
        
        return 1;
    }
}