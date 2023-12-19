#include "UW_Inventory_Slot.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"

void UUW_Inventory_Slot::NativeOnInitialized()
{
	V_Img_Icon_->SetVisibility(ESlateVisibility::Hidden);
	V_Img_Property_->SetVisibility(ESlateVisibility::Hidden);
	V_Txt_Count_->SetVisibility(ESlateVisibility::Hidden);
}
