#pragma once

#include "CoreMinimal.h"
#include "Action_Extended.h"
#include "Action_InteractProp.generated.h"

UCLASS(Blueprintable)
class SLAVEARENA_API UAction_InteractProp : public UAction_Extended
{
	GENERATED_BODY()
public:
	virtual void DoAction(const void* _Instance) override;
};
