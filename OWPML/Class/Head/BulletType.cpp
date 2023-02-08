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
#include "BulletType.h"

namespace OWPML {

    CBulletType* CBulletType::Create()
    {
        return new CBulletType();
    }

    CBulletType::CBulletType() : CExtObject(ID_HEAD_BulletType), m_bUseImage(false), m_uId(0)
    {
    }

    CBulletType::~CBulletType()
    {
    }

    void CBulletType::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CBulletType, img)
            OWPML_HEAD_REDIRECT_FUNC(CBulletType, paraHead)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CBulletType)
            OWPML_CORE_ADD_REDIRECT_FUNC(img, CImageType, ID_CORE_ImageType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(paraHead, CParaHeadType, ID_HEAD_ParaHeadType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CBulletType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"char", m_strChar);
        Util::CXMLAttConverter::SetAttribute(att, L"useImage", m_bUseImage);

        if (m_strCheckedChar.length() > 0) {
            Util::CXMLAttConverter::SetAttribute(att, L"checkedChar", m_strCheckedChar);
        }
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBulletType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"char", m_strChar);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"useImage", m_bUseImage);
        Util::CXMLAttConverter::GetAttribute(att, L"checkedChar", m_strCheckedChar);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CImageType* CBulletType::Setimg(CImageType* pimg)
    {
        CImageType* img = pimg;
        if (img == NULL) {
            img = CImageType::Create();
        }
        SetObject((CObject*)img);

        return img;
    }

    CImageType* CBulletType::Getimg(int index)
    {
        return static_cast<CImageType*>(GetObjectByID(ID_CORE_ImageType, index));
    }

    CParaHeadType* CBulletType::SetparaHead(CParaHeadType* pparaHead)
    {
        CParaHeadType* paraHead = pparaHead;
        if (paraHead == NULL) {
            paraHead = CParaHeadType::Create();
        }
        SetObject((CObject*)paraHead);

        return paraHead;
    }

    CParaHeadType* CBulletType::GetparaHead(int index)
    {
        return static_cast<CParaHeadType*>(GetObjectByID(ID_HEAD_ParaHeadType, index));
    }

}
