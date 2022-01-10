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
#include "Attribute.h"
#include "Class/enumdef.h"
#include "Util.h"


using namespace OWPML::Util;
using namespace OWPML;

_locale_t CXMLAttConverter::enUSlocale = _create_locale(LC_ALL, "en-US");

int CXMLAttConverter::_uatoi_enUS(wchar_t const* _String)
{
    return _wtoi_l(_String, enUSlocale);
}

long CXMLAttConverter::_uatol_enUS(wchar_t const* _String)
{
    return _wtol_l(_String, enUSlocale);
}

double CXMLAttConverter::_uatof_enUS(wchar_t const* _String)
{

    return _wtof_l(_String, enUSlocale);
}

int CXMLAttConverter::_ustricmp_enUS(wchar_t const* _String1, wchar_t const* _String2)
{
    return _wcsicmp_l(_String1, _String2, enUSlocale);
}

unsigned long  CXMLAttConverter::_ustrtoul_enUS(wchar_t const* _String, wchar_t** _EndPtr, int _Radix)
{
    return _wcstoul_l(_String, _EndPtr, _Radix, enUSlocale);
}

int CXMLAttConverter::ToInt(const CAttribute* patt, LPCWSTR name)
{
    LPCWSTR strvalue = patt->getValue(name);

    if (strvalue)
        return _uatoi_enUS(strvalue);
    else
        return 0;
}

bool CXMLAttConverter::ToBool(const CAttribute* patt, LPCWSTR name)
{
    LPCWSTR strvalue = patt->getValue(name);

    if (strvalue) {
        if (_ustricmp_enUS(strvalue, L"true") == 0) {
            return true;
        } else if (_ustricmp_enUS(strvalue, L"1") == 0) {
            return true;
        }
    }

    return false;
}

float CXMLAttConverter::ToFloat(const CAttribute* patt, LPCWSTR name)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue)
        return static_cast<float>(_uatof_enUS(strvalue));
    else
        return 0.0;
}

double CXMLAttConverter::ToDouble(const CAttribute* patt, LPCWSTR name)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue)
        return _uatof_enUS(strvalue);
    else
        return 0.0;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, unsigned int& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        if (strvalue[0] != L'-') {
            LPWSTR end = const_cast<LPWSTR>(strvalue + _ustrlen(strvalue));
            value = static_cast<unsigned int>(_ustrtoul_enUS(strvalue, &end, 10));
            return true;
        }
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, int& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = _uatoi_enUS(strvalue);
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, double& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = static_cast<double>(_uatof_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, bool& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = false;
        if (_ustricmp_enUS(strvalue, L"1") == 0) {
            value = true;
        } else if (_ustricmp_enUS(strvalue, L"true") == 0) {
            value = true;
        }

        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, float& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = static_cast<float>(_uatof_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, long& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = static_cast<long>(_uatol_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, long long& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = static_cast<long long>(_uatof_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, short& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = static_cast<short>(_uatoi_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, unsigned short& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        LPWSTR end = const_cast<LPWSTR>(strvalue + _ustrlen(strvalue));
        value = static_cast<unsigned short>(_ustrtoul_enUS(strvalue, &end, 10));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, char& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = static_cast<char>(_uatoi_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, unsigned char& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        LPWSTR end = const_cast<LPWSTR>(strvalue + _ustrlen(strvalue));
        value = static_cast<unsigned char>(_ustrtoul_enUS(strvalue, &end, 10));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, CColorRef& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        if (_ustricmp_enUS(strvalue, L"none") == 0) {
            value.SetRgb(0xFFFFFFFF);
        } else {
            LPWSTR end = const_cast<LPWSTR>(&strvalue[1] + _ustrlen(strvalue));
            value.SetRgb(static_cast<DWORD>(_ustrtoul_enUS(&strvalue[1], &end, 16)));
        }
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, hncstd::wstring& value)
{
    LPCWSTR strvalue = patt->getValue(name);
    if (strvalue) {
        value = strvalue;
        return true;
    }

    return false;
}

bool CXMLAttConverter::GetAttribute(const CAttribute* patt, LPCWSTR name, SYSTEMTIME& dtime)
{
    LPCWSTR strvalue = patt->getValue(name);

    if (strvalue) {
        _usscanf_s(strvalue, L"%04hu-%02hu-%02huT%02hu:%02hu:%02hu.%03hu", &dtime.wYear, &dtime.wMonth, &dtime.wDay,
            &dtime.wHour, &dtime.wMinute, &dtime.wSecond, &dtime.wMilliseconds);
        return true;
    }

    return false;
}

bool CXMLAttConverter::GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, const ENUMLIST* plist, unsigned int& value)
{
    LPCWSTR strvalue = patt->getValue(name);

    if (strvalue) {
        for (int i = 0; plist[i].token; ++i) {
            if (_ustrcmp(plist[i].token, strvalue) == 0) {
                value = plist[i].id;
                return true;
            }
        }
    }

    return false;
}

bool CXMLAttConverter::GetAttribute(const OWPML::CAttribute* patt, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int& value, unsigned int defaultvalue)
{
    if (GetAttribute(patt, name, plist, value) == false) {
        value = defaultvalue;
    }

    return true;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned int& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        LPWSTR end = const_cast<LPWSTR>(strvalue + _ustrlen(strvalue));
        value = static_cast<unsigned int>(_ustrtoul_enUS(strvalue, &end, 10));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, int& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = _uatoi_enUS(strvalue);
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, double& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<double>(_uatof_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, bool& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = false;

        if (_ustricmp_enUS(strvalue, L"1") == 0) {
            value = true;
        } else if (_ustricmp_enUS(strvalue, L"true") == 0) {
            value = true;
        }

        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, float& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<float>(_uatof_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, long& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<long>(_uatol_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned long& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<unsigned long>(_uatol_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, long long& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<long long>(_uatof_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, short& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<short>(_uatoi_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned short& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        LPWSTR end = const_cast<LPWSTR>(strvalue + _ustrlen(strvalue));
        value = static_cast<unsigned short>(_ustrtoul_enUS(strvalue, &end, 10));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, char& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = static_cast<char>(_uatoi_enUS(strvalue));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, unsigned char& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        LPWSTR end = const_cast<LPWSTR>(strvalue + _ustrlen(strvalue));
        value = static_cast<unsigned char>(_ustrtoul_enUS(strvalue, &end, 10));
        return true;
    }
    return false;
}

bool CXMLAttConverter::GetAttributeNS(const CAttribute* patt, LPCWSTR ns, LPCWSTR name, hncstd::wstring& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);
    if (strvalue) {
        value = strvalue;
        return true;
    }

    return false;
}

bool CXMLAttConverter::GetAttributeNS(const OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const ENUMLIST* plist, unsigned int& value)
{
    LPCWSTR strvalue = patt->getValue(ns, name);

    if (strvalue) {
        for (int i = 0; plist[i].token; ++i) {
            if (_ustrcmp(plist[i].token, strvalue) == 0) {
                value = plist[i].id;
                return true;
            }
        }
    }

    return false;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
// Set 함수들
/////////////////////////////////////////////////////////////////////////////////////////////////
void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const unsigned int& value)
{
    WCHAR buffer[128] = { 0, };

    _uultoa_s(value, buffer, 128, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const int& value)
{
    WCHAR buffer[128] = { 0, };

    _uitoa_s(value, buffer, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const double& value)
{
    WCHAR buffer[128] = { 0, };

    if (value == 0.0f) {
        _ustrcpy_s(buffer, L"0");        // 0일 경우 그냥 '0'을 serialize
    } else {
        _usprintf_s(buffer, 128, L"%.20f", value);
        _trimZeros(buffer);
    }

    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const bool& value)
{
    if (value)
        patt->setValue(name, L"1");
    else
        patt->setValue(name, L"0");
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const float& value)
{
    WCHAR buffer[128] = { 0, };

    if (value == 0.0f) {
        _ustrcpy_s(buffer, L"0");        // 0일 경우 그냥 '0'을 serialize
    } else {
        _usprintf_s(buffer, 128, L"%f", value);
        _trimZeros(buffer);
    }

    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const long& value)
{
    WCHAR buffer[128] = { 0, };

    _ultoa_s(value, buffer, 128, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const long long& value)
{
    WCHAR buffer[128] = { 0, };

    _usprintf_s(buffer, 128, L"%.0f", static_cast<double>(value));
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const short& value)
{
    WCHAR buffer[128] = { 0, };

    _uitoa_s((int)value, buffer, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const unsigned short& value)
{
    WCHAR buffer[128] = { 0, };

    _uultoa_s((unsigned long)value, buffer, 128, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const char& value)
{
    WCHAR buffer[128] = { 0, };

    _uitoa_s((int)value, buffer, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const unsigned char& value)
{
    WCHAR buffer[128] = { 0, };

    _uultoa_s((unsigned long)value, buffer, 128, 10);
    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const CColorRef& value)
{
    WCHAR buffer[128] = { 0, };

    if ((COLORREF)value == 0xFFFFFFFF) {
        _ustrcpy_s(buffer, L"none");
    } else {
        CColorRef regvalue(value);

        _usprintf_s(buffer, 128, L"#%06X", regvalue.GetRgb());
    }

    patt->setValue(name, buffer);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, hncstd::wstring& value, bool bempty)
{
    //  attribute에 들어가는 금지문자를 Symbol of Signs로 변경
    hncstd::wstring modifiedValue;
    Util::CXMLAttConverter::_Att2SymbolOfSignsStr(value.c_str(), modifiedValue);

    if (!name)
        return;

    if (!modifiedValue.length() && bempty) {
        patt->setValue(name, L"");
    } else {
        patt->setValue(name, modifiedValue.c_str());
    }
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, LPCWSTR value, bool bempty)
{
    if (!name)
        return;

    if (value && _ustrlen(value)) {
        patt->setValue(name, value);
    } else if (bempty) {
        patt->setValue(name, L"");
    }
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, SYSTEMTIME& dtime)
{
    hncstd::wstring value;
    WCHAR buf[_MAX_PATH] = { 0, };
    _usprintf_s(buf, _MAX_PATH, L"%04u-%02u-%02uT%02u:%02u:%02u.%03u", dtime.wYear, dtime.wMonth, dtime.wDay, dtime.wHour,
        dtime.wMinute, dtime.wSecond, dtime.wMilliseconds);
    value = buf;
    patt->setValue(name, value.c_str());
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const unsigned int* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const int* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const double* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const bool* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const float* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const long* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const long long* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const short* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const char* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, const unsigned char* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, hncstd::wstring* pvalue)
{
    if (pvalue)
        SetAttribute(patt, name, *pvalue);
}

void CXMLAttConverter::SetAttribute(CAttribute* patt, LPCWSTR name, SYSTEMTIME* dtime)
{
    if (dtime) {
        hncstd::wstring value;
        WCHAR buf[_MAX_PATH] = { 0, };
        _usprintf_s(buf, _MAX_PATH, L"%04u-%02u-%02uT%02u:%02u:%02u.%03u", dtime->wYear, dtime->wMonth, dtime->wDay, dtime->wHour,
            dtime->wMinute, dtime->wSecond, dtime->wMilliseconds);
        value = buf;
        SetAttribute(patt, name, value);
    }
}

void CXMLAttConverter::SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const ENUMLIST* plist, unsigned int value)
{
    if (plist == NULL)
        return;

    for (int i = 0; plist[i].token; ++i) {
        if (plist[i].id == value) {
            SetAttribute(patt, name, plist[i].token);
            return;
        }
    }
}

void CXMLAttConverter::SetAttribute(OWPML::CAttribute* patt, LPCWSTR name, const OWPML::ENUMLIST* plist, unsigned int value, unsigned int defaultvalue)
{
    if (plist == NULL)
        return;

    int defaultindex = 0;

    for (int i = 0; plist[i].token; ++i) {
        if (plist[i].id == value) {
            SetAttribute(patt, name, plist[i].token);
            return;
        }

        if (plist[i].id == defaultvalue) {
            defaultindex = i;
        }
    }

    // 값을 못찾으면 defaultvalue;
    SetAttribute(patt, name, plist[defaultindex].token);
}


void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned int& value)
{
    WCHAR buffer[128] = { 0, };

    _uultoa_s(value, buffer, 128, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const int& value)
{
    WCHAR buffer[128] = { 0, };

    _uitoa_s(value, buffer, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const double& value)
{
    WCHAR buffer[128] = { 0, };

    _usprintf_s(buffer, 128, L"%f", value);
    _trimZeros(buffer);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const bool& value)
{
    if (value)
        patt->setValue(ns, name, L"1");
    else
        patt->setValue(ns, name, L"0");
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const float& value)
{
    WCHAR buffer[128] = { 0, };

    _usprintf_s(buffer, 128, L"%f", value);
    _trimZeros(buffer);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long& value)
{
    WCHAR buffer[128] = { 0, };

    _ltow_s(value, buffer, 128, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned long& value)
{
    WCHAR buffer[128] = { 0, };

    _ultow_s(value, buffer, 128, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long long& value)
{
    WCHAR buffer[128] = { 0, };

    _usprintf_s(buffer, 128, L"%.0f", static_cast<double>(value));
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const short& value)
{
    WCHAR buffer[128] = { 0, };

    _uitoa_s((int)value, buffer, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned short& value)
{
    WCHAR buffer[128] = { 0, };

    _uultoa_s((unsigned long)value, buffer, 128, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const char& value)
{
    WCHAR buffer[128] = { 0, };

    _uitoa_s((int)value, buffer, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned char& value)
{
    WCHAR buffer[128] = { 0, };

    _uultoa_s((unsigned long)value, buffer, 128, 10);
    patt->setValue(ns, name, buffer);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, hncstd::wstring& value)
{
    //  attribute에 들어가는 금지문자를 Symbol of Signs로 변경
    hncstd::wstring modifiedValue;
    Util::CXMLAttConverter::_Att2SymbolOfSignsStr(value.c_str(), modifiedValue);

    patt->setValue(ns, name, modifiedValue.c_str());
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, LPCWSTR value)
{
    patt->setValue(ns, name, value);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned int* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const int* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const double* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const bool* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const float* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned long* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const long long* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const short* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const char* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, const unsigned char* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(CAttribute* patt, LPCWSTR ns, LPCWSTR name, hncstd::wstring* pvalue)
{
    if (pvalue != NULL)
        SetAttributeNS(patt, ns, name, *pvalue);
}

void CXMLAttConverter::SetAttributeNS(OWPML::CAttribute* patt, LPCWSTR ns, LPCWSTR name, const ENUMLIST* plist, unsigned int value)
{
    if (plist == NULL)
        return;

    for (int i = 0; plist[i].token; ++i) {
        if (plist[i].id == value) {
            SetAttributeNS(patt, ns, name, plist[i].token);
            return;
        }
    }
}



//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

// 1byte 범위의 hex stgring value를 decimal long value로 반환
static unsigned long _HexStrToDecVal(hncstd::wstring& hexStr)
{
    unsigned long tmpVal = 0;
    if (!hexStr.empty()) {
        LPWSTR pTmpEnd = NULL;
        tmpVal = _ustrtoul(hexStr.c_str(), &pTmpEnd, 16/*hex 변환*/);
    }

    return tmpVal;
}

unsigned long CXMLAttConverter::ConvStrToRGB(const hncstd::wstring& hexStr3bytes)
{
    unsigned long rgbVal = 0;
    if (!hexStr3bytes.empty()) {
        hncstd::wstring tmpHexStr;

        // R
        tmpHexStr.assign(hexStr3bytes.c_str(), 2);
        unsigned long R = _HexStrToDecVal(tmpHexStr);

        // G
        tmpHexStr.assign(hexStr3bytes.c_str() + 2, 2);
        unsigned long G = _HexStrToDecVal(tmpHexStr);

        // B
        tmpHexStr.assign(hexStr3bytes.c_str() + 4, 2);
        unsigned long B = _HexStrToDecVal(tmpHexStr);

        // COLORREF의 byte order를 따르므로 사용시 주의할 것..
        rgbVal = static_cast<unsigned long>(RGB(R, G, B));
    }

    return rgbVal;
}

unsigned long CXMLAttConverter::ConvStrToARGB(const hncstd::wstring& hexStr4bytes)
{
    unsigned long argbVal = 0;
    if (!hexStr4bytes.empty()) {
        hncstd::wstring tmpHexStr;

        // A
        tmpHexStr.assign(hexStr4bytes.c_str(), 2);
        BYTE a = _HexStrToDecVal(tmpHexStr) & 0xff;

        // R
        tmpHexStr.assign(hexStr4bytes.c_str() + 2, 2);
        BYTE r = _HexStrToDecVal(tmpHexStr) & 0xff;

        // G
        tmpHexStr.assign(hexStr4bytes.c_str() + 4, 2);
        BYTE g = _HexStrToDecVal(tmpHexStr) & 0xff;

        // B
        tmpHexStr.assign(hexStr4bytes.c_str() + 6, 2);
        BYTE b = _HexStrToDecVal(tmpHexStr) & 0xff;

        // GDI+::ARGB 의 byte order를 따르므로 사용시 주의할 것..
        argbVal = static_cast<unsigned long>((a << 24) | (r << 16) | (g << 8) | b);
    }

    return argbVal;
}

unsigned short CXMLAttConverter::ConvStrToUShort(const hncstd::wstring& hexStr2bytes)
{
    unsigned short ushortVal = 0;
    if (!hexStr2bytes.empty()) {
        hncstd::wstring tmpHexStr;

        // up
        tmpHexStr.assign(hexStr2bytes, 2);
        BYTE up = _HexStrToDecVal(tmpHexStr) & 0xff;

        // down
        tmpHexStr.assign(hexStr2bytes.c_str() + 2, 2);
        BYTE down = _HexStrToDecVal(tmpHexStr) & 0xff;

        ushortVal = static_cast<unsigned short>((up << 8) | down);
    }

    return ushortVal;
}

long long CXMLAttConverter::ConvStrToCellRef(LPCWSTR strCellRef)
{
    const unsigned short charA = L'A';
    const unsigned short charZ = L'Z';
    const unsigned short chara = L'a';
    const unsigned short charz = L'z';
    const unsigned short charZero = L'0';
    const unsigned short charNine = L'9';
    const unsigned int decimal = 10; // 0 ... 9 10진수
    const unsigned int alpa = 26; // A ....  Z  26진수


    long long cellrefVal = 0;
    int index, len;
    WCHAR ch;

    if (strCellRef == NULL)
        return cellrefVal;

    len = _ustrlen(strCellRef);
    if (len <= 0)
        return cellrefVal;

    // Col
    unsigned int nCol = 0;
    for (index = 0; index < len; ++index) {
        ch = strCellRef[index];
        if ((ch >= charA) && (ch <= charZ)) {
            nCol *= alpa;
            nCol += (ch - charA + 1);
        } else if ((ch >= chara) && (ch <= charz)) {
            nCol *= alpa;
            nCol += (ch - chara + 1);
        } else {
            break;
        }
    }
    --nCol;

    // row
    unsigned int nRow = 0;

    for (; index < len; ++index) {
        ch = strCellRef[index];
        if ((ch >= charZero) && (ch <= charNine)) {
            nRow *= decimal;
            nRow += (ch - charZero);
        } else {
            break;
        }
    }

    --nRow;

    cellrefVal = ((static_cast<long long>(nRow)) << 32) | nCol;

    return cellrefVal;
}

long long CXMLAttConverter::ConvStrToCellSpans(LPCWSTR strCellSpans)
{
    LPWSTR pEndPtr = NULL;
    LPCWSTR pContext = NULL;
    if (_ustrchr(strCellSpans, L':') == NULL)
        return 0;

    pContext = strCellSpans;

    // startCellSpan
    unsigned long startCellSpan = 0;
    if (pContext) {
        startCellSpan = _ustrtoul(pContext, &pEndPtr, 10) - 1;
        pContext = pEndPtr + 1;
    }

    // endCellSpan
    unsigned long endCellSpan = 0;
    if (pContext) {
        endCellSpan = _ustrtoul(pContext, &pEndPtr, 10) - 1;
    }

    long long cellSpansVal = (static_cast<long long>(startCellSpan) << 32) | endCellSpan;
    return cellSpansVal;
}

static void _HexDecValToStr(unsigned long decval, hncstd::wstring& hexStr)
{
    WCHAR tmpBuf[3/*무조건 1byte만 변환*/] = { 0, };
    _ultow_s(decval, tmpBuf, 16/*hex 변환*/);
    if (_ustrlen(tmpBuf) == 2) {
        hexStr.assign(tmpBuf);
    } else {
        hexStr.assign(L"0");
        hexStr.append(tmpBuf);
    }
}

void CXMLAttConverter::ConvRGBToStr(const unsigned long rgb, hncstd::wstring& hexStr3bytes)
{
    hncstd::wstring tmpHexStr;
    unsigned long tmpVal = 0;

    // R
    tmpVal = GetRValue(rgb);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr3bytes += tmpHexStr;

    // G
    tmpVal = GetGValue(rgb);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr3bytes += tmpHexStr;

    // B
    tmpVal = GetBValue(rgb);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr3bytes += tmpHexStr;
}

void CXMLAttConverter::ConvARGBToStr(const unsigned long argb, hncstd::wstring& hexStr4bytes)
{
    hncstd::wstring tmpHexStr;
    unsigned long tmpVal = 0;

    // A
    tmpVal = static_cast<unsigned long>((argb >> 24) & 0xff);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr4bytes += tmpHexStr;

    // R
    tmpVal = static_cast<unsigned long>((argb >> 16) & 0xff);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr4bytes += tmpHexStr;

    // G
    tmpVal = static_cast<unsigned long>((argb >> 8) & 0xff);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr4bytes += tmpHexStr;

    // B
    tmpVal = static_cast<unsigned long>(argb & 0xff);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr4bytes += tmpHexStr;
}

void CXMLAttConverter::ConvUShortToStr(const unsigned short ushort, hncstd::wstring& hexStr2bytes)
{
    hncstd::wstring tmpHexStr;
    unsigned long tmpVal = 0;

    // up
    tmpVal = static_cast<unsigned long>((ushort >> 8) & 0xff);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr2bytes += tmpHexStr;

    // down
    tmpVal = static_cast<unsigned long>(ushort & 0xff);
    _HexDecValToStr(tmpVal, tmpHexStr);
    hexStr2bytes += tmpHexStr;
}

void CXMLAttConverter::ConvCellRefToStr(const long long cellRef, hncstd::wstring& strCellRef)
{
    const unsigned short charA = L'A';
    const unsigned short char0 = L'0';
    const unsigned short _MAX_RC_NAME_LEN = 16;
    WCHAR tmpBuf[_MAX_RC_NAME_LEN] = { 0, };
    LPWSTR pBuf = NULL;

    // 1) Col
    unsigned long nCol = static_cast<unsigned long>((cellRef) & 0xFFFFFFFF);

    pBuf = tmpBuf;
    pBuf += (_MAX_RC_NAME_LEN - 1);

    *pBuf = L'\0';
    *--pBuf = charA + (nCol % 26);
    while (nCol /= 26)
        *--pBuf = charA + (--nCol % 26);

    strCellRef.assign(pBuf);

    // 2) Row
    unsigned long nRow = static_cast<unsigned long>(((cellRef) >> 32) & 0xFFFFFFFF) + 1;

    pBuf = tmpBuf;
    pBuf += (_MAX_RC_NAME_LEN - 1);

    *pBuf = L'\0';
    *--pBuf = char0 + nRow % 10;

    while (nRow /= 10)
        *--pBuf = char0 + (nRow % 10);

    strCellRef.append(pBuf);
}

void CXMLAttConverter::ConvCellSpansToStr(const long long cellSpans, hncstd::wstring& strCellSpans)
{
    WCHAR tmpBuf[10] = { 0, };

    // startCellSpan
    unsigned long startCellSpan = static_cast<unsigned long>(((cellSpans) >> 32) & 0xFFFFFFFF);
    _ultow_s(startCellSpan + 1, tmpBuf, 10/*decimal 변환*/);
    strCellSpans += tmpBuf;

    strCellSpans += L":";
    *tmpBuf = L'\0';

    // endCellSpan
    unsigned long endCellSpan = static_cast<unsigned long>((cellSpans) & 0xFFFFFFFF);
    _ultow_s(endCellSpan + 1, tmpBuf, 10/*decimal 변환*/);
    strCellSpans += tmpBuf;
}

// double(float)값을 serialize하면서 소수점 이하의 의미없는 0의 나열이 있을 경우 삭제하여 파일사이즈를 줄인다.
// 예>
//    0.0010000    ==>    0.001
//    25.253400    ==>    25.2534
//    11.00000    ==>    11
void CXMLAttConverter::_trimZeros(LPWSTR valBuf)
{
    if (valBuf) {
        size_t valLen = _ustrlen(valBuf);
        LPWSTR pLastChar = valBuf + valLen - 1;
        while (pLastChar >= valBuf) {
            if (*pLastChar == L'0') {
                *pLastChar = L'\0';
            } else if (*pLastChar == L'.' && (*(pLastChar + 1) == L'\0')) {
                *pLastChar = L'\0';
                break;
            } else {
                break;
            }

            --pLastChar;
        }
    }
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
// "Symbol Of Signs"
//
struct _XML_Symbols_of_Signs_Pair
{
    LPCWSTR orgStr;
    LPCWSTR symbol_of_signs;
};

// XML Entity(Value)에서 쓰이지 않는 문자열에 대한 변환테이블
static _XML_Symbols_of_Signs_Pair s_valSymbolsOfSignsTbl[] = {
    { L"&",            L"&amp;"    /* L"&#38;" */ },                    // ampersand 문자는 무조건 가장 먼저 변환하여야 한다.
    { L">",            L"&gt;"        /* L"&#62;" */ },
    { L"<",            L"&lt;"        /* L"&#60;" */ },

    { NULL, NULL }
};

// XML Attribite에서 쓰이지 않는 문자열에 대한 변환테이블
static _XML_Symbols_of_Signs_Pair s_attSymbolsOfSignsTbl[] = {
    { L"&",            L"&amp;"    /* L"&#38;" */ },                    // ampersand 문자는 무조건 가장 먼저 변환하여야 한다.
    { L">",            L"&gt;"        /* L"&#62;" */ },
    { L"<",            L"&lt;"        /* L"&#60;" */ },
    { L"\"",        L"&quot;"    /* L"&#34;" */ },
    //    { L"`",            L"&apos;"    /* L"&#39;" */ },

        { NULL, NULL }
};

// XML Relationship Target Attribite에서 쓰이지 않는 문자열에 대한 변환테이블
static _XML_Symbols_of_Signs_Pair s_attRelTargetSymbolsOfSignsTbl[] = {
    { L"&",            L"&amp;"    /* L"&#38;" */ },                    // ampersand 문자는 무조건 가장 먼저 변환하여야 한다.
    { L" ",            L"%20" },
    { L"\n",           L"%10" },
    { L"\"",           L"%22" },
    { L"[",            L"%5b" },
    { L"]",            L"%5d" },

    { NULL, NULL }
};

void CXMLAttConverter::ConvertInvalidStr(LPCWSTR orgStr, hncstd::wstring& replacedStr, const bool isPara, const bool isValue)
{
    size_t len = _ustrlen(orgStr);
    size_t i = 0;

    replacedStr.reserve(len);

    for (i = 0; i < len; ++i) {
        if (isPara) {
            // Surrogate Pair (H:0xD800-0xDBFF, L:0xDC00-0xDFFF)
            if ((orgStr[i] & 0xF800) == 0xD800) {
                if ((orgStr[i] & 0xFC00) == 0xDC00) {
                    // 처음부터 low만 온경우
                    replacedStr.append(L"\x25A1");
                    continue;
                } else {
                    if (i + 1 < len) {
                        if ((orgStr[i + 1] & 0xFC00) == 0xDC00) { // 정상적인 경우
                            replacedStr.append(&orgStr[i], 2);
                            ++i;
                            continue;
                        } else {
                            // high 만 온경우
                            replacedStr.append(L"\x25A1");
                            continue;
                        }
                    } else {
                        // 마지막 CHAR에 HIGH 만 온경우
                        replacedStr.append(L"\x25A1");
                        continue;
                    }
                }
            } else if (orgStr[i] >= 0x01 && orgStr[i] < 0x20) {
                continue;
            }
        }

        // XML에서 쓰이지 않는 문자열 변환
        if ((orgStr[i] >= 0x01 && orgStr[i] <= 0x08)
            || (orgStr[i] >= 0x0B && orgStr[i] <= 0x0C)
            || (orgStr[i] >= 0x0E && orgStr[i] <= 0x1F)
            || orgStr[i] == 0xFFFE || orgStr[i] == 0xFFFF) {
            replacedStr.append(L" ");
            continue;
        } else if (orgStr[i] == L'&') { // ampersand 문자는 무조건 가장 먼저 변환하여야 한다.
            replacedStr.append(L"&amp;");
            continue;
        } else if (orgStr[i] == L'>') {
            replacedStr.append(L"&gt;");
            continue;
        } else if (orgStr[i] == L'<') {
            ;
            replacedStr.append(L"&lt;");
            continue;
        }

        if (isValue == false) {
            // XML Attribute에서 쓰이지 않는 문자열 변환
            if (orgStr[i] == L'\"') {
                replacedStr.append(L"&quot;");
                continue;
            }
        }

        replacedStr.append(&orgStr[i], 1);
    }

    return;
}

void CXMLAttConverter::_Val2SymbolOfSignsStr(LPCWSTR org, hncstd::wstring& symbol_of_signs, const bool isPara)
{
    ConvertInvalidStr(org, symbol_of_signs, isPara, true);
}

void CXMLAttConverter::_Att2SymbolOfSignsStr(LPCWSTR org, hncstd::wstring& symbol_of_signs, const bool isPara)
{
    ConvertInvalidStr(org, symbol_of_signs, isPara, false);
}

void CXMLAttConverter::_ReplaceStringAll(hncstd::wstring& subject, LPCWSTR search, LPCWSTR replace)
{
    size_t pos = 0;

    while ((pos = subject.find(search, pos)) != hncstd::wstring::npos) {
        subject.replace(pos, _ustrlen(search), replace);
        pos += _ustrlen(replace);
    }
}

void CXMLAttConverter::_AttRelTarget2SymbolOfSignsStr(LPCWSTR org, hncstd::wstring& symbol_of_signs)
{
    LPCWSTR pCurEscape = _ustrstr(org, L"%");
    if (pCurEscape) {
        symbol_of_signs.clear();
        LPCWSTR curStr = org;
        LPCWSTR endStr = org + _ustrlen(org);
        while (pCurEscape) {
            if (((pCurEscape + 2) < endStr) && _uisxdigit(*(pCurEscape + 1)) && _uisxdigit(*(pCurEscape + 2))) {
                // 이미 URL encoding 되어있음
                symbol_of_signs.append(curStr, (pCurEscape + 3) - curStr);
                curStr = pCurEscape + 3;
            } else {
                // URL encoding과 무관한 '%'문자가 나왔으므로 '%25'로 변환
                symbol_of_signs.append(curStr, (pCurEscape - curStr));
                symbol_of_signs.append(L"%25");
                curStr = pCurEscape + 1;
            }

            pCurEscape = _ustrstr(curStr, L"%");
        }

        symbol_of_signs.append(curStr, (endStr - curStr));
    } else {
        symbol_of_signs = org;
    }

    _XML_Symbols_of_Signs_Pair* pCurPair = &(s_attRelTargetSymbolsOfSignsTbl[0]);
    while (pCurPair->orgStr) {
        _ReplaceStringAll(symbol_of_signs, pCurPair->orgStr, pCurPair->symbol_of_signs);
        ++pCurPair;
    }
}

void CXMLAttConverter::_SymbolOfSigns2AttRelTargetStr(LPCWSTR org, hncstd::wstring& modifiedStrs)
{
    modifiedStrs = org;

    _XML_Symbols_of_Signs_Pair* pCurPair = &(s_attRelTargetSymbolsOfSignsTbl[0]);
    while (pCurPair->orgStr) {
        _ReplaceStringAll(modifiedStrs, pCurPair->symbol_of_signs, pCurPair->orgStr);
        ++pCurPair;
    }
}

static UINT _hexStr2Uint(LPCWSTR hexStr, UINT lenHexStr)
{
    UINT rtnVal = 0;
    UINT tmpVal = 0;

    LPCWSTR pCurChar = hexStr;
    while (*pCurChar) {
        if ((*pCurChar >= L'0') && (*pCurChar <= L'9')) {
            tmpVal = *pCurChar - L'0';
        } else if ((_utolower(*pCurChar) >= L'a') && (_utolower(*pCurChar) <= L'f')) {
            tmpVal = _utolower(*pCurChar) - L'a' + 10;
        } else {
            _ASSERT(FALSE);
            break;
        }

        rtnVal += (tmpVal * static_cast<UINT>(std::pow(static_cast<long double>(16), static_cast<int>(lenHexStr - (pCurChar - hexStr) - 1))));
        ++pCurChar;
    }

    return rtnVal;
}

void CXMLAttConverter::ConvertFromEscString(/*[in]*/const hncstd::wstring& escString, /*[out]*/hncstd::wstring& stdString)
{
    static const UINT hexBufSize = 4;
    WCHAR hexBuf[hexBufSize + 1];

    LPCWSTR pEndVal = escString.c_str() + escString.length();
    LPCWSTR pCurLastEsc = escString.c_str();
    LPCWSTR pCurEsc = _ustrstr(escString.c_str(), L"_x");
    if (pCurEsc) {
        stdString.assign(L"");
        while (pCurEsc && ((pCurEsc + 6) < pEndVal)) {
            if ((*(pCurEsc + 6) == L'_') && _uisxdigit(*(pCurEsc + 2)) && _uisxdigit(*(pCurEsc + 3)) && _uisxdigit(*(pCurEsc + 4)) && _uisxdigit(*(pCurEsc + 5))) {

                if (pCurEsc != pCurLastEsc)
                    stdString.append(pCurLastEsc, pCurEsc - pCurLastEsc);

                wcsncpy_s(hexBuf, pCurEsc + 2, hexBufSize);

                WCHAR tmpCode[2] = { LOWORD(_hexStr2Uint(hexBuf, hexBufSize)), L'\0' };
                stdString.append(tmpCode);
                pCurEsc += 7;
            } else {
                pCurEsc += 2;
                stdString.append(pCurLastEsc, pCurEsc - pCurLastEsc);
            }

            pCurLastEsc = pCurEsc;
            if (pCurEsc >= pEndVal)
                break;
            pCurEsc = _ustrstr(pCurEsc, L"_x");
        }

        if (pEndVal > pCurLastEsc)
            stdString.append(pCurLastEsc, pEndVal - pCurLastEsc);
    } else {
        stdString = escString;
    }
}

struct _EscCharTbl
{
    WCHAR start;
    WCHAR end;
};

static void _ConvertToEscString(/*[in]*/const hncstd::wstring& stdString, /*[out]*/hncstd::wstring& escString, _EscCharTbl* pEscTbl)
{
    escString.assign(L"");

    // 1) escape 오해여지가 있는 문자에 대한 선처리
    hncstd::wstring buf(L"");
    if (!stdString.empty()) {

        LPCWSTR pEndVal = stdString.c_str() + stdString.length();
        LPCWSTR pCurLastEsc = stdString.c_str();
        LPCWSTR pCurEsc = _ustrstr(stdString.c_str(), L"_x");
        if (pCurEsc) {
            while (pCurEsc && ((pCurEsc + 6) < pEndVal)) {
                if ((*(pCurEsc + 6) == L'_') && _uisxdigit(*(pCurEsc + 2)) && _uisxdigit(*(pCurEsc + 3)) && _uisxdigit(*(pCurEsc + 4)) && _uisxdigit(*(pCurEsc + 5))) {

                    if (pCurEsc != pCurLastEsc)
                        buf.append(pCurLastEsc, pCurEsc - pCurLastEsc);

                    buf.append(L"_x005F_");        // L'_'에 대한 아스키값(0x005f)
                    buf.append(pCurEsc + 1, 6);
                    pCurEsc += 7;
                } else {
                    pCurEsc += 2;
                    buf.append(pCurLastEsc, pCurEsc - pCurLastEsc);
                }

                pCurLastEsc = pCurEsc;
                if (pCurEsc >= pEndVal)
                    break;
                pCurEsc = _ustrstr(pCurEsc, L"_x");
            }

            if (pEndVal > pCurLastEsc)
                buf.append(pCurLastEsc, pEndVal - pCurLastEsc);
        } else {
            buf.assign(stdString);
        }
    }

    // 2) XML 불허 문자에 대한 처리
    if (!buf.empty()) {
        WCHAR tmpCode = L'\0';
        WCHAR tmpBuf[20];

        UINT nIdx = 0;
        UINT nSize = buf.length();
        while (nIdx < nSize) {
            tmpCode = buf.at(nIdx);
            if (!IS_SURROGATEHIGH(tmpCode)) {
                BOOL bAvail = FALSE;
                _EscCharTbl* pCurTblElem = pEscTbl;
                while (pCurTblElem && pCurTblElem->start && pCurTblElem->end) {
                    if ((tmpCode >= pCurTblElem->start) && (tmpCode <= pCurTblElem->end)) {
                        // ① XML 허용 문자
                        escString += tmpCode;
                        bAvail = TRUE;
                        break;
                    }
                    ++pCurTblElem;
                }

                if (!bAvail) {
                    // ② XML 불허 문자
                    _usprintf_s(tmpBuf, 20, L"_x%04X_", tmpCode);
                    escString.append(tmpBuf);
                }
            } else {
                // ③ Surrogate
                escString.append((LPCWSTR)buf.c_str() + nIdx, 2);
                ++nIdx;
            }

            ++nIdx;
        }
    }
}

void CXMLAttConverter::ConvertToEscStringAttr(/*[in]*/const hncstd::wstring& stdString, /*[out]*/hncstd::wstring& escString)
{
    // XML 1.0 스펙(http://www.w3.org/TR/xml/)에서
    // 2.2 Characters 부분을 살펴보면 Character Range를 아래와 같이 정의해 놓았습니다.
    //   [2] Char ::= #x9 | #xA | #xD | [#x20-#xD7FF] | [#xE000-#xFFFD] | [#x10000-#x10FFFF] // any Unicode character, excluding the surrogate blocks, FFFE, and FFFF.
    _EscCharTbl esctbl[] = {
        { 0x0009, 0x0009 },
        { 0x0020, 0xD7FF },
        { 0xE000, 0xFFFD },
        { 0x0000, 0x0000 } };

    _ConvertToEscString(stdString, escString, esctbl);
}

void CXMLAttConverter::ConvertToEscStringValue(/*[in]*/const hncstd::wstring& stdString, /*[out]*/hncstd::wstring& escString)
{
    // XML 1.0 스펙(http://www.w3.org/TR/xml/)에서
    // 2.2 Characters 부분을 살펴보면 Character Range를 아래와 같이 정의해 놓았습니다.
    //   [2] Char ::= #x9 | #xA | #xD | [#x20-#xD7FF] | [#xE000-#xFFFD] | [#x10000-#x10FFFF] // any Unicode character, excluding the surrogate blocks, FFFE, and FFFF.
    _EscCharTbl esctbl[] = {
        { 0x0009, 0x0009 },
        { 0x000A, 0x000A },
        { 0x000D, 0x000D },
        { 0x0020, 0xD7FF },
        { 0xE000, 0xFFFD },
        { 0x0000, 0x0000 },
        NULL };

    _ConvertToEscString(stdString, escString, esctbl);
}

bool CXMLAttConverter::ConvStrToBool(LPCWSTR strvalue)
{
    bool bresult = false;
    if (strvalue) {
        if (_ustrcmp(strvalue, L"1") == 0) {
            bresult = true;
        } else if (_ustricmp_enUS(strvalue, L"true") == 0) {
            bresult = true;
        }
    }

    return bresult;
}

BOOL CFileUtil::ExistDir(LPCWSTR dirname)
{
    DWORD attr;

    attr = GetFileAttributesW(dirname);

    if (attr == 0xFFFFFFFF)
        return FALSE;

    return (attr & FILE_ATTRIBUTE_DIRECTORY);
}


void CFileUtil::_AppendBackSlash(LPWSTR path)
{
    int len = _ustrlen(path);

    if (len && _ustrrchr(path, HNC_DIR_SEPARATOR_W) != (path + len - 1)) {
        path[len] = HNC_DIR_SEPARATOR_W;
        path[len + 1] = L'\0';
    }
}

// path는 directory아니면 file이름이 될수도 있으므로 \ 붙은 곳까지의 directory를 만든다.
BOOL CFileUtil::CreateFullDirectory(LPCWSTR path)
{
    // Directory를 만든다
    WCHAR drive[_MAX_DRIVE] = { 0, };
    WCHAR dir[_MAX_PATH] = { 0, };
    WCHAR newpath[_MAX_PATH] = { 0, };

    _usplitpath_s(path, drive, _MAX_DRIVE, dir, _MAX_PATH, NULL, 0, NULL, 0);
    _umakepath_s(newpath, _MAX_PATH, drive, dir, NULL, NULL);

    if (ExistDir(newpath))
        return TRUE;

    WCHAR temppath[_MAX_PATH] = { 0, };
    WCHAR *pSlash, *pStart;

    _ustrcpy_s(temppath, newpath);
    _AppendBackSlash(temppath);

    if ((pStart = _ustrchr(temppath, HNC_DIR_SEPARATOR_W)) == NULL)
        return FALSE;
    pStart++;

    while ((pSlash = _ustrchr(pStart, HNC_DIR_SEPARATOR_W)) != 0) {

        *pSlash = L'\0';
        if (!ExistDir(temppath) && !CreateDirectory(temppath, NULL))
            return FALSE;

        *pSlash++ = HNC_DIR_SEPARATOR_W;
        if (*pSlash)
            pStart = pSlash;
        else
            break;
    }

    return TRUE;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
