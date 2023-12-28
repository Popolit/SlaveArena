#include "ItemSubsystem.h"

#include "EngineUtils.h"
#include "Engine/DataTable.h"
#include "SlaveArena/Prop/ItemInfo.h"
#include "SlaveArena/CustomSettings.h"

void UItemSubsystem::Initialize(FSubsystemCollectionBase& _Collection)
{
	Super::Initialize(_Collection);

	ItemInfo_ = GetDefault<UCustomSettings>()->ItemInfo_.LoadSynchronous();
	ensureMsgf(false == ItemInfo_.IsNull(), TEXT("ItemInfo In CustomSetting was invalid"));
}

const FItemInfo* UItemSubsystem::GetItemInfo(uint8 _ItemID) const
{
	check(false == ItemInfo_.IsNull());

	const UDataTable* DataTable = ItemInfo_.Get();

	check(DataTable);
	TArray<FItemInfo*> ItemInfos;
	DataTable->GetAllRows("", ItemInfos);

	if(ItemInfos.IsValidIndex(_ItemID - 1))
	{
		return ItemInfos[_ItemID - 1];
	}
	return nullptr;
}
