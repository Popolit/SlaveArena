#include "InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	MaxSlot_ = 9;
	MaxWeight_ = 30.0f;

	Items_.Reserve(MaxSlot_);
}

void UInventoryComponent::PushItem(uint8 _ItemID, uint8 _Count)
{
	//TODO : ���Կ� �ִ� ���� ����ؼ� �ֱ�
	if(Items_.Contains(_ItemID))
	{
		Items_[_ItemID] += _Count;
	}
	
	
}

