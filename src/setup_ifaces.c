#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "debug.h"
#include "setup_ifaces.h"
#include "utils.h"

#include "ISteamAppList/ISteamAppList.h"
#include "ISteamAppList/ISteamAppList001.h"
#include "ISteamApps/ISteamApps.h"
#include "ISteamApps/ISteamApps001.h"
#include "ISteamApps/ISteamApps003.h"
#include "ISteamApps/ISteamApps005.h"
#include "ISteamApps/ISteamApps006.h"
#include "ISteamApps/ISteamApps007.h"
#include "ISteamApps/ISteamApps008.h"
#include "ISteamClient/ISteamClient.h"
#include "ISteamClient/ISteamClient006.h"
#include "ISteamClient/ISteamClient012.h"
#include "ISteamClient/ISteamClient014.h"
#include "ISteamClient/ISteamClient016.h"
#include "ISteamClient/ISteamClient017.h"
#include "ISteamController/ISteamController.h"
#include "ISteamController/ISteamController001.h"
#include "ISteamController/ISteamController003.h"
#include "ISteamController/ISteamController005.h"
#include "ISteamController/ISteamController006.h"
#include "ISteamFriends/ISteamFriends.h"
#include "ISteamFriends/ISteamFriends001.h"
#include "ISteamFriends/ISteamFriends013.h"
#include "ISteamFriends/ISteamFriends014.h"
#include "ISteamFriends/ISteamFriends015.h"
#include "ISteamGameCoordinator/ISteamGameCoordinator.h"
#include "ISteamGameCoordinator/ISteamGameCoordinator001.h"
#include "ISteamGameServer/ISteamGameServer.h"
#include "ISteamGameServer/ISteamGameServer011.h"
#include "ISteamGameServer/ISteamGameServer012.h"
#include "ISteamGameServerStats/ISteamGameServerStats.h"
#include "ISteamGameServerStats/ISteamGameServerStats001.h"
#include "ISteamHTMLSurface/ISteamHTMLSurface.h"
#include "ISteamHTMLSurface/ISteamHTMLSurface002.h"
#include "ISteamHTMLSurface/ISteamHTMLSurface003.h"
#include "ISteamHTMLSurface/ISteamHTMLSurface004.h"
#include "ISteamHTTP/ISteamHTTP.h"
#include "ISteamHTTP/ISteamHTTP001.h"
#include "ISteamHTTP/ISteamHTTP002.h"
#include "ISteamInventory/ISteamInventory.h"
#include "ISteamInventory/ISteamInventory001.h"
#include "ISteamInventory/ISteamInventory002.h"
#include "ISteamMatchmaking/ISteamMatchmaking.h"
#include "ISteamMatchmaking/ISteamMatchmaking001.h"
#include "ISteamMatchmaking/ISteamMatchmaking009.h"
#include "ISteamMatchmakingServers/ISteamMatchmakingServers.h"
#include "ISteamMatchmakingServers/ISteamMatchmakingServers001.h"
#include "ISteamMatchmakingServers/ISteamMatchmakingServers002.h"
#include "ISteamMusic/ISteamMusic.h"
#include "ISteamMusic/ISteamMusic001.h"
#include "ISteamMusicRemote/ISteamMusicRemote.h"
#include "ISteamMusicRemote/ISteamMusicRemote001.h"
#include "ISteamNetworking/ISteamNetworking.h"
#include "ISteamNetworking/ISteamNetworking001.h"
#include "ISteamNetworking/ISteamNetworking005.h"
#include "ISteamParentalSettings/ISteamParentalSettings.h"
#include "ISteamParentalSettings/ISteamParentalSettings001.h"
#include "ISteamRemoteStorage/ISteamRemoteStorage.h"
#include "ISteamRemoteStorage/ISteamRemoteStorage001.h"
#include "ISteamRemoteStorage/ISteamRemoteStorage012.h"
#include "ISteamRemoteStorage/ISteamRemoteStorage013.h"
#include "ISteamRemoteStorage/ISteamRemoteStorage014.h"
#include "ISteamScreenshots/ISteamScreenshots.h"
#include "ISteamScreenshots/ISteamScreenshots001.h"
#include "ISteamScreenshots/ISteamScreenshots002.h"
#include "ISteamScreenshots/ISteamScreenshots003.h"
#include "ISteamUGC/ISteamUGC.h"
#include "ISteamUGC/ISteamUGC001.h"
#include "ISteamUGC/ISteamUGC005.h"
#include "ISteamUGC/ISteamUGC007.h"
#include "ISteamUGC/ISteamUGC009.h"
#include "ISteamUGC/ISteamUGC010.h"
#include "ISteamUnifiedMessages/ISteamUnifiedMessages.h"
#include "ISteamUnifiedMessages/ISteamUnifiedMessages001.h"
#include "ISteamUser/ISteamUser.h"
#include "ISteamUser/ISteamUser004.h"
#include "ISteamUser/ISteamUser016.h"
#include "ISteamUser/ISteamUser017.h"
#include "ISteamUser/ISteamUser018.h"
#include "ISteamUser/ISteamUser019.h"
#include "ISteamUserStats/ISteamUserStats.h"
#include "ISteamUserStats/ISteamUserStats011.h"
#include "ISteamUtils/ISteamUtils.h"
#include "ISteamUtils/ISteamUtils001.h"
#include "ISteamUtils/ISteamUtils002.h"
#include "ISteamUtils/ISteamUtils006.h"
#include "ISteamUtils/ISteamUtils007.h"
#include "ISteamUtils/ISteamUtils008.h"
#include "ISteamUtils/ISteamUtils009.h"
#include "ISteamVideo/ISteamVideo.h"
#include "ISteamVideo/ISteamVideo001.h"
#include "ISteamVideo/ISteamVideo002.h"

int dsa_set_default_interfaces_version(void)
{
	static const struct
	{
		const char *name;
		void (*iface_set_default_version)(const char *);
	} ifaces[] = {
		{ STEAMAPPLIST_INTERFACE_VERSION_001, SteamAppList_set_version },
		{ STEAMAPPS_INTERFACE_VERSION_001, SteamApps_set_version },
		{ STEAMAPPS_INTERFACE_VERSION_003, SteamApps_set_version },
		{ STEAMAPPS_INTERFACE_VERSION_005, SteamApps_set_version },
		{ STEAMAPPS_INTERFACE_VERSION_006, SteamApps_set_version },
		{ STEAMAPPS_INTERFACE_VERSION_007, SteamApps_set_version },
		{ STEAMAPPS_INTERFACE_VERSION_008, SteamApps_set_version },
		{ STEAMCLIENT_INTERFACE_VERSION_006, SteamClient_set_version },
		{ STEAMCLIENT_INTERFACE_VERSION_012, SteamClient_set_version },
		{ STEAMCLIENT_INTERFACE_VERSION_014, SteamClient_set_version },
		{ STEAMCLIENT_INTERFACE_VERSION_016, SteamClient_set_version },
		{ STEAMCLIENT_INTERFACE_VERSION_017, SteamClient_set_version },
		{ STEAMCONTROLLER_INTERFACE_VERSION_001, SteamController_set_version },
		{ STEAMCONTROLLER_INTERFACE_VERSION_003, SteamController_set_version },
		{ STEAMCONTROLLER_INTERFACE_VERSION_005, SteamController_set_version },
		{ STEAMCONTROLLER_INTERFACE_VERSION_006, SteamController_set_version },
		{ STEAMFRIENDS_INTERFACE_VERSION_001, SteamFriends_set_version },
		{ STEAMFRIENDS_INTERFACE_VERSION_013, SteamFriends_set_version },
		{ STEAMFRIENDS_INTERFACE_VERSION_014, SteamFriends_set_version },
		{ STEAMFRIENDS_INTERFACE_VERSION_015, SteamFriends_set_version },
		{ STEAMGAMECOORDINATOR_INTERFACE_VERSION_001, SteamGameCoordinator_set_version },
		{ STEAMGAMESERVER_INTERFACE_VERSION_011, SteamGameServer_set_version },
		{ STEAMGAMESERVER_INTERFACE_VERSION_012, SteamGameServer_set_version },
		{ STEAMGAMESERVERSTATS_INTERFACE_VERSION_001, SteamGameServerStats_set_version },
		{ STEAMHTMLSURFACE_INTERFACE_VERSION_002, SteamHTMLSurface_set_version },
		{ STEAMHTMLSURFACE_INTERFACE_VERSION_003, SteamHTMLSurface_set_version },
		{ STEAMHTMLSURFACE_INTERFACE_VERSION_004, SteamHTMLSurface_set_version },
		{ STEAMHTTP_INTERFACE_VERSION_001, SteamHTTP_set_version },
		{ STEAMHTTP_INTERFACE_VERSION_002, SteamHTTP_set_version },
		{ STEAMINVENTORY_INTERFACE_VERSION_001, SteamInventory_set_version },
		{ STEAMINVENTORY_INTERFACE_VERSION_002, SteamInventory_set_version },
		{ STEAMMATCHMAKING_INTERFACE_VERSION_001, SteamMatchmaking_set_version },
		{ STEAMMATCHMAKING_INTERFACE_VERSION_009, SteamMatchmaking_set_version },
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_001, SteamMatchmakingServers_set_version },
		{ STEAMMATCHMAKINGSERVERS_INTERFACE_VERSION_002, SteamMatchmakingServers_set_version },
		{ STEAMMUSIC_INTERFACE_VERSION_001, SteamMusic_set_version },
		{ STEAMMUSICREMOTE_INTERFACE_VERSION_001, SteamMusicRemote_set_version },
		{ STEAMNETWORKING_INTERFACE_VERSION_001, SteamNetworking_set_version },
		{ STEAMNETWORKING_INTERFACE_VERSION_005, SteamNetworking_set_version },
		{ STEAMPARENTALSETTINGS_INTERFACE_VERSION_001, SteamParentalSettings_set_version },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_001, SteamRemoteStorage_set_version },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_012, SteamRemoteStorage_set_version },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_013, SteamRemoteStorage_set_version },
		{ STEAMREMOTESTORAGE_INTERFACE_VERSION_014, SteamRemoteStorage_set_version },
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_001, SteamScreenshots_set_version },
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_002, SteamScreenshots_set_version },
		{ STEAMSCREENSHOTS_INTERFACE_VERSION_003, SteamScreenshots_set_version },
		{ STEAMUGC_INTERFACE_VERSION_001, SteamUGC_set_version },
		{ STEAMUGC_INTERFACE_VERSION_005, SteamUGC_set_version },
		{ STEAMUGC_INTERFACE_VERSION_007, SteamUGC_set_version },
		{ STEAMUGC_INTERFACE_VERSION_009, SteamUGC_set_version },
		{ STEAMUGC_INTERFACE_VERSION_010, SteamUGC_set_version },
		{ STEAMUNIFIEDMESSAGES_INTERFACE_VERSION_001, SteamUnifiedMessages_set_version },
		{ STEAMUSER_INTERFACE_VERSION_004, SteamUser_set_version },
		{ STEAMUSER_INTERFACE_VERSION_016, SteamUser_set_version },
		{ STEAMUSER_INTERFACE_VERSION_017, SteamUser_set_version },
		{ STEAMUSER_INTERFACE_VERSION_018, SteamUser_set_version },
		{ STEAMUSER_INTERFACE_VERSION_019, SteamUser_set_version },
		{ STEAMUSERSTATS_INTERFACE_VERSION_011, SteamUserStats_set_version },
		{ STEAMUTILS_INTERFACE_VERSION_001, SteamUtils_set_version },
		{ STEAMUTILS_INTERFACE_VERSION_002, SteamUtils_set_version },
		{ STEAMUTILS_INTERFACE_VERSION_006, SteamUtils_set_version },
		{ STEAMUTILS_INTERFACE_VERSION_007, SteamUtils_set_version },
		{ STEAMUTILS_INTERFACE_VERSION_008, SteamUtils_set_version },
		{ STEAMUTILS_INTERFACE_VERSION_009, SteamUtils_set_version },
		{ STEAMVIDEO_INTERFACE_VERSION_001, SteamVideo_set_version },
		{ STEAMVIDEO_INTERFACE_VERSION_002, SteamVideo_set_version },
		{ NULL, NULL }
	};
	int result = -1;
	size_t ret;
	const char *orig_steam_api_lib;
	FILE *fp;
	char *data;
	long len;

	LOG_ENTER0("()");

	orig_steam_api_lib = dsa_config_get_orig_steam_api_lib();

	fp = fopen(orig_steam_api_lib, "rb");
	if (!fp)
	{
		WARN("Unable to open \"%s\" in read mode.", orig_steam_api_lib);
		goto failed_open_file;
	}

	len = dsa_utils_file_get_size(fp);
	if (len <= 0)
	{
		WARN("File \"%s\" is empty.", orig_steam_api_lib);
		goto failed_get_file_size;
	}

	data = malloc(len);
	if (!data)
	{
		WARN0("Out of memory.");
		goto failed_alloc_data;
	}

	ret = fread(data, len, 1, fp);
	if (ret != 1)
	{
		WARN("Failed to read from \"%s\".", orig_steam_api_lib);
		goto failed_read;
	}

	for (long i = 0; i < len; i++)
	{
		char *d = &data[i];
		int j = 0;

		while (ifaces[j].name)
		{
			size_t name_len = strlen(ifaces[j].name) + 1;
			size_t remaining_len = len - i;

			if (remaining_len < name_len)
			{
				j++;
				continue;
			}

			if (strncmp(ifaces[j].name, d, name_len) == 0)
			{
				if (ifaces[j].iface_set_default_version)
					ifaces[j].iface_set_default_version(ifaces[j].name);

				i += name_len - 1;
				break;
			}
			j++;
		}
	}

	result = 0;

failed_read:
	free(data);

failed_alloc_data:
failed_get_file_size:
	fclose(fp);

failed_open_file:
	return result;
}
