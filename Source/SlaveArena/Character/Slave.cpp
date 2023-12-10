#include "Slave.h"
#include "EnhancedInputComponent.h"
#include "SlaveArena/Action/ActionData.h"

ASlave::ASlave()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASlave::BeginPlay()
{
	Super::BeginPlay();
}

void ASlave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlave::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if(nullptr == ActionData_)
	{
		ensureMsgf(false, TEXT("%s's ActionData was nullptr"), *this->GetName());
		return;
	}

	APlayerController* PC = Cast<APlayerController>(Controller);
	if(PC)
	{
		ActionData_->AddMappingContext(PC->GetLocalPlayer());
		ActionData_->BindAll(this);
	}

	/*APlayerController* PC = Cast<APlayerController>(GetController());
	check(PC);

#if WITH_EDITOR
	if (Cast<UEnhancedPlayerInput>(PC->PlayerInput) == nullptr)
	{
		PC->ClientMessage(TEXT("Player controller is not using the Enhanced Input system."));
		return;
	}
#endif

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
	{
		UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
		if (InputMappingContext.IsNull() == false)
		{
			Subsystem->AddMappingContext(InputMappingContext.Get(), 1);
			TSet<const UInputAction*> InputActions;
			for (const auto& Elem : InputMappingContext->GetMappings())
			{
				InputActions.Add(Elem.Action);
			}
			for(const auto& Elem : InputActions)
			{
				Input->BindAction(Elem, ETriggerEvent::Triggered, this, &ASlave::Move);
			}
			Subsystem->RequestRebuildControlMappings(FModifyContextOptions(), EInputMappingRebuildType::RebuildWithFlush);
		}
	}*/
}


void ASlave::Move(const FInputActionInstance& _Instance)
{
	const FVector2D Amount = _Instance.GetValue().Get<FVector2D>();
	AddMovementInput(FVector(Amount.X, Amount.Y, 0.0f));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("%f %f"), Amount.X, Amount.Y));
}

void ASlave::Look(const FInputActionInstance& _Instance)
{
	const FVector2D Amount = _Instance.GetValue().Get<FVector2D>();
	AddControllerPitchInput(Amount.X);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT(""));
}

