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
#ifndef  _ABSTRACTSHAPECOMPONENTTYPE_H_
#define  _ABSTRACTSHAPECOMPONENTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CASCOffset;
    class COrgSz;
    class CCurSz;
    class CFlip;
    class CRotationInfo;
    class CRenderingInfo;

    // CAbstractShapeComponentType Declaration 
    class CAbstractShapeComponentType : public CAbstractShapeObjectType
    {
    public:
        CAbstractShapeComponentType(UINT id);
    public:
        virtual ~CAbstractShapeComponentType();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CASCOffset* Setoffset(CASCOffset* offset = NULL);
        CASCOffset* Getoffset(int index = 0);

        COrgSz* SetorgSz(COrgSz* orgSz = NULL);
        COrgSz* GetorgSz(int index = 0);

        CCurSz* SetcurSz(CCurSz* curSz = NULL);
        CCurSz* GetcurSz(int index = 0);

        CFlip* Setflip(CFlip* flip = NULL);
        CFlip* Getflip(int index = 0);

        CRotationInfo* SetrotationInfo(CRotationInfo* rotationInfo = NULL);
        CRotationInfo* GetrotationInfo(int index = 0);

        CRenderingInfo* SetrenderingInfo(CRenderingInfo* renderingInfo = NULL);
        CRenderingInfo* GetrenderingInfo(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetInstId(void) { return m_uInstId; }
        void SetInstId(UINT instid) { m_uInstId = instid; }

        LPCWSTR GetHref(void) { return m_strHref.c_str(); }
        void SetHref(LPCWSTR href) { m_strHref = href; }

        UINT GetGroupLevel(void) { return m_uGroupLevel; }
        void SetGroupLevel(UINT groupLevel) { m_uGroupLevel = groupLevel; }


    private:
        hncstd::wstring m_strHref;
        UINT m_uGroupLevel;
        UINT m_uInstId;
    };
}
#endif // _ABSTRACTSHAPECOMPONENTTYPE_H_
