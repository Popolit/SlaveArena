#include "Weapon.h"

#include "ItemInfo.h"

AWeapon::AWeapon()
{
	PrimaryActorTick.bCanEverTick = true;
	Root_ = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root_);
}

void AWeapon::Initialize(const FItemInfo* _ItemInfo)
{
	if (false == _ItemInfo->Mesh_.IsNull())
	{
		UStreamableRenderAsset* Mesh = _ItemInfo->Mesh_.LoadSynchronous();

		switch (Mesh->GetRenderAssetType())
		{
			case EStreamableRenderAssetType::StaticMesh:
			{
				UStaticMeshComponent* SMComponent = Cast<UStaticMeshComponent>(AddComponentByClass(UStaticMeshComponent::StaticClass(), false, FTransform(), false));
				SMComponent->SetStaticMesh(Cast<UStaticMesh>(Mesh));
				SMComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				Mesh_ = SMComponent;
				break;
			}
			case EStreamableRenderAssetType::SkeletalMesh:
			{
				USkeletalMeshComponent* SKMComponent = Cast<USkeletalMeshComponent>(AddComponentByClass(USkeletalMeshComponent::StaticClass(), false, FTransform(), false));
				SKMComponent->SetSkeletalMesh(Cast<USkeletalMesh>(Mesh));
				SKMComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				Mesh_ = SKMComponent;
				break;
			}
			default:
			{
				//여기에 걸릴 경우, 아이템의 메쉬 타입을 확인하고 필요하면 Case를 추가해야함
				check(false);
			}
		}
	}
}
