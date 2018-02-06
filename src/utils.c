#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

static int dsa_log_level;

int dsa_utils_get_log_level(void)
{
	return dsa_log_level;
}

int dsa_utils_set_log_level(int lvl)
{
	dsa_log_level = lvl;

	return 0;
}

long dsa_utils_file_get_size(FILE *fp)
{
	long old, size;

	old = ftell(fp);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, old, SEEK_SET);

	return size;
}

int dsa_utils_init(void)
{
	const char *data;

	dsa_log_level = DSA_LOG_LEVEL_WARN;

	data = getenv("DSA_LOG_LEVEL");
	if (data)
		dsa_log_level = strtoul(data, NULL, 0);

	return 0;
}
