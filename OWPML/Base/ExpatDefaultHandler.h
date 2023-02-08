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

#ifndef EXPAT_DEFAULTHANDER_H
#define EXPAT_DEFAULTHANDER_H
namespace OWPML {

    class CExpatDefaultHandler
    {
    public:
        CExpatDefaultHandler(CDefaultHandler* handler);
        virtual ~CExpatDefaultHandler(void);

    public:
        static void characters(void *data, const XML_Char *ch, int len);
        static  void endDocument(void *data);
        static void endElementNs(void *data, const XML_Char *uri, const XML_Char *qname, const XML_Char *localname);
        static  void startDocument(void *data);

        static void startElementNs(void *data, const XML_Char *uri, const XML_Char *qname, const XML_Char *localname, const XML_Char **atts);
        static  void startPrefixMapping(void *data, const XML_Char* const prefix, const XML_Char* const uri);
        static  void endPrefixMapping(void *data, const XML_Char* const prefix);

        void SetDefaultHandler(CDefaultHandler* handler);
        void SetHandler(XML_Parser parser);

    private:
        CDefaultHandler* GetHandler(void) const { return m_Handler; }

    private:
        CDefaultHandler* m_Handler;
    };

}

#endif // EXPAT_DEFAULTHANDER_H