#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ItemSubsystem.generated.h"

UCLASS()
class SLAVEARENA_API UItemSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& _Collection) override;
	const struct FItemInfo* GetItemInfo(uint8 _ItemID) const;

private:
	TObjectPtr<class UDataTable> ItemInfo_;
};
