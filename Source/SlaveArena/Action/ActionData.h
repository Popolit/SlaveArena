#pragma once

#include "CoreMinimal.h"
#include "ActionData.generated.h"



UCLASS(BlueprintType)
class SLAVEARENA_API UActionData : public UDataAsset
{
	GENERATED_BODY()
public:
	void AddMappingContext(const ULocalPlayer* _LocalPlayer) const;
	void BindAll(AActor* _Actor);
	void BindAll(UUserWidget* _Widget);
private:
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<class UInputMappingContext> InputMappingContext_;
	UPROPERTY(EditDefaultsOnly)
		TMap<TObjectPtr<class UInputAction>, TSubclassOf<class UAction>> Actions_;
};
