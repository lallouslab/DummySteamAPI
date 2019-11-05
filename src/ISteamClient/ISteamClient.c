#include <string.h>

#include "ISteamUser/ISteamUser019.h"
#include "ISteamAppList/ISteamAppList.h"
#include "ISteamApps/ISteamApps.h"
#include "ISteamController/ISteamController.h"
#include "ISteamFriends/ISteamFriends.h"
#include "ISteamGameCoordinator/ISteamGameCoordinator.h"
#include "ISteamGameServer/ISteamGameServer.h"
#include "ISteamGameServerStats/ISteamGameServerStats.h"
#include "ISteamHTMLSurface/ISteamHTMLSurface.h"
#include "ISteamHTTP/ISteamHTTP.h"
#include "ISteamInventory/ISteamInventory.h"
#include "ISteamMatchmaking/ISteamMatchmaking.h"
#include "ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "ISteamMusic/ISteamMusic.h"
#include "ISteamMusicRemote/ISteamMusicRemote.h"
#include "ISteamNetworking/ISteamNetworking.h"
#include "ISteamParentalSettings/ISteamParentalSettings.h"
#include "ISteamScreenshots/ISteamScreenshots.h"
#include "ISteamRemoteStorage/ISteamRemoteStorage.h"
#include "ISteamUGC/ISteamUGC.h"
#include "ISteamUnifiedMessages/ISteamUnifiedMessages.h"
#include "ISteamUser/ISteamUser.h"
#include "ISteamUserStats/ISteamUserStats.h"
#include "ISteamUtils/ISteamUtils.h"
#include "ISteamVideo/ISteamVideo.h"
#include "debug.h"
#include "steam.h"

#include "ISteamClient.h"
#include "ISteamClient_priv.h"
#include "ISteamClient006.h"
#include "ISteamClient012.h"
#include "ISteamClient014.h"
#include "ISteamClient016.h"
#include "ISteamClient017.h"

static const char *steam_client_version = NULL;

MEMBER steam_handle_pipe_t ISteamClient_CreateSteamPipe(struct ISteamClient *iface)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 1;
}

EXPORT steam_handle_pipe_t SteamAPI_ISteamClient_CreateSteamPipe(struct ISteamClient *iface)
{
	return ISteamClient_CreateSteamPipe(iface);
}

MEMBER steam_bool_t ISteamClient_BReleaseSteamPipe(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_pipe = %d)", VOIDPTR(This), steam_pipe);

	return STEAM_TRUE;
}

EXPORT steam_bool_t SteamAPI_ISteamClient_BReleaseSteamPipe(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe)
{
	return ISteamClient_BReleaseSteamPipe(iface, steam_pipe);
}

MEMBER steam_user_t ISteamClient_ConnectToGlobalUser(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_pipe = %u)", VOIDPTR(This), steam_pipe);

	return ISteamUser019_GetHSteamUser(SteamUser019());
}

EXPORT steam_user_t SteamAPI_ISteamClient_ConnectToGlobalUser(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe)
{
	return ISteamClient_ConnectToGlobalUser(iface, steam_pipe);
}

MEMBER void ISteamClient_ReleaseUser(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, steam_user_t steam_user)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_pipe = %u, steam_user = %u)", VOIDPTR(This), steam_pipe, steam_user);
}

EXPORT void SteamAPI_ISteamClient_ReleaseUser(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, steam_user_t steam_user)
{
	ISteamClient_ReleaseUser(iface, steam_pipe, steam_user);
}

MEMBER struct ISteamAppList *ISteamClient_GetISteamAppList(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamAppList_generic(version);
}

EXPORT struct ISteamAppList *SteamAPI_ISteamClient_GetISteamAppList(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamAppList(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamApps *ISteamClient_GetISteamApps(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamApps_generic(version);
}

EXPORT struct ISteamApps *SteamAPI_ISteamClient_GetISteamApps(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamApps(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamClient *ISteamClient_GetISteamClient(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_pipe, debug_str(version));

	return SteamClient_generic(version);
}

EXPORT struct ISteamClient *SteamAPI_ISteamClient_GetISteamClient(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamClient(iface, steam_pipe, version);
}

MEMBER struct ISteamController *ISteamClient_GetISteamController(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamController_generic(version);
}

EXPORT struct ISteamController *SteamAPI_ISteamClient_GetISteamController(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamController(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamFriends *ISteamClient_GetISteamFriends(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamFriends_generic(version);
}

EXPORT struct ISteamFriends *SteamAPI_ISteamClient_GetISteamFriends(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamFriends(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamGameCoordinator *ISteamClient_GetISteamGameCoordinator(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamGameCoordinator_generic(version);
}

EXPORT struct ISteamGameCoordinator *SteamAPI_ISteamClient_GetISteamGameCoordinator(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamGameCoordinator(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamGameServer *ISteamClient_GetISteamGameServer(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamGameServer_generic(version);
}

EXPORT struct ISteamGameServer *SteamAPI_ISteamClient_GetISteamGameServer(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamGameServer(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamGameServerStats *ISteamClient_GetISteamGameServerStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamGameServerStats_generic(version);
}

EXPORT struct ISteamGameServerStats *SteamAPI_ISteamClient_GetISteamGameServerStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamGameServerStats(iface, steam_user, steam_pipe, version);
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

static void *get_generic_ISteamHTMLSurface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamHTMLSurface(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamHTTP(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamInventory(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamInventory(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamMatchmaking(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamMatchmakingServers(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamMusic(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamMusic(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamMusicRemote(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamMusicRemote(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamNetworking(iface, steam_user, steam_pipe, debug_str(version)));
}

static void *get_generic_ISteamParentalSettings(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamParentalSettings(iface, steam_user, steam_pipe, debug_str(version)));
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

static void *get_generic_ISteamVideo(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return VOIDPTR(ISteamClient_GetISteamVideo(iface, steam_user, steam_pipe, debug_str(version)));
}

MEMBER void *ISteamClient_GetISteamGenericInterface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
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
		{ STEAMHTMLSURFACE_INTERFACE_VERSION_PREFIX,        get_generic_ISteamHTMLSurface },
		{ STEAMHTTP_INTERFACE_VERSION_PREFIX,               get_generic_ISteamHTTP },
		{ STEAMINVENTORY_INTERFACE_VERSION_PREFIX,          get_generic_ISteamInventory },
		{ STEAMMATCHMAKING_INTERFACE_VERSION_PREFIX,        get_generic_ISteamMatchmaking },
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_PREFIX, get_generic_ISteamMatchmakingServers },
		{ STEAMMUSIC_INTERFACE_VERSION_PREFIX,              get_generic_ISteamMusic },
		{ STEAMMUSICREMOTE_INTERFACE_VERSION_PREFIX,        get_generic_ISteamMusicRemote },
		{ STEAMNETWORKING_INTERFACE_VERSION_PREFIX,         get_generic_ISteamNetworking },
		{ STEAMPARENTALSETTINGS_INTERFACE_VERSION_PREFIX,   get_generic_ISteamParentalSettings },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_PREFIX,      get_generic_ISteamRemoteStorage },
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_PREFIX,        get_generic_ISteamScreenshots },
		{ STEAMUGC_INTERFACE_VERSION_PREFIX,                get_generic_ISteamUGC },
		{ STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_PREFIX,    get_generic_ISteamUnifiedMessages },
		{ STEAMUSER_INTERFACE_VERSION_PREFIX,               get_generic_ISteamUser },
		{ STEAMUSERSTATS_INTERFACE_VERSION_PREFIX,          get_generic_ISteamUserStats },
		{ STEAMUTILS_INTERFACE_VERSION_PREFIX,              get_generic_ISteamUtils },
		{ STEAMVIDEO_INTERFACE_VERSION_PREFIX,              get_generic_ISteamVideo },
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

			goto fail;
		}
		i++;
	}

fail:
	WARN("Unable to find an interface for version \"%s\".", debug_str(version));
	return INVAL_PTR;
}

EXPORT void *SteamAPI_ISteamClient_GetISteamGenericInterface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamGenericInterface(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamHTMLSurface *ISteamClient_GetISteamHTMLSurface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamHTMLSurface_generic(version);
}

EXPORT struct ISteamHTMLSurface *SteamAPI_ISteamClient_GetISteamHTMLSurface(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamHTMLSurface(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamHTTP *ISteamClient_GetISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamHTTP_generic(version);
}

EXPORT struct ISteamHTTP *SteamAPI_ISteamClient_GetISteamHTTP(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamHTTP(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamInventory *ISteamClient_GetISteamInventory(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamInventory_generic(version);
}

EXPORT struct ISteamInventory *SteamAPI_ISteamClient_GetISteamInventory(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamInventory(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamMatchmaking *ISteamClient_GetISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamMatchmaking_generic(version);
}

EXPORT struct ISteamMatchmaking *SteamAPI_ISteamClient_GetISteamMatchmaking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamMatchmaking(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamMatchmakingServers *ISteamClient_GetISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamMatchmakingServers_generic(version);
}

EXPORT struct ISteamMatchmakingServers *SteamAPI_ISteamClient_GetISteamMatchmakingServers(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamMatchmakingServers(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamMusic *ISteamClient_GetISteamMusic(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamMusic_generic(version);
}

EXPORT struct ISteamMusic *SteamAPI_ISteamClient_GetISteamMusic(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamMusic(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamMusicRemote *ISteamClient_GetISteamMusicRemote(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamMusicRemote_generic(version);
}

EXPORT struct ISteamMusicRemote *SteamAPI_ISteamClient_GetISteamMusicRemote(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamMusicRemote(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamNetworking *ISteamClient_GetISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamNetworking_generic(version);
}

EXPORT struct ISteamNetworking *SteamAPI_ISteamClient_GetISteamNetworking(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamNetworking(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamParentalSettings *ISteamClient_GetISteamParentalSettings(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamParentalSettings_generic(version);
}

EXPORT struct ISteamParentalSettings *SteamAPI_ISteamClient_GetISteamParentalSettings(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamParentalSettings(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamRemoteStorage *ISteamClient_GetISteamRemoteStorage(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamRemoteStorage_generic(version);
}

EXPORT struct ISteamRemoteStorage *SteamAPI_ISteamClient_GetISteamRemoteStorage(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamRemoteStorage(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamScreenshots *ISteamClient_GetISteamScreenshots(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamScreenshots_generic(version);
}

EXPORT struct ISteamScreenshots *SteamAPI_ISteamClient_GetISteamScreenshots(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamScreenshots(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamUGC *ISteamClient_GetISteamUGC(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUGC_generic(version);
}

EXPORT struct ISteamUGC *SteamAPI_ISteamClient_GetISteamUGC(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamUGC(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamUnifiedMessages *ISteamClient_GetISteamUnifiedMessages(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUnifiedMessages_generic(version);
}

EXPORT struct ISteamUnifiedMessages *SteamAPI_ISteamClient_GetISteamUnifiedMessages(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamUnifiedMessages(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamUser *ISteamClient_GetISteamUser(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUser_generic(version);
}

EXPORT struct ISteamUser *SteamAPI_ISteamClient_GetISteamUser(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamUser(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamUserStats *ISteamClient_GetISteamUserStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamUserStats_generic(version);
}

EXPORT struct ISteamUserStats *SteamAPI_ISteamClient_GetISteamUserStats(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamUserStats(iface, steam_user, steam_pipe, version);
}

MEMBER struct ISteamUtils *ISteamClient_GetISteamUtils(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_pipe, debug_str(version));

	return SteamUtils_generic(version);
}

EXPORT struct ISteamUtils *SteamAPI_ISteamClient_GetISteamUtils(struct ISteamClient *iface, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamUtils(iface, steam_pipe, version);
}

MEMBER struct ISteamVideo *ISteamClient_GetISteamVideo(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER("(This = %p, steam_user = %u, steam_pipe = %u, version = \"%s\")", VOIDPTR(This), steam_user, steam_pipe, debug_str(version));

	return SteamVideo_generic(version);
}

EXPORT struct ISteamVideo *SteamAPI_ISteamClient_GetISteamVideo(struct ISteamClient *iface, steam_user_t steam_user, steam_handle_pipe_t steam_pipe, const char *version)
{
	return ISteamClient_GetISteamVideo(iface, steam_user, steam_pipe, version);
}

MEMBER void ISteamClient_SetWarningMessageHook(struct ISteamClient *iface, void *callback)
{
	struct ISteamClientImpl *This = impl_from_ISteamClient(iface);

	LOG_ENTER_NOTIMPL("(This = %p, callback = %p)", VOIDPTR(This), callback);
}

EXPORT void SteamAPI_ISteamClient_SetWarningMessageHook(struct ISteamClient *iface, void *callback)
{
	ISteamClient_SetWarningMessageHook(iface, callback);
}

struct ISteamClient *SteamClient_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamClient *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMCLIENT_INTERFACE_VERSION_006, SteamClient006 },
		{ STEAMCLIENT_INTERFACE_VERSION_012, SteamClient012 },
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
