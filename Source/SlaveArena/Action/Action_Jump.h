#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_Jump.generated.h"

UCLASS(Blueprintable)
class SLAVEARENA_API UAction_Jump : public UAction
{
	GENERATED_BODY()

public:
	virtual void DoAction(const FInputActionInstance& _InputInstance) override;
};
