#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "Slave.generated.h"

UCLASS()
class SLAVEARENA_API ASlave : public ACharacter
{
	GENERATED_BODY()

public:
	ASlave(const FObjectInitializer& _ObjectInitializer);

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
		TObjectPtr<class UActionData> ActionData_;
};
