#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interactable Prop
 */
class SLAVEARENA_API IInteractable
{
	GENERATED_BODY()

public:
	virtual void Interact() = 0;
};
