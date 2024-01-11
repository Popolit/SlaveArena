#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "ButtonHasAction.generated.h"

class UAction;

/**
 * 
 */
UCLASS()
class SLAVEARENA_API UButtonHasAction : public UButton
{
	GENERATED_BODY()

public:
	void Initialize();

private:
	UFUNCTION()
		void DoAction();

private:
	UPROPERTY(EditInstanceOnly)
		TSubclassOf<UAction> ActionClass_;
	TObjectPtr<UAction> Action_;
};
