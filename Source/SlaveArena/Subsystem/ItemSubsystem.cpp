#include "ItemSubsystem.h"

#include "Engine/DataTable.h"
#include "SlaveArena/Prop/ItemInfo.h"
#include "SlaveArena/CustomSettings.h"

void UItemSubsystem::Initialize(FSubsystemCollectionBase& _Collection)
{
	Super::Initialize(_Collection);

	ItemInfo_ = GetDefault<UCustomSettings>()->ItemInfo_.LoadSynchronous();
	ensureMsgf(false == ItemInfo_.IsNull(), TEXT("ItemInfo In CustomSetting was invalid"));
}

FItemInfo* UItemSubsystem::GetItemInfo(uint8 _ItemID) const
{
	check(false == ItemInfo_.IsNull());

	const UDataTable* DataTable = ItemInfo_.Get();

	check(DataTable);
	return DataTable->FindRow<FItemInfo>(FName(*FString::FromInt(_ItemID)), "", true);
}
