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

#ifndef EXPAT_SAXREADER_H
#define EXPAT_SAXREADER_H

namespace OWPML {

    class CExpatSaxReader : public CSaxReader
    {
    public:
        CExpatSaxReader(void);
        virtual ~CExpatSaxReader(void);

    public:
        bool parse(LPCWSTR const path);
        bool parse(LPCWSTR const path, CObject* pRootObject);
        bool parse(LPCWSTR const unidata, unsigned int datalen);
        bool parse(LPCWSTR const unidata, unsigned int datalen, CObject* pRootObject);
        bool parse(const char *const multidata, unsigned int datalen);
        bool parse(const char *const multidata, unsigned int datalen, CObject* pRootObject);
        bool getFeature(LPCWSTR const name);
        void setFeature(LPCWSTR const name, const bool value);
        void setContentHandler(CDefaultHandler* handler);

        bool parsestart();
        bool continueparse(LPCWSTR const unidata, unsigned int datalen, BOOL bend);
        bool continueparse(const char *const multidata, unsigned int datalen, BOOL bend);
        bool parseend();

    private:
        bool fileparse(LPCWSTR const path, XML_Parser parser);

    private:
        CExpatDefaultHandler* m_pHandler;
        XML_Parser m_parser;
    };

    CSaxReader*  CreateSaxReader(void);
    void ReleaseSaxReader(CSaxReader* preader);

}

#endif // EXPAT_SAXREADER_H