#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemInfo.generated.h"

UENUM()
enum class EItemType : uint8
{
	OneHandedWeapon, TwoHandedWeapon, Max
};

USTRUCT()
struct FItemInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
		EItemType Type_;
	UPROPERTY(EditDefaultsOnly)
		TSoftObjectPtr<UTexture2D> Icon_;
	UPROPERTY(EditDefaultsOnly)
		FSoftObjectPath Tooltip_;
	UPROPERTY(EditDefaultsOnly)
		TSoftClassPtr<UStreamableRenderAsset> Mesh_;
	UPROPERTY(EditDefaultsOnly)
		uint8 MaxStack_ = 1;
	UPROPERTY(EditDefaultsOnly)
		float Weight_;
};