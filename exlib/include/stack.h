/*
 *  stack.h
 *  Created on: Jul 14, 2015
 *
 *  Copyright (c) 2015 by Leo Hoo
 *  lion@9465.net
 */

#include "osconfig.h"
#include "utils.h"
#include <stdio.h>

#ifndef _ex_stack_h__
#define _ex_stack_h__

namespace exlib
{

#ifdef _WIN32

extern "C" void win_switch(void *from, void *to);
#define fb_switch win_switch

extern "C" void win_save(void *now);
#define fb_save win_save

#else

extern "C" void nix_switch(void *from, void *to);
#define fb_switch nix_switch

extern "C" void nix_save(void *now);
#define fb_save nix_save

#endif

#pragma pack (1)

class context
{
public:
#if defined(x64)
    union {
        intptr_t Rbp;
        intptr_t fp;
    };
    intptr_t Rbx;
    intptr_t Rcx;
    intptr_t Rdx;
    intptr_t Rsi;
    intptr_t Rdi;
    intptr_t R12;
    intptr_t R13;
    intptr_t R14;
    intptr_t R15;
    union {
        intptr_t Rsp;
        intptr_t sp;
    };
    union {
        intptr_t Rip;
        intptr_t ip;
    };
#elif defined(I386)
    union {
        intptr_t Ebp;
        intptr_t fp;
    };
    intptr_t Ebx;
    intptr_t Ecx;
    intptr_t Edx;
    intptr_t Esi;
    intptr_t Edi;
    union {
        intptr_t Esp;
        intptr_t sp;
    };
    union {
        intptr_t Eip;
        intptr_t ip;
    };
#elif defined(arm)
    intptr_t r0;
    intptr_t r1;
    intptr_t r2;
    intptr_t r3;
    intptr_t r4;
    intptr_t r5;
    intptr_t r6;
#ifdef __thumb2__
    union {
        intptr_t r7;
        intptr_t fp;
    };
#else
    intptr_t r7;
#endif
    intptr_t r8;
    intptr_t r9;
    intptr_t r10;
#ifndef __thumb2__
    union {
        intptr_t r11;
        intptr_t fp;
    };
#else
    intptr_t r11;
#endif
    intptr_t r12;
    union {
        intptr_t r13;
        intptr_t sp;
    };
    union {
        intptr_t r14;
        intptr_t ip;
    };
#endif

public:
    void switchto(void *to)
    {
        fb_switch(this, to);
    }

    void save()
    {
        fb_save(this);
    }
};

#pragma pack ()

class trace
{
public:
    trace() : m_frame_count(0)
    {
    }

    void clear()
    {
        m_frame_count = 0;
    }

#ifndef WIN32
    void dump();
    void save(intptr_t fp = 0);
#else
    void dump()
    {}
    void save(intptr_t fp = 0)
    {}
#endif

    static void test(const char *msg, const char *file, int line)
    {
        printf("Assertion failed: %s, file %s, line %d\n", msg, file, line);

        trace tr;

        tr.save();
        tr.dump();
    }

public:
    void* m_frames[100];
    int32_t m_frame_count;
};

#ifdef NDEBUG
# define trace_assert(EX)
#else
# define trace_assert(EX) (void)((EX) || (exlib::trace::test(#EX, __FILE__, __LINE__),0))
#endif

#if defined(DEBUG) && !defined(_WIN32)
void mem_check();
void mem_diff();
void mem_savestack();
#else
inline void mem_check()
{}
inline void mem_diff()
{}
inline void mem_savestack()
{}
#endif

}

#endif
