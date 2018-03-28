#include <stdlib.h>

#include "debug.h"

int dsa_config_init(void)
{
	const char *data;

	data = getenv("DSA_LOG_LEVEL");
	if (data)
		dsa_debug_set_log_level(strtoul(data, NULL, 0));

	return 0;
}
