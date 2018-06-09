#ifndef ISTEAMINVENTORY002_H
#define ISTEAMINVENTORY002_H 1

#include "steam.h"

#include "ISteamInventory.h"

#define STEAMINVENTORY_INTERFACE_VERSION_002 "STEAMINVENTORY_INTERFACE_V002"

struct ISteamInventory002Vtbl
{
	void *GetResultStatus;
	void *GetResultItems;
	void *GetResultItemProperty;
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
	void *StartPurchase;
	void *RequestPrices;
	void *GetNumItemsWithPrices;
	void *GetItemsWithPrices;
	void *GetItemPrice;
	void *StartUpdateProperties;
	void *RemoveProperty;
	void *SetPropertyStr;
	void *SetPropertyBool;
	void *SetPropertyI64;
	void *SetPropertyFloat;
	void *SubmitUpdateProperties;
};

struct ISteamInventory *SteamInventory002(void);

#endif /* ISTEAMINVENTORY002_H */
