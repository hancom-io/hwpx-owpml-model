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
#include "renderingInfo.h"

namespace OWPML {

    CRenderingInfo* CRenderingInfo::Create()
    {
        return new CRenderingInfo();
    }

    CRenderingInfo* CRenderingInfo::Clone()
    {
        CRenderingInfo* clone = new CRenderingInfo();

        clone->SetObjectList(this->GetObjectList());
        return clone;
    }

    CRenderingInfo::CRenderingInfo() : CExtObject(ID_PARA_RenderingInfo)
    {
    }

    CRenderingInfo::~CRenderingInfo()
    {
    }

    void CRenderingInfo::InitMap(bool bRead)
    {
        OWPML_CORE_REDIRECT_FUNC(CRenderingInfo, transMatrix)
            OWPML_CORE_REDIRECT_FUNC(CRenderingInfo, scaMatrix)
            OWPML_CORE_REDIRECT_FUNC(CRenderingInfo, rotMatrix)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CRenderingInfo)
            OWPML_CORE_ADD_REDIRECT_FUNC(transMatrix, CMatrixType, ID_CORE_MatrixType_Trans)
            OWPML_CORE_ADD_REDIRECT_FUNC(scaMatrix, CMatrixType, ID_CORE_MatrixType_Sca)
            OWPML_CORE_ADD_REDIRECT_FUNC(rotMatrix, CMatrixType, ID_CORE_MatrixType_Rot)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CRenderingInfo::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CRenderingInfo::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CMatrixType* CRenderingInfo::SettransMatrix(CMatrixType* ptransMatrix)
    {
        CMatrixType* transMatrix = ptransMatrix;
        if (transMatrix == NULL) {
            transMatrix = CMatrixType::CreateArg(ID_CORE_MatrixType_Trans);
        }
        SetObject((CObject*)transMatrix);

        return transMatrix;
    }

    CMatrixType* CRenderingInfo::GettransMatrix(int index)
    {
        return static_cast<CMatrixType*>(GetObjectByID(ID_CORE_MatrixType_Trans, index));
    }

    CMatrixType* CRenderingInfo::SetscaMatrix(CMatrixType* pscaMatrix)
    {
        CMatrixType* scaMatrix = pscaMatrix;
        if (scaMatrix == NULL) {
            scaMatrix = CMatrixType::CreateArg(ID_CORE_MatrixType_Sca);
        }
        SetObject((CObject*)scaMatrix);

        return scaMatrix;
    }

    CMatrixType* CRenderingInfo::GetscaMatrix(int index)
    {
        return static_cast<CMatrixType*>(GetObjectByID(ID_CORE_MatrixType_Sca, index));
    }

    CMatrixType* CRenderingInfo::SetrotMatrix(CMatrixType* protMatrix)
    {
        CMatrixType* rotMatrix = protMatrix;
        if (rotMatrix == NULL) {
            rotMatrix = CMatrixType::CreateArg(ID_CORE_MatrixType_Rot);
        }
        SetObject((CObject*)rotMatrix);

        return rotMatrix;
    }

    CMatrixType* CRenderingInfo::GetrotMatrix(int index)
    {
        return static_cast<CMatrixType*>(GetObjectByID(ID_CORE_MatrixType_Rot, index));
    }

}
