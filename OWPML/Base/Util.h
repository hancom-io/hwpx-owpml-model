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

#ifndef _OWPML_UTIL_H_
#define _OWPML_UTIL_H_
#pragma once

#include "Type.h"

namespace OWPML {

    namespace Util {
        class CXMLAttConverter
        {
        public:
            // get
            static int ToInt(const OWPML::CAttribute* patt, LPCWSTR name);
            static bool ToBool(const OWPML::CAttribute* patt, LPCWSTR name);
            static float ToFloat(const OWPML::CAttribute* patt, LPCWSTR name);
            static double ToDouble(const OWPML::CAttribute* patt, LPCWSTR name);

            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, unsigned int& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, int& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, double& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, bool& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, float& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, long& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, long long& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, short& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, unsigned short& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, char& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, unsigned char& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, CColorRef& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, hncstd::wstring& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, SYSTEMTIME& dtime);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int& value);
            static bool GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int& value, unsigned int defaultvalue);

            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned int& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, int& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, double& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, bool& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, float& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, long& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned long& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, long long& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, short& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned short& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, char& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned char& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, hncstd::wstring& value);
            static bool GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int& value);

            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const unsigned int& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const int& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const double& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const bool& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const float& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const long& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const long long& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const short& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const unsigned short& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const char& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const unsigned char& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const CColorRef& value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, hncstd::wstring& value, bool bempty = false);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, LPCWSTR value, bool bempty = false);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, SYSTEMTIME& dtime);

            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const unsigned int* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const int* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const double* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const bool* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const float* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const long* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const long long* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const short* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const char* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const unsigned char* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, hncstd::wstring* pvalue);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, SYSTEMTIME* dtime);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int value);
            static void SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int value, unsigned int defaultvalue);

            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned int& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const int& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const double& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const bool& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const float& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned long& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long long& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const short& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned short& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const char& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned char& value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, LPCWSTR value);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, hncstd::wstring& value);

            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned int* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const int* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const double* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const bool* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const float* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned long* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long long* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const short* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const char* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned char* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, hncstd::wstring* pvalue);
            static void SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int value);

        public:
            static unsigned long ConvStrToRGB(const hncstd::wstring& hexStr3bytes);            // COLORREF 의 byte order를 따름.. 주의!
            static unsigned long ConvStrToARGB(const hncstd::wstring& hexStr4bytes);        // GDI+::ARGB 의 byte order를 따름.. 주의!
            static unsigned short ConvStrToUShort(const hncstd::wstring& hexStr2bytes);
            static long long ConvStrToCellRef(LPCWSTR strCellRef);
            static long long ConvStrToCellSpans(LPCWSTR strCellSpans);

            static void ConvRGBToStr(const unsigned long rgb, hncstd::wstring& hexStr3bytes);
            static void ConvARGBToStr(const unsigned long argb, hncstd::wstring& hexStr4bytes);
            static void ConvUShortToStr(const unsigned short ushort, hncstd::wstring& hexStr2bytes);
            static void ConvCellRefToStr(const long long cellRef, hncstd::wstring& strCellRef);
            static void ConvCellSpansToStr(const long long cellSpans, hncstd::wstring& strCellSpans);
            static void _trimZeros(LPWSTR valBuf);
            static void ConvertInvalidStr(LPCWSTR orgStr, hncstd::wstring& replacedStr, const bool isPara, const bool isValue);
            static void _Val2SymbolOfSignsStr(LPCWSTR org, hncstd::wstring& symbol_of_signs, const bool isPara = false);
            static void _Att2SymbolOfSignsStr(LPCWSTR org, hncstd::wstring& symbol_of_signs, const bool isPara = false);
            static void _AttRelTarget2SymbolOfSignsStr(LPCWSTR org, hncstd::wstring& symbol_of_signs);
            static void _SymbolOfSigns2AttRelTargetStr(LPCWSTR org, hncstd::wstring& modifiedStrs);
            static void ConvertFromEscString(/*[in]*/const hncstd::wstring& escString, /*[out]*/hncstd::wstring& stdString);
            static void ConvertToEscStringAttr(/*[in]*/const hncstd::wstring& stdString, /*[out]*/hncstd::wstring& escString);
            static void ConvertToEscStringValue(/*[in]*/const hncstd::wstring& stdString, /*[out]*/hncstd::wstring& escString);
            static bool ConvStrToBool(LPCWSTR strvalue);


            static int _uatoi_enUS(wchar_t const* _String);
            static long _uatol_enUS(wchar_t const* _String);
            static double _uatof_enUS(wchar_t const* _String);
            static int _ustricmp_enUS(wchar_t const* _String1, wchar_t const* _String2);
            static unsigned long  _ustrtoul_enUS(wchar_t const* _String, wchar_t** _EndPtr, int _Radix);
            static void _ReplaceStringAll(hncstd::wstring& subject, LPCWSTR search, LPCWSTR replace);

        private:
            static _locale_t enUSlocale;
        };


        class CFileUtil
        {
        public:
            // path는 directory아니면 file이름이 될수도 있으므로 \ 붙은 곳까지의 directory를 만든다.
            static BOOL CreateFullDirectory(LPCWSTR path);

            static BOOL ExistDir(LPCWSTR dirname);
        private:
            static void _AppendBackSlash(LPWSTR path);
        };
    }
}
#endif //_OWPML_UTIL_H_