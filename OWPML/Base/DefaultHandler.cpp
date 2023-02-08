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
#include "DefaultHandler.h"

namespace OWPML {

    CDefaultHandler::CDefaultHandler(void)
    {
    }

    CDefaultHandler::~CDefaultHandler(void)
    {
    }

    inline void CDefaultHandler::characters(LPCWSTR const /*chars*/, const unsigned int /*length*/)
    {
    }

    inline void CDefaultHandler::endDocument()
    {
    }

    inline void CDefaultHandler::endElement(LPCWSTR const /*uri*/, LPCWSTR const /*localname*/, LPCWSTR const /*qname*/)
    {
    }

    inline void CDefaultHandler::ignorableWhitespace(LPCWSTR const /*chars*/, const unsigned int /*length*/)
    {
    }

    inline void CDefaultHandler::processingInstruction(LPCWSTR const /*target*/, LPCWSTR const /*data*/)
    {
    }

    inline void CDefaultHandler::resetDocument()
    {
    }

    inline void CDefaultHandler::startDocument()
    {
    }

    inline void CDefaultHandler::startElement(LPCWSTR const /*uri*/, LPCWSTR const /*localname*/, LPCWSTR const /*qname*/, \
        const CAttribute* /*attrs*/)
    {
    }

    inline void CDefaultHandler::startPrefixMapping(LPCWSTR const /*prefix*/, LPCWSTR const /*uri*/)
    {
    }

    inline void CDefaultHandler::endPrefixMapping(LPCWSTR const /*prefix*/)
    {
    }

    inline void CDefaultHandler::skippedEntity(LPCWSTR const /*name*/)
    {
    }

    inline void CDefaultHandler::resetErrors()
    {
    }

    inline void CDefaultHandler::resetDocType()
    {
    }

    inline void CDefaultHandler::comment(LPCWSTR const /*chars*/, const unsigned int /*length*/)
    {
    }

    inline void CDefaultHandler::endCDATA()
    {
    }

    inline void CDefaultHandler::endDTD()
    {
    }

    inline void CDefaultHandler::endEntity(LPCWSTR const /*name*/)
    {
    }

    inline void CDefaultHandler::startCDATA()
    {
    }

    inline void CDefaultHandler::startDTD(LPCWSTR const /*name*/, LPCWSTR const /*publicId*/, LPCWSTR const /*systemId*/)
    {
    }

    inline void CDefaultHandler::startEntity(LPCWSTR const /*name*/)
    {
    }

    inline void CDefaultHandler::elementDecl(LPCWSTR const /*name*/, LPCWSTR const /*model*/)
    {
    }

    inline void CDefaultHandler::internalEntityDecl(LPCWSTR const /*name*/, LPCWSTR const /*value*/)
    {
    }

    inline void CDefaultHandler::externalEntityDecl(LPCWSTR const /*name*/, LPCWSTR const /*publicId*/, LPCWSTR const /*systemId*/)
    {
    }

}
