#include "macros.h"

#include "ISteamMatchmaking009.h"
#include "ISteamMatchmaking_priv.h"

static const struct ISteamMatchmaking009Vtbl ISteamMatchmaking009_vtbl = {
	ISteamMatchmaking_GetFavoriteGameCount,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	ISteamMatchmaking_RequestLobbyList003,
	ISteamMatchmaking_AddRequestLobbyListStringFilter,
	ISteamMatchmaking_AddRequestLobbyListNumericalFilter,
	ISteamMatchmaking_AddRequestLobbyListNearValueFilter,
	ISteamMatchmaking_AddRequestLobbyListFilterSlotsAvailable,
	ISteamMatchmaking_AddRequestLobbyListDistanceFilter,
	ISteamMatchmaking_AddRequestLobbyListResultCountFilter,
	ISteamMatchmaking_AddRequestLobbyListCompatibleMembersFilter,
	INVAL_PTR,
	ISteamMatchmaking_CreateLobby007,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR,
	INVAL_PTR
};

struct ISteamMatchmaking *SteamMatchmaking009(void)
{
	static struct ISteamMatchmakingImpl impl;

	impl.base.vtbl.v009 = &ISteamMatchmaking009_vtbl;

	return &impl.base;
}
