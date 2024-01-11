#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_RequestEquipItem.generated.h"

/**
 * This Action Request Equip Weapon Item When Item Menu -> Equip Button Clicked 
 */
UCLASS()
class SLAVEARENA_API UAction_RequestEquipItem : public UAction
{
	GENERATED_BODY()

	virtual void DoAction(const void* _Instance) override;

};
