#include "Slave.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SlaveArena/Component/InteractComponent.h"
#include "SlaveArena/Action/InputActionData.h"

ASlave::ASlave()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateCameraAndSpringArm();
	InteractComponent_ = CreateDefaultSubobject<UInteractComponent>("InteractComponent");
	InteractComponent_->SetupAttachment(GetMesh());
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void ASlave::BeginPlay()
{
	Super::BeginPlay();
}

void ASlave::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);

}

void ASlave::SetupPlayerInputComponent(UInputComponent* _PlayerInputComponent)
{
	if(nullptr == InputActionData_)
	{
		ensureMsgf(false, TEXT("%s's InputActionData was nullptr"), *this->GetName());
		return;
	}

	APlayerController* PC = Cast<APlayerController>(Controller);
	if(PC)
	{
		InputActionData_->AddMappingContext(PC->GetLocalPlayer());
		InputActionData_->BindAll(this);
	}
}

void ASlave::Landed(const FHitResult& _Hit)
{
	Super::Landed(_Hit);
}

void ASlave::CreateCameraAndSpringArm() 
{
	SpringArmComponent_ = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent_->SetupAttachment(GetMesh());
	SpringArmComponent_->SetRelativeLocation(FVector(0.0, 0.0, 150.0));
	SpringArmComponent_->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));
	SpringArmComponent_->TargetArmLength = 400.0;
	SpringArmComponent_->bUsePawnControlRotation = true;

	CameraComponent_ = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent_->SetupAttachment(SpringArmComponent_.Get());
	CameraComponent_->SetRelativeLocation(FVector(-30.0, 0.0, 0.0));
}
