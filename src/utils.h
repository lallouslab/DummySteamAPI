#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h> /* offsetof() */
#include <stdlib.h>
#include <stdio.h>

#define EXPORT __attribute__((visibility("default")))
#define CONSTRUCTOR __attribute__((constructor))

#define INVAL_PTR NULL
#define VOIDPTR(x) ((void *)x)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define CONTAINER_OF(ptr, type, member) ((type *)((uintptr_t)(ptr) - offsetof(type, member)))

#define DSA_LOG_LEVEL_NONE 0
#define DSA_LOG_LEVEL_WARN 1
#define DSA_LOG_LEVEL_DEBUG 2

#define DEBUG(str, ...) \
	do { \
		if (dsa_utils_get_log_level() >= DSA_LOG_LEVEL_DEBUG) { \
			fprintf(stderr, "DEBUG: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); \
		} \
	} while (0)
#define DEBUG0(str) DEBUG(str "%s", "");

#define WARN(str, ...) \
	do { \
		if (dsa_utils_get_log_level() >= DSA_LOG_LEVEL_WARN) { \
			fprintf(stderr, "WARN: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); \
		} \
	} while (0)
#define WARN0(str) WARN(str "%s", "");

#define LOG_ENTER(str, ...) DEBUG("%s" str, __func__, __VA_ARGS__)
#define LOG_ENTER0(str) LOG_ENTER(str "%s", "")

#define LOG_ENTER_NOTIMPL(str, ...) LOG_ENTER(str ": Not implemented yet!", __VA_ARGS__)
#define LOG_ENTER0_NOTIMPL(str) LOG_ENTER_NOTIMPL(str "%s", "")

typedef void (*PFN_VOID)(void);

static inline const char *debug_str(const char *str) {
	return str ? str : "(null)";
}

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

int dsa_utils_get_log_level(void);
int dsa_utils_set_log_level(int lvl);
long dsa_utils_file_get_size(FILE *fp);
int dsa_utils_init(void);

#endif /* UTILS_H */
