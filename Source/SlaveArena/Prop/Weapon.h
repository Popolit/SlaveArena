#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class SLAVEARENA_API AWeapon : public AActor
{
	GENERATED_BODY()
public:
	AWeapon();
	void Initialize(const struct FItemInfo* _ItemInfo);

private:
	TObjectPtr<USceneComponent> Root_;
	TObjectPtr<UMeshComponent> Mesh_;
};
