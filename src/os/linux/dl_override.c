#define _GNU_SOURCE 1

#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"
#include "macros.h"

typedef void *(*PFN_DLOPEN)(const char *, int);
typedef void *(*PFN_DLMOPEN)(Lmid_t lmid, const char *, int);

extern void *__libc_dlopen_mode(const char *, int);

static PFN_DLOPEN dlopen_ptr = NULL;
static PFN_DLMOPEN dlmopen_ptr = NULL;

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

		dlopen_ptr = (PFN_DLOPEN)voidptr_to_pfn(dlsym(libdl_handle, "dlopen"));
		if (!dlopen_ptr)
		{
			WARN0("Failed to intercept dlopen(): Failed to locate dlopen inside libdl.so.2.");
			return -1;
		}

		dlmopen_ptr = (PFN_DLMOPEN)voidptr_to_pfn(dlsym(libdl_handle, "dlmopen"));
		if (!dlmopen_ptr)
		{
			WARN0("Failed to intercept dlmopen(): Failed to locate dlmopen inside libdl.so.2.");
			return -1;
		}
	}

	DEBUG0("dlopen() interception initialized.");

	return 0;
}

static int is_steam_lib(const char *filename)
{
	static const char *libs_name[] = {
		"libCSteamworks.so",
		"libsteam_api.so",
		"steamclient.so",
		NULL
	};
	int result;
	int i;

	if (!filename)
		return -1;

	i = 0;
	while (libs_name[i])
	{
		const char *lib_name = libs_name[i];
		size_t lib_name_len;
		size_t len;

		i++;

		lib_name_len = strlen(lib_name);
		len = strlen(filename);

		if (len < lib_name_len)
			continue;

		result = strcmp(&filename[len - lib_name_len], lib_name);
		if (result == 0)
			return 0;
	}

	return -1;
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

	result = is_steam_lib(filename);
	if (result < 0)
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

EXPORT void *dlmopen(Lmid_t lmid, const char *filename, int flags)
{
	int result;
	Dl_info this_sym_info;

	DEBUG("dlmopen(%ld, \"%s\", %x)", lmid, debug_str(filename), flags);

	if (!dlmopen_ptr)
		dl_override_init();

	if (!dlmopen_ptr)
	{
		WARN0("Unable to call original dlmopen()!");
		return NULL;
	}

	result = is_steam_lib(filename);
	if (result < 0)
	{
		DEBUG0("No need to intercept.");
		goto done;
	}

	result = dladdr(pfn_to_voidptr((PFN_VOID)dl_override_init), &this_sym_info);
	if (!result || !this_sym_info.dli_fname)
	{
		WARN("Failed to intercept dlmopen() of \"%s\": dladdr() failed to retrieve the DummySteamAPI library path.", filename);
		goto done;
	}

	DEBUG("Intercepting dlmopen() of \"%s\" => \"%s\".", filename, this_sym_info.dli_fname);

	filename = this_sym_info.dli_fname;

done:
	return dlmopen_ptr(lmid, filename, flags);
}
