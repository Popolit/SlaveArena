#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_ItemMenu.generated.h"

class UButtonHasAction;

/**
 * 
 */
UCLASS()
class SLAVEARENA_API UUW_ItemMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;
	virtual void NativeOnFocusLost(const FFocusEvent& _InFocusEvent) override;

private:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButtonHasAction> V_Button1_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButtonHasAction> V_Button2_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButtonHasAction> V_Button3_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UButtonHasAction> V_Button4_;
};
