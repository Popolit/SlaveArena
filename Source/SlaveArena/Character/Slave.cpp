#include "Slave.h"
#include "EnhancedInputComponent.h"
#include "SlaveArena/Action/ActionData.h"

ASlave::ASlave(const FObjectInitializer& _ObjectInitializer) : Super(_ObjectInitializer.SetDefaultSubobjectClass<USkeletalMeshComponent>(ACharacter::MeshComponentName))
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
}
