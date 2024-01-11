#include "Action_ShowUI.h"

#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanelSlot.h"


void UAction_ShowUI::DoAction(const void* _Instance)
{
	check(WidgetClass_);

	if (Widget_.IsNull())
	{
		Widget_ = CreateWidget(GetWorld(), WidgetClass_);
	}
	if(false == Widget_->IsInViewport())
	{
		Widget_->AddToViewport();
	}
	
	const FVector2D* Position = static_cast<const FVector2D*>(_Instance);
	if (Position)
	{
		Widget_->SetPositionInViewport(*Position);
	}
}
