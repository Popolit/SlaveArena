#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IAction.generated.h"


UINTERFACE(MinimalAPI)
class UIAction : public UInterface
{
	GENERATED_BODY()
};

class SLAVEARENA_API IIAction
{
	GENERATED_BODY()

public:
	virtual void DoAction(const struct FInputActionInstance& _InputInstance) = 0;
};
