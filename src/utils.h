#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h> /* offsetof() */
#include <stdio.h>

#define EXPORT __attribute__((visibility("default")))

#define VOIDPTR(x) ((void *)x)
#define INVAL_PTR VOIDPTR(0xbeefbeef)

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define CONTAINER_OF(ptr, type, member) ((type *)((uintptr_t)(ptr) - offsetof(type, member)))

#define LOG_ENTER(str, ...) do { fprintf(stderr, "%s" str "\n", __func__, __VA_ARGS__); } while (0)
#define LOG_ENTER0(str) do { LOG_ENTER(str "%c", '\0'); } while (0)

#define LOG_ENTER_NOTIMPL(str, ...) do { LOG_ENTER(str ": Not implemented yet!", __VA_ARGS__); } while (0)
#define LOG_ENTER0_NOTIMPL(str) do { LOG_ENTER_NOTIMPL(str "%c", '\0'); } while (0)

#define DEBUG(str, ...) do { fprintf(stderr, "DEBUG: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); } while (0)
#define DEBUG0(str) do { DEBUG(str "%c", '\0'); } while (0)

#define WARN(str, ...) do { fprintf(stderr, "WARN: %s:%u: " str "\n", __FILE__, __LINE__, __VA_ARGS__); } while (0)
#define WARN0(str) do { WARN(str "%c", '\0'); } while (0)

static inline const char *debug_str(const char *str) {
	return str ? str : "(null)";
}

#endif /* UTILS_H */
