#ifdef WIN32
 #define EXPORT __declspec(dllexport)
#else
 #define EXPORT
#endif
#include "VCMP.h"
/*
    https://forum.vc-mp.org/index.php?topic=13.0
    pluginFuncs is the PluginFuncs struct from the server header, which can be used to call any function available through the plugin SDK.
    pluginCalls is a struct of PluginCallbacks. pluginCalls essentially starts off empty; your plugin must provide its own callbacks and set them in the struct in order for them to be called, and you must use the same pointer to the struct provided.
    pluginInfo is a struct of PluginInfo (from the SDK) that, again, is empty at first. You can set your plugin's version and name (max 32 characters) through it, but you must use the same pointer to the struct.
*/
extern "C" EXPORT unsigned int VcmpPluginInit( PluginFuncs* pluginFuncs, PluginCallbacks* pluginCalls, PluginInfo* pluginInfo)
{
    pluginInfo->pluginVersion   = 0x100;
    pluginInfo->apiMajorVersion = 2;
    pluginInfo->apiMinorVersion = 0;
    return 1;
}