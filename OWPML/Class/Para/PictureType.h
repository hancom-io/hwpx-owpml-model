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
#ifndef  _PICTURETYPE_H_
#define  _PICTURETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CLineShapeType;
    class CImgRect;
    class CImgClip;
    class CEffectsType;
    class CInsideMarginType;
    class CImageType;


    // CPictureType Declaration 
    class CPictureType : public CAbstractShapeComponentType
    {
    private:
        CPictureType();
    public:
        virtual ~CPictureType();
        static CPictureType* Create();

        CPictureType* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CLineShapeType* SetlineShape(CLineShapeType* lineShape = NULL);
        CLineShapeType* GetlineShape(int index = 0);

        CImgRect* SetimgRect(CImgRect* imgRect = NULL);
        CImgRect* GetimgRect(int index = 0);

        CImgClip* SetimgClip(CImgClip* imgClip = NULL);
        CImgClip* GetimgClip(int index = 0);

        CEffectsType* Seteffects(CEffectsType* effects = NULL);
        CEffectsType* Geteffects(int index = 0);

        CInsideMarginType* SetinMargin(CInsideMarginType* inMargin = NULL);
        CInsideMarginType* GetinMargin(int index = 0);

        CImageType* Setimg(CImageType* img = NULL);
        CImageType* Getimg(int index = 0);

        CImgDim* SetimgDim(CImgDim* imgDim = NULL);
        CImgDim* GetimgDim();

        // Attribute Set/Get Fucntion
        BOOL GetReverse(void) { return m_bReverse == true ? TRUE : FALSE; }
        void SetReverse(BOOL breverse) { m_bReverse = (breverse == TRUE ? true : false); }

    private:
        bool m_bReverse;// 그림 반전
    };
}
#endif // _PICTURETYPE_H_
