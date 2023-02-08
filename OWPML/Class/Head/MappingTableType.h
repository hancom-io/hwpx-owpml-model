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
#ifndef  _MAPPINGTABLETYPE_H_
#define  _MAPPINGTABLETYPE_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;
    class CFontfaces;
    class CBorderFills;
    class CCharProperties;
    class CTabProperties;
    class CNumberings;
    class CBullets;
    class CParaProperties;
    class CStyles;
    class CMemoProperties;
    class CTrackChangeAuthors;
    class CTrackChanges;

    // CMappingTableType Declaration 
    class CMappingTableType : public CExtObject
    {
    private:
        CMappingTableType();
    public:
        virtual ~CMappingTableType();
        static CMappingTableType* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        CFontfaces* Setfontfaces(CFontfaces* fontfaces = NULL);
        CFontfaces* Getfontfaces(int index = 0);

        CBorderFills* SetborderFills(CBorderFills* borderFills = NULL);
        CBorderFills* GetborderFills(int index = 0);

        CCharProperties* SetcharProperties(CCharProperties* charProperties = NULL);
        CCharProperties* GetcharProperties(int index = 0);

        CTabProperties* SettabProperties(CTabProperties* tabProperties = NULL);
        CTabProperties* GettabProperties(int index = 0);

        CNumberings* Setnumberings(CNumberings* numberings = NULL);
        CNumberings* Getnumberings(int index = 0);

        CBullets* Setbullets(CBullets* bullets = NULL);
        CBullets* Getbullets(int index = 0);

        CParaProperties* SetparaProperties(CParaProperties* paraProperties = NULL);
        CParaProperties* GetparaProperties(int index = 0);

        CStyles* Setstyles(CStyles* styles = NULL);
        CStyles* Getstyles(int index = 0);

        CMemoProperties* SetmemoProperties(CMemoProperties* memoProperties = NULL);
        CMemoProperties* GetmemoProperties(int index = 0);

        CTrackChanges* SettrackChanges(CTrackChanges* trackchanges = NULL);
        CTrackChanges* GettrackChanges(int index = 0);

        CTrackChangeAuthors* SettrackChangeAuthors(CTrackChangeAuthors* trackchangeAuthors = NULL);
        CTrackChangeAuthors* GettrackChangeAuthors(int index = 0);

        // Attribute Set/Get Fucntion

    private:
    };
}
#endif // _MAPPINGTABLETYPE_H_
