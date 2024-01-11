#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_Inventory.generated.h"

class UAction;

UCLASS()
class SLAVEARENA_API UUW_Inventory : public UUserWidget
{
	GENERATED_BODY()

public:
	void AddInventoryAction(const UAction* _Action);

protected:
	virtual void NativeOnInitialized() override;

private:
	void SetInventoryData(const TArray<struct FItemData>& _Items);
	void OnInventorySlotSelected(const UWidget* _Slot);
	int32 GetSelectedItemIndex();

private:
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<class UUniformGridPanel> V_UGrid_Slots_;
	TArray<TObjectPtr<const class UUW_Inventory_Slot>> Slots_;
	TWeakObjectPtr<const UWidget> SelectedItem_;

	//�׼��� ����
	//���Ե��� ��� ������ �׼� ��ü�� �����ؾ� �ϹǷ� �� ���� ��ü�� �κ��丮���� ������ ��
	//�̰� �ּ��ΰ�?
	TArray<TObjectPtr<const UAction>> InventoryActions_;
};
