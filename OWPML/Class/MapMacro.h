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

#ifndef _OWPML_MAP_MACRO_H_
#define _OWPML_MAP_MACRO_H_

 ////////////////////////////////////////////////////////////////////////////////////
 // Initialize Function Map 매크로

 // 1) Base
#define OWPML_FOUNDATION_REDIRECT_FUNC(parentClass, elementName, nameSpace, nsElementName) \
    static LPCWSTR _str_##nameSpace##_##elementName = _W(#nsElementName);

#define _CONVERT_OWPML_BASE_REDIRECT_FUNC(nameSpace, parentClass, elementName) \
    OWPML_FOUNDATION_REDIRECT_FUNC(parentClass, elementName, nameSpace, nameSpace:elementName)

#define _CONVERT_OWPML_BASE_REDIRECT_FUNC1(nameSpace, parentClass, elementVariableName, elementName) \
    OWPML_FOUNDATION_REDIRECT_FUNC(parentClass, elementVariableName, nameSpace, nameSpace:elementName)

#define OWPML_BASE_REDIRECT_FUNC(nameSpace, parentClass, elementName) \
    _CONVERT_OWPML_BASE_REDIRECT_FUNC(nameSpace, parentClass, elementName)

#define OWPML_BASE_REDIRECT_FUNC1(nameSpace, parentClass, elementVariableName, elementName) \
    _CONVERT_OWPML_BASE_REDIRECT_FUNC1(nameSpace, parentClass, elementVariableName, elementName)


#define _CONVERT_OWPML_BASE_ADD_REDIRECT_FUNC(nameSpace, elementName, className, elementId) \
    _funcMap.push_back(_MapElem(elementId, _str_##nameSpace##_##elementName, (CREATEFUNCTION)&className::Create));

#define OWPML_BASE_ADD_REDIRECT_FUNC(nameSpace, elementName, className, elementId) \
        _CONVERT_OWPML_BASE_ADD_REDIRECT_FUNC(nameSpace, elementName, className, elementId)

// 1-5) for non used static variable
#define OWPML_FOUNDATION_OWPML_BASE_ADD_REDIRECT_FUNC2(nsElementName, className, elementId) \
        _funcMap.push_back(_MapElem(elementId, _W(#nsElementName), &className::Create));

#define _CONVERT_OWPML_BASE_ADD_REDIRECT_FUNC2(nameSpace, elementName, className, elementId) \
        OWPML_FOUNDATION_OWPML_BASE_ADD_REDIRECT_FUNC2(nameSpace:elementName, className, elementId) \

#define OWPML_BASE_ADD_REDIRECT_FUNC2(nameSpace, elementName, className, elementId) \
        _CONVERT_OWPML_BASE_ADD_REDIRECT_FUNC2(nameSpace, elementName, className, elementId)

// 2) Begin & End Function Map
#define OWPML_BEGIN_IMPLEMENT_FUNCMAP(parentClass) \
    static _Maplist _funcMap; \
    static MapStruct _mapStruct; \
    static bool _sorted; \
    m_pMapStruct = &_mapStruct; \
    if (_funcMap.empty()) {

#define OWPML_END_IMPLEMENT_FUNCMAP() \
        _mapStruct.m_pMap = &_funcMap; \
        _mapStruct.m_pCached = NULL; \
        CExtObject::InitMap(bRead); \
        _sorted = bRead; \
    } else if (bRead != _sorted) { \
        CExtObject::InitMap(bRead); \
        _sorted = bRead; \
    }

// 3) Declare Static String & Function / Add Function Pointer
//        - Core
#define OWPML_CORE_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(HWPML_CORE_PREFIX, parentClass, elementName)

#define OWPML_CORE_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_CORE_PREFIX, elementName, className, elementId)

//        - Head
#define OWPML_HEAD_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(HWPML_HEAD_PREFIX, parentClass, elementName)

#define OWPML_HEAD_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_HEAD_PREFIX, elementName, className, elementId)

//        - History
#define OWPML_HISTORY_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(HWPML_HISTORY_PREFIX, parentClass, elementName)

#define OWPML_HISTORY_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_HISTORY_PREFIX, elementName, className, elementId)

//        - Application
#define OWPML_APPLICATION_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(HWPML_APP_PREFIX, parentClass, elementName)

#define OWPML_APPLICATION_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_APP_PREFIX, elementName, className, elementId)

//        - Paralist
#define OWPML_PARALIST_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(HWPML_PARAGRAPH_PREFIX, parentClass, elementName)

#define OWPML_PARALIST_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_PARAGRAPH_PREFIX, elementName, className, elementId)

#define OWPML_OPF_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(OPF_NAMESPACE_PREFIX, parentClass, elementName)

#define OWPML_OCF_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(OCF_NAMESPACE_PREFIX, parentClass, elementName)

#define OWPML_ODF_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(ODF_NAMESPACE_PREFIX, parentClass, elementName)

#define OWPML_ODF_REDIRECT_FUNC1(parentClass, elementVariableName, elementName) \
    OWPML_BASE_REDIRECT_FUNC1(ODF_NAMESPACE_PREFIX, parentClass, elementVariableName, elementName)

#define OWPML_ODFCONFIG_REDIRECT_FUNC1(parentClass, elementVariableName, elementName) \
    OWPML_BASE_REDIRECT_FUNC1(ODF_CONFIG_NAMESPACE_PREFIX, parentClass, elementVariableName, elementName)

#define OWPML_HPF_REDIRECT_FUNC(parentClass, elementName) \
    OWPML_BASE_REDIRECT_FUNC(HWPML_PACKAGEFILE_PREFIX, parentClass, elementName)

// RDF
#define OWPML_RDF_REDIRECT_FUNC(parentClass, elementName) \
        OWPML_BASE_REDIRECT_FUNC(RDF_NAMESPACE_PREFIX, parentClass, elementName)


#define OWPML_OCF_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(OCF_NAMESPACE_PREFIX, elementName, className, elementId)

#define OWPML_OPF_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(OPF_NAMESPACE_PREFIX, elementName, className, elementId)

#define OWPML_ODF_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(ODF_NAMESPACE_PREFIX, elementName, className, elementId)

#define OWPML_ODFCONFIG_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(ODF_CONFIG_NAMESPACE_PREFIX, elementName, className, elementId)

#define OWPML_HPF_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(HWPML_PACKAGEFILE_PREFIX, elementName, className, elementId)

// RDF
#define OWPML_RDF_ADD_REDIRECT_FUNC(elementName, className, elementId) \
        OWPML_BASE_ADD_REDIRECT_FUNC(RDF_NAMESPACE_PREFIX, elementName, className, elementId)

#endif // _OWPML_MAP_MACRO_H_