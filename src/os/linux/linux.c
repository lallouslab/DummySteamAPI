#define _GNU_SOURCE 1
#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>

#include <sched.h>
#include <pthread.h>
#include <pwd.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/stat.h> /* mkdir() */
#include <sys/types.h>
#include <unistd.h>

#include "debug.h"
#include "dsa.h"
#include "utils.h"
#include "os/os.h"

#include "dl_override.h"

#define CONSTRUCTOR __attribute__((constructor))
#define DESTRUCTOR __attribute__((destructor))

struct dsa_os_thread
{
	dsa_os_thread_entry_point_t ep;
	void *arg;
	pthread_t thrd;
};

struct dsa_os_mutex
{
	pthread_mutex_t mtx;
};

struct dsa_os_semaphore
{
	sem_t sem;
};

static struct
{
	char *home_dir;
	char *steam_dir;
} os_ctx;


CONSTRUCTOR static void dsa_os_init(void)
{
	const char steam_dir[] = "/.local/share/Steam";

	dsa_init();

	dl_override_init();

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
}

DESTRUCTOR static void dsa_os_deinit(void)
{
	dsa_deinit();

	dsa_utils_free_ptr(&os_ctx.home_dir);
	dsa_utils_free_ptr(&os_ctx.steam_dir);
}

const char *dsa_os_get_home_dir(void)
{
	return os_ctx.home_dir;
}

const char *dsa_os_get_steam_dir(void)
{
	return os_ctx.steam_dir;
}

static void *dsa_os_thrd_wrapper(void *arg)
{
	struct dsa_os_thread *thrd = (struct dsa_os_thread *)arg;

	thrd->ep(thrd->arg);
	return NULL;
}

struct dsa_os_thread *dsa_os_thread_create(dsa_os_thread_entry_point_t ep, void *arg)
{
	struct dsa_os_thread *thrd;
	int ret;

	thrd = malloc(sizeof(*thrd));
	if (!thrd)
		return NULL;

	thrd->ep = ep;
	thrd->arg = arg;

	ret = pthread_create(&thrd->thrd, NULL, dsa_os_thrd_wrapper, thrd);
	if (ret != 0)
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
	int ret;

	ret = pthread_kill(thrd->thrd, SIGKILL);
	if (ret != 0)
		return -1;
	return 0;
}

int dsa_os_thread_wait(struct dsa_os_thread *thrd)
{
	int ret;

	ret = pthread_join(thrd->thrd, NULL);
	if (ret != 0)
		return -1;
	return 0;
}

int dsa_os_thread_trywait(struct dsa_os_thread *thrd)
{
	int ret;

	ret = pthread_tryjoin_np(thrd->thrd, NULL);
	if (ret != 0)
		return -1;
	return 0;
}

void dsa_os_thread_yield(void)
{
	sched_yield();
}

struct dsa_os_mutex *dsa_os_mutex_create(void)
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

void dsa_os_mutex_destroy(struct dsa_os_mutex *mtx)
{
	pthread_mutex_destroy(&mtx->mtx);
	free(mtx);
}

int dsa_os_mutex_lock(struct dsa_os_mutex *mtx)
{
	int ret;

	ret = pthread_mutex_lock(&mtx->mtx);
	if (ret != 0)
		return -1;
	return 0;
}

int dsa_os_mutex_trylock(struct dsa_os_mutex *mtx)
{
	int ret;

	ret = pthread_mutex_trylock(&mtx->mtx);
	if (ret != 0)
		return -1;
	return 0;
}

int dsa_os_mutex_unlock(struct dsa_os_mutex *mtx)
{
	int ret;

	ret = pthread_mutex_unlock(&mtx->mtx);
	if (ret != 0)
		return -1;
	return 0;
}

struct dsa_os_semaphore *dsa_os_semaphore_create(unsigned int val)
{
	struct dsa_os_semaphore *sem;
	int ret;

	sem = malloc(sizeof(*sem));
	if (!sem)
		return NULL;

	ret = sem_init(&sem->sem, 0, val);
	if (ret < 0)
	{
		free(sem);
		return NULL;
	}

	return sem;
}

void dsa_os_semaphore_destroy(struct dsa_os_semaphore *sem)
{
	sem_destroy(&sem->sem);
	free(sem);
}

int dsa_os_semaphore_signal(struct dsa_os_semaphore *sem)
{
	int ret;

	ret = sem_post(&sem->sem);
	if (ret < 0)
		return -1;
	return 0;
}

int dsa_os_semaphore_wait(struct dsa_os_semaphore *sem)
{
	int ret;

	ret = sem_wait(&sem->sem);
	if (ret < 0)
		return -1;
	return 0;
}

int dsa_os_semaphore_trywait(struct dsa_os_semaphore *sem)
{
	int ret;

	ret = sem_trywait(&sem->sem);
	if (ret < 0)
		return -1;
	return 0;
}

int dsa_os_mkdir(const char *path)
{
	return mkdir(path, 0777);
}
