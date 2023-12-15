#pragma once

#include "CoreMinimal.h"
#include "Action_Extended.h"
#include "Action_Jump.generated.h"

UCLASS(Blueprintable, HideDropdown)
class SLAVEARENA_API UAction_Jump : public UAction_Extended
{
	GENERATED_BODY()

public:
	virtual void DoAction(const void* _Instance) override;
};
