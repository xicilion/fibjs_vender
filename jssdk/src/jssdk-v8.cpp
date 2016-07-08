/*
 *  jssdk-v8.cpp
 *  Created on: Mar 31, 2016
 *
 *  Copyright (c) 2016 by Leo Hoo
 *  lion@9465.net
 */

#include "jssdk-v8.h"
#include "libplatform/libplatform.h"
#include <stdlib.h>
#include <string.h>

namespace js
{

class v8_Runtime : public Runtime
{
private:
	class ShellArrayBufferAllocator : public v8::ArrayBuffer::Allocator
	{
	public:
		virtual void* Allocate(size_t length)
		{
			void* data = AllocateUninitialized(length);
			return data == NULL ? data : memset(data, 0, length);
		}

		virtual void* AllocateUninitialized(size_t length)
		{
			return malloc(length);
		}

		virtual void Free(void* data, size_t)
		{
			free(data);
		}
	};

public:
	v8_Runtime()
	{
		create_params.array_buffer_allocator = &array_buffer_allocator;
		m_isolate = v8::Isolate::New(create_params);

		v8::Locker locker(m_isolate);
		v8::HandleScope handle_scope(m_isolate);
		v8::Isolate::Scope isolate_scope(m_isolate);

		m_context.Reset(m_isolate, v8::Context::New(m_isolate));

		// v8::Number::New(m_isolate, 100);
	}

public:
	void destroy()
	{
		m_isolate->Dispose();
		delete this;
	}

	void Locker_enter(Locker& locker)
	{
		new (locker.m_locker) v8::Locker(m_isolate);
	}

	void Locker_leave(Locker& locker)
	{
		((v8::Locker*)locker.m_locker)->~Locker();
	}

	void Unlocker_enter(Unlocker& unlocker)
	{
		new (unlocker.m_unlocker) v8::Unlocker(m_isolate);
	}

	void Unlocker_leave(Unlocker& unlocker)
	{
		((v8::Unlocker*)unlocker.m_unlocker)->~Unlocker();
	}

	void Scope_enter(Scope& scope)
	{
		class HandleScope : public v8::HandleScope
		{
		public:
			HandleScope(v8::Isolate *rt) : v8::HandleScope(rt)
			{}

		public:
			static void *operator new(size_t, void * p)
			{
				return p;
			}
		};

		new (scope.m_locker) v8::Locker(m_isolate);
		new (scope.m_handle_scope) HandleScope(m_isolate);
		m_isolate->Enter();
		v8::Local<v8::Context>::New(m_isolate, m_context)->Enter();
	}

	void Scope_leave(Scope& scope)
	{
		v8::Local<v8::Context>::New(m_isolate, m_context)->Exit();
		m_isolate->Exit();
		((v8::HandleScope*)scope.m_handle_scope)->~HandleScope();
		((v8::Locker*)scope.m_locker)->~Locker();
	}

	Value NewNumberValue(double d)
	{
		return Value(v8::Number::New(m_isolate, d));
	}

	Value execute(const char* code, int32_t size, const char* soname)
	{
		v8::Local<v8::Context> context = v8::Context::New(m_isolate);
		v8::Local<v8::String> str = v8::String::NewFromUtf8(m_isolate,
		                            code, v8::String::kNormalString, size);
		v8::Local<v8::Script> script = v8::Script::Compile(str,
		                               v8::String::NewFromUtf8(m_isolate, code));

		return Value(script->Run(context).ToLocalChecked());
	}

private:
	v8::Isolate *m_isolate;
	v8::Persistent<v8::Context> m_context;

	v8::Isolate::CreateParams create_params;
	ShellArrayBufferAllocator array_buffer_allocator;
};

class Api_v8 : public Api
{
public:
	virtual const char* getEngine()
	{
		return "v8";
	}

	virtual int32_t getVersion()
	{
		return version;
	}

	virtual void init()
	{
		v8::Platform *platform = v8::platform::CreateDefaultPlatform();
		v8::V8::InitializePlatform(platform);

		v8::V8::Initialize();
	}

	virtual Runtime* createRuntime()
	{
		return new v8_Runtime();
	}

	double ValueToNumber(Value& v)
	{
		return v.m_v->NumberValue();
	}
};

static Api_v8 s_api;
Api* _v8_api = &s_api;

}