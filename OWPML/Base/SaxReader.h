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

#ifndef OWPML_SAXREADER_H
#define OWPML_SAXREADER_H

namespace OWPML {

    class CDefaultHandler;

    class CSaxReader
    {
    public:
        CSaxReader(void) {};
        virtual ~CSaxReader(void) {};

    public:
        virtual bool parse(LPCWSTR const path) = 0;
        virtual bool parse(LPCWSTR const path, CObject* pRootObject) = 0;
        virtual bool parse(LPCWSTR const unidata, unsigned int datalen) = 0;
        virtual bool parse(LPCWSTR const unidata, unsigned int datalen, CObject* pRootObject) = 0;
        virtual bool parse(const char *const multidata, unsigned int datalen) = 0;
        virtual bool parse(const char *const multidata, unsigned int datalen, CObject* pRootObject) = 0;

        virtual bool parsestart() = 0;
        virtual bool continueparse(LPCWSTR const unidata, unsigned int datalen, BOOL bend) = 0;
        virtual bool continueparse(const char *const multidata, unsigned int datalen, BOOL bend) = 0;
        virtual bool parseend() = 0;

        virtual bool getFeature(LPCWSTR const name) = 0;
        virtual void setFeature(LPCWSTR const name, const bool value) = 0;
        virtual void setContentHandler(CDefaultHandler* handler) = 0;
    };

}

#endif // SD_SAXREADER_H