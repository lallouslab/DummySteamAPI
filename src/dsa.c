#include "config.h"
#include "callbacks.h"
#include "jobserver.h"

int dsa_init(void)
{
	int result;

	/* Here, none of the functions of os can be used,
	   except: dsa_os_thread*(), dsa_os_mutex*(), dsa_os_semaphore*(), dsa_os_mkdir() */

	result = dsa_config_init();
	if (result < 0)
		return result;

	result = dsa_jobserver_init();
	if (result < 0)
		return result;

	result = callbacks_init();
	if (result < 0)
		return result;

	return 0;
}

int dsa_deinit(void)
{
	return 0;
}
