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

	//TODO : ����� ��, Ȥ�� ���� �ֽ� ������ �����Ͽ� ����
	return &InteractableProps_[0];
}

void UInteractComponent::BeginPlay()
{
	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::OnBeginOverlap);

	//TODO : Collision Channel �߰�
}


void UInteractComponent::OnBeginOverlap(UPrimitiveComponent* _OverlappedComponent, AActor* _OtherActor, UPrimitiveComponent* _OtherComp, int32 _OtherBodyIndex, bool _bFromSweep, const FHitResult& _SweepResult)
{
	//TODO: Interactive Class�� ��ӹ��� ���Ϳ��� ����
	//�ӽ� ����
	TScriptInterface<IInteractable> Interactable = _OtherActor;
	if(Interactable)
	{
		InteractableProps_.AddUnique(Interactable);
	}
}
