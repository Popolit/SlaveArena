#include "WeaponComponent.h"

#include "GameFramework/Character.h"
#include "SlaveArena/Character/Slave.h"
#include "SlaveArena/Prop/ItemInfo.h"
#include "SlaveArena/Prop/Weapon.h"
#include "SlaveArena/Subsystem/ItemSubsystem.h"


void UWeaponComponent::TryEquipItem(uint8 _ItemID)
{
	if(nullptr == GetOwner())
	{
		ensureMsgf(false, TEXT("%s's Owner was nullptr"), *GetName());
		return;
	}
	const UGameInstance* GameInstance = GetOwner()->GetGameInstance();

	if (nullptr == GameInstance)
	{
		ensureMsgf(false, TEXT("GameInstance was nullptr"));
		return;
	}

	const UItemSubsystem* Subsystem = GameInstance->GetSubsystem<UItemSubsystem>();
	if(ensureMsgf(Subsystem, TEXT("ItemSubsystem has not found")))
	{
		const FItemInfo* ItemInfo = Subsystem->GetItemInfo(_ItemID);
		check(ItemInfo);

		if(IsWeaponType(ItemInfo->Type_))
		{
			CreateAndEquipWeaponFromItem(ItemInfo);
		}
	}
}

void UWeaponComponent::CreateAndEquipWeaponFromItem(const FItemInfo* _ItemInfo)
{
	UWorld* World = GetWorld();
	check(World);

	AWeapon* NewWeapon = Cast<AWeapon>(World->SpawnActor(AWeapon::StaticClass()));
	NewWeapon->Initialize(_ItemInfo);

	
	//TODO : 임시 구현
	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if(Character)
	{
		NewWeapon->AttachToComponent(Character->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "weapon_r");
		//TODO : 웨폰 타입에 맞는 무기 만들기
		EquippingWeapons_.Push(NewWeapon);
	}
}

bool UWeaponComponent::IsWeaponType(const EItemType _ItemType) const
{
	return _ItemType == EItemType::OneHandedWeapon || _ItemType == EItemType::TwoHandedWeapon;
}
