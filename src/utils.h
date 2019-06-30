#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h>
#include <stdio.h>

static inline unsigned int dsa_minu(unsigned int a, unsigned int b) {
	return a < b ? a : b;
}

static inline unsigned int dsa_maxu(unsigned int a, unsigned int b) {
	return a > b ? a : b;
}

char *dsa_utils_concat(const char *s1, ...);
long dsa_utils_file_get_size(FILE *fp);
char *dsa_utils_file_get_contents(const char *path, size_t *size);
void dsa_utils_free_ptr(void *ptr);
void *dsa_utils_memdup(const void *data, size_t size);
char *dsa_utils_strdup(const char *str);

#endif /* UTILS_H */
