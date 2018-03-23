#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h> /* mkdir() */
#include <sys/types.h>
#include <unistd.h>

#include "debug.h"
#include "utils.h"
#include "os/os.h"

static struct
{
	char *home_dir;
	char *steam_dir;
} os_ctx;

EXPORT int dsa_os_init(void)
{
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

	return 0;
}

EXPORT int dsa_os_deinit(void)
{
	dsa_utils_free_ptr(&os_ctx.home_dir);

	return 0;
}

EXPORT const char *dsa_os_get_home_dir(void)
{
	return os_ctx.home_dir;
}

EXPORT int dsa_os_mkdir(const char *path)
{
	return mkdir(path, 0777);
}
