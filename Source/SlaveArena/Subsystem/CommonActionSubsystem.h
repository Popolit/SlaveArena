#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "CommonActionSubsystem.generated.h"

class UAction;
/**
 * 공통적으로 사용(인스턴스끼리 돌려 쓰는)하는 액션을 제공하기 위한  서브 시스템
 */
UCLASS()
class SLAVEARENA_API UCommonActionSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	TWeakObjectPtr<UAction> GetAction(const UClass* _ClassOfAction);
private:
	TMap<const UClass*, TObjectPtr<UAction>> CommonActions_;
};


