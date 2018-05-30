#ifndef MACROS_H
#define MACROS_H 1

#include <stddef.h> /* offsetof() */
#include <stdlib.h>

#define PACKED_STRUCT struct __attribute__((packed))

#if CONFIG_OS_WINDOWS

# pragma GCC diagnostic ignored "-Wformat"

# define EXPORT __declspec(dllexport)

# define DECL_FUNC_WITH_MEMBER_CALLBACK_PARAM __extension__
# define MEMBER_CALLBACK_PARAM __attribute__((thiscall)) __attribute__((ms_abi))
# define MEMBER DECL_FUNC_WITH_MEMBER_CALLBACK_PARAM MEMBER_CALLBACK_PARAM
# define DSA_MEMBER_RETURN_STRUCT0(ret_type, ret_param, name, param_this) MEMBER ret_type *name(param_this, ret_type *ret_param)
# define DSA_MEMBER_RETURN_STRUCT(ret_type, ret_param, name, param_this, ...) MEMBER ret_type *name(param_this, ret_type *ret_param, __VA_ARGS__)
# define DSA_CALL_MEMBER_RETURN_STRUCT0(pfn, ret_ptr, param_this) ((void)(pfn)((param_this), (ret_ptr)))
# define DSA_CALL_MEMBER_RETURN_STRUCT(pfn, ret_ptr, param_this, ...) ((void)(pfn)((param_this), (ret_ptr), __VA_ARGS__))
# define DSA_MEMBER_RETURN_STRUCT_RETURN(ret_param, value) do { *(ret_param) = (value); return (ret_param); } while (0)

#else

# define EXPORT __attribute__((visibility("default")))

# define DECL_FUNC_WITH_MEMBER_CALLBACK_PARAM
# define MEMBER_CALLBACK_PARAM
# define MEMBER
# define DSA_MEMBER_RETURN_STRUCT0(ret_type, ret_param, name, param_this) MEMBER ret_type name(param_this)
# define DSA_MEMBER_RETURN_STRUCT(ret_type, ret_param, name, param_this, ...) MEMBER ret_type name(param_this, __VA_ARGS__)
# define DSA_CALL_MEMBER_RETURN_STRUCT0(pfn, ret_ptr, param_this) ((void)(*(ret_ptr) = (pfn)((param_this))))
# define DSA_CALL_MEMBER_RETURN_STRUCT(pfn, ret_ptr, param_this, ...) ((void)(*(ret_ptr) = (pfn)((param_this), __VA_ARGS__)))
# define DSA_MEMBER_RETURN_STRUCT_RETURN(ret_param, value) do { return (value); } while(0)

#endif

#define DSA_PFN_MEMBER_RETURN_STRUCT0(ret_type, ret_param, name, param_this) DSA_MEMBER_RETURN_STRUCT0(ret_type, ret_param, (*name), param_this)
#define DSA_PFN_MEMBER_RETURN_STRUCT(ret_type, ret_param, name, param_this, ...) DSA_MEMBER_RETURN_STRUCT(ret_type, ret_param, (*name), param_this, __VA_ARGS__)

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
