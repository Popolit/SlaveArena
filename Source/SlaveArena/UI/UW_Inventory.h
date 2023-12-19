#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_Inventory.generated.h"

UCLASS()
class SLAVEARENA_API UUW_Inventory : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<class UUniformGridPanel> V_UGrid_Slots_;
	TArray<TObjectPtr<UWidget>> Slots_;
};
