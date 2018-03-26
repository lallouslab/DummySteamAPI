#define _POSIX_C_SOURCE 200809L

#include <pthread.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h> /* mkdir() */
#include <sys/types.h>
#include <unistd.h>

#include "debug.h"
#include "utils.h"
#include "os/os.h"

struct dsa_os_mutex
{
	pthread_mutex_t mtx;
};

static struct
{
	char *home_dir;
	char *steam_dir;
} os_ctx;

EXPORT int dsa_os_init(void)
{
	const char steam_dir[] = "/.local/share/Steam";

	/* home_dir */

	os_ctx.home_dir = dsa_utils_strdup(getenv("HOME"));
	if (!os_ctx.home_dir)
	{
		struct passwd *pw;

		pw = getpwuid(geteuid());
		if (pw)
			os_ctx.home_dir = dsa_utils_strdup(pw->pw_dir);
	}

	if (!os_ctx.home_dir)
	{
		WARN0("Failed to define user home directory.");
		os_ctx.home_dir = dsa_utils_strdup("${HOME}");
	}

	/* steam_dir */

	os_ctx.steam_dir = dsa_utils_concat(os_ctx.home_dir, steam_dir, NULL);
	if (!os_ctx.steam_dir)
	{
		WARN0("Failed to define steam directory.");
		os_ctx.steam_dir = dsa_utils_strdup("${STEAM_DIR}");
	}

	return 0;
}

EXPORT int dsa_os_deinit(void)
{
	dsa_utils_free_ptr(&os_ctx.home_dir);
	dsa_utils_free_ptr(&os_ctx.steam_dir);

	return 0;
}

EXPORT const char *dsa_os_get_home_dir(void)
{
	return os_ctx.home_dir;
}

EXPORT const char *dsa_os_get_steam_dir(void)
{
	return os_ctx.steam_dir;
}

EXPORT struct dsa_os_mutex *dsa_os_mutex_create(void)
{
	struct dsa_os_mutex *mtx;
	pthread_mutexattr_t attr;
	int ret;

	mtx = malloc(sizeof(*mtx));
	if (!mtx)
		return NULL;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

	ret = pthread_mutex_init(&mtx->mtx, &attr);
	if (ret != 0)
	{
		free(mtx);
		return NULL;
	}

	pthread_mutexattr_destroy(&attr);

	return mtx;
}

EXPORT void dsa_os_mutex_destroy(struct dsa_os_mutex *mtx)
{
	pthread_mutex_destroy(&mtx->mtx);
	free(mtx);
}

EXPORT int dsa_os_mutex_lock(struct dsa_os_mutex *mtx)
{
	int ret;

	ret = pthread_mutex_lock(&mtx->mtx);
	if (ret != 0)
		return -1;
	return 0;
}

EXPORT int dsa_os_mutex_trylock(struct dsa_os_mutex *mtx)
{
	int ret;

	ret = pthread_mutex_trylock(&mtx->mtx);
	if (ret != 0)
		return -1;
	return 0;
}

EXPORT int dsa_os_mutex_unlock(struct dsa_os_mutex *mtx)
{
	int ret;

	ret = pthread_mutex_unlock(&mtx->mtx);
	if (ret != 0)
		return -1;
	return 0;
}

EXPORT int dsa_os_mkdir(const char *path)
{
	return mkdir(path, 0777);
}
