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
#include "bullets.h"

namespace OWPML {

    CBullets* CBullets::Create()
    {
        return new CBullets();
    }

    CBullets::CBullets() : CExtObject(ID_HEAD_Bullets), m_uItemCnt(0)
    {
    }

    CBullets::~CBullets()
    {
    }

    void CBullets::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CBullets, bullet)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CBullets)
            OWPML_HEAD_ADD_REDIRECT_FUNC(bullet, CBulletType, ID_HEAD_BulletType)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CBullets::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"itemCnt", m_uItemCnt);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CBullets::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"itemCnt", m_uItemCnt);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CBulletType* CBullets::Setbullet(CBulletType* pbullet)
    {
        CBulletType* bullet = pbullet;
        if (bullet == NULL) {
            bullet = CBulletType::Create();
        }
        SetObject((CObject*)bullet);

        return bullet;
    }

    CBulletType* CBullets::Getbullet(int index)
    {
        return static_cast<CBulletType*>(GetObjectByID(ID_HEAD_BulletType, index));
    }

}
