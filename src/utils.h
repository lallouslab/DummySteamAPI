#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h>
#include <stdio.h>

char *dsa_utils_concat(const char *s1, ...);
long dsa_utils_file_get_size(FILE *fp);
void dsa_utils_free_ptr(void *ptr);
void *dsa_utils_memdup(const void *data, size_t size);
char *dsa_utils_strdup(const char *str);

#endif /* UTILS_H */
