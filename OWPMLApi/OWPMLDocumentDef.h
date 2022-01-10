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

#ifndef _OWPMLAPI_OWPML_DOCUMENT_DEF_H_
#define _OWPMLAPI_OWPML_DOCUMENT_DEF_H_

#define MIMETYPE_FILENAME            L"mimetype"
#define VERSION_FILENAME             L"version.xml"
#define SETTINGS_FILENAME            L"settings.xml"
#define CONTENT_FILENAME             L"Contents/content.hpf"
#define HEADER_FILENAME              L"Contents/header.xml"
#define CONTAINER_FILENAME           L"META-INF/container.xml"
#define MANIFEST_FILENAME            L"META-INF/manifest.xml"
#define SIGNATURES_FILENAME          L"META-INF/signatures.xml"
#define PREVEWTEXT_FILENAME          L"Preview/PrvText.txt"
#define PREVEWIMAGE_FILENAME         L"Preview/PrvImage.png"
#define HEADERSCRIPTS_FILENAME       L"Scripts/headerScripts.js"
#define SOURCESCRIPTS_FILENAME       L"Scripts/sourceScripts.js"
#define PRESCRIPTS_FILENAME          L"Scripts/preScripts.js"
#define POSTSCRIPTS_FILENAME         L"Scripts/postScripts.js"
#define XMLTEMPLATESCHEMANAME_FILENAME  L"XMLTemplate/TemplateSchemaName.txt"
#define XMLTEMPLATESCHEMA_FILENAME  L"XMLTemplate/TemplateSchema.xsd"
#define XMLTEMPLATEINSTANCE_FILENAME  L"XMLTemplate/TemplateInstance.xml"
#define HISTORYLASTDOC_FILENAME      L"DocHistory/historylastdoc.hml"
#define BIBLIOGRAPHY_FILENAME        L"Custom/bibliography.xml"
#define RDF_FILENAME                 L"META-INF/container.rdf"
#define CSVTABLE_FILENAME            L"tablecache.csv"

// ref id
#define APP_JAVASCRIPT_TYPE          L"application/x-javascript"
#define APP_XML_TYPE                 L"application/xml"
#define APP_TEXT_TYPE                L"text/xml"
#define APP_HML_TYPE                 L"application/hancomhml"
#define APP_RDF_TYPE                 L"application/rdf+xml"
#define APP_TEXTPLAIN_TYPE           L"text/plain"
#define TYPE_CHARSET_UTF16           L"charset=utf-16"

#define HEADER_ID                    L"header"
#define SETTINGS_ID                  L"settings"
#define HEADER_SCRIPT_ID             L"headersc"         // headerscript
#define SOURCE_SCRIPT_ID             L"sourcesc"         // sourcescript
#define PRE_SCRIPT_ID                L"presc"            // prescript
#define POST_SCRIPT_ID               L"postsc"           // postscript
#define XMLTEMPLATE_SCHEMA_NAME_ID   L"xmltemplateschemaname"
#define XMLTEMPLATE_SCHEMA_ID        L"xmltemplateschema"
#define XMLTEMPLATE_INSTANCE_ID      L"xmltemplateinstance"
#define SECTION_ID_FORMAT            L"section%d"
#define VERSION_LOG_ID_FORMAT        L"versionlog%d"
#define HISTORY_LASTDOC_ID           L"historylastdoc"
#define CHART_ID_FORMAT              L"chart%d"
#define CHART_FILENAME_FORMAT        L"chart/chart%d.xml"
#define BIBLIOGRAPHY_ID              L"bibliography"

// 표준 표맷 version
#define XML_VERSION                  L"1.31" // 21.05.27 이후 버전, Hwpx 필터 문제 수정 (여백 등에서 글자(ch)로 저장시 pt로 저장되는 문제) 
#define APPLICATION_NAME             L"Hancom Office Hangul"

#define PROGRESS_MAX_POS             1000

#endif // _OWPMLAPI_OWPML_DOCUMENT_DEF_H_