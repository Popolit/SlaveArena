#include "Action_Move.h"

#include "InputAction.h"
#include "GameFramework/Character.h"


void UAction_Move::DoAction(const void* _Instance)
{
	const FInputActionInstance* InputInstance = static_cast<const FInputActionInstance*>(_Instance);
	check(InputInstance);

	ACharacter* Character = Cast<ACharacter>(GetOuter());

	if (ensureMsgf(nullptr != Character, TEXT("%s's Causer was not a Character class"), *this->GetName()))
	{
		const FVector2D MovingFactor = InputInstance->GetValue().Get<FVector2D>();
		FVector Direction = FVector(MovingFactor.X, MovingFactor.Y, 0.0f);

		const FRotator CharacterRotation = Character->GetControlRotation();
		Direction = CharacterRotation.RotateVector(Direction);

		Character->AddMovementInput(Direction.GetSafeNormal2D());
	}
}
