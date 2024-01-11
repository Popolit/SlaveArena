#include "Slave.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "SlaveArena/Component/InteractComponent.h"
#include "SlaveArena/Component/InventoryComponent.h"
#include "SlaveArena/Action/InputActionData.h"
#include "SlaveArena/Component/WeaponComponent.h"

ASlave::ASlave()
{
	PrimaryActorTick.bCanEverTick = true;

	CreateAllComponents();

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	SpringArmComponent_->SetRelativeLocation(FVector(0.0, 0.0, 150.0));
	SpringArmComponent_->SetRelativeRotation(FRotator(0.0, 90.0, 0.0));
	SpringArmComponent_->TargetArmLength = 400.0;
	SpringArmComponent_->bUsePawnControlRotation = true;

	CameraComponent_->SetRelativeLocation(FVector(-30.0, 0.0, 0.0));
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
	check(InputActionData_Default_);
	check(InputActionData_UI_);

	APlayerController* PC = Cast<APlayerController>(Controller);
	if(PC)
	{
		InputActionData_Default_->AddMappingContext(PC->GetLocalPlayer());
		InputActionData_Default_->BindAll(this);

		InputActionData_UI_->AddMappingContext(PC->GetLocalPlayer());
		InputActionData_UI_->BindAll(this);
	}
}

void ASlave::Landed(const FHitResult& _Hit)
{
	Super::Landed(_Hit);
}

void ASlave::CreateAllComponents()
{
	SpringArmComponent_ = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent_->SetupAttachment(GetMesh());

	CameraComponent_ = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent_->SetupAttachment(SpringArmComponent_.Get());

	InteractComponent_ = CreateDefaultSubobject<UInteractComponent>("InteractComponent");
	InteractComponent_->SetupAttachment(GetMesh());

	InventoryComponent_ = CreateDefaultSubobject<UInventoryComponent>("InventoryComponent");

	WeaponComponent_ = CreateDefaultSubobject<UWeaponComponent>("WeaponComponent");
}
