#include "Action.h"

#include "EnhancedInputComponent.h"

void UAction::DoAction(const void* _Instance) {}

void UAction::DoActionByInput(const FInputActionInstance& _Instance)
{
	DoAction(&_Instance);
}
