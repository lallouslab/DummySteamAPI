#ifndef STEAMCLIENT_H
#define STEAMCLIENT_H 1

#include "steam.h"

extern void *CreateInterface(const char *version, enum steam_result *result);
extern void Steam_ReleaseThreadLocalMemory(steam_bool_t thread_exit);

#endif /* STEAMCLIENT_H */
