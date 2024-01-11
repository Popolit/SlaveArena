#include "UW_ItemMenu.h"

#include "ButtonHasAction.h"

void UUW_ItemMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	V_Button1_->Initialize();
	V_Button2_->Initialize();
	V_Button3_->Initialize();
	V_Button4_->Initialize();
}

void UUW_ItemMenu::NativeOnFocusLost(const FFocusEvent& _InFocusEvent)
{
	Super::NativeOnFocusLost(_InFocusEvent);

	if(IsInViewport())
	{
		RemoveFromViewport();
	}
}

