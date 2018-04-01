#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include "ISteamClient/ISteamClient017.h"

#include "CCallback.h"
#include "callbacks.h"
#include "debug.h"
#include "os/os.h"
#include "setup_ifaces.h"
#include "steam.h"
#include "steam_api.h"
#include "steam_gameserver.h"

static steam_bool_t is_init = STEAM_FALSE;

EXPORT steam_bool_t SteamAPI_Init(void)
{
	LOG_ENTER0("()");

	if (is_init)
		return STEAM_TRUE;

	is_init = STEAM_TRUE;

	dsa_set_default_interfaces_version();

	g_pSteamClientGameServer = SteamClient();

	return STEAM_TRUE;
}

EXPORT steam_bool_t SteamAPI_InitSafe(void)
{
	LOG_ENTER0("()");

	return SteamAPI_Init();
}

EXPORT steam_bool_t SteamAPI_IsSteamRunning(void)
{
	LOG_ENTER0("()");

	return STEAM_TRUE;
}

EXPORT void SteamAPI_Shutdown(void)
{
	LOG_ENTER0("()");

	if (!is_init)
		return;

	is_init = STEAM_FALSE;

	g_pSteamClientGameServer = INVAL_PTR;
}

EXPORT steam_bool_t SteamAPI_RestartAppIfNecessary(steam_app_id_t app_id)
{
	LOG_ENTER("(app_id = %u)", app_id);

	/* The app was started through the Steam client. */
	return STEAM_FALSE;
}

EXPORT void SteamAPI_RunCallbacks(void)
{
	LOG_ENTER0("()");

	callbacks_run();
}

EXPORT void SteamAPI_WriteMiniDump(uint32_t excp_code, void *excp_info, uint32_t build_id)
{
	//char cmd[256];

	LOG_ENTER("(excp_code = %#x, excp_info = %p, build_id = %#x)", excp_code, excp_info, build_id);

	//snprintf(cmd, sizeof(cmd), "gcore -o /tmp/DummySteamAPI-crash %u", getpid());
	//system(cmd);
}

EXPORT void SteamAPI_SetMiniDumpComment(const char *msg)
{
	LOG_ENTER_NOTIMPL("(msg = \"%s\")", debug_str(msg));
}

EXPORT void SteamAPI_RegisterCallback(struct CCallbackBase *callback, enum steam_callback_type type)
{
	LOG_ENTER("(callback = %p, type = %s (%d))", VOIDPTR(callback), dsa_debug_steam_callback_type(type), type);

	callbacks_register_callback(callback, type);
}

EXPORT void SteamAPI_UnregisterCallback(struct CCallbackBase *callback)
{
	LOG_ENTER("(callback = %p)", VOIDPTR(callback));

	callbacks_unregister_callback(callback);
}

EXPORT void SteamAPI_RegisterCallResult(struct CCallbackBase *callback, steam_api_call_t api_call)
{
	LOG_ENTER("(callback = %p, api_call = %" PRIu64 ")", VOIDPTR(callback), api_call);

	callbacks_register_api_call_result(callback, api_call);
}

EXPORT void SteamAPI_UnregisterCallResult(struct CCallbackBase *callback, steam_api_call_t api_call)
{
	LOG_ENTER("(callback = %p, api_call = %" PRIu64 ")", VOIDPTR(callback), api_call);

	callbacks_unregister_api_call_result(callback, api_call);
}

EXPORT steam_handle_pipe_t SteamAPI_GetHSteamPipe(void)
{
	LOG_ENTER0_NOTIMPL("()");

	return 1;
}

EXPORT steam_handle_pipe_t GetHSteamPipe(void)
{
	LOG_ENTER0("()");

	return SteamAPI_GetHSteamPipe();
}

EXPORT steam_user_t SteamAPI_GetHSteamUser(void)
{
	LOG_ENTER0("()");

	return 1;
}

EXPORT steam_user_t GetHSteamUser(void)
{
	LOG_ENTER0("()");

	return SteamAPI_GetHSteamUser();
}

EXPORT void SteamAPI_SetTryCatchCallbacks(steam_bool_t enable)
{
	LOG_ENTER_NOTIMPL("(enable = %u)", enable);
}

EXPORT void SteamAPI_UseBreakpadCrashHandler(const char *version, const char *date, char const *time, steam_bool_t is_full_memory_dump, void *context, void *pre_minidump_callback)
{
	LOG_ENTER_NOTIMPL("(version = \"%s\", date = \"%s\", time = \"%s\", is_full_memory_dump = %u, context = %p, pre_minidump_callback = %p)", debug_str(version), debug_str(date), debug_str(time), is_full_memory_dump, context, pre_minidump_callback);
}

EXPORT void *SteamInternal_CreateInterface(const char *version)
{
	struct ISteamClient *steam_client;

	LOG_ENTER("(version = \"%s\")", version);

	steam_client = SteamClient017();

	return steam_client->vtbl.v017->GetISteamGenericInterface(steam_client, SteamAPI_GetHSteamUser(), SteamAPI_GetHSteamPipe(), version);
}

EXPORT struct CSteamAPIContext *SteamInternal_ContextInit(struct CSteamAPIContextInitData *data)
{
	LOG_ENTER("(data = %p)", VOIDPTR(data));

	if (data->callback)
		data->callback(&data->ctx);

	return &data->ctx;
}
