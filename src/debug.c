#include "debug.h"

static enum dsa_log_level log_level = DSA_LOG_LEVEL_WARN;

enum dsa_log_level dsa_debug_get_log_level(void)
{
	return log_level;
}

void dsa_debug_set_log_level(enum dsa_log_level lvl)
{
	log_level = lvl;
}