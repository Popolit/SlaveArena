#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"

enum class EItemType : uint8;
class AWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLAVEARENA_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void TryEquipItem(uint8 _ItemID);

private:
	void CreateAndEquipWeaponFromItem(const struct FItemInfo* _ItemInfo);
	bool IsWeaponType(EItemType _ItemType) const;

private:
	TArray<TObjectPtr<AWeapon>> EquippingWeapons_;

	TWeakObjectPtr<AWeapon> LeftWeapon_;
	TWeakObjectPtr<AWeapon> RightWeapon_;
};
