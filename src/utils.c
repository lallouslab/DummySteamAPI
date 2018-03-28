#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

char *dsa_utils_concat(const char *s1, ...)
{
	va_list ap;
	const char *s;
	size_t size = 0;
	char *dst;
	char *d;

	va_start(ap, s1);

	s = s1;

	while (s)
	{
		size += strlen(s);

		s = va_arg(ap, const char *);
	}

	va_end(ap);

	dst = malloc(size + 1);
	if (!dst)
		return NULL;

	d = dst;

	va_start(ap, s1);

	s = s1;

	while (s)
	{
		size_t len;

		len = strlen(s);
		memcpy(d, s, len);
		d += len;

		s = va_arg(ap, const char *);
	}

	va_end(ap);

	*d = '\0';

	return dst;
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

void dsa_utils_free_ptr(void *ptr)
{
	void **p = ptr;

	if (!*p)
		return;

	free(*p);
	*p = NULL;
}

void *dsa_utils_memdup(const void *data, size_t size)
{
	char *dst;

	if (!data)
		return NULL;

	dst = malloc(size);
	if (!dst)
		return NULL;

	return memcpy(dst, data, size);
}

char *dsa_utils_strdup(const char *s)
{
	if (!s)
		return NULL;

	return dsa_utils_memdup(s, strlen(s) + 1);
}
