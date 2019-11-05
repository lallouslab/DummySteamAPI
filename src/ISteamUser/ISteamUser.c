#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#include "callbacks.h"
#include "config.h"
#include "debug.h"
#include "os/os.h"
#include "steam.h"
#include "utils.h"

#include "ISteamUser.h"
#include "ISteamUser_priv.h"
#include "ISteamUser004.h"
#include "ISteamUser016.h"
#include "ISteamUser017.h"
#include "ISteamUser018.h"
#include "ISteamUser019.h"

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

DSA_MEMBER_RETURN_STRUCT0(union CSteamID, ret, ISteamUser_GetSteamID, struct ISteamUser *iface)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	union CSteamID steam_id;

	LOG_ENTER("(This = %p)", VOIDPTR(This));

	steam_id.bits.account_id = dsa_config_get_steam_user_id();
	steam_id.bits.account_instance = STEAM_ACCOUNT_INSTANCE_USER_DESKTOP;
	steam_id.bits.account_type = STEAM_ACCOUNT_TYPE_INDIVIDUAL;
	steam_id.bits.universe = STEAM_UNIVERSE_PUBLIC;

	DSA_MEMBER_RETURN_STRUCT_RETURN(ret, steam_id);
}

EXPORT uint64_t SteamAPI_ISteamUser_GetSteamID(struct ISteamUser *iface)
{
	union CSteamID steam_id;

	DSA_CALL_MEMBER_RETURN_STRUCT0(ISteamUser_GetSteamID, &steam_id, iface);

	return steam_id.raw;
}

MEMBER int ISteamUser_InitiateGameConnection(struct ISteamUser *iface, void *auth_blob, int auth_blob_size, union CSteamID steam_id_game_server, steam_app_id_t app_id, uint32_t server_ip, uint16_t server_port, steam_bool_t secure)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER("(This = %p, auth_blob = %p, auth_blob_size = %d, steam_id_game_server = %#" PRIx64 ", app_id = %u, server_ip = %#x, server_port = %u, secure = %u)", VOIDPTR(This), auth_blob, auth_blob_size, steam_id_game_server.raw, app_id, server_ip, server_port, secure);

	return ISteamUser_InitiateGameConnection010(iface, auth_blob, auth_blob_size, steam_id_game_server, server_ip, server_port, secure);
}

MEMBER int ISteamUser_InitiateGameConnection010(struct ISteamUser *iface, void *auth_blob, int auth_blob_size, union CSteamID steam_id_game_server, uint32_t server_ip, uint16_t server_port, steam_bool_t secure)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	union CSteamID steam_id;

	LOG_ENTER_NOTIMPL("(This = %p, auth_blob = %p, auth_blob_size = %d, steam_id_game_server = %#" PRIx64 ", server_ip = %#x, server_port = %u, secure = %u)", VOIDPTR(This), auth_blob, auth_blob_size, steam_id_game_server.raw, server_ip, server_port, secure);

	if ((size_t)auth_blob_size < sizeof(steam_id))
		return 0;

	ISteamUser019_GetSteamID(iface, &steam_id);

	memcpy(auth_blob, &steam_id, sizeof(steam_id));

	return auth_blob_size < 1024 ? auth_blob_size : 1024;
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

	user_id = dsa_config_get_steam_user_id_str();
	app_id = dsa_config_get_steam_app_id_str();

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

MEMBER steam_auth_ticket_handle_t ISteamUser_GetAuthSessionTicket(struct ISteamUser *iface, void *buf, int buf_size, uint32_t *ticket_len)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	const char ticket[] = "DSA dummy ticket";
	char *cbuf = buf;
	struct steam_callback_data_user_get_auth_session_ticket_response get_auth_session_ticket_response;

	LOG_ENTER_NOTIMPL("(This = %p, buf = %p, buf_size = %d, ticket_len = %p)", VOIDPTR(This), buf, buf_size, VOIDPTR(ticket_len));

	if (!buf_size)
		return 0;

	*ticket_len = dsa_minu(sizeof(ticket), buf_size);

	memcpy(cbuf, ticket, *ticket_len);
	cbuf[*ticket_len - 1] = 0;

	get_auth_session_ticket_response.ticket = 1;
	get_auth_session_ticket_response.result = STEAM_RESULT_OK;

	callbacks_dispatch_callback_output(STEAM_CALLBACK_TYPE_USER_GET_AUTH_SESSION_TICKET_RESPONSE, &get_auth_session_ticket_response, sizeof(get_auth_session_ticket_response));

	return get_auth_session_ticket_response.ticket;
}

MEMBER void ISteamUser_CancelAuthTicket(struct ISteamUser *iface, steam_auth_ticket_handle_t ticket_handle)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER_NOTIMPL("(This = %p, ticket_handle = %u)", VOIDPTR(This), ticket_handle);
}

MEMBER steam_bool_t ISteamUser_BIsBehindNAT(struct ISteamUser *iface)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER_NOTIMPL("(This = %p)", VOIDPTR(This));

	return STEAM_FALSE;
}

MEMBER void ISteamUser_AdvertiseGame(struct ISteamUser *iface, union CSteamID steam_id_game_server, uint32_t server_ip, uint16_t server_port)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);

	LOG_ENTER_NOTIMPL("(This = %p, steam_id_game_server = %#" PRIx64 ", server_ip = %#x, server_port = %u)", VOIDPTR(This), steam_id_game_server.raw, server_ip, server_port);
}

MEMBER steam_api_call_t ISteamUser_RequestEncryptedAppTicket(struct ISteamUser *iface, void *data, int data_size)
{
	struct ISteamUserImpl *This = impl_from_ISteamUser(iface);
	struct steam_callback_data_user_encrypted_app_ticket_response encrypted_app_ticket_response;
	steam_api_call_t api_call;

	LOG_ENTER("(This = %p, data = %p, data_size = %d)", VOIDPTR(This), data, data_size);

	encrypted_app_ticket_response.result = STEAM_RESULT_FAIL;

	api_call = callbacks_await_api_call_result_output();
	callbacks_dispatch_api_call_result_output(api_call, STEAM_CALLBACK_TYPE_USER_ENCRYPTED_APP_TICKET_RESPONSE, STEAM_TRUE, &encrypted_app_ticket_response, sizeof(encrypted_app_ticket_response));
	return api_call;
}

struct ISteamUser *SteamUser_generic(const char *version)
{
	static const struct
	{
		const char *name;
		struct ISteamUser *(*iface_getter)(void);
	} ifaces[] = {
		{ STEAMUSER_INTERFACE_VERSION_004, SteamUser004 },
		{ STEAMUSER_INTERFACE_VERSION_016, SteamUser016 },
		{ STEAMUSER_INTERFACE_VERSION_017, SteamUser017 },
		{ STEAMUSER_INTERFACE_VERSION_018, SteamUser018 },
		{ STEAMUSER_INTERFACE_VERSION_019, SteamUser019 },
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
		steam_user_version = STEAMUSER_INTERFACE_VERSION_019;

		WARN("ISteamUser: No version specified, defaulting to \"%s\".", debug_str(steam_user_version));
	}

	if (!cached_iface)
		cached_iface = SteamUser_generic(steam_user_version);

	return cached_iface;
}
