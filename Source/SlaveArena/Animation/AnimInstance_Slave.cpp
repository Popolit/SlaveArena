#include "AnimInstance_Slave.h"

#include "GameFramework/Character.h"

void UAnimInstance_Slave::NativeUpdateAnimation(float DeltaSeconds)
{
	const APawn* Pawn = TryGetPawnOwner();
	if(Pawn == nullptr)
	{
		return;
	}

	Speed = Pawn->GetVelocity().Size2D();
}
