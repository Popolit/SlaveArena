#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_ShowUI.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SLAVEARENA_API UAction_ShowUI : public UAction
{
	GENERATED_BODY()
public:
	virtual void DoAction(const void* _Instance) override;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UUserWidget> WidgetClass_;
	TObjectPtr<UUserWidget> Widget_;
};
