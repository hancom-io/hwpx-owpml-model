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
#ifndef _OBJECT_H_
#define _OBJECT_H_

namespace OWPML {

    //interface IPart;
    class IPart;
    class CAttribute;
    class CSerializer;
    class CMetaTag;

    // CObject를 상속한 각 concrete class의 Create함수는 반환타입이 모두 CObject* 임(함수포인터에 넣기 위해).
    // concrete class의 Create()를 호출하고 나온 CObject* 개체를 concrete class type으로 캐스팅하여 redirection하는 템플릿함수.
    template <class _UserClass>
    _UserClass* _Create()
    {
        return static_cast<_UserClass*>(_UserClass::Create());
    }

    class CObject;
    typedef CObject* (*CREATEFUNCTION)();

    typedef struct tagCreantFunctionSet
    {
        tagCreantFunctionSet() : pfucnion(NULL), id(0) {}

        CREATEFUNCTION pfucnion;
        unsigned int id;
    } CREATEFUNCSET;

    typedef std::vector<CObject*> Objectlist;

    /////////////////////////////////////////////////////////////////////////////////////
    // CObject Declaration
    class CObject
    {
    private: // 기본 생성자를 사용하지 못하게 private로 지정
        CObject()
            : m_ErrorCode(0), m_pRootpart(NULL), m_pParent(NULL)
        {}

    protected:
        CObject(unsigned int id);
    public:
        virtual ~CObject();
        virtual CObject* Clone(void) { return NULL; }

    public:
        unsigned int GetID() const { return m_ID; }
        void SetObjectID(unsigned int id) { m_ID = id; }

        // Funcs for Part
        void SetRootpart(IPart* part) { m_pRootpart = part; }
        IPart* GetRootpart(void) const { return m_pRootpart; }
        void SetReNewRootPart(IPart* part);

        // CExtObject 에 구현되어 있음.
        virtual void InitMap(bool /*bRead*/) {}
        virtual void SetObject(CObject* /*pobject*/, BOOL /*bAutoSet*/ = TRUE) {}
        virtual CObject* CreateObject(LPCWSTR /*elename*/, BOOL /*bAutoSet*/ = TRUE) { return NULL; }
        virtual Objectlist* GetObjectList() const { return NULL; }
        virtual CObject* GetObjectByID(unsigned int /*id*/, int /*index*/ = 0) const { return NULL; }
        virtual CObject* GetObjectByIndex(unsigned int /*index*/) const { return NULL; }
        virtual size_t GetObjectListByID(unsigned int /*id*/, Objectlist& /*objectlist*/) const { return 0; }
        virtual size_t GetObjectCountByID(unsigned int /*id*/) const { return 0; }
        virtual bool HasChildList(void) const { return false; }
        virtual LPCWSTR FindObjectName(CObject* /*pChildObj*/) { return NULL; }
        virtual BOOL IsDrawingObject(void) const { return FALSE; }
        virtual BOOL HasAnyelement(void) const { return FALSE; }
        virtual void SetObjectList(Objectlist* /*objectlist*/) {}

        virtual CObject* ChildElementCreate(LPCWSTR const /*qname*/, const CAttribute* /*attrs*/) { return NULL; }

        // AlternateContent를 위한 함수
        virtual void SetParentObj(CObject* pParent) { m_pParent = pParent; }
        CObject* GetParentObj(void) { return m_pParent; }

        virtual LPCWSTR GetElemName() const { return NULL; }

        static void Delete(CObject* pObject);

    public: // read, write funcion
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
        virtual bool ReadNodeValue(LPCWSTR const value, const unsigned int length);

        // Unknown Element를 유지시킬지 여부
    public:
        typedef std::vector<hncstd::wstring> MaintainElementList;
        virtual bool IsMaintainObject() { return FALSE; }
        virtual MaintainElementList* GetMaintainElementList() { return NULL; }

    public:
        void SetErrorCode(UINT error) { m_ErrorCode = error; }
        UINT GetErrorCode() const { return m_ErrorCode; }

        //bool IsMetaTagVaild(jsonUI::HwpJson* pMetaTag);
        //void SetMetaTag(jsonUI::HwpJson* pMetaTag);
        //CMetaTag* SetMetaTag(CMetaTag* meta = NULL);

    private:
        unsigned int m_ID = 0;
        IPart* m_pRootpart;

    private:
        // Error Handling은 각 App에 위임
        // 0 : NO ERROR
        // 1 : ERROR
        // 2 : FATAL ERROR    
        // 3 : WARNING
        UINT m_ErrorCode;

        CObject* m_pParent;
    };


    /////////////////////////////////////////////////////////////////////////////////////
    // CExtObject Declaration
    class CExtObject : public CObject
    {
    protected:
        CExtObject(unsigned int id);

    public:
        virtual ~CExtObject();

    protected:
        class _MapElem
        {
        public:
            _MapElem(UINT id, LPCWSTR name, CREATEFUNCTION func)
                : elemId(id), elemName(name), elemFunc(func)
            {}

        public:
            // comparing function object class
            class _foSortById
            {
            public:
                bool operator() (const _MapElem& val1, const _MapElem& val2) const
                {
                    return (val1.elemId < val2.elemId) ? true : false;
                }
            };

            class _foSortByName
            {
            public:
                bool operator() (const _MapElem& val1, const _MapElem& val2) const
                {
                    return (_ustrcmp(val1.elemName, val2.elemName) < 0) ? true : false;
                }
            };

        public:
            UINT            elemId;
            LPCWSTR         elemName;
            CREATEFUNCTION  elemFunc;
        };

        typedef std::vector<_MapElem> _Maplist;

        struct MapStruct
        {
            _Maplist* m_pMap;
            _MapElem* m_pCached;
        };

    public:
        virtual void InitMap(bool bRead);
        virtual void SetObject(CObject* pobject, BOOL bAutoSet = TRUE);
        virtual CObject* CreateObject(LPCWSTR elename, BOOL bAutoSet = TRUE);
        virtual Objectlist* GetObjectList() const { return m_pObjectList; }
        virtual CObject* GetObjectByID(unsigned int id, int index = 0) const;
        virtual CObject* GetObjectByIndex(unsigned int index = 0) const;
        virtual size_t GetObjectListByID(unsigned int id, Objectlist& objectlist) const;
        virtual size_t GetObjectCountByID(unsigned int id) const;
        virtual bool HasChildList(void) const;
        virtual LPCWSTR FindObjectName(CObject* pChildObj);
        unsigned int GetChildCount(void) const;
        CObject* GetParentObject(void) const;
        void SetObjectList(Objectlist* objectlist);
    protected:
        MapStruct* m_pMapStruct;

    private:
        Objectlist* m_pObjectList;
    };


    /////////////////////////////////////////////////////////////////////////////////////
    // CNamedObject Declaration
    class CNamedObject : public CExtObject
    {
    protected:
        CNamedObject(unsigned int id);

    public:
        virtual ~CNamedObject();

    public:
        void SetElemName(LPCWSTR elename);
        virtual LPCWSTR GetElemName() const;

    private:
        hncstd::wstring m_elemName;
    };


    /////////////////////////////////////////////////////////////////////////////////////
    // CCustomObject Declaration
    class CCustomObject : public CNamedObject
    {
    protected:
        CCustomObject(unsigned int id);

    public:
        virtual ~CCustomObject();

    public:
        virtual CObject* CreateObject(LPCWSTR elename, BOOL bAutoSet = TRUE);

    public: // read, write function
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);
        virtual bool ReadAttribute(CAttribute* att);
    };


    //////////////////////////////////////////////////////
    // CValueObject Declaration
    template<class _ValType, class _RtnType>
    class CValueObject : public CObject
    {
    protected:
        CValueObject(unsigned int id) : CObject(id) {}

    public:
        virtual ~CValueObject() {}

    protected:
        virtual bool ReadNodeValue(LPCWSTR const /*value*/, const unsigned int /*length*/) { _ASSERT(FALSE); return false; /*Read 함수를 오버라이딩 할것!*/ }
        virtual bool WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* /*att*/) { _ASSERT(FALSE); return false; /*Write 함수를 오버라이딩 할것!*/ }

    public:
        void Setval(_RtnType val) { m_val = val; }
        _RtnType Getval() const { return m_val; }

    protected:
        _ValType m_val;
    };


    //////////////////////////////////////////////////////
    // CValueObject Declaration
    template<>
    class CValueObject<hncstd::wstring, LPCWSTR> : public CObject
    {
    protected:
        CValueObject(unsigned int id) : CObject(id) {}

    public:
        virtual ~CValueObject() {}

    protected:
        virtual bool ReadNodeValue(LPCWSTR const /*value*/, const unsigned int /*length*/) { _ASSERT(FALSE); return false; /*Read 함수를 오버라이딩 할것!*/ }
        virtual bool WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* /*att*/) { _ASSERT(FALSE); return false; /*Write 함수를 오버라이딩 할것!*/ }

    public:
        void Setval(LPCWSTR val) { m_val = val; }
        LPCWSTR Getval() const { return m_val.c_str(); }

    protected:
        hncstd::wstring m_val;
    };


    //////////////////////////////////////////////////////
    // CExtValueObject Declaration
    template<class _ValType, class _RtnType>
    class CExtValueObject : public CExtObject
    {
    protected:
        CExtValueObject(unsigned int id) : CExtObject(id) {}

    public:
        virtual ~CExtValueObject() {}

    protected:
        virtual bool ReadNodeValue(LPCWSTR const /*value*/, const unsigned int /*length*/) { _ASSERT(FALSE); return false; /*Read 함수를 오버라이딩 할것!*/ }
        virtual bool WriteElement(LPCWSTR /*pCurObjName*/, CSerializer* /*serialize*/, CAttribute* /*att*/) { _ASSERT(FALSE); return false; /*Write 함수를 오버라이딩 할것!*/ }

    public:
        void Setval(_RtnType val) { m_val = val; }
        _RtnType Getval() const { return m_val; }

    protected:
        _ValType m_val;
    };

    //////////////////////////////////////////////////////
    // CStringValueObject Declaration
    class CStringValueObject : public CValueObject<hncstd::wstring, LPCWSTR>
    {
    protected:
        CStringValueObject(unsigned int id) : CValueObject<hncstd::wstring, LPCWSTR>(id) {}

    public:
        static CObject* Create(unsigned int id);
        virtual ~CStringValueObject() {}

    public:
        virtual bool ReadNodeValue(LPCWSTR const value, const unsigned int length);
        virtual bool WriteElement(LPCWSTR pCurObjName, CSerializer* serialize, CAttribute* att);

    public:
    };


}
#endif //_OBJECT_H_
