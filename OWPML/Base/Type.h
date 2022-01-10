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

#ifndef _OWPML_TYPE_H_
#define _OWPML_TYPE_H_

namespace OWPML {

    typedef struct tagENUMLIST {
        UINT   id;
        WCHAR* token;
    } ENUMLIST, *LPENUMLIST;

    typedef struct idENUMLIST {
        UINT hwpid;
        UINT owpmlid;
    } IDENUMLIST, *LPIDENUMLIST;

    class CColorRef
    {
    public:
        CColorRef() : m_ext(0), m_green(0), m_blue(0), m_red(0)
        {
        }

        CColorRef(COLORREF color)
        {
            m_ext = (BYTE)((color & 0xFF000000) >> 24);
            m_blue = (BYTE)((color & 0x00FF0000) >> 16);
            m_green = (BYTE)((color & 0x0000FF00) >> 8);
            m_red = (BYTE)(color & 0x000000FF);
        }

        operator COLORREF() const
        {
            COLORREF color = 0;
            color += (m_ext << 24);
            color += (m_blue << 16);
            color += (m_green << 8);
            color += m_red;
            return color;
        }

        CColorRef& operator=(const CColorRef& src)
        {
            m_ext = src.m_ext;
            m_green = src.m_green;
            m_blue = src.m_blue;
            m_red = src.m_red;
            return *this;
        }

        CColorRef& operator=(const COLORREF& src)
        {
            m_ext = (BYTE)((src & 0xFF000000) >> 24);
            m_blue = (BYTE)((src & 0x00FF0000) >> 16);
            m_green = (BYTE)((src & 0x0000FF00) >> 8);
            m_red = (BYTE)(src & 0x000000FF);
            return *this;
        }

        DWORD GetRgb()
        {
            DWORD color = 0;
            color += (m_ext << 24);
            color += (m_red << 16);
            color += (m_green << 8);
            color += m_blue;
            return color;
        }

        void SetRgb(DWORD rgbcolor)
        {
            m_ext = (BYTE)((rgbcolor & 0xFF000000) >> 24);;
            m_red = (BYTE)((rgbcolor & 0x00FF0000) >> 16);
            m_green = (BYTE)((rgbcolor & 0x0000FF00) >> 8);
            m_blue = (BYTE)(rgbcolor & 0x000000FF);
        }

    private:
        BYTE m_ext;
        BYTE m_green;
        BYTE m_blue;
        BYTE m_red;
    };

}

#endif // _OWPML_TYPE_H_