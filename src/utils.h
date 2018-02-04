#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h> /* offsetof() */
#include <stdio.h>

#define EXPORT __attribute__((visibility("default")))
#define CONSTRUCTOR __attribute__((constructor))

#define VOIDPTR(x) ((void *)x)
#define INVAL_PTR VOIDPTR(0xbeefbeef)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define CONTAINER_OF(ptr, type, member) ((type *)((uintptr_t)(ptr) - offsetof(type, member)))

#define DEBUG(str, ...) do { fprintf(stderr, "DEBUG: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); } while (0)
#define DEBUG0(str) DEBUG(str "%s", "");

#define WARN(str, ...) do { fprintf(stderr, "WARN: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); } while (0)
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

long dsa_utils_file_get_size(FILE *fp);

#endif /* UTILS_H */
