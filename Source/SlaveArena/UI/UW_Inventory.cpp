#include "UW_Inventory.h"

#include "UW_Inventory_Slot.h"
#include "Components/UniformGridPanel.h"
#include "SlaveArena/Action/Action.h"
#include "SlaveArena/Component/InventoryComponent.h"

/*const TWeakObjectPtr<UAction>& UUW_Inventory::AddActionForUI(const TSubclassOf<UAction>& _ActionClass)
{
	if(_ActionClass)
	{
		UAction* Action = NewObject<UAction>(this, _ActionClass);
		ActionsForUI_.Add(Action);
		return nullptr;
	}
	return nullptr;
}*/

void UUW_Inventory::AddInventoryAction(const UAction* _Action)
{
	InventoryActions_.Add(_Action);
}

int32 UUW_Inventory::GetSelectedItemIndex()
{
	check(false == SelectedItem_.IsExplicitlyNull());
	const UUW_Inventory_Slot* InventorySlot = Cast<UUW_Inventory_Slot>(SelectedItem_.Get());
	check(InventorySlot);
	const int32 Ret = V_UGrid_Slots_->GetChildIndex(InventorySlot);
	return Ret;
}

void UUW_Inventory::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	for (UWidget* Child : V_UGrid_Slots_->GetAllChildren())
	{
		UUW_Inventory_Slot* InventorySlot = Cast<UUW_Inventory_Slot>(Child);
		Slots_.Add(InventorySlot);
		InventorySlot->OnInventorySlotSelected_.BindUObject(this, &UUW_Inventory::OnInventorySlotSelected);
	}

	const APawn* Owner = GetOwningPlayerPawn();
	if(ensureMsgf(Owner, TEXT("%s's Owner was nullptr"), this->GetClass()))
	{
		UInventoryComponent* Inventory = Cast<UInventoryComponent>(Owner->GetComponentByClass(UInventoryComponent::StaticClass()));
		if(Inventory)
		{
			Inventory->OnInventoryChanged_.BindUObject(this, &UUW_Inventory::SetInventoryData);
			Inventory->GetIndexOfSelectedItemDelegate_.BindUObject(this, &UUW_Inventory::GetSelectedItemIndex);
			SetInventoryData(Inventory->GetInventory());
		}
	}
}

void UUW_Inventory::SetInventoryData(const TArray<FItemData>& _Items)
{
	for (uint8 u = 0; u < _Items.Num(); u++)
	{
		if(_Items[u].Count_ == 0)
		{
			Slots_[u]->SetSlotEmpty();
		}
		else
		{
			Slots_[u]->SetItem(_Items[u].ID_);
			Slots_[u]->SetItemCount(_Items[u].Count_);
		}
	}
}

void UUW_Inventory::OnInventorySlotSelected(const UWidget* _Slot)
{
	SelectedItem_ = _Slot;
}
