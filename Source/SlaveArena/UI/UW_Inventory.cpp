#include "UW_Inventory.h"

#include "UW_Inventory_Slot.h"
#include "Components/UniformGridPanel.h"
#include "SlaveArena/Component/InventoryComponent.h"

void UUW_Inventory::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	for (UWidget* Child : V_UGrid_Slots_->GetAllChildren())
	{
		Slots_.Add(Cast<UUW_Inventory_Slot>(Child));
	}

	const APawn* Owner = GetOwningPlayerPawn();
	if(ensureMsgf(Owner, TEXT("%s's Owner was nullptr"), this->GetClass()))
	{
		UInventoryComponent* Inventory = Cast<UInventoryComponent>(Owner->GetComponentByClass(UInventoryComponent::StaticClass()));
		if(Inventory)
		{
			Inventory->OnInventoryChanged_.BindUObject(this, &UUW_Inventory::SetInventoryData);
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
