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
#include "Object.h"
#include "Attribute.h"
#include "Util.h"
#include "Serialize.h"
#include "container.h"

namespace OWPML {

    /////////////////////////////////////////////////////////////////////////////////////////
    // CRootFile
    /////////////////////////////////////////////////////////////////////////////////////////
    CRootFile* CRootFile::Create()
    {
        return new CRootFile();
    }

    CRootFile::CRootFile() : CExtObject(ID_CON_RootFile)
    {
    }

    CRootFile::~CRootFile()
    {
    }

    void CRootFile::InitMap(bool /*bRead*/)
    {
    }

    bool CRootFile::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"full-path", m_strFullpath);
        Util::CXMLAttConverter::SetAttribute(att, L"media-type", m_strMediatype);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRootFile::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"full-path", m_strFullpath);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"media-type", m_strMediatype);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CRootFiles
    /////////////////////////////////////////////////////////////////////////////////////////
    CRootFiles* CRootFiles::Create()
    {
        return new CRootFiles();
    }

    CRootFiles::CRootFiles() : CExtObject(ID_CON_RootFiles)
    {
    }

    CRootFiles::~CRootFiles()
    {
    }

    void CRootFiles::InitMap(bool bRead)
    {
        OWPML_OCF_REDIRECT_FUNC(CRootFiles, rootfile)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CRootFiles)
            OWPML_OCF_ADD_REDIRECT_FUNC(rootfile, CRootFile, ID_CON_RootFile)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CRootFiles::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRootFiles::ReadAttribute(CAttribute* att)
    {
        return CExtObject::ReadAttribute(att);
    }

    CRootFile* CRootFiles::Setrootfile(CRootFile* prootfile)
    {
        CRootFile* rootfile = prootfile;
        if (rootfile == NULL) {
            rootfile = CRootFile::Create();
        }
        SetObject((CObject*)rootfile);

        return rootfile;
    }

    CRootFile* CRootFiles::Getrootfile(int index)
    {
        return static_cast<CRootFile*>(GetObjectByID(ID_CON_RootFile, index));
    }

    /////////////////////////////////////////////////////////////////////////////////////////
    // CContainer
    /////////////////////////////////////////////////////////////////////////////////////////
    CContainer* CContainer::Create()
    {
        return new CContainer();
    }

    CContainer::CContainer() : CNamedObject(ID_CON_Container)
    {
        SetElemName(L"ocf:container");
    }

    CContainer::~CContainer()
    {
    }

    void CContainer::InitMap(bool bRead)
    {
        OWPML_OCF_REDIRECT_FUNC(CContainer, rootfiles)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CContainer)
            OWPML_OCF_ADD_REDIRECT_FUNC(rootfiles, CRootFiles, ID_CON_RootFiles)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CContainer::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CContainer::ReadAttribute(CAttribute* att)
    {
        return CNamedObject::ReadAttribute(att);
    }

    CRootFiles* CContainer::Setrootfiles(CRootFiles* prootfiles)
    {
        CRootFiles* rootfiles = prootfiles;
        if (rootfiles == NULL) {
            rootfiles = CRootFiles::Create();
        }
        SetObject((CObject*)rootfiles);

        return rootfiles;
    }

    CRootFiles* CContainer::Getrootfiles(int index)
    {
        return static_cast<CRootFiles*>(GetObjectByID(ID_CON_RootFiles, index));
    }

}
