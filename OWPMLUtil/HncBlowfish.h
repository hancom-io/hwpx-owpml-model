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

#ifndef _BLOWFISH_H
#define _BLOWFISH_H
#include "HncDefine.h"

typedef void* HNC_BF_INFO;

HNC_BF_INFO HNC_BF_Create(void);
void        HNC_BF_Init(HNC_BF_INFO AlgInfo, bool bdecode, const char* key, uint32_t keylen, const char* arg, uint32_t arglen);
void        HNC_BF_Update(HNC_BF_INFO AlgInfo, bool bdecode, const char* data, uint32_t datLen, char* buffer, uint32_t bufferlen);
void        HNC_BF_Final(HNC_BF_INFO AlgInfo);

#endif    //    _BLOWFISH_H
