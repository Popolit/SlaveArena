#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_Inventory_Slot.generated.h"

UCLASS()
class SLAVEARENA_API UUW_Inventory_Slot : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;

public:
	void SetItem(const uint8 _ItemID) const;
	void SetItemCount(const uint8 _Count) const;
	void SetSlotEmpty() const;

private:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<class UImage> V_Img_Icon_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UImage> V_Img_Property_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<class UTextBlock> V_Txt_Count_;
};
