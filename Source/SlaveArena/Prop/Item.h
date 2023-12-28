#pragma once

#include "CoreMinimal.h"
#include "Prop.h"
#include "Interactable.h"
#include "Item.generated.h"

UCLASS(NotBlueprintable)
class SLAVEARENA_API AItem : public AProp, public IInteractable
{
	GENERATED_BODY()
public:
	AItem();
	virtual void BeginPlay() override;
	virtual void Interact(AActor* _Causer) override;
	void SetItemID(uint8 _ItemID);
	void SetItemCount(uint8 _Count);
	void Spawn();

private:
	void SetItemData();

private:
	UPROPERTY(EditInstanceOnly)
		uint8 ItemID_;
	UPROPERTY(EditInstanceOnly)
		uint8 Count_;
	uint8 MaxStack_;
	TObjectPtr<USceneComponent> RootComponent_;
	TObjectPtr<UMeshComponent> MeshComponent_;
};
