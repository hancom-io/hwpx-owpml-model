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
#ifndef  _ABSTRACTSHAPEOBJECTTYPE_H_
#define  _ABSTRACTSHAPEOBJECTTYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CSz;
    class CASOPos;
    class COutMargin;
    class CCaption;
    class CShapeComment;

    // CAbstractShapeObjectType Declaration 
    class CAbstractShapeObjectType : public CExtObject
    {
    public:
        CAbstractShapeObjectType(UINT id);
    public:
        virtual ~CAbstractShapeObjectType();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

        virtual BOOL IsDrawingObject(void) const { return TRUE; }

    public:
        // Element Set Fucntion
        CSz* Setsz(CSz* sz = NULL);
        CSz* Getsz(int index = 0);

        CASOPos* Setpos(CASOPos* pos = NULL);
        CASOPos* Getpos(int index = 0);

        COutMargin* SetoutMargin(COutMargin* outMargin = NULL);
        COutMargin* GetoutMargin(int index = 0);

        CCaption* Setcaption(CCaption* caption = NULL);
        CCaption* Getcaption(int index = 0);

        CShapeComment* SetshapeComment(CShapeComment* shapeComment = NULL);
        CShapeComment* GetshapeComment(int index = 0);

        // Attribute Set/Get Fucntion
        UINT GetId(void) { return m_uId; }
        void SetId(UINT id) { m_uId = id; }

        INT GetZOrder(void) { return m_nZOrder; }
        void SetZOrder(INT zOrder) { m_nZOrder = zOrder; }

        ASONUMBERINGTYPE GetNumberingType(void) { return (ASONUMBERINGTYPE)m_uNumberingType; }
        void SetNumberingType(ASONUMBERINGTYPE numberingType) { m_uNumberingType = (UINT)numberingType; }

        ASOTEXTWRAPTYPE GetTextWrap(void) { return (ASOTEXTWRAPTYPE)m_uTextWrap; }
        void SetTextWrap(ASOTEXTWRAPTYPE textWrap) { m_uTextWrap = (UINT)textWrap; }

        ASOTEXTFLOWTYPE GetTextFlow(void) { return (ASOTEXTFLOWTYPE)m_uTextFlow; }
        void SetTextFlow(ASOTEXTFLOWTYPE textFlow) { m_uTextFlow = (UINT)textFlow; }

        BOOL GetLock(void) { return m_bLock == true ? TRUE : FALSE; }
        void SetLock(BOOL lock) { m_bLock = (lock == TRUE ? true : false); }

        UINT GetDropCapStyle(void) { return m_uDropCapStyle; }
        void SetDropCapStyle(UINT uStyle) { m_uDropCapStyle = uStyle; }

    private:
        UINT m_uId;
        INT m_nZOrder;
        UINT m_uNumberingType;
        UINT m_uTextWrap;
        UINT m_uTextFlow;
        bool m_bLock;
        UINT m_uDropCapStyle;
    };
}
#endif // _ABSTRACTSHAPEOBJECTTYPE_H_
