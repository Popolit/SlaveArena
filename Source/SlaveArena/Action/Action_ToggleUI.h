#pragma once

#include "CoreMinimal.h"
#include "Action.h"
#include "Action_ToggleUI.generated.h"

UCLASS(Blueprintable, HideDropdown)
class SLAVEARENA_API UAction_ToggleUI : public UAction
{
	GENERATED_BODY()
public:
	virtual void DoAction(const void* _Instance) override;

private:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UUserWidget> WidgetClass_;
	UPROPERTY(EditDefaultsOnly)
		bool bNeedCursor;
	TObjectPtr<UUserWidget> Widget_;
};
