#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

struct FItemInfo;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLAVEARENA_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UInventoryComponent();
	void PushItem(uint8 _ItemID, uint8 _Count);

private:
	UPROPERTY(EditDefaultsOnly)
		uint8 MaxSlot_;
	UPROPERTY(EditDefaultsOnly)
		float MaxWeight_;
	TMap<uint8, uint8> Items_;
};