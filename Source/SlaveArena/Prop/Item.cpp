#include "Item.h"

#include "ItemInfo.h"
#include "SlaveArena/Component/InventoryComponent.h"
#include "SlaveArena/Subsystem/ItemSubsystem.h"

AItem::AItem()
{
	RootComponent_ = CreateDefaultSubobject<USceneComponent>("Root");
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	Spawn();
}

void AItem::Interact(AActor* _Causer)
{
	check(_Causer);

	UInventoryComponent* Inventory = Cast<UInventoryComponent>(_Causer->GetComponentByClass(UInventoryComponent::StaticClass()));
	if(Inventory)
	{
		SetItemCount(Inventory->TryPushItem(ItemID_, Count_, MaxStack_));
	}
}

void AItem::SetItemID(const uint8 _ItemID)
{
	if(ItemID_ == _ItemID)
	{
		return;
	}

	ItemID_ = _ItemID;
	if(false == MeshComponent_.IsNull())
	{
		MeshComponent_->DestroyComponent();
	}
}

void AItem::SetItemCount(const uint8 _Count)
{
	Count_ = _Count;

	if(Count_ == 0)
	{
		Destroy();
	}
}

void AItem::Spawn()
{
	if(Count_ == 0)
	{
		return;
	}
	SetItemData();
}

void AItem::SetItemData()
{
	const UGameInstance* GameInstance = GetGameInstance();

	if(nullptr == GameInstance)
	{
		ensureMsgf(false, TEXT("GameInstance was nullptr"));
		return;
	}

	const UItemSubsystem* Subsystem = GameInstance->GetSubsystem<UItemSubsystem>();
	if(ensureMsgf(Subsystem, TEXT("Item Subsystem was nullptr")))
	{
		const FItemInfo* ItemInfo = Subsystem->GetItemInfo(ItemID_);
		check(ItemInfo);

		MaxStack_ = ItemInfo->MaxStack_;

		if(false == ItemInfo->Mesh_.IsNull())
		{
			UStreamableRenderAsset* Mesh = ItemInfo->Mesh_.LoadSynchronous();

			switch(Mesh->GetRenderAssetType())
			{
				case EStreamableRenderAssetType::StaticMesh:
				{
					UStaticMeshComponent* SMComponent = NewObject<UStaticMeshComponent>(this);
					SMComponent->SetStaticMesh(Cast<UStaticMesh>(Mesh));
					SMComponent->SetSimulatePhysics(true);
					MeshComponent_ = SMComponent;
					FinishAddComponent(SMComponent, false, FTransform());
					break;
				}
				case EStreamableRenderAssetType::SkeletalMesh:
				{
					USkeletalMeshComponent* SKMComponent = NewObject<USkeletalMeshComponent>(this);
					SKMComponent->SetSkeletalMesh(Cast<USkeletalMesh>(Mesh));
					SKMComponent->SetSimulatePhysics(true);
					MeshComponent_ = SKMComponent;
					FinishAddComponent(SKMComponent, false, FTransform());
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
}


