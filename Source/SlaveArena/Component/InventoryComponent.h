#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

struct FItemData
{
	uint8 ID_, Count_;
};

DECLARE_DELEGATE_OneParam(FOnInventoryChanged, const TArray<FItemData>&)
DECLARE_DELEGATE_RetVal(int32, FGetIndexOfSelectedItemDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLAVEARENA_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UInventoryComponent();
	uint8 TryPushItem(uint8 _ItemID, uint8 _Count, uint8 _MaxStack);
	void TryEquipSelectedItem() const;
	const TArray<FItemData>& GetInventory();

private:
	uint8 GetItemSlotIndex(uint8 _ItemID);

public:
	FOnInventoryChanged OnInventoryChanged_;
	FGetIndexOfSelectedItemDelegate GetIndexOfSelectedItemDelegate_;
private:
	UPROPERTY(EditDefaultsOnly)
		uint8 MaxSlot_;
	UPROPERTY(EditDefaultsOnly)
		float MaxWeight_;
	TArray<FItemData> Items_;
	int32 SelectedSlotIndex_ = INDEX_NONE;
};