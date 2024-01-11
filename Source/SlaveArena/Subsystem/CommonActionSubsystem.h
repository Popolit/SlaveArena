#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "CommonActionSubsystem.generated.h"

class UAction;
/**
 * ���������� ���(�ν��Ͻ����� ���� ����)�ϴ� �׼��� �����ϱ� ����  ���� �ý���
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


