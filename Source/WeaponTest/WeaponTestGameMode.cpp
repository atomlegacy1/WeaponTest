// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeaponTestGameMode.h"
#include "WeaponTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWeaponTestGameMode::AWeaponTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
