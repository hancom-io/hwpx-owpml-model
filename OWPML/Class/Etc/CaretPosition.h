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
#ifndef  _CARETPOSITION_H_
#define  _CARETPOSITION_H_

namespace OWPML {

    class CAttribute;
    class CSerializer;

    // CCaretPosition Declaration 
    class CCaretPosition : public CExtObject
    {
    private:
        CCaretPosition();
    public:
        virtual ~CCaretPosition();
        static CCaretPosition* Create();

    public: // read, write function 
        virtual void InitMap(bool bRead);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);

    public:
        // Element Set Fucntion
        // Attribute Set/Get Fucntion
        UINT GetListID(void) { return m_uListID; }
        void SetListID(UINT listID) { m_uListID = listID; }

        UINT GetParaID(void) { return m_uParaID; }
        void SetParaID(UINT paraID) { m_uParaID = paraID; }

        UINT GetPos(void) { return m_uPos; }
        void SetPos(UINT pos) { m_uPos = pos; }


    private:
        UINT m_uListID;
        UINT m_uParaID;
        UINT m_uPos;
    };
}
#endif // _CARETPOSITION_H_
