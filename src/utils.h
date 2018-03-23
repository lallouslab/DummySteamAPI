#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h> /* offsetof() */
#include <stdio.h>
#include <stdlib.h>

#define CONSTRUCTOR __attribute__((constructor))
#define EXPORT __attribute__((visibility("default")))
#define PACKED_STRUCT struct __attribute__((packed))

#define INVAL_PTR NULL
#define VOIDPTR(x) ((void *)x)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define CONTAINER_OF(ptr, type, member) ((type *)((uintptr_t)(ptr) - offsetof(type, member)))

typedef void (*PFN_VOID)(void);

static inline PFN_VOID voidptr_to_pfn(void *ptr) {
	union
	{
		void *voidptr;
		PFN_VOID pfn;
	} s;

	s.voidptr = ptr;

	return s.pfn;
}

static inline void *pfn_to_voidptr(PFN_VOID pfn) {
	union
	{
		void *voidptr;
		PFN_VOID pfn;
	} s;

	s.pfn = pfn;

	return s.voidptr;
}

long dsa_utils_file_get_size(FILE *fp);
int dsa_utils_init(void);
char *dsa_utils_strdup(const char *str);

#endif /* UTILS_H */
