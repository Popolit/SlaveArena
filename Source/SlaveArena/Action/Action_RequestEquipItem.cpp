#include "Action_RequestEquipItem.h"

#include "Blueprint/UserWidget.h"
#include "Components/Widget.h"
#include "GameFramework/Character.h"
#include "SlaveArena/Component/InventoryComponent.h"

void UAction_RequestEquipItem::DoAction(const void* _Instance)
{
	UWidget* Widget = Cast<UWidget>(GetOuter());
	check(Widget)

	if (nullptr == Widget->GetOwningPlayer())
	{
		return;
	}

	ACharacter* Character = Widget->GetOwningPlayer()->GetCharacter();
	if(nullptr == Character)
	{
		return;
	}

	UInventoryComponent* Inventory = Cast<UInventoryComponent>(Character->GetComponentByClass(UInventoryComponent::StaticClass()));
	Inventory->TryEquipSelectedItem();
}
