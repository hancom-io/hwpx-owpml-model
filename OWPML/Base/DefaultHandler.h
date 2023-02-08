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

#ifndef _DEFAULTHANDLER_H_
#define _DEFAULTHANDLER_H_

namespace OWPML {

    class CAttribute;

    class CDefaultHandler
    {
    public:
        CDefaultHandler(void);
        virtual ~CDefaultHandler(void);

    public:
        virtual void characters(LPCWSTR const /*chars*/, const unsigned int /*length*/);
        virtual void endDocument();
        virtual void endElement(LPCWSTR const /*uri*/, LPCWSTR const /*localname*/, LPCWSTR const /*qname*/);
        virtual void ignorableWhitespace(LPCWSTR const /*chars*/, const unsigned int /*length*/);
        virtual void processingInstruction(LPCWSTR const /*target*/, LPCWSTR const /*data*/);
        virtual void resetDocument();
        virtual void startDocument();
        virtual void startElement(LPCWSTR const /*uri*/, LPCWSTR const /*localname*/, LPCWSTR const /*qname*/, const CAttribute* /*attrs*/);
        virtual void startPrefixMapping(LPCWSTR const /*prefix*/, LPCWSTR const /*uri*/);
        virtual void endPrefixMapping(LPCWSTR const /*prefix*/);
        virtual void skippedEntity(LPCWSTR const /*name*/);
        virtual void resetErrors();
        virtual void resetDocType();
        virtual void comment(LPCWSTR const /*chars*/, const unsigned int /*length*/);
        virtual void endCDATA();
        virtual void endDTD();
        virtual void endEntity(LPCWSTR const /*name*/);
        virtual void startCDATA();
        virtual void startDTD(LPCWSTR const /*name*/, LPCWSTR const /*publicId*/, LPCWSTR const /*systemId*/);
        virtual void startEntity(LPCWSTR const /*name*/);
        virtual void elementDecl(LPCWSTR const /*name*/, LPCWSTR const /*model*/);
        virtual void internalEntityDecl(LPCWSTR const /*name*/, LPCWSTR const /*value*/);
        virtual void externalEntityDecl(LPCWSTR const /*name*/, LPCWSTR const /*publicId*/, LPCWSTR const /*systemId*/);
    };

}

#endif // _DEFAULTHANDLER_H_