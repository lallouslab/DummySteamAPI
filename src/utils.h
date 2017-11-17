#ifndef UTILS_H
#define UTILS_H 1

#include <stddef.h> /* offsetof() */
#include <stdio.h>

#define VOIDPTR(x) ((void *)x)

#define CONTAINER_OF(ptr, type, member) ((type *)((uintptr_t)(ptr) - offsetof(type, member)))

#define log_enter(str, ...) do { fprintf(stderr, "%s" str "\n", __func__, __VA_ARGS__); } while (0)
#define log_enter0(str) do { log_enter(str "%s", ""); } while (0)

#define log_enter_notimpl(str, ...) do { log_enter(str ": Not implemented yet!", __VA_ARGS__); } while (0)
#define log_enter_notimpl0(str) do { log_enter_notimpl(str "%s", ""); } while (0)

static inline const char *debug_str(const char *str) {
	return str ? str : "(null)";
}

#endif /* UTILS_H */
