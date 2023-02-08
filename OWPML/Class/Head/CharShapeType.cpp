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
#include "CharShapeType.h"

namespace OWPML {

    CCharShapeType* CCharShapeType::Create()
    {
        return new CCharShapeType();
    }

    CCharShapeType::CCharShapeType() : CExtObject(ID_HEAD_CharShapeType), m_nHeight(1000), m_cTextColor(0x000000), m_cShadeColor(0xFFFFFF), m_bUseFontSpace(false), m_bUseKerning(false), m_uSymMark(SMT_NONE),
        m_uId(0), m_uBorderFillIDRef(0)
    {
    }

    CCharShapeType::~CCharShapeType()
    {
    }

    void CCharShapeType::InitMap(bool bRead)
    {
        OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, fontRef)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, ratio)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, spacing)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, relSz)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, offset)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, italic)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, bold)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, underline)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, strikeout)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, outline)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, shadow)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, emboss)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, engrave)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, supscript)
            OWPML_HEAD_REDIRECT_FUNC(CCharShapeType, subscript)

            OWPML_BEGIN_IMPLEMENT_FUNCMAP(CCharShapeType)
            OWPML_HEAD_ADD_REDIRECT_FUNC(fontRef, CFontRef, ID_HEAD_FontRef)
            OWPML_HEAD_ADD_REDIRECT_FUNC(ratio, CRatio, ID_HEAD_Ratio)
            OWPML_HEAD_ADD_REDIRECT_FUNC(spacing, CSpacing, ID_HEAD_Spacing)
            OWPML_HEAD_ADD_REDIRECT_FUNC(relSz, CRelSz, ID_HEAD_RelSz)
            OWPML_HEAD_ADD_REDIRECT_FUNC(offset, COffset, ID_HEAD_Offset)
            OWPML_HEAD_ADD_REDIRECT_FUNC(italic, CItalic, ID_HEAD_Italic)
            OWPML_HEAD_ADD_REDIRECT_FUNC(bold, CBold, ID_HEAD_Bold)
            OWPML_HEAD_ADD_REDIRECT_FUNC(underline, CUnderline, ID_HEAD_Underline)
            OWPML_HEAD_ADD_REDIRECT_FUNC(strikeout, CStrikeout, ID_HEAD_Strikeout)
            OWPML_HEAD_ADD_REDIRECT_FUNC(outline, COutline, ID_HEAD_Outline)
            OWPML_HEAD_ADD_REDIRECT_FUNC(shadow, CCharShadow, ID_HEAD_CharShadow)
            OWPML_HEAD_ADD_REDIRECT_FUNC(emboss, CEmboss, ID_HEAD_Emboss)
            OWPML_HEAD_ADD_REDIRECT_FUNC(engrave, CEngrave, ID_HEAD_Engrave)
            OWPML_HEAD_ADD_REDIRECT_FUNC(supscript, CSupscript, ID_HEAD_Supscript)
            OWPML_HEAD_ADD_REDIRECT_FUNC(subscript, CSubscript, ID_HEAD_Subscript)
            OWPML_END_IMPLEMENT_FUNCMAP()
    }

    bool CCharShapeType::WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att)
    {
        Util::CXMLAttConverter::SetAttribute(att, L"id", m_uId);
        Util::CXMLAttConverter::SetAttribute(att, L"height", m_nHeight);
        Util::CXMLAttConverter::SetAttribute(att, L"textColor", m_cTextColor);
        Util::CXMLAttConverter::SetAttribute(att, L"shadeColor", m_cShadeColor);
        Util::CXMLAttConverter::SetAttribute(att, L"useFontSpace", m_bUseFontSpace);
        Util::CXMLAttConverter::SetAttribute(att, L"useKerning", m_bUseKerning);
        Util::CXMLAttConverter::SetAttribute(att, L"symMark", g_SymblolMarkList, m_uSymMark);
        Util::CXMLAttConverter::SetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);

        return serialize->WriteElement(pCurObjName, this, att, NULL);
    }

    bool CCharShapeType::ReadAttribute(CAttribute* att)
    {
        bool bres = TRUE;
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"id", m_uId);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"height", m_nHeight);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"textColor", m_cTextColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"shadeColor", m_cShadeColor);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"useFontSpace", m_bUseFontSpace);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"useKerning", m_bUseKerning);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"symMark", g_SymblolMarkList, m_uSymMark);
        bres &= Util::CXMLAttConverter::GetAttribute(att, L"borderFillIDRef", m_uBorderFillIDRef);

        bres &= CExtObject::ReadAttribute(att);
        return bres;
    }

    CFontRef* CCharShapeType::SetfontRef(CFontRef* pfontRef)
    {
        CFontRef* fontRef = pfontRef;
        if (fontRef == NULL) {
            fontRef = CFontRef::Create();
        }
        SetObject((CObject*)fontRef);

        return fontRef;
    }

    CFontRef* CCharShapeType::GetfontRef(int index)
    {
        return static_cast<CFontRef*>(GetObjectByID(ID_HEAD_FontRef, index));
    }

    CRatio* CCharShapeType::Setratio(CRatio* pratio)
    {
        CRatio* ratio = pratio;
        if (ratio == NULL) {
            ratio = CRatio::Create();
        }
        SetObject((CObject*)ratio);

        return ratio;
    }

    CRatio* CCharShapeType::Getratio(int index)
    {
        return static_cast<CRatio*>(GetObjectByID(ID_HEAD_Ratio, index));
    }

    CSpacing* CCharShapeType::Setspacing(CSpacing* pspacing)
    {
        CSpacing* spacing = pspacing;
        if (spacing == NULL) {
            spacing = CSpacing::Create();
        }
        SetObject((CObject*)spacing);

        return spacing;
    }

    CSpacing* CCharShapeType::Getspacing(int index)
    {
        return static_cast<CSpacing*>(GetObjectByID(ID_HEAD_Spacing, index));
    }

    CRelSz* CCharShapeType::SetrelSz(CRelSz* prelSz)
    {
        CRelSz* relSz = prelSz;
        if (relSz == NULL) {
            relSz = CRelSz::Create();
        }
        SetObject((CObject*)relSz);

        return relSz;
    }

    CRelSz* CCharShapeType::GetrelSz(int index)
    {
        return static_cast<CRelSz*>(GetObjectByID(ID_HEAD_RelSz, index));
    }

    COffset* CCharShapeType::Setoffset(COffset* poffset)
    {
        COffset* offset = poffset;
        if (offset == NULL) {
            offset = COffset::Create();
        }
        SetObject((CObject*)offset);

        return offset;
    }

    COffset* CCharShapeType::Getoffset(int index)
    {
        return static_cast<COffset*>(GetObjectByID(ID_HEAD_Offset, index));
    }

    CItalic* CCharShapeType::Setitalic(CItalic* pitalic)
    {
        CItalic* italic = pitalic;
        if (italic == NULL) {
            italic = CItalic::Create();
        }
        SetObject((CObject*)italic);

        return italic;
    }

    CItalic* CCharShapeType::Getitalic(int index)
    {
        return static_cast<CItalic*>(GetObjectByID(ID_HEAD_Italic, index));
    }

    CBold* CCharShapeType::Setbold(CBold* pbold)
    {
        CBold* bold = pbold;
        if (bold == NULL) {
            bold = CBold::Create();
        }
        SetObject((CObject*)bold);

        return bold;
    }

    CBold* CCharShapeType::Getbold(int index)
    {
        return static_cast<CBold*>(GetObjectByID(ID_HEAD_Bold, index));
    }

    CUnderline* CCharShapeType::Setunderline(CUnderline* punderline)
    {
        CUnderline* underline = punderline;
        if (underline == NULL) {
            underline = CUnderline::Create();
        }
        SetObject((CObject*)underline);

        return underline;
    }

    CUnderline* CCharShapeType::Getunderline(int index)
    {
        return static_cast<CUnderline*>(GetObjectByID(ID_HEAD_Underline, index));
    }

    CStrikeout* CCharShapeType::Setstrikeout(CStrikeout* pstrikeout)
    {
        CStrikeout* strikeout = pstrikeout;
        if (strikeout == NULL) {
            strikeout = CStrikeout::Create();
        }
        SetObject((CObject*)strikeout);

        return strikeout;
    }

    CStrikeout* CCharShapeType::Getstrikeout(int index)
    {
        return static_cast<CStrikeout*>(GetObjectByID(ID_HEAD_Strikeout, index));
    }

    COutline* CCharShapeType::Setoutline(COutline* poutline)
    {
        COutline* outline = poutline;
        if (outline == NULL) {
            outline = COutline::Create();
        }
        SetObject((CObject*)outline);

        return outline;
    }

    COutline* CCharShapeType::Getoutline(int index)
    {
        return static_cast<COutline*>(GetObjectByID(ID_HEAD_Outline, index));
    }

    CCharShadow* CCharShapeType::Setshadow(CCharShadow* pshadow)
    {
        CCharShadow* shadow = pshadow;
        if (shadow == NULL) {
            shadow = CCharShadow::Create();
        }
        SetObject((CObject*)shadow);

        return shadow;
    }

    CCharShadow* CCharShapeType::Getshadow(int index)
    {
        return static_cast<CCharShadow*>(GetObjectByID(ID_HEAD_CharShadow, index));
    }

    CEmboss* CCharShapeType::Setemboss(CEmboss* pemboss)
    {
        CEmboss* emboss = pemboss;
        if (emboss == NULL) {
            emboss = CEmboss::Create();
        }
        SetObject((CObject*)emboss);

        return emboss;
    }

    CEmboss* CCharShapeType::Getemboss(int index)
    {
        return static_cast<CEmboss*>(GetObjectByID(ID_HEAD_Emboss, index));
    }

    CEngrave* CCharShapeType::Setengrave(CEngrave* pengrave)
    {
        CEngrave* engrave = pengrave;
        if (engrave == NULL) {
            engrave = CEngrave::Create();
        }
        SetObject((CObject*)engrave);

        return engrave;
    }

    CEngrave* CCharShapeType::Getengrave(int index)
    {
        return static_cast<CEngrave*>(GetObjectByID(ID_HEAD_Engrave, index));
    }

    CSupscript* CCharShapeType::Setsupscript(CSupscript* psupscript)
    {
        CSupscript* supscript = psupscript;
        if (supscript == NULL) {
            supscript = CSupscript::Create();
        }
        SetObject((CObject*)supscript);

        return supscript;
    }

    CSupscript* CCharShapeType::Getsupscript(int index)
    {
        return static_cast<CSupscript*>(GetObjectByID(ID_HEAD_Supscript, index));
    }

    CSubscript* CCharShapeType::Setsubscript(CSubscript* psubscript)
    {
        CSubscript* subscript = psubscript;
        if (subscript == NULL) {
            subscript = CSubscript::Create();
        }
        SetObject((CObject*)subscript);

        return subscript;
    }

    CSubscript* CCharShapeType::Getsubscript(int index)
    {
        return static_cast<CSubscript*>(GetObjectByID(ID_HEAD_Subscript, index));
    }

}
