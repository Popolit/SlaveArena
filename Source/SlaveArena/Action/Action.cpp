#include "Action.h"

#include "EnhancedInputComponent.h"

UAction::~UAction()
{
}

void UAction::DoAction(const FInputActionInstance& _InputInstance) {}

void UAction::BindAction(UEnhancedInputComponent* _IC, UInputAction* _InputAction)
{
	_IC->BindAction(_InputAction, ETriggerEvent::Triggered, this, &UAction::DoAction);
}