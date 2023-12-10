#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_Look.generated.h"

UCLASS()
class SLAVEARENA_API UAction_Look : public UAction
{
	GENERATED_BODY()

public:
	virtual void DoAction(const FInputActionInstance& _InputInstance) override;
};
