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

#ifndef _OWPMLAPI_OWPML_SERIALIZE_MODEL_H_
#define _OWPMLAPI_OWPML_SERIALIZE_MODEL_H_

namespace OWPML
{

    class COwpmlSerializeModel
    {

    public:
        COwpmlSerializeModel();
        ~COwpmlSerializeModel();

        void PushMataTag(OWPML::CObject* object);
        std::vector<OWPML::CObject*>& GetMetaTagObjects() { return m_metaTag; }

    private:
        std::vector<OWPML::CObject*> m_metaTag;
    };

}
#endif // _OWPML_SERIALIZE_MODEL_H_