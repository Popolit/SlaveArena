#include "InventoryComponent.h"

#include "WeaponComponent.h"

UInventoryComponent::UInventoryComponent()
{
	MaxSlot_ = 9;
	MaxWeight_ = 30.0f;

	Items_.Reserve(MaxSlot_);
}

//Return Value is Num of Leftover
uint8 UInventoryComponent::TryPushItem(uint8 _ItemID, uint8 _Count, uint8 _MaxStack)
{
	//TODO : 무게 고려해서 넣기
	uint8 SlotIndex = GetItemSlotIndex(_ItemID);

	if(Items_.IsValidIndex(SlotIndex))
	{
		Items_[SlotIndex].Count_ += _Count;
	}
	else if(Items_.Num() < MaxSlot_)
	{
		Items_.Push({ _ItemID, _Count });
		SlotIndex = Items_.Num() - 1;
	}
	else
	{
		return _Count;
	}

	//Calculate Leftover
	uint8 Leftover = 0;
	if(_MaxStack < Items_[SlotIndex].Count_)
	{
		Leftover = MaxSlot_ - Items_[SlotIndex].Count_;
		Items_[SlotIndex].Count_ = MaxSlot_;
	}

	OnInventoryChanged_.ExecuteIfBound(Items_);
	return Leftover;
}


void UInventoryComponent::TryEquipSelectedItem() const
{
	if(false == GetIndexOfSelectedItemDelegate_.IsBound())
	{
		return;
		
	}
	const uint32 Index = GetIndexOfSelectedItemDelegate_.Execute();
	if(false == Items_.IsValidIndex(Index))
	{
		return;
	}

	UWeaponComponent* WeaponComponent = Cast<UWeaponComponent>(GetOwner()->GetComponentByClass(UWeaponComponent::StaticClass()));
	if(ensureMsgf(WeaponComponent, TEXT("WeaponComponent was nullptr")))
	{
		WeaponComponent->TryEquipItem(Items_[Index].ID_);
	}
}


const TArray<FItemData>& UInventoryComponent::GetInventory()
{
	return Items_;
}

uint8 UInventoryComponent::GetItemSlotIndex(const uint8 _ItemID)
{
	for(uint8 u = 0; u < Items_.Num(); u++)
	{
		if(Items_[u].ID_ == _ItemID)
		{
			return u;
		}
	}
	return MaxSlot_;
}
