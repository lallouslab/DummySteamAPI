#ifndef DEBUG_H
#define DEBUG_H 1

#include <stdio.h>

#include "CCallback.h"

enum dsa_log_level
{
	DSA_LOG_LEVEL_NONE = 0,
	DSA_LOG_LEVEL_WARN,
	DSA_LOG_LEVEL_DEBUG
};

#define DEBUG(str, ...) \
	do { \
		if (dsa_debug_get_log_level() >= DSA_LOG_LEVEL_DEBUG) { \
			fprintf(dsa_debug_get_log_file(), "DEBUG: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); \
			fflush(dsa_debug_get_log_file()); \
		} \
	} while (0)
#define DEBUG0(str) DEBUG(str "%s", "");

#define WARN(str, ...) \
	do { \
		if (dsa_debug_get_log_level() >= DSA_LOG_LEVEL_WARN) { \
			fprintf(dsa_debug_get_log_file(), "WARN: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); \
			fflush(dsa_debug_get_log_file()); \
		} \
	} while (0)
#define WARN0(str) WARN(str "%s", "");

#define LOG_ENTER(str, ...) DEBUG("%s" str, __func__, __VA_ARGS__)
#define LOG_ENTER0(str) LOG_ENTER(str "%s", "")

#define LOG_ENTER_NOTIMPL(str, ...) LOG_ENTER(str ": Not implemented yet!", __VA_ARGS__)
#define LOG_ENTER0_NOTIMPL(str) LOG_ENTER_NOTIMPL(str "%s", "")


static inline const char *debug_str(const char *str) {
	return str ? str : "(null)";
}

enum dsa_log_level dsa_debug_get_log_level(void);
void dsa_debug_set_log_level(enum dsa_log_level lvl);
FILE *dsa_debug_get_log_file(void);
const char *dsa_debug_steam_callback_type(enum steam_callback_type type);

#endif /* DEBUG_H */
