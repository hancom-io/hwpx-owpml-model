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
#ifndef HNC_STRING_DEF_H
#define HNC_STRING_DEF_H

#if defined(_MSC_VER)
#define HNCSTD_EXPORT
#else
#define HNCSTD_EXPORT __attribute__((visibility ("default")))
#endif // #if defined(_MSC_VER)
namespace hncstd HNCSTD_EXPORT {

#if defined(_MSC_VER)

    typedef std::wstring          wstring;        // 같은 namespace를 사용하기 위하여
    typedef std::string           string;         // 같은 namespace를 사용하기 위하여
    typedef std::wstringstream    wstringstream;  // 같은 namespace를 사용하기 위하여
    typedef std::wistringstream   wistringstream; // 같은 namespace를 사용하기 위하여
    typedef std::wostringstream   wostringstream; // 같은 namespace를 사용하기 위하여
    typedef std::stringstream     stringstream;   // 같은 namespace를 사용하기 위하여
    typedef std::istringstream    istringstream;  // 같은 namespace를 사용하기 위하여
    typedef std::ostringstream    ostringstream;  // 같은 namespace를 사용하기 위하여
    using std::to_wstring;

#else // #if defined(_MSC_VER)

    using std::mbstate_t;
    using std::streamoff;
    using std::streampos;
    using ::wint_t;       // cwchar
    using std::wstreampos;

    using std::streamoff;
    using std::streampos;
    using std::wstreampos;

    // 여기서 2byte짜리 wchar_t에 대한 처리를 한다. (glibc안쪽은 wchar_t가 4byte)
    struct hnc_char_traits_w {
        typedef wchar_t     char_type;
        typedef wint_t      int_type;
        typedef streamoff   off_type;
        typedef wstreampos  pos_type;
        typedef mbstate_t   state_type;

        static void
            assign(char_type& d, const char_type& s)
        {
            d = s;
        }

        static char_type*
            assign(char_type* dest, size_t n, char_type s)
        {
            for (size_t i = 0; i < n; ++i) {
                dest[i] = s;
            }
            return dest;
        }

        static bool
            eq(const char_type& a, const char_type& b)
        {
            return a == b;
        }

        static bool
            lt(const char_type& a, const char_type& b)
        {
            return a < b;
        }

        static int
            compare(const char_type* str, const char_type* other, size_t n)
        {
            for (size_t i = 0; i < n; ++i) {
                if (str[i] != other[i])
                    return (str[i] > other[i]) ? 1 : -1;
            }
            return 0;
        }

        static size_t
            length(const char_type* str)
        {
            size_t len = 0;
            for (; str[len] != L'\0'; ++len) {
            }
            return len;
        }

        static const char_type*
            find(const char_type* str, size_t n, const char_type& c)
        {
            for (size_t i = 0; i < n; ++i) {
                if (str[i] == c)
                    return &str[i];
            }
            return NULL;
        }

        static char_type*
            move(char_type* dest, const char_type* src, size_t n)
        {
            return static_cast<char_type*>(memmove(dest, src, n * sizeof(char_type)));
        }

        static char_type*
            copy(char_type* dest, const char_type* src, size_t n)
        {
            for (size_t i = 0; i < n; ++i) {
                dest[i] = src[i];
            }
            return dest;
        }

        static char_type
            to_char_type(const int_type& c)
        {
            return static_cast<char_type>(c);
        }

        static int_type
            to_int_type(const char_type& c)
        {
            return static_cast<int_type>(c);
        }

        static bool
            eq_int_type(const int_type& a, const int_type& b)
        {
            return a == b;
        }

        static int_type
            eof()
        {
            return static_cast<int_type>(WEOF);
        }

        static int_type
            not_eof(const int_type& c)
        {
            return (c != eof()) ? c : 0;
        }
    };

    typedef std::basic_stringstream<wchar_t, hnc_char_traits_w, std::allocator<wchar_t> > wstringstream;
    typedef std::basic_istringstream<wchar_t, hnc_char_traits_w, std::allocator<wchar_t> > wistringstream;
    typedef std::basic_ostringstream<wchar_t, hnc_char_traits_w, std::allocator<wchar_t> > wostringstream;
    typedef std::stringstream    stringstream;    // 같은 namespace를 사용하기 위하여
    typedef std::istringstream   istringstream;   // 같은 namespace를 사용하기 위하여
    typedef std::ostringstream   ostringstream;   // 같은 namespace를 사용하기 위하여
  
    typedef std::basic_string<wchar_t, hnc_char_traits_w> wstring;
    typedef std::string         string;         // 같은 namespace를 사용하기 위하여

    template <typename T>
    inline wstring to_wstring(T value) {
        wstring result;
        string temp = std::to_string(value);
        result.assign(temp.begin(), temp.end());
        return result;
    }
#endif // #if defined(_MSC_VER)

} // namespace hncstd {

#endif