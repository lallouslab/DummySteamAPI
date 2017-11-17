#ifndef STEAM_H
#define STEAM_H

#include <stdint.h>

enum steam_bool
{
	STEAM_FALSE = 0u,
	STEAM_TRUE  = 1u
};

typedef uint64_t steam_delayed_return_t;
typedef uint32_t steam_app_id_t;
typedef enum steam_bool steam_bool_t;

#endif
