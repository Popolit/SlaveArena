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
	virtual void Interact(AActor* _Causer) override;

private:
	TObjectPtr<UMeshComponent> Mesh_;
	//const uint8 ItemID_;
	uint8 Count_;
};
