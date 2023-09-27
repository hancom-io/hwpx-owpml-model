#pragma once
#include <Shlwapi.h>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>
#include <windows.h>
#include "OWPMLApi/OWPMLApi.h"
#include "OWPMLUtil/HncDefine.h"
#include "OWPML/OWPML.h"

void PrintText(OWPML::CT* text, std::wstring& outtext);
void GetSectionText(OWPML::COwpmlDocumnet* document, std::wstring& outtext);
void ProcessingTextElement(OWPML::CObject* object, std::wstring& outtext);
void HwpxToText(LPCWSTR srcPath, LPCWSTR targetPath);