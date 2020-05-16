#include <exlib/include/osconfig.h>

#if defined(Darwin) || defined(Linux)
#include <dlfcn.h>
#else defined(Windows)
#include <windows.h>
#endif

#include <exlib/include/qstring.h>
#include <jssdk/jsaddons.h>

const char* ERROR_MSG_DLL_NOT_FOUND = "[%s] Unable to load lib: %s\n";
const char* ERROR_MSG_SYMBOL_NOT_FOUND = "[%s] Unable to get symbol: %s\n";

namespace js {
bool loadAddon(const char* _dll_fname, jsaddons::t_addon_retValue& addonVal)
{
    js::Api* fibjs_api = js::fibjs_api;
    if (!js::isJSRuntimeSetup())
        return false;

    exlib::string dll_fname(_dll_fname);

#if defined(Darwin) || defined(Linux)
    void* handle = dlopen(dll_fname.c_str(), RTLD_LAZY);

    if (!handle) {
        printf(ERROR_MSG_DLL_NOT_FOUND, __FILE__, dlerror());
        return false;
    }

    jsaddons::t_addon_initialize addonInitialize = (jsaddons::t_addon_initialize)dlsym(handle, jsaddons::ENTRY_POINT);

    if (!addonInitialize) {
        printf(ERROR_MSG_SYMBOL_NOT_FOUND, __FILE__, dlerror());
        return false;
    }
#else defined(Windows)
    HMODULE handle = LoadLibrary(UTF8_W(dll_fname.c_str()));
    if (!handle) {
        printf(ERROR_MSG_DLL_NOT_FOUND, __FILE__);
        return false;
    }

    jsaddons::t_addon_initialize addonInitialize = (jsaddons::t_addon_initialize)GetProcAddress(handle, "NtQueryInformationFile");
    if (!addonInitialize) {
        printf(ERROR_MSG_SYMBOL_NOT_FOUND, __FILE__);
        return false;
    }
#endif

    js::Isolate* isolate = fibjs_api->getCurrentIsolate();
    v8::Local<v8::Object> init_ctx = v8::Object::New(js::fibjs_api->getCurrentIsolate()->m_isolate);

    addonInitialize(init_ctx, addonVal);
    if (addonVal.IsEmpty()) {
        printf("addon retVal not filled! check your addon's implementation.");
        abort();
        return false;
    }

    // dlclose(handle);
    return true;
}
}