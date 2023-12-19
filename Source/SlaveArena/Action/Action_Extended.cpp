#include "Action_Extended.h"

#include "GameFramework/Character.h"
#include "Particles/ParticleSystem.h"
#include "NiagaraSystem.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"


void UAction_Extended::DoAction(const void* _Instance) {}


void UAction_Extended::PlayAnimation() const
{
	if(AnimMontage_.IsNull())
	{
		return;
	}

	ACharacter* Character = Cast<ACharacter>(GetOuter());
	if(Character)
	{
		Character->PlayAnimMontage(AnimMontage_.LoadSynchronous());
	}
}

void UAction_Extended::SpawnParticle(const FTransform& _Transform) const
{
	if (Particle_.IsNull())
	{
		return;
	}

	FTransform Transform = _Transform;
	const AActor* Actor = Cast<AActor>(GetOuter());
	if(Actor)
	{
		Transform = Transform.GetRelativeTransform(Actor->GetActorTransform());
	}

	const UParticleSystem* ParticleSystem = Cast<UParticleSystem>(Particle_.Get());
	if(ParticleSystem)
	{
	}


	const UNiagaraSystem* NiagaraSystem = Cast<UNiagaraSystem>(Particle_.Get());
	if(NiagaraSystem)
	{
	}
}

void UAction_Extended::PlaySound() const
{
	if(SoundCue_.IsNull())
	{
		return;
	}

	const AActor* Actor = Cast<AActor>(GetOuter());
	if (Actor)
	{
		const FVector Location = Actor->GetActorLocation();
		UGameplayStatics::PlaySoundAtLocation(this, Cast<USoundBase>(SoundCue_.Get()), Location);
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, Cast<USoundBase>(SoundCue_.Get()));
	}

}
