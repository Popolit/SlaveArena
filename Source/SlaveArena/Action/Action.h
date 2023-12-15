#pragma once

#include "CoreMinimal.h"
#include "IAction.h"
#include "Action.generated.h"

UCLASS(HideDropdown)
class SLAVEARENA_API UAction : public UObject, public IIAction
{
	GENERATED_BODY()
	friend class UInputActionData;
public:
	virtual void DoAction(const void* _Instance = nullptr) override;

private:
	void DoActionByInput(const struct FInputActionInstance& _Instance);
};
