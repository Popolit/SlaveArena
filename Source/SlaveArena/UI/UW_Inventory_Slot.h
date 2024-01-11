#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_Inventory_Slot.generated.h"

DECLARE_DELEGATE_OneParam(FOnInventorySlotSelected, const UWidget*)
class UAction;

UCLASS()
class SLAVEARENA_API UUW_Inventory_Slot : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeOnInitialized() override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& _InGeometry, const FPointerEvent& _InMouseEvent) override;
	virtual void NativeOnDragDetected(const FGeometry& _InGeometry, const FPointerEvent& _InMouseEvent, UDragDropOperation*& _OutOperation) override;

public:
	void SetItem(const uint8 _ItemID) const;
	void SetItemCount(const uint8 _Count) const;
	void SetSlotEmpty() const;

public:
	FOnInventorySlotSelected OnInventorySlotSelected_;

private:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<class UImage> V_Img_Icon_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UImage> V_Img_Property_;
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<class UTextBlock> V_Txt_Count_;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UAction> RightClickActionClass_;

	TWeakObjectPtr<UAction> RightClickAction_;
};
