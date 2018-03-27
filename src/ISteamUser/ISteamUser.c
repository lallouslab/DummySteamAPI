#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "debug.h"
#include "os/os.h"
#include "steam.h"
#include "utils.h"

#include "ISteamUser.h"
#include "ISteamUser_priv.h"
#include "ISteamUser004.h"
#include "ISteamUser017.h"
#include "ISteamUser018.h"

static const char *steam_user_version = NULL;

MEMBER steam_user_t ISteamUser_GetHSteamUser(struct ISteamUser *iface)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return 1;
}

MEMBER steam_bool_t ISteamUser_BLoggedOn(struct ISteamUser *iface)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_TRUE;
}

MEMBER void ISteamUser_GetSteamID(union CSteamID *ret, struct ISteamUser *iface)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	const char *user_id;

	LOG_ENTER("(ret = %p, This = %p)", VOIDPTR(ret), VOIDPTR(This));

	user_id = getenv("STEAM_USER_ID");
	if (!user_id)
	{
		WARN0("STEAM_USER_ID is not set, please check DummySteamAPI config.sh.");
		user_id = "1";
	}

	ret->bits.account_id = strtoul(user_id, NULL, 0);
	ret->bits.account_instance = STEAM_ACCOUNT_INSTANCE_USER_DESKTOP;
	ret->bits.account_type = STEAM_ACCOUNT_TYPE_INDIVIDUAL;
	ret->bits.universe = STEAM_UNIVERSE_PUBLIC;
}

MEMBER union CSteamID ISteamUser_GetSteamID018(struct ISteamUser *iface)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	union CSteamID steam_id;

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	ISteamUser_GetSteamID(&steam_id, iface);

	return steam_id;
}

MEMBER void ISteamUser_TerminateGameConnection(struct ISteamUser *iface, uint32_t server_ip, uint16_t server_port)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER_NOTIMPL("(This = %p, server_ip = %#x, server_port = %u)", VOIDPTR(This), server_ip, server_port);
}

MEMBER steam_bool_t ISteamUser_GetUserDataFolder(struct ISteamUser *iface, char *buf, int buf_len)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	const char *steam_dir;
	const char userdata_dir[] = "/userdata/";
	const char *user_id;
	const char *app_id;
	char *str;
	int str_size;

	LOG_ENTER("This = %p, buf = %p, buf_len = %d)", VOIDPTR(This), VOIDPTR(buf), buf_len);

	buf[0] = '\0';

	steam_dir = dsa_os_get_steam_dir();

	user_id = getenv("STEAM_USER_ID");
	if (!user_id)
	{
		WARN0("STEAM_USER_ID is not set, please check DummySteamAPI config.sh.");
		return STEAM_FALSE;
	}

	app_id = getenv("SteamAppId");
	if (!app_id)
	{
		WARN0("SteamAppId is not set.");
		return STEAM_FALSE;
	}

	str = dsa_utils_concat(steam_dir, userdata_dir, user_id, "/", app_id, NULL);

	str_size = strlen(str) + 1;
	if (str_size > buf_len)
	{
		WARN("buf_len (%d) < str_size (%u)!", buf_len, str_size);
		return STEAM_FALSE;
	}

	memcpy(buf, str, str_size);

	free(str);

	DEBUG("UserDataFolder: \"%s\"", buf);

	dsa_os_mkdir(buf);

	return STEAM_TRUE;
}

MEMBER steam_api_call_t ISteamUser_RequestEncryptedAppTicket(struct ISteamUser *iface, void *data, int data_size)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	PACKED_STRUCT
	{
		enum steam_result result;
	} encrypted_app_ticket_response;

	LOG_ENTER("(This = %p, data = %p, data_size = %d)", VOIDPTR(This), data, data_size);

	encrypted_app_ticket_response.result = STEAM_RESULT_FAIL;

	return callbacks_dispatch_api_call_result_output(STEAM_CALLBACK_TYPE_USER_ENCRYPTED_APP_TICKET_RESPONSE, STEAM_TRUE, &encrypted_app_ticket_response, sizeof(encrypted_app_ticket_response));
}

struct ISteamUser *SteamUser_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUser *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUSER_INTERFACE_VERSION_004, SteamUser004 },
		{ STEAMUSER_INTERFACE_VERSION_017, SteamUser017 },
		{ STEAMUSER_INTERFACE_VERSION_018, SteamUser018 },
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

	WARN("Unable to find ISteamUser version \"%s\".", debug_str(version));

	return INVAL_PTR;
}

void SteamUser_set_version(const char *version)
{
	LOG_ENTER("(version = \"%s\")", debug_str(version));

	if (!steam_user_version)
		steam_user_version = version;
}

EXPORT struct ISteamUser *SteamUser(void)
{
	static struct ISteamUser *cached_iface = NULL;

	LOG_ENTER0("()");

	if (!steam_user_version)
	{
		steam_user_version = STEAMUSER_INTERFACE_VERSION_018;

		WARN("ISteamUser: No version specified, defaulting to \"%s\".", debug_str(steam_user_version));
	}

	if (!cached_iface)
		cached_iface = SteamUser_generic(steam_user_version);

	return cached_iface;
}
