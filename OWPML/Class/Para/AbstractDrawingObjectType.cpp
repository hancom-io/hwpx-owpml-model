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
#include "AbstractShapeObjectType.h"
#include "AbstractShapeComponentType.h"
#include "AbstractDrawingObjectType.h"

namespace OWPML {

    CAbstractDrawingObjectType::CAbstractDrawingObjectType(UINT id) : CAbstractShapeComponentType(id)
    {
    }

    CAbstractDrawingObjectType::~CAbstractDrawingObjectType()
    {
    }

    void CAbstractDrawingObjectType::InitMap(bool /*bRead*/)
    {
    }

    bool CAbstractDrawingObjectType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        CAbstractShapeComponentType::WriteElement(pCurObjName, serialize, att);

        return true;
    }

    bool CAbstractDrawingObjectType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= CAbstractShapeComponentType::ReadAttribute(att);

        return bres;
    }

    CLineShapeType* CAbstractDrawingObjectType::SetlineShape(CLineShapeType* plineShape)
    {
        CLineShapeType* lineShape = plineShape;
        if (lineShape == NULL) {
            lineShape = CLineShapeType::Create();
        }
        SetObject((CObject*)lineShape);

        return lineShape;
    }

    CLineShapeType* CAbstractDrawingObjectType::GetlineShape(int index)
    {
        return static_cast<CLineShapeType*>(GetObjectByID(ID_PARA_LineShapeType, index));
    }

    CFillBrushType* CAbstractDrawingObjectType::SetfillBrush(CFillBrushType* pfillBrush)
    {
        CFillBrushType* fillBrush = pfillBrush;
        if (fillBrush == NULL) {
            fillBrush = CFillBrushType::Create();
        }
        SetObject((CObject*)fillBrush);

        return fillBrush;
    }

    CFillBrushType* CAbstractDrawingObjectType::GetfillBrush(int index)
    {
        return static_cast<CFillBrushType*>(GetObjectByID(ID_CORE_FillBrushType, index));
    }

    CDrawText* CAbstractDrawingObjectType::SetdrawText(CDrawText* pdrawText)
    {
        CDrawText* drawText = pdrawText;
        if (drawText == NULL) {
            drawText = CDrawText::Create();
        }
        SetObject((CObject*)drawText);

        return drawText;
    }

    CDrawText* CAbstractDrawingObjectType::GetdrawText(int index)
    {
        return static_cast<CDrawText*>(GetObjectByID(ID_PARA_DrawText, index));
    }

    CShadowType* CAbstractDrawingObjectType::Setshadow(CShadowType* pshadow)
    {
        CShadowType* shadow = pshadow;
        if (shadow == NULL) {
            shadow = CShadowType::Create();
        }
        SetObject((CObject*)shadow);

        return shadow;
    }

    CShadowType* CAbstractDrawingObjectType::Getshadow(int index)
    {
        return static_cast<CShadowType*>(GetObjectByID(ID_PARA_ShadowType, index));
    }

}
