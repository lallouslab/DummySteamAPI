#include "list.h"
#include "os/os.h"
#include "steam.h"

#include "jobserver.h"

#define THREAD_POOL_SIZE 4

struct dsa_jobserver_job
{
	dsa_jobserver_callback_t callback;
	char arg[];
};

struct dsa_jobserver_pool_thread_arg
{
	struct dsa_jobserver_ctx *ctx;
	struct dsa_os_thread *thrd;
};

struct dsa_jobserver_ctx
{
	struct list jobs;
	struct dsa_os_semaphore *job_sem;
	struct dsa_jobserver_pool_thread_arg pool[THREAD_POOL_SIZE];
};

static struct dsa_jobserver_ctx jobserver_ctx;


static void dsa_jobserver_exit_callback(void *arg)
{
	(void)arg;
}

static void dsa_jobserver_pool_thread_ep(void *arg)
{
	struct dsa_jobserver_pool_thread_arg *targ = (struct dsa_jobserver_pool_thread_arg *)arg;
	struct dsa_jobserver_ctx *ctx = targ->ctx;
	steam_bool_t exit_thrd = STEAM_FALSE;

	while (!exit_thrd)
	{
		struct list_elem *elem;
		struct dsa_jobserver_job *job;

		dsa_os_semaphore_wait(ctx->job_sem);

		list_lock(&ctx->jobs);

		elem = list_head(&ctx->jobs);
		list_extract(&ctx->jobs, elem);
		job = (struct dsa_jobserver_job *)list_get_data(elem);

		list_unlock(&ctx->jobs);

		if (job->callback == dsa_jobserver_exit_callback)
			exit_thrd = STEAM_TRUE;

		job->callback(job->arg);

		free(elem);
	}
}

int dsa_jobserver_init(void)
{
	list_init(&jobserver_ctx.jobs);
	jobserver_ctx.job_sem = dsa_os_semaphore_create(0);

	for (size_t i = 0; i < THREAD_POOL_SIZE; i++)
	{
		struct dsa_jobserver_pool_thread_arg *targ = &jobserver_ctx.pool[i];

		targ->ctx = &jobserver_ctx;
		targ->thrd = dsa_os_thread_create(dsa_jobserver_pool_thread_ep, targ);
	}
	return 0;
}

int dsa_jobserver_deinit(void)
{
	for (size_t i = 0; i < THREAD_POOL_SIZE; i++)
		dsa_jobserver_schedule(dsa_jobserver_exit_callback, NULL, 0);

	for (size_t i = 0; i < THREAD_POOL_SIZE; i++)
	{
		struct dsa_jobserver_pool_thread_arg *targ = &jobserver_ctx.pool[i];

		dsa_os_thread_wait(targ->thrd);
		dsa_os_thread_destroy(targ->thrd);
	}

	dsa_os_semaphore_destroy(jobserver_ctx.job_sem);
	list_deinit(&jobserver_ctx.jobs);
	return 0;
}

int dsa_jobserver_schedule(dsa_jobserver_callback_t callback, void *arg, size_t arg_size)
{
	struct dsa_jobserver_job *job;
	size_t job_size = sizeof(*job) + arg_size;
	char data[job_size];

	job = (struct dsa_jobserver_job *)data;
	job->callback = callback;

	if (arg && arg_size)
		memcpy(job->arg, arg, arg_size);

	list_lock(&jobserver_ctx.jobs);
	list_push(&jobserver_ctx.jobs, job, job_size);
	list_unlock(&jobserver_ctx.jobs);

	dsa_os_semaphore_signal(jobserver_ctx.job_sem);
	return 0;
}

