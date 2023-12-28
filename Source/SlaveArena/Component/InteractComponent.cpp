#include "InteractComponent.h"

#include "SlaveArena/Prop/Interactable.h"


UInteractComponent::UInteractComponent()
{
}

const TScriptInterface<IInteractable>* UInteractComponent::GetProp() const
{
	if(InteractableProps_.IsEmpty())
	{
		return nullptr;
	}

	//TODO : 가까운 순, 혹은 가장 최신 순으로 정렬하여 리턴
	return &InteractableProps_[0];
}

void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::OnBeginOverlap);

	//TODO : Collision Channel 추가
}


void UInteractComponent::OnBeginOverlap(UPrimitiveComponent* _OverlappedComponent, AActor* _OtherActor, UPrimitiveComponent* _OtherComp, int32 _OtherBodyIndex, bool _bFromSweep, const FHitResult& _SweepResult)
{
	//TODO: Interactive Class를 상속받은 액터에만 반응
	//임시 구현
	TScriptInterface<IInteractable> Interactable = _OtherActor;
	if(Interactable)
	{
		InteractableProps_.AddUnique(Interactable);
	}
}
