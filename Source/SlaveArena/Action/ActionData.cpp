#include "ActionData.h"

#include "Action.h"
#include "Blueprint/UserWidget.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void UActionData::AddMappingContext(const ULocalPlayer* _LocalPlayer) const
{
	if (InputMappingContext_.IsNull())
	{
		ensureMsgf(false, TEXT("%s's InputMappingContext is missing!"), *this->GetName());
		return;
	}

	check(_LocalPlayer);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = _LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if(ensureMsgf(Subsystem, TEXT("%s's Subsystem was nullptr"), *this->GetName()))
	{
		if(Subsystem->HasMappingContext(InputMappingContext_.Get()))
		{
			return;
		}
		Subsystem->AddMappingContext(InputMappingContext_.Get(), 1);
	}
}

void UActionData::BindAll(AActor* _Actor)
{
	UEnhancedInputComponent* InputComponent = Cast<UEnhancedInputComponent>(_Actor->InputComponent.Get());
	if(nullptr == InputComponent)
	{
		ensureMsgf(false, TEXT("%s's InputComponent was not EnhancedInputComponent"), *_Actor->GetName());
		return;
	}

	//Input -> Action Binding
	for(auto& Elem : Actions_)
	{
		if(nullptr == Elem.Value)
		{
			ensureMsgf(false, TEXT("%s's Action was not nullptr"), *Elem.Key->GetName());
			continue;
		}
		UAction* NewAction = NewObject<UAction>(_Actor, Elem.Value);
		UInputAction* InputAction = Elem.Key.Get();
		NewAction->BindAction(InputComponent, InputAction);
	}
}


void UActionData::BindAll(UUserWidget* _Widget)
{
	
}