#include "UW_Inventory_Slot.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "SlaveArena/Prop/ItemInfo.h"
#include "SlaveArena/Subsystem/ItemSubsystem.h"

void UUW_Inventory_Slot::NativeOnInitialized()
{
	SetSlotEmpty();
}


void UUW_Inventory_Slot::SetItem(const uint8 _ItemID) const
{
	const UWorld* World = GetWorld();
	if(nullptr == World)
	{
		return;
	}
	const UItemSubsystem* ItemSubsystem = World->GetGameInstance()->GetSubsystem<UItemSubsystem>();
	const FItemInfo* ItemInfo = ItemSubsystem->GetItemInfo(_ItemID);

	if(nullptr == ItemInfo)
	{
		ensureMsgf(true, TEXT("Item Info of %d was nullptr"), _ItemID);
		return;
	}

	V_Img_Icon_->SetBrushFromSoftTexture(ItemInfo->Icon_);
	V_Img_Icon_->SetVisibility(ESlateVisibility::Visible);
}

void UUW_Inventory_Slot::SetItemCount(const uint8 _Count) const
{
	if(_Count == 0)
	{
		SetSlotEmpty();
		return;
	}

	V_Txt_Count_->SetText(FText::FromString(FString::FromInt(_Count)));
	V_Txt_Count_->SetVisibility(ESlateVisibility::Visible);
}

void UUW_Inventory_Slot::SetSlotEmpty() const
{
	V_Img_Icon_->SetVisibility(ESlateVisibility::Hidden);
	V_Img_Property_->SetVisibility(ESlateVisibility::Hidden);
	V_Txt_Count_->SetVisibility(ESlateVisibility::Hidden);
}
