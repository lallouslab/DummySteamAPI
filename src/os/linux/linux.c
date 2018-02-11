#include <sys/stat.h> /* mkdir() */

#include "utils.h"
#include "os/os.h"

EXPORT int dsa_os_init()
{
	return 0;
}

EXPORT int dsa_os_mkdir(const char *path)
{
	return mkdir(path, 0777);
}
