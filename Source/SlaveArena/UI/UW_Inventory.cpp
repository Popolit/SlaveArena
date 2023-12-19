#include "UW_Inventory.h"

#include "Components/UniformGridPanel.h"

void UUW_Inventory::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	for (UWidget* Child : V_UGrid_Slots_->GetAllChildren())
	{
		Slots_.Add(Child);
	}
}


