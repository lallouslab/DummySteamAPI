#include <string.h>

#include "debug.h"
#include "utils.h"

#include "ISteamClient.h"
#include "ISteamClient_priv.h"
#include "ISteamClient006.h"
#include "ISteamClient014.h"
#include "ISteamClient016.h"
#include "ISteamClient017.h"
#include "../ISteamAppList/ISteamAppList.h"
#include "../ISteamApps/ISteamApps.h"
#include "../ISteamController/ISteamController.h"
#include "../ISteamFriends/ISteamFriends.h"
#include "../ISteamGameCoordinator/ISteamGameCoordinator.h"
#include "../ISteamGameServer/ISteamGameServer.h"
#include "../ISteamGameServerStats/ISteamGameServerStats.h"
#include "../ISteamHTTP/ISteamHTTP.h"
#include "../ISteamMatchmaking/ISteamMatchmaking.h"
#include "../ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "../ISteamNetworking/ISteamNetworking.h"
#include "../ISteamScreenshots/ISteamScreenshots.h"
#include "../ISteamRemoteStorage/ISteamRemoteStorage.h"
#include "../ISteamUGC/ISteamUGC.h"
#include "../ISteamUnifiedMessages/ISteamUnifiedMessages.h"
#include "../ISteamUser/ISteamUser.h"
#include "../ISteamUserStats/ISteamUserStats.h"
#include "../ISteamUtils/ISteamUtils.h"

static const char *steam_client_version = NULL;

steam_handle_pipe_t ISteamClient_CreateSteamPipe(struct ISteamClient *iface)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 1;
}

struct ISteamAppList *ISteamClient_GetISteamAppList(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamAppList_generic(version);
}

struct ISteamApps *ISteamClient_GetISteamApps(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamApps_generic(version);
}

struct ISteamClient *ISteamClient_GetISteamClient(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_pipe, debug_str(version));

	return SteamClient_generic(version);
}

struct ISteamController *ISteamClient_GetISteamController(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamController_generic(version);
}

struct ISteamFriends *ISteamClient_GetISteamFriends(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamFriends_generic(version);
}

struct ISteamGameCoordinator *ISteamClient_GetISteamGameCoordinator(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamGameCoordinator_generic(version);
}

struct ISteamGameServer *ISteamClient_GetISteamGameServer(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamGameServer_generic(version);
}

struct ISteamGameServerStats *ISteamClient_GetISteamGameServerStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamGameServerStats_generic(version);
}

static void *get_generic_ISteamAppList(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamAppList(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamApps(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamApps(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamClient(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	(void)steam_user;

	return VOIDPTR(ISteamClient_GetISteamClient(iface, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamController(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamController(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamFriends(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamFriends(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamGameCoordinator(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamGameCoordinator(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamGameServer(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamGameServer(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamGameServerStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamGameServerStats(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamHTTP(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamMatchmaking(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamMatchmakingServers(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamNetworking(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamRemoteStorage(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamRemoteStorage(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamScreenshots(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamScreenshots(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamUGC(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamUGC(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamUnifiedMessages(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamUnifiedMessages(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamUser(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamUser(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamUserStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamUserStats(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamUtils(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	(void)steam_user;

	return VOIDPTR(ISteamClient_GetISteamUtils(iface, steam_pipe, debug_str(version)));
}

void *ISteamClient_GetISteamGenericInterface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);
	static const struct
	{
		const char *name;
		void *(*iface_getter)(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version);
	} ifaces[] = {
		{ STEAMAPPLIST_INTERFACE_VERSION_PREFIX,            get_generic_ISteamAppList },
		{ STEAMAPPS_INTERFACE_VERSION_PREFIX,               get_generic_ISteamApps },
		{ STEAMCLIENT_INTERFACE_VERSION_PREFIX,             get_generic_ISteamClient },
		{ STEAMCONTROLLER_INTERFACE_VERSION_PREFIX0,        get_generic_ISteamController },
		{ STEAMCONTROLLER_INTERFACE_VERSION_PREFIX1,        get_generic_ISteamController },
		{ STEAMFRIENDS_INTERFACE_VERSION_PREFIX,            get_generic_ISteamFriends },
		{ STEAMGAMECOORDINATOR_INTERFACE_VERSION_PREFIX,    get_generic_ISteamGameCoordinator },
		{ STEAMGAMESERVER_INTERFACE_VERSION_PREFIX,         get_generic_ISteamGameServer },
		{ STEAMGAMESERVERSTATS_INTERFACE_VERSION_PREFIX,    get_generic_ISteamGameServerStats },
		{ STEAMHTTP_INTERFACE_VERSION_PREFIX,               get_generic_ISteamHTTP },
		{ STEAMMATCHMAKING_INTERFACE_VERSION_PREFIX,        get_generic_ISteamMatchmaking },
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_PREFIX, get_generic_ISteamMatchmakingServers },
		{ STEAMNETWORKING_INTERFACE_VERSION_PREFIX,         get_generic_ISteamNetworking },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_PREFIX,      get_generic_ISteamRemoteStorage },
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_PREFIX,        get_generic_ISteamScreenshots },
		{ STEAMUGC_INTERFACE_VERSION_PREFIX,                get_generic_ISteamUGC },
		{ STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_PREFIX,    get_generic_ISteamUnifiedMessages },
		{ STEAMUSER_INTERFACE_VERSION_PREFIX,               get_generic_ISteamUser },
		{ STEAMUSERSTATS_INTERFACE_VERSION_PREFIX,          get_generic_ISteamUserStats },
		{ STEAMUTILS_INTERFACE_VERSION_PREFIX,              get_generic_ISteamUtils },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	i = 0;
	while (ifaces[i].name)
	{
		if (strncmp(ifaces[i].name, version, strlen(ifaces[i].name)) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter(iface, steam_user, steam_pipe, debug_str(version));

			return INVAL_PTR;
		}
		i++;
	}

	return INVAL_PTR;
}

struct ISteamHTTP *ISteamClient_GetISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamHTTP_generic(version);
}

struct ISteamMatchmaking *ISteamClient_GetISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamMatchmaking_generic(version);
}

struct ISteamMatchmakingServers *ISteamClient_GetISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamMatchmakingServers_generic(version);
}

struct ISteamNetworking *ISteamClient_GetISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamNetworking_generic(version);
}

struct ISteamRemoteStorage *ISteamClient_GetISteamRemoteStorage(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamRemoteStorage_generic(version);
}

struct ISteamScreenshots *ISteamClient_GetISteamScreenshots(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamScreenshots_generic(version);
}

struct ISteamUGC *ISteamClient_GetISteamUGC(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUGC_generic(version);
}

struct ISteamUnifiedMessages *ISteamClient_GetISteamUnifiedMessages(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUnifiedMessages_generic(version);
}

struct ISteamUser *ISteamClient_GetISteamUser(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUser_generic(version);
}

struct ISteamUserStats *ISteamClient_GetISteamUserStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUserStats_generic(version);
}

struct ISteamUtils *ISteamClient_GetISteamUtils(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_pipe, debug_str(version));

	return SteamUtils_generic(version);
}

void ISteamClient_SetWarningMessageHook(struct ISteamClient *iface, void *callback)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p, callback = %p)", VOIDPTR(This), callback);
}

struct ISteamClient *SteamClient_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamClient *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMCLIENT_INTERFACE_VERSION_006, SteamClient006 },
		{ STEAMCLIENT_INTERFACE_VERSION_014, SteamClient014 },
		{ STEAMCLIENT_INTERFACE_VERSION_016, SteamClient016 },
		{ STEAMCLIENT_INTERFACE_VERSION_017, SteamClient017 },
		{ NULL, NULL }
	};
	int i;

	LOG_ENTER("(version = \"%s\")", debug_str(version));

	i = 0;
	while (ifaces[i].name)
	{
		if (strcmp(ifaces[i].name, version) == 0)
		{
			if (ifaces[i].iface_getter)
				return ifaces[i].iface_getter();

			break;
		}
		i++;
	}

	WARN("Unable to find ISteamClient version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamClient_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_client_version)
		steam_client_version = version;
}

EXPORT struct ISteamClient *SteamClient(void)
{
	static struct ISteamClient *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_client_version)
	{
		steam_client_version = STEAMCLIENT_INTERFACE_VERSION_017;

		WARN("ISteamClient: No version specified, defaulting to \"%s\".", debug_str(steam_client_version));
	}

	if (!cached_iface)
		cached_iface = SteamClient_generic(steam_client_version);

	return cached_iface;
}
