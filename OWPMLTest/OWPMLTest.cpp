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

#include "HwpxToText.h"
#include <string>
#include <sstream>
#include <codecvt>
#include <locale>

void PrintText(OWPML::CT* text, std::wstring& outtext)
{
    if (text == nullptr) {
        return;
    }

    int childs = text->GetChildCount();
    for (int i = 0; i < childs; i++) {
        OWPML::CObject* pObject = text->GetObjectByIndex(i);

        if (pObject->GetID() == ID_PARA_Char) {
            OWPML::CChar* pChar = (OWPML::CChar*)pObject;
            wprintf(L"%s", pChar->Getval());
            outtext.append(pChar->Getval());
        }
    }
}

void ProcessingTextElement(OWPML::CObject* object, std::wstring& outtext)
{
    if (object == NULL) {
        return;
    }

    std::u16string text, buff;

    OWPML::Objectlist* pChildList = object->GetObjectList();
    OWPML::CObject* pObject = NULL;

    if (pChildList) {
        for (auto pObject : *pChildList) {
            if (pObject) {
                switch (pObject->GetID()) {
                case ID_PARA_T:
                {
                    PrintText((OWPML::CT*)pObject, outtext);
                    break;
                }
				case ID_PARA_LineSeg:
				{
					outtext += L"\n";
					break;
				}
                default:
                    ProcessingTextElement(pObject, outtext);
                    break;
                }
            }
        } // for
    }
    return;
}

void GetSectionText(OWPML::COwpmlDocumnet* document, std::wstring& outtext)
{
    std::vector<OWPML::CSectionType*>* sections = document->GetSections();
    std::vector<OWPML::CSectionType*>::iterator iter = sections->begin();

    if (iter != sections->end()) {
        ProcessingTextElement(*iter, outtext);
    }
}

void HwpxToText(LPCWSTR srcPath, LPCWSTR targetPath)
{
	std::locale utf8Locale(std::locale(), new std::codecvt_utf8_utf16<wchar_t>);
    OWPML::COwpmlDocumnet* pdocument = OWPML::COwpmlDocumnet::OpenDocument(srcPath);

    if (pdocument == nullptr) {
        return;
    }

    std::wstring outtext;
    GetSectionText(pdocument, outtext);

	std::wofstream f;
	f.imbue(utf8Locale);
	f.open(targetPath, std::ios::trunc);

	if (f.is_open()) {
		f << outtext;
		f.close();
	}

	delete pdocument;
}

int wmain(int argc, wchar_t* argv[])
{
    WCHAR szOrgPath[_MAX_PATH] = { 0, };
    WCHAR szDesPath[_MAX_PATH] = { 0, };

    if (argc == 1) {
        return -1;
    } else {

        wcscpy_s(szOrgPath, _MAX_PATH, argv[1]);
        wcscpy_s(szDesPath, _MAX_PATH, argv[2]);

        //InputPath의 확장자 확인
        if (_wcsicmp(PathFindExtensionW(szOrgPath), L".hwpx") != 0) {
            return -1;
        }

        //InputPath의 파일 존재 여부 확인
        if (PathFileExistsW(szOrgPath) == FALSE) {
            return -1;
        }

        HwpxToText(szOrgPath, szDesPath);

        return 1;
    }
}