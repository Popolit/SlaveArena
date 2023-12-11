#include "Action.h"

#include "EnhancedInputComponent.h"

UAction::~UAction()
{
	//Remove (Unbind) Action
}

void UAction::DoAction(const FInputActionInstance& _InputInstance) {}

void UAction::BindAction(UEnhancedInputComponent* _IC, const UInputAction* _InputAction)
{
	_IC->BindAction(_InputAction, ETriggerEvent::Triggered, this, &UAction::DoAction);
}