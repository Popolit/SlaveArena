#include "ButtonHasAction.h"

#include "SlaveArena/Action/Action.h"

void UButtonHasAction::Initialize()
{
	if (ActionClass_)
	{
		Action_ = NewObject<UAction>(this, ActionClass_);
	}
	OnClicked.AddDynamic(this, &UButtonHasAction::DoAction);
}

void UButtonHasAction::DoAction()
{
	if(Action_.IsNull())
	{
		return;
	}

	Action_->DoAction();
}
