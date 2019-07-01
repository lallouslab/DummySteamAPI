#include <limits.h>
#include <string.h>

#include <userenv.h>
#include <windows.h>

#include "debug.h"
#include "dsa.h"
#include "utils.h"
#include "os/os.h"

#ifndef GetCurrentProcessToken
# define GetCurrentProcessToken() ((HANDLE)~(ULONG_PTR)3)
#endif

struct dsa_os_thread
{
	dsa_os_thread_entry_point_t ep;
	void *arg;
	HANDLE handle;
};

struct dsa_os_mutex
{
	CRITICAL_SECTION cs;
};

struct dsa_os_semaphore
{
	HANDLE handle;
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

	dsa_init();

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

static DWORD WINAPI dsa_os_thrd_wrapper(void *arg)
{
	struct dsa_os_thread *thrd = (struct dsa_os_thread *)arg;

	thrd->ep(thrd->arg);
	return 0;
}

struct dsa_os_thread *dsa_os_thread_create(dsa_os_thread_entry_point_t ep, void *arg)
{
	struct dsa_os_thread *thrd;

	thrd = malloc(sizeof(*thrd));
	if (!thrd)
		return NULL;

	thrd->ep = ep;
	thrd->arg = arg;

	thrd->handle = CreateThread(NULL, 0, dsa_os_thrd_wrapper, thrd, 0, NULL);
	if (!thrd->handle)
	{
		free(thrd);
		return NULL;
	}

	return thrd;
}

void dsa_os_thread_destroy(struct dsa_os_thread *thrd)
{
	free(thrd);
}

int dsa_os_thread_kill(struct dsa_os_thread *thrd)
{
	BOOL bret;

	bret = TerminateThread(thrd->handle, 0);
	if (!bret)
		return -1;
	return 0;
}

int dsa_os_thread_wait(struct dsa_os_thread *thrd)
{
	DWORD dwret;

	dwret = WaitForSingleObject(thrd->handle, INFINITE);
	if (dwret != WAIT_OBJECT_0)
		return -1;
	return 0;
}

int dsa_os_thread_trywait(struct dsa_os_thread *thrd)
{
	DWORD dwret;

	dwret = WaitForSingleObject(thrd->handle, 0);
	if (dwret != WAIT_OBJECT_0)
		return -1;
	return 0;
}

void dsa_os_thread_yield(void)
{
	SwitchToThread();
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

struct dsa_os_semaphore *dsa_os_semaphore_create(unsigned int val)
{
	struct dsa_os_semaphore *sem;

	sem = malloc(sizeof(*sem));
	if (!sem)
		return NULL;

	sem->handle = CreateSemaphoreA(NULL, val, LONG_MAX, NULL);
	if (!sem->handle)
	{
		free(sem);
		return NULL;
	}

	return sem;
}

void dsa_os_semaphore_destroy(struct dsa_os_semaphore *sem)
{
	CloseHandle(sem->handle);
	free(sem);
}

int dsa_os_semaphore_signal(struct dsa_os_semaphore *sem)
{
	BOOL bret;

	bret = ReleaseSemaphore(sem->handle, 1, NULL);
	if (!bret)
		return -1;
	return 0;
}

int dsa_os_semaphore_wait(struct dsa_os_semaphore *sem)
{
	DWORD dwret;

	dwret = WaitForSingleObject(sem->handle, INFINITE);
	if (dwret != WAIT_OBJECT_0)
		return -1;
	return 0;
}

int dsa_os_semaphore_trywait(struct dsa_os_semaphore *sem)
{
	DWORD dwret;

	dwret = WaitForSingleObject(sem->handle, 0);
	if (dwret != WAIT_OBJECT_0)
		return -1;
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
