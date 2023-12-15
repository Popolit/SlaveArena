#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Slave.generated.h"

UCLASS()
class SLAVEARENA_API ASlave : public ACharacter
{
	GENERATED_BODY()

public:
	ASlave();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float _DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* _PlayerInputComponent) override;
	virtual void Landed(const FHitResult& _Hit) override;

private:
	void CreateCameraAndSpringArm();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
		TObjectPtr<class UInputActionData> InputActionData_;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<class USpringArmComponent> SpringArmComponent_;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<class UCameraComponent> CameraComponent_;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<class UInteractComponent> InteractComponent_;
};
