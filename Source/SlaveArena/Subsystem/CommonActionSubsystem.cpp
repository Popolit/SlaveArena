#include "CommonActionSubsystem.h"

#include "SlaveArena/Action/Action.h"

TWeakObjectPtr<UAction> UCommonActionSubsystem::GetAction(const UClass* _ClassOfAction)
{
	return CommonActions_.FindOrAdd(_ClassOfAction, NewObject<UAction>(this, _ClassOfAction));
}
