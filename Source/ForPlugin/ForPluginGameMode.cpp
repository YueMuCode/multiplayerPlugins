// Copyright Epic Games, Inc. All Rights Reserved.

#include "ForPluginGameMode.h"
#include "ForPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AForPluginGameMode::AForPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
