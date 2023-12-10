#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_Move.generated.h"

UCLASS(Blueprintable)
class SLAVEARENA_API UAction_Move : public UAction
{
	GENERATED_BODY()
public:
	virtual void DoAction(const FInputActionInstance& _InputInstance) override;
};
