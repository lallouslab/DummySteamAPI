#include <stdio.h>

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
