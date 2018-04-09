#include <stddef.h>
#include <stdlib.h>

#include "debug.h"
#include "steam.h"
#include "macros.h"

enum dsa_cfg
{
	/* DSA_CFG_LOG_LEVEL should be the first to avoid printing unwanted log messages. */
	DSA_CFG_LOG_LEVEL = 0,
	DSA_CFG_ORIG_STEAM_API_LIB,
	DSA_CFG_STEAM_APP_ID,
	DSA_CFG_STEAM_GAME_ID,
	DSA_CFG_STEAM_USER_ID
};

struct dsa_cfg_var
{
	const char *name;
	const char *val;
	unsigned int is_defined : 1;
};

#define DSA_CFG_VAR(name, default_val) { name, default_val, 0 }
#define DSA_CFG_VAR0(name) DSA_CFG_VAR(name, "${" name "}")

static struct dsa_cfg_var cfg_vars[] = {
	[DSA_CFG_LOG_LEVEL]          = DSA_CFG_VAR("DSA_LOG_LEVEL", TO_STR(DSA_LOG_LEVEL_WARN)),
	[DSA_CFG_ORIG_STEAM_API_LIB] = DSA_CFG_VAR0("DSA_ORIG_STEAM_API_LIB"),
	[DSA_CFG_STEAM_APP_ID]       = DSA_CFG_VAR("SteamAppId", "1"),
	[DSA_CFG_STEAM_GAME_ID]      = DSA_CFG_VAR("SteamGameId", "1"),
	[DSA_CFG_STEAM_USER_ID]      = DSA_CFG_VAR("STEAM_USER_ID", "1")
};

#undef DSA_CFG_VAR0
#undef DSA_CFG_VAR

int dsa_config_init(void)
{
	for (size_t i = 0; i < ARRAY_SIZE(cfg_vars); i++)
	{
		struct dsa_cfg_var *cfg_var = &cfg_vars[i];
		const char *data;

		data = getenv(cfg_var->name);
		if (!data)
		{
			WARN("Config var %s not defined. Defaulting to %s=\"%s\".", cfg_var->name, cfg_var->name, cfg_var->val);
			continue;
		}

		cfg_var->val = data;
		cfg_var->is_defined = 1;

		DEBUG("Config var %s=\"%s\".", cfg_var->name, cfg_var->val);
	}

	return 0;
}

enum dsa_log_level dsa_config_get_log_level(void)
{
	return strtoul(cfg_vars[DSA_CFG_LOG_LEVEL].val, NULL, 0);
}

const char *dsa_config_get_orig_steam_api_lib(void)
{
	return cfg_vars[DSA_CFG_ORIG_STEAM_API_LIB].val;
}

const char *dsa_config_get_steam_app_id_str(void)
{
	return cfg_vars[DSA_CFG_STEAM_APP_ID].val;
}

steam_app_id_t dsa_config_get_steam_app_id(void)
{
	return strtoul(dsa_config_get_steam_app_id_str(), NULL, 0);
}

union CGameID dsa_config_get_steam_game_id(void)
{
	union CGameID game_id;

	game_id.raw = strtoull(cfg_vars[DSA_CFG_STEAM_GAME_ID].val, NULL, 0);
	return game_id;
}

const char *dsa_config_get_steam_user_id_str(void)
{
	return cfg_vars[DSA_CFG_STEAM_USER_ID].val;
}

steam_user_t dsa_config_get_steam_user_id(void)
{
	return strtoul(dsa_config_get_steam_user_id_str(), NULL, 0);
}
