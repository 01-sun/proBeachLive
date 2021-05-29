// Copyright Epic Games, Inc. All Rights Reserved.

#include "projectBeachGameMode.h"
#include "projectBeachCharacter.h"
#include "UObject/ConstructorHelpers.h"

AprojectBeachGameMode::AprojectBeachGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
