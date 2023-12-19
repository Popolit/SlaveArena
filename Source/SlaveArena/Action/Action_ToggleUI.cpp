#include "Action_ToggleUI.h"

#include "Blueprint/UserWidget.h"

void UAction_ToggleUI::DoAction(const void* _Instance)
{
	check(WidgetClass_);

	if(Widget_.IsNull())
	{
		Widget_ = CreateWidget(GetWorld(), WidgetClass_);
	}

	if(Widget_->IsInViewport())
	{
		Widget_->RemoveFromViewport();

		if(bNeedCursor)
		{
			Widget_->GetOwningPlayer()->bShowMouseCursor--;
		}
	}
	else
	{
		Widget_->AddToViewport();

		if(bNeedCursor)
		{
			Widget_->GetOwningPlayer()->bShowMouseCursor++;
		}
	}
}
