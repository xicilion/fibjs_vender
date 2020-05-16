/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-05 01:13:31
 * @modify date 2020-05-05 01:13:31
 * @desc jssdk's fiber runtime for fibjs
 */

#ifndef _jssdk_utils_h__
#define _jssdk_utils_h__

#ifndef EXTERN_C_START
#if __cplusplus
#define EXTERN_C_START extern "C" {
#else
#define EXTERN_C_START
#endif
#endif // EXTERN_C_START

#ifndef EXTERN_C_END
#if __cplusplus
#define EXTERN_C_END }
#else
#define EXTERN_C_END
#endif
#endif // EXTERN_C_START

// If you need __declspec(dllimport), either include <jssdk/include/jssdk-fibjs.h> instead, or
// define FAPI_EXTERN as __declspec(dllimport) on the compiler's command line.
#ifndef FAPI_EXTERN
#ifdef _WIN32
#define FAPI_EXTERN __declspec(dllexport)
#else
#define FAPI_EXTERN __attribute__((visibility("default")))
#endif
#endif // FAPI_EXTERN

EXTERN_C_START

FAPI_EXTERN const char* fapi_hello();

EXTERN_C_END

#endif // _jssdk_utils_h__