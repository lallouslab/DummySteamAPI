#define _GNU_SOURCE 1

#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "macros.h"

#define LIBSTEAM_API_LIB_NAME "libsteam_api.so"

typedef void *(*PFN_DLOPEN)(const char *, int);

extern void *__libc_dlopen_mode(const char *, int);
extern void *__libc_dlsym(void *, const char *);

static PFN_DLOPEN dlopen_ptr = NULL;

int dl_override_init(void)
{
	if (!dlopen_ptr)
	{
		void *libdl_handle;

		libdl_handle = __libc_dlopen_mode("libdl.so.2", RTLD_LOCAL | RTLD_NOW);
		if (!libdl_handle)
		{
			WARN0("Failed to intercept dlopen(): Failed to open libdl.so.2.");
			return -1;
		}

		dlopen_ptr = (PFN_DLOPEN)voidptr_to_pfn(__libc_dlsym(libdl_handle, "dlopen"));
		if (!dlopen_ptr)
		{
			WARN0("Failed to intercept dlopen(): Failed to locate dlopen inside libdl.so.2.");
			return -1;
		}
	}

	DEBUG0("dlopen() interception initialized.");

	return 0;
}

EXPORT void *dlopen(const char *filename, int flags)
{
	int result;
	Dl_info this_sym_info;

	DEBUG("dlopen(\"%s\", %x)", debug_str(filename), flags);

	if (!dlopen_ptr)
		dl_override_init();

	if (!dlopen_ptr)
	{
		WARN0("Unable to call original dlopen()!");
		return NULL;
	}

	result = -1;

	if (filename)
		result = strcmp(filename, LIBSTEAM_API_LIB_NAME);

	if (result != 0)
	{
		DEBUG0("No need to intercept.");
		goto done;
	}

	result = dladdr(pfn_to_voidptr((PFN_VOID)dl_override_init), &this_sym_info);
	if (!result || !this_sym_info.dli_fname)
	{
		WARN("Failed to intercept dlopen() of \"%s\": dladdr() failed to retrieve the DummySteamAPI library path.", filename);
		goto done;
	}

	DEBUG("Intercepting dlopen() of \"%s\" => \"%s\".", filename, this_sym_info.dli_fname);

	filename = this_sym_info.dli_fname;

done:
	return dlopen_ptr(filename, flags);
}
