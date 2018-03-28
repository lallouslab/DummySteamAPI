#include "config.h"
#include "callbacks.h"

int dsa_init(void)
{
	int result;

	result = dsa_config_init();
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
