#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CustomSettings.generated.h"

UCLASS(Config = Game, meta = (DisplayName = "Custom Settings"))
class SLAVEARENA_API UCustomSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnyWhere, Config, Category = "Item")
		TSoftObjectPtr<class UDataTable> ItemInfo_;
};
