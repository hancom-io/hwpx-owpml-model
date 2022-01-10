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
#ifndef  _VIDEOTYPE_H_
#define  _VIDEOTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CVideoType Declaration 
    class CVideoType : public CAbstractShapeComponentType
    {
    private:
        CVideoType();
    public:
        virtual ~CVideoType();
        static CVideoType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion

        // Attribute Set/Get Fucntion
        UINT GetVideoType(void) { return m_uVideoType; }
        void SetVideoType(UINT videotype) { m_uVideoType = videotype; }

        LPCWSTR GetFileID(void) { return m_strFileID.c_str(); }
        void SetFileID(LPCWSTR fileid) { m_strFileID = fileid; }

        LPCWSTR GetImageID(void) { return m_strImageID.c_str(); }
        void SetImageID(LPCWSTR imageid) { m_strImageID = imageid; }

        LPCWSTR GetTag(void) { return m_strTag.c_str(); }
        void SetTag(LPCWSTR tag) { m_strTag = tag; }

    private:
        UINT            m_uVideoType;
        hncstd::wstring        m_strFileID;
        hncstd::wstring        m_strImageID;
        hncstd::wstring        m_strTag;
    };
}
#endif // _PICTURETYPE_H_
