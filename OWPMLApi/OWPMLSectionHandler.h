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

#ifndef _OWPMLAPI_OWPML_SECTION_HANDLER_H_
#define _OWPMLAPI_OWPML_SECTION_HANDLER_H_

namespace OWPML
{
    class COwpmlSerialize;
    class COwpmlSerializeModel;

    class CSectionHandler : public CHandler
    {
    public:
        explicit CSectionHandler(COwpmlSerialize* serialize, COwpmlSerializeModel* serializeModel);
        virtual ~CSectionHandler();

        virtual void startElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname, const CAttribute* attrs);
        virtual void endElement(LPCWSTR const uri, LPCWSTR const localname, LPCWSTR const qname);

    private:
        BOOL IsShapeObjectElem(const CAttribute* attrs);
        BOOL IsMetaTagAttribute(const CAttribute* attrs);

        void ProcessingElement();

    private:
        int m_startparalevel;

        COwpmlSerialize* m_serialize;
        COwpmlSerializeModel* m_serializeModel;
    };
}

#endif // _OWPMLAPI_OWPML_SECTION_HANDLER_H_