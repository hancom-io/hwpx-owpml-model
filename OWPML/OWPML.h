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

#ifndef _OWPML_H_
#define _OWPML_H_

#define XML_UNICODE_WCHAR_T

#include "OWPML/Base/Object.h"
#include "OWPML/Base/SaxReader.h"
#include "OWPML/Base/Serialize.h"
#include "OWPML/Base/XMLSerializer.h"
#include "OWPML/Base/DefaultHandler.h"
#include "OWPML/Base/Handler.h"
#include "OWPML/Base/Attribute.h"
#include "OWPML/Zip/encrypt.h"
#include "OWPML/Zip/SDZip.h"
#include "OWPML/Document.h"
#include "OWPML/Class/classinclude.h"

#ifdef OS_WIN
#ifdef _DEBUG
#pragma comment(lib, "Owpmld.Lib")
#else
#pragma comment(lib, "Owpml.Lib")
#endif
#endif // OS_WIN
#endif // _OWPML_H_