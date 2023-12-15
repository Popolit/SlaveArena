#include "AnimInstance_Slave.h"

#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"

void UAnimInstance_Slave::NativeUpdateAnimation(float DeltaSeconds)
{
	const APawn* Pawn = TryGetPawnOwner();
	if(Pawn == nullptr)
	{
		return;
	}

	Speed_ = Pawn->GetVelocity().Size2D();
	bIsInAir_ = Pawn->GetMovementComponent()->IsFalling();
}
