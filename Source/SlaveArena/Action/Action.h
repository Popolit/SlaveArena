#pragma once

#include "CoreMinimal.h"
#include "IAction.h"
#include "Action.generated.h"

UCLASS(HideDropdown)
class SLAVEARENA_API UAction : public UObject, public IIAction
{
	GENERATED_BODY()

	friend class UActionData;
public:
	virtual ~UAction() override;

	virtual void DoAction(const FInputActionInstance& _InputInstance) override;

private:
	void BindAction(UEnhancedInputComponent* _IC, class UInputAction* _InputAction);
};
