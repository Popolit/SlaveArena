#include "Item.h"

#include "SlaveArena/Component/InventoryComponent.h"

AItem::AItem()
{
	Mesh_ = CreateDefaultSubobject<UMeshComponent>("Mesh");
}

void AItem::Interact(AActor* _Causer)
{
	check(_Causer);

	UInventoryComponent* Inventory = Cast<UInventoryComponent>(_Causer->GetComponentByClass(UInventoryComponent::StaticClass()));
	if(Inventory)
	{
		//Inventory->PushItem(ItemID_, Count_);
	}
}

