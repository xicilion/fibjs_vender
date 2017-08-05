/*
 *  utils.h
 *  Created on: Mar 19, 2012
 *
 *  Copyright (c) 2012 by Leo Hoo
 *  lion@9465.net
 */

#ifndef _ex_utils_h__
#define _ex_utils_h__

#include <stdint.h>
#include "osconfig.h"
#include <atomic>

#ifdef Windows
#include "utils_win.h"
#elif defined(amd64)
#include "utils_x64.h"
#elif defined(i386)
#include "utils_x86.h"
#elif defined(arm64)
#include "utils_arm64.h"
#elif defined(arm)
#include "utils_arm.h"
#elif defined(mips)
#include "utils_mips.h"
#elif defined(mips64)
#include "utils_mips64.h"
#else
#error unknoen arch....
#endif

namespace exlib
{

class atomic
{
public:
	atomic() : m_v(0)
	{
	}

	atomic(intptr_t new_value) : m_v(new_value)
	{
	}

	atomic(const atomic &new_value) : m_v(new_value.m_v)
	{
	}

public:
	intptr_t operator=(intptr_t new_value)
	{
		xchg(new_value);
		return new_value;
	}

	intptr_t operator=(const atomic &new_value)
	{
		intptr_t v = new_value.m_v;

		xchg(v);
		return v;
	}

	operator intptr_t () const
	{
		return m_v;
	}

	intptr_t value() const
	{
		return m_v;
	}

	intptr_t CompareAndSwap(intptr_t old_value, intptr_t new_value)
	{
		return exlib::CompareAndSwap(&m_v, old_value, new_value);
	}

	inline intptr_t add(intptr_t incr)
	{
		return atom_add(&m_v, incr);
	}

	inline intptr_t xchg(intptr_t new_value)
	{
		return atom_xchg(&m_v, new_value);
	}

	inline intptr_t inc()
	{
		return add(1);
	}

	inline intptr_t dec()
	{
		return add(-1);
	}

private:
	volatile intptr_t m_v;
};

template<class T>
class atomic_ptr
{
public:
	atomic_ptr() : m_v(0)
	{}

	atomic_ptr(T* new_value) : m_v(new_value)
	{
	}

	atomic_ptr(const atomic_ptr &new_value) : m_v(new_value.m_v)
	{
	}

public:
	T* operator=(T* new_value)
	{
		atom_xchg(&m_v, new_value);
		return new_value;
	}

	T* operator=(const atomic_ptr &new_value)
	{
		T* v = new_value.m_v;

		atom_xchg(&m_v, v);
		return v;
	}

	operator T* () const
	{
		return m_v;
	}

	T* value() const
	{
		return m_v;
	}

	T* CompareAndSwap(T* old_value, T* new_value)
	{
		return exlib::CompareAndSwap(&m_v, old_value, new_value);
	}

	inline T* xchg(T* new_value)
	{
		return atom_xchg(&m_v, new_value);
	}

private:
	T *volatile m_v;
};

class spinlock
{
public:
	void lock()
	{
		while (m_atom.CompareAndSwap(0, -1))
			yield();
	}

	void unlock()
	{
		m_atom.xchg(0);
	}

private:
	atomic m_atom;
};

}

#ifndef ARRAYSIZE
#define ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))
#endif

#endif
