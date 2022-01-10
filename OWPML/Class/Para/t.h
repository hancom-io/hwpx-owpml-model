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
#ifndef  _T_H_
#define  _T_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CMarkpenBegin;
    class CMarkpenEnd;
    class CTitleMark;
    class CTab;
    class CLineBreak;
    class CHypen;
    class CNbSpace;
    class CFwSpace;
    class CTrackChangeEnd;
    class CTrackChangeBegin;
    class CTrackChangeTag;

    // CT Declaration 
    class CT : public CExtObject
    {
    private:
        CT();
    public:
        virtual ~CT();
        static CT* Create();

        CT* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual bool ReadNodeValue(LPCWSTR const value, const unsigned int length);

    public:
        // Element Set Fucntion
        CMarkpenBegin* SetmarkpenBegin(CMarkpenBegin* markpenBegin = NULL);
        CMarkpenBegin* GetmarkpenBegin(int index = 0);

        CMarkpenEnd* SetmarkpenEnd(CMarkpenEnd* markpenEnd = NULL);
        CMarkpenEnd* GetmarkpenEnd(int index = 0);

        CTrackChangeTag* SettcInsertBegin(CTrackChangeTag* ptcbegin = NULL);
        CTrackChangeTag* GettcInsertBegin(int index = 0);

        CTrackChangeTag* SettcInsertEnd(CTrackChangeTag* ptcend = NULL);
        CTrackChangeTag* GettcInsertEnd(int index = 0);

        CTrackChangeTag* SettcDeleteBegin(CTrackChangeTag* ptcbegin = NULL);
        CTrackChangeTag* GettcDeleteBegin(int index = 0);

        CTrackChangeTag* SettcDeleteEnd(CTrackChangeTag* ptcend = NULL);
        CTrackChangeTag* GettcDeleteEnd(int index = 0);

        CTitleMark* SettitleMark(CTitleMark* titleMark = NULL);
        CTitleMark* GettitleMark(int index = 0);

        CTab* Settab(CTab* tab = NULL);
        CTab* Gettab(int index = 0);

        CLineBreak* SetlineBreak(CLineBreak* lineBreak = NULL);
        CLineBreak* GetlineBreak(int index = 0);

        CHypen* Sethypen(CHypen* hypen = NULL);
        CHypen* Gethypen(int index = 0);

        CNbSpace* SetnbSpace(CNbSpace* nbSpace = NULL);
        CNbSpace* GetnbSpace(int index = 0);

        CFwSpace* SetfwSpace(CFwSpace* fwSpace = NULL);
        CFwSpace* GetfwSpace(int index = 0);

        void Setval(LPCWSTR val, BOOL bread = FALSE);

        // Attribute Set/Get Fucntion
        UINT GetCharStyleIDRef(void) { return m_uCharStyleIDRef; }
        void SetCharStyleIDRef(UINT charStyleIDRef) { m_uCharStyleIDRef = charStyleIDRef; }

    private:
        UINT m_uCharStyleIDRef;
    };

    class CChar : public CStringValueObject
    {
    public:
        CChar(LPCWSTR val);
        virtual ~CChar();

        CChar* Clone();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    private:
        void Setval(LPCWSTR val);
        void Setval(hncstd::wstring& /*val*/) {};
    };


    // surrogate 문자중 하나만 사용된 경우 처리
    // 예전 한글에서 기호로 사용되어서 처리한다.
    class CUnknownChar : public CExtObject
    {
    public:
        CUnknownChar(WCHAR unchar = 0);

    public:
        static CUnknownChar* Create();
        virtual ~CUnknownChar();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        void SetUnknownChar(WCHAR unchar) { m_wUnknownChar = unchar; }
        WCHAR GetUnknownChar(void) { return m_wUnknownChar; }

    private:
        WCHAR m_wUnknownChar;
    };

}
#endif // _T_H_
