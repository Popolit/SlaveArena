#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "InteractComponent.generated.h"

/*
 * Owner Can Interact To Prop (Interactable)
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SLAVEARENA_API UInteractComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UInteractComponent();
	const TScriptInterface<class IInteractable>* GetProp() const;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnBeginOverlap(UPrimitiveComponent* _OverlappedComponent, AActor* _OtherActor, UPrimitiveComponent* _OtherComp, int32 _OtherBodyIndex, bool _BFromSweep, const FHitResult& _SweepResult);

private:
	TArray<TScriptInterface<IInteractable>> InteractableProps_;
};
