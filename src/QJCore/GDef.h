#pragma once

#include <cstdio>
#include <assert.h>

//#define QJ_DEBUG

#define QJCallback

#define QJ_INTERFACE

#define QJ_OVERRIDE override

#define QJ_UNUSE(x) (void)x;

#define QJNEW  new (std::nothrow)

#define QJSignal

#define QJSlot

#define QJ_SHOW_DEFINE( x ) QJ_TO_STRING( x )
#define QJ_TO_STRING( x ) #x

#ifdef QJ_DEBUG
#define QJASSERT assert
#else
#define QJASSERT (true)&&
#endif

#ifdef QJ_DEBUG
#define QJDELETE(obj) \
    QJASSERT(obj); \
    delete obj; \
    obj = nullptr;
#else
#define QJDELETE(obj) \
    if( obj ) \
{ \
    delete obj; \
    obj = nullptr; \
    }
#endif

#define QJLOG(x)

#define VA_ARGS_NUM(...) std::tuple_size<decltype(std::make_tuple(__VA_ARGS__))>::value

#define QJmSleep(x)\
    QJSleep::mSleep (x)

#define QJsSleep(x)\
    QJSleep::Sleep (x)



