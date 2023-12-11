#include "Action_Jump.h"

#include "InputAction.h"
#include "GameFramework/Character.h"


void UAction_Jump::DoAction(const FInputActionInstance& _InputInstance)
{
	ACharacter* Character = Cast<ACharacter>(GetOuter());
	if (ensureMsgf(nullptr != Character, TEXT("%s's Causer was not a Character class"), *this->GetName()))
	{
		Character->Jump();
	}
}
