#ifndef MACROS_H
#define MACROS_H 1

#include <stddef.h> /* offsetof() */
#include <stdlib.h>

#define EXPORT __attribute__((visibility("default")))
#define PACKED_STRUCT struct __attribute__((packed))

#if CONFIG_OS_WINDOWS
# define DECL_FUNC_WITH_MEMBER_CALLBACK_PARAM __extension__
# define MEMBER_CALLBACK_PARAM __attribute__((thiscall))
# define MEMBER DECL_FUNC_WITH_MEMBER_CALLBACK_PARAM MEMBER_CALLBACK_PARAM
# pragma GCC diagnostic ignored "-Wformat"
#else
# define DECL_FUNC_WITH_MEMBER_CALLBACK_PARAM
# define MEMBER_CALLBACK_PARAM
# define MEMBER
#endif

#define INVAL_PTR NULL
#define VOIDPTR(x) ((void *)x)
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define CONTAINER_OF(ptr, type, member) ((type *)((uintptr_t)(ptr) - offsetof(type, member)))
#define TO_STR_(x) #x
#define TO_STR(x) TO_STR_(x)

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

#endif /* MACROS_H */
