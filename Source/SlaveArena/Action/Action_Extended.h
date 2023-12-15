#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_Extended.generated.h"

/*
 * Action Needs Animation & Particle etc..
 * Sandbox Pattern
 */
UCLASS(Abstract, HideDropdown)
class SLAVEARENA_API UAction_Extended : public UAction
{
	GENERATED_BODY()
public:
	virtual void DoAction(const void* _Instance = nullptr) override;

protected:
	void PlayAnimation() const;
	void SpawnParticle(const FTransform& _Transform) const;
	void PlaySound() const;

private:
	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<UAnimMontage> AnimMontage_;
	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<class UFXSystemAsset> Particle_;
	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<class USoundCue> SoundCue_;
};
