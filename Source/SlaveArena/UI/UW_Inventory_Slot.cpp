#include "UW_Inventory_Slot.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "SlaveArena/Action/Action.h"
#include "SlaveArena/Prop/ItemInfo.h"
#include "SlaveArena/Subsystem/CommonActionSubsystem.h"
#include "SlaveArena/Subsystem/ItemSubsystem.h"


void UUW_Inventory_Slot::NativeOnInitialized()
{
	SetSlotEmpty();

	if(ensureMsgf(RightClickActionClass_, TEXT("%s's RightClickActionClass was nullptr"), *GetName()))
	{
		if(RightClickAction_.IsExplicitlyNull())
		{
			UCommonActionSubsystem* Subsystem = GetOwningLocalPlayer()->GetSubsystem<UCommonActionSubsystem>();
			RightClickAction_ = Subsystem->GetAction(RightClickActionClass_);
		}
	}
}

FReply UUW_Inventory_Slot::NativeOnMouseButtonDown(const FGeometry& _InGeometry, const FPointerEvent& _InMouseEvent)
{
	//¿ìÅ¬¸¯
	if(_InMouseEvent.IsMouseButtonDown(EKeys::RightMouseButton))
	{
		if (false == RightClickAction_.IsExplicitlyNull())
		{
			const FVector2D Position = _InMouseEvent.GetScreenSpacePosition();
			OnInventorySlotSelected_.ExecuteIfBound(this);
			RightClickAction_->DoAction(&Position);
		}
	}
	return FReply::Handled();
}

void UUW_Inventory_Slot::NativeOnDragDetected(const FGeometry& _InGeometry, const FPointerEvent& _InMouseEvent,
	UDragDropOperation*& _OutOperation)
{
	Super::NativeOnDragDetected(_InGeometry, _InMouseEvent, _OutOperation);
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