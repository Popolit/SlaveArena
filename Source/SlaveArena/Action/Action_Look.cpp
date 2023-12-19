#include "Action_Look.h"

#include "InputAction.h"
#include "GameFramework/Character.h"

void UAction_Look::DoAction(const void* _Instance)
{
	const FInputActionInstance* InputInstance = static_cast<const FInputActionInstance*>(_Instance);
	check(InputInstance);

	ACharacter* Character = Cast<ACharacter>(GetOuter());
	
	if (ensureMsgf(nullptr != Character, TEXT("%s's Causer was not a Character class"), *this->GetName()))
	{
		const APlayerController* PC = Cast<APlayerController>(Character->Controller);
		if(PC && PC->bShowMouseCursor == false)
		{
			const FVector2D LookingFactor = InputInstance->GetValue().Get<FVector2D>();
			Character->AddControllerYawInput(LookingFactor.X);
			Character->AddControllerPitchInput(LookingFactor.Y);
		}
	}
}
