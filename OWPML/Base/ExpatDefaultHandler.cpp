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

#include "Attribute.h"
#include "DefaultHandler.h"
#include "ExpatSax.h"
#include "ExpatAttribute.h"
#include "ExpatDefaultHandler.h"

namespace OWPML {

    CExpatDefaultHandler::CExpatDefaultHandler(CDefaultHandler* handler) : m_Handler(handler)
    {
    }

    CExpatDefaultHandler::~CExpatDefaultHandler(void)
    {
    }

    void CExpatDefaultHandler::SetDefaultHandler(CDefaultHandler* handler)
    {
        m_Handler = handler;
    }

    void CExpatDefaultHandler::SetHandler(XML_Parser parser)
    {
        XML_SetUserData(parser, (void*)this);
        XML_SetElementNSHandler(parser, CExpatDefaultHandler::startElementNs, CExpatDefaultHandler::endElementNs);
        XML_SetStartNamespaceDeclHandler(parser, CExpatDefaultHandler::startPrefixMapping);
        XML_SetEndNamespaceDeclHandler(parser, CExpatDefaultHandler::endPrefixMapping);
        XML_SetCharacterDataHandler(parser, CExpatDefaultHandler::characters);
    }

    void CExpatDefaultHandler::characters(void* data, const XML_Char *ch, int len)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;
        handle->GetHandler()->characters((LPCWSTR)ch, len);
    }

    void CExpatDefaultHandler::endDocument(void * data)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;
        handle->GetHandler()->endDocument();
    }

    void CExpatDefaultHandler::endElementNs(void* data, const XML_Char *uri, const XML_Char *qname, const XML_Char *localname)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;
        // endElement 처리
        handle->GetHandler()->endElement((LPCWSTR)uri, (LPCWSTR)localname, (LPCWSTR)qname);
    }

    void CExpatDefaultHandler::startDocument(void* data)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;
        handle->GetHandler()->startDocument();
    }

    void CExpatDefaultHandler::startElementNs(void* data, const XML_Char *uri, const XML_Char *qname, const XML_Char *localname, const XML_Char **atts)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;

        // startElement 처리
        CExpatAttribute attr(atts);
        handle->GetHandler()->startElement((LPCWSTR)uri, (LPCWSTR)localname, (LPCWSTR)qname, &attr);
    }

    void CExpatDefaultHandler::startPrefixMapping(void *data, const XML_Char* const prefix, const XML_Char* const uri)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;
        handle->GetHandler()->startPrefixMapping((LPCWSTR)prefix, (LPCWSTR)uri);
    }

    void CExpatDefaultHandler::endPrefixMapping(void *data, const XML_Char* const prefix)
    {
        CExpatDefaultHandler* handle = (CExpatDefaultHandler*)data;
        handle->GetHandler()->endPrefixMapping((LPCWSTR)prefix);
    }
}
