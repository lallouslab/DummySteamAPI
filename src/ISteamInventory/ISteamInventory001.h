#ifndef ISTEAMINVENTORY001_H
#define ISTEAMINVENTORY001_H 1

#include "steam.h"

#include "ISteamInventory.h"

#define STEAMINVENTORY_INTERFACE_VERSION_001 "STEAMINVENTORY_INTERFACE_V001"

struct ISteamInventory001Vtbl
{
	void *GetResultStatus;
	void *GetResultItems;
	void *GetResultTimestamp;
	void *CheckResultSteamID;
	void *DestroyResult;
	void *GetAllItems;
	void *GetItemsByID;
	void *SerializeResult;
	void *DeserializeResult;
	void *GenerateItems;
	void *GrantPromoItems;
	void *AddPromoItem;
	void *AddPromoItems;
	void *ConsumeItem;
	void *ExchangeItems;
	void *TransferItemQuantity;
	void *SendItemDropHeartbeat;
	void *TriggerItemDrop;
	void *TradeItems;
	void *LoadItemDefinitions;
	void *GetItemDefinitionIDs;
	void *GetItemDefinitionProperty;
	void *RequestEligiblePromoItemDefinitionsIDs;
	void *GetEligiblePromoItemDefinitionIDs;
};

struct ISteamInventory *SteamInventory001(void);

#endif /* ISTEAMINVENTORY001_H */
