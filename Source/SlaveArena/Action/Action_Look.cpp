#include "Action_Look.h"

#include "InputAction.h"
#include "GameFramework/Character.h"

void UAction_Look::DoAction(const FInputActionInstance& _InputInstance)
{
	ACharacter* Character = Cast<ACharacter>(GetOuter());
	if (ensureMsgf(nullptr != Character, TEXT("%s's Causer was not a Character class"), *this->GetName()))
	{
		const FVector2D LookingFactor = _InputInstance.GetValue().Get<FVector2D>();
		Character->AddControllerYawInput(LookingFactor.X);
		Character->AddControllerPitchInput(LookingFactor.Y);
	}
}
