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

#ifndef _NAMESPACE_PREFIX_H_
#define _NAMESPACE_PREFIX_H_

namespace OWPML {

    ////////////////////////////////////////////////////////////////////////////////////////////////
    // Namespace & Prefix                                                                         //

    // version
#define HWPML_VERSION_PREFIX                                            hv
    extern LPCWSTR str_HWPML_VERSION_NAMESPACE;

    // app
#define HWPML_APP_PREFIX                                                ha
    extern LPCWSTR str_HWPML_APP_NAMESPACE;

    // paragraph
#define HWPML_PARAGRAPH_PREFIX                                            hp
    extern LPCWSTR str_HWPML_PARAGRAPH_NAMESPACE;

#define HWPML_PARAGRAPH10_PREFIX                                        hp10
    extern LPCWSTR str_HWPML_PARAGRAPH10_NAMESPACE;

    // section
#define HWPML_SECTION_PREFIX                                            hs
    extern LPCWSTR str_HWPML_SECTION_NAMESPACE;

    // core
#define HWPML_CORE_PREFIX                                                hc
    extern LPCWSTR str_HWPML_CORE_NAMESPACE;

    // head
#define HWPML_HEAD_PREFIX                                                hh
    extern LPCWSTR str_HWPML_HEAD_NAMESPACE;

    // history
#define HWPML_HISTORY_PREFIX                                            hhs
    extern LPCWSTR str_HWPML_HISTORY_NAMESPACE;

    // master-page
#define HWPML_MASTERPAGE_PREFIX                                            hm
    extern LPCWSTR str_HWPML_MASTERPAGE_NAMESPACE;

    // Package file
#define HWPML_PACKAGEFILE_PREFIX                                        hpf
    extern LPCWSTR str_HWPML_PACKAGEFILE_NAMESPACE;

    // Shared - Dublin Core
#define DC_NAMESPACE_PREFIX                                                dc
    extern LPCWSTR str_DC_NAMESPACE;

    // Shared - opf
#define OPF_NAMESPACE_PREFIX                                            opf
    extern LPCWSTR str_OPF_NAMESPACE;

    // Shared - odf
#define ODF_NAMESPACE_PREFIX                                            odf
    extern LPCWSTR str_ODF_MANIFEST_NAMESPACE;

#define OCF_NAMESPACE_PREFIX                                            ocf                            
    extern LPCWSTR str_OCF_CONTAIVER_NAMESPACE;

#define RDF_NAMESPACE_PREFIX                                            rdf
    extern LPCWSTR str_RDF_NAMESPACE;

#define ODF_CONFIG_NAMESPACE_PREFIX                                        config
    extern LPCWSTR str_ODF_CONFIG_NAMESPACE;

    // alternatecontent
#define HWPML_OOXMLCHART_NAMESPACE_PREFIX                                ooxmlchart
    extern LPCWSTR str_HWPML_OOXMLCHART_NAMESPACE;

    // epub
#define EPUB_NAMESPACE_PREFIX                                            epub
    extern LPCWSTR    str_EPUB_NAMESPACE;

    // HwpUnitChar
#define HWPML_HWPUNITCHAR_NAMESPACE_PREFIX                                hwpunitchar
    extern LPCWSTR str_HWPML_HWPUNITCHAR_NAMESPACE;


    // user default ("#")
    extern LPCWSTR str_DEFAULT_NAMESPACE_PREFIX;


    // [Namespace - Prefix] Pair Table
    typedef struct namespace_prefix
    {
        LPCWSTR nameSpace;
        LPCWSTR prefixStr;
    } _PAIR_NAMESPACE_PREFIX;


    _PAIR_NAMESPACE_PREFIX* GetStaticNamespacePrefix(int index);

    //extern _PAIR_NAMESPACE_PREFIX s_pairtable_NamespacePrefix[];

}

#endif    // _NAMESPACE_PREFIX_H_
