#include <userenv.h>
#include <windows.h>

#include "debug.h"
#include "dsa.h"
#include "utils.h"
#include "os/os.h"

#ifndef GetCurrentProcessToken
# define GetCurrentProcessToken() ((HANDLE)~(ULONG_PTR)3)
#endif

struct dsa_os_mutex
{
	CRITICAL_SECTION cs;
};

static struct
{
	char *home_dir;
	char *steam_dir;
} os_ctx;

static int dsa_os_init(void)
{
	BOOL ret;
	LONG retl;
	HANDLE process_tok;
	DWORD size;
	HKEY steam_key;

	os_ctx.home_dir = NULL;
	os_ctx.steam_dir = NULL;

	process_tok = GetCurrentProcessToken();

	/* home_dir */

	size = 0;

	ret = GetUserProfileDirectoryA(process_tok, NULL, &size);
	if (ret)
	{
		os_ctx.home_dir = malloc(size);
		ret = GetUserProfileDirectoryA(process_tok, os_ctx.home_dir, &size);
	}

	if (!ret)
	{
		WARN0("Failed to define user home directory.");
		os_ctx.home_dir = dsa_utils_strdup("${HOME}");
	}

	/* steam_dir */

	retl = RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Valve\\Steam", 0, KEY_READ, &steam_key);
	if (retl == ERROR_SUCCESS)
	{
		size = 0;

		retl = RegGetValueA(steam_key, NULL, "SteamPath", RRF_RT_REG_SZ, NULL, NULL, &size);
		if (retl == ERROR_SUCCESS)
		{
			os_ctx.steam_dir = malloc(size);
			retl = RegGetValueA(steam_key, NULL, "SteamPath", RRF_RT_REG_SZ, NULL, os_ctx.steam_dir, &size);
		}

		RegCloseKey(steam_key);
	}

	if (retl != ERROR_SUCCESS)
	{
		WARN0("Failed to define steam directory.");
		os_ctx.steam_dir = dsa_utils_strdup("${STEAM_DIR}");
	}

	dsa_init();

	return 0;
}

static int dsa_os_deinit(void)
{
	dsa_deinit();

	dsa_utils_free_ptr(&os_ctx.home_dir);
	dsa_utils_free_ptr(&os_ctx.steam_dir);

	return 0;
}

const char *dsa_os_get_home_dir(void)
{
	return os_ctx.home_dir;
}

const char *dsa_os_get_steam_dir(void)
{
	return os_ctx.steam_dir;
}

struct dsa_os_mutex *dsa_os_mutex_create(void)
{
	struct dsa_os_mutex *mtx;

	mtx = malloc(sizeof(*mtx));
	if (!mtx)
		return NULL;

	InitializeCriticalSectionAndSpinCount(&mtx->cs, 4000);

	return mtx;
}

void dsa_os_mutex_destroy(struct dsa_os_mutex *mtx)
{
	DeleteCriticalSection(&mtx->cs);
	free(mtx);
}

int dsa_os_mutex_lock(struct dsa_os_mutex *mtx)
{
	EnterCriticalSection(&mtx->cs);
	return 0;
}

int dsa_os_mutex_trylock(struct dsa_os_mutex *mtx)
{
	BOOL ret;

	ret = TryEnterCriticalSection(&mtx->cs);
	return ret ? 0 : -1;
}

int dsa_os_mutex_unlock(struct dsa_os_mutex *mtx)
{
	LeaveCriticalSection(&mtx->cs);
	return 0;
}

int dsa_os_mkdir(const char *path)
{
	BOOL ret;

	ret = CreateDirectoryA(path, NULL);
	return ret ? 0 : -1;
}

EXPORT BOOL WINAPI DllMain(HINSTANCE inst, DWORD reason, void *res)
{
	(void)inst;
	(void)res;

	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			dsa_os_init();
			return TRUE;

		case DLL_PROCESS_DETACH:
			dsa_os_deinit();
			break;

		default:
			break;
	}

	return FALSE;
}
