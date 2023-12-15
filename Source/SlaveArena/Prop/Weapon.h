#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Prop.h"
#include "Weapon.generated.h"

UCLASS()
class SLAVEARENA_API AWeapon : public AProp, public IInteractable
{
	GENERATED_BODY()
public:
	AWeapon();
	virtual void Interact() override;
};
