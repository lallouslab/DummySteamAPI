#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "utils.h"

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

	data = getenv("DSA_LOG_LEVEL");
	if (data)
		dsa_debug_set_log_level(strtoul(data, NULL, 0));

	return 0;
}

char *dsa_utils_strdup(const char *s)
{
	size_t size;
	char *dst;

	if (!s)
		return NULL;

	size = strlen(s) + 1;

	dst = malloc(size);
	if (!dst)
		return NULL;

	return memcpy(dst, s, size);
}
