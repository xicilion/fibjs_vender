/**
 * @author Richard
 * @email richardo2016@mail.com
 * @create date 2020-05-05 16:25:35
 * @modify date 2020-05-05 16:25:35
 * @desc addons definitions
 */

#ifndef _jssdk_addons_h_
#define _jssdk_addons_h_

#include <exlib/include/osconfig.h>
#include <exlib/include/qstring.h>

#include <v8/include/v8.h>
#include "libplatform/libplatform.h"

#include <exlib/include/qstring.h>

#ifdef _WIN32
// Building native module against fibjs
#define FAPI_EXTERN __declspec(dllexport)
#endif

#include <jssdk/include/jssdk-fibjs.h>

namespace jsaddons {

const char* DLL_PREFIX = "Addon_";
const char* ENTRY_POINT = "addonEntry";

typedef v8::Local<v8::Object>& t_init_context_value_ref;
typedef v8::Local<v8::Value> t_addon_retValue;
typedef void (*t_addon_initialize)(t_init_context_value_ref ctx, t_addon_retValue& retAddonVal);
typedef void (*t_internal_init_callback)(t_init_context_value_ref ctx, t_addon_retValue& retAddonVal);

inline void OnInitialize(t_internal_init_callback init_cb, t_init_context_value_ref init_ctx, t_addon_retValue& retAddonVal)
{
    js::Api* fibjs_api = js::fibjs_api;

    js::Runtime* js_runtime = fibjs_api->getCurrentJSRuntime();

    if (js_runtime == NULL)
        return;

    js::Isolate* isolate = fibjs_api->getCurrentIsolate();

    js::Object init_ctx_obj = js::Object(js_runtime, init_ctx);

    js::Object(js_runtime, init_ctx);

    init_cb(init_ctx, retAddonVal);
}
}

/**
 * Define your own addon by macro FIBJS_ADDON,
 *
 * you can add module for fibjs, where all Sandbox would install the module.
 *
 */
#define FIBJS_ADDON_QUOTE(name) #name
#define FIBJS_ADDON(init_cb)                                                                              \
    extern "C" {                                                                                          \
    FAPI_EXTERN                                                                                           \
    void addonEntry(jsaddons::t_init_context_value_ref init_ctx, jsaddons::t_addon_retValue& retAddonVal) \
    {                                                                                                     \
        jsaddons::OnInitialize(init_cb, init_ctx, retAddonVal);                                           \
    };                                                                                                    \
    }

#endif // _jssdk_addons_h_