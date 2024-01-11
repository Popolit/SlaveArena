#pragma once

#include "CoreMinimal.h"
#include "InputActionData.generated.h"



UCLASS(BlueprintType)
class SLAVEARENA_API UInputActionData : public UDataAsset
{
	GENERATED_BODY()
public:
	void AddMappingContext(const ULocalPlayer* _LocalPlayer) const;
	void BindAll(AActor* _Actor);
	void BindAll(UInputComponent* _InputComponent);
private:
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<class UInputMappingContext> InputMappingContext_;
	UPROPERTY(EditDefaultsOnly)
		TMap<TObjectPtr<class UInputAction>, TSubclassOf<class UAction>> InputActions_;
};
