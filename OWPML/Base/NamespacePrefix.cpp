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
#include "NamespacePrefix.h"

namespace OWPML {

    // Namespaces
    LPCWSTR str_HWPML_VERSION_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/version";
    LPCWSTR str_HWPML_APP_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/app";
    LPCWSTR str_HWPML_PARAGRAPH_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/paragraph";
    LPCWSTR str_HWPML_PARAGRAPH10_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2016/paragraph";
    LPCWSTR str_HWPML_SECTION_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/section";
    LPCWSTR str_HWPML_CORE_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/core";
    LPCWSTR str_HWPML_HEAD_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/head";
    LPCWSTR str_HWPML_HISTORY_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/history";
    LPCWSTR str_HWPML_MASTERPAGE_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2011/master-page";
    LPCWSTR str_HWPML_PACKAGEFILE_NAMESPACE = L"http://www.hancom.co.kr/schema/2011/hpf";
    LPCWSTR str_DC_NAMESPACE = L"http://purl.org/dc/elements/1.1/";
    LPCWSTR str_OPF_NAMESPACE = L"http://www.idpf.org/2007/opf/";
    LPCWSTR str_OCF_CONTAIVER_NAMESPACE = L"urn:oasis:names:tc:opendocument:xmlns:container";
    LPCWSTR str_ODF_MANIFEST_NAMESPACE = L"urn:oasis:names:tc:opendocument:xmlns:manifest:1.0";
    LPCWSTR str_ODF_CONFIG_NAMESPACE = L"urn:oasis:names:tc:opendocument:xmlns:config:1.0";
    LPCWSTR str_RDF_NAMESPACE = L"http://www.w3.org/1999/02/22-rdf-syntax-ns#";

    // alternatecontent
    LPCWSTR str_HWPML_OOXMLCHART_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2016/ooxmlchart";

    LPCWSTR str_EPUB_NAMESPACE = L"http://www.idpf.org/2007/ops";

    LPCWSTR str_DEFAULT_NAMESPACE_PREFIX = L"#";

    LPCWSTR str_HWPML_HWPUNITCHAR_NAMESPACE = L"http://www.hancom.co.kr/hwpml/2016/HwpUnitChar";

    // for Macro Conversion
#define    _CONVERT_MID(x)                                        _W(#x)
#define    _CONVERT_FINAL(x)                                    _CONVERT_MID(x)


    _PAIR_NAMESPACE_PREFIX* GetStaticNamespacePrefix(int index)
    {
        static _PAIR_NAMESPACE_PREFIX s_pairtable_NamespacePrefix[] = {
            { str_HWPML_VERSION_NAMESPACE, _CONVERT_FINAL(HWPML_VERSION_PREFIX) },
            { str_HWPML_APP_NAMESPACE, _CONVERT_FINAL(HWPML_APP_PREFIX) },
            { str_HWPML_PARAGRAPH_NAMESPACE, _CONVERT_FINAL(HWPML_PARAGRAPH_PREFIX) },
            { str_HWPML_PARAGRAPH10_NAMESPACE, _CONVERT_FINAL(HWPML_PARAGRAPH10_PREFIX) },
            { str_HWPML_SECTION_NAMESPACE, _CONVERT_FINAL(HWPML_SECTION_PREFIX) },
            { str_HWPML_CORE_NAMESPACE, _CONVERT_FINAL(HWPML_CORE_PREFIX) },
            { str_HWPML_HEAD_NAMESPACE, _CONVERT_FINAL(HWPML_HEAD_PREFIX) },
            { str_HWPML_HISTORY_NAMESPACE, _CONVERT_FINAL(HWPML_HISTORY_PREFIX) },
            { str_HWPML_MASTERPAGE_NAMESPACE, _CONVERT_FINAL(HWPML_MASTERPAGE_PREFIX) },
            { str_HWPML_PACKAGEFILE_NAMESPACE, _CONVERT_FINAL(HWPML_PACKAGEFILE_PREFIX) },
            { str_DC_NAMESPACE, _CONVERT_FINAL(DC_NAMESPACE_PREFIX) },
            { str_OPF_NAMESPACE, _CONVERT_FINAL(OPF_NAMESPACE_PREFIX) },
            { str_ODF_MANIFEST_NAMESPACE, _CONVERT_FINAL(ODF_NAMESPACE_PREFIX) },
            { str_ODF_CONFIG_NAMESPACE, _CONVERT_FINAL(ODF_CONFIG_NAMESPACE_PREFIX) },
            { str_OCF_CONTAIVER_NAMESPACE, _CONVERT_FINAL(OCF_NAMESPACE_PREFIX) },
            { str_HWPML_OOXMLCHART_NAMESPACE, _CONVERT_FINAL(HWPML_OOXMLCHART_NAMESPACE_PREFIX) },
            { str_EPUB_NAMESPACE, _CONVERT_FINAL(EPUB_NAMESPACE_PREFIX) },
            { str_RDF_NAMESPACE, _CONVERT_FINAL(RDF_NAMESPACE_PREFIX) },
            { str_HWPML_HWPUNITCHAR_NAMESPACE, _CONVERT_FINAL(HWPML_HWPUNITCHAR_NAMESPACE_PREFIX) },
            { NULL, NULL },    // end of table
        };

        return &s_pairtable_NamespacePrefix[index];
    }

}
