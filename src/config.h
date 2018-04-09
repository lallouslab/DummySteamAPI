#ifndef CONFIG_H
#define CONFIG_H 1

#include "debug.h"
#include "steam.h"

int dsa_config_init(void);
enum dsa_log_level dsa_config_get_log_level(void);
const char *dsa_config_get_orig_steam_api_lib(void);
const char *dsa_config_get_steam_app_id_str(void);
steam_app_id_t dsa_config_get_steam_app_id(void);
union CGameID dsa_config_get_steam_game_id(void);
const char *dsa_config_get_steam_user_id_str(void);
steam_user_t dsa_config_get_steam_user_id(void);

#endif /* CONFIG_H */
