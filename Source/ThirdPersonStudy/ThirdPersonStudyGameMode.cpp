// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonStudyGameMode.h"
#include "ThirdPersonStudyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdPersonStudyGameMode::AThirdPersonStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
