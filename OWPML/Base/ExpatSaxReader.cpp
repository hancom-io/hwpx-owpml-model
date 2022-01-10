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

#include "Object.h"
#include "DefaultHandler.h"
#include "Attribute.h"
#include "Handler.h"
#include "ExpatSax.h"
#include "ExpatDefaultHandler.h"

#include "SaxReader.h"
#include "ExpatSaxReader.h"

namespace OWPML {

    CExpatSaxReader::CExpatSaxReader(void)
        : m_pHandler(NULL)
        , m_parser(NULL)
    {
    }

    CExpatSaxReader::~CExpatSaxReader(void)
    {
        if (m_pHandler) {
            delete m_pHandler;
            m_pHandler = NULL;
        }
    }

    bool CExpatSaxReader::parse(LPCWSTR const path)
    {
        bool res = false;
        m_parser = XML_ParserCreateNS(NULL, L':');

        if (m_parser) {
            m_pHandler->startDocument(m_pHandler);

            m_pHandler->SetHandler(m_parser);

            res = fileparse(path, m_parser);
            XML_ParserFree(m_parser);

            if (res)
                m_pHandler->endDocument(m_pHandler);
        }

        return res;
    }

    bool CExpatSaxReader::parse(LPCWSTR const path, CObject* pRootObject)
    {
        CRootObjFactory* pnewfactory = NULL;
        CHandler sdhander;

        setContentHandler(&sdhander);
        pnewfactory = new CRootObjFactory(pRootObject);

        sdhander.AddFactory(pnewfactory);

        return parse(path);
    }

    bool CExpatSaxReader::parse(LPCWSTR const unidata, unsigned int datalen)
    {
        return parse((const char *const)unidata, datalen * sizeof(WCHAR));
    }

    bool CExpatSaxReader::parse(LPCWSTR const unidata, unsigned int datalen, CObject* pRootObject)
    {
        return parse((const char *const)unidata, datalen * sizeof(WCHAR), pRootObject);
    }

    bool CExpatSaxReader::parse(const char *const multidata, unsigned int datalen)
    {
        bool res = false;
        m_parser = XML_ParserCreateNS(NULL, L':');

        if (m_parser) {
            m_pHandler->startDocument(m_pHandler);

            m_pHandler->SetHandler(m_parser);

            if (XML_Parse(m_parser, multidata, datalen, 1) != XML_STATUS_ERROR) {
                res = true;
            }

            XML_ParserFree(m_parser);

            if (res)
                m_pHandler->endDocument(m_pHandler);
        }

        return res;
    }

    bool CExpatSaxReader::parse(const char *const multidata, unsigned int datalen, CObject* pRootObject)
    {
        CRootObjFactory* pnewfactory = NULL;
        CHandler sdhander;

        setContentHandler(&sdhander);
        pnewfactory = new CRootObjFactory(pRootObject);
        sdhander.AddFactory(pnewfactory);

        return parse(multidata, datalen);
    }

    bool CExpatSaxReader::parsestart()
    {
        m_parser = XML_ParserCreateNS(NULL, L':');

        if (m_parser) {
            m_pHandler->startDocument(m_pHandler);
            m_pHandler->SetHandler(m_parser);
            return true;
        }

        return false;
    }

    bool CExpatSaxReader::continueparse(LPCWSTR const unidata, unsigned int datalen, BOOL bend)
    {
        return continueparse((const char *const)unidata, datalen * sizeof(WCHAR), bend);
    }

    bool CExpatSaxReader::continueparse(const char *const multidata, unsigned int datalen, BOOL bend)
    {
        if (m_parser) {
            if (XML_Parse(m_parser, multidata, datalen, bend ? 1 : 0) != XML_STATUS_ERROR) {
                return true;
            }
        }
        return false;
    }

    bool CExpatSaxReader::parseend()
    {
        if (m_parser) {
            XML_ParserFree(m_parser);
            m_pHandler->endDocument(m_pHandler);
            return true;
        }
        return false;
    }

    bool CExpatSaxReader::getFeature(LPCWSTR const /*name*/)
    {
        return false;
    }

    void CExpatSaxReader::setFeature(LPCWSTR const /*name*/, const bool /*value*/)
    {
    }

    void CExpatSaxReader::setContentHandler(CDefaultHandler* handler)
    {
        if (m_pHandler) {
            m_pHandler->SetDefaultHandler(handler);
            return;
        }
        m_pHandler = new CExpatDefaultHandler(handler);
    }

    bool CExpatSaxReader::fileparse(LPCWSTR const path, XML_Parser parser)
    {
        static int readsize = 200;
        FILE* fd = NULL;

        if (path == NULL)
            return false;

        if (_wfopen_s(&fd, path, L"rb") != 0)
            return false;

        if (fd == NULL)
            return false;

        for (;;) {
            int nread;
            char *buf = (char *)XML_GetBuffer(parser, readsize);
            if (!buf) {
                fclose(fd);
                return false;
            }
            nread = fread(buf, 1, readsize, fd);
            if (nread < 0) {
                fclose(fd);
                return false;
            }
            if (XML_ParseBuffer(parser, nread, nread == 0) == XML_STATUS_ERROR) {
                fclose(fd);
                return false;
            }
            if (nread == 0) {
                fclose(fd);
                break;
            }
        }
        return true;
    }

    CSaxReader*  CreateSaxReader(void)
    {
        CExpatSaxReader* pExpatSaxReader = new CExpatSaxReader;

        return pExpatSaxReader;
    }

    void ReleaseSaxReader(CSaxReader* preader)
    {
        CExpatSaxReader* pExpatSaxReader = static_cast<CExpatSaxReader*>(preader);

        if (pExpatSaxReader) {
            delete pExpatSaxReader;

            pExpatSaxReader = NULL;
        }
    }

}
