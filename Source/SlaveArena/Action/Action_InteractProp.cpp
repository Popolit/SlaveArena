#include "Action_InteractProp.h"

#include "SlaveArena/Component/InteractComponent.h"
#include "SlaveArena/Prop/Interactable.h"

void UAction_InteractProp::DoAction(const void* _Instance)
{
	const AActor* Actor = Cast<AActor>(GetOuter());
	if(nullptr == Actor)
	{
		return;
	}

	const UInteractComponent* InteractComponent = Cast<UInteractComponent>(Actor->GetComponentByClass(UInteractComponent::StaticClass()));
	if(nullptr == InteractComponent)
	{
		return;
	}

	auto Prop = InteractComponent->GetProp();

	//TODO : Prop ������ ���� ��ȣ�ۿ� ����
	if(nullptr != Prop)
	{
		(*Prop)->Interact();
		PlayAnimation();
		PlaySound();
	}
}
